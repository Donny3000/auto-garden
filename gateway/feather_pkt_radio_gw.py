#!/usr/bin/python

from time import sleep                             #pause the app
from ConfigParser import *
from uuid import getnode as get_mac
import att_iot_gateway.att_iot_gateway as IOT        #provide cloud support
from RFM69 import RFM69
from RFM69registers import *
import gateway
import datetime
import time


def connect():
    'set up the connection with the cloud + register the gateway'
    IOT.on_message = on_message
    IOT.connect()           #"att-capp-2.cloudapp.net"
    if authenticate():
        IOT.subscribe()		#starts the bi-directional communication   "att-2.cloudapp.net"s
    else:
        raise Exception("Failed to authenticate with IOT platform")


def authenticate():
    '''if authentication had previously succeeded, loads credentials and validates them with the platform
       if not previously authenticated: register as gateway and wait until user has claimed it
       params:
    '''
    if _tryLoadConfig() == False:
        uid = _getUid()
        IOT.createGateway("Packet Radio Gateway", uid)
        while True:                                     # we try to finish the claim process until success or app quits, cause the app can't continue without a valid and claimed gateway
            if IOT.finishclaim("Packet Radio Gateway", uid):
                _storeConfig()
                sleep(2)                                # give the platform a litle time to set up all the configs so that we can subscribe correctly to the topic. If we don't do this, the subscribe could fail
                return True
            else:
                sleep(1)
        return False                                # if we get here, didn't succeed in time to finish the claiming process.
    else:
        if IOT.authenticate():
            print 'Authenticated'
            return True
        else:
            print 'Failed to Authenticate'
            return False


def _tryLoadConfig():
    'load the config from file'
    c = ConfigParser()
    if c.read('gateway.ini'):
        IOT.GatewayId = c.get('general', 'gatewayId')
        IOT.ClientId = c.get('general', 'clientId')
        IOT.ClientKey = c.get('general', 'clientKey')
        return True
    else:
        return False


def _storeConfig():
    "store the current gateway settings in a config file"
    c = ConfigParser()
    c.add_section('general')
    c.set('general', 'gatewayId', IOT.GatewayId)
    c.set('general', 'clientId', IOT.ClientId)
    c.set('general', 'clientKey', IOT.ClientKey)

    with open('gateway.ini', 'w') as f:
        c.write(f)


def _getUid():
    'extract the mac address in order to identify the gateway in the cloud'
    mac = 0
    while True:                                                                     # for as long as we are getting a fake mac address back, try again (this can happen if the hw isn't ready yet, for instance usb wifi dongle)
        mac = get_mac()
        if mac & 0x10000000000 == 0:
            break
        sleep(1)                                                                    # wait a bit before retrying.

    result = hex(mac)[2:-1]                                                         # remove the 0x at the front and the L at the back.
    while len(result) < 12:                                                         # it could be that there were missing '0' in the front, add them manually.
        result = "0" + result
    result = result.upper()                                                         # make certain that it is upper case, easier to read, more standardized
    print 'MAC Address: ' + result
    return result

nodeId = 0
networkId = 100
isRFM69HW = True
encryptKey = "autoGardenKey001"
c = ConfigParser()
if c.read('gateway.ini'):
    nodeId = int(c.get('radio', 'nodeId'))
    networkId = int(c.get('radio', 'networkId'))
    isRFM69HW = c.get('radio', 'rfm69hw')
    encryptKey = c.get('radio', 'encryptKey')

print "********************************************************************************"
print "********************* RFM69 Packet Radio Configuration *************************"
print "********************************************************************************"
print "Node ID   : 0x%X" % nodeId
print "Network ID: 0x%X" % networkId
print "Is RFM69HW:", isRFM69HW
print "Encryption Key:", encryptKey

radio = RFM69(RF69_915MHZ, nodeId, networkId, isRFM69HW)
print "********************************************************************************"
print "******************* RFM69 Packet Radio Class Initialized ***********************"
print "********************************************************************************"
#callback: handles values sent from the cloudapp to the device
def on_message(device, actuator, value):
    if actuator == "1":
        if value == "true":
            #note: best to store the destination address (long and short) from the incomming packets, so it becomes dynamic
            zb.send("remote_at", frame="A", command="D4", dest_addr_long = device, dest_addr="QH",parameter='\x05')        # should turn on relay
        else:
            zb.send("remote_at", frame="A", command="D4", dest_addr_long = device, dest_addr="QH",parameter='\x04')        # should turn off relay


devices = []                                           #contains the list of devices already connected to the
if __name__ == "__main__":
    print "********************************************************************************"
    print "*********************** Reading All RFM69 Registers ****************************"
    print "********************************************************************************"
    regs = radio.readAllRegs()
    for reg in regs:
        print reg

    print "********************************************************************************"
    print "************************* Performing rcCalibration *****************************"
    print "********************************************************************************"
    radio.rcCalibration()

    print "********************************************************************************"
    print "************************** Setting Encryption Key ******************************"
    print "********************************************************************************"
    radio.encrypt(encryptKey)

    mavlink = gateway.MAVLink(None)

    # Connect to IoT cloud
    connect()
    while True:
        try:
            radio.receiveBegin()
            while not radio.receiveDone():
                time.sleep(0.1)
            print "Found Data  :", radio.DATA
            print "Parsing Data:", mavlink.parse_buffer(radio.DATA)

            deviceId = "0x%X" % radio.SENDERID
            if deviceId not in devices:			#if we haven't seen this deviceId yet, check if we need to create a new device for it
                devices.append(deviceId)
                print "Checking if device already known in IoT"
                if IOT.deviceExists(deviceId) == False:			#as we only keep deviceId's locally in memory, it could be that we already created the device in a previous run. We only want to create it 1 time.
                    print "creating new device"
                    #IOT.addDevice(deviceId, 'name of the device', "description of the device" )		#adjust according to your needs
                    #IOT.addAsset(1, deviceId, 'relay', 'switch something on/off', True, 'boolean')	#adjust according to your needs
            # IOT.send(data['samples'][0]['adc-1'], deviceId, 1)									#adjust according to your needs
            # IOT.send(data['samples'][0]['adc-2'], deviceId, 2)									#adjust according to your needs
            # IOT.send(data['samples'][0]['adc-3'], deviceId, 3)									#adjust according to your needs
        except KeyboardInterrupt:                                                    				#stop the script
            break

