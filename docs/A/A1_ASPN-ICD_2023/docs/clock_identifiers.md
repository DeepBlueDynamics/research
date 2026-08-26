controlled: no

distribution: A

# Clock Identifiers

ASPN allows for several clock/timing sources to be used in both the timestamp and time or frequency measurements.  When used in a `.yaml`, the description is abbreviated for clarity of the overall `.yaml`.  For example, 

```
- name: clock_id
  type: uint8[num_obs]
  description: >
    Identifier for clock/timing source for each measurement...
```

This document describes each clock identification in more detail.  The intent of each definition is that they are described in adequate detail to be related to each other.  The reason is the fusion software or another subsystem may then incur the burden of placing all timing information onto a common scale.

## Description

`clock_id` is an `uint8` that identifies a clock/timing source. (Note: The clock identification `name:` value may vary, e.g., when two clock identifiers are needed.)  

The clock identification value range is split into ASPN-defined values and user defined values:

- Values 0 to 50 are reserved for clocks/timing sources that represent common time standards

- Values above 50 are user-defined clocks/timing sources

The summary is as follows:

| `clock_id` | Clock/Timing Source |
| --- | --- |
| `0` | ASPN System Time |
| `1` | International Atomic Time (TAI) |
| `2` | Universal Coordinated Time (UTC) |
| `3` | GPS System Time |
| `4` | Galileo System Time |
| `5` | GLONASS System Time |
| `6` | BeiDou System Time |
| `7` through `50` | Reserved for future additional time scale representations |
| `51` through `255` | User-defined clocks/timing sources |

## ASPN System Time (`clock_id = 0`)

Time elapsed since ASPN system time zero epoch, where the zero epoch is defined by the ASPN system.  A properly defined ASPN system time shall have the following two characteristics:

- The ASPN system time shall be represented as a monotonically increasing quantity defined by the system.
- The ASPN system time zero epoch shall be defined by the system.  

> Example: the current system time is the current TAI time minus the TAI time at the system power on event. (This is effectively the time elapsed since the system power on event.)

## International Atomic Time (TAI) (`clock_id = 1`)

Total elapsed time since 00:00:10 TAI on 1 Jan 1970 (which would be equivalent to 00:00:00 UTC on 1 Jan 1970, if we apply the definition of UTC in 1972 backwards in time to 1970).  During a leap second, this representation of TAI Time continues to advance.  

The relationship between this representation of TAI Time and the representation of UTC time given in the description for `clock_id = 2` during the 30 June/1 July 1972 leap second is as follows:

                                                      
|    TAI Time             |   UTC Time             | TAI elapsed (`clock_id=1`) | UTC elapsed (`clock_id=2`) |
|   --------------------- | ---------------------- | ---------- | ---------- |
|    1 Jul 1972 00:00:08.0 |   30 Jun 1972 23:59:58.0 |  78796798.0  | 78796798.0 |
|    1 Jul 1972 00:00:09.0 | 30 Jun 1972 23:59:59.0 |  78796799.0 |  78796799.0 |
|    1 Jul 1972 00:00:10.0 |  30 Jun 1972 23:59:60.0 |  78796800.0 |  78796800.0 |
|    1 Jul 1972 00:00:10.5 |  30 Jun 1972 23:59:60.5 |  78796800.5 |  78796800.5 |
|    1 Jul 1972 00:00:10.9 |  30 Jun 1972 23:59:60.9 |  78796800.9 |  78796800.9 |
|    1 Jul 1972 00:00:11.0 |   1 Jul 1972 00:00:00.0 |  78796801.0 |  78796800.0 < UTC jumps -1 sec |
|    1 Jul 1972 00:00:12.0  |  1 Jul 1972 00:00:01.0 |  78796802.0 |  78796801.0 |
|    1 Jul 1972 00:00:13.0  |  1 Jul 1972 00:00:02.0 |  78796803.0 |  78796802.0 |

## Universal Coordinated Time (UTC) (`clock_id = 2`)

Elapsed time since 00:00:10 TAI on 1 Jan 1970 (which would be equivalent to 00:00:00 UTC on 1 Jan 1970, if the current form of UTC existed in 1970), but with a -1 second instantaneous jump at the end of each leap second.  During a leap second, this representation of UTC Time continues to advance, but at the end of the leap second it jumps back in time by exactly 1 second, as shown in the table above.  When not in a leap second, the relationship between this representation of UTC time (`clock_id = 2`) and this representation of TAI time (`clock_id = 1`) is 

```
TAI Time = UTC Time + accumulated leap seconds since 1 Jan 1970.  
```

