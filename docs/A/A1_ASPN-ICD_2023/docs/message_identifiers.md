controlled: no

distribution: A

# Message Identification Description

Each header contains a set of 4 identifiers (ID) that provide a unique ID for each transmitted message.  The first uniquely identify a logical stream of data from a sensor or other publishing application:

1. ```vendor_id``` uniquely identifies the device or application vendor.  Vendor ID is user-selected, inspired by your company name to mitigate conflicts with other users.  Vendor IDs ```0x23 00 00 00``` through ```0x23 FF FF FF``` inclusive are reserved and shall not be chosen as user-selected vendor IDs. (If vender_id is interpreted as four ascii characters, vendor_ids starting with the ascii char ```#``` are reserved.) Data from a specific sensor or other publishing application provided by the vendor is then further defined by the device and context IDs.
2. ```device_id```  indicates the type or model of sensor that produced the data (e.g. a specific GPS receiver model) and identifies the specific device or source of the message.
3. ```context_id``` identifies the context or logical data stream to distinguish between data streams in the case that a device provides multiple measurements of the same type (e.g. positions from each antenna of a dual-antenna GPS receiver).

The first three identifiers ```vendor_id , device_id , context_id``` combine to uniquely identify a **logical stream of data from a sensor or other publishing application**.  In addition to ```vendor_id, device_id, context_id```, ASPN provides a ```sequence_id``` to uniquely identify every message from a logical stream of data from a sensor or other publishing application:

- ```sequence_id``` uniquely identifies a specific message within a data stream as defined by a vendor_id, device_id, and context_id.  Sequential messages from each data source (identified by vendor_id, device_id, and context_id) shall increment by exactly 1 and rollover to 0 after an overflow.