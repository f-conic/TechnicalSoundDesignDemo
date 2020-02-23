#!/usr/bin/env python3
# Make sure to run python -m pip install waapi-client before running this.

from waapi import WaapiClient, CannotConnectToWaapiException
from pprint import pprint

def get_connection_status(client):
    result = client.call("ak.wwise.core.remote.getConnectionStatus", {})
    
    return result

def connect_to_wwise(client):
    result = client.call("ak.wwise.core.remote.connect", {"host":"127.0.0.1"})

def disconnect_from_wwise(client):
    result = client.call("ak.wwise.core.remote.disconnect", {})

try:
    # Connecting to Waapi using default URL
    with WaapiClient() as client:
        result = get_connection_status(client)   

        if(result.get("isConnected")):
            disconnect_from_wwise(client)
        else:
            connect_to_wwise(client)

except CannotConnectToWaapiException:
    print("Could not connect to Waapi: Is Wwise running and Wwise Authoring API enabled?")