Note: The representation of time indicated by `clock_id = 2` (UTC) is similar to, but not exactly the same, as POSIX time. Specifically, on days when there is not a leap second, the two should be equivalent.  However, on days when there is a leap second, POSIX time and ASPN UTC time will likely be different, depending on the POSIX implementation.

## GPS System Time (`clock_id = 3`)

Total elapsed time as measured by the GPS system clock(s) since the GPS System Time Epoch: 00:00:00 UTC on 6 Jan 1980, or equivalently, 00:00:19 TAI on 6 Jan 1980. During a leap second, this representation of GPS System Time continues to advance just like TAI. Accounting for the difference in time epochs, the relationship between this representation of GPS System Time (clock_id = 3) and the representation of TAI Time (clock_id = 1) is 

```
TAI Time ~= GPS System Time + 315964809 seconds
```

(The symbol “~=” means “is approximately equal to”.  This is not a true equality because the GPS clocks do not exactly track TAI).  

Note: GPS System Time represents a different time system than UTC, and it is not to be used to represent UTC time as generated by a GPS receiver. (Use `clock_id = 2` for that case).

## Galileo System Time (`clock_id = 4`)

Total elapsed time as measured by the Galileo system clock(s) since the Galileo System Time Epoch: 11:59:47 UTC on 21 Aug 1999, or equivalently, 00:00:19 TAI on 22 Aug 1999.  During a leap second, this representation of Galileo System Time continues to advance just like TAI.   Galileo System Time always remains approximately 32 seconds behind TAI. Accounting for the difference in time epochs, the relationship between this representation of Galileo System Time (`clock_id = 4`) and the representation of TAI Time (`clock_id = 1`) is 

```
TAI Time ~= Galileo System Time + 935280009 seconds
```

(The symbol “~=” means “is approximately equal to”.) This is not a true equality because the Galileo clocks do not exactly track TAI).  

Note: Galileo System Time represents a different time system than UTC, and it is not intended to represent UTC time as generated by a Galileo receiver (use `clock_id = 2` for that case).

## GLONASS System Time (`clock_id = 5`)

Elapsed time as measured by the GLONASS system clocks since the GLONASS System Time Epoch: 00:00:00 UTC on 6 Jan 1980, but with a -1 second instantaneous jump at the end of each leap second.  GLONASS System Time always remains approximately the same as UTC (impacted by the same leap seconds).  Accounting for the difference in time epochs, the relationship between this representation of GLONASS System Time (`clock_id = 5`) and the representation of UTC Time (`clock_id = 2`) is 

```
UTC Time ~= GLONASS System Time + 315964800 seconds
```

(The symbol “~=” means “is approximately equal to”.)  This is not a true equality because the GLONASS clocks do not exactly track TAI).  

Note: GLONASS System Time represents a different time system than UTC, and it is not intended to represent UTC time as generated by a GLONASS receiver (use `clock_id = 2` for that case).

## BeiDou System Time (`clock_id = 6`)

Total elapsed time as measured by the BeiDou system clock(s) since the BeiDou Time Epoch: 00:00:00 UTC on 1 Jan 2006, or equivalently, 00:00:33 TAI on 1 Jan 2006. During a leap second, this representation of BeiDou System Time continues to advance just like TAI. BeiDou System Time always remains approximately 33 seconds behind TAI.  Accounting for the difference in time epochs, the relationship between this representation of BeiDou System Time (`clock_id = 6`) and the representation of TAI Time (`clock_id = 1`) is 

```
TAI Time ~= BeiDou System Time + 1136073623 seconds
```

(The symbol “~=” means “is approximately equal to”.)  This is not a true equality because the BeiDou clocks do not exactly track TAI).

Note: BeiDou System Time represents a different time system than UTC, and it is not intended to represent UTC time as generated by a BeiDou receiver. (Use `clock_id = 2` for that case).

## Reserved (`clock_id = 7` through `clock_id = 50`)

These values are reserved for future, additional clock/timing sources that may be defined by ASPN.  When additional representations are added, this document will be modified to include the additional definitions.

## User-Defined (`clock_id = 51` through `clock_id = 255`)

These values are reserved for system-specific clock/timing sources defined by a particular system.  A properly defined user-defined system time shall have the following two characteristics:

- The user-defined time shall be represented as a monotonically increasing quantity defined by the system.
- The user-defined time zero epoch shall be defined by the system.  

> Example: `clock_id = 51` is the current TAI time minus the TAI time at Midnight, 1 Jan 2023. (This is the time elapsed since a particular event.)

_Caution_:  These definitions may vary from system to system, and there is no deconfliction enforced by the ASPN data model.

> For example, `clock_id = 51` in one system may be drastically different than `clock_id = 51` in another system.
