<!-- source: corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf -->
<!-- source_sha256: 908dc28561b9b16d5a033a830fccc4ec1cf39f1881e3d0212070e25d6e71c556 -->
<!-- source_bytes: 2166466 -->
<!-- source_pdf_link: ../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf -->
<!-- extractor: pymupdf4llm 1.28.2 / PyMuPDF 1.28.2 -->
<!-- pages: 196 -->
<!-- extracted_chars: 457080 -->
<!-- generated: 2026-08-26T21:55:27Z by tools/build_docs.py -->

--- [page 1](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=1) ---

# **_GLOBAL POSITIONING SYSTEM STANDARD POSITIONING SERVICE PERFORMANCE STANDARD_** 





## _5_<sup>_<u>th</u>_</sup> _Edition_ 

## _April 2020_ 

**_Integrity - Service - Excellence_** 

Distribution Statement A: Approved for public release; distribution is unlimited

--- [page 2](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=2) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.)

--- [page 3](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=3) ---

##### **FOREWORD** 

This document defines the levels of performance the U.S. Government makes available to users of the Global Positioning System (GPS) Standard Positioning Service (SPS). The GPS SPS Performance Standard underscores the U.S. commitment to cooperate with other global navigation satellite systems and augmentation system providers to ensure compatibility and interoperability of GPS with emerging systems for peaceful, civilian worldwide use. Please refer any questions or comments, in writing, to: 

Office of the Department of Defense Chief Information Officer Attn: Assistant for GPS, Positioning and Navigation 6000 Defense Pentagon Washington, DC 20301-6000 

MOOREFIELD.FRE Digitally signed by DERICK.D.1229141 MOOREFIELD.FREDERICK.D.1229141143 143 Date: 2020.04.15 12:05:55 -04'00' 

Frederick D. Moorefield, Jr. Deputy Chief Information Officer for Command, Control, and Communications

--- [page 4](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=4) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.)

--- [page 5](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=5) ---

GPS SPS PS 

April 2020 

### **TABLE OF CONTENTS** 

|**List of Figures… .........................................................................................................  iii**|
|---|
|**List of Tables.. ............................................................................................................  iii**|
|**List of Appendices… ..................................................................................................  iv**|
|**Executive Summary… ................................................................................................   v**|
|**SECTION 1.0  The GPS Standard Positioning Service .............................................   1**|
|1.1  Purpose.. ........................................................................................................................................   1|
|1.2  Scope .............................................................................................................................................   2|
|1.3  GPS SPS Definition .......................................................................................................................   2|
|1.4  Backward Compatibility..................................................................................................................   3|
|1.5  Key Terms and Definitions .............................................................................................................   4|
|1.6  Global Positioning System Overview .............................................................................................   4|
|1.6.1  GPS Space Segment (SS) ....................................................................................................   4|
|<br>1.6.2  GPS Control Segment (CS) ...................................................................................................   7|
|**SECTION 2.0  SPS SIS Characteristics and Minimum**|
|**Usage Assumptions ............................................................................   9**|
|2.1  SPS SIS Interface Specification Requirements .............................................................................   9|
|2.2  Overview of SPS SIS Interface Characteristics .............................................................................   9|
|2.2.1  SPS SIS RF Characteristics ..................................................................................................   9|
|2.2.2  GPS NAV Message Characteristics ...................................................................................... 11|
|2.2.3  GPS SPS SIS Component Combinations ............................................................................. 14|
|2.3 Overview of SPS SIS Performance Characteristics ....................................................................... 15|
|2.3.1  SPS SIS Availability ............................................................................................................... 15|
|2.3.2  SPS SIS Health ..................................................................................................................... 16|
|2.3.3  SPS SIS Accuracy ................................................................................................................. 24|
|2.3.4  SPS SIS Integrity ................................................................................................................... 25|
|2.3.5  SPS SIS Continuity ................................................................................................................ 29|
|<br>2.3.6  SPS SIS UTC(USNO) Accuracy ............................................................................................ 29|
|2.4  Usage Assumptions for SPS Performance Standards .................................................................. 30|
|2.4.1  SPS User ............................................................................................................................... 30|
|2.4.2  SPS SIS Configuration .......................................................................................................... 30|
|2.4.3  Single-/Dual-/Triple-Frequency Operation ............................................................................. 30|
|<br>2.4.4  SPS SIS Health ..................................................................................................................... 30|
|2.4.5  Excluded Errors ..................................................................................................................... 32|
|2.4.6  “Dummy” Satellites ................................................................................................................ 33|
|**SECTION 3.0  SPS SIS Performance Standards ....................................................... 35**|
|3.1  Overview ........................................................................................................................................ 35|
|3.1.1  SPS SIS Performance Standards Organization .................................................................... 36|
|3.1.2  CM-Code, CL-Code, I5-Code, and Q5-Code SIS Performance Standards .......................... 36|
|3.2  24-Slot Constellation Definitions .................................................................................................... 37|
|3.3  SPS SIS Coverage ........................................................................................................................ 41|
|<br>3.3.1  Per Satellite Coverage ........................................................................................................... 41|



5<sup>th</sup> Edition 

Page i

--- [page 6](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=6) ---

GPS SPS PS 

April 2020 

|3.3.2  Baseline/Expandable 24-Slot Constellation Coverage .......................................................... 42|
|---|
|3.4  SPS SIS Accuracy ......................................................................................................................... 43<br>|
|3.4.1  SPS SIS URE Accuracy Standards ....................................................................................... 44<br>|
|3.4.2  SPS SIS URRE Accuracy Standards .................................................................................... 45<br>|
|3.4.3  SPS SIS URAE Accuracy Standards .................................................................................... 45<br>|
|3.4.4  SPS SIS UTCOE Accuracy Standards .................................................................................. 46|
|3.5  SPS SIS Integrity ........................................................................................................................... 47|
|3.5.1  SPS SIS Instantaneous URE Integrity Standards ................................................................. 47<br>|
|3.5.2  SPS SIS Instantaneous URRE Integrity Standards .............................................................. 48<br>|
|3.5.3  SPS SIS Instantaneous URAE Integrity Standards ............................................................... 49<br>|
|3.5.4  SPS SIS Instantaneous UTCOE Integrity Standards ............................................................ 49|
|3.5.5  Psatand PconstStandards ........................................................................................................ 50|
|3.6  SPS SIS Continuity ........................................................................................................................ 51<br>|
|3.6.1  SPS SIS Continuity Standards – Unscheduled Failure Interruptions .................................... 51|
|3.6.2  SPS SIS Continuity Standards – Unscheduled Maintenance Interruptions .......................... 51|
|3.6.3  SPS Status and Problem Reporting Standards ..................................................................... 52|
|3.7  SPS SIS Availability ....................................................................................................................... 53<br>|
|3.7.1  SPS SIS Per-Slot Availability Standards ............................................................................... 53|
|3.7.2  SPS SIS Constellation Availability Standards ....................................................................... 54|
|3.7.3  Operational Satellite Count Standards .................................................................................. 55|
|3.8  SPS Position/Time Domain Standards .......................................................................................... 56|
|3.8.1  PDOP Availability Standards ................................................................................................. 57|
|3.8.2  SPS Position Availability Standards ...................................................................................... 57|
|3.8.3  SPS Position/Velocity/Time Accuracy Standards .................................................................. 58|
|**SECTION 4.0  References ........................................................................................... 59**|
|4.1  Government Documents ................................................................................................................ 60|
|4.2  Non-Government Documents ........................................................................................................ 62|



5<sup>th</sup> Edition 

Page ii

--- [page 7](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=7) ---

GPS SPS PS 

April 2020 

||**List of Figures**|
|---|---|
|Figure 1.6-1<br>|Block II Series Satellite GPS SIS Generation and Transmission..... ....................................   5<br>|
|Figure 1.6-2|The GPS Control Segment (CS)… .......................................................................................   8|
|Figure 2.2-1|LNAV Message Content and Format Overview ................................................................... 12|
||**List of Tables**|
|Table 1.4-1|SPS SIS Backward Compatibility ..........................................................................................   3|
|Table 1.6-1|GPS SIS Taxonomy ...............................................................................................................   5|
|Table 1.6-2|GPS SPS SIS Broadcast Configurations ...............................................................................   6|
|Table 2.2-1|CNAV Message Types/Content vs LNAV Subframes/Content ............................................. 13|
|Table 2.2-2|SPS SIS Component Combinations Covered by this Edition of the_SPS PS_....................... 14|
|Table 3.1-1|SPS SIS Performance Standards vs. SPS SIS Signals ........................................................ 37|
|Table 3.2-1|Baseline 24-Slot Constellation Slot Assignments as of the Defined Epoch .......................... 38|
|Table 3.2-2|Expandable 24-Slot Constellation Slot Assignments as of the Defined Epoch ..................... 39|
|Table 3.2-3|Reference Orbit Parameters .................................................................................................. 40|
|Table 3.3-1|SPS SIS Per-Satellite Coverage Standards .......................................................................... 41|
|Table 3.3-2|SPS SIS Constellation Coverage Standards ......................................................................... 42|
|Table 3.4-1|SPS SIS URE Accuracy Standards ....................................................................................... 44|
|Table 3.4-2|SPS SIS URRE Accuracy Standards .................................................................................... 45|
|Table 3.4-3|SPS SIS URAE Accuracy Standards .................................................................................... 46|
|Table 3.4-4|SPS SIS UTCOE Accuracy Standards .................................................................................. 46|
|Table 3.5-1|SPS SIS Instantaneous URE Integrity Standards ................................................................. 47|
|Table 3.5-2<br>|SPS SIS Instantaneous URRE Integrity Standards ............................................................... 48<br>|
|Table 3.5-3|SPS SIS Instantaneous URAE Integrity Standards ............................................................... 49|
|Table 3.5-4|SPS SIS Instantaneous UTCOE Integrity Standards ............................................................ 49|
|Table 3.5-5|SPS SIS Instantaneous Psatand PconstStandards ................................................................. 50|
|Table 3.6-1|SPS SIS Unscheduled Failure Interruption Continuity Standards ......................................... 51|
|<br>Table 3.6-2|<br>SPS SIS Unscheduled Maintenance Interruption Continuity Standards ............................... 52|
|Table 3.6-3|SPS Status and Problem Reporting Standards ..................................................................... 52|
|Table 3.7-1|SPS SIS Per-Slot Availability Standards ............................................................................... 53|
|Table 3.7-2|SPS SIS Constellation Availability Standards ....................................................................... 54|
|Table 3.7-3|Operational Satellite Count Standards .................................................................................. 55|
|Table 3.8-1|PDOP Availability Standards ................................................................................................. 57|
|Table 3.8-2|SPS Position Availability Standards ...................................................................................... 57|
|Table 3.8-3|SPS Position/Velocity/Time Accuracy Standards .................................................................. 58|



5<sup>th</sup> Edition 

Page iii

--- [page 8](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=8) ---

GPS SPS PS 

April 2020 

### **List of Appendices** 

Appendix A: SPS Signal-In-Space (SIS) Background Information Appendix B: SPS Position, Velocity, and Time (PVT) Performance Expectations Appendix C: Key Terms, Definitions, Abbreviations and Acronyms 

Note:  A Table of Contents is contained within each respective Appendix. 

5<sup>th</sup> Edition 

Page iv

--- [page 9](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=9) ---

GPS SPS PS 

April 2020 

### **Executive Summary** 

The U.S. Global Positioning System (GPS) Standard Positioning Service (SPS) consists of spacebased positioning, navigation, and timing (PNT) signals delivered free of direct user fees for peaceful civil, commercial, and scientific uses worldwide.  This SPS Performance Standard (SPS PS) specifies the levels of SPS performance in terms of broadcast signal parameters and GPS constellation design.  The U.S. Government is committed to meeting and exceeding the minimum levels of service specified in this SPS PS. 

Since GPS initial operational capability (IOC) was first declared in 1993, actual GPS performance has continuously met and exceeded minimum performance levels specified in the SPS PS and users can generally expect improved performance over the minimum levels described here.  For example, with current (2018) Signal-in-Space (SIS) accuracy, well-designed GPS receivers have been achieving horizontal accuracy of 3 meters or better and vertical accuracy of 5 meters or better 95% of the time.  A number of U.S. agencies continually monitor actual GPS SPS performance, including the Federal Aviation Administration (FAA) which publishes quarterly Performance Analysis Reports at its National Satellite Test Bed (NSTB) web site (http://www.nstb.tc.faa.gov/).  Interested readers are encouraged to refer to this and other sources for updated GPS performance. 

The performance specifications in this edition of the SPS PS apply to the L1 (1575.42 MHz) Coarse/Acquisition (C/A) signal.  Information is also provided regarding characteristics of planned L2C (1227.60 MHz) Civil Moderate Code (CM) and Civil Long Code (CL) signals, and the L5 (1176.45 MHz) In-Phase Code (I5) and Quadrature Phase (Q5) signals.  The L2C and L5 signals are pre-operational and their use is at the users’ own risk.  No commitment of signal availability for L2C or L5 will be made until the signals are declared fully operational by the DoD and available for users. The “Baseline 24-Slot” GPS constellation definition remains unchanged from the previous edition of the SPS PS while the “Expandable 24-Slot” GPS constellation definition has improved slightly (see Section 3.2). 

The SPS PS is updated periodically as GPS modernizes its SPS signal structure.  This edition of the SPS PS revises and supersedes the previous edition, published September 2008, and meets or surpasses all performance commitments of the previous edition.  Significant changes in this update include the addition of information regarding the pre-operational L2C and L5 signals, and expanded capabilities which allow the total size of operational constellation to grow beyond the previous maximum of 32 Navstar satellites.  The L1C signal, the newest GPS signal designed to improve interoperability, will be fielded over time as GPS III satellites populate the GPS constellation and is not addressed in this edition of the SPS PS. 

It is important to distinguish the operational status of the signals defined in this document.  Full Operational Capability (FOC) has been declared for the L1 C/A signal, and it will continue to be provided in accordance with the Federal Radionavigation Plan (FRP) for the foreseeable future. Any use of the pre-operational signals L2C and L5 is at the users’ own risk until those signals are declared fully operational by the DoD and incorporated as operational signals in future editions of the SPS PS, in accordance with the FRP. 

In addition to specifying GPS minimum performance parameters, the SPS PS serves as a complement to the GPS SPS SIS Interface Specifications (IS-GPS-200 and IS-GPS-705), which provide relevant information for design and fabrication of GPS civil receiver equipment.  Readers 

5<sup>th</sup> Edition 

Page v

--- [page 10](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=10) ---

GPS SPS PS 

April 2020 

interested in GPS tutorial information are encouraged to refer to the wide range of reference material available on the subject. 

Finally, in line with the U.S. Space-Based PNT Policy (http://www.gps.gov/policy/), the SPS PS underscores the U.S. commitment to cooperate with other GNSS and augmentation system providers to ensure compatibility and interoperability of GPS with emerging systems for peaceful, civilian worldwide use. 

5<sup>th</sup> Edition 

Page vi

--- [page 11](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=11) ---

GPS SPS PS 

April 2020 

### **SECTION 1.0 The GPS Standard Positioning Service** 

The Navstar Global Positioning System, hereafter referred to as GPS, is a space-based radionavigation system owned by the United States Government (USG) and operated by the United States Space Force (USSF).  GPS has provided positioning, navigation, and timing services to military and civilian users on a continuous worldwide basis since initial operational capability was declared in 1993.  An unlimited number of users with a civil or military GPS receiver can determine accurate time and location, in any weather, day or night, anywhere in the world. 

The USSF is responsible for the design, development, procurement, operation, sustainment, and modernization of the system.  The 2<sup>nd</sup> Space Operations Squadron (2 SOPS) maintains the health and status of the operational constellation at facilities located at Schriever Air Force Base, Colorado through a network of dedicated ground antennas and monitor stations located worldwide to ensure GPS performance and reliability meet or exceed the needs of both military and civilian users.  The Space and Control Segments are acquired by the Space and Missile Systems Center (SMC) at Los Angeles Air Force Base, California. 

GPS has grown into a global utility whose multi-use services are integral to U.S. and global security, economic growth, transportation safety, and are an essential element of the worldwide economic infrastructure.   In an effort to ensure beneficial services are available to the greatest number of users without degrading security interests, two GPS services are provided.  The Precise Positioning Service (PPS) is available primarily to the military of the United States and its allies for users properly equipped with PPS receivers.  The Standard Positioning Service (SPS), as initially described in the _SPS Signal Specification_ , was originally designed to provide civil users with a less accurate positioning capability than PPS, through a feature known as Selective Availability (SA).  The use of SA has been discontinued. 

The _SPS Performance Standard_ serves as a companion document to the _PPS Performance Standard_ for the “dual use” (SPS or PPS) system.  This update to the _SPS Performance Standard (5th Edition)_ is part of the evolution of the performance standards toward the overall goal of providing users -- civil and military alike -- complete, consistent, and appropriate performance standards for both the SPS SIS and PPS SIS. 

###### **1.1  Purpose** 

This _5th Edition of the SPS Performance Standard_ ( _SPS PS_ ) defines the levels of Signal In Space (SIS) performance to be provided by the USG to the SPS user community.  In addition to providing general information to the SPS user community, it is established to provide a basis for certification of SPS receivers for use in aviation Instrument Flight Rules (IFR) and to establish a minimum performance level which the GPS constellation must sustain.  As additional capabilities are realized on future GPS space, control and user segments, the standards in this _SPS PS_ will be updated.  Its performance metrics and assumptions should therefore _not_ be used as the sole basis for estimates of utility for future civil applications.  Performance standards described in this document lie between original design parameters and maximum constellation capability.  GPS constellation operations are conducted by 2 SOPS in a manner that balances system performance and operational tempo so as to assure the most consistent and sustainable GPS performance to all users.  The performance standards presented in this document are supported by 2 SOPS operational procedures, and are tempered with technical and operational margin. 

5th Edition 

Page 1

--- [page 12](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=12) ---

GPS SPS PS 

April 2020 

This _SPS PS_ consists of a main body and three appendices.  The _SPS PS_ first provides an overview of the GPS program plus an overview of the SPS SIS and how it is used.  It then provides the performance standards for the SPS SIS.  It concludes with the relevant reference documents. The appendices provide additional information that quantifies and illustrates SPS SIS performance.  Provided below is a definition of each appendix's purpose. 

- **Appendix A:  SPS Signal-In-Space (SIS) Background Information.** This appendix provides further background information on the SPS SIS and its performance standards. 

- **Appendix B:  SPS Position, Velocity, and Time (PVT) Performance Expectations.** This appendix describes examples of how to translate the SPS SIS performance standards into end user position, velocity, and time (PVT) statistical performance expectations.  These are only examples because user equipment (UE) performance characteristics vary significantly based upon user applications.  UE performance specifications are beyond the scope of this _SPS PS_ . 

- **Appendix C:  Definitions.** This appendix provides a list of key terms, definitions, abbreviations and acronyms used in this _SPS PS_ . 

###### **1.2  Scope** 

This _SPS PS_ defines standards for the GPS SPS SIS performance.  Section 3 specifies the performance standards for the SPS SIS from a global perspective, in terms of performance metrics the USG uses to specify system performance.  Appendix B describes the PVT performance an end user can expect to achieve using those same performance metrics.  GPS users need to be aware that GPS is not optimized to support any specific user group, except potentially in time of emergency or national need.  The USG reserves the right to optimize performance to support high priority mission needs over an area of operations (AOO).  See the _Concept of Operations for the Global Positioning System_ (“ _GPS CONOPS_ ”) for additional details. Any such optimization will not degrade GPS SPS SIS performance beyond the standards defined in this _SPS PS_ . 

This _SPS PS_ employs standard definitions and relationships between the performance parameters such as availability, continuity, integrity, and accuracy.  The standard definitions in this _SPS PS_ represent the performance attributes of a space-based positioning and time transfer system.  Refer to Appendix B for a more comprehensive discussion of the relationships between SPS SIS performance and end user PVT expectations. 

This _SPS PS_ only applies to the SPS SIS as it exists on the publication date of this document. This document does not address P(Y)-code, M-code, or L1C which is being or will be broadcast by the latest satellites. 

###### **1.3  GPS SPS Definition** 

The GPS Standard Positioning Service (SPS) is defined as follows: 

5th Edition 

Page 2

--- [page 13](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=13) ---

GPS SPS PS 

April 2020 

_The SPS is a positioning and timing service that is available for peaceful civil, commercial, and scientific use.  It includes the C/A-code signal, the CM/CL-code signals, and the I5-code/Q5code signals.  The C/A-code signal is transmitted by all satellites and comprises an L1 carrier modulated by a coarse/acquisition (C/A) code ranging signal with a legacy navigation (LNAV) data message.  The CM-code and CL-code signals are transmitted by some satellites and comprise an L2 carrier modulated by both a civil moderate length (CM) code ranging signal with a civil navigation (CNAV) data message and a civil long length (CL) code ranging signal without a data message.  The I5-code and Q5-code signals are transmitted by some satellites and comprise an L5 carrier modulated by both a civil in-phase (I5) code ranging signal with a CNAV data message and a civil quadrature-phase (Q5) code ranging signal without a data message._ 

###### **1.4  Backward Compatibility** 

The SPS is, and will continue to be, backward compatible.  Even though the SPS SIS evolves over time, existing SPS receiving equipment continues to obtain performance that is the same, or is better, than received in the past. 

The effectivity milestone for backward compatibility is the declaration of initial operational capability (IOC).  IOC for the L1 C/A-code portion of the SPS SIS was declared on 8 December 1993.  The first edition of this _SPS PS_ was issued that same day to define the initial operational capabilities of the C/A-code portion of the SPS SIS.  SPS receiving equipment which was compliant with the relevant SIS Interface Control Document / Interface Specification (ICD/IS) in effect on that date was provided with C/A-code signals which met the performance commitments in that first edition of the _SPS PS_ .  If any SPS receiving equipment from 1993 is still in operation today, that equipment is still receiving ICD-compliant C/A-code signals which meet or exceed the performance commitments in that first edition of the _SPS PS_ . 

The historical nature of SPS SIS backward compatibility is shown in Table 1.4-1.  The milestones corresponding to each edition of this _SPS PS_ are included for reference purposes. 

**Table 1.4-1.  SPS SIS Backward Compatibility** 

|**Date**|**SIS Definition **|**SIS Performance Specification **|**Milestone**|
|---|---|---|---|
|1993|ICD-GPS-200C|1<sup>st</sup>Edition of SPS Signal Specification|C/A-Code IOC|
|1995||2<sup>nd</sup>Edition of SPS Signal Specification|C/A-Code FOC|
|2001||3<sup>rd</sup>Edition of SPS Performance Standard|SA Discontinued|
|2004|IS-GPS-200D|||
|2008||4<sup>th</sup>Edition of SPS Performance Standard|GPS Modernization|
|2010|IS-GPS-200E|||
|2011|IS-GPS-200F|||
|2012|IS-GPS-200G|||
|2013|IS-GPS-200H|||
|2018||5<sup>th</sup>EditionofSPSPerformance Standard|CM, CL,I5, Q5Introduced|



5th Edition 

Page 3

--- [page 14](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=14) ---

GPS SPS PS 

April 2020 

Note that this edition of the _SPS PS_ is not associated with either an IOC or full operational capability (FOC) declaration for the CM-code, CL-code, I5-code, or Q5-code signals.  Future editions are, however, expected in response to these milestones. 

###### **1.5  Key Terms and Definitions** 

Terms and definitions which are key to understanding the scope of the GPS SPS SIS are provided in Appendix C.  A list of abbreviations and acronyms is also provided in Appendix C. 

###### **1.6  Global Positioning System Overview** 

Sufficient information is provided below to promote a common understanding of the GPS baseline for the purposes of this document.  The GPS baseline herein is comprised of the segments owned by the USG: the Control and Space Segments.  The Control and Space Segments provide two types of service, the SPS SIS and the PPS SIS.  This document covers the SPS SIS.  For further information on the PPS SIS, refer to the _PPS PS_ . 

The two GPS system segments are described below.  The SPS SIS interface is described later in Section 2. 

###### **1.6.1  GPS Space Segment (SS)** 

The GPS constellation nominally consists of 24, properly geometrically spaced slots, where each slot contains at least one operational satellite (see Section 3.2). 

The GPS SIS generation and transmission process for an objective Block II series satellite is illustrated in Figure 1.6-1.  The atomic frequency standard generates the stable time base for the satellite.  The synthesized 10.23 MHz clock signal and synchronized code/carrier timing signals are distributed by the frequency synthesizer to other payload subsystems.  The mission computer receives the uploaded navigation (NAV) data from the Control Segment (CS) through the Telemetry, Tracking, and Command (TT&C) subsystem.  The Navigation Baseband generates the pseudorandom noise (PRN) ranging codes and adds the NAV message data to the PRN ranging codes.  The L-Band subsystem modulates the resulting binary sequences onto the L1 (1575.42 MHz), L2 (1227.6 MHz), and L5 (1176.45 MHz) carriers which are then broadcast by the helix array antenna. 

Each satellite broadcasts a minimum of two PRN ranging codes: (1) the precision (P) code, which is the principal ranging code or the Y-code which is used in place of the P-code whenever the anti-spoofing mode of operation is activated; and (2) the coarse/acquisition (C/A) code which is used for acquisition of the P (or Y) code (denoted as P(Y)) and as the primary civil ranging signal. The legacy NAV (LNAV) message based upon data periodically uploaded from the Control Segment is provided by adding the LNAV data to both the 10.23 MHz P(Y)-code sequence and the 1.023 MHz C/A-code sequence.  The satellite modulates the two resulting code-plus-data sequences onto the L1 carrier, and modulates just the 10.23 MHz code-plus-data sequence onto the L2 carrier; and then both modulated carriers are broadcast to the user community.  Depending on the particular satellite configuration, the following additional PRN ranging codes and NAV message data may also be broadcast by a satellite: (a) the military (M) codes and military NAV (MNAV) messages on the L1 and L2 carriers, (b) the second civil (L2C) codes and civil NAV 

5th Edition 

Page 4

--- [page 15](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=15) ---

GPS SPS PS 

April 2020 

(CNAV) messages on the L2 carrier, and (c) the third civil (L5) codes and CNAV message on the L5 carrier. 



<!-- Start of picture text -->
GPS SIS<br>Right-Hand Circularly Polarized<br>1575.42 MHz, 1227.6 MHz, 1176.45 MHz<br>NAV DATA<br>UPLOAD<br>FROM CS<br>ATOMIC<br>FREQUENCY  TT&C<br>STANDARD  SUBSYSTEM<br>Helix Array<br>Antenna<br>FREQUENCY SYNTHESIZER  MISSION  NAVIGATION  L-BAND<br>COMPUTER  BASEBAND  SUBSYSTEM<br>GENERATOR<br> 10.23 MHz synthesized   NAV & control       Synchronized ranging   Spread spectrum modulation<br>digital clock  data checks  codes generation  of 1575.42 MHz, 1227.6 MHz,<br> Generation of synchronized   NAV data   Modulo-2 addition of  and 1176.45 MHz carriers<br>code and carrier timing  generation  codes and NAV data<br><!-- End of picture text -->

**Figure 1.6-1.  Block II Series Satellite GPS SIS Generation and Transmission** 

The set of P(Y), M, and C/A code-plus-NAV-data sequences, and carriers is referred to as the PPS SIS. The set of C/A-code-plus-NAV-data sequences, CM-code-plus-NAV-data sequences, CL-code sequences, I5-code-plus-NAV-data sequences, Q5-code sequence, and carriers is referred to as the SPS SIS. Collectively, the PPS SIS and the SPS SIS are known as the satellite's navigation signals (or navigation SIS or GPS SIS).  This GPS SIS taxonomy is illustrated in Table 1.6-1. 

**Table 1.6-1.  GPS SIS Taxonomy** 

||**GPS**|**SIS**|
|---|---|---|
|Carrier Frequency|**PPS SIS**|**SPS SIS**|
|L1<br> <br> <br>|P(Y)-code + LNAV Data*<br>M-code + MNAV Data<br>C/A-code + LNAV Data*|C/A-code + LNAV Data*|
|L2<br> <br>|P(Y)-code + LNAV Data*<br>M-code + MNAV Data|CM-code + CNAV Data<br>CL-code|
|L5||I5-code + CNAV Data<br>Q5-code|



* SIS components marked by an asterisk are broadcast by all Navstar satellites 

5th Edition 

Page 5

--- [page 16](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=16) ---

GPS SPS PS 

April 2020 

The SIS broadcast configuration of the satellites occupying each GPS constellation slot has evolved in the past and will continue to evolve in the future.  This evolution is designed to occur in a backward compatible manner so as to sustain the existing SIS components while concurrently deploying new SIS components.  Table 1.6-2 defines four SPS SIS broadcast configurations across three carriers addressed in the current edition of this _SPS PS_ along with representative Block II series satellite examples.  The definitions of the objective, intermediate, and baseline SPS SIS broadcast configurations are expected to further evolve in future editions of this _SPS PS_ .  The definition of the minimum SPS SIS broadcast configuration is expected to remain unchanged in the future. 

**Table 1.6-2.  GPS SPS SIS Broadcast Configurations** 

|**Configuration Name**|**L1 Carrier**|**L2 Carrier*****|**L5 Carrier*****|
|---|---|---|---|
|Objective (e.g., IIF)|C/A-code + LNAV Data|CM-code + CNAV Data<br>CL-code|I5-code + CNAV Data<br> Q5-code|
||C/A-code + LNAV Data|CM-code**<br> CL-code|I5-code**<br> Q5-code|
|Intermediate*|C/A-code + LNAV Data||I5-code + CNAV Data<br> Q5-code|
|<br>(e.g., IIR-M,<br>dfid IIF|C/A-code + LNAV Data||I5-code**<br> Q5-code|
|own-congure )|C/A-code + LNAV Data|CM-code + CNAV Data<br> CL-code||
||C/A-code + LNAV Data|CM-code** + CL-code||
|Minimum (e.g., IIR/IIA)|C/A-code + LNAV Data|||



* Only selected examples of the intermediate SPS SIS broadcast configurations shown for illustration 

** Includes the intentional broadcast of default CNAV data 

*** Refer to <u>the configuration code broadcast in the NAV message for each particular satellite</u> 

Regardless of their particular SIS broadcast configuration, all satellites are designed to provide reliable service over their design lives through a combination of space qualified parts, multiple redundancies for critical subsystems, and internal diagnostic logic.  The satellites require minimal interaction with the ground and allow all but a few maintenance activities to be conducted without interruption to the broadcast SIS.  Periodic uploads of NAV message data are designed to cause no interruption to the SIS. 

An important line of defense against loss-of-availability SIS anomalies comes from the ability of certain satellites to operate in degraded broadcast configurations which still satisfy the SPS SIS minimum broadcast configuration defined in Table 1.6-2.  A satellite may be able to survive certain subsystem failures and continue to operate by having its SIS broadcast configuration intentionally downgraded to a less demanding configuration.  As long as the minimum SPS SIS broadcast configuration is still satisfied by the satellite, there is no loss-of-availability SIS anomaly.  The effects of a downgrade which does not satisfy the minimum SPS SIS broadcast configuration are covered in Section 3 of this _SPS PS_ . 

The first line of defense against loss-of-integrity SIS anomalies are the satellites themselves.  The satellites automatically remove themselves from service whenever they experience any of a number of different kinds of on-board failures that could result in loss-of-integrity SIS anomalies. This removal from service is accomplished by the satellite switching from broadcasting its normal navigation signals to instead broadcasting signals with non-standard PRN code sequences and/or default NAV message data. 

5th Edition 

Page 6

--- [page 17](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=17) ---

GPS SPS PS 

April 2020 

###### **1.6.2  GPS Control Segment (CS)** 

The Control Segment (CS) is comprised of four major subsystems:  a Master Control Station (MCS), an Alternate Master Control Station (AMCS), a network of four ground antennas (GAs), and a network of globally-distributed monitor stations (MSs).  An overview of the CS is provided in Figure 1.6-2. 

The MCS is located at Schriever Air Force Base, Colorado, and is the central control node for the GPS satellite constellation.  Operations are maintained 24 hours a day, seven days a week throughout the year by highly skilled 2 SOPS personnel.  The MCS is responsible for all aspects of constellation command and control, to include: 

- Routine satellite bus and payload status monitoring 

- Satellite maintenance and subsystem anomaly resolution 

- Satellite commissioning, decommissioning, and disposal support 

- Management of GPS SIS performance to comply with all performance standards ( _SPS PS_ and _PPS PS_ ) 

- NAV message upload operations as required to sustain performance in accordance with accuracy and integrity performance standards 

- Detecting and responding to GPS SIS anomalies 

- Communicating with military GPS users 

In the event of a prolonged MCS outage, GPS operations can be moved to the AMCS. 

The DoD does not currently monitor and assess SPS SIS performance in real time.  The DoD does monitor the P(Y)-code signals and LNAV data on both the L1 and L2 carriers for all satellites in view of CS monitor stations in near-real time, to ensure they are meeting their PPS performance standards.  Due to the way that satellites generate their broadcast SIS, monitoring the PPS SIS has been an adequate surrogate for monitoring the SPS SIS under the minimum SPS SIS broadcast configuration (i.e., C/A-code + LNAV data). 

The CS's four GAs provide a near real-time TT&C interface between the satellites and the MCS. The MSs provide near real-time satellite pseudorange measurement data and received NAV messages to the MCS and support continuous monitoring of constellation performance.  The current CS monitor stations provide 100% global coverage with the inclusion of National Geospatial-Intelligence Agency (NGA) MSs. 

The CS provides the second line of defense against GPS SIS anomalies.  (The first line of defense are the satellites themselves.)  When a GPS SIS anomaly occurs that is not covered by the satellite’s automatic removal capability, the CS will respond to the failure by manually removing the satellite from service in a prompt manner, subject to MS visibility, GA visibility, and CS equipment and communications reliability constraints.  For details on both automatic and manual removal from service, see the SPS SIS integrity alarms listed in paragraph 2.3.4 and the related SPS SIS integrity performance standards given in Section 3.5. 

When a MS is tracking a satellite's GPS SIS and the MCS is receiving the L-band measurements in near-real time, the MCS monitors the following GPS SIS metrics (among others) from that satellite: 

a. pseudorange error, and 

5th Edition 

Page 7

--- [page 18](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=18) ---

GPS SPS PS 

April 2020 

- b. pseudorange rate error (i.e., the first time derivative of the pseudorange error, also known as the pseudorange "velocity" error). 



<!-- Start of picture text -->
GROUND ANTENNAS  TT&C  GPS  MONITOR STATIONS<br>Link  SIS<br>MASTER CONTROL STATION<br> Commands   Received NAV Messages<br> Telemetry  Network Control Function   Ranging Measurement Data<br> NAV Message Uploads   Monitor Station Control<br> Data Traffic Management<br> Ground Antenna Control   Monitor Station Status<br>Performance Assess Function  Satellite Control Function  Positioning & Timing Function<br> Check performance against   Command Generation   Ranging Measurement Processing<br>specifications   Telemetry Processing   Satellite State Estimation/Prediction<br> Alarm if failure detected   Upload Generation & Control   NAV Message Generation<br><!-- End of picture text -->

**Figure 1.6-2.  The GPS Control Segment (CS)** 

The MCS does not directly monitor the pseudorange acceleration error (i.e., the second time derivative of the pseudorange error, also known as the pseudorange rate rate error). 

The pseudorange error and the pseudorange rate error for each GPS SIS are used internally by the MCS to determine how to manage each satellite to ensure its GPS SIS meets the performance standards (particularly the integrity standards).  There are three primary options:  (1) if the satellite's pseudorange error is small enough and growing slowly enough, then no action needs to be taken until the next regularly scheduled upload of NAV message data to that satellite; (2) if the satellite's pseudorange error is large enough or is growing quickly enough, then an unscheduled contingency upload may be performed to refresh the satellite's NAV message data and restore the accuracy/integrity of the GPS SIS; or (3) in extreme cases, if the satellite's pseudorange error is very large or is growing so rapidly that the satellite is at risk of exceeding its integrity tolerance, then the MCS may need to manually remove the satellite from service. 

5th Edition 

Page 8

--- [page 19](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=19) ---

GPS SPS PS 

April 2020 

### **SECTION 2.0  SPS SIS Characteristics and Minimum Usage Assumptions** 

This section provides an overview of the SPS SIS interface characteristics, SPS SIS performance characteristics, and the assumptions made to arrive at the performance standards in Section 3.0. The representative receiver characteristics are used to provide a framework for defining the SPS performance standards.  They are not intended to impose any minimum requirements on receiver manufacturers or integrators, although they are necessary attributes to achieve the SPS performance described in this document.  Receiver characteristics used in this standard are required in order to establish a frame of reference in which the SPS SIS performance can be described. 

###### **2.1  SPS SIS Interface Specification (IS) Requirements** 

The SPS SIS shall comply with the technical requirements related to the interface between the Space Segment and the SPS receivers as established by the current revision of IS-GPS-200 and the current revision of IS-GPS-705.  In the event of conflict between the SPS SIS interface characteristics described in this document and the ISs, defer to the ISs. 

###### **2.2  Overview of SPS SIS Interface Characteristics** 

This section provides an overview of the SPS SIS interface characteristics.  SPS SIS interface characteristics are allocated to three categories: (1) carrier and modulation radio frequency (RF) characteristics, (2) the structure, protocols, and contents of the NAV messages, and (3) the combining of SPS SIS components. 

###### **2.2.1  SPS SIS RF Characteristics** 

For a particular Space Vehicle (SV), all transmitted signal elements (carriers, codes and data) are coherently derived from the same on-board frequency source. 

###### 2.2.1.1  L1 Signals 

All satellites transmit right-hand circularly polarized (RHCP) signals at 1575.42 MHz as specified in IS-GPS-200.  The L1 signals are transmitted with enough power to ensure the minimum received signal power level of -158.5 dBW for the L1 C/A-code under the conditions defined in ISGPS-200. 

The L1 carrier consists of two carrier components which are in phase quadrature with each other. Each carrier component is phase shift key (PSK) modulated by separate bit trains.  The in-phase bit train includes the Modulo-2 sum of the P(Y)-code and the LNAV data clocked at 50 bits per second (bps), while the quadrature-phase bit train includes the Modulo-2 sum of the C/A-code and the LNAV data also clocked at 50 bps.  Each satellite’s unique C/A-code is 1,023 chips long and is clocked at a rate of 1.023 megachips per second (Mcps).  At L1, the SPS SIS specifically includes – and is specifically limited to – each satellite’s broadcast C/A-code and the associated 

5th Edition 

Page 9

--- [page 20](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=20) ---

GPS SPS PS 

April 2020 

LNAV data.  See IS-GPS-200 for the detailed definition of the C/A-codes and the LNAV data.  For convenience, a summary description of the LNAV data is provided in Section 2.2.2.1. 

###### 2.2.1.2  L2 Signals 

All satellites transmit RHCP signals at 1227.60 MHz as specified in IS-GPS-200.  When the L2C signal is present, the L2 signals are transmitted with enough power to ensure the minimum received signal power level of at least -160.0 dBW for the composite L2C-code (i.e., the chip-bychip multiplex combination of the CM-code plus the CL-code) under the conditions defined in ISGPS-200. 

When the L2C signal is present, the L2 carrier consists of two carrier components which are in phase quadrature with each other.  Each carrier component is PSK modulated by separate bit trains.  The in-phase bit train includes the Modulo-2 sum of the P(Y)-code and the LNAV data clocked at 50 bps, while the quadrature-phase bit train normally includes the chip-by-chip multiplex combination of the Modulo-2 sum of the CM-code plus CNAV data clocked at 25 bps and the CL-code.  Each satellite’s unique composite L2C-code is 1,534,500 chips long and is clocked at a rate of 1.023 Mcps where the underlying CM-code and CL-codes are each clocked at a rate of 0.5115 Mcps.  At L2, the SPS SIS specifically includes – and is specifically limited to – each satellite’s broadcast L2C-code and the associated CNAV data.  See IS-GPS-200 for the detailed definition of the L2C-codes and the CNAV data.  For convenience, a summary description of the CNAV data is provided in Section 2.2.2.2. 

_Notes:_ 

_1.  Because the CNAV data is encoded in a rate ½ convolutional encoder before broadcast, a 25 bps source rate for CNAV data on CM-code results in the 50 symbol per second (sps) broadcast rate for the CM-code plus CNAV data train._ 

_2.  Some GPS satellites may occasionally employ an alternate configuration with the L2C-code signal broadcast on the in-phase carrier component.  See IS-GPS-200 for details._ 

###### 2.2.1.3  L5 Signals 

Some satellites transmit RHCP signals at 1176.45 MHz as specified in IS-GPS-705.  When the L5 signals are present, the L5 signals are transmitted with enough power to ensure the minimum received signal power levels of at least -157.9 dBW for I5-code and -157.9 dBW for Q5-code under the conditions defined in IS-GPS-705. 

When the L5 signal is present, the L5 carrier consists of two carrier components which are in phase quadrature with each other.  Each carrier component is PSK modulated by separate bit trains.  The in-phase bit train includes the Modulo-2 sum of the I5-code and the CNAV data clocked at 50 bps plus a 10-bit Neuman-Hofman (NH) overlay code clocked at 1 Kbps, while the quadrature-phase bit train includes the Q5-code plus a 20-bit NH overlay code clocked at 1 Kbps. Each satellite’s unique I5-code is 10,230 chips long and is clocked at a rate of 10.23 Mcps. Likewise, each satellite’s unique Q5-code is also 10,230 chips long and is also clocked at a rate of 10.23 Mcps.  At L5, the SPS SIS specifically includes – and is specifically limited to – each satellite’s broadcast I5-code, 10-bit NH-code, and the associated CNAV data; plus each satellite’s broadcast Q5-code and 20-bit NH-code.  See IS-GPS-705 for the detailed definition of the I5codes, Q5-codes, NH-codes, and CNAV data.  For convenience, a summary description of the CNAV data is provided in Section 2.2.2.2.  Since the same CNAV data is carried by the I5-code 

5th Edition 

Page 10

--- [page 21](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=21) ---

GPS SPS PS 

April 2020 

as by the CM-code, the summary description of the CNAV data in Section 2.2.2.2 applies equally to the CM-code signals and the I5-code signals. 

_Notes:_ 

_1.  Because the CNAV data is encoded in a rate ½ convolutional encoder before broadcast, a 50 bps source rate for CNAV data on I5 results in the 100 sps broadcast rate for the I5 CNAV data train. This is twice as fast as the 50 sps broadcast rate for the CNAV data train on the CM-code signal._ 

_2.  The (I5-code + 10-bit NH-code + CNAV data) and (Q5-code + 20-bit NH-code) are separate signals that share the same L5 carrier in quadrature, in the same way that P(Y)-code and C/A-code are separate signals that share the same L1 carrier.  See IS-GPS-705 for details._ 

###### **2.2.2  GPS NAV Message Characteristics** 

###### 2.2.2.1  Legacy NAV (LNAV) Message 

Each satellite broadcasts LNAV message data to support the GPS receiver's PVT determination process.  Figure 2.2-1 provides an overview of the data contents and “fixed frame” structure within the LNAV data stream.  It shows each master frame consists of 25 data frames and each data frame consists of 5 subframes.  Subframe 4 and 5 data is different (paged) for each data frame within a master frame.  Each subframe begins with a telemetry word (TLM) and handover word (HOW) pair.  The rest of the data in each subframe includes information required to determine the following: 

- Satellite time-of-transmission 

- Satellite position 

- Satellite (SIS) health 

- Satellite clock correction 

- Single-frequency (SF) ionospheric delay model corrections 

- Time transfer to Coordinated Universal Time (UTC) as kept by the U.S. Naval Observatory (USNO) 

- Constellation status 

5th Edition 

Page 11

--- [page 22](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=22) ---

GPS SPS PS 

April 2020 

The same LNAV message data is broadcast via the SPS SIS and the PPS SIS to all GPS receivers.  See IS-GPS-200 for further information on LNAV message development. 



<!-- Start of picture text -->
Significant Subframe Contents<br>SUBFRAME 1  TLM  HOW  GPS Week Number, User Range Accuracy (URA), Real-Time<br>Health, and Satellite Clock Correction Terms<br>SUBFRAME 2  TLM  HOW  Ephemeris Parameters<br>Frame<br>SUBFRAME 3                                                                                                                                                        (30 sec TLM  HOW Ephemeris Parameters<br>                                                                                                                                                                                   repeat)<br>SUBFRAME 4  TLM  HOW  Almanac and Long-Term Health for Satellites 25-32, Special  Pages<br>Messages, Configuration Flags, Ionospheric and UTC Data  1-25<br>SUBFRAME 5  TLM  HOW  Almanac and Long-Term Health for Satellites 1-24, and  Pages<br>Almanac Reference Time and Week Number  1-25<br><!-- End of picture text -->

**Figure 2.2-1.  LNAV Message Content and Format Overview** 

###### 2.2.2.2  Civil NAV (CNAV) Message 

Some satellites also broadcast CNAV message data to support the GPS receiver's PVT determination process.  Table 2.2-1 provides an overview of the data contents and “flexible message” structure within the CNAV data stream and compares them to the LNAV data contents and “fixed frame” structure.  Unlike LNAV’s rigid structure where every subframe and every page of a subframe is broadcast by every satellite at exactly the same time each week, CNAV’s fluid “flexible message” structure allows different messages to be broadcast by different satellites at different times each week.  It further allows the possibility for new message types to be added into the sequence (or old message types omitted from the sequence) of CNAV messages broadcast by each satellite. 

5th Edition 

Page 12

--- [page 23](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=23) ---

GPS SPS PS 

April 2020 

**Table 2.2-1.  CNAV Message Types/Content vs LNAV Subframes/Content** 

||**CNAV MESSAGES**||**LNAV SUBFRAMES**|
|---|---|---|---|
|**Message**<br>**Type **|**Contents**|**Subframe**<br>**(Page)**|<br>**Contents**|
|Every|Satellite Time-of-Transmission|All|Satellite Time-of-Transmission|
|10|Satellite Position (half of ephemeris)|2|Satellite Position (half of ephemeris)|
|11|Satellite Position (rest of ephemeris)|3|Satellite Position (rest of ephemeris)|
|10|Satellite (SIS) Health|1|Satellite (SIS) Health|
|10, 3x|Satellite User Range Accuracy (URA)|1|Satellite User Range Accuracy (URA)|
|3x|Satellite Clock Correction|1|Satellite Clock Correction|
|30|Satellite Delays & Ionospheric Delay|4(18)|Constellation Ionospheric Delay|
|33|Constellation UTC(USNO) Offset|4(18)|Constellation UTC(USNO) Offset|
|||4 & 5|Constellation Status (full almanacs)|
|37|Constellation Status (midi almanacs)|–|–|
|31 or 12|Constellation Status (mini almanacs)|–|–|
|32|Constellation Earth Orientation|–|–|
|34 or<br>13/14|Constellation Differential Corrections|4(13)|Constellation Differential Corrections|
|35|Constellation GPS-GNSS Time Offset|<br>–|–|
|36 or 15|Constellation Text Messages|4(17)|Constellation Text Messages|
|0|Default CNAV Data(alternating1s/0s)|Any|Default LNAV Data(alternating1s/0s)|



_Notes:_ 

_1.  CNAV messages with content designated as “satellite” are transmitted by each particular satellite for its own L2C or L5 SIS.  CNAV messages with content designated as “constellation” are common across the constellation and may not be transmitted by a particular satellite on its L2C or L5 SIS._ 

_2.  The designator “Message Type 3x” or “MT-3x” means all of the CNAV messages in the Message Type 30 series (i.e., MT-30, MT-31, MT-32, MT-33, etcetera)._ 

_3.  See the individual GPS SPS SIS Interface Specifications (IS-GPS-200 and IS-GPS-705) for further details, particularly the message broadcast intervals tables._ 

###### 2.2.2.3  Clock, Ephemeris, Integrity (CEI) Data Sets 

A “Clock, Ephemeris, Integrity” (CEI) data set is the collection of satellite-specific clock correction parameters, ephemeris parameters, and related parameters (e.g., health flags, URA parameters, time tags) needed to use the satellite’s broadcast signal(s) for accurate positioning or timing.  The performance standards in this document only apply to current and consistent CEI data sets within the curve fit interval for that CEI data set. 

For LNAV messages, the CEI data set comprises most of Subframes 1, 2, and 3.  The Subframe 1, 2, and 3 messages which make up a consistent CEI data set share the same broadcast Index of Data Ephemeris (IODE) value which further matches the 8 least significant bits (LSBs) of the broadcast Index of Data Clock (IODC) value.  See IS-GPS-200 for an explicit listing of the contents of an LNAV CEI data set. 

For CNAV messages, the CEI data set comprises MT-10, MT-11, and the front portion of MT-3x. The MT-10, -11, and -3x messages which make up a consistent CEI data set all share the same 

5th Edition 

Page 13

--- [page 24](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=24) ---

GPS SPS PS 

April 2020 

broadcast data propagation time of week (top) value.  See IS-GPS-200 and IS-GPS-705 for an explicit listing of the contents of a CNAV CEI data set. 

###### **2.2.3  SPS SIS Component Combinations** 

The SPS SIS component combinations covered by this edition of the _SPS PS_ are identified in Table 2.2-2.  These component combinations are grouped by the number of carrier frequencies involved and the corresponding user operating mode supported: one carrier and ‘single frequency’ (SF), two carriers and ‘dual frequency’ (DF), plus three carriers and ‘triple frequency’ (TF).  SPS SIS component combinations not explicitly identified in Table 2.2-2 are not covered by this edition of the _SPS PS_ and have no SPS performance standards. 

**Table 2.2-2.  SPS SIS Component Combinations Covered by this Edition of the** **_SPS PS_** 

|**One Carrier,**<br>**Single Frequency (SF)**|**Two Carriers,**<br>**Dual Frequency (DF)**|**Three Carriers,**<br>**Triple Frequency (TF)**|
|---|---|---|
|C/A-code + LNAV Data|(C/A + CM)-codes + CNAV Data|(C/A + CM + I5)-codes +CNAV Data|
|CM-code + CNAV Data|(C/A + CL)-codes + CNAV Data|(C/A + CL + I5)-codes +CNAV Data|
|CL-code + CNAV Data|(C/A+CM+CL)-codes + CNAV Data|(C/A + CM+CL + I5)-codes +CNAV Data|
|(CM+CL)-codes + CNAV Data|(C/A + I5)-codes + CNAV Data|(C/A + CM + Q5)-codes +CNAV Data|
|I5-code + CNAV Data|(C/A + Q5)-codes + CNAV Data|(C/A + CL + Q5)-codes +CNAV Data|
|Q5-code + CNAV Data|(C/A + I5+Q5)-codes + CNAV Data|(C/A+CM+CL+Q5)-codes +CNAV Data|
|(I5+Q5)-codes + CNAV Data||(C/A+CM+CL+I5+Q5)-codes +CNAV Data|



_Notes:_ 

_1. Proper use of CM-code, CL-code, I5-code, and Q5-code requires the application of the current inter-signal correction (ISC) values which are provided in the CNAV data stream.  Use of CL-code in SF mode by itself or in DF mode with C/A-code imposes additional effort to obtain the required ISC values.  Use of Q5-code in SF mode by itself or in DF mode with C/A-code likewise also imposes additional effort to obtain the required ISC values._ 

_2. The CM-code and the CL-code, as well as the I5-code and the Q5-code can be used separately (e.g., independently or sequentially) or jointly (e.g., concurrently)._ 

_3. DF operation with either of the L2 signals and either of the L5 signals is not covered – and is not recommended – by this edition of the SPS PS.  The L2 and L5 frequencies are only separated by 51 MHz which is not considered adequate for reliable DF operation.  The CNAV integrity-related information does not account for the excessive inaccuracies of L2/L5 DF operation._ 

5th Edition 

Page 14

--- [page 25](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=25) ---

GPS SPS PS 

April 2020 

###### **2.3 Overview of SPS SIS Performance Characteristics** 

The SPS SIS performance characteristics are described below.  The SPS PS performance characteristics are availability, health, accuracy, integrity, continuity, and UTC(USNO) accuracy. 

This overview of the SPS SIS performance characteristics follows a logical progression relative to the output of the SPS SIS from a satellite.  Most fundamentally, a satellite’s SPS SIS is considered either trackable or untrackable.  A trackable SIS is a SIS which can be preprocessed by an SPS receiver sufficiently to be categorized as either healthy, unhealthy, or marginal.  Note that only a trackable and healthy SPS SIS has performance standards for accuracy, integrity, and continuity.  The last characteristic in this section relating GPS time to UTC(USNO) applies at the system level and is independent of the output of the SPS SIS from any particular satellite. 

###### **2.3.1  SPS SIS Availability** 

The SPS SIS availability is the probability that the slots in the GPS constellation will be occupied by satellites transmitting a trackable and healthy SPS SIS.  For this _SPS PS_ , there are two components of availability as follows: 

**Per-Slot Availability.** The fraction of time that a slot in the GPS constellation will be occupied by a satellite that is transmitting a trackable and healthy SPS SIS. 

**Constellation Availability.** The fraction of time that a specified number of slots in the GPS constellation are occupied by satellites that are transmitting a trackable and healthy SPS SIS. 

Both components of availability apply to each SPS SIS signal individually.  Thus, there are separate per-slot availability characteristics and separate constellation availability characteristics for: 

**C/A-Code Signal Availability.** Applies to C/A-code + LNAV data. 

**CM-Code Signal Availability.** Applies to CM-code + CNAV data. 

**CL-Code Signal Availability.** Applies to CL-code + CNAV data. 

**I5-Code Signal Availability.** Applies to I5-code + 10-bit NH-code + CNAV data. 

**Q5-Code Signal Availability.** Applies to Q5-code + 20-bit NH-code. 

_Notes:_ 

_1.  The C/A-code signal (C/A-code + LNAV data) from a satellite is either both trackable and healthy or else the L1 C/A-code signal is unavailable from that satellite.  The CM-code signal (CM-code + CNAV data) from a satellite is either both trackable and healthy or else the CM-code signal is unavailable from that satellite.  The CL-code signal from a satellite is either both trackable and healthy or else the CL-code signal is unavailable from that satellite.  The I5-code signal (I5-code + 10-bit NH-code + CNAV data) from a satellite is either both trackable and healthy or else the L5 I5code signal is unavailable from that satellite.  The Q5-code signal (Q5-code + 20-bit NH-code) from_ 

5th Edition 

Page 15

--- [page 26](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=26) ---

GPS SPS PS 

April 2020 

_a satellite is either both trackable and healthy or else the Q5-code signal is unavailable from that satellite._ 

_2.  In this edition of the SPS PS, the availability performance standards in Section 3.7 only apply to the C/A-code signals.  There are no availability performance standards yet for the CM-code signals, the CL-code signals the I5-code signals, or the Q5-code signals,_ 

Not all satellites occupy a slot in the GPS constellation.  Satellites that are not occupying a slot in the GPS constellation are considered "auxiliary" satellites.  The SPS SIS from an auxiliary satellite is available if that satellite is transmitting a trackable and healthy SPS SIS (which is not the case for SVN-49 for example).  The SPS SIS signals from auxiliary satellites always improve the geometric dilution of precision (DOP) provided by the constellation and therefore contribute to accuracy.  However, the SPS SIS signals from auxiliary satellites do not count towards either the per-slot availability or the constellation availability. 

_Notes:_ 

_1.  The term "spare satellite" has certain connotations which do not apply to an "auxiliary satellite."  In the past, there were 3 spare satellites in the previous 18+3-satellite and 21+3-satellite constellation baselines.  Each of the 3 spare satellites had a pre-defined slot and the operating plan was to launch a new satellite to fill those slots when they were unoccupied.  In contrast, the current baseline is a 24-slot constellation, not a 24+3-slot constellation.  Auxiliary satellites do not have pre-defined slots, and there are no a priori plans to replace auxiliary satellites when they fail._ 

_2.  Auxiliary satellites are required to meet the performance standards for accuracy and integrity in this standard but not continuity or availability.  They may be newly launched satellites not yet assigned to a constellation slot, or older satellites nearing retirement that previously occupied a constellation slot.  Some auxiliary satellites may broadcast fewer SPS signals than their original design due to subsystem failures and/or intentional reconfiguration commanded by the Control Segment.  If so, the configuration code in the broadcast NAV message data will reflect the residual, rather than the designed capabilities of the satellite, such that a GPS receiver tracking the satellite need not search for signals that are no longer being broadcast.  A satellite must have the minimum ability to broadcast C/A code to remain in service._ 

###### **2.3.2  SPS SIS Health** 

The SPS SIS health is the status given by the real-time health-related information broadcast by each satellite as an integral part of each SPS SIS signal.  The SPS SIS health is also sometimes referred to as "satellite health", “space vehicle health”, “SV health” or “signal health”.  For this standard, there are four possible SPS SIS health conditions:  “healthy”, “marginal”, “unhealthy”, and “not applicable”.  The mapping of the real-time health-related information broadcast by the satellite to these four conditions is given in the paragraphs below for each SPS SIS signal. 

_Note:_ 

_1.  The condition of “marginal” collectively encompasses several situations identified in the interface specifications where the SPS SIS cannot be categorized as either “healthy” or “unhealthy”._ 

- 2.3.2.1  C/A-Code Signal 

**"Healthy".** The C/A-code signal is healthy when all of the following four conditions are present: 

5th Edition 

Page 16

--- [page 27](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=27) ---

GPS SPS PS 

April 2020 

- (1) There is no C/A-code signal alarm indication present.  C/A-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine C/A-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the C/A-code signal may not be correct. 

- (2) The C/A-code signal indicates the SPS SIS is healthy.  More specifically, the sixbit health status word given in subframe 1 of the LNAV message is set to all zeros (i.e., binary 0000002, meaning “all NAV data are OK, all signals are OK”). 

- (3) The User Range Accuracy (URA) alert flag for the C/A-code signal is not raised (i.e., bit 18 of the LNAV HOW is set to 0 (meaning the URA is not worse than the URA index value transmitted in subframe 1). 

- (4) The transmitted SPS URA index for the C/A-code signal in subframe 1 is less than 8 (“N” <8).  The URA index is an integer that equates to a range of URA values.  A URA index of less than 8 equates to a URA of less than or equal to 48 meters. 

The above descriptions only relate to how each condition applies to a healthy C/A-code signal.  Definitions for all the different settings of conditions 2, 3, and 4 are given in ISGPS-200. 

**"Marginal".** The C/A-code signal is marginal when the C/A-code signal would otherwise have been defined as healthy except that one or more of the following three warning conditions is or are present: 

- (1) The C/A-code signal indicates that any one of the satellite’s SIS components may not be fully capable.  More specifically, the Most Significant Bit (MSB) of the six-bit health status word given in subframe 1 of the LNAV message is set to 02 (“all NAV data are OK”) and the 5 Least Significant Bits (LSBs) of the six-bit health status word in subframe 1 of the LNAV message are set to anything other than 000002 (all signals are OK), 000102 (all signals dead), or 111002 (“SV is temporarily out”). 

- (2) The URA alert flag is raised (i.e., bit 18 of the LNAV HOW is set to 1) and the SPS URA does not apply.  This means the URA may be worse than the URA index value transmitted in subframe 1.  See IS-GPS-200 for details. 

- (3) The transmitted SPS URA index in subframe 1 is greater than or equal to 8 ("N"=8). A URA index of 8 or greater indicates that the URA is greater than 48 meters or that there is no URA prediction available.  See IS-GPS-200 for details. 

**"Unhealthy".** The C/A-code signal is unhealthy when any one or more of the following four conditions is or are present: 

- (1) There is a C/A-code signal alarm indication present.  C/A-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine C/A-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the C/A-code signal may not be correct, 

- (2) The MSB of the six-bit health status word given in subframe 1 of the LNAV message is set to 12 (“some or all NAV data are bad”). 

- (3) The 5 LSBs of the six-bit health status word in subframe 1 of the LNAV message are set to 000102 (“all signals dead”) or 111002 (“SV is temporarily out”). 

- (4) The transmitted C/A-code signal is untrackable. 

5th Edition 

Page 17

--- [page 28](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=28) ---

GPS SPS PS 

April 2020 

**"Not Applicable".** The “not applicable” health condition does not apply to the C/A-code signal since it is not an allowed SPS SIS broadcast configuration (see Table 1.6-2). 

_Notes:_ 

_1.  The C/A-code signal is unhealthy when the MSB of the six-bit health status word in subframe 1 is set to 12 (“some or all NAV data are bad”) and/or the 5 LSBs of the six-bit health status word in subframe 1 are set to 111112 (“more than one combination would be required to describe anomalies”).  The Control Segment frequently uses this particular combination to indicate a “dead” satellite._ 

_2.  Subframes 4 and 5 of the LNAV message also contain information related to the SIS health of all satellites in the constellation.  This is not real-time information.  It is more of a long-term indicator and may not correspond to the actual health of the C/A-code signal from the transmitting satellite or from other satellites in the constellation.  The preceding definitions in this paragraph take precedence over the information in subframes 4 and 5._ 

_3.  From the above C/A-code signal characteristics, it follows that: (a) a “healthy” C/A-code signal is necessarily trackable, (b) a “marginal” C/A-code signal is necessarily trackable, and (c) an “unhealthy” C/A-code signal may either be trackable or untrackable._ 

_4. If broadcast, CNAV messages may also contain information related to the SIS health of the signals from various satellites in the constellation.  This information may not correspond to the actual health of the C/A-code signal from the broadcasting satellite or from other satellites in the constellation. The most reliable information about a satellite’s C/A-code signal health is obtained directly from that satellite’s C/A-code signal. The preceding definitions in this paragraph take precedence over the information in the CNAV messages._ 

###### 2.3.2.2  CM-Code Signal 

**"Healthy".** The CM-code signal is healthy when all of the following four conditions are present: 

- (1) There is no CM-code signal alarm indication present.  CM-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine CM-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the CM-code signal may not be correct. 

- (2) The CM-code signal indicates the CM-code signal is healthy.  More specifically, the L2 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 0. 

- (3) The URA alert flag for the CM-code signal is not raised (i.e., bit 38 of each CNAV message is set to 0). 

- (4) The transmitted SPS URAED index in MT-10 and the SPS URANED0 index in MT-3x are both less than 8.  The URAED index and URANED0 index are integers that equate to a range of URAED and URANED0 values respectively.  A URAED and URANED0 index of less than 8 equates to a URAED, and URANED0 value of less than or equal to 48 meters. 

The above descriptions only relate to how each condition applies to a healthy CM-code signal.  Definitions for all the different settings of conditions 2, 3, and 4 are given in ISGPS-200. 

5th Edition 

Page 18

--- [page 29](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=29) ---

GPS SPS PS 

April 2020 

**"Marginal".** The CM-code signal health is marginal when the CM-code signal would otherwise have been defined as healthy except that one or more of the following three warning conditions is or are present: 

- (1) Default CNAV data (i.e., MT-0) is being transmitted in lieu of MT-10 and/or MT-11 and/or MT-3x on the L2C-code signal (e.g., a current and consistent CEI data set is not available). 

- (2) The URA alert flag is raised (i.e., bit 38 of each CNAV message is set to 1) and the L2C-code signal URA components do not apply.  This means the CM-code signal URA may be worse than indicated by the URA index components transmitted in MT-10 and MT-3x.  See IS-GPS-200 for details. 

- (3) Either or both the transmitted SPS URAED index in MT-10 and the SPS URANED0 index in MT-3x are greater than or equal to 8 ("N"=8).  A URAED index or URANED0 index of 8 or greater indicates that the L2C-code signal URA is greater than 48 meters or that there is no CM-code signal URA prediction available.  See IS-GPS200 for details. 

**"Unhealthy".** The CM-code signal health is unhealthy when any one or more of the following three conditions is or are present: 

- (1) There is an CM-code signal alarm indication present.  CM-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine CM-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the CM-code signal may not be correct, 

- (2) The CM-code signal indicates the CM-code signal is bad.  More specifically for the CM-code signal, the L2 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 1. 

- (3) The transmitted CM-code signal is untrackable. 

**"Not Applicable".** The “not applicable” health condition applies to the CM-code signal when the satellite is not broadcasting an CM-code signal either: (a) because the satellite was designed without an CM-code signal capability as indicated by the broadcast configuration code for the satellite, or (b) because the satellite’s CM-code signal capability has been disabled and the broadcast configuration code for the satellite has been changed to reflect the residual capabilities of the satellite.  See the relevant SPS SIS broadcast configurations given in Table 1.6-2. 

_Notes:_ 

_1.  If broadcast, the almanac data in MT-31 and/or MT-12 and/or MT-37 of the CNAV message also contains information related to the L1/L2/L5 SIS health of the satellites in the constellation.  This is not real-time information.  It is more of a long-term indicator and may not correspond to the actual health of the L1/L2/L5 SIS from the transmitting satellite or from other satellites in the constellation._ 

_2.  From the above SIS characteristics, it follows that: (a) a “healthy” CM-code signal is necessarily trackable, (b) a “marginal” CM-code signal is necessarily trackable, (c) an “unhealthy” CM-code signal may either be trackable or untrackable, and (d) a “not applicable” CM-code signal does not exist._ 

5th Edition 

Page 19

--- [page 30](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=30) ---

GPS SPS PS 

April 2020 

_3.  The most reliable information about a satellite’s CM-code signal health is obtained directly from that satellite’s CM-code signal.  The preceding definitions in this paragraph take precedence over other information in the CNAV and LNAV messages._ 

###### 2.3.2.3  CL-Code Signal 

**"Healthy".** The CL-code signal is healthy when all of the following four conditions are present: 

- (1) There is no CL-code signal alarm indication present.  CL-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the four CL-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the CL-code signal may not be correct. 

- (2) The CM-code signal indicates the CL-code signal is healthy.  More specifically, the L2 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 0. 

- (3) The URA alert flag for the CM-code signal is not raised (i.e., bit 38 of each CMcode signal CNAV message is set to 0). 

- (4) The transmitted SPS URAED index in the CM-code signal MT-10 and the SPS URANED0 index in the CM-code signal MT-3x are both less than 8. 

The above descriptions only relate to how each condition applies to a healthy CL-code signal.  Definitions for all the different settings of conditions 2, 3, and 4 are given in ISGPS-200. 

**"Marginal".** The CL-code signal health is marginal when the CL-code signal would otherwise have been defined as healthy except that one or more of the following three warning conditions is or are present: 

- (1) Default CNAV data (i.e., MT-0) is being transmitted in lieu of MT-10 and/or MT-11 and/or MT-3x (e.g., a current and consistent CEI data set is not available) on the CM-code signal. 

- (2) The URA alert flag for the I5-code signal is raised (i.e., bit 38 of each CNAV message is set to 1) and the CM-code signal URA components do not apply to the CL-code signal. 

- (3) Either or both the transmitted SPS URAED index in the CM-code signal MT-10 and the SPS URANED0 index in the CM-code signal MT-3x are greater than or equal to 8 ("N"=8). 

**"Unhealthy".** The CL-code signal health is unhealthy when any one or more of the following three conditions is or are present: 

- (1) There is a CL-code signal alarm indication present.  CL-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the four CL-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the CL-code signal may not be correct, 

5th Edition 

Page 20

--- [page 31](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=31) ---

GPS SPS PS 

April 2020 

- (2) The CM-code signal indicates the CL-code signal is bad.  More specifically for the CL-code signal, the L2 health bit of the three-bit signal health field given in the CMcode signal MT-10 of the CNAV message is set to 1. 

- (3) The transmitted CL-code signal is untrackable. 

**"Not Applicable".** The “not applicable” health condition applies to the CL-code signal when the satellite is not broadcasting a CL-code signal either: (a) because the satellite was designed without a CL-code signal capability as indicated by the broadcast configuration code for the satellite, or (b) because the satellite’s CL-code signal capability has been disabled and the broadcast configuration code for the satellite has been changed to reflect the residual capabilities of the satellite.  See the relevant SPS SIS broadcast configurations given in Table 1.6-2. 

_Notes:_ 

_1.  From the above SIS characteristics, it follows that: (a) a “healthy” CL-code signal is necessarily trackable, (b) a “marginal” CL-code signal is necessarily trackable, (c) an “unhealthy” CL-code signal may either be trackable or untrackable, and (d) a “not applicable” CL-code signal does not exist._ 

_2.  The most reliable information about a satellite’s CL-code signal health is obtained directly from that satellite’s CL-code signal and then indirectly from that satellite’s CM-code signal.  The preceding definitions in this paragraph take precedence over other information in the CNAV and LNAV messages._ 

###### 2.3.2.4  I5-Code Signal 

**"Healthy".** The I5-code signal is healthy when all of the following four conditions are present: 

- (1) There is no I5-code signal alarm indication present.  I5-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine I5-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the I5-code signal may not be correct. 

- (2) The I5-code signal indicates the I5-code signal is healthy.  More specifically, the L5 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 0. 

- (3) The URA alert flag for the I5-code signal is not raised (i.e., bit 38 of each CNAV message is set to 0). 

- (4) The transmitted SPS URAED index in MT-10 and the SPS URANED0 index in MT-3x are both less than 8.  The URAED index and URANED0 index are integers that equate to a range of URAED and URANED0 values respectively.  A URAED and URANED0 index of less than 8 equates to a URAED, and URANED0 value of less than or equal to 48 meters. 

The above descriptions only relate to how each condition applies to a healthy I5-code signal.  Definitions for all the different settings of conditions 2, 3, and 4 are given in ISGPS-705. 

5th Edition 

Page 21

--- [page 32](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=32) ---

GPS SPS PS 

April 2020 

**"Marginal".** The I5-code signal health is marginal when the I5-code signal would otherwise have been defined as healthy except that one or more of the following three warning conditions is or are present: 

- (1) Default CNAV data (i.e., MT-0) is being transmitted in lieu of MT-10 and/or MT-11 and/or MT-3x on the I5-code signal (e.g., a current and consistent CEI data set is not available). 

- (2) The URA alert flag is raised (i.e., bit 38 of each CNAV message is set to 1) and the I5-code signal URA components do not apply.  This means the I5-code signal URA may be worse than indicated by the URA index components transmitted in MT-10 and MT-3x.  See IS-GPS-705 for details. 

- (3) Either or both the transmitted SPS URAED index in MT-10 and the SPS URANED0 index in MT-3x are greater than or equal to 8 ("N"=8).  A URAED index or URANED0 index of 8 or greater indicates that the I5-code signal URA is greater than 48 meters or that there is no I5-code signal URA prediction available.  See IS-GPS705 for details. 

**"Unhealthy".** The I5-code signal health is unhealthy when any one or more of the following three conditions is or are present: 

- (1) There is an I5-code signal alarm indication present.  I5-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the nine I5-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the I5-code signal may not be correct, 

- (2) The I5-code signal indicates the I5-code signal is bad.  More specifically for the I5code signal, the L5 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 1. 

- (3) The transmitted I5-code signal is untrackable. 

**"Not Applicable".** The “not applicable” health condition applies to the I5-code signal when the satellite is not broadcasting an I5-code signal either: (a) because the satellite was designed without an I5-code signal capability as indicated by the broadcast configuration code for the satellite, or (b) because the satellite’s I5-code signal capability has been disabled and the broadcast configuration code for the satellite has been changed to reflect the residual capabilities of the satellite.  See the relevant SPS SIS broadcast configurations given in Table 1.6-2. 

_Notes:_ 

_1.  If broadcast, the almanac data in MT-31 and/or MT-12 and/or MT-37 of the CNAV message also contains information related to the L1/L2/L5 SIS health of the satellites in the constellation.  This is not real-time information.  It is more of a long-term indicator and may not correspond to the actual health of the L1/L2/L5 SIS from the transmitting satellite or from other satellites in the constellation._ 

_2.  From the above SIS characteristics, it follows that: (a) a “healthy” I5-code signal is necessarily trackable, (b) a “marginal” I5-code signal is necessarily trackable, (c) an “unhealthy” I5-code signal may either be trackable or untrackable, and (d) a “not applicable” I5-code signal does not exist._ 

5th Edition 

Page 22

--- [page 33](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=33) ---

GPS SPS PS 

April 2020 

_3.  The most reliable information about a satellite’s I5-code signal health is obtained directly from that satellite’s I5-code signal.  The preceding definitions in this paragraph take precedence over other information in the CNAV and LNAV messages._ 

###### 2.3.2.5  Q5-Code Signal 

**"Healthy".** The Q5-code signal is healthy when all of the following four conditions are present: 

- (1) There is no Q5-code signal alarm indication present.  Q5-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the four Q5-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the Q5-code signal may not be correct. 

- (2) The I5-code signal indicates the Q5-code signal is healthy.  More specifically, the L5 health bit of the three-bit signal health field given in MT-10 of the CNAV message is set to 0. 

- (3) The URA alert flag for the I5-code signal is not raised (i.e., bit 38 of each I5-code signal CNAV message is set to 0). 

- (4) The transmitted SPS URAED index in the I5-code signal MT-10 and the SPS URANED0 index in the I5-code signal MT-3x are both less than 8. 

The above descriptions only relate to how each condition applies to a healthy Q5-code signal.  Definitions for all the different settings of conditions 2, 3, and 4 are given in ISGPS-705. 

**"Marginal".** The Q5-code signal health is marginal when the Q5-code signal would otherwise have been defined as healthy except that one or more of the following three warning conditions is or are present: 

- (1) Default CNAV data (i.e., MT-0) is being transmitted in lieu of MT-10 and/or MT-11 and/or MT-3x (e.g., a current and consistent CEI data set is not available) on the I5-code signal. 

- (2) The URA alert flag for the I5-code signal is raised (i.e., bit 38 of each CNAV message is set to 1) and the I5-code signal URA components do not apply to the Q5-code signal. 

- (3) Either or both the transmitted SPS URAED index in the I5-code signal MT-10 and the SPS URANED0 index in the I5-code signal MT-3x are greater than or equal to 8 ("N"=8). 

**"Unhealthy".** The Q5-code signal health is unhealthy when any one or more of the following three conditions is or are present: 

- (1) There is a Q5-code signal alarm indication present.  Q5-code signal alarm indications are one component of the SPS SIS integrity.  The presence of any one of the four Q5-code signal alarm indications listed in paragraph 2.3.4 means the information provided by the Q5-code signal may not be correct, 

5th Edition 

Page 23

--- [page 34](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=34) ---

GPS SPS PS 

April 2020 

- (2) The I5-code signal indicates the Q5-code signal is bad.  More specifically for the Q5-code signal, the L5 health bit of the three-bit signal health field given in the I5code signal MT-10 of the CNAV message is set to 1. 

- (3) The transmitted Q5-code signal is untrackable. 

**"Not Applicable".** The “not applicable” health condition applies to the Q5-code signal when the satellite is not broadcasting a Q5-code signal either: (a) because the satellite was designed without a Q5-code signal capability as indicated by the broadcast configuration code for the satellite, or (b) because the satellite’s Q5-code signal capability has been disabled and the broadcast configuration code for the satellite has been changed to reflect the residual capabilities of the satellite.  See the relevant SPS SIS broadcast configurations given in Table 1.6-2. 

_Notes:_ 

_1.  From the above SIS characteristics, it follows that: (a) a “healthy” Q5-code signal is necessarily trackable, (b) a “marginal” Q5-code signal is necessarily trackable, (c) an “unhealthy” Q5-code signal may either be trackable or untrackable, and (d) a “not applicable” Q5-code signal does not exist._ 

_2.  The most reliable information about a satellite’s Q5-code signal health is obtained directly from that satellite’s Q5-code signal and then indirectly from that satellite’s I5-code signal.  The preceding definitions in this paragraph take precedence over other information in the CNAV and LNAV messages._ 

###### **2.3.3  SPS SIS Accuracy** 

The SPS SIS accuracy is described in two statistical ways; one way is as the 95<sup>th</sup> percentile (95%) SPS SIS user range error (URE) at a specified age of data (AOD), the other is as the 95% SPS SIS URE over all AODs.  With either statistical expression, the SPS SIS accuracy is also known as the SPS SIS pseudorange accuracy.  In this context, “pseudorange” means the full pseudorange data set (i.e., the matched combination of a corrected pseudorange measurement and a pseudorange origin, or equivalently the matched combination of a raw pseudorange measurement and the associated NAV data).  Other accuracy-related SPS SIS performance parameters include the SPS SIS pseudorange rate (velocity) accuracy defined as the 95% SPS SIS pseudorange rate error over all AODs and the SPS SIS pseudorange acceleration (rate rate) accuracy defined as the 95% SPS SIS pseudorange acceleration error over all AODs. 

5th Edition 

Page 24

--- [page 35](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=35) ---

GPS SPS PS 

April 2020 

###### **2.3.4  SPS SIS Integrity** 

The SPS SIS integrity is defined to be the trust which can be placed in the correctness of the information provided by the SPS SIS.  SPS SIS integrity includes the ability of the SPS SIS to provide timely alerts to receivers when the SPS SIS should not be used for positioning or timing. The SPS SIS should not be used when it is providing misleading signal-in-space information (MSI), where the threshold for “misleading” is a not-to-exceed (NTE) tolerance on the SIS URE. For this _SPS PS_ , the four components of integrity are the probability of a major service failure, the time to alert, the SIS URE NTE tolerance, and the alert (either one or the other of two types of alerts). 

**Probability of a Major Service Failure.** The probability of a major service failure for the SPS SIS is defined to be the probability that the SPS SIS's instantaneous URE exceeds the SIS URE NTE tolerance (i.e., MSI) without a timely alert being issued (i.e., unalerted MSI [UMSI]).  Alerts generically include both alarms and warnings. 

**Time to Alert.** The time to alert (TTA) for the SPS SIS is defined to be the time from the onset of MSI until an alert (alarm or warning) indication arrives at the receiver's antenna. Real-time alert information broadcast as part of the NAV message data is defined to arrive at the receiver’s antenna at the end of the NAV message subframe which contains that particular piece of real-time alert information. 

**SIS URE NTE Tolerance.** The SPS SIS URE NTE tolerance for a trackable and healthy SPS SIS is defined to be 4.42 times the integrity assured URA (IAURA) value currently being broadcast by the satellite.  For LNAV, the IAURA is equal to the upper bound on the URA value corresponding to the URA index "N" currently broadcast by the satellite in subframe 1.  For CNAV, the IAURA is the RSS of an elevation-dependent function of the upper bound value of the URAED component and a non-elevation-dependent function of the upper bound value of the URANED component currently broadcast by the satellite in MT-10 and MT-3x respectively.  The SIS URE NTE tolerance for a marginal SPS SIS is not defined and there is no SIS URE NTE tolerance for an unhealthy SPS SIS. 

**Alert – Alarm Indications.** An otherwise healthy SPS SIS signal or marginal SPS SIS signal becomes unhealthy when it is the subject of a SPS SIS alarm indication.  Each SPS SIS signal has its own set of alarm indications as detailed below. 

###### <u>C/A-Code Signal</u> 

The presence of any of the 9 alarm indications listed below means the information provided by the C/A-code signal may not be correct.  The C/A-code signal alarm indications are defined to include the following: 

- (1) The C/A-code signal becomes untrackable (e.g., ≥ 20 dB decrease in transmitted signal power, ≥ 20 dB increase in correlation loss): 

- (a) The C/A-code signal ceases transmission. 

- (b) The elimination of the standard C/A-code (e.g., gibberish code). 

- (c) The substitution of non-standard C/A-code for the standard C/A-code. 

5th Edition 

Page 25

--- [page 36](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=36) ---

GPS SPS PS 

April 2020 

- (d) The substitution of PRN C/A-code number 37 for the standard C/A-code. 

- (2) The failure of parity on 5 successive words of NAV data (3 seconds). 

- (3) The broadcast IODE does not match the 8 LSBs of the broadcast IODC (excluding normal data set cutovers, see IS-GPS-200). 

- (4) The transmitted bits in words 3-10 of subframe 1, 2, or 3 are all set to 0's or all set to 1's. 

- (5) Default NAV data is being transmitted in subframes 1, 2, or 3 (see IS-GPS-200). 

- (6) The 8-bit preamble does not equal 100010112, decimal 139, or hexadecimal 8B. 

###### <u>CM-Code Signal</u> 

The presence of any of the 9 alarm indications listed below means the information provided by the CM-code signal may not be correct.  The CM-code signal alarm indications are defined to include the following: 

- (1) The CM-code signal becomes untrackable (e.g., ≥ 20 dB decrease in transmitted signal power, ≥ 20 dB increase in correlation loss): 

- (a) The CM-code signal ceases transmission. 

- (b) The elimination of the standard CM-code (e.g., gibberish code). 

- (c) The substitution of non-standard CM-code for the standard CM-code. 

- (d) The substitution of PRN CM-code number 37 for the standard CM-code. 

- (2) The failure of the cyclic redundancy check (CRC) on 5 successive CNAV messages (60 seconds). 

- (3) The broadcast time of ephemeris (toe) is not current or does not match the broadcast time of clock (toc) (excluding normal data set cutovers, see IS-GPS-200). 

- (4) The broadcast top is not consistent across the MT-10, -11, and -3x messages which comprise the current CEI data set (excluding normal data set cutovers, see ISGPS-200). 

- (5) The transmitted bits in MT-10, MT-11, and MT-3x are all set to 0's or all set to 1's. 

- (6) The 8-bit preamble does not equal 100010112, decimal 139, or hexadecimal 8B. 

5th Edition 

Page 26

--- [page 37](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=37) ---

GPS SPS PS 

April 2020 

###### CL-Code Signal 

The presence of any of the 4 alarm indications listed below means the information provided by the CL-code signal may not be correct.  The CL-code signal alarm indications are defined to include the following: 

- (1) The CL-code signal becomes untrackable (e.g., ≥ 20 dB decrease in transmitted signal power, ≥ 20 dB increase in correlation loss): 

- (a) The CL-code signal ceases transmission. 

- (b) The elimination of the standard CL-code (e.g., gibberish code). 

- (c) The substitution of non-standard CL-code for the standard CL-code. 

- (d) The substitution of PRN CL-code number 37 for the standard CL-code. 

###### I5-Code Signal 

The presence of any of the 9 alarm indications listed below means the information provided by the I5-code signal may not be correct.  The I5-code signal alarm indications are defined to include the following: 

- (1) The I5-code signal becomes untrackable (e.g., ≥ 20 dB decrease in transmitted signal power, ≥ 20 dB increase in correlation loss): 

- (a) The I5-code signal ceases transmission. 

- (b) The elimination of the standard I5-code (e.g., gibberish code). 

- (c) The substitution of non-standard I5-code for the standard I5-code. 

- (d) The substitution of PRN I5-code number 37 for the standard I5-code. 

- (2) The failure of the CRC on 5 successive CNAV messages (30 seconds). 

- (3) The broadcast toe is not current or does not match the broadcast toc (excluding normal data set cutovers, see IS-GPS-705). 

- (4) The broadcast top is not consistent across the MT-10, -11, and -3x messages which comprise the current CEI data set (excluding normal data set cutovers, see ISGPS-705). 

- (5) The transmitted bits in MT-10, MT-11, and MT-3x are all set to 0's or all set to 1's. 

- (6) The 8-bit preamble does not equal 100010112, decimal 139, or hexadecimal 8B. 

5th Edition 

Page 27

--- [page 38](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=38) ---

GPS SPS PS 

April 2020 

###### Q5-Code Signal 

The presence of any of the 4 alarm indications listed below means the information provided by the Q5-code signal may not be correct.  The Q5-code signal alarm indications are defined to include the following: 

- (1) The Q5-code signal becomes untrackable (e.g., ≥ 20 dB decrease in transmitted signal power, ≥ 20 dB increase in correlation loss): 

- (a) The Q5-code signal ceases transmission. 

- (b) The elimination of the standard Q5-code (e.g., gibberish code). 

- (c) The substitution of non-standard Q5-code for the standard Q5-code. 

- (d) The substitution of PRN Q5-code number 37 for the standard Q5-code. 

**Alert – Warning Indications.** An otherwise trackable and healthy SPS SIS becomes marginal or unhealthy when it is the subject of a SPS SIS warning indication.  SPS SIS warnings are typically provided in advance of the onset of potential MSI events (i.e., preemptive setting of the six-bit health status word in subframe 1 prior to scheduled maintenance).  SPS SIS warnings are also common after an SPS SIS alarm and at satellite end of life.  The SPS SIS warning indications are defined in paragraph 2.3.2 above, plus: 

- (1) An appropriately inflated URA index "N" value or appropriately inflated set of URAED and URANED values (appropriately inflated to cover the expected risk of an abnormally large SPS SIS URE). 

_Notes:_ 

_1.  A SPS SIS alarm indication exists when the satellite is not trackable because it is not transmitting the standard PRN code modulation on the L-band carrier signal.  As indicated above, specific SPS SIS alarm indications include the following: (a) when the L-band carrier signal has no modulation (i.e., unmodulated carrier signal), (b) when the L-band carrier signal is modulated by nonstandard PRN code, and (c) when the L-band carrier signal is modulated by PRN code number 37.  These SPS SIS alarm indications are specifically called out above because of their relatively high probability of occurrence._ 

_2.  The SPS SIS alarm indications related to the LNAV and CNAV message data are considered “weak” indications since SPS receivers do not necessarily continuously read each satellite’s LNAV or CNAV message data either by design or by circumstance (e.g., radio-frequency interference [RFI] can prevent reading NAV message data).  These weak SPS SIS alarm indications are assumed to have a five minute lag time before SPS receivers take notice of them for alerting purposes._ 

_3.  The SPS SIS alarm indications related to the NAV message data are indicative of a problem onboard the satellite.  GPS receivers may perceive similar indications caused by local effects that are unrelated to the broadcast SPS SIS._ 

5th Edition 

Page 28

--- [page 39](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=39) ---

GPS SPS PS 

April 2020 

_4.  MSI is the SIS range domain analog of hazardously misleading information (HMI) in the user position domain.  SPS SIS MSI may or may not cause some SPS receivers to output HMI._ 

_5.  See Appendix A, Section A.5 for additional background information on integrity._ 

_6.  In addition to SPS SIS alarm indications, other conditions may also cause GPS signals to become temporarily untrackable, such as ionospheric signal fades, local signal masking, or local interference._ 

###### **2.3.5  SPS SIS Continuity** 

The SPS SIS continuity for a trackable and healthy SPS SIS is the probability that the SPS SIS will continue to be trackable and healthy without unscheduled interruption over a specified time interval.  Scheduled interruptions which are announced at least 48 hours in advance do not contribute to a loss of continuity.  Scheduled SPS SIS interruptions are announced by way of the Control Segment issuing a "Notice Advisory to Navstar Users" (NANU).  NANUs are similar to the "Notices to Airmen" (NOTAMs) issued regarding scheduled interruptions of ground-based air navigation aids.  CS internal procedures are to issue NANUs for scheduled interruptions at least 96 hours in advance. 

_Note:_ 

_1.  In this edition of the SPS PS, the continuity performance standards in Section 3.6 only apply to the C/A-code signals.  There are no continuity performance standards yet for the CM-code signals, the CL-code signals, the I5-code signals, or the Q5-code signals,_ 

###### **2.3.6  SPS SIS UTC(USNO) Accuracy** 

The SPS UTC(USNO) accuracy for a healthy or marginal SPS SIS is defined to be the 95% error in the parameters (ref. 20.3.3.5.2.4 of IS-GPS-200) contained in that SPS SIS which relate GPS time to UTC(USNO). 

5th Edition 

Page 29

--- [page 40](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=40) ---

GPS SPS PS 

April 2020 

###### **2.4  Usage Assumptions for SPS Performance Standards** 

This _SPS PS_ is conditioned upon certain assumptions regarding use of the SPS SIS.  Those assumptions are as follows. 

###### **2.4.1  SPS User** 

This _SPS PS_ assumes an SPS user with an SPS receiver. 

The SPS user is assumed to be a human or an automated (sub)system desiring to use the SPS positioning and timing service described in this document for a peaceful civil, commercial, or scientific purpose. 

The SPS receiver is assumed to comply with the technical requirements related to the interface between the Space Segment and SPS receivers as established by IS-GPS-200 and IS-GPS-705. The SPS receiver is also assumed to properly account for the performance impacts caused by use of any NAV data outside the curve fit interval for that data and for SIS extended operations. 

###### **2.4.2  SPS SIS Configuration** 

This _SPS PS_ assumes the GPS receiver is tracking, processing, and using one or more of the SPS SIS component combinations listed in Table 2.2-2 as appropriate to the SPS SIS component transmitted by each satellite.  Pseudorange measurements are assumed to be made by PRN code tracking with an early-minus-late correlator at 1 chip spacing using an exact replica of the waveform within an ideal sharp-cutoff filter bandwidth at 24 MHz with linear phase centered at the carrier frequency.  Carrier phase measurement processing is not assumed. 

###### **2.4.3  Single-/Dual-/Triple-Frequency Operation** 

This _SPS PS_ assumes a GPS receiver operates with any of the SF/DF/TF combinations listed in Table 2.2-2.  The performance standards in Section 3 of this _SPS PS_ are independent of whether the GPS receiver uses the satellite-transmitted ionospheric parameters for SF model-based ionospheric delay compensation purposes or not. 

This _SPS PS_ assumes a SF GPS receiver will apply the group delay time correction (TGD) term in accordance with IS-GPS-200 or IS-GPS-705. 

###### **2.4.4  SPS SIS Health** 

This _SPS PS_ preferentially uses the terms "SPS SIS health" or "SPS signal health" to describe the status indicated by the real-time health-related information broadcast by each satellite as part of the SPS SIS (see paragraph 2.3.2).  Occasionally, for consistency with prior usage, this _SPS PS_ may also use the terms "satellite health” or “space vehicle health”. 

5th Edition 

Page 30

--- [page 41](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=41) ---

GPS SPS PS 

April 2020 

###### 2.4.4.1  Limitations on SPS SIS Health 

This _SPS PS_ assumes a GPS receiver will only consider using an SPS SIS component whose health status is indicated as healthy.  This _SPS PS_ explicitly assumes a GPS receiver will not use a SPS SIS component whose health status is indicated as either marginal or unhealthy. 

_Notes:_ 

_1. It is recognized that GPS receivers may gain operational benefit in certain situations by cautiously using a SPS SIS component whose status is indicated as marginal.  Such situations include periods of reduced satellite visibility due to terrain masking, body masking, abnormal receiving antenna orientation, default CNAV messages, or instances where an additional pseudorange data set is needed for fault exclusion.  Although potentially beneficial, use of a SPS SIS whose status is indicated as marginal is not recommended by this SPS PS.  If an indicated-as-marginal SPS SIS is used, the reason for the marginal status should be ascertained and the impact on performance (accuracy, integrity, continuity) should be accounted for in that use._ 

_2. It is further recognized that many GPS augmentation systems (e.g., maritime differential GPS (DGPS) services operating in accordance with the recommendations in RTCM Paper 19493/SC104-STD, Satellite–Based Augmentation System (SBAS) services operating in accordance with RTCA/DO-229) can override many parts of the real-time and long-term health-related information transmitted by each satellite.  If a GPS augmentation system does override any of the health-related information transmitted by the satellites, that GPS augmentation system is explicitly responsible for any and all consequences of the override._ 

###### 2.4.4.2  Priority of SPS SIS Health Information 

This _SPS PS_ assumes a GPS receiver will prioritize the application of the real-time health-related information transmitted by each satellite ahead of the long-term health-related information transmitted by that satellite or any other satellite.  The real-time health-related information is as described earlier in paragraph 2.3.2 of this _SPS PS_ .  The long-term health-related information is contained in words 3 through 10 of the various pages of subframe 4 and subframe 5 of the LNAV data message as shown in Figure 2.2-1 and as further described in IS-GPS-200, or in MT-31 and/or MT-12 and/or MT-37 of the CNAV message as further described in IS-GPS-200 and ISGPS-705.  In this context, “prioritize” means the GPS receiver will use current real-time healthrelated information for a GPS SIS whenever it is available in lieu of long-term health-related information for that GPS SIS. 

###### 2.4.4.3  Timely Application of SPS SIS Health Information 

This _SPS PS_ assumes a GPS receiver will monitor, process, and apply the real-time healthrelated information transmitted by each satellite (including SPS SIS alert indications) each time the information is transmitted.  For real-time health-related information broadcast as part of the NAV message data, the assumed time of application is 2.0 seconds after the end of the NAV message subframe or message which contains the particular piece of real-time health-related information. 

_Notes:_ 

_1. Real-time alert information broadcast as part of the NAV message data is assumed to require an additional 2 seconds for application as opposed to real-time alert information not broadcast as part of the NAV message data._ 

5th Edition 

Page 31

--- [page 42](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=42) ---

GPS SPS PS 

April 2020 

_2. The Control Segment will endeavor to operate the SPS SIS in such a manner to allow GPS receivers at least five minutes to receive, process, and apply the real-time health-related information broadcast as part of the NAV message data before taking any action that could cause a large SPS SIS URE under normal operations and maintenance (O&M) conditions._ 

It is recognized that GPS receivers cannot always monitor the broadcast NAV message data since interruptions may be caused by temporary signal blockages, abnormal receiving antenna orientation, RFI (particularly jamming), and intermittent environmental effects.  Although the GPS receiver is responsible for taking appropriate action when it cannot monitor, process, or apply the current real-time health-related information in the NAV message data, it is possible for the Control Segment to aid some GPS receivers by giving them some advance warning of impending SPS SIS health changes.  This action will only be beneficial for SPS SIS integrity if the SPS SIS health changes from healthy to marginal, or from healthy to unhealthy.  An example of such an inadvance warning would be setting the 5 LSBs of the six-bit health status word in subframe 1 of the LNAV message to 111012 (“SV will be temporarily out”) for a period of time before setting the MSB of the six-bit health status word given in subframe 1 of the LNAV message to 12 (“some or all NAV data are bad”) and/or setting the 5 LSBs of the six-bit health status word in subframe 1 to 111002 (“SV is temporarily out”). 

_Note:_ 

_1. The Control Segment currently provides advance warning of large SPS SIS URE by setting the MSB of the six-bit health status word in subframe 1 to 12 (“some or all NAV data are bad”) and setting the 5 LSBs of the six-bit health status word in subframe 1 to either 111002 (“SV is temporarily out”) or 111112 (“more than one combination would be required to describe anomalies”).  These are conservative courses of action.  The impact of these courses of action has already been factored into the SPS SIS availability standards._ 

###### **2.4.5  Excluded Errors** 

The performance standards in Section 3 of this _SPS PS_ do not take into consideration any error source that is not under direct control of the Space Segment or Control Segment.  Specifically excluded errors include those due to the effects of: 

- Signal distortions caused by ionospheric and/or tropospheric scintillation 

- Residual receiver ionospheric delay compensation errors 

- Residual receiver tropospheric delay compensation errors 

- Receiver noise (including received signal power and interference power) and resolution 

- Receiver hardware/software faults 

- Multipath and receiver multipath mitigation 

- User antenna effects 

- Operator (user) error 

5th Edition 

Page 32

--- [page 43](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=43) ---

GPS SPS PS 

April 2020 

###### **2.4.6  “Dummy” Satellites** 

This _SPS PS_ assumes a GPS receiver will not intentionally attempt to acquire, acquire, track, or use the signals broadcast by any satellite indicated as being a “dummy” satellite in the almanac data broadcast by the non-dummy satellites in the constellation.  The performance standards in Section 3 of this _SPS PS_ do not apply to dummy satellites. 

_Note:_ 

_1. See the definition of a dummy satellite in IS-GPS-200._ 

5th Edition 

Page 33

--- [page 44](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=44) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition 

Page 34

--- [page 45](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=45) ---

GPS SPS PS 

April 2020 

### **SECTION 3.0  SPS SIS Performance Standards** 

This section establishes SPS SIS performance standards for GPS operations.  The USSF is committed to operating GPS in accordance with these standards, in a manner consistent with system capabilities and subject to budgetary constraints.  The USG reserves the right to adjust GPS constellation management practices as necessary to support military and civil end users. One of the potential adjustments to increase the robustness of constellation availability and enhance the overall SPS SIS performance is an expandable 24-slot constellation consisting of the expansion of as many as six of the baseline 24-slot constellation slots.  The USG also reserves the right to optimize performance to support high priority mission needs over an AOO (e.g., maximizing accuracy and availability at the site of a major natural disaster).  Any such optimization will not degrade the SPS SIS performance beyond the standards defined in this section for areas outside the AOO. 

###### **3.1  Overview** 

The SPS SIS performance is specified in terms of minimum performance standards for each performance parameter.  Each standard includes a definition of conditions and constraints applicable to the provision of the specified service.  The phrase “any [healthy] SPS SIS”, when listed as a condition or constraint for any of the performance standards in this section, refers to the individual SPS signal in space transmissions from each satellite. 

SPS SIS performance standards do not include any element not under the direct control of the GPS Control/Space Segments.  Any performance parameters not specified in this section are not considered to be part of the SPS SIS performance standards.  Performance parameters not specified in this section, in IS-GPS-200D/E/F/G/H, or in IS-GPS-705D do not represent a part of the minimum service being provided to the user community. 

These SPS SIS performance standards do not directly represent the end performance users will experience.  The standards provide a definition of the components of GPS performance that, when combined with a signal reception environment and assumptions concerning the GPS receiver, allow users to define for themselves the end performance they can expect for their particular application.  The USG recognizes that these metrics have little direct meaning to the average end user (e.g., pilot, navigator, driver), but they are absolutely essential for GPS receiver designers, system integrators, application engineers, infrastructure and augmentation system developers, space/control segment operators and maintainers, and usage regulators.  In support of end users, Appendix B provides an expanded description of the position domain performance implied by the SPS SIS performance standards combined with the typical performance assumptions, including ionosphere, troposphere, and receiver noise error contributions, for a range of GPS receivers to give a sense of the operational characteristics that can be expected under a wide spectrum of operating conditions.  Appendix B also gives examples of how to translate the expected pseudorange domain characteristics into end user PVT performance terms. 

5th Edition 

Page 35

--- [page 46](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=46) ---

GPS SPS PS 

April 2020 

###### **3.1.1  SPS SIS Performance Standards Organization** 

The SPS SIS performance standards are organized in a ‘build-up sequence’ order.  They start with the most basic performance standard (coverage) and conclude with the position/time domain standards which are a culmination of the preceding SIS performance standards interpreted through a representative SPS receiver. 

The build-up sequence of SPS SIS performance standards (and the specific section references) is as follows: 

**Constellation (3.2)** Deployment of the SPS SIS transmitters (satellites) 

**Coverage (3.3)** 

Broadcast region served by each SPS SIS transmitter 

**Accuracy (3.4)** 

Level of errors in the SPS SIS transmissions over the broadcast region 

**Integrity (3.5)** 

Trustworthiness of the claimed ‘level of errors’ in the SPS SIS transmissions 

**Continuity (3.6)** 

Reliability (continuous availability) of the SPS SIS transmissions with integrity 

**Availability (3.7)** 

Restoration/replacement of SPS SIS transmitters when they lose continuity 

**Position/Time Domain (3.8)** 

Result of constellation & coverage, plus accuracy/integrity/continuity, considering availability 

###### **3.1.2  CM-Code, CL-Code, I5-Code, and Q5-Code SIS Performance Standards** 

This 5th Edition of the _SPS PS_ only addresses the operation of CM-code, CL-code, I5-code, and Q5-code signals prior to IOC.  Until IOC is declared for each SPS SIS, the CM-code, CL-code, I5-code, and Q5-code signals will only meet the Constellation (Section 3.2), Coverage (Section 3.3), Accuracy (Section 3.4) and Integrity (Section 3.5) standards; and then only when trackable and “Healthy” as defined in Sections 2.3.2.2, 2.3.2.3, and 2.3.2.4.  Subsequent editions of this _SPS PS_ will address post-IOC and post-FOC standards for the L2C and L5 signals. 

The applicability of SPS SIS performance standards to each of the SPS SIS signals in this edition of the _SPS PS_ are graphically illustrated in Table 3.1-1. 

5th Edition 

Page 36

--- [page 47](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=47) ---

GPS SPS PS 

April 2020 

**Table 3.1-1.  SPS SIS Performance Standards vs. SPS SIS Signals** 

||**C/A-Code**|**CM-Code**|**CL-Code**|**I5-Code**|**Q5-Code**|
|---|---|---|---|---|---|
|**Constellation**||||||
|**Coverage**||||||
|**Accuracy**||||||
|**Integrity**||||||
|**Continuity**||*|*|*|*|
|**Availability**||*|*|*|*|
|**Position/Time Domain**||*|*|*|*|



Note: 

*  Performance Standards Marked by an Asterisk will be addressed in a Future Edition of this _SPS PS_ 

###### **3.2  24-Slot Constellation Definitions** 

The GPS baseline 24-slot constellation consists of 24 slots in six orbital planes with four slots per plane.  The baseline satellites will occupy these slots.  Six of the 24 slots are expandable.  For historical reasons, the expandable slots are divided into two sets; one set spanning the B/D/F planes and the other set spanning the A/C/E planes.  Any combination of expandable slots (including none or all) may be expanded at a given moment.  Any auxiliary satellites that exist on orbit will occupy other locations in the orbital planes.  There are no a priori specified slots for auxiliary satellites. 

The baseline 24-slot constellation satellites will be placed in the orbital slots whose nominal slot centers are defined by Table 3.2-1.  Satellites will be maintained relative to those slot centers in accordance with the reference orbit specifications and tolerances in Table 3.2-3. 

Slots for the baseline 24-slot constellation are specified in terms of the Right Ascension of the Ascending Node (RAAN) and the Argument of Latitude for a defined epoch.  The corresponding Groundtrack Equatorial Crossing (GEC) values (also known as the Geographic Longitude of the Ascending Node [GLAN] values) are also provided in Table 3.2-1.  Tables 3.2-1 and 3.2-3 define the nominal, properly geometrically spaced, baseline 24-slot constellation for GPS. 

5th Edition 

Page 37

--- [page 48](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=48) ---

GPS SPS PS 

April 2020 

**Table 3.2-1.  Baseline 24-Slot Constellation Slot Assignments as of the Defined Epoch** 

|**Slot**|**RAAN**|**Argument of**<br>**Latitude**|**GEC**<br>**(GLAN)**|
|---|---|---|---|
|**A1**|288.85|239.54|127.85|
|**A2***|288.85|133.20|74.68|
|**A3**|288.85|343.09|179.63|
|**A4**|288.85|13.22|14.69|
|**B1***|348.85|52.37|94.27|
|**B2**|348.85|144.75|140.46|
|**B3**|348.85|281.39|28.78|
|**B4**|348.85|175.79|155.98|
|**C1**|48.85|83.29|169.73|
|**C2**|48.85|343.21|119.69|
|**C3**|48.85|311.08|103.62|
|**C4***|48.85|212.97|54.57|
|**D1**|108.85|106.64|61.40|
|**D2***|108.85|236.86|126.51|
|**D3**|108.85|6.57|11.37|
|**D4**|108.85|138.77|77.47|
|**E1**|168.85|168.46|152.31|
|**E2**|168.85|274.01|25.09|
|**E3***|168.85|37.48|86.82|
|**E4**|168.85|305.10|40.63|
|**F1**|228.85|210.30|53.23|
|**F2***|228.85|316.64|106.40|
|**F3**|228.85|76.62|166.39|
|**F4**|228.85|106.76|1.46|



Notes: 

Epoch:  23:59:43 UTC, 31 December 2016 (Week 1930 / Time of Week 0000 GPS time) Leap second offset (GPS-UTC) transitioned from 17 to 18 sec at 23:59:60 UTC, 31 December 2016 

Greenwich Hour Angle:  100.765° Referenced to FK5/J2000.00 Coordinates Orbital Slot IDs are Arbitrarily Numbered 

- Orbital Slots Marked by an Asterisk are Expandable 

5th Edition 

Page 38

--- [page 49](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=49) ---

GPS SPS PS 

April 2020 

The expandable 24-slot constellation consists of the baseline 24-slot constellation modified to include at least one expandable slot occupied by a pair of satellites in its expanded configuration defined in Table 3.2-2.  The fore (F) and aft (A) locations in an expandable slot are defined relative to the baseline slot center in the direction of satellite motion.  Together, Tables 3.2-1 and 3.2-2 define a total of up to 30 orbital locations and 64 variations of the expandable-24 constellation. There are 6 variations to occupy 25 orbital locations using any 1 expanded slot, 15 variations to occupy 26 orbital locations using any 2 expanded slots, 20 variations to occupy 27 orbital locations using any 3 expanded slots, 15 variations to occupy 28 orbital locations using any 4 expanded slots, 6 variations to occupy 29 orbital locations using any 5 expanded slots, and 1 variation to occupy 30 orbital locations using all 6 expanded slots. 

**Table 3.2-2.  Expandable 24-Slot Constellation Slot Assignments as of the Defined Epoch** 

|**Expandable**|**Slot**|**RAAN**|**Argument of**<br>**Latitude**|**GEC**<br>**(GLAN)**|
|---|---|---|---|---|
|**B1 Exands To:**|**B1F**|348.85|66.33|101.25|
|**p**|**B1A**|348.85|37.77|86.97|
|**D2 Exands To:**|**D2F**|108.85|254.09|135.13|
|**p**|**D2A**|108.85|229.39|122.78|
|**F2 Exands To:**|**F2F**|228.85|331.87|114.02|
|**p**|**F2A**|228.85|305.43|100.80|
|**A2 Ed T**|**A2F**|288.85|144.40|80.28|
|**xpans o:**|**A2A**|288.85|117.96|67.06|
|**C4 Exands To:**|**C4F**|48.85|220.43|58.30|
|**p**|**C4A**|48.85|195.73|45.95|
|**E3 Ed T**|**E3F**|168.85|52.08|94.18|
|**xpans o:**|**E3A**|168.85|23.52|79.84|



Note that the actual satellite RAAN values will vary from the nominal values in Table 3.2-1 and Table 3.2-2 due to initial launch dispersion, perturbation forces acting over each satellite's lifetime (particularly the inclination-dependent forces due to the Earth’s geopotential oblateness [J2 term]), and variations in other forces affecting each unique satellite orbit nodal regression rate. Maintenance of the satellite argument of latitude (ArgLat)  values and relative spacing of the slots are the controls employed to compensate for orbit plane drift and sustain constellation geometry at acceptable levels.  It is also possible for the inclination to drift out of the operational range. 

5th Edition 

Page 39

--- [page 50](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=50) ---

GPS SPS PS 

April 2020 

**Table 3.2-3.  Reference Orbit Parameters** 

|**Reference Orbit Parameter **|**Nominal Value**|**Operational Range**|**Required Tolerance**|
|---|---|---|---|
|Semi-Major Axis, km|26,559.8|Note 1|Note 2|
|Eccentricity|0.0|0.0 to 0.02|0.0 to 0.03|
|Inclination, deg|55.0|3|N/A|
|RAAN, deg|Note 3|180|N/A|
|Argument of Perigee, deg|0.0|180|N/A|
|Argument of Latitude at<br>Epoch, deg|Note 3|180|Note 1|
|Nodal Regression Rate,<br>deg/day|-0.0402|N/A|N/A|



Note 1:  The satellite’s semi-major axis and orbital period will be adjusted to optimize the overlap between the satellite’s footprint on the surface of the Earth and the slot center’s footprint on the surface of the Earth.  For practical reasons, such as the prudent use of a satellite’s on-orbit fuel supply, the maximization of footprint overlaps will only be approximate. 

Note 2:  The nominal value shown provides stationary ground tracks. 

Note 3:  See Tables 3.2-1 and 3.2-2. 

5th Edition 

Page 40

--- [page 51](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=51) ---

GPS SPS PS 

April 2020 

###### **3.3  SPS SIS Coverage** 

This section provides the SPS SIS coverage standards. 

There are two components of SPS SIS coverage:  (1) the per-satellite coverage, and (2) the baseline/expandable 24-slot constellation coverage.  These two components are interrelated. The per-satellite coverage depends primarily on the satellite antenna subsystem design, the onorbit satellite pointing accuracy, and the satellite altitude (where the allowed range of satellite altitudes is defined by the 24-slot constellation architecture).  The baseline/expandable 24-slot constellation coverage depends primarily on the per-satellite coverage coupled with the baseline/expandable 24-slot constellation architecture. 

Each component of SPS SIS coverage shall be as specified below. 

###### **3.3.1  Per-Satellite Coverage** 

The terrestrial service volume for per-satellite coverage comprises the portion of the near-Earth region which extends from the surface of the Earth up to an altitude of 3,000 km above the surface of the Earth which is visible from the satellite's orbital position (i.e., those portions of the resulting spherical shell surrounding the Earth which are not otherwise physically obscured by the Earth or by localized obstructions).  The per-satellite coverage performance standards apply at the worstcase satellite antenna pointing angle relative to the Earth. 

The space service volume for per-satellite coverage comprises the near-Earth region which extends from an altitude of 3,000 km above the surface of the Earth up to and including 36,000 km above the Earth’s surface which is visible from the satellite's orbital position.  The space service volume coverage is limited by the transmitting satellite’s antenna gain pattern and freespace path loss.  The limits of coverage are determined by the received power contour surface of -182 dBW assuming a linear receiving antenna with a minimum gain that varies from +3 dBic at 3,000 km altitude to +7 dBic at 36,000 km altitude.  There are no explicit per-satellite coverage standards for the space service volume. 

The per-satellite coverage shall be as specified in Table 3.3-1. 

**Table 3.3-1.  SPS SIS Per-Satellite Coverage Standards** 

|**SIS Per-Satellite Coverage Standard**|**Conditions and Constraints**|
|---|---|
|Terrestrial Service Volume:|For any healthy or marginal SPS SIS|
|100% Coverage||
|Space Service Volume:||
|No Coverage Performance Specified||



_Notes:_ 

_1. The guaranteed minimum user-received SPS SIS power levels for the terrestrial service volume are specified in IS-GPS-200 and IS-GPS-705.  Although IS-GPS-200 and IS-GPS-705 uses a 5 degree elevation angle as the reference value for specifying the guaranteed minimum user-_ 

5th Edition 

Page 41

--- [page 52](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=52) ---

GPS SPS PS 

April 2020 

_received SPS SIS power levels, the per-satellite coverage is not restricted to just those locations where the satellite viewing angle is greater than or equal to 5 degrees above the local horizon.  The user-received SPS SIS power levels may be less than the guaranteed minimum at viewing angles below 5 degrees above the local horizon._ 

###### **3.3.2  Baseline/Expandable Constellation Coverage** 

The terrestrial service volume for the baseline 24-slot constellation and expandable 24-slot constellation coverage comprises the entire near-Earth region which extends from the surface of the Earth up to an altitude of 3,000 km above the surface of the Earth which is not physically obscured by localized obstructions. 

The space service volume for the baseline 24-slot constellation and expandable 24-slot constellation coverage comprises the near-Earth region which extends from an altitude of 3,000 km above the surface of the Earth up to and including 36,000 km above the Earth’s surface.  At certain times and locations in the space service volume, the baseline/expandable 24-slot constellations do not provide adequate coverage for instantaneous position solutions.  Users operating at those times and locations are therefore limited to time-filtered position solutions propagated over time.  There are no explicit constellation coverage standards for the space service volume. 

The constellation coverage shall be as specified in Table 3.3-2. 

**Table 3.3-2.  SPS SIS Constellation Coverage Standards** 

|**SIS Constellation Coverage Standard**|**Conditions and Constraints**|
|---|---|
|Terrestrial Service Volume:|From only healthy or marginal SPS SIS|
|100% Coverage||
|Space Service Volume:||
|No Coverage Performance Specified||



5th Edition 

Page 42

--- [page 53](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=53) ---

GPS SPS PS 

April 2020 

###### **3.4  SPS SIS Accuracy** 

This section provides the SPS SIS accuracy standards.  The SPS SIS accuracy standards apply to the SIS portion of the GPS error budgets for the user equivalent range error (UERE). 

There are four main aspects of SPS SIS accuracy.  The standards for each of these aspects are given in this section.  The four main aspects are: 

1. The pseudorange accuracy (i.e., “User Range Error” or URE) 

2. The time derivative of the URE (i.e., “User Range Rate Error” or URRE) 

3. The second time derivative of URE (i.e., “User Range Acceleration Error” or URAE) 

4. The UTC Offset Error (UTCOE) 

The standards for each of the four main aspects of SPS SIS accuracy are different depending on the operational application and/or condition of utilization.  Refer to Section A.4 in Appendix A for descriptions of the operational applications conditions of utilization.  Different SPS SIS accuracy standards are given in this section for: 

- a. Across all AODs versus at a specified AOD (i.e., either at zero AOD or at maximum AOD) 

- b. Normal operations versus extended operation (see paragraph A.4.3.2) 

- c. Any trackable and healthy SPS SIS versus across all trackable and healthy SPS SISs 

Regardless of SPS SIS component(s) or operational application/utilization, each of the four main aspects of SPS SIS accuracy are addressed in terms of a "global statistic" performance standard. In this case, "global statistic" means the statistic across the portion of the globe in view of the satellite (or constellation ensemble of satellites) over at least the ergodic period (see Appendix A for additional details on the meaning of "global statistic").  All of the SPS SIS performance standards in this section are expressed at the 95% probability level in accordance with international standards. 

The SPS SIS accuracy standards given in the following tables apply to the SPS SIS from all satellites regardless of whether they are occupying locations in the baseline/expandable 24-slot constellation or not.  These SPS SIS accuracy standards therefore apply equally to the SPS SIS from baseline/expandable slot satellites and from auxiliary satellites. 

_Notes:_ 

_1. The accuracy performance standards do not apply beyond the defined bounds of SPS SIS coverage (see Section 3.3)._ 

_2. The ergodic period contains the minimum number of samples such that the sample statistic is representative of the population statistic.  Under a one-upload-per-day scenario, for example, the traditional approximation for the URE ergodic period is 30 days._ 

_3. Normal operations and extended operations refer to two different GPS operating modes with distinctly different accuracy levels.  In the normal operations mode, the satellites are uploaded with fresh NAV message data by the Control Segment on a regular basis.  In the extended operations_ 

5th Edition 

Page 43

--- [page 54](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=54) ---

GPS SPS PS 

April 2020 

_mode, one or more satellites are_ _<u>not</u> uploaded with fresh NAV message data by the Control Segment on a regular basis.  See paragraph A.4.3.2 for additional information._ 

###### **3.4.1  SPS SIS URE Accuracy Standards** 

The SPS SIS URE accuracy shall be as specified in Table 3.4-1. 

**Table 3.4-1.  SPS SIS URE Accuracy Standards** 

|**SIS Accuracy Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|For any trackable and healthy SPS SIS<br> Neglecting SF ionospheric delay model<br>errors|
| 7.0 m 95% Global Statistic URE during<br>Normal Operations over all AODs<br>  3.8 m 95% Global Statistic URE during<br>Normal Operations at Zero AOD|Including group delay time correction (TGD)<br>errors at L1<br> Including inter-signal bias (P(Y)-code to<br>C/A-code) errors at L1<br> Including ISC errors|
| 9.7 m 95% Global Statistic URE during<br>Normal Operations at Any AOD||
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>  30 m 99.94% Global Statistic URE during<br>Normal Operations<br>  30 m 99.79% Worst Case Single Point<br>Statistic URE during Normal Operations|For any trackable and healthy SPS SIS<br> Neglecting SF ionospheric delay model<br>errors<br> Including group delay time correction (TGD)<br>errors at L1<br> Including inter-signal bias (P(Y)-code to<br>C/A-code) errors at L1<br> Including ISC errors<br> Standard based on measurement interval<br>of one year; statistic of daily values within<br>the service volume<br> Standard based on 3 service failures per<br>year, lasting no more than 6 hours each|
|SF C/A-Code:<br>  388 m 95% Global Statistic URE during<br>Extended Operations after 14 Days without<br>Upload|For any trackable and healthy SPS SIS|
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>  2.0 m 95% Global Statistic URE during<br>Normal Operations over all AODs for the<br>ensemble of constellation slots|Across all trackable and healthy SPS SISs<br>from satellites occupying constellation slots<br> Neglecting SF ionospheric delay model<br>errors<br> Including group delay time correction (TGD)<br>errors at L1<br> Including inter-signal bias (P(Y)-code to<br>C/A-code) errors at L1<br> Including ISC errors|



5th Edition 

Page 44

--- [page 55](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=55) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. For SF URE, see Appendix A for information on how to factor in the SF ionospheric delay model errors for L1.  SF ionospheric delay model errors are specifically excluded from the SPS SIS URE standard as an explicit constraint to emphasize they are neglected despite the fact that the SF ionospheric delay model parameters are part of the broadcast SPS SIS._ 

_2. The “over all AODs” performance standards are the ones which are the most directly representative of the URE experienced by SPS receivers.  See Appendix A for further information._ 

_3. The ≤ 7.0 m 95% SPS SIS URE performance standard is statistically equivalent to a ≤ 3.6 m RMS SPS SIS URE performance standard, assuming a normal distribution with zero mean._ 

_4. Numerical values apply to the absolute value of the “95% global statistic URE”._ 

###### **3.4.2  SPS SIS URRE Accuracy Standards** 

The SPS SIS URRE accuracy shall be as specified in Table 3.4-2. 

**Table 3.4-2.  SPS SIS URRE Accuracy Standards** 

|**SIS Accuracy Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>   0.006 m/sec 95% Global Statistic URRE<br>over any 3-second interval during Normal|For any trackable and healthy SPS SIS<br> Neglecting all perceived pseudorange rate<br>errors attributable to pseudorange step<br>changes caused by NAV message data<br>cutovers|
|Operations at Any AOD|Neglecting SF ionospheric delay model<br>errors|



_Notes:_ 

_1. The normal operations performance standards are consistent with an early GPS Block II clock stability of 1x10_<sup>_-11_</sup> _at a tau of 3 seconds for either Rubidium clocks or Cesium clocks._ 

_2. Root-sum-squaring the SIS-caused URRE with the receiver-caused pseudorange rate error, and neglecting any correlated components, the combined pseudorange rate error perceived by the GPS receiver is known as the User Equivalent Range Rate Error (UERRE)._ 

_3. Because all SIS components are coherently derived onboard each satellite, the URRE performance standard applies equally to the transmitted code rate error and transmitted carrier rate error._ 

_4. Numerical values apply to the absolute value of the “95% global statistic URRE”._ 

###### **3.4.3  SPS SIS URAE Accuracy Standards** 

The SPS SIS URAE accuracy shall be as specified in Table 3.4-3. 

5th Edition 

Page 45

--- [page 56](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=56) ---

GPS SPS PS 

April 2020 

**Table 3.4-3.  SPS SIS URAE Accuracy Standards** 

|**SIS Accuracy Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|For any trackable and healthy SPS SIS<br> Neglecting all perceived pseudorange<br>acceleration errors attributable to|
| 0.002 m/sec/sec 95% Global Statistic<br>URAE over any 3-second interval during<br>Normal Operations at Any AOD|pseudorange step changes caused by<br>NAV message data cutovers<br> Neglecting SF ionospheric delay model<br>errors|



_Notes:_ 

_1. The normal operations performance standards are consistent with an early GPS Block II clock stability of 1x10_<sup>_-11_</sup> _at a tau of 3 seconds for either Rubidium clocks or Cesium clocks._ 

_2. Root-sum squaring the SIS-caused URAE with the receiver-caused pseudorange acceleration error, and neglecting any correlated components, the combined pseudorange acceleration error perceived by the GPS receiver is known as the User Equivalent Range Acceleration Error (UERAE)._ 

_3. Because all SIS components are coherently derived onboard each satellite, the URAE performance standard applies equally to the transmitted code acceleration error and transmitted carrier acceleration error._ 

_4. Numerical values apply to the absolute value of the “95% global statistic URAE”._ 

###### **3.4.4  SPS SIS UTCOE Accuracy Standards** 

The SPS SIS UTCOE accuracy shall be as specified in Table 3.4-4. 

**Table 3.4-4.  SPS SIS UTCOE Accuracy Standards** 

|**SIS Accuracy Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|For any trackable and healthy SPS SIS|
| 30 ns 95% Global Statistic UTCOE during<br>Normal Operations at Any AOD||



_Notes:_ 

_1. This is the accuracy of the UTC(USNO) offset data in the broadcast navigation message portion of the SPS SIS which relates GPS time (as maintained by the Control Segment) to UTC (as maintained by the U.S. Naval Observatory)._ 

_2. Root-sum squaring the UTCOE with a receiver’s solution accuracy for GPS time gives the total UTC accuracy for that receiver.  See Appendix B for further information._ 

_3. Numerical values apply to the absolute value of the “95% global statistic UTCOE”._ 

5th Edition 

Page 46

--- [page 57](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=57) ---

GPS SPS PS 

April 2020 

###### **3.5  SPS SIS Integrity** 

This section provides the SPS SIS integrity standards.  For a positioning/timing system, integrity is defined as the trust which can be placed in the correctness of the positioning/timing information provided by the system.  Integrity includes the ability of that system to provide timely alerts when it should not be used for positioning/timing.  See Appendix A, Section A.5 for further definition. 

The SPS SIS integrity standards given in the following tables apply to the SPS SIS from all satellites regardless of whether they are occupying locations in the baseline/expandable 24-slot constellation or not.  These SPS SIS integrity standards therefore apply equally to the SPS SIS from baseline/expandable slot satellites and from auxiliary satellites. 

A timely alert is defined to be an alert provided at the GPS receiver antenna no later than 8 seconds after an instantaneous error exceeds the relevant NTE tolerance for any alert method except SatZap and non-standard code (NSC).  An additional 2 seconds is assumed for the GPS receiver response time.  For SatZap and NSC, a timely alert is defined to be an alert provided at the GPS receiver antenna no later than 10 seconds after an instantaneous error exceeds the relevant NTE tolerance. 

###### **3.5.1  SPS SIS Instantaneous URE Integrity Standards** 

The SPS SIS instantaneous URE integrity shall be as specified in Table 3.5-1. 

**Table 3.5-1.  SPS SIS Instantaneous URE Integrity Standards** 

|**SIS Integrity Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>  1x10<sup>-5</sup>Probability Over Any Hour of the<br>SPS SIS Instantaneous URE Exceeding the<br>NTE Tolerance Without a Timely Alert|Applies to any trackable and healthy SPS<br>SIS<br> SPS SIS URE NTE tolerance defined to be<br>4.42 times the relevant IAURA value<br>currently broadcast by the satellite<br> Given that the maximum SPS SIS<br>instantaneous URE did not exceed the<br>NTE tolerance at the start of the hour<br> UMSI occurs if no timely alert issued after<br>SPS SIS URE NTE tolerance exceeded<br> Worst case for delayed alert is 6 hours<br> Neglecting SF ionospheric delay model<br>errors|



For the maximum possible 32 satellites in the current broadcast LNAV almanac (baseline/expandable slot satellites plus auxiliary satellites), the corresponding average annual number of SPS SIS instantaneous URE integrity losses is 3.  Assuming each of these 3 losses of SPS SIS integrity lasts for no more than 6 hours, the equivalent worst-case probability of users experiencing UMSI is 18 hours divided by 8760 hours or 0.002.  For an average 1-hour loss of SPS SIS instantaneous URE integrity, recognizing that each satellite is only visible to a third of the Earth at any one time, the equivalent average probability of users experiencing UMSI is approximately 1 hour divided by 8760 hours or 0.0001. 

5th Edition 

Page 47

--- [page 58](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=58) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. In 1 year, 32 satellites each continuously transmitting a trackable and healthy SPS SIS will accumulate a total of approximately 2.8x10_<sup>_+5_</sup> _hours of operation.  For a probability of 1x10_<sup>_-5_</sup> _/hour of maintaining integrity, the expected number of losses of SPS SIS integrity in 1 year across the entire constellation is approximately 3._ 

_2. The worst-case probability of a user experiencing UMSI assumes that each of the 3 losses of SPS SIS integrity results in UMSI for 6 hours and that the worst-case user is unlucky enough to be using each of the 3 satellites during the full duration of each loss of SPS SIS integrity._ 

_3. The duration statistics for losses of SPS SIS integrity are: (a) worst case ≤ 6 hours, (b) 99.9_<sup>_th_</sup> _percentile ≤ 3 hours, (c) 50_<sup>_th_</sup> _percentile ≤ 1 hour._ 

###### **3.5.2  SPS SIS Instantaneous URRE Integrity Standards** 

The SPS SIS instantaneous URRE (i.e., pseudorange rate error) integrity shall be as specified in Table 3.5-2. 

**Table 3.5-2.  SPS SIS Instantaneous URRE Integrity Standards** 

|**SIS Integrity Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|A future edition of this_SPS PS_may<br>establish a standard|
| No Integrity Performance Specified||



_Notes:_ 

_1. Although there is no SPS SIS URRE NTE tolerance defined, a high-probability (6-sigma) upper bound on the SPS SIS Instantaneous URRE which is typically used for design purposes is 0.02 m/sec over any 3-second interval during normal operations at any AOD.  This is consistent with an early Block II clock stability of 1x10_<sup>_-11_</sup> _at a tau of 3 seconds for either Rubidium clocks or Cesium clocks._ 

_2. Short-term fluctuations in the ionosphere can produce very large SPS SIS instantaneous URREs for SF C/A-Code operations._ 

_3. Instantaneous URREs due to upload data cutovers and data set pageovers last for less than 3 seconds._ 

5th Edition 

Page 48

--- [page 59](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=59) ---

GPS SPS PS 

April 2020 

###### **3.5.3  SPS SIS Instantaneous URAE Integrity Standards** 

The SPS SIS instantaneous URAE (i.e., pseudorange acceleration error) integrity shall be as specified in Table 3.5-3. 

**Table 3.5-3.  SPS SIS Instantaneous URAE Integrity Standards** 

|**SIS Integrity Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|A future edition of this_SPS PS_may<br>establish a standard|
| No Integrity Performance Specified||



_Notes:_ 

_1. Although there is no SPS SIS URAE NTE tolerance defined for SF operation, a high-probability upper bound on the SPS SIS Instantaneous URAE which is typically used for design purposes is 0.007 m/sec/sec over any 3-second interval during normal operations at any AOD.  This is consistent with an early Block II clock stability of 1x10_<sup>_-11_</sup> _at a tau of 3 seconds for either Rubidium clocks or Cesium clocks._ 

_2. Short-term fluctuations in the ionosphere can produce extremely large SPS SIS instantaneous URAEs for SF operations._ 

_3. Instantaneous URAEs due to upload data cutovers and data set pageovers last for less than 3 seconds._ 

###### **3.5.4  SPS SIS Instantaneous UTCOE Integrity Standards** 

The SPS SIS instantaneous UTCOE (i.e., UTC(USNO) offset error) integrity shall be as specified in Table 3.5-4. 

**Table 3.5-4.  SPS SIS Instantaneous UTCOE Integrity Standards** 

|**SIS Integrity Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:|Applies to any trackable and healthy SPS<br>SIS<br> SPS SIS UTCOE NTE tolerance defined to|
| 1x10<sup>-5</sup>Probability Over Any Hour of the<br>SPS SIS Instantaneous UTCOE Exceeding|be120 ns<br> Given that the maximum SPS SIS|
|the NTE Tolerance Without a Timely Alert<br>during Normal Operations|instantaneous URE did not exceed the<br>NTE tolerance at the start of the hour<br> Worst case for delayed alert is 6 hours|



_Notes:_ 

_1. This is the integrity of the UTC(USNO) offset data in the broadcast navigation message portion of the SPS SIS which relates GPS time (as maintained by the Control Segment) to UTC (as maintained by the U.S. Naval Observatory)._ 

5th Edition 

Page 49

--- [page 60](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=60) ---

GPS SPS PS 

April 2020 

_2. Adding the UTCOE to a receiver’s solution error for GPS time gives the total UTC error for that receiver.  See Appendix B for further information._ 

###### **3.5.5  Psat and Pconst Standards** 

The SPS SIS instantaneous Psat and Pconst shall be as specified in Table 3.5-5. 

**Table 3.5-5.  SPS SIS Instantaneous Psat and Pconst Standards** 

|**SIS Integrity Standard**|**Conditions and Constraints**|
|---|---|
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>  1x10<sup>-5</sup>Fraction of Time When the SPS SIS<br>Instantaneous URE Exceeds the NTE<br>Tolerance Without a Timely Alert (Psat)|Applies to any trackable and healthy SPS<br>SIS<br> SPS SIS URE NTE tolerance defined to be<br>4.42 times the relevant IAURA value<br>currently broadcast by the satellite<br> Average case for delayed alert is 1 hour<br> Neglecting SF ionospheric delay model<br>errors|
|Each SPS SIS Component Combination per<br>Table 2.2-2:<br>  1x10<sup>-8</sup>Fraction of Time When the SPS SIS<br>Instantaneous URE from Two or More<br>Satellites Exceeds the NTE Tolerance Due to<br>a Common Cause Without a Timely Alert<br>(**Pconst**)|Applies across all trackable and healthy<br>SPS SIS<br> SPS SIS URE NTE tolerance defined to be<br>4.42 times the relevant IAURA value<br>currently broadcast by the satellite<br> Average case for delayed alert is 1 hour<br> Neglecting SF ionospheric delay model<br>errors|



_Notes:_ 

_1. The difference between the Psat in Table 3.5-5 and the probability of UMSI (P(UMSI)) in Table 3.51 is the duration._ 

_2. Common cause faults are assumed to have common mode effects._ 

_3. Per satellite fault modes are assumed to be independent with high probability._ 

5th Edition 

Page 50

--- [page 61](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=61) ---

GPS SPS PS 

April 2020 

###### **3.6  SPS SIS Continuity** 

This section provides the SPS SIS continuity standards.  The SPS SIS continuity for a trackable and healthy SPS SIS is the probability that the SPS SIS will continue to be healthy and trackable without unscheduled interruption over a specified time interval. 

Planned interruptions of the SPS are subject to a minimum of 48-hour advance notice provided by the Control Segment to the Coast Guard Navigation Center and the FAA Notice to Airmen (NOTAM) system (e.g., scheduled satellite maintenance).  An interruption is defined as a period in which the SIS from a satellite does not comply with the standards defined in this _SPS PS_ .  A scheduled interruption is defined as a period announced at least 48 hours in advance in which the SIS from a satellite is not planned to comply with the standards defined in this _SPS PS_ . Unscheduled interruptions resulting from system malfunctions or maintenance occurring outside the scheduled period will be announced to the Coast Guard and the FAA as soon as possible. Scheduled interruptions which are announced at least 48 hours in advance do not constitute a loss of continuity. 

###### **3.6.1  SPS SIS Continuity Standards – Unscheduled Failure Interruptions** 

The SPS SIS continuity shall be as specified in Table 3.6-1 for the composite of all unscheduled interruptions in service (long-term [LT] hard failures, short term [ST] hard failures, soft failures, as well as end-of-life [EOL] failures and satellite O&M activity interruptions without a timely NANU; see Section A.6). 

**Table 3.6-1.  SPS SIS Unscheduled Failure Interruption Continuity Standards** 

|**SIS Continuity Standard**|**Conditions and Constraints**|
|---|---|
|Unscheduled Failure Interruptions of SF C/A-<br>Code:|Calculated as an average over all slots in<br>the 24-slot constellation, normalized<br>annually|
|  0.9998 Probability Over Any Hour of Not<br>Losing the SPS SIS Availability from a Slot<br>Due to Unscheduled Interruption|Given that SF C/A-Code is available from<br>the slot at the start of the hour|
||NANU timeliness standard per Table 3.6-3|



_Note:_ 

_1. At this point in time, there are no unscheduled failure interruption continuity standards for any SPS SIS component combination per Table 2.2-2 other than SF C/A-code._ 

###### **3.6.2  SPS SIS Continuity Standards – Unscheduled Maintenance Interruptions** 

The SPS SIS continuity shall be as specified in Table 3.6-2 for the composite of all unscheduled maintenance interruptions in service (e.g. planned EOL failure events and satellite O&M activity interruptions; see Section A.6). 

5th Edition 

Page 51

--- [page 62](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=62) ---

GPS SPS PS 

April 2020 

**Table 3.6-2.  SPS SIS Unscheduled Maintenance Interruption Continuity Standards** 

|**SIS Continuity Standard**|**Conditions and Constraints**|
|---|---|
|Unscheduled Maintenance Interruptions:<br> No Performance Specified|A future edition of this_SPS PS_may<br>establish a standard|



_Note:_ 

_1. Table 3.6-2 is effectively a placeholder for a future standard that defines the level of rigor the Control Segment must maintain in issuing the NANUs._ 

###### **3.6.3 Status and Problem Reporting Standards** 

The commitments for maintaining continuity result in support for status and problem reporting standards as presented in Table 3.6-3. 

**Table 3.6-3.  SPS Status and Problem Reporting Standards** 

|**Status and Problem Reporting Standard**|**Conditions and Constraints**|
|---|---|
|Scheduled Event Affecting Service<br>Appropriate NANU issued to the Coast Guard<br>and the FAA at least 48 hours prior to the event<br>for 95% of the events|For any SPS SIS Component Combination<br>per Table 2.2-2|
|Unscheduled Outage or Problem Affecting<br>Service|For any SPS SIS Component Combination<br>per Table 2.2-2|
|Appropriate NANU issued to the Coast Guard<br>and the FAA as soon as possible after the event||



_Notes:_ 

_1. A CS internal goal (not a performance standard) is to issue the NANU 96 hours prior to the event._ 

_2. NANUs not issued at least 48 hours prior to a scheduled event affecting service means the scheduled event counts against the “Unscheduled Failure Interruption Continuity Standards” per paragraph 3.6.1._ 

5th Edition 

Page 52

--- [page 63](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=63) ---

GPS SPS PS 

April 2020 

###### **3.7  SPS SIS Availability** 

This section provides the SPS SIS availability standards. 

There are two components of SPS SIS availability:  (1) the per-slot availability, and (2) the constellation availability.  These two components are related.  The per-slot availability depends primarily on the satellite design and the Control Segment procedures for on-orbit maintenance and failure response.  The constellation availability depends primarily on the per-slot availability coupled with the satellite launch policies and satellite disposal criteria. 

Each component of SPS SIS availability shall be as specified below.  These availability standards apply to satellites broadcasting PRN codes numbered in the range of 1 to 32.  Satellites broadcasting higher numbered PRN codes (“expanded PRN codes”) are not eligible for satisfying these availability standards due to backward compatibility limitations. 

This section also provides the operational satellite count standard. 

_Notes:_ 

_1. The term "operational satellite" applies to any satellite which appears in the current almanac data (e.g., subframe 4 or 5 of the LNAV message).  This designation is used even when a satellite’s SIS is untrackable or is set unhealthy.  It applies to nearly every satellite in the constellation._ 

_2. At this point in time, there are no SPS SIS availability standards for any SPS SIS component combination per Table 2.2-2 other than SF C/A-code._ 

_3. A slot is occupied by a satellite when the satellite’s footprint on the surface of the Earth overlaps 95% of the slot center’s footprint on the surface of the Earth averaged over an orbit revolution._ 

_4. Satellites operating satisfactorily beyond their design life may be administratively declared as occupying their assigned slot even if the satellite’s footprint on the Earth’s surface fails to overlap 95% of the slot center’s footprint on the Earth’s surface averaged over an orbit revolution._ 

###### **3.7.1  SPS SIS Per-Slot Availability Standards** 

The SPS SIS per-slot availability shall be as specified in Table 3.7-1 for slots in either the baseline 24-slot constellation configuration or the expandable 24-slot constellation configuration. 

**Table 3.7-1.  SPS SIS Per-Slot Availability Standards** 

|**SIS Availability Standard**|**Conditions and Constraints**|
|---|---|
|  0.957 Probability that a Slot in the Baseline<br>24-Slot Configuration will be Occupied by a<br>Satellite Broadcasting a Healthy SF C/A-<br>Code SPS SIS<br>   0.957 Probability that a Slot in the<br>Expanded Configuration will be Occupied by<br>a Pair of Satellites Each Broadcasting a<br>Healthy SF C/A-Code SPS SIS|Calculated as an average over all slots in<br>the 24-slot constellation, normalized<br>annually<br> Applies to satellites broadcasting a healthy<br>SF C/A-Code SPS SIS which also satisfy<br>the other performance standards in this<br>_SPS PS_|



5th Edition 

Page 53

--- [page 64](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=64) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. The SPS SIS availability standards given in Tables 3.7-1 apply to the SPS SIS from all slots in the 24-slot constellation._ 

_2. Expanded slot availability includes occupancy by a pair of satellites in an equivalent-or-better nonstandard configuration.  See Section A.7 in Appendix A for example equivalent-or-better nonstandard configurations._ 

_3. The loss of availability caused by an expanded slot which has lost one of its pair of satellites can be remedied by either replacing the lost satellite or by returning the slot back to its baseline configuration.  See Section A.7 in Appendix A for further information._ 

_4. These SPS SIS availability standards do not apply to auxiliary satellites not occupying a slot in the 24-slot constellation._ 

_5. The SPS SIS per-slot availability measurement interval must be substantially longer than the mean time between per-slot interruptions and the mean time to restore per-slot availability._ 

###### **3.7.2  SPS SIS Constellation Availability Standards** 

The SPS SIS constellation availability shall be as specified in Table 3.7-2 for the ensemble of all 24 slots in either the baseline 24-slot configuration or the expandable 24-slot configuration. 

**Table 3.7-2.  SPS SIS Constellation Availability Standards** 

|**SIS Availability Standard**|**Conditions and Constraints**|
|---|---|
|  0.98 Probability that at least 21 Slots out of<br>the 24 Slots will be Occupied Either by a<br>Satellite Broadcasting a Healthy SF C/A-<br>Code SPS SIS in the Baseline 24-Slot<br>Configuration or by a Pair of Satellites Each<br>Broadcasting a Healthy SF C/A-Code SPS<br>SIS in the Expanded Slot Configuration<br>   0.99999 Probability that at least 20 Slots<br>out of the 24 Slots will be Occupied Either by<br>a Satellite Broadcasting a Healthy SF C/A-<br>Code SPS SIS in the Baseline 24-Slot<br>Configuration or by a Pair of Satellites Each<br>Broadcasting a Healthy SF C/A-Code SPS<br>SIS in the Expanded Slot Configuration|Calculated as an average over all slots in<br>the 24-slot constellation, normalized<br>annually<br> Applies to satellites broadcasting a healthy<br>SF C/A-Code SPS SIS which also satisfies<br>the other performance standards in this<br>_SPS PS_|



_Notes:_ 

_1. So long as at least 21 slots out of the 24 slots are occupied either by a satellite broadcasting a trackable and healthy SPS SIS in the baseline 24-slot configuration or by a pair of satellites each broadcasting a trackable and healthy SPS SIS in the expanded slot configuration, the all-in-view position dilution of precision (PDOP) with a mask angle of 5 degrees will be 6 or less for:  a) 98% of the global average over any sidereal day, and b) 88% at the worst site over any sidereal day. See Appendix A for further information._ 

5th Edition 

Page 54

--- [page 65](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=65) ---

GPS SPS PS 

April 2020 

_2. Expandable slots occupied by a pair of satellites in the expanded configuration can provide more robust constellation availability to enhance the overall SPS SIS performance.  However, since there are no standards given in this SPS PS for the probabilities of the expandable slots being in their expanded configurations and occupied by pairs of satellites, no credit can be taken for them relative to the baseline 24-slot constellation availability with all slots in their baseline configuration._ 

_3. The SPS SIS constellation availability measurement interval must be substantially longer than the mean time between constellation interruptions and the mean time to restore constellation availability._ 

###### **3.7.3  Operational Satellite Count Standards** 

The total number of operational satellites in the constellation shall be as specified in Table 3.7-3. 

**Table 3.7-3.  Operational Satellite Count Standards** 

|**Operational Satellite Count Standard**|**Conditions and Constraints**|
|---|---|
|  0.95 Probability that the Constellation will<br>Have at least 24 Operational Satellites<br>Regardless of Whether Those Operational<br>Satellites are Located in Slots or Not|Applies to the total number of operational<br>satellites in the constellation (averaged<br>over any day); where any satellite which<br>appears in the transmitted navigation<br>message almanac is defined to be an<br>operational satellite regardless of whether<br>that satellite is currently broadcasting a<br>trackable and healthy SPS SIS or not and<br>regardless of whether the broadcast SPS<br>SIS also satisfies the other performance<br>standards in this_SPS PS_or not|



5th Edition 

Page 55

--- [page 66](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=66) ---

GPS SPS PS 

April 2020 

###### **3.8  SPS Position/Time Domain Standards** 

This section provides the SPS position/time domain performance standards.  SPS position/time domain performance standards are a key element of backward compatibility and are based on a specific set of receiver assumptions.  The user assumptions include the error exclusions identified in paragraph 2.4.5 as well as the following SPS receiver assumptions. 

The use of a representative SPS receiver that: 

- is designed in accordance with IS-GPS-200. 

- is tracking the SF C/A-code SPS SIS from all satellites in view above a 5° mask angle with respect to the local horizon (no local obscura are considered).  It is assumed the receiver is operating in a nominal noise environment that does not interrupt receiver acquisition and tracking capabilities. 

- accomplishes satellite position and geometric range computations in the most current realization of the World Geodetic System 1984 (WGS 84) Earth-Centered, Earth-Fixed (ECEF) coordinate system. 

- • generates a position/time domain solution from data broadcast by all satellites in view transmitting PRNs 1-32. 

- compensates for dynamic Doppler shift effects on nominal SPS ranging signal carrier phase and C/A-code measurements. 

- processes the health-related information in the SIS and excludes marginal and unhealthy SISs from the position solution. 

- ensures up-to-date and internally consistent CEI and UTC offset (UTCO) data within the respective curve fit intervals for all satellites used in the position solution. 

- generates range rate measurements using carrier phase tracking (for velocity solution). 

- loses track in the event a GPS satellite stops transmitting a trackable SIS. 

- is operating at a surveyed location (for a time transfer receiver). 

The SPS position/time domain performance standards are defined for a position/time solution meeting the representative receiver conditions and operating within the service volume over any sidereal day (approximately 24-hour interval).  For information regarding different receiver assumptions, see Appendix B. 

5th Edition 

Page 56

--- [page 67](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=67) ---

GPS SPS PS 

April 2020 

###### **3.8.1  PDOP Availability Standards** 

The commitments for maintaining the constellation (Sections 3.2 and 3.7) and coverage (Section 3.3) result in support for position dilution of precision (PDOP) standards presented in Table 3.81. 

**Table 3.8-1.  PDOP Availability Standards** 

|**PDOP Availability Standard**|**Conditions and Constraints**|
|---|---|
|≥ 98% global PDOP of 6 or less||
|≥ 88% worst site PDOP of 6 or less||



###### **3.8.2  SPS Position Availability Standards** 

The commitments for maintaining PDOP (Table 3.8-1) and SPS SIS URE accuracy (Table 3.4-1) result in support for position availability standards as presented in Table 3.8-2. 

**Table 3.8-2.  SPS Position Availability Standards** 

|**Position Availability Standard**|**Conditions and Constraints**|
|---|---|
|≥ 99% Horizontal Service Availability, average<br>location|15 m horizontal (SIS only) 95% threshold<br> 33 m vertical (SIS only) 95% threshold|
|≥ 99% Vertical Service Availability, average<br>location||
|≥ 90% Horizontal Service Availability, worst-<br>case location|15 m horizontal (SIS only) 95% threshold<br> 33 m vertical (SIS only) 95% threshold|
|≥ 90% Vertical Service Availability, worst-case<br>location||



5th Edition 

Page 57

--- [page 68](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=68) ---

GPS SPS PS 

April 2020 

###### **3.8.3  SPS Position/Velocity/Time Accuracy Standards** 

The commitments for maintaining PDOP (Table 3.8-1), SPS SIS URE accuracy (Table 3.4-1), and SPS SIS URRE accuracy (Table 3.4-2) result in support for position/velocity/time accuracy standards as presented in Table 3.8-3. 

**Table 3.8-3.  SPS Position/Velocity/Time Accuracy Standards** 

|**Position/Time Accuracy Standard**|**Conditions and Constraints**|
|---|---|
|Global Average Position Accuracy<br> ≤ 8 m 95% Horizontal Error<br> ≤ 13m95%Vertical Error|Defined for a position/time solution meeting<br>the representative user conditions<br> Position/time solution is available|
|Worst Site Position Accuracy<br> ≤ 15 m 95% Horizontal Error<br> ≤ 33 m 95% Vertical Error|Defined for a position/time solution meeting<br>the representative user conditions<br> Position/time solution is available|
|Global Average Velocity Accuracy<br> ≤ 0.2 m/sec 95% velocity error, any axis|Defined for a position/velocity/time solution<br>meeting the representative user conditions<br> Position/velocity/time solution is available|
|Time Transfer Accuracy<br> ≤ 30 ns Time Transfer error 95% of time (SIS<br>only)|Defined for a time transfer solution meeting<br>the representative user conditions<br> Time transfer solution is available|



5th Edition 

Page 58

--- [page 69](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=69) ---

GPS SPS PS 

April 2020 

### **SECTION 4.0  References** 

This section identifies the Government documents and non-Government documents explicitly referenced in or related to the content of this _SPS PS_ . 

###### **4.1  Government Documents** 

###### **<u>SPECIFICATIONS:</u>** 

###### <u>Federal</u> 

|8 December 1993|_Global Positioning System Standard Positioning Service_<br>_Signal Specification, (1_<sup>_st_</sup> _Edition)_|
|---|---|
|2 June 1995|_Global Positioning System Standard Positioning Service_<br>_Signal Specification, 2_<sup>_nd_</sup>_Edition)_|
|4 October 2001|_Global Positioning System Standard Positioning Service_<br>_Performance Standard, 3_<sup>_rd_</sup> _Edition_|
|23 February 2007|_Global Positioning System Precise Positioning Service_<br>_Performance Standard, 1_<sup>_st_</sup>_Edition_|
|September 2008|_Global Positioning System Standard Positioning Service_<br>_Performance Standard, 4_<sup>_th_</sup>_Edition_|
|Military||



None 

|Program||
|---|---|
|SS-GPS-300G|_System Specification for the Navstar Global Positioning_|
|5 August 2005|_System_|
|Other Government A|ctivity|
|10 USC 2281|_Title 10 United States Code, Section 2281_|
|NIMA TR8350.2|_Department of Defense_|
|3 January 2000|_World Geodetic System 1984_<br>_Its Definition and Relationship with Local Geodetic Systems_|



###### **<u>STANDARDS:</u>** 

###### <u>Federal</u> 

|TSO-C145e|Technical Standard Order (TSO),_Airborne Navigation_|
|---|---|
|5 May 2017|_Sensors Using the Global Positioning System Augmented_|
||_By The Satellite Based Augmentation System (SBAS)_|



5th Edition 

Page 59

--- [page 70](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=70) ---

GPS SPS PS 

April 2020 

|TSO-C146e<br>5 May 2017|Technical Standard Order (TSO),_Stand-Alone Airborne_<br>_Navigation Equipment Using the Global Positioning System_<br>_Augmented by The Satellite Based Augmentation System_<br>_(SBAS)_|
|---|---|
|TSO-C196b<br>20 December 2013|Technical Standard Order (TSO),_Airborne Supplemental_<br>_Navigation Sensors for Global Positioning System_<br>_Equipment Using Aircraft-Based Augmentation_|
|31 October 2008|_Global Positioning System Wide Area Augmentation_<br>_System (WAAS) Performance Standard, 1_<sup>_st_</sup>_Edition_|
|Military||
|MSO-C129b<br>13 October 2005|Military Standard Order (MSO),_Airborne Supplemental_<br>_Navigation Equipment Using the Global Positioning System_<br>_(GPS) / Precise Positioning Service (PPS)_|
|MSO-C145b<br>12 August 2016<br>_Precise Positioni_|Military Standard Order (MSO),_Airborne Navigation_<br>_Sensors Using the Global Positioning System (GPS) /_<br>_ng Service (PPS) for Area Navigation (RNAV)_<br>_in Required Navigation Performance (RNP) Airspace and_<br>_for Automatic Dependent Surveillance- Broadcast (ADS-B)_|
|Program||
|IS-GPS-200<br>Current Revision|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-200H<br>24 September 2013|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-200G<br>5 September 2012|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-200F<br>21 September 2011|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-200E<br>8 June 2010|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-200D<br>7 December 2004|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|ICD-GPS-200C<br>10 October 1993|_Navstar GPS Space Segment / Navigation User_<br>_Interfaces_|
|IS-GPS-705<br>Current Revision|_Navstar GPS Space Segment / User Segment L5_<br>_Interfaces_|



###### <u>Other Government Activity</u> 

5th Edition 

Page 60

--- [page 71](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=71) ---

GPS SPS PS 

April 2020 

###### **<u>OTHER PUBLICATIONS:</u>** 

###### <u>Manuals</u> 

None 

###### <u>Regulations</u> 

None 

###### <u>Plans</u> 

DOT-VNTSC-OST-R-15-01 _2017 Federal Radionavigation Plan_ (FRP) 20 September 2017 

###### <u>Miscellaneous</u> 

28 December 2001 Headquarters Air Force Space Command _Concept of Operations for the Global Positioning System_ (Also known as the “ _GPS CONOPS_ ”) Tech Report No. 96 U.S. Air Force Aeronautical Chart and Information Center, February 1962 _Principles of Error Theory and Cartographic Applications_ Publication No. 9 N. Bowditch; _The American Practical Navigator, an Epitome_ 2002 _of Navigation; 2002 Bicentennial Edition_ ; prepared and published by the National Imagery and Mapping Agency; Bethesda, MD AC 20-138D Federal Aviation Administration Advisory Circular (AC) Change 2 _Airworthiness Approval of Positioning and_ 4 April 2016 _Navigation Systems_ AC 90-96A Federal Aviation Administration Advisory Circular (AC) Change 1 _Approval of U.S. Operators and Aircraft to Operate Under_ 12 November 2010 _Instrument Flight Rules (IFR) in European Airspace d Designate for Basic Area Navigation (BRNAV) and Precision Area Navigation (PRNAV)_ TOR S3-G-89-01 Technical Operating Report (TOR) 23 March 1989 _Navstar Global Positioning System Standardized Accuracy Definitions and Relationships_ 

5th Edition 

Page 61

--- [page 72](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=72) ---

GPS SPS PS 

April 2020 

###### **4.2  Non-Government Documents** 

###### **<u>SPECIFICATIONS:</u>** 

None 

###### **<u>STANDARDS:</u>** 

SARPs Annex 10 International Civil Aviation Organization (ICAO) Amendment 89 _Annex 10 to the Convention on International Civil Aviation,_ 13 November 2014 _International Standards and Recommended Practices, Aeronautical Telecommunications, Volume 1, Radio Navigation Aids_ RTCA/DO-229E RTCA Document, Special Committee 159 15 December 2016 _Minimum Operational Performance Standards for Global Positioning System/Wide Area Augmentation System Airborne Equipment_ RTCA/DO-236C RTCA Document, Special Committee 181 23 September 2014 _Minimum Aviation System Performance Standards: Required Navigation Performance for Area Navigation_ RTCA/DO-316 RTCA Document, Special Committee 159 14 April 2009 _Minimum Operational Performance Standards for Global Positioning System/Aircraft Based Augmentation System Airborne Equipment_ RTCM Paper 136-2001/SC104-STD RTCM Document, Special Committee 104 August 2001 _RTCM Recommended Standards for Differential Navstar GS Service, Version 2.3_ 

###### **<u>OTHER PUBLICATIONS:</u>** 

[No Number] M. Ananda, J. Leung, P. Munjal, and B. Siegel; September 1994 _RAIM Detection and Isolation Integrity Availability With and Without CAG_ ; Proceedings of ION GPS-94, the 7<sup>th</sup> International Technical Meeting of the Satellite Division of the Institute of Navigation, Salt Lake City, UT [No Number] P. Massatt and M. Zeitzew; _The GPS Constellation_ January 1998 _Design – Current and Projected_ ; Proceedings of the 1998 National Technical Meeting of the Institute of Navigation, Long Beach, CA A.953(23) International Maritime Organization (IMO) 26 February 2004 _World-wide Radionavigation System_ 

5th Edition 

Page 62

--- [page 73](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=73) ---

GPS SPS PS 

April 2020 

# _GLOBAL POSITIONING SYSTEM STANDARD POSITIONING SERVICE PERFORMANCE STANDARD_ 

## _APPENDIX A_ 

## _SPS SIGNAL-IN-SPACE (SIS) BACKGROUND INFORMATION_ 





## _April 2020_ 

**_Integrity - Service - Excellence_** 

5th Edition

--- [page 74](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=74) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition

--- [page 75](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=75) ---

GPS SPS PS 

April 2020 

### **TABLE OF CONTENTS** 

|**SECTION A.1  Introduction**.......................................................................................**A-1**|
|---|
|A.1.1  Scope ......................................................................................................................................  A-1|
|A.1.2  Limitations  ..............................................................................................................................  A-1|
|**SECTION A.2  Constellation**.....................................................................................**A-2**|
|A.2.1  Relationship with Section 3.2  .................................................................................................  A-2|
|A.2.2  Baseline 24-Slot Constellation Configuration ..........................................................................  A-2|
|A.2.3  Expandable 24-Slot Constellation Configuration .....................................................................  A-3|
|A.2.4  Propagating the Constellation over Time ................................................................................  A-4|
|**SECTION A.3  Coverage**...........................................................................................**A-7**|
|A.3.1  Relationship with Section 3.3  .................................................................................................   A-7|
|A.3.2  Per-Satellite Coverage ............................................................................................................   A-7<br>|
|A.3.2.1  Satellite Footprint ............................................................................................................   A-7<br>|
|A.3.2.2  Mask Angles ....................................................................................................................   A-7|
|A.3.3  Constellation Coverage ...........................................................................................................   A-8<br>|
|A.3.3.1  Seamless Coverage ........................................................................................................   A-8|
|A.3.3.2  Terrestrial Service Volume ..............................................................................................   A-8<br>|
|A.3.3.3  Space Service Volume ....................................................................................................   A-8|
|**SECTION A.4  Accuracy**............................................................................................**A-9**|
|A.4.1  Relationship with Section 3.4  .................................................................................................   A-9|
|A.4.2_Reserved_.................................................................................................................................   A-9|
|A.4.3  Time Dependency ...................................................................................................................   A-9<br>|
|A.4.3.1  Graceful Degradation ......................................................................................................   A-9|
|A.4.3.2  Normal Operations vs. Extended Operations .................................................................   A-9|
|<br>A.4.3.3  Variations During Normal Operations ............................................................................. A-10<br>|
|A.4.3.4  Accuracy at Time of Upload ............................................................................................ A-13|
|A.4.4  Contingency Uploads .............................................................................................................. A-14|
|A.4.5  UERE Budgets ........................................................................................................................ A-14|
|A.4.6  URE Over All AODs................................................................................................................. A-16|
|A.4.7  URE Time Derivative Accuracies ............................................................................................ A-17|
|A.4.8  UTC(USNO) Offset Accuracy .................................................................................................. A-19|
|A.4.9  Single-Frequency Ionospheric Delay Model Errors ................................................................. A-19|
|A.4.10  Group Delay Time Correction (TGD) Errors ............................................................................ A-20|
|A.4.11  Spatial Dependency .............................................................................................................. A-20|
|A.4.12  Inter-Signal Bias (ISB) & Inter-Signal Correction (ISC) Errors .............................................. A-23|



5th Edition 

Page A-i

--- [page 76](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=76) ---

GPS SPS PS 

April 2020 

|**SECTION A.5  Integrity**............................................................................................**A-25**|
|---|
|A.5.1  Relationship with Section 3.5  ...............................................................................................   A-25|
|A.5.2  URA Relationship to Integrity ................................................................................................   A-25|
|A.5.3  IAURA-Derived Integrity Tolerance .......................................................................................   A-26|
|A.5.4  Nature of SPS SIS URE ........................................................................................................   A-27<br>|
|A.5.4.1  Integrity Failure Modes and Effects...............................................................................   A-27<br>|
|A.5.4.2  Control Segment Monitoring and Intervention ..............................................................   A-29<br>|
|A.5.4.3  Control Segment Preemptive Actions ...........................................................................   A-30<br>|
|A.5.4.4  Satellite On-Board Monitoring and Intervention ............................................................   A-31|
|A.5.5  Timely Alert Considerations ..................................................................................................   A-32|
|A.5.6  Nature of SPS SIS URE Time Derivatives ............................................................................   A-33|
|A.5.6.1  URE Time Derivative Illustrations for Integrity ..............................................................   A-33|
|A.5.6.2  URE Second Time Derivative Illustrations ....................................................................   A-34|
|A.5.6.3  Combinations of URE Time Derivatives ........................................................................   A-36|
|A.5.7  SPS SIS Component Combination Integrity Considerations ................................................   A-36|
|A.5.7.1  Per ‘SPS SIS Component Combination’ Integrity Accounting ......................................   A-36|
|A.5.7.2  Independence of SPS SIS Component Combination Integrity .....................................   A-38|
|**SECTION A.6  Continuity**........................................................................................**A-39**|
|A.6.1  Relationship with Section 3.6  ...............................................................................................   A-39|
|A.6.2  Various Types of Failures and the Impacts on Continuity .....................................................   A-39|
|A.6.2.1  Hard Failures .................................................................................................................   A-39|
|A.6.2.2  Wear-Out Failures .........................................................................................................   A-40<br>|
|A.6.2.3  Soft Failures ..................................................................................................................   A-41|
|A.6.2.4  Satellite O&M Activities .................................................................................................   A-41|
|A.6.3  Losses of Continuity ..............................................................................................................   A-42|
|A.6.4  Expected Frequencies for Losses of Continuity ....................................................................   A-42|
|A.6.5  Expandable Slot Continuity ...................................................................................................   A-43|
|**SECTION A.7  Availability**.......................................................................................**A-44**|
|A.7.1  Relationship with Section 3.7  ...............................................................................................   A-44|
|A.7.2  Per-Slot Availability................................................................................................................   A-44<br>|
|A.7.2.1  Satellite Outage Categories ..........................................................................................   A-44|
|A.7.2.2  Conservative Satellite/Slot Availability Model ...............................................................   A-44|
|A.7.2.3  Satellite/Slot Availability Computation ...........................................................................   A-45|
|A.7.2.4  Expandable Slot Availability ..........................................................................................   A-46<br>|
|A.7.2.5  Equivalent-or-Better Non-Standard Expanded Slot Configurations ..............................   A-46|
|A.7.3  Constellation Availability ........................................................................................................   A-49|
|A.7.4  Slot Occupancy .....................................................................................................................   A-49|
|**SECTION A.8  Position/Time Domain**....................................................................**A-52**|
|A.8.1  Relationship with Section 3.8  ...............................................................................................   A-52|
|A.8.2  Availability of Geometry (and PVT Determination) ................................................................   A-52|
|A.8.3  Availability of Geometry Impacts Due to Expandable24 Slots ..............................................   A-53|
|A.8.4  Availability of Geometry Impacts Due to Auxiliary Satellites .................................................   A-53|
|A.8.5  Position/Time Domain Time Derivatives ...............................................................................   A-53|



5th Edition 

Page A-ii

--- [page 77](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=77) ---

GPS SPS PS 

April 2020 

### **List of Figures** 

|Figure A.3-1  Illustration of Satellite Footprint .........................................................................................   A-7|
|---|
|Figure A.3-2  Illustration of Terrestrial Service Volume ..........................................................................   A-8|
|Figure A.4-1  UERE Graceful Degradation ............................................................................................. A-10|
|Figure A.4-2a  UERE as a Function of AOD, One-Upload-Per-Day Scenario ....................................... A-11|
|Figure A.4-2b  UERE as a Function of AOD, Three-Uploads-Per-Day Scenario ................................... A-11|
|Figure A.4-3  Statistical PPS SIS URE as a Function of AOD, One-Upload-Per-Day Scenario ............ A-12|
|Figure A.4-4  Instantaneous SPS SIS URE as a Function of Time ........................................................ A-12|
|Figure A.4-5a  Instantaneous SPS SIS URE as a Function of Time ...................................................... A-18|
|Figure A.4-5b  Instantaneous SPS SIS URRE as a Function of Time ................................................... A-18|
|Figure A.4-5c  Instantaneous SPS SIS URAE as a Function of Time .................................................... A-18|
|Figure A.4-6  Illustration of Spatial Dependency - Horizontal Orbit Error ............................................... A-21|
|Figure A.4-7  Illustration of Spatial Dependency - Radial Orbit Error ..................................................... A-22|
|Figure A.5-1  Types of URE Effects ........................................................................................................ A-28|
|Figure A.5-2  Types of URE/URRE Effects ............................................................................................. A-34|
|Figure A.5-3  Types of URE/URAE Effects ............................................................................................. A-35|
|Figure A.5-4  Combined URE Time Derivative Examples ...................................................................... A-37|
|Figure A.7-1  Illustration of Nominal and Expanded Slot Configurations ................................................ A-46|
|Figure A.7-2  Illustration of Equivalent-or-Better Non-Standard Configurations (1 of 2) ........................ A-47|
|Figure A.7-2  Illustration of Equivalent-or-Better Non-Standard Configurations (2 of 2) ........................ A-48|
|Figure A.7-3  Nominal Slot Ellipse .......................................................................................................... A-50|



### **List of Tables** 

|Table A.2-1  Baseline 24-Slot Constellation Almanac, at GPS Epoch of 0000 on 1 Jan 17 ..................   A-2|
|---|
|Table A.2-2  Expandable 24-Slot Constellation Almanac, at GPS Epoch of 0000 on 1 Jan 17 .............   A-3|
|Table A.2-3  Baseline 24-Slot Constellation at 00:00:00 UTC 1 Jan 17 .................................................   A-4|
|Table A.2-4  Reference Orbit Parameters ..............................................................................................   A-5|
|Table A.2-5  Baseline 24-Slot Constellation at 00:00:00 UTC 1 Jan 18 .................................................   A-6|
|Table A.4-1  DF L1 C/A – L2C UERE Budget ......................................................................................... A-15|
|Table A.4-2  SF L1 C/A-Code UERE Budget .......................................................................................... A-16|
|Table A.4-3_Reserved_............................................................................................................................ A-16|
|Table A.4-4_Reserved_............................................................................................................................ A-16|
|Table A.5-1  LNAV URA Index to Expected URE Relationship .............................................................. A-25|
|Table A.5-2  Normal Distribution Bounds vs. Probability of Exceeding Those Bounds .......................... A-26|
|Table A.5-3  Potential Integrity Failure Modes ........................................................................................ A-28|
|Table A.7-1  Per-Satellite/Slot Availability Model Parameters for Baseline Slots ................................... A-45|
|Table A.7-2  Constellation Availability ..................................................................................................... A-49|



5th Edition 

Page A-iii

--- [page 78](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=78) ---

GPS SPS PS 

April 2020 

###### (This page intentionally left blank.) 

5th Edition 

Page A-iv

--- [page 79](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=79) ---

GPS SPS PS 

April 2020 

#### **SECTION A.1  Introduction** 

###### **A.1.1  Scope** 

This appendix provides further background information on the SPS SIS and its performance standards.  The performance standards given in Section 3 of this _SPS PS_ , along with the referenced ISs, comprise a full and complete description of the SPS SIS interface provided to the User Segment's SPS receivers.  The background information in this appendix serves to place those standards into context and explain the rationale behind them. 

###### **A.1.2  Limitations** 

Nothing in this appendix shall be deemed to change, modify, or alter the performance standards in Section 3 of this _SPS PS_ .  The background information in this appendix is for reference purposes only. 

5th Edition 

Page A-1

--- [page 80](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=80) ---

GPS SPS PS 

April 2020 

#### **SECTION A.2  Constellation** 

###### **A.2.1  Relationship with Section 3.2** 

Section 3.2 contains the SPS SIS performance standards for the satellite constellation.  The orbital slots defined in Section 3.2 are the nominal originating locations for the SPS SIS.  For convenience, this section further describes those nominal SPS SIS originating locations in a manner equivalent to the LNAV almanac data sets defined by IS-GPS-200 which may be more familiar to some readers. 

###### **A.2.2  Baseline 24-Slot Constellation Configuration** 

The baseline 24-slot constellation defined by Tables 3.2-1 and 3.2-3 can be expressed in an "almanac type" representation using parameters and units equivalent to those in IS-GPS-200 – see Table A.2-1.  (Recognize that IS-GPS-200 uses semicircles rather than degrees, meters<sup>½</sup> rather than meters, and includes clock offset parameters which are not shown in Table A.2-1). The almanac reference week (WNa) is 1930 and the almanac reference time (toa) is 0000. 

**Table A.2-1.  Baseline 24-Slot Constellation Almanac, at GPS Epoch of 0000 on 1 Jan 17** 

|Slot<br>ID|e<br>(unit less)<br>|i<br>(degrees)|<br>OMEGADOT<br>(deg/sec)|A<br>(meters)|OMEGA0<br>(degrees)|<br>(degrees)|<br>M0<br>(degrees)|
|---|---|---|---|---|---|---|---|
|A1|0.000|+1.00|-4.6528E-7|26,559,800|188.085|0.00|239.54|
|A2|0.000|+1.00|-4.6528E-7|26,559,800|188.085|0.00|133.20|
|A3|0.000|+1.00|-4.6528E-7|26,559,800|188.085|0.00|343.09|
|A4|0.000|+1.00|-4.6528E-7|26,559,800|188.085|0.00|13.22|
|B1|0.000|+1.00|-4.6528E-7|26,559,800|248.085|0.00|52.37|
|B2|0.000|+1.00|-4.6528E-7|26,559,800|248.085|0.00|144.75|
|B3|0.000|+1.00|-4.6528E-7|26,559,800|248.085|0.00|281.39|
|B4|0.000|+1.00|-4.6528E-7|26,559,800|248.085|0.00|175.79|
|C1|0.000|+1.00|-4.6528E-7|26,559,800|308.085|0.00|83.29|
|C2|0.000|+1.00|-4.6528E-7|26,559,800|308.085|0.00|343.21|
|C3|0.000|+1.00|-4.6528E-7|26,559,800|308.085|0.00|311.08|
|C4|0.000|+1.00|-4.6528E-7|26,559,800|308.085|0.00|212.97|
|D1|0.000|+1.00|-4.6528E-7|26,559,800|8.085|0.00|106.64|
|D2|0.000|+1.00|-4.6528E-7|26,559,800|8.085|0.00|236.86|
|D3|0.000|+1.00|-4.6528E-7|26,559,800|8.085|0.00|6.57|
|D4|0.000|+1.00|-4.6528E-7|26,559,800|8.085|0.00|138.77|
|E1|0.000|+1.00|-4.6528E-7|26,559,800|68.085|0.00|168.46|
|E2|0.000|+1.00|-4.6528E-7|26,559,800|68.085|0.00|274.01|
|E3|0.000|+1.00|-4.6528E-7|26,559,800|68.085|0.00|37.48|
|E4|0.000|+1.00|-4.6528E-7|26,559,800|68.085|0.00|305.10|
|F1|0.000|+1.00|-4.6528E-7|26,559,800|128.085|0.00|210.30|
|F2|0.000|+1.00|-4.6528E-7|26,559,800|128.085|0.00|316.64|
|F3|0.000|+1.00|-4.6528E-7|26,559,800|128.085|0.00|76.62|
|F4|0.000|+1.00|-4.6528E-7|26,559,800|128.085|0.00|106.76|



5th Edition 

Page A-2

--- [page 81](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=81) ---

GPS SPS PS 

April 2020 

Notes: 

- e =  Eccentricity i =  Delta-inclination relative to a nominal value of 0.30 semi-circles (54 degrees) OMEGADOT =  Rate of Right Ascension A =  Semi-major axis OMEGA0 =  Geographic Longitude of the Ascending Node at the Weekly Epoch  =  Argument of perigee M0 =  Mean anomaly at the reference time 

###### **A.2.3  Expandable 24-Slot Constellation Configuration** 

Table A.2-2 provides the equivalent "almanac type" representation for when all of the expandable slots are in their expanded configuration in accordance with Tables 3.2-1, 3.2-2, and 3.2-3.  Note that each expandable slot may individually be in its non-expanded configuration or in its expanded configuration.  There is no linkage between the expandable slots. 

**Table A.2-2.  Expandable 24-Slot Constellation Almanac, at GPS Epoch of 0000 on 1 Jan 17** 

|SlotID|e<br>(unit less)|i<br>(degrees)|OMEGADOT<br>(deg/sec)|A<br>(meters)|OMEGA0<br>(degrees)|<br>(degrees)|<br>M0<br>(degrees)|
|---|---|---|---|---|---|---|---|
|A1|0.000|+1.00|-4.6404E-7|26,559,800|188.085|0.00|239.54|
|A2F|0.000|+1.00|-4.6404E-7|26,559,800|188.085|0.00|144.40|
|A2A|0.000|+1.00|-4.6404E-7|26,559,800|188.085|0.00|176.96|
|A3|0.000|+1.00|-4.6404E-7|26,559,800|188.085|0.00|343.09|
|A4|0.000|+1.00|-4.6404E-7|26,559,800|188.085|0.00|13.22|
|B1F|0.000|+1.00|-4.6404E-7|26,559,800|248.085|0.00|66.33|
|B1A|0.000|+1.00|-4.6404E-7|26,559,800|248.085|0.00|37.77|
|B2|0.000|+1.00|-4.6404E-7|26,559,800|248.085|0.00|144.75|
|B3|0.000|+1.00|-4.6404E-7|26,559,800|248.085|0.00|281.39|
|B4|0.000|+1.00|-4.6404E-7|26,559,800|248.085|0.00|175.79|
|C1|0.000|+1.00|-4.6404E-7|26,559,800|308.085|0.00|83.29|
|C2|0.000|+1.00|-4.6404E-7|26,559,800|308.085|0.00|343.21|
|C3|0.000|+1.00|-4.6404E-7|26,559,800|308.085|0.00|311.08|
|C4F|0.000|+1.00|-4.6404E-7|26,559,800|308.085|0.00|220.43|
|C4A|0.000|+1.00|-4.6404E-7|26,559,800|308.085|0.00|195.73|
|D1|0.000|+1.00|-4.6404E-7|26,559,800|8.085|0.00|106.64|
|D2F|0.000|+1.00|-4.6404E-7|26,559,800|8.085|0.00|254.09|
|D2A|0.000|+1.00|-4.6404E-7|26,559,800|8.085|0.00|229.39|
|D3|0.000|+1.00|-4.6404E-7|26,559,800|8.085|0.00|6.57|
|D4|0.000|+1.00|-4.6404E-7|26,559,800|8.085|0.00|138.77|
|E1|0.000|+1.00|-4.6404E-7|26,559,800|68.085|0.00|168.46|
|E2|0.000|+1.00|-4.6404E-7|26,559,800|68.085|0.00|274.01|
|E3F|0.000|+1.00|-4.6404E-7|26,559,800|68.085|0.00|52.08|
|E3A|0.000|+1.00|-4.6404E-7|26,559,800|68.085|0.00|23.52|
|E4|0.000|+1.00|-4.6404E-7|26,559,800|68.085|0.00|305.10|
|F1|0.000|+1.00|-4.6404E-7|26,559,800|128.085|0.00|210.30|
|F2F|0.000|+1.00|-4.6404E-7|26,559,800|128.085|0.00|331.87|
|F2A|0.000|+1.00|-4.6404E-7|26,559,800|128.085|0.00|305.43|
|F3|0.000|+1.00|-4.6404E-7|26,559,800|128.085|0.00|76.62|
|F4|0.000|+1.00|-4.6404E-7|26,559,800|128.085|0.00|106.76|



5th Edition 

Page A-3

--- [page 82](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=82) ---

GPS SPS PS 

April 2020 

###### **A.2.4  Propagating the Constellation over Time** 

The GPS baseline constellation defined in Section 3.2 is designed to be a ground track repeating orbit with a period of a half of a sidereal day.  The constellation RAAN values change over time with the mean nodal regression rate of -0.0402 deg/day.  The repeating ground track for the nominal constellation require that any propagation of the constellation is relative to time in UTC. The baseline constellation at 1 January 2017 00:00:00 UTC ( _JD0_ = 2457754.5) is: 

**Table A.2-3.  Baseline 24-Slot Constellation at 00:00:00 UTC 1 Jan 17** 

|**Slot**|**RAAN (Ω)**|**Argument of Latitude**|
|---|---|---|
|A1|288.85°|239.68°|
|A2|288.85°|133.34°|
|A3|288.85°|343.24°|
|A4|288.85°|13.36°|
|B1|348.85°|52.52°|
|B2|348.85°|144.90°|
|B3|348.85°|281.54°|
|B4|348.85°|175.94°|
|C1|48.85°|83.44°|
|C2|48.85°|343.36°|
|C3|48.85°|311.22°|
|C4|48.85°|213.12°|
|D1|108.85°|106.78°|
|D2|108.85°|237.00°|
|D3|108.85°|6.72°|
|D4|108.85°|138.92°|
|E1|168.85°|168.60°|
|E2|168.85°|274.16°|
|E3|168.85°|37.62°|
|E4|168.85°|305.24°|
|F1|228.85°|210.44°|
|F2|228.85°|316.78°|
|F3|228.85°|76.76°|
|F4|228.85°|106.90°|



_Note:_ 

_1. The epoch time of the above table is slightly different from the corresponding table in Section 3.2._ 

For propagation purposes, the following reference orbit parameters from Table 3.2-3 are held fixed with their nominal values as shown below.  The indicated symbols are used in the equations which follow. 

5th Edition 

Page A-4

--- [page 83](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=83) ---

GPS SPS PS 

April 2020 

**Table A.2-4.  Reference Orbit Parameters** 

|**Reference Orbit Parameter**|**Nominal Value**|
|---|---|
|Semi-Major Axis, km (a)|26,599.8|
|Eccentricity (e)|0.0|
|Inclination (i)|55.0°|
|Argument of Perigee ()|0.0°|



Only the RAAN (Ω) and the argument of latitude are time dependent.  Because eccentricity (e) and argument of perigee () are both zero, the argument of latitude equals the mean anomaly (M).  For simplicity M will be used for propagation. 

To propagate the RAAN forward to a new epoch whose Julian Date is _JDf_ : 



where Ω0 is the satellite RAAN at 1 January 2017 00:00:00 UTC. 

The repeating ground tracks mean that the Geographic Longitude of the Ascending Node (GLAN) values (also known as the Groundtrack Equatorial Crossing [GEC] values and denoted as λ), for the nominal constellation are constant over time.  When a satellite is at a nodal crossing, λ may be expressed as a function of M, Ω, and θG, where θG is the Greenwich hour angle.  Taking into account that the ground tracks repeat twice a sidereal day, at any time _t_ : 



Furthermore, because the ground tracks for the nominal constellation repeat, λ _t_ = λ0 for all future times _t_ .  Thus: 



As an example, the 1 January 2017 00:00:00 UTC constellation configuration shown in Table A.23 and A.2-4 propagated forward to a later epoch of 1 January 2018 00:00:00 UTC results in the equivalent constellation configuration shown in Table A.2-6 and A.2-7. 

5th Edition 

Page A-5

--- [page 84](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=84) ---

GPS SPS PS 

April 2020 

###### **Table A.2-5.  Baseline 24-Slot Constellation at 00:00:00 UTC 1 Jan 18** 

|**Slot**|**RAAN (Ω)**|**Argument of Latitude**|
|---|---|---|
|A1|274.18°|268.55°|
|A2|274.18°|162.21°|
|A3|274.18°|12.11°|
|A4|274.18°|42.23°|
|B1|334.18°|81.39°|
|B2|334.18°|173.77°|
|B3|334.18°|310.41°|
|B4|334.18°|204.81°|
|C1|34.18°|112.31°|
|C2|34.18°|12.23°|
|C3|34.18°|340.09°|
|C4|34.18°|241.99°|
|D1|94.18°|135.65°|
|D2|94.18°|265.87°|
|D3|94.18°|35.59°|
|D4|94.18°|167.79°|
|E1|154.18°|197.47°|
|E2|154.18°|303.03°|
|E3|154.18°|66.49°|
|E4|154.18°|334.11°|
|F1|214.18°|239.31°|
|F2|214.18°|345.65°|
|F3|214.18°|105.63°|
|F4|214.18°|135.77°|



This propagation defines the baseline constellation at any epoch after 1 January 2017 00:00:00 UTC.  The GLANs (λ) for operational satellites are adjusted by the right ascension dispersion of the satellite: 



Where λ is the GLAN for the operational satellite, λn is the GLAN for the nominal satellite orbit as defined in the baseline satellite constellation, Ω is the right ascension of ascending node for the operational satellite, and Ωn is the right ascension for the nominal satellite orbit as defined in the baseline satellite constellation. 

5th Edition 

Page A-6

--- [page 85](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=85) ---

GPS SPS PS 

April 2020 

#### **SECTION A.3  Coverage** 

###### **A.3.1  Relationship with Section 3.3** 

Section 3.3 contains the SPS SIS performance standards for coverage from each satellite and from the satellite constellation.  This section provides further information relative to both aspects of the SPS SIS coverage. 

###### **A.3.2  Per-Satellite Coverage** 

###### **A.3.2.1  Satellite Footprint** 

The portion of the surface of the Earth which is visible from a satellite's orbital location is known as the satellite’s “footprint”.  See Figure A.3-1. 

The footprint of each satellite occupying a slot in the baseline/expandable 24-slot constellation covers approximately 38% of the Earth’s surface.  The use of artificial mask angles will reduce the satellite’s effective footprint.  With a 5-degree mask angle, a satellite’s effective footprint is reduced to slightly more than one-third of the Earth's surface (33.9%). 



<!-- Start of picture text -->
Satellite Footprint<br>27.8°<br>Not to scale<br><!-- End of picture text -->

**Figure A.3-1.  Illustration of Satellite Footprint** 

###### **A.3.2.2  Mask Angles** 

The 5 degree elevation angle used in IS-GPS-200 and IS-GPS-705 for specifying the guaranteed minimum user-received power level should not be interpreted as specifying, recommending, or suggesting a particular GPS receiver mask angle.  The GPS receiver mask angle (if any) should 

5th Edition 

Page A-7

--- [page 86](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=86) ---

GPS SPS PS 

April 2020 

be determined as a function of the IS-GPS-200 and/or IS-GPS-705 guaranteed minimum userreceived power levels, the GPS SIS frequencies used, the GPS receiver antenna gain patterns at each frequency, the GPS receiver front-end sensitivity at each frequency, the particular types of mission(s) to be accomplished, and related factors.  Some common GPS receiver mask angles are 15 degrees, 10 degrees, 7.5 degrees, 5 degrees, 2 degrees, and 0 degrees.  Some GPS receivers have no mask angle.  Some older GPS receivers have a variable mask angle.  See AC 20-138 for some aviation mask angle examples. 

###### **A.3.3  Constellation Coverage** 

###### **A.3.3.1  Seamless Coverage** 

The coverage of a "global positioning system" should obviously be global and seamless.  The same is not necessarily true for a "global navigation satellite system" (GNSS) which incorporates wide area or local area augmentations.  The SPS SIS constellation coverage is seamless. 

###### **A.3.3.2  Terrestrial Service Volume** 

The near-Earth region extending from the surface of the Earth up to an altitude of 3,000 km above the surface of the Earth is also known as the "terrestrial service volume".  See Figure A.3-2. 



<!-- Start of picture text -->
Terrestrial Service Volume<br>41.3°<br>Alt = 3000 km<br>Not to scale<br><!-- End of picture text -->

**Figure A.3-2.  Illustration of Terrestrial Service Volume** 

###### **A.3.3.3  Space Service Volume** 

The spherical shell extending from the outer surface of the terrestrial service volume up to an altitude of 36,000 km above the surface of the Earth (approximately the geosynchronous orbit altitude) is known as the "space service volume".  There are no explicit constellation coverage standards for the space service volume. 

5th Edition 

Page A-8

--- [page 87](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=87) ---

GPS SPS PS 

April 2020 

#### **SECTION A.4  Accuracy** 

###### **A.4.1  Relationship with Section 3.4** 

Section 3.4 contains the SPS SIS performance standards for accuracy.  This section provides background information relative to the SPS SIS accuracy performance standards. 

###### **A.4.2  Reserved** 

###### **A.4.3  Time Dependency** 

###### **A.4.3.1  Graceful Degradation** 

GPS UERE budgets and corresponding SPS SIS accuracy standards vary as a function of time. The accuracy variation over time will be significant if the Control Segment is unable to upload fresh NAV message data to the satellites in the constellation.  Such a condition could occur as the result of total loss of the Control Segment due to a natural or man-made disaster, or it could occur on a per-satellite basis if a satellite were to become unable to accept and process the uploaded data.  In either case, the UERE will degrade gracefully over time as illustrated in Figure A.4-1. 

###### **A.4.3.2  Normal Operations vs. Extended Operations** 

When the satellites are being uploaded on a routine basis, the SPS SIS accuracy standards which apply are for the normal operations mode.  During normal operations, each satellite in the constellation is uploaded at least once per day.  Additional (contingency) uploads may be necessary for certain satellites as described in the following section.  The normal operations mode is shown at the far left-hand side of Figure A.4-1.  The SPS SIS indicates when the satellite is in the normal operations mode by way of the C/A-code signal LNAV data stream fit interval flag 



<!-- Start of picture text -->
400<br>Normal Operations<br>300<br>Extended Operations<br>200<br>100<br>   0<br>0              2              4               6              8             10             12            14<br>Days Since Last Upload<br>Not to scale<br>UERE (95%), meters<br><!-- End of picture text -->

**Figure A.4-1.  UERE Graceful Degradation** 

5th Edition 

Page A-9

--- [page 88](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=88) ---

GPS SPS PS 

April 2020 

being set to “0” (zero) in accordance with IS-GPS-200.  When the fit interval flag is set to “1” (one), the satellite is operating in the extended operations mode.  Special SPS SIS accuracy standards apply for the extended operations mode.  See IS-GPS-200 for details on the fit interval flag. 

_Notes:_ 

_1. Three uploads per day is a worst-case assumption for the normal operations period.  One upload per day is a best-case assumption.  Many satellites typically only require one upload per day._ 

_2. There is no equivalent ‘normal operations mode’ flag (fit interval flag) in the CNAV data stream on the CM-code signal or the I5-code signal._ 

The extended operations period is shown at the center and right-hand side of Figure A.4-1.  A different set of SPS SIS accuracy standards applies when a satellite is operating in the extended operations mode.  All satellites will provide a usable (i.e., healthy or marginal)  C/A-code signal for at least 14 days in the extended operations mode (i.e., at least 14 days after the last upload of fresh LNAV message data from the Control Segment).  Most satellites will continue to provide a usable C/A-code signal for even longer than 14 days.  The extended operations mode for CNAV message data from the CM-code signal and the I5-code signal is only 2 days for the Block IIR-M and Block IIF satellites.  See IS-GPS-200 for further details on the capability of different types of satellites to continue in the extended operations mode beyond 14 days. 

###### **A.4.3.3  Variations During Normal Operations** 

During the normal operations period, the GPS UERE and SPS SIS accuracy vary as a function of the time since upload in the same general manner as shown in Figure A.4-1, but with the maximum time since last upload for each satellite limited to no more than about a day.  The smallest UERE and best SIS accuracy will generally occur immediately after an upload of fresh NAV message data to a satellite, while the largest UERE and worst SIS accuracy will usually be with the stalest NAV message data just prior to the next upload to that satellite. 

The metric used to characterize whether the NAV message data being transmitted by a satellite is fresh or stale is the age of data (AOD), where the AOD is the elapsed time since the Control Segment generated the satellite clock/ephemeris prediction used to create the NAV message data upload.  The AOD is approximately equal to the time since last upload plus the time it took the Control Segment to create the NAV message data and upload it to the satellite. 

For normal operations, the GPS UERE budget and the traditional SPS SIS accuracy specifications apply at each AOD.  Because the largest UERE and worst SIS accuracy usually occur with the stalest NAV message data, the UERE budget and traditional SPS SIS accuracy specifications are taken as applying at the maximum AOD. 

Figure A.4-2 shows close-up views of the normal operations period.  The horizontal axes are given in terms of the AOD.  In a best-case one-upload-per-day scenario for a satellite with a very stable clock (Figure A.4-2a), the maximum AOD is assumed to be 26 hours based on:  (a) 1 hour to create the NAV message data and upload it to satellite, (b) 24 hours mean time between uploads, and (c) 1 hour schedule variation for the subsequent upload.  In a worst-case threeupload-per-day scenario for a satellite with a less stable clock (Figure A.4-2b), the maximum AOD is assumed to be 10 hours based on:  (a) 1 hour to create the NAV message data and upload it to satellite, (b) 8 hours mean time between uploads, and (c) 1 hour schedule variation for the subsequent upload. 

5th Edition 

Page A-10

--- [page 89](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=89) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
 16<br> 12<br>   8<br>   4<br>   0<br>0     2      4      6      8      10    12    14    16    18    20    22    24    26<br>Age of Data (AOD), hours<br>Not to scale<br>Figure A.4-2a.  UERE as a Function of AOD, One-Upload-Per-Day Scenario<br> 16<br> 12<br>   8<br>   4<br>   0<br>0                  2                   4                    6                   8                  10<br>Age of Data (AOD), hours<br>Not to scale<br>UERE (95%), meters<br>UERE (95%), meters<br><!-- End of picture text -->

**Figure A.4-2b.  UERE as a Function of AOD, Three-Uploads-Per-Day Scenario** 

Recognize that a large portion of the UERE in Figure A.4-2a (and in Figure A.4-2b) does not vary as a function of the AOD.  The dominant component which does not vary is the SPS receiver's contribution to the UERE (known as the user equipment error or UEE).  Factoring out the SPS receiver's UEE leaves just the SPS SIS contribution to the UERE (i.e., the SPS SIS URE).  As shown in Figure A.4-3, the SPS SIS URE exhibits a stronger dependence on the AOD than the SPS UERE shown in Figure A.4-2a. 

Figure A.4-3, like the preceding figures, is a statistical plot.  It shows the cumulative SPS SIS URE-as-a-function-of-AOD results over many uploads (e.g., all uploads to a satellite over the course of a year in a one-upload-per-day scenario).  Figure A.4-4 shows a representative example of four uploads performed over a day to a single satellite in a three-upload-per-day scenario. Unlike the preceding figures, Figure A.4-4 shows the instantaneous URE as a function of time rather than the cumulative statistical URE as a function of the AOD. 

5th Edition 

Page A-11

--- [page 90](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=90) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
 16<br> 12<br>   8<br>   4<br>   0<br>0     2      4      6      8      10    12    14    16    18    20    22    24    26<br>Age of Data (AOD), hours<br>Not to scale<br>Figure A.4-3.  Statistical SPS SIS URE as a Function of AOD, One-Upload-Per-Day<br>Scenario<br>Upload  Upload  Upload<br>Upload<br>  +8<br>  +4<br>   0   Time,<br>0               4                8              12              16              20              24  hours<br>  -4<br>  -8<br>Not to scale<br>Figure A.4-4.  Instantaneous SPS SIS URE as a Function of Time<br>URE (95%), meters<br>URE (Instantaneous), meters<br><!-- End of picture text -->

**Figure A.4-3.  Statistical SPS SIS URE as a Function of AOD, One-Upload-Per-Day Scenario** 

_Note:_ 

_1. The instantaneous URE can be positive or negative as shown in Figure A.4-4.  The statistical URE is always unsigned (illustrated as positive) as shown in Figures A.4-1 through A.4-3._ 

In Figure A.4-4, the uploads are shown as occurring at approximately 00:42, 08:28, 16:29, and 23:57.  Each upload is characterized by the instantaneous SPS SIS URE resetting to near zero as a result of the satellite starting to broadcast the fresh NAV message which has just been uploaded.  The transition from the stale old NAV message data to the fresh new NAV message data is known as an "upload cutover".  In addition to the large discontinuities at the upload cutovers, Figure A.4-4 also shows much smaller discontinuities occurring at the 2-hour 

5th Edition 

Page A-12

--- [page 91](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=91) ---

GPS SPS PS 

April 2020 

boundaries (slightly exaggerated for clarity).  These smaller discontinuities are the result of the satellite switching from broadcasting one 2-hour data set to the next 2-hour data set from the same upload.  Even though sequential 2-hour data sets come from the same upload, minor differences in clock/ephemeris curve fitting introduce small discontinuities between data sets (i.e., between curve fits).  The transition from one 2-hour data set to the next 2-hour data set is known as a "data set cutover".  See IS-GPS-200 and IS-GPS-705 for further details on upload cutovers and data set cutovers. 

###### **A.4.3.4  Accuracy at Time of Upload** 

As shown in the preceding figures, uploads of fresh NAV message data reset the instantaneous SPS SIS URE to near zero, but they do not always reset the instantaneous SPS SIS URE to exactly zero.  There are three main types of errors which prevent fresh NAV message data from being 100% accurate at the time of the upload.  In descending order of impact on upload accuracy, the three types of limiting errors are: 

- a. The first error type is the result of the inability of the Control Segment to perfectly determine a satellite’s clock offset from GPS time and its location in orbit at every instant in time.  This is often called the zero age of data (ZAOD) error.  The MCS uses a Kalman filter to process the GPS SIS tracking data supplied by the MSs and generates estimates for the satellite clock/ephemeris parameters in near real time.  Because Kalman filters do not react instantaneously to unpredictable changes, and because there are only a limited number of MSs providing GPS SIS tracking measurements, the near real time estimated clock/ephemeris parameters in the MCS are always slightly inaccurate.  The ZAOD errors tend to be lower when more MSs are tracking a satellite, and they tend to be larger when a satellite’s clock or orbit is changing in an unpredictable manner.  Inaccurately estimated clock/ephemeris parameters from the Control Segment’s Kalman filter map directly into the upload based on those parameters. 

- b. The second error type is the result of there only being a limited number of data bits in the NAV message data to represent a satellite’s predicted clock and ephemeris.  This is known as the curve fit error.  The two “curves” which have the fitting error are: (1) the quadratic curve specified in IS-GPS-200/IS-GPS-705 for representing a satellite’s predicted clock offset from GPS time, and (2) the quasi-Keplerian curve specified in IS-GPS-200/IS-GPS705 for representing a satellite’s predicted ephemeris.  This is the same error which is responsible for the small discontinuities occurring at the 2-hour boundaries shown in Figure A.4-4.  See IS-GPS-200/IS-GPS-705 for further details on curve fit errors.  LNAV curve fit errors make up a significant portion of the C/A-code signal URE at the time of upload.  CNAV curve fit errors are insignificant contributors to the CM-code signal URE, the I5-code signal URE, and the Q5-code signal URE regardless of the time of upload. 

- c. The third error type is the result of the delay between the time that the Control Segment’s Kalman filter generates its estimates of the satellite clock/ephemeris parameters and the time that the satellite starts transmitting new NAV message data from an upload based on those Kalman filter estimates.  The AOD starts counting at the time the Kalman filter generates the satellite clock/ephemeris parameters, not at the time of the upload. Because of the delay, new NAV message data already has a significant non-zero AOD when a satellite starts transmitting it. 

5th Edition 

Page A-13

--- [page 92](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=92) ---

GPS SPS PS 

April 2020 

###### **A.4.4  Contingency Uploads** 

The Control Segment has some ability to manage the SPS SIS contribution to the overall UERE. The Control Segment can do this by monitoring the current instantaneous GPS SIS URE from each satellite and performing a "contingency upload" if the URE starts to become large relative to the allocated Space/Control portions of the UERE budget.  Done consistently, this puts an effective bound on the maximum SPS SIS URE.  This _SPS PS_ contains no requirement for the Control Segment to perform contingency uploads nor does it give any SPS SIS URE threshold for prompting a contingency upload.  The contingency upload threshold (CUT), if any, is under the purview of the Control Segment.  The only SPS SIS accuracy-related requirements on the Control Segment for uploading are: (1) uploading each satellite a minimum of approximately once per day, and (2) satisfying the requirements of Tables 3.4-1 through 3.4-4. 

###### **A.4.5  UERE Budgets** 

For reference, the GPS UERE budgets for typical DF L1 C/A – L2C receivers and for SF L1 C/Acode receivers at zero AOD, at maximum AOD in normal operations, and at 14.5 day AOD in extended operations, are shown in Tables A.4-1 and A.4-2.  The breakouts of the individual segment components of the UERE budgets shown in these tables are given for illustration purposes only.  The actual SPS SIS accuracy standards are given in Table 3.4-1. 

Recognize that those portions of the GPS UERE budgets related to the SPS receivers are shown strictly for illustration purposes only.  The actual SPS receiver UEE contributions to the overall GPS UERE budgets will vary significantly as a function of SPS receiver design and performance under different environmental conditions. 

_Notes:_ 

_1. Deleted._ 

_2. The normal operations UERE budgets are consistent with an early Block II clock stability of 5x10_<sup>_-_</sup> _13 at a tau of 104 seconds for either Rubidium clocks or Cesium clocks and an average of three uploads per day per satellite assuming an average maximum AOD of 8.5 hours.  Under a threeuploads-per-day scenario, the actual average maximum AOD is on the order of 10 hours._ 

_3. The normal operations UERE budgets are conservative with a later Block II clock stability of 6x10_<sup>_-_</sup> _14 at a tau of 105 seconds for a Rubidium clock and an average of one upload per day per satellite assuming an average maximum AOD of 26 hours._ 

_4. The extended operations UERE budgets are consistent with an "average" early Block II clock stability of 3.5x10_<sup>_-13_</sup> _at a tau of 10_<sup>_4_</sup> _seconds (i.e., average between a Rubidium clock and a Cesium clock) and an AOD of 14.5 days._ 

_5. 14 days after the Control Segment ceases uploading satellites with fresh NAV message data under the system-wide graceful degradation scenario, the average AOD across all satellites in the constellation will be 14.5 days assuming an average of one upload per day per satellite before the Control Segment ceased uploading satellites.  The extended operations URE standards apply across the entire constellation 14 days after the Control Segment ceased uploading satellites._ 

5th Edition 

Page A-14

--- [page 93](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=93) ---

GPS SPS PS 

April 2020 

_6. Reserved_ 

_7. Reserved_ 

_8. Actual SF ionospheric delay model errors depend on the point in the 11-year sunspot cycle, the geomagnetic location, the local solar time of day, and the local satellite elevation angle.  Due to this variability, the SF URE, URRE, and URAE standards do not include the SF ionospheric delay model errors.  Tables A.4-2 and A.4-4 illustrate the typical method for including the SF ionospheric delay model errors at L1.  See paragraph A.4.9 for additional information._ 

_9. The user contributions to the UERE budget illustrate mid-1980s vintage receiving equipment.  See Appendix B for additional information on different SPS receivers and environments._ 

_10. All statistical values are expressed at the 95% probability level in accordance with international standards._ 

###### **Table A.4-1.  DF L1 C/A – L2C UERE Budget** 

|||UERE<br>|Contribution<br>(meters)<br>|(95%)<br>|
|---|---|---|---|---|
|Segment|Error Source|Zero AOD|Max. AOD<br>in Normal<br>Operation|14.5 Day<br>AOD|
||Clock Stability|0.0|7.5|257|
|S|Group Delay Stability|1.6|1.6|1.6|
|pace|Diff'l Group Delay Stability|2.4|2.4|2.4|
||Satellite Acceleration Uncertainty|0.0|2.0|204|
||OtherSpace SegmentErrors|1.0|1.0|1.0|
||Clock/Ephemeris Estimation|2.0|2.0|2.0|
||Clock/Ephemeris Prediction|0.0|4.4|206|
|Control|Clock/Ephemeris Curve Fit|0.1|0.1|1.2|
||Iono Delay Model Terms|N/A|N/A|N/A|
||Group Delay Time Correction|N/A|N/A|N/A|
||OtherControlSegmentErrors|1.0|1.0|1.0|
||Ionospheric Delay Compensation|4.5|4.5|4.5|
||Tropospheric Delay Compensation|3.9|3.9|3.9|
|User*|Receiver Noise and Resolution|2.9|2.9|2.9|
||Multipath|2.4|2.4|2.4|
||OtherUserSegmentErrors|1.0|1.0|1.0|
|9|5% SystemUERE(SPS)|8.0|12.0|388|
|* For illustratio|n only,actual SPS receiverperformance var|ies significantly|-- see Table B.|2-1|



5th Edition 

Page A-15

--- [page 94](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=94) ---

GPS SPS PS 

April 2020 

**Table A.4-2.  SF L1 C/A-Code UERE Budget** 

|||UERE<br>|Contribution (<br>(meters)<br>|95%)|
|---|---|---|---|---|
|Segment|Error Source|Zero AOD|Max. AOD<br>in Normal<br>Operation|14.5 Day<br>AOD|
|Space|Clock Stability<br>Group Delay Stability<br>Diff'l Group Delay Stability|0.0<br>1.6<br>0.0|7.5<br>1.6<br>0.0|257<br>1.6<br>0.0|
||Satellite Acceleration Uncertainty<br>|0.0|2.0|204|
||OtherSpace SegmentErrors|1.0|1.0|1.0|
||Clock/Ephemeris Estimation|2.0|2.0|2.0|
||Clock/Ephemeris Prediction|0.0|4.4|206|
|Control|Clock/Ephemeris Curve Fit|0.6|0.6|1.2|
||Iono Delay Model Terms|9.8-19.6|9.8-19.6|9.8-19.6|
||Group Delay Time Correction<br>|2.3|2.3.0|2.3.0|
||OtherControlSegmentErrors|1.0|1.0|1.0|
||Ionospheric Delay Compensation|N/A|N/A|N/A|
||Tropospheric Delay Compensation|3.9|3.9|3.9|
|User*|Receiver Noise and Resolution|2.9|2.9|2.9|
||Multipath|2.4|2.4|2.4|
||OtherUserSegmentErrors|1.0|1.0|1.0|
|9|5% System UERE (SPS)|11.9-20.7|14.8<br>-22.6|388|



* For illustration only, actual SPS receiver performance varies significantly -- see Table B.2-1 

**Table A.4-3.** **_Reserved_** 

###### **Table A.4-4.** **_Reserved_** 

###### **A.4.6  URE Over All AODs** 

The SPS SIS portions of the preceding UERE budgets describe the SPS SIS accuracy at various specified AODs.  During the normal operations period, the statistical SPS SIS URE at the maximum AOD (i.e., any AOD) has traditionally been taken as being the URE seen by SPS receivers for system accuracy computations.  Although valid under worst-case conditions, SPS receivers are very unlikely to encounter a condition where all satellites being used are simultaneously at their maximum AOD.  Instead, the general-case condition for a SPS receiver is for the satellites being used to have a range of AODs.  Some satellites will have large AODs, some satellites will have small AODs, and some satellites will have AODs in the middle.  Under this general-case condition, using the SPS SIS URE at the maximum AOD will result in overly conservative system accuracy computations. 

To avoid over-conservatism for the normal operations period, a different SPS SIS URE statistic is used.  This is the SPS SIS URE over all AODs which occur during the normal operations period. The SPS SIS URE over all AODs applies to individual satellites over time as well as to the ensemble of satellites used by a SPS receiver over time.  The SPS SIS URE over all AODs should be used in system accuracy computations. 

5th Edition 

Page A-16

--- [page 95](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=95) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. Due to the shape of the SPS SIS URE curve as a function of AOD (e.g., see Figure A.4-3), the SPS SIS URE over all AODs is not equal to the SPS SIS URE at the average AOD._ 

_2. The SPS SIS URE over all AODs is the expected SPS SIS URE at a random point in time over a long series of uploads (i.e., at a random AOD)._ 

###### **A.4.7  URE Time Derivative Accuracies** 

There are two time derivatives of the SPS SIS instantaneous URE (instantaneous pseudorange error) addressed in this _SPS PS_ .  The first time derivative of the SPS SIS instantaneous pseudorange error is the SPS SIS instantaneous pseudorange rate error; also known as the instantaneous pseudorange velocity error or instantaneous user range rate error (URRE).  The second time derivative of the SPS SIS instantaneous pseudorange error is the SPS SIS instantaneous pseudorange rate rate error; more commonly known as the instantaneous pseudorange acceleration error or instantaneous user range acceleration error (URAE). 

The inter-relationship of the time derivatives with the SPS SIS instantaneous URE is shown in the three panels of Figure A.4-5.  Because the instantaneous pseudorange rate error is the rate of change of the instantaneous URE, the instantaneous URRE is simply the slope of the instantaneous URE.  For example; just before the first upload, the slope of the instantaneous URE is steep and positive -- hence the instantaneous URRE is large and positive.  This large and positive instantaneous URRE is shown in Figure A.4-5(b).  One derivative further, the instantaneous pseudorange acceleration error is the rate of change of the rate of change of the instantaneous URE, or equivalently the rate of change (the slope) of the instantaneous URRE. For the example in Figure A.4-5(a); right after the first upload, the slope of the instantaneous URE starts out at zero and gradually becomes negative over time -- these changing slopes are the instantaneous URRE over time as shown in Figure A.4-5(b) -- and the changing slopes of the instantaneous URRE over time are the instantaneous URAE over time as shown in Figure A.45(c). 

Just as the behavior of the instantaneous URE over time is specified in terms of a statistical URE, the behavior of the instantaneous pseudorange rate error over time is specified in terms of a statistical URRE and the behavior of the instantaneous pseudorange acceleration error over time is specified in terms of a statistical URAE.  Also, like the URE values, the URRE and URAE values are expressed as 95<sup>th</sup> percentile accuracies over time, where measurement point is at any AOD for the normal operations scenario and at 14 days after the Control Segment ceases uploading in the extended operations scenario. 

The infinite spikes in the instantaneous URRE and instantaneous URAE values shown in Figures A.4-5b and A.4-5c deserves special mention.  Whenever a step change occurs in the instantaneous URE in Figure A.4-5a -- due to a discontinuity caused by either an upload cutover or a data set cutover -- there is a corresponding spike in the instantaneous URRE.  These spikes occur because the step change in the instantaneous URE at the cutover happens over an infinitesimally short time and the resulting "slope" of the instantaneous URE at the step change is infinite.  The same principle also causes spikes in the instantaneous URAE whenever a step change in the instantaneous URRE occurs at a cutover.  These spikes in the instantaneous URRE and instantaneous URAE are infinitely large in size, but only last for an infinitesimally short duration.  These spikes are not included in the statistical URRE 95% and URAE 95% values. 

5th Edition 

Page A-17

--- [page 96](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=96) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
Upload  Upload  Upload  Upload<br>  +8<br>  +4<br>    0  Time,<br>0               4                8              12              16              20              24  hours<br>   -4<br>Not to scale<br>Instantaneous URE, meters     -8<br><!-- End of picture text -->

**Figure A.4-5a.  Instantaneous SPS SIS URE as a Function of Time** 



<!-- Start of picture text -->
+0.0004<br>+0.0002<br>           0  Time,<br>0               4                8              12              16              20              24  hours<br> -0.0002<br> -0.0004 Not to scale<br>Figure A.4-5b.  Instantaneous SPS SIS URRE as a Function of Time<br>+2  10 -8<br>+1  10 -8<br>         0  Time,<br>0               4                8              12              16              20              24  hours<br> -2  10 -8<br> -2  10 -8<br>Not to scale<br>Instantaneous URRE, m/sec<br>Instantaneous URAE, m/sec/sec<br><!-- End of picture text -->

**Figure A.4-5c.  Instantaneous SPS SIS URAE as a Function of Time** 

5th Edition 

Page A-18

--- [page 97](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=97) ---

GPS SPS PS 

April 2020 

###### **A.4.8  UTC(USNO) Offset Accuracy** 

The SPS SIS NAV message contains offset data for relating GPS time to UTC(USNO).  During normal operations, the accuracy of this offset data during the transmission interval is such that the UTC offset error (UTCOE) in relating GPS time (as maintained by the Control Segment) to UTC (as maintained by the U.S. Naval Observatory) is within 30 nanoseconds 95% (15 nanoseconds 1-sigma).  See IS-GPS-200 and/or IS-GPS-705 for additional details regarding the UTC(USNO) offset data. 

_Notes:_ 

_1. The accuracy of the UTC(USNO) offset data will degrade if the Control Segment is unable to upload fresh data to the satellites.  During extended operations, it is expected that alternate sources of UTC are no longer available, and that the relative accuracy of the UTC(USNO) offset data will be sufficient for most users._ 

_2. The UTC(USNO) offset data is intended to be applied by the GPS receiver, or by the user, after the GPS receiver has solved for its own offset from GPS time.  The GPS receiver is not required to compute a position solution for the UTC(USNO) offset data to be useful, only a time solution is needed._ 

_3. The Control Segment is not required to update its estimate of the UTC (USNO) offset data prior to each upload.  As such, the same UTC(USNO) offset data is commonly broadcast by several satellites simultaneously.  Depending on the Control Segment's UTC(USNO) offset estimate update schedule, it is possible for all satellites to be broadcasting the same UTC(USNO) offset data._ 

###### **A.4.9  Single-Frequency Ionospheric Delay Model Errors** 

The accuracy of the single-frequency (SF) ionospheric delay model is better than 50%.  Typical global statistic SF ionospheric delay model errors for L1 vary from 9.8 m to 19.6 m 95% for benign and disturbed ionospheric conditions respectively.  SF ionospheric delay model errors for L2 and L5 are larger because of the lower carrier frequencies.  Ionospheric delay model errors can be as severe as ±100 m or more in some solar conditions, at some latitudes, at some elevation angles, and at some times of day.  The largest errors are usually seen when solar storms occur during or shortly after a maximum in the 11-year sunspot cycle, within ±15 degrees of the geomagnetic equator, near the horizon, during the local afternoon.  The smallest errors are usually seen when the sun is quiet during a minimum in the 11-year sunspot cycle, at the geomagnetic mid-latitudes, at zenith, during the local night.  The influence of the local time of day on the SF ionospheric delay model accuracy is particularly strong.  Regardless of the 11-year sunspot cycle phase or geomagnetic latitude, the ionospheric delay model errors at zenith between local midnight and local dawn are commonly less than ±1 m. 

Table A.4-2 illustrates the typical method for including the SF ionospheric delay model errors in the Control Segment contribution to the L1 C/A-code SPS SIS URE.  The same method is also used for including the SF ionospheric delay model errors in the Control Segment contribution to the L2 CM-code and L5 I5-code/Q5-code SPS SIS UREs. 

5th Edition 

Page A-19

--- [page 98](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=98) ---

GPS SPS PS 

April 2020 

###### **A.4.10  Group Delay Time Correction (TGD) Errors** 

As described in IS-GPS-200 and IS-GPS-705, the group delay time correction (TGD) is broadcast in the LNAV and CNAV messages for the benefit of SF GPS receivers.  Errors in the broadcast TGD value affect the URE experienced by SF GPS receivers which apply that TGD value. 

Table A.4-2 illustrates the typical method for including TGD errors in the Control Segment contribution to the L1 C/A-code SPS SIS URE.  The same method is also used for including TGD errors in the Control Segment contribution to the L2 CM-code and L5 I5-code/Q5-code SPS SIS UREs.  TGD error effects are included in the performance standards in Section 3 of this _SPS PS_ . 

###### **A.4.11  Spatial Dependency** 

As described earlier in this Section, the GPS UERE budgets and the SPS SIS accuracy standards vary as a function of the elapsed time since upload.  The UERE budgets and SIS accuracy standards do not vary as a function of the spatial “look angles” relative to the satellites.  The UERE budgets and accuracy standards apply equally at every point within the satellite’s coverage footprint. 

In reality, however, the SPS SIS URE does vary significantly across each satellite’s coverage. The sources of this spatial dependency are errors in the satellite orbit.  Satellite orbit errors are primarily due to either:  (a) unpredictable satellite accelerations, or (b) inaccurate ephemeris data uploads.  The distinction between these sources of satellite orbit errors is manifested in the UERE budgets of Tables A.4-1 through A.4-4.  Unpredictable satellite accelerations are satellite specific, and the Space Segment has a UERE budget allocation for them in Tables A.4-1 through A.4-4. Inaccurate ephemeris data uploads are due to a mix of estimation/prediction errors plus curve fit limitations, and the Control Segment has UERE budget allocations for each of them in Tables A.4-1 through A.4-4.  There are also secondary causes of satellite orbit errors, such as misorientation of the lever arm from the satellite center of mass to the broadcast antenna phase center.  These secondary causes of satellite orbit errors are also in the UERE budgets of Tables A.4-1 through A.4-4 under the “other segment errors” lines for the Space Segment and for the Control Segment. 

The SIS URE’s spatial dependency on satellite orbit errors is partially explained in Figure A.4-6. This figure shows a horizontal orbit error “H” (also known as a tangential orbit error) resulting from some combination of Space/Control Segment errors.  In Figure A.4-6, the horizontal orbit error vector is oriented due north, with the satellite actually being located further south than the location indicated by the broadcast ephemeris data (the sense of the error vector is “indicated minus truth”). 

5th Edition 

Page A-20

--- [page 99](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=99) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
Projection  =  +H x sin(13.88°)<br>H<br>13.88° Projection  =  0<br>13.88°<br>Projection  =  -H x sin(13.88°)<br>Not to scale<br><!-- End of picture text -->

**Figure A.4-6.  Illustration of Spatial Dependency - Horizontal Orbit Error** 

An observer located at the edge of the satellite’s coverage footprint due north of the sub-satellite point will perceive a _positive_ instantaneous URE because the satellite’s true location is further away from the observer than the location indicated by the broadcast ephemeris data.  An observer located at the edge of the satellite’s coverage footprint due south of the sub-satellite point will perceive a _negative_ instantaneous URE because the satellite’s true location is closer than the location indicated by the broadcast ephemeris data.  And an observer located at center of the satellite’s coverage footprint exactly at the sub-satellite point will perceive _zero_ instantaneous URE because the satellite’s true location is just as far away as the location indicated by the broadcast ephemeris data. 

This sinusoidal variation of the instantaneous URE across the coverage footprint depending on the look angle projection is characteristic of horizontal orbit errors.  In the customary radialalongtrack-crosstrack (RAC) orbital coordinate system, the alongtrack (A) and crosstrack (C) orbital errors are the two orthogonal horizontal error components and each has the same sinusoidal characteristic in its impact on the instantaneous URE.  Over a satellite’s coverage footprint on the Earth’s surface, their maximum impact on the instantaneous URE is ±0.240 x A and ±0.240 x C.  Across the coverage footprint on the Earth’s surface at a 2° mask, their rootmean-square (RMS) effect on the URE is 0.141 x A and 0.141 x C.  At the edge of the terrestrial service volume (0° mask, 3,000 km above a mean Earth radius of 6,371 km), their maximum impact on the instantaneous URE is ±0.353 x A and ±0.353 x C. 

The second part of URE’s spatial dependency on satellite orbit errors is explained in Figure A.47.  This figure shows a radial orbit error (“R”) resulting from a combination of Space/Control Segment errors.  In Figure A.4-7, the radial orbit error vector is oriented towards the Earth, with the satellite actually being located further away from the Earth than the location indicated by the broadcast ephemeris data. 

5th Edition 

Page A-21

--- [page 100](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=100) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
Projection  =  +R x cos(13.88°)<br>R<br>13.88° Projection  =  +R<br>13.88°<br>Projection  =  +R x cos(13.88°)<br>Not to scale<br><!-- End of picture text -->

**Figure A.4-7.  Illustration of Spatial Dependency - Radial Orbit Error** 

An observer located anywhere within the satellite’s coverage footprint (north, south, east, west, or centered) will perceive a _positive_ instantaneous URE because the satellite’s true location is always further away from the observer than the location indicated by the broadcast ephemeris data.  The URE spatial dependency for radial (R) orbital errors is cosinusoidal rather than sinusoidal as for the horizontal orbital errors.  The impact of an R orbital error on the instantaneous URE does not change algebraic signs at the sub-satellite point as does the impact of A or C orbital errors. 

Over the coverage footprint on the Earth’s surface, the maximum impact on the instantaneous URE of a radial error is 1.000 x R and the minimum impact is 0.971 x R.  Across the coverage footprint on the Earth’s surface at a 2° mask, the RMS effect on the URE is 0.980 x R.  At the edge of the terrestrial service volume (0° mask, 3,000 km above a mean Earth radius of 6,371 km), the minimum impact on the instantaneous URE is 0.936 x R. 

SPS SIS timing errors (e.g., satellite clock, inter-signal delays, group delays) do not cause the URE to vary across a satellite’s coverage.  SPS SIS timing errors are omni-directional.  They affect the URE equally at every point within the satellite’s coverage. 

As described in Section 3.4, the SPS SIS accuracy performance standards are addressed in terms of a "global statistic URE" where "global statistic URE" means the statistical URE across the portion of the globe in view of the satellite.  There are two generally accepted methods for computing the global statistic URE for a satellite at a particular instant in time as an (RMS) value. Those two methods are: 

1. <u>Brute Force RMS.  The instantaneous URE values can be evaluated at a large number of</u> spatial points spread evenly across the satellite’s coverage, and the global statistic URE value can then be computed as the RMS of the instantaneous URE value at each of those spatial points. 

5th Edition 

Page A-22

--- [page 101](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=101) ---

GPS SPS PS 

April 2020 

2. Piecewise RMS.  The satellite’s instantaneous alongtrack, crosstrack, and radial orbit error components, plus its total SPS SIS timing error can be used piecewise in the following equation: 

Global Statistic URERMS = ((cxT)<sup>2</sup> +(0.980xR)<sup>2</sup> +(0.141xA)<sup>2</sup> +(0.141xC)<sup>2</sup> -1.960xcxTxR)<sup>½</sup> (A-1) 

where 

- c = speed of light 

- T = total Timing error 

- R = Radial orbit error 

- A = Alongtrack orbit error 

C = Crosstrack orbit error 

and where the final term in the equation accounts for the correlation (possibly significant) between the total timing error and the radial orbit error. 

Rather than computing an RMS statistic, there are two similar methods for computing the global statistic URE for a satellite at a particular instant in time as a 95% value.  Those two methods are: 

1. <u>Brute Force 95%.  The instantaneous URE values can be evaluated at a large number of</u> spatial points spread evenly across the satellite’s coverage, and the global statistic URE value can then be computed as the 95<sup>th</sup> percentile of the instantaneous URE value at each of those spatial points. 

2. Piecewise 95%.  The satellite’s instantaneous alongtrack, crosstrack, and radial orbit error components, plus its total SPS SIS timing error can be used piecewise in the following equation: 

|Global Statistic URE95%| ≤ (|(cxT)+R|+0.240x(A<sup>2</sup> +C<sup>2</sup> )<sup>½</sup> ) 

(A-2) 

Where c, T, R, A, and C are as above. 

_Note:_ 

_1. The two piecewise methods above are only applicable at a particular instant in time.  The two brute force methods are easily extended to cover multiple instants in time._ 

###### **A.4.12  Inter-Signal Bias (ISB) & Inter-Signal Correction (ISC) Errors** 

The inter-signal bias (ISB) in transmit time between the reference L1 P(Y)-code signal and the L1 C/A-code signal contributes directly to the L1 C/A-code signal SPS URE.  It is accounted for in Table A.4-2 as part of the group delay stability, and its effects are included in the performance standards in Section 3 of this _SPS PS_ . 

The LNAV data stream does not contain any information relative to the ISB for the C/A-code signal.  The CNAV data stream does, however, contain ‘inter-signal correction’ (ISC) parameters for the C/A-code signal, the L2C signals (the same ISC applies to both the CM and CL signals), the I5 signal, and the Q5 signal.  Each of these ISC parameters is an estimate of the ISB in transmit time between the reference L1 P(Y)-code signal and the relevant SPS SIS signal.  An 

5th Edition 

Page A-23

--- [page 102](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=102) ---

GPS SPS PS 

April 2020 

SPS receiver which applies the broadcast ISC values to the measured pseudoranges in accordance with IS-GPS-200/IS-GPS-705 is able to cancel out the ISB effects on the measured pseudoranges from the relevant SPS SIS signal. 

Cancelling out the ISB effects on the measured pseudoranges for any SPS SIS signal with the ISC value provides a direct one-to-one benefit on the SF SPS SIS URE for that signal.  The SF L1 C/A-code URE after applying the broadcast ISC value for that C/A-code signal is better (lower) than the SF L1 C/A-code URE obtained without applying the broadcast ISC value.  The accuracy improvement effects of properly applying the broadcast ISC values are included in the SF SPS SIS URE performance standards in Section 3 of this _SPS PS_ for the L2C signals, the I5 signal, and the Q5 signal. 

The DF ionospheric delay correction equations in IS-GPS-200 and IS-GPS-705 utilize the differences between pseudoranges measured across frequencies to determine the total ionospheric delay affecting the SIS at each frequency.  Due to scaling factors which effectively act as multipliers of the differential ISB between the two DF signals, properly applying the pair of ISC values to those signals is critical to obtaining an accurate DF ionospheric delay correction. The accuracy improvement effects of properly applying the broadcast ISC values are included in the performance standards in Section 3 of this _SPS PS_ for the identified DF SPS SIS component combinations. 

5th Edition 

Page A-24

--- [page 103](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=103) ---

GPS SPS PS 

April 2020 

#### **SECTION A.5  Integrity** 

###### **A.5.1  Relationship with Section 3.5** 

Section 3.5 contains the SPS SIS performance standards for integrity.  This section provides background information relative to the SPS SIS integrity performance standards. 

###### **A.5.2  URA Relationship to Integrity** 

One of the axioms of information theory is that all data is useful provided one knows how much weight to give to the data.  This axiom applies well to data from the SPS SIS.  Some satellites inherently provide more accurate data on average than other satellites do.  One should logically place more weight on the data from the inherently more accurate satellites than on data from inherently less accurate satellites. 

The LNAV URA index, "N", included in each satellite's broadcast LNAV data stream describes the satellite's expected accuracy (i.e., 1-sigma bounds on the expected URE) as illustrated below. Note that this table is equivalent to the look-up table in IS-GPS-200.  For most accuracy-related or data weighting purposes, the ‘typical expected URE’ values in the second column are adequate.  For integrity assurance purposes however, the upper bound values in the furthest right column are the ‘integrity assured URA’ (IAURA) values for each LNAV URA index, "N". 

**Table A.5-1.  LNAV URA Index to Expected URE Relationship** 

|**LNAV URA**<br>**Index "N"**|**Typical Expected URE,**<br>**1-sigma**|**Numerical URA**<br>**Bounds on the**|**Value, Rep**<br>**Expected**|**resenting the**<br>**URE, 1-sigma**|
|---|---|---|---|---|
|0|2.0 m|0.00 m|URA|2.40 m|
|1|2.8 m|2.40 m|URA|3.40 m|
|2|4.0 m|3.40 m|URA|4.85 m|
|3|5.7 m|4.85 m|URA|6.85 m|
|4|8.0 m|6.85 m|URA|9.65 m|
|5|11.3 m|9.65 m|URA|13.65 m|
|6|16.0 m|13.65 m|URA|24.00 m|
|7|32.0 m|24.00 m|URA|48.00 m|
|8|64.0 m|48.00 m|URA|96.00 m|
|9|128.0 m|96.00 m|URA|192.00 m|
|10|256.0 m|192.00 m|URA|384.00 m|
|11|512.0 m|384.00 m|URA|768.00 m|
|12|1024.0 m|768.00 m|URA|1536.00 m|
|13|2048.0 m|1536.00 m|URA|3072.00 m|
|14|4096.0 m|3072.00 m|URA|6144.00 m|
|15|No Expectation Provided|6144.00 m|URA|Use at own risk|



_Notes:_ 

> _1. The LNAV URA Index, and its corresponding ‘Typical Expected URE’ and ‘Numerical URA Value’, includes all SPS SIS error components except for those specific to SF C/A-code operation (i.e., TGD inaccuracy, L1 P-to-L1 C/A-code biases)._ 

5th Edition 

Page A-25

--- [page 104](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=104) ---

GPS SPS PS 

April 2020 

_2. If the LNAV URA were completely reliable, then the SPS SIS would have full integrity with regards to all SPS SIS error components except for those specific to SF operation.  For instance, say that: (1) all of the satellites except one always broadcast a SPS URA index of 3 and the actual SPS URE for those satellites always follows a normal distribution with a 1-sigma dispersion of 5.7 meters, and (2) one satellite always broadcasts a SPS URA index of 7 and the actual SPS URE for that satellite always follows a normal distribution with a 1-sigma dispersion of 32.0 meters.  Each SPS SIS has full integrity in this case because the user (i.e., the SPS receiver) can decide whether the satellite which always broadcasts a SPS URA index of 7 should be used for navigation in the context of the particular mission to be accomplished.  As a general rule, most modern SPS receivers would still use the satellite broadcasting a SPS URA index of 7, but they would deweight it by a factor of about 6 relative to the satellites broadcasting a SPS URA index of 3._ 

In the CNAV data stream, there are four separate URA indexes: URAED, URANED0, URANED1, and URANED2.  IS-GPS-200 and IS-GPS-705 provide the equations necessary to use these four separate URA indexes to compute the ‘typical expected URE’ value for accuracy-related or data weighting purposes and to compute the IAURA value for integrity purposes. 

_Note:_ 

_1. The CNAV URANED0 Index, and its corresponding ‘Typical Expected URE’ and  ‘Numerical URA Value’, include all zero_<sup>_th_</sup> _order SPS SIS error components including those specific to SF C/A-code operation (i.e., TGD inaccuracy, L1 P-to-L1 C/A-code biases)._ 

###### **A.5.3  IAURA-Derived Integrity Tolerance** 

The broadcast URA index in the LNAV data stream or the broadcast URA indexes in the CNAV data stream are used to determine the user's (the SPS receiver's) expectation for the SPS URE and to set the IAURA value for each satellite.  For accuracy-related or data weighting purposes, the ‘typical expected URE’ value can be used directly as a conservative RMS estimate assuming a normal distribution.  For integrity purposes, the IAURA value must be converted into a pass/fail integrity tolerance. 

Treating the IAURA as a normal distribution does not directly lend itself to developing a pass/fail integrity tolerance because a normal distribution has no outer bounds per se.  As can be seen in Table A.5-2, the probability of exceeding a given outer bound drops off as the outer bound increases to ever larger values; but it never becomes absolutely zero no matter how far out the bounds are placed. 

**Table A.5-2.  Normal Distribution Bounds vs. Probability of Exceeding Those Bounds** 

|**Normal Distribution**<br>**Bounds**|**Probability of Exceeding**<br>**Those Bounds**|
|---|---|
|1-sigma|0.317310508|
|2-sigma|0.045500264|
|3-sigma|0.002699796|
|4-sigma|0.000063342|
|5-sigma|0.000000573|
|6-sigma|0.000000002|



5th Edition 

Page A-26

--- [page 105](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=105) ---

GPS SPS PS 

April 2020 

For integrity assurance purposes, outer bounds have been established at 4.42-sigma relative to the IAURA value.  The corresponding probability of exceeding these bounds for a normal distribution is 0.00001 (i.e., 1x10<sup>-5</sup> ).  These outer bounds constitute the not-to-exceed (NTE) SPS SIS URE tolerance for integrity.  A SPS SIS URE exceeding the NTE tolerance is defined to be misleading signal-in-space information (MSI).  MSI may or may not be a loss of SPS SIS integrity depending on whether a timely alert is issued. 

_Notes:_ 

_1. These outer bounds are consistent with the outer bounds used by legacy civil users who were subject to SA before the use of SA was discontinued in May 2000.  SA was the dominant SPS SIS error with an a priori assumed 1-sigma dispersion of 33 m.  For these civil users,_  _150 m outer bounds were established for SPS SIS integrity purposes by rounding the product of 33 m multiplied by 4.42._ 

_2. SPS SIS MSI may cause some SPS receivers to output hazardously misleading information (HMI). The factors which determine if SPS SIS MSI will cause HMI or not include: whether the affected SPS SIS is being used in the position solution, the relative geometry of the set of satellites being used in the position solution, whether the SPS receiver performs any autonomous integrity monitoring to detect the occurrence of MSI and/or exclude an affected SPS SIS in a timely manner (see Appendix B for further information), and the user’s particular tolerance for error in the current application._ 

###### **A.5.4  Nature of SPS SIS URE** 

Neglecting failures and ignoring Control Segment intervention, the SPS SIS URE from satellites can reasonably be assumed to follow a normal distribution over the long term with zero mean. Under this assumption, the SPS URA would be a fully satisfactory means of providing SPS SIS integrity.  Unfortunately, GPS failures do occur and many of them can impact the SPS SIS URE enough to cause the SPS URE to exceed the SPS SIS URE NTE tolerance.  Fortunately, the Control Segment monitors the SPS SIS URE and is able to intervene when such a "soft" GPS failure has occurred. (As used in this _SPS PS_ , a soft GPS failure is a failure where the SPS SIS is still healthy but the URE is impacted enough to pose a potential risk to integrity.  A hard GPS failure is a failure where the SPS SIS is no longer trackable and therefore poses no risk to integrity.) 

###### **A.5.4.1  Integrity Failure Modes and Effects** 

GPS failures which impact the SPS SIS, can occur in the satellites, the Control Segment, or in the information supplied to the Control Segment by an external source.  The soft failure modes which pose a potential integrity risk are listed in Table A.5-3 along with the representative type of effect on the URE.  The various types of URE effects are illustrated in Figure A.5-1.  Table A.5-3 also identifies whether these potential integrity failure modes have a related symptom which is detectable by a SPS receiver. 

5th Edition 

Page A-27

--- [page 106](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=106) ---

GPS SPS PS 

April 2020 

###### **Table A.5-3.  Potential Integrity Failure Modes** 

|**System/**<br>**Segment**|**Failure Mode**|**Representative**<br>**Effect on URE**|**Spatially**<br>**Dependent**|**Receiver**<br>**Detectable**|
|---|---|---|---|---|
||Momentum Dump (Thruster Firing)|Step/Ramp/Sinusoid|Yes|No|
||Loss of L1 or L2 or L5|Sinusoid|No|Yes|
||L1 or L2 or L5 Power Reduction|Noise|No|Yes|
||Incorrect PRN|Varies|Some|Yes|
|Satellite|Clock Frequency Shift or Instability|Ramp|No|No|
||NAV Message Data Garbled|Varies|Some|Yes|
||PRN Code Generation Errors|Step|No|Some|
||Frequency Synthesizer Upsets|Step|No|No|
||Out-Gassing|Step/Ramp/Sinusoid|Yes|No|
||Delayed/Missed Upload|Ramp|Some|No|
||Bad Upload: Bad Clock/Ephemeris|Step, Ramp, or Sinusoid|<br>Some|No|
||Bad Upload: Wrong/Irrelevant Data|<br>Varies|Some|Most|
|Control|Operational Error: Health Settings|Step, Ramp, or Sinusoid|<br>Some|No|
||Operational Error: Data Content|Step or Sinusoid|Some|No|
||GA Induced Errors|Varies|No|Yes|
||MSInducedErrors|Step,Ramp, orSinusoid|Some|No|
||_Reserved_|_Reserved_|_Reserved_|_Reserved_|
|Input<br>|Bad Earth Orientation Predictions|Ramp or Sinusoid|Yes|No|
|Data|Bad Solar Flux Observations|Sinusoid|Yes|No|
||Bad UTC(USNO)Offset Data|Other|No|No|





<!-- Start of picture text -->
MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0  0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>a.  Ramp Error  b.  Step Error<br>MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0  0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>c.  Sinusoid Error  d.  Noise Error<br>Instantaneous URE  Instantaneous URE<br>Instantaneous URE  Instantaneous URE<br><!-- End of picture text -->

**Figure A.5-1.  Types of URE Effects** 

5th Edition 

Page A-28

--- [page 107](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=107) ---

GPS SPS PS 

April 2020 

For the potential integrity failure modes which are detectable by a SPS receiver, most of them are accompanied by a SPS SIS alarm or warning indication which is what is actually detected by the SPS receiver.  The C/A-code SIS alarm indications include, but are not limited to, the following (CM-code, CL-code, I5-code, and Q5-code are similar): 

- (1) The apparent cessation of L1  SIS transmission (can also be symptomatic of a hard failure or Control Segment intervention actions). 

- (2) The elimination of the standard C/A-code (can also be symptomatic of a hard failure or Control Segment intervention actions). 

- (3) The substitution of non-standard C/A-code for the standard C/A-code (an action taken by the satellite when it autonomously detects certain failures that could compromise the URA). 

- (4) The substitution of pseudorandom noise (PRN) C/A-code number 37 for the standard C/Acode (indicative of Control Segment intervention). 

- (5) The failure of parity on 5 successive words of LNAV data (can be symptomatic of a "bad upload: wrong/irrelevant data" failure). 

- (6) The broadcast Index of Data Ephemeris (IODE) does not match the 8 LSBs of the broadcast IODC data (can also be symptomatic of a "bad upload: wrong/irrelevant data" failure; excluding normal data set cutovers, see IS-GPS-200). 

- (7) All transmitted bits in subframes 1, 2, or 3 are set to 0's or to 1's (can be symptomatic of a "bad upload: wrong/irrelevant data" failure). 

- (8) Default LNAV data is being transmitted in subframes 1, 2, or 3 (an action taken by the satellite when it autonomously detects certain failures that could compromise the URA). 

- (9) The preamble does not equal 100010112, or 13910, or 8B16 (can be indicative of a failure in the satellite navigation data unit or in the navigation baseband unit). 

###### **A.5.4.2  Control Segment Monitoring and Intervention** 

One of the Control Segment's major functions is monitoring and assessing the GPS SIS performance.  If the Control Segment determines that a failure has occurred which will adversely affect the SPS SIS performance, the Control Segment will intervene to prevent, or at least minimize, the impact of the failure on the SPS SIS performance. 

When a soft failure effect on the SPS SIS URE is small, or when rare normal fault-free performance excursions occur, the typical Control Segment intervention is to perform a contingency upload (see paragraph A.4.4) to the affected satellite.  Contingency uploads serve both to prevent an integrity fault from occurring and to maintain SPS SIS accuracy. 

5th Edition 

Page A-29

--- [page 108](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=108) ---

GPS SPS PS 

April 2020 

_Note:_ 

_1. During fault-free operation, the SPS SIS URE is assumed to follow a normal distribution with zero mean.  Large SPS SIS URE values are expected to occur during fault-free operations but they should be rare (see Table A.5.2)._ 

When the soft failure effect on the SPS SIS URE is large, the typical Control Segment intervention is to send a SatZap command to the affected satellite.  The SatZap command results in the satellite immediately switching its assigned PRN code identity to PRN code 37 (i.e., the satellite starts transmitting P(Y)-code number 37 and C/A-code number 37).  This terminates the trackable SPS SIS from the SatZapped satellite.  An equivalent intervention, also sometimes referred to as SatZap, is commanding the satellite to switch to transmitting non-standard codes in lieu of the normal PRN codes.  Compared to performing a contingency upload or even just performing an upload to set the satellite unhealthy, SatZap is a much quicker method of intervening -- but it necessarily renders the SPS SIS untrackable by all SPS receivers. 

The Control Segment is able to monitor each satellite's GPS SIS 100% of the time but is not able to upload or command each satellite 100% of the time due to GA limitations.  Although very unlikely, this _SPS PS_ assumes it is possible for a SPS SIS integrity fault to persist for up to 6 hours before the Control Segment is able to intervene.  This intervention delay is comparable to an average satellite in-view time of 6<sup>2</sup> /3 hours.  Most SPS SIS integrity faults (99.9%) persist for less than or equal to 3 hours before the Control Segment intervenes.  On average (50%), SPS SIS integrity faults persist for approximately 1 hour. 

_Note:_ 

_1. The 6_<sup>_2_</sup> _/3 hour average in-view time (along with the 6 hour maximum intervention delay) also applies to SPS SIS UREs that are large, but not so large as to result in an integrity fault or MSI.  For receiver autonomous integrity monitoring (RAIM) purposes, the average in-view time can be conservatively assumed as the effective correlation time for "large, but not too large" SPS SIS UREs._ 

###### **A.5.4.3  Control Segment Preemptive Actions** 

One of the Control Segment's other major functions is conducting on-orbit O&M of the satellites. Most satellite O&M are scheduled in advance.  Certain types of O&M activities are quite likely to cause a large SPS SIS URE (e.g., station keeping maneuvers and atomic clock maintenance). In order to prevent a large SPS SIS URE from compromising the URA-derived NTE tolerance and thereby causing a SPS SIS MSI, the Control Segment will take preemptive action to warn SPS receivers to not use the SPS SIS from the affected satellite.  The preemptive SPS SIS warning indications include, but are not limited to, causing the satellite to broadcast the following: 

- (1) An appropriately inflated LNAV URA index "N" value and/or appropriately inflated CNAV set of URAED and URANED values (appropriately inflated to cover the expected risk of an abnormally large SPS SIS URE). 

- (2) The LNAV 6-bit health status word in subframe 1 with the MSB equal to 12 and/or the 5 LSBs equal to anything other than 000002 (a typical "do not use" indication is with the MSB equal to 12 (“some or all NAV data are bad”) and the 5 LSBs equal to 111002 (“SV is temporarily out”)) and/or all three bits of the three-bit signal health field in MT-10 of the CNAV message set to ones. 

5th Edition 

Page A-30

--- [page 109](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=109) ---

GPS SPS PS 

April 2020 

- (3) An LNAV URA index "N" = 15 and/or CNAV URAED and URANED0 = 15 (default action which may be taken by the Control Segment when a reliable URA cannot be computed). 

- (4) The URA alert flag is set to 12. 

To be preemptive, a SPS SIS warning indication must be broadcast to GPS receivers in advance of the potential integrity fault.  So long as the last bit of the LNAV subframe and/or CNAV message which contains the particular SPS SIS warning indication is received before the NTE tolerance is breached, no integrity fault will occur because the SPS SIS has provided a timely warning that it should not be used.  The Control Segment may take one or more of the above preemptive actions, or other preemptive actions (e.g., SatZap) in advance of conducting the O&M that can cause the large SPS SIS URE.  The fact that a preemptive action or actions occurs early with respect to the NTE tolerance being breached has no adverse impact on SPS SIS integrity.  There is no "false alarm" requirement to constrain how early the Control Segment can take preemptive actions.  The impact of "too early" preemptive actions, or preemptive actions which occur when the subsequent O&M is cancelled or not completed, is the resulting adverse effect on SPS SIS availability. 

_Notes:_ 

_1. As described in paragraph 2.4.4.3, the Control Segment normally operates the SPS SIS in such a manner to allow GPS receivers at least five minutes to receive, process, and apply the real-time health-related information in the NAV message before taking any O&M actions that could cause a large SPS SIS URE under normal conditions._ 

_2. NANUs are another form of preemptive warning.  However, NANUs are not considered as a warning for integrity purposes.  The SPS SIS alarm and warning indications received in real time by an operating GPS receiver always take precedence over the NANU information received off-line by an end user.  However, NANUs are considered as an adequate warning for continuity purposes (see Section 3.6)._ 

###### **A.5.4.4  Satellite On-Board Monitoring and Intervention** 

The satellites are able to autonomously perform a substantial amount of on-board monitoring for those subsystems which affect the SPS SIS performance.  If a satellite determines that a malfunction has occurred which may adversely affect the SPS SIS performance, an internal alarm will be generated, and the satellite will intervene to minimize the impact of that failure on the SPS SIS performance.  If the detected malfunction affects the satellite's reference frequency standard or other critical subsystem, the satellite will provide an integrity alert by switching its broadcast standard PRN code signals  to non-standard code (NSC) signals.  If the detected malfunction affects the satellite's NAV data generation subsystem, the satellite will provide an integrity alert by switching its broadcast LNAV subframe content to default data (alternating 1s and 0s with invalid parity) and/or some or all CNAV messages to MT-0.  In general, the Block II series of satellites will switch to broadcasting NSC or default NAV data within 6 seconds of detecting a fault which can impact SPS SIS integrity. 

Many of malfunctions detected by the satellite on-board monitoring are transient, either because the conditions which cause them only exist for a short while or because the satellite will autonomously correct the malfunction.  If the on-board monitoring determines the detected 

5th Edition 

Page A-31

--- [page 110](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=110) ---

GPS SPS PS 

April 2020 

malfunction is no longer present, the satellite will return to broadcasting normal PRN-codes and/or normal NAV data as appropriate.  Typical recovery times range from 6 to 24 seconds. 

_Notes:_ 

_1. When a satellite switches over to broadcasting NSC signals in lieu of standard PRN-code signals, GPS receivers which are currently tracking the satellite signals lose track of the satellite signals at the time of the switchover.  GPS receivers which are currently attempting to acquire the satellite signals are unable to acquire the satellite signals._ 

_2. When a satellite switches over to broadcasting default NAV data in lieu of normal NAV data, GPS receivers are assumed to continue tracking the satellite signals through the switchover even though the GPS receiver is assumed to intentionally not use any of the default NAV data.  GPS receivers which are currently attempting to acquire the satellite signals are assumed to be able to acquire the satellite signals but will not intentionally use any of the default NAV data._ 

_3. Satellite malfunctions which are not detected by the satellite may require Control Segment intervention to protect the user (see paragraph A.5.4.2).  Control Segment intervention is usually required to return a satellite to broadcasting a trackable and healthy SPS SIS._ 

###### **A.5.5  Timely Alert Considerations** 

The definition of integrity used in this document requires a "timely alert" to be provided when the SPS SIS should not be used for positioning.  Based on operational needs, a threshold of 10 seconds after a breach of the SPS SIS URE NTE tolerance has been established for an alarm or warning to be issued in order to be considered timely.  Alarms and warnings are collectively called "alerts".  This 10 second threshold applies to alerts issued to the end user of the SPS receiver, and so includes both the time allocated to the SPS SIS and the time allocated to the SPS receiver. For the SPS SIS, the allocated time (known as the "time to alert" or TTA) is 8 seconds for all alert indications except for SatZap and NSC.  SatZap and NSC are allocated the full 10 seconds.  If a SPS alert indication is transmitted within 8 seconds of an integrity fault occurring, then -- by definition -- the SPS SIS has converted the MSI into "alerted misleading signal-in-space information" (AMSI) because a timely alert has been provided.  On the other hand, if a SPS alert indication is not transmitted within 8 seconds of an integrity fault occurring, then the SPS SIS is defined to have provided "unalerted misleading signal-in-space information" (UMSI).  UMSI constitutes a loss of SPS SIS integrity while AMSI is not a loss of integrity since the alert is timely. Breaches of the relevant NTE tolerance for less than the overall TTA of 10 seconds do not require a timely alert. 

Preemptive actions taken by the Control Segment (as described in paragraph A.5.4.3) are fully satisfactory as alerts for integrity purposes.  To be timely, the last bit of the NAV message subframe which contains the particular SPS SIS warning indication must be present at the receiving antenna within 8 seconds of the NTE tolerance being breached.  Preemptive Control Segment actions are taken well in advance of scheduled O&M activities that are likely to cause a large SPS SIS URE (e.g., station keeping maneuvers and atomic clock maintenance).  The fact that Control Segment preemptive actions occur early (e.g., 5 minutes or more) with respect to the NTE tolerance being breached has no adverse impact on SPS SIS integrity. 

5th Edition 

Page A-32

--- [page 111](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=111) ---

GPS SPS PS 

April 2020 

###### **A.5.6  Nature of SPS SIS URE Time Derivatives** 

GPS receivers provide end users with velocity information in addition to position and time information.  This is evident in the fact that the outputs of a GPS receiver are commonly referred to as PVT (i.e., position, velocity, and time).  The accuracy and integrity of the GPS receiver's velocity output depends in large part on the accuracy and integrity of the SIS velocity.  The SIS velocity errors are called the "first time derivatives of the URE", "pseudorange rate errors", or URRE.  GPS receivers generally do not output acceleration information.  SIS acceleration errors -- more properly the "second time derivatives of the URE", "pseudorange acceleration errors", or URAE -- are important primarily for their effect on the integrity of the GPS receiver's output PVT information and for the limitations they impose on augmentations like differential GPS (DGPS) and inertial aiding. 

###### **A.5.6.1  URE Time Derivative Illustrations for Integrity** 

A typical large pseudorange rate error was illustrated by Figure A.5-1(a) given earlier for a URE ramp error effect.  Figure A.5-1(a) showed the instantaneous URE being well behaved before the start of the failure, then ramping off rapidly after the failure onset at a relatively constant rate. Since the instantaneous URRE is the slope of the instantaneous URE, the ramp error for the instantaneous URE thus represents a step error for the instantaneous URRE as shown in Figure A.5-2(a).  This type of instantaneous URE ramp error -- or instantaneous URRE step error -- is the integrity failure paradigm for testing RAIM algorithms in GPS receivers (see Appendix B for information on RAIM).  The URRE step used for RAIM testing is 5 m/sec.  Although fine for test purposes, it is not a representative failure magnitude for the actual SPS SIS. 

Figure A.5-2(b) shows an instantaneous URE step error with a constant (near zero) instantaneous URRE on both sides of instantaneous URE step error.  This sort of instantaneous URE step error is a much larger version of the URE step changes which are seen at NAV message data transitions after an upload cutover and the smaller URE step changes which are seen at the NAV message data set cutovers every two hours (see Figure A.4-4).  While none of these instantaneous URE step changes necessarily involves a finite-duration instantaneous URRE to get from one instantaneous URE to the other, an instantaneous URRE will be perceived if the simple difference between two instantaneous UREs which straddle the step change is computed and divided by the difference in time separating the two instantaneous UREs.  In the limit, as the time difference between two instantaneous UREs becomes smaller and smaller, this perception will converge to an infinitely large instantaneous URRE occurring over an infinitely short duration. 

Another typical URRE error arises from an instantaneous URE sinusoid error effect as illustrated by Figure A.5-2(c).  After the failure occurs in this figure, the instantaneous URE is at first positive, then it gradually becomes zero at the maximum positive URE, then it becomes negative, and then 

5th Edition 

Page A-33

--- [page 112](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=112) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0  0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>a.  URE Ramp Error - URRE Step Error b.  URE Step Error - URRE Spike<br>MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0  0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>    c.  URE Sinusoid Error -  d.  URE Noise Error - URRE Noise Error<br>URRE Sinusoid Error<br>Instantaneous URE/URRE Instantaneous URE/URRE<br>Instantaneous URE/URRE Instantaneous URE/URRE<br><!-- End of picture text -->

**Figure A.5-2.  Types of URE/URRE Effects** 

it starts to become zero again.  This is a fairly common type of instantaneous URE.  It is seen when ephemeris errors are mapped along the line-of-sight to a GPS receiver over the full in-view period.  The peak URE magnitudes of these pseudorange rate errors are usually only about half of the URE budget.  Because the instantaneous URRE is the time derivative of the instantaneous URE, the instantaneous URRE associated with a sinusoidal instantaneous URE is also a sinusoid, but offset in phase by a quarter period (i.e., the time derivative of a sine wave is a cosine wave). 

Depending on the particular time scale involved, there may or may not be noise-like instantaneous URREs associated with the instantaneous URE noise error like those shown in Figure A.5-2(d). If the instantaneous URE noise time scale is very long, then there will be instantaneous URREs whose characteristics are equivalent to many successive ramp errors with random magnitudes and durations.  If the time scale is very short, then there will only be instantaneous URREs with infinitely large magnitudes occurring over infinitely short durations. 

###### **A.5.6.2  URE Second Time Derivative Illustrations** 

Figure A.5-2(a) showed a step change in the instantaneous URRE where the instantaneous URRE is near zero before the instantaneous URE ramp starts and jumps up to a near-constant positive instantaneous URRE value immediately afterwards.  Just as there does not need to be a finite-duration instantaneous URRE when an instantaneous URE step change occurs to get from one instantaneous URE to the next, there does not need to be a finite-duration instantaneous 

5th Edition 

Page A-34

--- [page 113](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=113) ---

GPS SPS PS 

April 2020 

URAE when a URRE step change occurs to get from one instantaneous URRE to the next.  The rationale is analogous to that given in the preceding section regarding the URE step change in Figure A.5-2(b).  Some GPS receivers may perceive an instantaneous URAE when an instantaneous URE ramp error occurs if they simply compute the difference between two instantaneous URREs which straddle the start of the ramp error and divide by the difference in time separating the two instantaneous URREs; but there really is no finite-duration instantaneous URAE for the "sharp" ramp error, only an infinitely narrow instantaneous URAE spike as shown in Figure A.5-3(a).  A "dull" instantaneous URE ramp error, however, may have a large finiteduration instantaneous URAE -- particularly if the magnitude of the ramp error starts out small but grows over time. 

Figure A.5-3(b) shows a double-headed infinitely narrow instantaneous URAE spike occurring at the time of the instantaneous step change in the URE.  The reason for the double-headed URAE spike is intuitive if one imagines the instantaneous URE step change being caused by the URRE spike shown in A.5-2(b).  The positive portion of the URAE spike occurs when the URRE spike starts and the negative portion occurs when the URRE spike ends.  Since the URRE spike is infinitely narrow, the two portion of the URAE spike overlap and result in what appears to be a double-headed spike. 



<!-- Start of picture text -->
MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0 0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>b.  URE Step Error -<br>a.  URE Ramp Error - URAE Spike Error<br>      URAE Double Spike Error<br>MSI  MSI<br>+  Start  +  Start<br>+ SIS URE NTE  + SIS URE NTE<br>Tolerance  Tolerance<br>0  0<br>Time  Time<br>- SIS URE NTE  - SIS URE NTE<br>Tolerance  Failure  Tolerance  Failure<br>-  Onset  -  Onset<br>c.  URE Sinusoid Error -<br>d.  URE Noise Error - URAE Noise Error<br>     URAE Sinusoid Error<br>Instantaneous URE/URAE<br>Instantaneous URE/URAE Instantaneous URE/URAE<br>Instantaneous URE/URAE<br><!-- End of picture text -->

**Figure A.5-3.  Types of URE/URAE Effects** 

5th Edition 

Page A-35

--- [page 114](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=114) ---

GPS SPS PS 

April 2020 

Figure A.5-3(c) illustrates the most common form of instantaneous URAE.  Just as the most common form of instantaneous URRE has a sinusoidal effect because it is the first time derivative of an instantaneous URE with a sinusoidal effect, the most common form of instantaneous URAE has a sinusoidal effect because it is the second time derivative of a sinusoidal URE. 

_Note:_ 

_1. The first time derivative of a sine wave is a cosine wave, and the second time derivative of a sine wave is an inverted sine wave._ 

Like Figure A.5-2(d), Figure A.5-3(d) shows instantaneous URAEs with a noise effect.  This need not be the case, however, depending on the particular instantaneous URE noise time scale. 

###### **A.5.6.3  Combinations of URE Time Derivatives** 

Many potential integrity faults manifest themselves via a combination of instantaneous URE time derivatives.  A typical example is shown in Figure A.5-4.  This is an example where the satellite first causes the failure and then autonomously repairs it.  Figure A.5-4(a) shows a pair of offsetting instantaneous URE ramp failures (equal magnitudes but opposite signs) separated by a short period of constant large instantaneous URE.  Recognize the intervening period does not constitute an instantaneous URE step error although it appears similar.  Figure A.5-4(b) shows this same example in the first time derivative domain.  This figure clearly shows the pair of instantaneous URE ramp failures as equal but opposite sign instantaneous URRE step changes. Because the second time derivative of an instantaneous URE ramp failure is zero (i.e., no instantaneous URAE), Figure A.5-2(c) shows a constant instantaneous URAE of zero except for the four double-headed instantaneous URAE spikes which occur at the start and finish of each instantaneous URE ramp failure. 

###### **A.5.7  SPS SIS Component Combination Integrity Considerations** 

The preceding information applies specifically to the C/A-code signal and also applies in general to the other SPS SIS components as indicated.  There are some additional considerations, however, which only apply in the context of the SPS SIS component combinations. 

###### **A.5.7.1  ‘Per SPS SIS Component Combination’ Integrity Accounting** 

As indicated by Tables 3.5-1 through 3.5-5, SPS SIS integrity accounting applies to each SPS SIS component combination separately.  Strictly speaking, a common-cause failure which affects all SPS SIS components concurrently (e.g., a huge satellite clock frequency shift) can be said to result in up to twenty integrity failures because there are up to twenty SPS SIS component combinations identified in Table 2.2-2 that can each be affected.  Per se, this also represents an up to twenty-fold increase in the total number of integrity failures compared to previous editions of this _SPS PS_ where there was only one SPS SIS component that could suffer an integrity failure. Although the total number of integrity failures increases, the SIS integrity performance is unchanged because of the ‘per SPS SIS component combination’ definition specified in Tables 3.5-1 through 3.5-5.  The SIS integrity performance standards for ‘L1 C/A-code+LNAV data’ are the same as they ever were. 

5th Edition 

Page A-36

--- [page 115](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=115) ---

GPS SPS PS 

April 2020 

###### _Note:_ 

_1. If a satellite operating in the minimum SIS broadcast configuration per Table 1.6-2 (i.e., C/A-code + LNAV data) suffers an integrity-related failure in its LNAV data, there is obviously only one integrity failure to impact users.  Conversely, if a satellite operating in the objective SIS broadcast configuration per Table 1.6-2 (i.e., C/A-code + LNAV data, CM-code + CNAV data, CL-code, I5code + CNAV data, Q5-code) suffers an integrity-related failure in just its CNAV data, there are nineteen integrity failures to impact users; the twentieth SPS SIS component combination in Table 2.2-2 (C/A-code + LNAV data) is unaffected by the integrity-related CNAV failure._ 



<!-- Start of picture text -->
HMI  HMI<br>+  Start  End<br>+ SIS URE NTE<br>Tolerance<br>0<br>Time<br>- SIS URE NTE<br>Tolerance  Failure  Failure<br>-  Onset  Repaired<br>a.  Pseudorange (URE) Domain<br>+<br>0<br>Time<br>Failure  Failure<br>-  Onset  Repaired<br>b.  Pseudorange Rate (URRE) Domain<br>+<br>0<br>Time<br>Failure  Failure<br>-  Onset  Repaired<br>c.  Pseudorange Acceleration (URAE) Domain<br>URE Effect<br>Rate Effect<br>Acceleration Effect<br><!-- End of picture text -->

**Figure A.5-4.  Combined URE Time Derivative Examples** 

5th Edition 

Page A-37

--- [page 116](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=116) ---

GPS SPS PS 

April 2020 

###### **A.5.7.2  Independence of SPS SIS Component Combination Integrity** 

Although typically correlated, an integrity failure affecting one SPS SIS component combination does <u>not</u> necessarily mean there is a corresponding integrity failure affecting other SPS SIS component combinations.  Examples where this independence is observed include: 

- LNAV data faults versus CNAV data faults 

- LNAV IAURA values versus CNAV IAURA values 

- LNAV health changes asynchronous with CNAV health changes (temporary) 

- Signal-specific ISC faults 

###### _Note:_ 

_1. In some cases (such as a failure in the signal generation function of one signal), not all broadcast signals will be affected.  However, this_ SPS PS _does not grant partial credit for this situation because a large group of users will be impacted even though many may be spared.  Similarly, different integrity standards are not provided for each individual signal or combination, because they are equivalent for all practical purposes and because the standard is conservative enough that it masks any small differences between them._ 

5th Edition 

Page A-38

--- [page 117](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=117) ---

GPS SPS PS 

April 2020 

#### **SECTION A.6  Continuity** 

###### **A.6.1  Relationship with Section 3.6** 

Section 3.6 contains the SPS SIS performance standards for continuity.  This section provides background information relative to the SPS SIS continuity performance standards.  The SPS SIS performance standards for continuity only apply to the C/A-code signal and the LNAV data stream in this edition of the _SPS PS_ . 

###### **A.6.2    Various Types of Failures and the Impacts on Continuity** 

###### **A.6.2.1  Hard Failures** 

Satellites can suffer failures that result in the cessation of SPS SIS transmissions.  Such failures are known as "hard failures".  The cessation of SPS SIS transmissions need not be sudden as a result of the hard failure, it can be gradual (e.g., a steady drop in transmitted SPS SIS power would be a gradual cessation).  Some hard failures result in an immediate cessation of SPS SIS transmissions, while others result in a delayed cessation (e.g., if a satellite fails such that it can no longer accept new uploads of NAV message data, it will gracefully degrade in the extended operations mode for at least 14 days until the SPS SIS becomes unavailable).  Many different types of hard failures are possible. 

Hard failures are subdivided into two main categories:  (1) long-term failures, and (2) short-term failures.  Long-term (LT) hard failures are basically those failures which result in an irrecoverable loss of the SPS SIS from the satellite.  The normal remedy for LT hard failures is the lengthy process of launching a replacement satellite.  In contrast, short-term (ST) hard failures result in only a temporary loss of SPS SIS from the satellite.  The usual remedy for ST hard failures is the relatively rapid process of switching the satellite configuration over to using a redundant subsystem instead of the failed subsystem.  All critical satellite subsystems have on-board redundancy. 

Whether the hard failure of an otherwise functional satellite occupying a baseline/expandable slot results in a loss of continuity or not depends on the Control Segment issuing a NANU in advance of the SPS SIS interruption.  If the nature of the hard failure is such that the Control Segment issues the NANU at least 48 hours in advance of the interruption, then there is no loss of continuity.  If the hard failure results in a sudden or rapid loss of the SPS SIS from the satellite such that the Control Segment cannot issue a NANU at least 48 hours in advance, then there is a loss of continuity. 

An alternate means of avoiding a loss of continuity exists in those situations where a second satellite occupies the same slot in the baseline 24-slot constellation (or occupies the same position in the case of an expandable 24-slot constellation configuration).  So long as the second satellite does not cease its SPS SIS transmissions, the sudden or rapid loss of the SPS SIS in either of the two satellites occupying that slot does not cause a loss of continuity. 

5th Edition 

Page A-39

--- [page 118](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=118) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. The "48 hour in advance" threshold exists for operational reasons related to air traffic control and flight planning (i.e., NOTAMs -- see DOT-VNTSC-OST-R-15-01).  It is not based on any technical characteristics of the SPS SIS.  Internally, the CS uses a "96 hour in advance" threshold._ 

_2. There are no SPS SIS continuity standards applicable to auxiliary satellites.  This is true no matter where the auxiliary satellite is located.  It is expected that most auxiliary satellites will exhibit lower continuity than satellites occupying slots since most auxiliary satellites will have been made auxiliary because the satellite is near the end of its useful life and is thus more prone to failures._ 

###### **A.6.2.2  Wear-Out Failures** 

Satellites are subject to wear-out failures.  Wear-out failures differ from hard failures in that wearout failures are generally predictable (i.e., “schedulable”).  Hard failures are generally not predictable.  Wear-out failures are a characteristic of the satellite "end-of-life" (EOL) operating phase.  They do not occur on recently launched satellites nor do they occur on satellites in the "middle age" operating phase.  Wear-out failures are all ultimately LT failures, but it is frequently possible to prolong the usefulness of satellites in the EOL phase by the Control Segment expending substantial effort. 

Historically, one of the most likely wear-out failures that can affect satellites is a gradual reduction in on-board electrical power capacity which continues over time until the satellite can no longer sustain full mission capability.  When a satellite reaches this point in its life cycle, the Control Segment can reconfigure the satellite to eliminate some of the load(s) on its electrical subsystem to maintain at least partial mission capability.  Because RF transmitters are one of the major power loads, disabling one or more of the RF transmission chains is reasonable way of enabling continued use of the other RF transmitters.  In the future, the Control Segment may ultimately choose to follow this course of action with older satellites and intentionally disable transmission of the L5 signals to leave enough power to maintain transmission of the L1 and L2 signals. 

It is possible for a wear-out failure during the EOL phase to cause a loss of continuity, but this requires one of two unlikely errors on the part of the Control Segment.  It is extremely improbable that the Control Segment would fail to predict the wear-out failure in advance.  Much more probable, but still unlikely, the Control Segment could underestimate the effort needed to prolong the life of a satellite in the EOL phase.  If the Control Segment chooses to prolong the life of an EOL satellite but later comes up short and cannot expend the necessary effort due to unforeseen circumstances, then -- unless a NANU was issued at least 48 hours before the shortfall -- a loss of continuity will occur. 

_Notes:_ 

_1. The preferred means of avoiding the loss-of-continuity risk posed by a wear-out failure is to simply replace a satellite occupying a slot when it reaches the EOL operating phase.  This is not the required means of avoiding the loss-of-continuity risk, however.  The decision to replace a worn out satellite in a slot or to instead attempt to prolong its life and accept the loss-of-continuity risk is made based on many factors including cost and Control Segment operator workload._ 

_2. An alternate means of minimizing the loss-of-continuity risk posed by a wear-out failure is for the Control Segment to: (a) predict the future point in time where the wear-out failure will become severe enough to pose a non-trivial loss-of-continuity risk, (b) at least 48 hours (nominally 96 hours)_ 

5th Edition 

Page A-40

--- [page 119](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=119) ---

GPS SPS PS 

April 2020 

_in advance of that point in time issue a NANU warning that the SIS/satellite will become unavailable at that time, and (c) preemptively set the 6-bit health status word in subframe 1 to indicate the SIS is unhealthy at the planned time._ 

###### **A.6.2.3  Soft Failures** 

Section 3.5 addresses integrity failures.  Integrity failures are known as "soft failures" in that while a failure has occurred, the SPS SIS continues to be available without an alert indication (alarm or warning) that the failure has occurred.  Because the SPS SIS continues to be available to users, soft failures do not -- in and of themselves -- constitute a loss of continuity. 

Although soft failures do not constitute a loss of continuity themselves, they can certainly trigger a loss of continuity.  Certain soft failures are autonomously detectable on-board a satellite.  If the satellite detects and reacts to that soft failure by transmitting an alert, it is actually the alert that makes the SPS SIS unavailable to users and thereby causes the loss of continuity.  (Soft failures are not predictable, so there is no way to issue a NANU regarding them at least 48 hours in advance).  The same principle applies when the Control Segment detects and reacts to a soft failure.  The loss of continuity occurs when the Control Segment reaction causes the SPS SIS to become unavailable to users without a 48-hour advance warning.  This principle is similar to the one which applies to fault detection alerts issued by the RAIM algorithm in a GPS receiver.  A loss of continuity occurs if the fault cannot be excluded and a "do not use" alert is displayed to the user. 

In the case of a loss of continuity triggered by a soft failure, the Control Segment will provide notification via a NANU as soon as possible after the event. 

###### **A.6.2.4  Satellite O&M Activities** 

Certain types of routine satellite O&M that are almost certain to cause a large SPS SIS URE (e.g., station keeping maneuvers and atomic clock maintenance) are not commonly referred to as failures.  However, from a strict integrity perspective, most of them do result in MSI and could thus be correctly classified as a form of failure.  These types of "O&M-induced failures" are unique compared to all other failures in that they are planned in advance by the Control Segment.  Being planned, the Control Segment can prepare for them and can take preemptive actions to ensure that any MSI the O&M activity causes is AMSI (e.g., by performing an upload prior to the start of the O&M to set the SPS SIS unhealthy in the broadcast NAV data stream, or by SatZapping the satellite to make the SPS SIS unavailable to users).  Taking this preemptive action precludes UMSI and thus prevents any impact to SPS SIS integrity.  Although the preemptive action of taking the satellite off-line before the O&M activity is good for SPS SIS integrity, it is not necessarily good for SPS SIS continuity since it is an interruption in service that could potentially lead to a loss of continuity. 

Since these "O&M-induced interruptions in service" are normally planned well in advance, the Control Segment can also take further preemptive actions to prevent any impacts to SPS SIS continuity.  The typical required preemptive action is issuing a NANU regarding the planned interruption at least 48 hours in advance of the start of the SPS SIS scheduled outage period. From a strict continuity perspective, a NANU only needs to be issued for a scheduled interruption affecting a satellite occupying a slot that is not backed up by a second satellite in the orbital slot (or location in the case of an expanded slot configuration).  However, due to prior convention and operational reliance on the NANUs, all scheduled interruptions currently require a NANU to be 

5th Edition 

Page A-41

--- [page 120](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=120) ---

GPS SPS PS 

April 2020 

issued at least 48 hours in advance to avoid a loss of continuity.  The Control Segment normally issues NANUs at least 96 hours in advance of scheduled outages. 

The Control Segment can easily cause a loss of continuity of the SPS SIS by failing to issue the required NANU at least 48 hours in advance of the scheduled interruption in service.  Such a loss of continuity is considered to be reasonably probable. 

_Note:_ 

_1. Even though O&M-induced interruptions in service are normally short term, the duration of the loss of SPS SIS availability is not a determining factor for losing continuity.  So long as the outages last longer than the TTA of 8 seconds for integrity (which O&M-induced interruptions do), the outages will all pose the same risk of a loss of continuity.  Each loss of continuity counts as a single loss of continuity no matter if the loss lasts for one minute or it lasts for a thousand minutes.  Although the duration of the interruption does not affect the SPS SIS continuity, it very much does affect the SPS SIS availability._ 

###### **A.6.3  Losses of Continuity** 

For the SPS SIS from a satellite occupying a slot, continuity is lost any time there is an unscheduled loss of SPS SIS availability from that slot (unscheduled defined from the user perspective relative to the 48-hour advance warning threshold).  SPS SIS alert indications per paragraph 2.3.4 and SPS SIS "do not use" health indications per paragraph 2.3.2, which are defined as ways to maintain integrity, are also further defined as ways to lose continuity if they occur without at least 48 hours of advance warning. 

###### **A.6.4  Expected Frequencies for Losses of Continuity** 

The expected mean time between failure (MTBF), per-satellite, for the various types of failures defined in Section A.6.2 are as follows: 

- <u>LT Hard Failures.  The expected MTBF for LT hard failures is about twice the Block IIR</u> satellite design life of 7.5 years (roughly 15 years MTBF). 

- <u>ST Hard Failures.  The expected MTBF for ST hard failures is about one-fifteenth the</u> Block IIR satellite design life of 7.5 years (roughly 0.5 years MTBF). 

- <u>EOL (Hard) Failures.  The expected MTBF for EOL (hard) failures is about the same as</u> the Block IIR satellite design life of 7.5 years (roughly 7.5 years MTBF). 

- <u>Soft Failures.  The expected MTBF for soft failures is no greater than the MTBF for LT</u> hard failures (roughly 15 years MTBF or less). 

- <u>Satellite O&M Activities.  The expected "MTBF" for satellite O&M activities is no greater</u> than the MTBF for ST hard failures (roughly 0.5 years "MTBF" or less). 

Ideally, there should be no losses of continuity associated with either EOL (hard) failures or satellite O&M activities since the interruptions are schedulable and the Control Segment can be arbitrarily rigorous about issuing the required NANUs 48 hours in advance.  There is, however, 

5th Edition 

Page A-42

--- [page 121](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=121) ---

GPS SPS PS 

April 2020 

no standard which defines the level of rigor the Control Segment must maintain in issuing the NANUs other than the internal "at least 96 hours in advance" threshold with unspecified probability of success.  The worst case would obviously be no rigor whatsoever.  Even though unrealistic, this does put an upper bound on the expected frequency of the losses of continuity.  Comparing the 7.5 year MTBF for EOL (hard) failures against the 0.5 year "MTBF" for satellite O&M activities, it is obvious that the satellite O&M activities completely dominate the EOL (hard) failures.  The resulting mean time between loss of continuity (MTBLOC) is thus 0.5 years increased by whatever level of rigor the Control Segment can maintain. 

In contrast to the schedulable interruptions, there should be losses of continuity associated with all of the unschedulable interruptions due to LT hard failures, all ST hard failures, and most soft failures.  All LT hard failures and all ST hard failures should have an associated loss of continuity since there is no way the Control Segment can issue NANUs at least 48 hours in advance for these failures.  Most soft failures will also have an associated loss of continuity since they rapidly lead to an interruption in service and the Control Segment will not be able to issue a NANU at least 48 hours in advance.  Some soft failures will not lead to an interruption in service, however. Soft failures which the Control Segment resolves using contingency uploads do not involve an interruption in service.  Like with the schedulable interruptions, the MTBF for one of the failure modes (ST hard failures) completely dominates the MTBFs for the other two failure modes in determining the composite MTBLOC. 

###### **A.6.5  Expandable Slot Continuity** 

The expandable slots defined in Tables 3.2-1, 3.2-2 and 3.2-3 are considered to lose continuity when either: 

- (1) The expandable slot is in the baseline configuration, and the satellite occupying the orbital location defined in Table 3.2-1 for the slot loses continuity. 

- (2) The expandable slot is in the expanded configuration, and either one of the pair of satellites occupying the orbital locations defined in Table 3.2-2 for the slot loses continuity. 

5th Edition 

Page A-43

--- [page 122](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=122) ---

GPS SPS PS 

April 2020 

#### **SECTION A.7  Availability** 

###### **A.7.1  Relationship with Section 3.7** 

Section 3.7 contains the SPS SIS performance standards for availability.  This section provides background information relative to the SPS SIS availability performance standards.  The SPS SIS performance standards for availability only apply to the C/A-code signal and the LNAV data stream in this edition of the _SPS PS_ . 

The two components of SPS SIS availability (the per-slot availability and the constellation availability) are interrelated.  The per-slot availability depends primarily on the satellite design and the Control Segment procedures for on-orbit maintenance and failure response.  The constellation availability depends primarily on the per-slot availability coupled with the satellite launch policies and satellite disposal criteria. 

###### **A.7.2  Per-Slot Availability** 

###### **A.7.2.1  Satellite Outage Categories** 

The various types of failures and interruptions defined in Section A.6 for continuity reasons can be categorized as a function of the typical outage duration and whether the Control Segment has any ability to schedule them in advance.  The resulting four categories and the straightforward mapping of the outage reasons are: 

1. Long Term Unscheduled (LTU) Outages 

   - LT Hard Failures 

2. Short Term Unscheduled (STU) Outages 

   - ST Hard Failures 

   - Soft Failures 

3. Long Term Scheduled (LTS) Outages   EOL (Hard) Failures 

4. Short Term Scheduled (STS) Outages 

   - Satellite O&M Activities 

###### **A.7.2.2  Conservative Satellite/Slot Availability Model** 

The satellite/slot availability model for the baseline 24-slot constellation slots is both simple and conservative.  The assumed maximum life for the satellites addressed in this _SPS PS_ is 7.5 years, which corresponds to the design life of the Block IIR satellites.  Any satellite reaching this age is assumed to be at EOL and it is assumed it will be replaced.  The replacement timeline is assumed to be schedulable.  Each satellite is assumed to have an a priori probability of 0.6 for reaching EOL and a 0.4 probability of dying early due to an LT hard failure.  For those satellites that die early, the assumed mean age at the LT hard failure is approximately 3.75 years. 

5th Edition 

Page A-44

--- [page 123](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=123) ---

GPS SPS PS 

April 2020 

Before the satellite dies or is replaced, the conservative model assumes ST hard failures and soft failures happen at random.  The same is also true for satellite O&M activities. 

When it is time to replace a failed satellite, the conservative model assumes the replacement process does not start until after either the LT hard failure occurs or after the satellite is disposed of during EOL operations. 

Using the MTBF (MTBLOC) expectations given in Section A.6.4 in this appendix and average outage durations, the numerical satellite/slot availability model parameters are as summarized in Table A.7-1. 

###### **Table A.7-1.  Per-Satellite/Slot Availability Model Parameters for Baseline Slots** 

|**Model Parameter**|**Model Value**|
|---|---|
|Before theLT HardFailure or EOL Disposal:||
|Average Number of STU Outages|2.0 per year|
|Mean STU Outage Duration|36.0 hours|
|Average Number of STS Outages|2.0 per year|
|Mean STS Outage Duration|12.0 hours|
|FortheLT HardFailure or EOL Disposal:||
|Mean time to LT Hard Failure or EOL Disposal|6.0 years|
|Mean time to replace after LT Hard Failure or EOL Disposal|0.2years|



_Notes:_ 

_1. The conservative satellite/slot availability model and the parameters in Table A.7-1 represent the simple "launch on need" (LON) strategy for constellation sustainment._ 

_2. It can be assumed that the satellite/slot availability model and the parameters in Table A.7-1 will be conservative with respect to whatever Control Segment on-orbit maintenance and failure response procedures may be adopted by the USSF in the future.  The satellite/slot availability model and parameters in Table A.7-1 are very conservative compared to the current “launch to sustain” (LTS) strategy established in the GPS CONOPS.  (The LTS strategy is a combination of the LON and “launch on anticipated need” [LOAN] strategies.)_ 

_3. Table A.7-1 also applies to expandable slots in their baseline 24-slot constellation configuration._ 

###### **A.7.2.3  Satellite/Slot Availability Computation** 

Using the model parameters in Table A.7-1, the fraction of time that a baseline 24-slot constellation slot will be occupied by a satellite which is transmitting a trackable and healthy SPS SIS is no less than 0.957 (95.7%) on a long-term average basis.  The resulting fraction of time that the baseline slot will be occupied by a satellite which is transmitting an untrackable, marginal, or unhealthy SPS SIS (0.043) is the sum of the fraction of time that the satellite will be transmitting an untrackable, marginal, or unhealthy SPS SIS with an advance warning having been given via NANU (e.g., "scheduled downtime" due to on-orbit O&M or disposal activities) plus the fraction of time that a baseline satellite will be transmitting an untrackable, marginal, or unhealthy SPS SIS with no advance warning having been given (i.e., "unscheduled downtime" due to an on-orbit failure). 

5th Edition 

Page A-45

--- [page 124](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=124) ---

GPS SPS PS 

April 2020 

###### **A.7.2.4  Expandable Slot Availability** 

The expandable slots defined in Tables 3.2-1, 3.2-2 and 3.2-3 are considered to be available when either: 

- (1) The expandable slot is in the baseline configuration, and the orbital location defined in Table 3.2-1 for the slot is occupied by a satellite which is transmitting a trackable and healthy SPS SIS. 

- (2) The expandable slot is in the expanded configuration, and the pair of orbital locations defined in Table 3.2-2 for the slot are both occupied by a satellite which is transmitting a trackable and healthy SPS SIS. 

- (3) The expandable slot is in an equivalent-or-better non-standard configuration (see A.7.2.5), and the pair of non-standard orbital locations for the slot are both occupied by a satellite which is transmitting a trackable and healthy SPS SIS. 

There are no performance standards in this document related to how often an expandable slot can be or must be in its expanded configuration.  Each expandable slot may therefore be in its baseline configuration anywhere from 100% of the time to 0% of the time. 

###### **A.7.2.5  Equivalent-or-Better Non-Standard Expanded Slot Configurations** 

The expandable slots defined in Tables 3.2-1, 3.2-2 and 3.2-3 can be filled by satellites in a nonstandard configuration.  Any non-standard configuration which provides equivalent-or-better performance than the nominal (non-expanded) slot is defined to be an acceptable alternative for either the nominal slot or the expanded slot. 

The nominal and expanded configurations of an expandable slot can be graphically illustrated as shown in Figure A.7-1. 



<!-- Start of picture text -->
Nominal<br>Direction of<br>Satellite Motion<br>a.  Expandable Slot Occupied by a<br>Satellite in the Nominal Orbital Location<br>Aft  Fore  Direction of<br>Satellite Motion<br>b.  Expandable Slot Occupied by a Pair of Satellites in<br>the Expanded Orbital Locations<br><!-- End of picture text -->

###### **Figure A.7-1.  Illustration of Nominal and Expandable-24 Slot Configurations** 

5th Edition 

Page A-46

--- [page 125](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=125) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>a.  Condensed Slot - 1<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>b.  Condensed Slot - 2<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>c.  Condensed Slot - 3<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>d.  Expanding a Slot -1<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>e.  Expanding a Slot - 2<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>f.  Expanding a Slot - 3<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>g.  Expanding a Slot - 4<br><!-- End of picture text -->

**Figure A.7-2.  Illustration of Equivalent-or-Better Non-Standard Configurations (1 of 2)** 

5th Edition 

Page A-47

--- [page 126](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=126) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>h.  Contracting a Slot – 1<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>i.  Contracting a Slot – 2<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>j.  Contracted Slot – 3<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>k.  Reallocating from a Contracted Slot – 4<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>l.  Simultaneously Contracting and Reallocating – 1<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>m.  Simultaneously Contracting and Reallocating – 2<br>Nominal<br>Aft  Fore  Direction of<br>Orbital Motion<br>n.  Simultaneously Contracting and Reallocating – 3<br><!-- End of picture text -->

**Figure A.7-2.  Illustration of Equivalent-or-Better Non-Standard Configurations (2 of 2)** 

5th Edition 

Page A-48

--- [page 127](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=127) ---

GPS SPS PS 

April 2020 

Example non-standard configurations which provide equivalent-or-better performance than the nominal configuration are graphically illustrated in Figure A.7-2.  Mirror images of the illustrated examples also provide equivalent-or-better performance. 

The two contracting-and-reallocating sequences shown on Sheet 2 of Figure A.7-2 are likely options for when one of the satellites in an expandable-24 slot must be moved elsewhere in the orbital plane.  The contract-then-reallocate sequence (h-i-j-k) and the simultaneous-contract-andreallocate sequence (l-m-n) both maintain slot availability during the moves. 

###### **A.7.3  Constellation Availability** 

The fraction of time that varying numbers of slots in the baseline 24-slot constellation are occupied by satellites that are transmitting a trackable and healthy SPS SIS can be computed using a simple binomial probability model with the two probabilities of 0.957 and 0.043.  The results of that computation are given in Table A.7-2 compared to the standard model for selected numbers of occupied slots. 

**Table A.7-2.  Constellation Availability** 

|**Number of Baseline Constellation Slots**|**Binomial Model:**<br>**Fraction of Time**|**Standard Model:**<br>**Fraction of Time**|
|---|---|---|
|All 24 Slots|0.348|0.720|
|23 or More Slots|0.724|0.890|
|22 or More Slots|0.918|0.954|
|21 or More Slots|0.981|0.980|



_Notes:_ 

_1. The bottom line result of the simple binomial model and the standard model are both compatible with the specified SPS SIS availability performance standard given in Section 3.7._ 

_2. Additional terms in the binomial model are:_ 

|_20 or more slots_|_0.99685_|
|---|---|
|_19 or more slots_|_0.99957_|
|_18 or more slots_|_0.99995_|



_Operational constraints (see Section 3.7) preclude the number of occupied slots falling below 20._ 

_3. For additional information on the standard model, see “_ RAIM Detection and Isolation Integrity Availability With and Without CAG _”, by M. Ananda, J. Leung, P. Munjal, and B. Siegel, in Proceedings of ION GPS-94, the 7_<sup>_th_</sup> _International Technical Meeting of the Satellite Division of the Institute of Navigation, Salt Lake City, September 1994._ 

###### **A.7.4  Slot Occupancy** 

A satellite occupies a defined slot when the satellite’s footprint on the surface of the Earth overlaps 95% of the slot center’s footprint on the surface of the Earth averaged over an orbit revolution.  A conservative approximation for slot occupancy occurs when the following inequality is satisfied: 

5th Edition 

Page A-49

--- [page 128](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=128) ---

GPS SPS PS 

April 2020 

Let: 

ΔRAAN = RAANsatellite - RAANslot semi-circles ΔArgLat = ArgLatsatellite - ArgLatslot semi-circles 

The 95% requirement approximation is: 

¼ x (ΔRAAN)<sup>2</sup> + (ΔArgLat + 0.5736 x ΔRAAN)<sup>2</sup> ≤  (0.0333 semi-circles)<sup>2</sup> 

_Note:_ 

_1. The above inequality describes an ellipse whose center is at a nominal slot-center as defined in Table 3.2-1.  The semi-minor axis is along the nominal orbital plane (inclination 55˚).  The semimajor axis is along the great circle perpendicular to the nominal orbital plane (inclination 145˚).  The semi-major axis is 12° x sin(55˚) = 9.83˚ along the great circle.  The semi-minor axis is 6˚ in argument of latitude.  Figure A.7-3 illustrates the slot ellipse when the nominal slot center is at the equator:_ 



**Figure A.7-3.  Nominal Slot Ellipse** 

_Traditional CS management of the satellites in slots allowed for a ±4˚ tolerance in ArgLat (±2˚ GLAN).  The ArgLat limit has been a best practice for minimizing PDOP outages.  With the ellipticalslot definition it is possible for the satellite to drift beyond the ±4˚ ArgLat tolerance.  One possible way for the CS to maintain both the 95% footprint and the ArgLat tolerance is as follows:_ 

- _a) As RAAN drifts, adjust the target geographic longitude of ascending node (GLAN) by the formula, ΔGLAN = 0.713 x ΔRAAN.  This defines a moving target slot center as the RAAN drifts._ 

5th Edition 

Page A-50

--- [page 129](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=129) ---

GPS SPS PS 

April 2020 

_b) Limit the allowable ArgLat drift to the minimum of ±4˚ or the slot ellipse._ 

_Based on the above diagram, as the RAAN shifts, the target slot center moves along the semimajor axis of the slot ellipse.  The ArgLat could then drift to either ±4˚ (the orange lines) or the ellipse (blue curve), whichever is closer to the semi-major axis._ 

A pair of satellites occupy an expanded slot when the satellites’ combined footprint on the surface of the Earth overlaps 95% of the baseline slot center’s footprint on the surface of the Earth averaged over an orbit revolution.  The nominal RAAN for each position in an expanded slot is in the same orbit plane as the baseline slot to support constellation maintenance.  However, satellites in expanded slots can provide better coverage when the expanded slot RAANs are slightly adjusted outside of the baseline slot’s orbit plane. 

_Note:_ 

_1. One way for the CS to manage satellites occupying expanded slots is to manage the satellite in the forward position of an expanded slot separately from the satellite in the aft position of an expanded slot.  For satellites in the forward position of an expanded slot, that satellite may also be managed by ensuring the satellite’s footprint on the surface of the Earth overlaps 95% of the footprint of the nominal forward position’s center adjusted -5 degrees in RAAN, averaged over an orbit revolution:_ 

_¼ x (ΔRAAN + 5 degrees)_<sup>_2_</sup> _+ (ΔArgLat + 0.5736 x ΔRAAN)_<sup>_2_</sup> _≤  (0.03333 semi-circles)_ 

_For satellites in the aft position of an expanded slot, that satellite may also be managed by ensuring the satellite’s footprint on the surface of the Earth overlaps 95% of the footprint of the nominal aft position’s center adjusted +5 degrees in RAAN, averaged over an orbit revolution:_ 

_¼ x (ΔRAAN - 5 degrees)_<sup>_2_</sup> _+ (ΔArgLat + 0.5736 x ΔRAAN)_<sup>_2_</sup> _≤  (0.03333 semi-circles)_ 

5th Edition 

Page A-51

--- [page 130](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=130) ---

GPS SPS PS 

April 2020 

#### **SECTION A.8  Position/Time Domain** 

###### **A.8.1  Relationship with Section 3.8** 

Section 3.8 contains the SPS performance standards for the position/time domain.  This section provides background information relative to those SPS position/time domain performance standards. 

Unlike the other SPS performance standards in Section 3 of this document, the SPS position/time domain performance standards in Section 3.8 do not directly apply to the SPS SIS.  The SPS position/time domain performance standards are instead derived from the SPS SIS performance standards in Sections 3.2 through 3.7, and the SPS position/time domain performance standards apply only when interpreted through a specific set of user assumptions.  (Compare the wording difference between “SPS <u>position/time domain</u> performance standards” and “SPS <u>SIS</u> performance standards”.)  The specific user assumptions include the error exclusions identified in paragraph 2.4.5 as well as the SPS SF L1 C/A-code receiver assumptions in Section 3.8. 

These SPS position/time domain performance standards only apply to operations with the SF C/A-code signal and the LNAV data stream.  Future editions of this standard may add SPS position/time domain performance standards applicable to operations with other SF SPS signals, the CNAV data stream, and/or the DF/TF combinations of SPS signals. 

Although these SPS position/time domain performance standards can be derived from the other SPS performance standards in Sections 3.2 through 3.7 and are therefore somewhat “redundant”, they are included in Section 3.8 because of their simplicity in defining and documenting SPS SIS backward compatibility.  The SPS position/time domain performance standards in this 5<sup>th</sup> Edition of the _SPS PS_ are backward compatible with the SPS position/time domain performance standards in 4<sup>th</sup> Edition of the _SPS PS_ .  Similarly, the SPS position/time domain performance standards in the 4<sup>th</sup> Edition of the _SPS PS_ are backward compatible with the SPS position/time domain performance standards in 3<sup>rd</sup> Edition of the _SPS PS_ ; and so on and so forth. 

###### **A.8.2  Availability of Geometry (and PVT Determination)** 

The SPS performance standards for the position/time domain in Section 3.8 are dependent on the availability of ‘good geometry’ of the in-view satellites relative to the assumed user.  Without ‘good geometry’, it can sometimes be impossible for users to even determine a PVT solution.  The relative goodness of the satellites-to-user geometry is quantified by a set of metrics collectively known as the “dilutions of precision” (DOPs).  There are four DOP metrics applicable to Section 3.8.  They are: 

1. Position Dilution of Precision (PDOP) – spatial, three dimensions (3-D) 

2. Horizontal Dilution of Precision (HDOP) – spatial, two dimensions (2-D) 

3. Vertical Dilution of Precision (VDOP) – spatial, one dimension (1-D) 

4. Time Dilution of Precision (TDOP) – temporal, one dimension (1-D) 

5th Edition 

Page A-52

--- [page 131](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=131) ---

GPS SPS PS 

April 2020 

Due to their complexity and dependence on specific user assumptions, explanatory material on the DOP metrics has been placed into a separate appendix (Appendix B).  Using that DOP explanation material as a prerequisite, background information on SPS position/time domain performance standards subsequently follows in Appendix B.  Much of the focus in Appendix B is on how good the relative satellites-to-user geometry has to be in order to qualify as ‘good geometry’ for accurate PVT determination purposes. 

###### **A.8.3  Availability of Geometry Impacts Due to Expandable-24 Slots** 

It can be shown that all 7 variations of the expandable-24 constellation defined by Tables 3.2-1, 3.2-2, and 3.2-3 provide global availability of PDOP/HDOP/VDOP/TDOP that is at least as good as the fully-occupied baseline 24-slot constellation when all orbital locations in the expandable 24-slot constellation variation (baseline slots and expanded slots) are occupied by satellites broadcasting a trackable and healthy SPS SIS.  Expandable slots occupied by a pair of satellites enhance the overall SPS SIS performance; but no credit can be taken for them relative to the baseline 24-slot constellation performance standards.  The _SPS PS_ provides no standards for the probabilities of any of the expandable slots being in their expanded configurations and occupied by pairs of satellites broadcasting trackable and healthy SPS SISs. 

###### **A.8.4  Availability of Geometry Impacts Due to Auxiliary Satellites** 

The presence or absence of auxiliary satellites (i.e., operational satellites which are not occupying a defined orbital slot in the baseline/expandable 24-slot constellation) does not affect the availability of good PDOP/HDOP/VDOP/TDOP from the baseline/expandable 24-slot constellation.  If present and broadcasting trackable and healthy SPS SISs, auxiliary satellites can be shown to enhance the provided availability of good PDOP/HDOP/VDOP/TDOP; but no credit is taken for them relative to the baseline 24-slot constellation performance standards. Similarly, the absence of auxiliary satellites has no adverse impact on the availability of good PDOP/HDOP/VDOP/TDOP relative to the baseline 24-slot constellation performance standards. There are no standards given for the probabilities of any number of auxiliary satellites being present. 

###### **A.8.5  Position/Time Domain Time Derivatives** 

The position/time domain includes the time derivates of the position and time quantities.  For example, velocity is in the position/time domain because velocity is the time derivative of position. 

5th Edition 

Page A-53

--- [page 132](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=132) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition 

Page A-54

--- [page 133](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=133) ---

GPS SPS PS 

April 2020 

# _GLOBAL POSITIONING SYSTEM STANDARD POSITIONING SERVICE PERFORMANCE STANDARD_ 

## _APPENDIX B_ 

## _STANDARD POSITIONING SERVICE POSITION, VELOCITY, AND TIME (PVT) PERFORMANCE EXPECTATIONS_ 





## _April 2020_ 

**_Integrity - Service - Excellence_** 

5th Edition

--- [page 134](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=134) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition

--- [page 135](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=135) ---

GPS SPS PS 

April 2020 

### **TABLE OF CONTENTS** 

|**SECTION B.1  Introduction**.......................................................................................**B-1**|
|---|
|B.1.1  Historical Perspective ..............................................................................................................   B-1|
|B.1.2  Global Utility Metaphor ............................................................................................................   B-3|
|B.1.3  Direct Use of the Information in Section 3 ...............................................................................   B-3|
|B.1.4  Indirect Use of the Information in Section 3 (PVT Performance) ............................................   B-4|
|**SECTION B.2  Computing PVT Accuracy**................................................................**B-5**|
|B.2.1  Basic Equations for PVT Accuracy ..........................................................................................   B-5|
|B.2.2  Basic Equation for Time Transfer Accuracy ............................................................................   B-6|
|B.2.3  UERE Values ...........................................................................................................................   B-6|
|B.2.3.1  Specified UERE Values ..................................................................................................   B-6|
|B.2.3.2  Derived UERE Values .....................................................................................................   B-6<br>|
|B.2.3.3  Hypothetical UERE Values .............................................................................................   B-8<br>|
|B.2.3.4  Specified URE Values .....................................................................................................   B-8|
|B.2.3.5  Higher-Fidelity UERE Values ..........................................................................................   B-8|
|B.2.3.6  Dissimilar UERE Values ..................................................................................................   B-8|
|B.2.4  DOP Values .............................................................................................................................   B-9|
|B.2.4.1  DOP Values at a Time-Space (T-S) Point ......................................................................   B-9<br>|
|B.2.4.2  Computing DOP Values ..................................................................................................   B-9|
|B.2.4.3  Receiver Algorithms for Selecting SISs/Measurements to be Used ............................... B-10|
|B.2.5  Combining UERE/UERRE and DOP Values ........................................................................... B-11|
|**SECTION B.3  Availability of Geometry and PVT Accuracy**................................**B-12**|
|B.3.1  PDOP6.0 Threshold for ‘Availability of Adequate Accuracy’ ................................................. B-12|
|B.3.2  Horizontal/Vertical Thresholds for ‘Availability of Accuracy’ ................................................... B-13|
|B.3.2.1  Sources of the SAT Values ............................................................................................. B-13|
|B.3.2.2  HDOP Distributions & VDOP Distributions ..................................................................... B-13|
|B.3.2.3  "Global Average" HDOP Distributions & VDOP Distributions ......................................... B-16|
|B.3.2.4  "Worst-Case" HDOP T-S Point & VDOP T-S Point ........................................................ B-16|
|B.3.2.5  Intermediate Population HDOP Distributions & VDOP Distributions .............................. B-17|
|B.3.2.6_3_<sup>_rd_</sup> _Edition of the_ _SPS PS_"Global Average" and "Worst-Case Location"<br>DOP Distributions ......................................................................................................... B-17|
|B.3.2.7  Picking HDOP-AT & VDOP-AT Values for Computing SAT Values ............................... B-17|
|B.3.2.8  5<sup>th</sup> Edition SPS PS SATs and Position Service Availability Standards ........................... B-18|
|B.3.3  "Classic" Position Accuracy Statistics ..................................................................................... B-18|
|B.3.3.1  Reasons for Needing the DOP Distributions ................................................................... B-19|
|<br>B.3.3.2  Basic Procedure for Computing Classic Position Accuracy Statistics ............................ B-22|
|<br>B.3.3.3  Expanded Procedure for Computing Classic Position Accuracy Statistics ..................... B-23|
|B.3.3.4  Expanded Classic Position Accuracy Statistics .............................................................. B-24|
|B.3.4  "Current" Position Accuracy Statistics for Receiver Specification ........................................... B-25|
|B.3.4.1  Background ..................................................................................................................... B-25|
|B.3.4.2 “Current” Position Accuracy Statistics for Receivers ....................................................... B-25|



5th Edition 

Page B-i

--- [page 136](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=136) ---

GPS SPS PS 

April 2020 

|B.3.5  Position/Time Accuracy Standards in this Edition of the_SPS PS_........................................... B-23|
|---|
|**SECTION B.4  Customized PVT Performance Expectations**...............................**B-27**|
|B.4.1  Three Timeframes ................................................................................................................... B-27|
|B.4.2  Real-Time PVT Performance Expectations Directly from Your Receiver ............................... B-28|
|B.4.2.1  Real-Time Accuracy Estimates Directly from Your Receiver .......................................... B-28|
|B.4.2.2  Real-Time Integrity Estimates Directly from Your Receiver ............................................ B-30|
|B.4.3  In-Advance PVT Performance Expectations ........................................................................... B-34<br>|
|B.4.3.1  General Rule -- Don't Worry About It .............................................................................. B-34|
|B.4.3.2  In-Advance PVT Performance Expectations Directly from Your Receiver…. ................. B-38|
|B.4.3.3  In-Advance PVT Performance Expectations from a Computer Model…. ....................... B-39|
|B.4.4  After-the-Fact PVT Performance Expectations ....................................................................... B-40|



5th Edition 

Page B-ii

--- [page 137](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=137) ---

GPS SPS PS 

April 2020 

### **List of Figures** 

|Figure B.1-1.|New GPS Organizational Perspective .............................................................................   B-1|
|---|---|
|Figure B.3-1.|HDOP Distribution Curves ............................................................................................... B-14|
|Figure B.3-2.|VDOP Distribution Curves ................................................................................................ B-14|
|Figure B.3-3.|Vertical L95 for UERE=4.0 m 1-sigma and VDOP=1.80 ................................................. B-19|
|Figure B.3-4.|Vertical L95 for VDOP=1.40 Sub-Population and VDOP=2.20 Sub-Population .............. B-20|
|Figure B.4-1.|Three Time Frames .......................................................................................................... B-27|
|Figure B.4-2.|HPL, HUL, HAL Relationships ......................................................................................... B-33|
|Figure B.4-3.|Obscuration Angles versus SPS Receiver Antenna Height ............................................. B-37|
|Figure B.4-4.|Obscuration Angles versus SPS Receiver Antenna Location ......................................... B-37|



### **List of Tables** 

|Table B.2-1.|Typical UEE Error Budgets (95%) .....................................................................................   B-7|
|---|---|
|Table B.3-1.|Global Ensemble DOPs for Weighted Mix of Constellation States ................................... B-25|
|Table B.4-1.|EPE-to-FOM Correspondence .......................................................................................... B-30|
|Table B.4-2.|RAIM Availability Examples  .............................................................................................. B-34|



5th Edition 

Page B-iii

--- [page 138](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=138) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition 

Page B-iv

--- [page 139](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=139) ---

GPS SPS PS 

April 2020 

#### **SECTION B.1  Introduction** 

###### **B.1.1  Historical Perspective** 

GPS has often been described as having three main segments: 

1. Control Segment, 

2. Space Segment, 3. User Segment. 

This is still true from the system architectural perspective.  It really is no longer true from the program organizational perspective.  The new organizational perspective is shown in Figure B.11. 



<!-- Start of picture text -->
SPACE SEGMENT<br>GPS SIS<br>INTERFACE<br>K2DBK2DB  K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB K2DBK2DB<br>CONTROL SEGMENT  USER SEGMENT<br><!-- End of picture text -->

**Figure B.1-1.  New GPS Organizational Perspective** 

The USG owns the GPS Control Segment and the GPS Space Segment.  The USSF operates and maintains both of these GPS segments.  The Space and Control Segments are part of the GPS program organization.  The USG cannot be said to own, operate, or maintain the User Segment portion of GPS.  The User Segment encompasses millions of GPS receivers.  While the USG does develop and procure military PPS receivers for U.S. and allied users, these make up a very small fraction of the world’s total GPS receiver population. 

5th Edition 

Page B-1

--- [page 140](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=140) ---

GPS SPS PS 

April 2020 

Long ago, the GPS Joint Program Office (JPO), which has been reorganized within SMC, began developing all three segments of GPS.  Although the United States Air Force (USAF) was the executive service responsible for the JPO, the GPS JPO was truly a "joint" program office in that it included members from all branches of the U.S. military and later grew to include personnel from allied nations (with particularly strong participation from the North Atlantic Treaty Organization [NATO] countries) and from other Departments of the USG.  The GPS JPO not only developed the initial Control, Space, and User Segments of GPS; the GPS JPO also operated and maintained them as well.  Around the end of the 1970s, the GPS JPO either owned or directly controlled virtually every GPS receiver in the entire world.  Back then it made sense to specify GPS requirements in terms of the PVT performance seen by the end user since all three segments were under GPS JPO control.  The GPS receiver's displayed PVT was the final interface at the end of the GPS process. 

During the 1980s, the GPS JPO developed and deployed the Operational Control System (OCS) which it initially ran before turning it over to Air Force Space Command (AFSPC), now the USSF. The GPS JPO developed and began deploying the operational Block II series of satellites which were then handed over to AFSPC for on-orbit operations and maintenance.  The GPS JPO also developed and procured many different types of PPS receivers which were delivered to the Army, Navy, and Air Force, as well as other federal agencies and allied governments.  Not all PPS receivers were developed or produced by the GPS JPO, however.  Programs with specialized applications that required unique capabilities began developing and producing their own PPS receivers.  Some NATO governments also initiated their own PPS receiver development efforts. A few civil electronics manufacturers even started producing and selling commercial SPS receivers.  Since the bulk of the world's GPS receivers were still configuration managed by the GPS JPO, specifying GPS requirements in terms of the PVT performance delivered to the end user still made sense.  But as evidenced by the PPS user equivalent range error (UERE) budgets which appeared at the end of the 1980s, it had become necessary to specify the PPS SIS performance to accommodate those PPS receivers not developed by the GPS JPO. 

By the late 1990s, most PPS receivers were being bought by military system integrators directly from the manufacturer for use as a sensor embedded in other products.  The GPS JPO was still developing and procuring a few types of stand-alone PPS receivers for domestic use and foreign military sales, but those were only a very small fraction of the world's production of PPS receivers. More and more, PPS receivers have become just another component in integrated systems.  End users often do not see PPS-based PVT, they instead see navigation signals based on integrated PPS-inertial, PPS-Doppler, or PPS-terrain matching.  The PPS receivers embedded in these systems are purchased, operated, and maintained by organizations other than SMC.  Neither SMC nor the Joint Service System Management Office (JSSMO) nor USSF’s 50<sup>th</sup> Space Wing (50 SW), who are SMC’s partners for maintaining SMC-procured PPS receivers and for operating and maintaining the Control/Space Segments respectively), are responsible for the performance of these PPS receivers.  SMC, JSSMO, and 50 SW responsibilities end at the PPS SIS interface as shown in Figure B.1-1.  The same principle applies to the huge number of SPS receivers produced in the 1990s -- those SPS receivers are not purchased, operated, or maintained by the GPS program organization; and the GPS program organization's responsibility towards those SPS receivers ends at the SPS SIS interface. 

The GPS program organizational line of demarcation is at the SPS SIS interface (and PPS SIS interface) as shown in Figure B.1-1.  Operating and maintaining the Control/Space Segments to produce the SPS SIS is the responsibility of the GPS program organization.  The SPS User Segment is not the responsibility of the GPS program organization. 

5th Edition 

Page B-2

--- [page 141](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=141) ---

GPS SPS PS 

April 2020 

###### **B.1.2  Global Utility Metaphor** 

GPS has been metaphorically described as a "global utility".  This metaphor is seen in Figure B.11 with the "electrical socket in the sky" representing the SPS SIS interface and the SPS receivers shown "plugging in" to that interface.  The SPS SIS ISs/ICDs (particularly IS-GPS-200 and ISGPS-705) are where the technical details like "AC, 60 Hz, 120 volts" are defined.  Section 3 of this standard is where the GPS utility's performance parameters are specified like: 

- a.   The number of amperes each wall socket can deliver (accuracy) 

- b.   The maximum probability of dangerous voltage spikes (integrity) 

- c.   The mean time between unexpected blackouts (continuity) 

- d.   The fraction of time unaffected by blackouts (availability) 

- e.   The area served by the power company (coverage) 

The metaphor is particularly appropriate when the GPS program organizations are described as being "service providers".  The metaphor does break down, however, when one tries to apply it to cost; whereas utilities charge consumers for the services rendered, Federal law requires that the Secretary of Defense provide for the sustainment and operation of the GPS SPS for peaceful civil, commercial, and scientific uses on a continuous worldwide basis free of direct user fees (10 USC 2281(b)). 

###### **B.1.3  Direct Use of the Information in Section 3** 

The standards given in Section 3, along with the referenced ISs/ICDs, comprise a full and complete description of the SPS SIS interface provided to the User Segment's SPS receivers. Those standards and the ISs/ICDs provide the signal information needed by a manufacturer to design a SPS receiver that will successfully interface with the SPS SIS.  Some of the information in Section 3 is needed by developers of augmentations systems (e.g., DGPS) to design the parameters in the augmentation signal.  The information in Section 3 is also directly applicable to designing a system to integrate GPS with an inertial sensor; see Appendix R of RTCA/DO-229 for example. 

The information in Section 3 is essential to determining whether the SPS SIS can satisfy maritime user needs for a worldwide radionavigation system as expressed by the International Maritime Organization (IMO) in Assembly Resolution A.953(23).  The information is also essential for establishing baseline GPS performance as an International Civil Aviation Organization (ICAO) standardized Global Navigation Satellite System (GNSS) for both direct and augmented aerial navigation for all phases of flight up to and including precision approach – see _Annex 10 to the Convention on International Civil Aviation, International Standards and Recommended Practices_ (SARPs).  For official U.S. Government purposes, Section 3 is the publication cited by the _Federal Radionavigation Plan_ that defines the specific capabilities provided by the SPS.  Section 3 is the only place where the detailed SPS SIS integrity information needed for SPS RAIM fault detection (FD) algorithms is specified.  The information in Section 3 was specifically required to address integrity as well as the other Required Navigation Performance (RNP) parameters -- accuracy, continuity, and availability -- to support a worldwide performance based navigation (PBN) capability. 

5th Edition 

Page B-3

--- [page 142](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=142) ---

GPS SPS PS 

April 2020 

###### **B.1.4  Indirect Use of the Information in Section 3 (PVT Performance)** 

The standards in Section 3 describe the SPS SIS interface without constraining how the SPS SIS is used.  The SPS SIS standards are independent of the application of the SPS SIS information. Although this independence is technically correct, there is a long-standing tradition in GPS system specifications of addressing the implications of the SIS specifications to end users in the form of PVT accuracies. 

Section 3.8 in the main body of this standard continued this tradition by assuming hypothetical "benchmark" User Equipment (UE) and used it to translate the SPS SIS specifications into user PVT performance terms.  This appendix of the _SPS PS_ perpetuates the tradition by showing how Section 3.8 used the preceding SPS SIS specifications and benchmark UE assumptions to derive representative user PVT performance values given in Section 3. 

5th Edition 

Page B-4

--- [page 143](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=143) ---

GPS SPS PS 

April 2020 

#### **SECTION B.2  Computing PVT Accuracy** 

This section introduces the notion of using a computer model to translate GPS SIS performance standards into user PVT performance expectations.  It also describes some computer models that have been found to be acceptable for translating the SPS SIS performance standards into SPS PVT performance expectations. 

###### **B.2.1  Basic Equations for PVT Accuracy** 

The basic equation for PVT accuracy in GPS is: 



Equation B-1 is a simple approximation that has been found adequate for many applications.  It is appropriate when all pseudorange errors are zero mean, normally distributed, characterized by the same UERE such that a single dilution of precision (DOP) number can be used.  It is the same equation used by Section 3.8 to derive representative end user PVT performance values from the SPS SIS specifications and benchmark UE assumptions.  See TOR S3-G-89-01 for additional information regarding the use of this equation.  See Section B.2.3 for more information on UERE and Section B.2.4 for more information on DOP. 

There are different variations of equation B-1 used for different accuracy values (e.g., horizontal position accuracy, vertical velocity accuracy).  The variations of equation B-1 of relevance to this appendix are: 

UHNE  = UERE x HDOP (B-2) UVNE  = UERE x VDOP (B-3) 

UHVE  = UERRE x HDOP (B-4) UVVE  = UERRE x VDOP (B-5) 



where: 

UHNE = User Horizontal Navigation Error (RMS) UVNE = User Vertical Navigation Error (RMS) UHVE = User Horizontal Velocity Error (RMS) UVVE = User Vertical Velocity Error (RMS) UTE = User Time Error (RMS) c = speed of light, m/sec 

_Note:_ 

_1. The UHNE and UVNE are called "navigation" errors instead of "position" errors for historical reasons._ 

5th Edition 

Page B-5

--- [page 144](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=144) ---

GPS SPS PS 

April 2020 

###### **B.2.2  Basic Equation for Time Transfer Accuracy** 

The basic equation for time transfer accuracy relative to UTC(USNO) in GPS is: 



where: 

UUTCE =  User UTC(USNO) Error (RMS) TTDOP =  Time Transfer Dilution of Precision UTCOE =  UTC(USNO) Offset Error (RMS) 

_Note:_ 

_1. The form of equation B-7 is the root-sum-square (RSS) of two root-mean-square (RMS) values. The result is still an RMS value._ 

###### **B.2.3  UERE Values** 

###### **B.2.3.1  Specified UERE Values** 

When computing expected PVT accuracy for specification-compliance purposes, the UERE values to use in equations B-2, B-3, B-6, and B-7, and the UERRE values to use in equations B- 4 and B-5, are the ones given in the appropriate GPS signal specification, system/segment specification, or equivalent document for the particular circumstances being considered. Appendix A of this _SPS PS_ gives 3 different DF UERE values in Table A.4-1 and 3 different SF UERE values in Table A.4-2 for 3 different age of data (AOD) circumstances. (Remember that the UERE values in Tables A.4-1 and  A.4-2 are only illustrations; the only standards given in Section 3 of this document are for the SPS SIS.) 

_Notes:_ 

_1. Reserved._ 

_2. Equations B-1 through B-7 are all formulated using RMS statistics.  Care must be taken to ensure that the UERE values (or URE values) and UTC(USNO) offset accuracy values used in these equations are RMS statistics.  UERE values, URE values, and UTC(USNO) offset accuracy values expressed as 1-sigma statistics are equivalent to RMS statistics and can be used directly in Equations B-1 through B-7.  UERE values, URE values, and UTC(USNO) offset accuracy values expressed as 95% statistics can be converted to RMS statistics for use in Equations B-1 through B-7 by dividing them by a factor of 1.96 assuming that the errors are zero mean and normally distributed._ 

###### **B.2.3.2  Derived UERE Values** 

To compute expected PVT accuracy for long-term planning purposes for a particular type of GPS receiver, the UERE values to use in equations B-2, B-3, B-6, and B-7 can be derived as the RSS of the appropriate GPS SIS URE and the UEE for that particular GPS receiver under 

5th Edition 

Page B-6

--- [page 145](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=145) ---

GPS SPS PS 

April 2020 

consideration.  Recognize that not all SPS receivers are required to satisfy the same UEE specification.  Dating as far back as the late 1980s, the "traditional" UEE specification for a medium quality SPS receiver is 5.5 m 95% (2.8 m 1-sigma).  The commonly assumed "benign conditions" UEE specification for a high quality SPS receiver is 1.6 m 95% (0.8 m 1-sigma).  These two different UEE values result in two different derived UERE values.  For example, consider the 9.7 m 95% value for the SPS SIS URE specified in Table 3.4-1 at any AOD during normal operations neglecting single-frequency (SF) ionospheric delay model errors (or equivalently, the 9.7 m 95% value obtained by root-sum-squaring (RSS-ing) the Space Segment and Control Segment contributions to the SPS URE budget in Table A.4-1 in Appendix A of this _SPS PS_ ). This is a "base" URE value to which the appropriate SPS receiver UEE value is root-sum-squared (RSS-ed).  If the UEE specification for the SPS receiver being considered is the traditional 5.5 m 95% value obtained by RSS-ing each of the User Segment contributions to the SPS UERE budget in Table A.4-2 in Appendix A of this _SPS PS_ , then the derived UERE value to use in equations B- 2, B-3, B-6, and B-7 would be computed as follows: 



Taking this number and RSS-ing a conservative assumption for the SF ionospheric delay model error contribution of between 9.8 m and 19.6 m 95% results in exactly the numbers shown in Table A.4-2. 

For reference, the error budgets comprising some typical UEE values applicable to airborne C/Acode GPS receivers in normal operations are given in Table B.2-1.  The SF ionospheric delay compensation model performance does not appear in the SF receiver UEE budgets because its accuracy is not under the control of the SF receiver.  In contrast, the DF ionospheric delay compensation process performance does appear in the DF receiver UEE budget because its accuracy is under the control of the DF receiver.  For the traditional specification for DF ionospheric delay compensation accuracy, see Table A.4-1. 

**Table B.2-1.  Typical UEE Error Budgets (95%)** 

|Error Source|Traditional<br>Specification,<br>SF|Improved<br>Specification,<br>SF|Modern<br>Receiver,<br>SF|Advanced<br>Receiver,<br>DF|
|---|---|---|---|---|
|Ionospheric Delay Compensation|N/A|N/A|N/A|0.8|
|Tropospheric Delay Compensation|3.9|4.0|3.9|1.0|
|Receiver Noise and Resolution|2.9|2.0|2.0|0.4|
|Multipath|2.4|0.5|0.2|0.2|
|OtherUserSegmentErrors|1.0|1.0|1.0|0.8|
|UEE(m), 95%|5.5|4.6|4.5|1.6|



5th Edition 

Page B-7

--- [page 146](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=146) ---

GPS SPS PS 

April 2020 

###### **B.2.3.3  Hypothetical UERE Values** 

In addition to specified and derived UERE values, it is also possible to compute hypothetical UERE values and UERRE values to use in equations B-2 through B-7.  Hypothetical UERE values are often used in analytical "what if" studies.  A common hypothetical UERE value used in many studies is the UERE for a "perfect GPS receiver" with zero UEE.  This UERE is obtained by setting the UEE to zero in equation B-8.  This is the same as using the SIS URE in lieu of the UERE. The PVT accuracy using this "perfect GPS receiver" UERE is known as the "SIS-only PVT accuracy".  Another hypothetical UERE value neglects the SF ionospheric delay compensation model errors (e.g., the example in the previous paragraph). 

###### **B.2.3.4  Specified URE Values** 

An important example of using the SIS-only URE in lieu of the UERE for computing expected PVT accuracy was in the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ , published in 2001.  The _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ restricted itself to just the SIS, specifically excluding the UERE contribution of ionospheric delay compensation errors, tropospheric delay compensation errors, receiver tracking channel noise and resolution errors, multipath errors, and other user segment errors.  All of the expected positioning and timing accuracy standards given in the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ were SIS-only PVT accuracy values based on a 6 m RMS URE over all AODs during normal operations, a perfect GPS receiver, and neglecting the SF ionospheric delay compensation model errors. 

###### **B.2.3.5  Higher-Fidelity UERE Values** 

Higher-fidelity UERE values can be computed by observing the URA numbers contained within the transmitted GPS SIS, averaging them over time, and using the results to compute higherfidelity "transmitted on-orbit average" URE values to use in equation B-8.  Even higher-fidelity URE values can be computed based on historical trends revealed by instantaneous URE measurements produced by independent monitors such as differential GPS systems.  Such higher-fidelity URE values commonly reveal long-term variations between the satellites with the SIS from some satellites consistently being more accurate than others.  Caution must be exercised in making use of any higher-fidelity UERE values computed these ways:  (1) equations B-2, B-3, B-6, and B-7 are only valid if the same UERE value applies to each and every SIS, and (2) previous URE performance does not provide any guarantee of future URE performance. 

###### **B.2.3.6  Dissimilar UERE Values** 

Equations B-2, B-3, B-6, and B-7 are only valid when all pseudoranges are characterized by the same UERE value.  If the UERE values are different, then different equations must be used for computing the expected PVT accuracy. 

When the UERE values are different and there are pseudoranges available from more than four visible satellites, most GPS receivers will compute a "weighted position solution".  In a weighted position solution, more or less trust (weight) will be placed on each pseudorange according to the expected UERE value for that pseudorange.  More weight will be placed on pseudoranges with smaller expected UEREs, while less weight will be placed on pseudoranges with larger expected UEREs. 

There are still DOP values which apply to weighted position solutions, but these DOP values depend on the specific set of weighting factors used to compute the weighted position solution as well as the satellites-to-user geometry.  To distinguish them from the simple DOP values of an 

5th Edition 

Page B-8

--- [page 147](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=147) ---

GPS SPS PS 

April 2020 

unweighted position solution, these DOP values are known as "weighted DOPs".  Weighted DOPs are not discussed in this appendix due to their complexity. 

###### **B.2.4  DOP Values** 

###### **B.2.4.1  DOP Values at a Time-Space (T-S) Point** 

Each particular satellites-to-user geometry has its own set of DOP values.  Using the baseline 24slot constellation defined in Tables 3.2-1 and 3.2-3, the nominal satellites-to-user geometry can be computed for any time at any point in the GPS coverage volume.  Knowing the satellites-touser geometry at a specific time-space (T-S) point, and knowing which subset of the visible satellite's SISs will be used in the PVT solution or time transfer solution at that specific T-S point, allows the particular subset of DOP values to be computed for that specific T-S point. 

###### **B.2.4.2  Computing DOP Values** 

Although it is possible to compute the DOP values by hand for a specific T-S point, this is a very tedious and time-consuming task.  Computer models are therefore universally used for computing the DOP values.  Every GPS receiver that provides an output of the current DOP values has such a computer model inside.  RAIM availability prediction programs which are used in aviation applications also use such a computer model.  Stand-alone software for computing DOP values are available from many sources; these programs all embody a computer model. 

Typical computer models for computing the DOP values use the following inputs at a minimum: 

- a.   An almanac data file, with data similar to that shown in Table A.2-1 in Appendix A which defines the satellite constellation to be used in the computation.  The almanac data file customarily includes all parameters transmitted by the on-orbit satellites as part of their broadcast almanac data set in the NAV messages, including the health bits.  Some almanac data files also include average URA values based on recent observations. 

- b.   Operator-commanded overrides of the health settings built into the almanac data. 

- c.   The operator-specified T-S point (or set of T-S points) for which the DOP values are to be computed. 

- d.   Parameters which describe the exact type of GPS receiver to be emulated, especially the GPS receiver algorithm for selecting the subset of visible satellite SISs to be used in the PVT solution or time transfer solution (described in the following section). 

The output of the typical computer models, at a minimum, are the computed DOP values. 

_Note:_ 

_1. Several stand-alone software programs for computing DOP values and expected PVT accuracy can be downloaded from the web.  Many of these software programs use copies of the broadcast almanac data in GPS System Effectiveness Model (SEM) format.  A different software program for computing predicted RAIM availability can be accessed at no cost from the web at http://augur.ecacnav.com.  This software program is known as AUGUR.  The FAA maintains the following website with related software https://sapt.faa.gov/default.php.  There are many other software programs available for computing DOP values and related information._ 

5th Edition 

Page B-9

--- [page 148](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=148) ---

GPS SPS PS 

April 2020 

###### **B.2.4.3  Receiver Algorithms for Selecting SISs/Measurements to be Used** 

###### B.2.4.3.1  Satellite (SIS) Selection Algorithm 

Most typical computer models allow the operator to control the "satellite selection" algorithm the emulated GPS receiver will use to select the SISs used in the PVT solution or time transfer solution.  Many modern SPS receivers which can track and use up to a maximum of twelve SPS SISs will select the SISs from highest twelve satellites in the sky.  Advanced SPS receivers typically have sufficient capability to track and use all SPS SISs in view. 

###### B.2.4.3.2  Other Sensor Measurements 

Some computer models allow the operator to control whether the emulated GPS receiver will mimic the ability of a real GPS receiver to use information input by an aiding sensor.  For aviation use, most GPS receivers can take advantage of vertical position supplied by a barometric altimeter.  Computer models, which predict RAIM availability, emulate this capability by treating the barometric altimeter measurements as a form of pseudoranges.  For maritime use, most GPS receivers can take advantage of the fact that their vertical position is at mean sea level; some computer models also emulate this capability.  Some GPS receivers can accept acceleration information from an inertial measurement unit (IMU).  The use of inputs from aiding sensors, and the related computer modeling, is beyond the scope of this appendix.  See TSO-C196 and Appendix G of RTCA/DO-316 for further information on modeling the use of barometric altimeter inputs for aviation. 

###### B.2.4.3.3  Mask Angle 

Most typical computer models allow the operator to control the minimum mask angle above the local horizon which the emulated GPS receiver will use for determining whether a satellite is visible (and therefore available).  Some SPS receivers have a mask angle of 7.5 degrees, while others have a mask angle of 5 degrees (see AC 20-138).  Modern aviation receivers often use a mask angle of 2 degrees.  Time transfer receivers and some surveying receivers commonly use a mask angle of 15 degrees.  Some "all-in-view" GPS receivers do not have a mask angle per se; their only limitation on satellite availability is the radio horizon.  GPS receivers designed for space applications usually have negative mask angles. 

###### B.2.4.3.4  Maximum Number of SISs to be Used 

Many computer models allow the operator to control the maximum number of SISs the emulated GPS receiver will use in the PVT solution or time transfer solution.  Many modern SPS receivers can track and use up to a maximum of twelve SPS SISs at a time.  If there are, say, exactly five SPS SISs available at a given T-S point, the difference between the 4-SIS ("4-satellite") DOP value and the 5-SIS ("5-satellite") DOP value is usually, but not always, substantial.  Using five or more SISs for the PVT solution or time transfer solution always results in DOP values that are at least as good as the 4-SIS DOP values.  Advanced DF SPS receivers typically have sufficient capability to track and use all SPS SISs in view. 

_Note:_ 

_1. Although not always technically true, a GPS receiver that can track and use 12 SISs at a time is commonly referred to as being an "all-in-view" (AIV) GPS receiver._ 

5th Edition 

Page B-10

--- [page 149](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=149) ---

GPS SPS PS 

April 2020 

###### **B.2.5  Combining UERE/UERRE and DOP Values** 

With a uniform UERE value and UERRE value, the DOPs produced by a suitably configured computer model can be simply scaled by those UERE and UERRE values according to equations B-2 through B-6 to determine the expected PVT accuracy for the circumstances being considered. Alternatively, the computer model may have the capability to use the UERE or UERRE values and can automatically perform the scaling and output the expected PVT accuracy directly.  The same is also true for time transfer solutions; the operator can manually process equation B-7 or the computer model can process equation B-7 using the UERE and UTCOE values. 

When the UERE values and UERRE values are different across pseudoranges, a computer model which automatically performs the scaling is essential for reliably determining the expected PVT accuracy.  Manually using equations B-2 through B-6, or equation B-7, is not practical.  This is doubly true if there are more than four pseudoranges available and if the subject GPS receiver computes weighted position solutions. 

5th Edition 

Page B-11

--- [page 150](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=150) ---

GPS SPS PS 

April 2020 

#### **SECTION B.3  Availability of Geometry and PVT Accuracy** 

This section addresses the fundamental importance of having ‘good geometry’ for all discussions of user PVT performance in the position/time domain.  The availability of ‘good geometry’ from the in-view satellites relative to the assumed GPS receiver is the critical factor which limits the availability of accurate position determination.  Without good geometry, it can be impossible for a GPS receiver to even determine a PVT solution.  The relationship between availability of ‘good geometry’ and the availability of PVT accuracy is described herein. 

###### **B.3.1  PDOP**  **6.0 Threshold for ‘Availability of Adequate Accuracy’** 

In the early years of GPS (the late 1970s), when only a few of the Block I series of satellites had been launched into orbit, the constellation coverage was optimized to support daily GPS receiver testing periods at various locations in the Southwest United States.  For long intervals during the day, there would be no satellites in view whatsoever at the testing locations.  As time progressed toward the testing period, first one satellite would rise into view followed by another until there were at least four satellites in view (or, initially, a combination of four SIS transmitters in view where those transmitters were a mix of on-orbit satellites and ground-based ‘pseudo-satellite’ [“pseudolite”] transmitters).  In those days, a rule of thumb was adopted to the effect that the GPS receiver testing ‘window’ opened as soon as the PDOP of the four SIS transmitters dropped below a value of 6.0 and that it closed once the PDOP rose back above the value of 6.0. 

Since those early years, the PDOP≤6.0 rule of thumb has evolved into the “PDOP Availability Threshold” (PDOP-AT) criteria for defining ‘availability of adequate accuracy’.  This PDOP-AT value is also used extensively in GPS constellation design and maintenance planning.  It is still one of the primary position/time domain performance standards for backward compatibility – see Table 3.8-1 in the main body of this _SPS PS_ . 

It can be shown that the baseline 24-slot constellation defined by Tables 3.2-1 and 3.2-3 in the main body of this _SPS PS_ provides a PDOP value of less than or equal to 6.0 continuously at all points in the terrestrial service volume, under certain user receiving equipment assumptions, when all orbital slots in the baseline 24-slot constellation are filled with satellites broadcasting a trackable and healthy SPS SIS.  Using this PDOP6.0 threshold as a metric for defining “availability of adequate accuracy", the baseline 24-slot constellation is said to provide 100% global availability of adequate accuracy when all orbital slots in the baseline 24-slot constellation are occupied by satellites broadcasting a trackable and healthy SPS SIS. 

_Note:_ 

_1. For additional information on the use of the PDOP≤6.0 PDOP-AT value, see “_ The GPS Constellation Design – Current and Projected _”, by P. Massatt and M. Zeitzew, in Proceedings of the 1998 National Technical Meeting of The Institute of Navigation, Long Beach, CA, January 1998._ 

_2. The fraction of the terrestrial volume over time which satisfies the PDOP≤6.0 PDOP-AT value is known as the “constellation value” (CV).  When all orbital slots in the baseline 24-slot constellation are occupied by satellites broadcasting a trackable and healthy SPS SIS, and certain user receiving equipment assumptions are satisfied, the CV is equal to 1.000._ 

5th Edition 

Page B-12

--- [page 151](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=151) ---

GPS SPS PS 

April 2020 

_3. Strictly speaking, the PDOP≤6.0 PDOP-AT value is properly a metric related to “availability of adequate geometry for adequate accuracy” rather than to “availability of adequate accuracy”. However, since “adequate accuracy” is qualitative rather than quantitative, a generic assumption of “adequate URE” (which is generally true) is sufficient to allow the PDOP≤6.0 PDOP-AT value to serve as a surrogate for “availability of adequate accuracy”.  Quantitative “availability of accuracy” performance standards which also take URE into account are covered in the following paragraph._ 

###### **B.3.2  Horizontal/Vertical Thresholds for ‘Availability of Accuracy’** 

A pair of position accuracy values known as the "Horizontal Service Availability Threshold" (HSAT) and the "Vertical Service Availability Threshold" (VSAT) are the logical evolution of the PDOP-AT described in the previous paragraph.  The HSAT and VSAT values are used by Table 3.8-2 in the main body of this _SPS PS_ to describe the requirements for ‘service availability’ or equivalently for ‘availability of accuracy’.  The HSAT is a horizontal position accuracy of 15 m 95%, the VSAT is a vertical position accuracy of 33 m 95%.  These two SAT values are not the position service availability performance standards themselves, rather they are necessary conditions (definitions) for specifying the position service availability performance standards. (The actual position service availability performance standards are the ≥99% and ≥90% numbers in the left-hand column). 

###### **B.3.2.1  Sources of the SAT Values** 

The HSAT of 15 m 95% and VSAT of 33 m 95% in Table 3.8-2 do not come from any operational requirement.  They are not user requirements.  Instead, the HSAT and VSAT values are simply the result of DOP values picked off a pair of DOP distribution curves multiplied by the 7.0 m 95% (3.6 m 1-sigma) global statistic URE value during normal operations over all AODs specified in Table 3.4-1 and a statistical conversion factor.  These SAT values are therefore really basically just the results of equations B-2 and B-3 where the URE value is the one specified in Table 3.41 _._ The HSAT value corresponds to a particular HDOP value and the VSAT value corresponds to a particular VDOP value.  In parallel with the PDOP-AT described in paragraph 3.2.1 above, the particular HDOP value is known as the “HDOP Availability Threshold” (HDOP-AT) and the particular VDOP value is known as the “VDOP Availability Threshold” (VDOP-AT).  The process for picking the particular HDOP-AT and VDOP-AT values is described below. 

###### **B.3.2.2  HDOP Distributions and VDOP Distributions** 

The process for picking the particular HDOP-AT and VDOP-AT values to use in equations B-2 and B-3 to compute the HSAT and the VSAT is based on an HDOP distribution and a VDOP distribution like the ones illustrated in Figures B.3-1 and B.3-2. 

Figure B.3-1 shows an HDOP distribution for the baseline 24-slot constellation (non-expanded) in the form of two histogram curves, one direct and one cumulative.  The range of HDOP values is most easily seen from the direct distribution curve (the dotted one which looks vaguely like a bellshaped curve offset away from zero).  The smallest HDOP value is 0.68, the biggest HDOP value is 2.49.  The most likely HDOP value (i.e., value with the maximum area under the direct distribution curve) occurs at 0.91.  The cumulative distribution curve (the solid one which starts at 0% at an HDOP of 0.00 and rises to 100% at an HDOP of 2.49) is the one that gives the "no worse than" (NWT) percentages.  This cumulative distribution curve shows 50.0% of the HDOP 

5th Edition 

Page B-13

--- [page 152](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=152) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
100.0    99.9<br>  98.0<br>  95.0<br>  90.0    90.0<br> 1 Sidereal Day<br> 5 Minute Time Steps<br>  80.0<br> 4x4 Degree Global Grid<br> All-In-View Solution<br>  70.0   5 Degree Mask Angle<br> No Aiding Sensors<br>  60.0   All 24 Baseline Satellites<br> No Expanded Slots<br>  50.0    50.0<br>: Cumulative<br>: Direct<br>  40.0<br>  30.0<br>  20.0<br>  10.0<br>  00.0<br>0.00                  1.00                   2.00                   3.00                   4.00                   5.00                   6.00<br>HDOP Values<br>Figure B.3-1.  HDOP Distribution Curves<br>100.0    99.9<br>  98.0<br>  95.0<br>  90.0    90.0<br> 1 Sidereal Day<br> 5 Minute Time Steps<br>  80.0   4x4 Degree Global Grid<br> All-In-View Solution<br>  70.0   5 Degree Mask Angle<br> No Aiding Sensors<br>  60.0   All 24 Baseline Satellites<br> No Expanded Slots<br>  50.0    50.0<br>: Cumulative<br>  40.0<br>: Direct<br>  30.0<br>  20.0<br>  10.0<br>  00.0<br>0.00                  1.00                   2.00                   3.00                   4.00                   5.00                   6.00<br>VDOP Values<br>Percentage<br>Percentage<br><!-- End of picture text -->

**Figure B.3-2.  VDOP Distribution Curves** 

5th Edition 

Page B-14

--- [page 153](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=153) ---

GPS SPS PS 

April 2020 

values are NWT 0.94, 90.0% of the HDOP values are NWT 1.16, 95.0% of the HDOP values are NWT 1.25, 98.0% of the HDOP values are NWT 1.37, and 99.9% of the HDOP values are NWT 1.80. 

Figure B.3-2 shows the corresponding VDOP distribution, also in the form of two histogram curves.  Recognize that there really is only one HDOP distribution shown in Figure B.3-1 and one VDOP distribution shown in Figure B.3-2.  The direct distribution curve and the cumulative distribution curve in each figure are just two different ways of looking at the same DOP distribution. 

The HDOP distribution in Figure B.3-1 is only one out of a great many possible HDOP distributions for the baseline 24-slot constellation (equivalently for the VDOP distribution in Figure B.3-2).  That is why it is said to be an HDOP distribution, not the HDOP distribution.  The HDOP distribution in Figure B.3-1 is specific to the particular conditions identified on the figure, namely: 

1. 1 Sidereal Day 

2. 5 Minute Time Steps 

3. 4x4 Degree Global Grid 4. All-In-View Solution 

5. 5 Degree Mask Angle 6. No Aiding Sensors 7. All 24 Slots Occupied by Usable Satellites 8. No Expanded Slots 

Of these eight conditions, only the first one, "1 sidereal day", is standard because the baseline 24-slot constellation imposes it (the constellation geometry repeats every sidereal day, roughly 23 hours 56 minutes).  The DOP distributions computed over any sidereal day are identical to the DOP distributions computed over any other sidereal day for the baseline 24-slot constellation provided the other conditions remain the same.  This is not true for DOP distributions computed over periods which are not an integer multiple of a sidereal day.  The DOP distributions computed over a solar day (exactly 24 hours) do not repeat from solar day to solar day. 

The next two conditions, "5 minute time steps" and "4x4 degree global grid", define the set of T-S points at which the DOP values are computed to go into the DOP distributions.  5 minute time steps results in 287 independent time steps over a sidereal day.  The 4x4 degree global grid refers to the angular distance between the spatial points uniformly distributed around the equator.  The latitude spacing is uniform from pole to pole, but the longitude spacing varies with the cosine of the latitude to ensure that each spatial point represents an equal area of the Earth's surface. These two circumstances vary between different computer programs.  For instance, the standard T-S points used for civil aviation analyses (see RTCA/DO-316) are based on 5 minute time steps and a 3x3 degree grid which only covers the Northern Hemisphere.  Due to symmetry, the Northern and Southern Hemispheres see the same DOP distributions every half sidereal day. 

The fourth, fifth, and sixth conditions, "AIV solution", "5 degree mask angle", and "no aiding sensors", define the assumptions about receiver algorithms for selecting SISs and measurements (see paragraph B.2.4.3).  These three conditions vary among different computer programs as much as they do among different types of GPS receivers.  These three conditions are the same ones used in generating the horizontal and vertical SAT values. 

5th Edition 

Page B-15

--- [page 154](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=154) ---

GPS SPS PS 

April 2020 

The seventh condition is that "all 24 slots in the baseline 24-slot constellation are occupied by satellites which are operational and usable (i.e., transmitting a trackable GPS SIS and set healthy)”.  This is the circumstance that varies in picking the HDOP-AT and VDOP-AT values used to compute the horizontal and vertical SAT values. 

The final condition, that there are “no expanded slots”, is a conservative assumption. 

###### **B.3.2.3  "Global Average" HDOP Distributions and VDOP Distributions** 

The DOP distributions in the preceding paragraph are "global averages" in the sense that if one randomly selects a time during the day and a place on the Earth's surface, then the probability that one will find a DOP value that is NWT any particular value is given by the cumulative DOP distribution.  From Figure B.3-1 for example; at an "average" point in time and space, there is 50.0% probability of the HDOP being NWT 0.94, 90.0% of the HDOP being NWT 1.16, 95.0% of the HDOP being NWT 1.25, and so on. 

Given the DOP distributions shown in Figures B.3-1 and B.3-2, it is possible to compute the actual mathematical average HDOP and VDOP values.  From Figure B.3-1, the mathematical average HDOP value is 0.96.  This average HDOP value differs slightly from the 50.0% probability HDOP value of 0.94 because the 50.0% probability HDOP value is actually the median value of the distribution.  The average value of a probability distribution and the median value of that distribution are generally not equal.  The average and the median are equal only for certain special types of distributions; but those distributions are exceptions rather than the rule. 

###### **B.3.2.4  "Worst-Case" HDOP T-S Point and VDOP T-S Point** 

Instead of averaging over a full sidereal day over the entire globe as described above, one can instead focus on the "worst-case" T-S point.  From Figure B.3-1 for example; the worst-case T-S point has an HDOP that is 2.49.  From Figure B.3-2; the worst-case T-S point has a VDOP that is 5.43. 

_Notes:_ 

_1. The worst-case T-S point for HDOP is generally not the same T-S point as the worst-case T-S point for VDOP._ 

_2. Because the satellite orbital period is exactly one-half sidereal day and because the orbits are north-symmetric about the equator (i.e., near-circular orbits), the relative constellation-to-Earth geometry repeats four times each sidereal day.  With all else remaining the same (“_ ceteris paribus _”), the worst-case T-S point for HDOP will repeat twice each sidereal day in the Northern hemisphere, separated by one-half sidereal day in time and by 180 degrees in longitude, and twice each sidereal day in the Southern hemisphere, also separated by one-half sidereal day in time and by 180 degrees in longitude.  The Northern-Southern repeats are out of phase with each other by onequarter sidereal day in time and 90 degrees in longitude.  Similarly, there are also four identical worst-case T-S points for VDOP each sidereal day with two occurring in the Northern hemisphere and two occurring in the Southern hemisphere._ 

_3. With a population of only one T-S point (actually four identical T-S points), it is unconventional to use names like worst case HDOP “distribution” or worst case VDOP “distribution"._ 

5th Edition 

Page B-16

--- [page 155](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=155) ---

GPS SPS PS 

April 2020 

###### **B.3.2.5  Intermediate Population HDOP Distributions and VDOP Distributions** 

Between the "global-average" (global population) with all T-S points and the "worst-case" extreme with only one (four) T-S point, it is possible to define intermediate populations of T-S points for computing DOP distributions.  One intermediate population of interest is a full sidereal day over the Continental U.S. (CONUS).  Another intermediate population is the "worst-case point in time over a sidereal day" over the CONUS.  There are many intermediate populations.  With a suitable computer model, the number of intermediate populations for which one could compute the DOP distributions is virtually boundless. 

For the “worst-case location”’ HSAT and VSAT values,  Table 3.8-2 in the main body of this _SPS PS_ uses the ’worst-case point in space‘ over a day for its intermediate populations.  These populations are subsets of the global population.  Before lumping all the DOP values for all the space points together into the global population, the DOP distributions are computed for each space point individually.  These individual space point DOP cumulative distributions are then sorted to find the "worst-case location" DOP distributions where "worst" is defined to be the DOP cumulative distribution with the highest NWT value at a given probability. 

###### **B.3.2.6** **_3_**<sup>**_rd_**</sup> **_Edition of_ the** **_SPS PS_ "Global-Average" and "Worst-Case Location" DOP** 

###### **Distributions** 

The analysis that went into the _3_<sup>_rd_</sup> _Edition of the SPS PS_ computed the "global-average" (global population) and "worst-case location" (single space point population) DOP distributions.  These computations covered the condition where all 24 slots are occupied by satellites which are operational and usable, as well as the degraded conditions where each satellite in the constellation is assumed to have either suffered a hard failure or been unusable (24 cases) and where each pair of satellites in the constellation is assumed to have suffered a hard failure or been unusable (276 cases). 

_Notes:_ 

_1. As discussed in Appendix B of the 4_<sup>_th_</sup> _Edition of the SPS PS, the DOP distribution results for the "global-average" (global population) assumed the average pair of satellites down and the "worstcase" (single space point population) assumed the worst (highest value) pair of satellites down._ 

###### **B.3.2.7  Picking HDOP-AT & VDOP-AT Values for Computing SAT Values** 

For backward compatibility purposes, the _4_<sup>_<u>th</u>_</sup> _Edition of the SPS PS_ used the same HDOP-AT and VDOP-AT values as the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ .  This 5<sup>_<u>th</u>_</sup> _Edition of the SPS PS_ perpetuates this use.  The HDOP-AT and VDOP-AT values are: 

HDOP-AT =  2.10 VDOP-AT =  4.53 

The availabilities of HDOPs less than this HDOP-AT value and VDOPs less than this VDOP-AT value are given as 90% or better at the worst case location, and 99% or better at the average location, under the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ conditions (i.e., the SIS from the worst-case two slots are unavailable, or the SIS from the average two slots are unavailable). 

5th Edition 

Page B-17

--- [page 156](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=156) ---

GPS SPS PS 

April 2020 

_Note:_ 

_1. Since both the baseline 24-slot constellation definition and the SPS SIS availability performance standards are unchanged since the 3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS, it is reasonable that the HDOP-AT and VDOP-AT values should be unchanged as well._ 

###### **B.3.2.8  5**<sup>**<u>th</u>**</sup> **Edition SPS PS SATs and Position Service Availability Standards** 

In keeping with prior editions, this ~~5~~<sup>_<u>th</u>_</sup> _Edition of the SPS PS_ converts these HDOP-AT and VDOPAT values into SIS-only HSAT and VSAT values assuming a 3.6 m RMS URE and a value of 2.0 for both the UHNE-to-R95 conversion factor and the UVNE-to-L95 conversion factor.  Specifically: 

- HSAT =  HDOP-AT x 3.6 m x 2.0 =  2.10 x 3.6 m x 2.0 

   - =  15 m 95% 

- VSAT =  VDOP-AT x 3.6 m x 2.0 

   - =  4.53 x 3.6 m x 2.0 

   - =  33 m 95% 

###### **B.3.3  "Classic" Position Accuracy Statistics** 

For its first quarter century, GPS position accuracies were always described in terms of a total overall statistic.  For example, the original 16 m spherical error probable (SEP) requirement – see _The American Practical Navigator_ for PPS users – was such a total overall statistic.  This 16 m SEP requirement meant that over all T-S points, 50% of the PPS user position fixes would have a three-dimensional (3-D) accuracy equal to or better than 16 m.  Equivalently stated, the 16 m SEP specification meant that if a PPS user went out at a random point in time at random location on the surface of the Earth, that user would have a 50% probability of getting a position fix with 3-D accuracy equal to or better than 16 m.  This total overall statistic was one of the primary sources of the term ‘global average accuracy’. 

The _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ documented a radical paradigm shift in describing GPS position accuracy.  The focus went from "how good is GPS on average" to "how bad can GPS possibly be".  The _~~3~~_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ described GPS position service availability of accuracy assuming the "worst-case" constellation (2 worst failed satellites) and the "worst-case" location (any single point on the Earth).  The position service availability of accuracy specifications at the worst-case location are thus both extremely conservative ("worst-case" constellation and "worstcase" location) and extremely liberal (excluding the worst 10% of the sidereal day as being "unavailable").  The _4_<sup>_th_</sup> _and 5_<sup>_th_</sup> _Editions of the SPS PS_ have carried on with this paradigm shift. 

This section of the current (5th) Edition of the _SPS PS_ addresses the classic way of describing GPS position accuracy as it is used in Table 3.8-3 in the main body.  This classic way is also known as the “global ensemble” description of GPS position accuracy.  It is frequently referred to as the “global average” description of GPS position accuracy, but the statistical probability level is usually at the 95% level as seen in Table 3.8-3 rather than at the 50% as in the early 16 m SEP requirement. 

5th Edition 

Page B-18

--- [page 157](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=157) ---

GPS SPS PS 

April 2020 

###### **B.3.3.1  Reasons for Needing the DOP Distributions** 

A global-average DOP value by itself is really not adequate from computing a global-average position accuracy value.  The actual DOP distribution must be taken into account in order to compute an accurate accuracy value.  The following simple example illustrates why this is so. 

_Note:_ 

_1. Because the probability conversion factors for the Gaussian (normal) distribution can be found in any good statistics textbook, the following example uses GPS vertical position accuracy since the vertical position accuracy follows a Gaussian distribution._ 

###### B.3.3.1.1  Global Average Accuracy Without DOP Distribution Information 

Say one knows the global-average VDOP for some constellation condition (e.g., worst 2-satellite failure) is exactly 1.80, but one does not know the distribution of the population of VDOP values. One might just assume that all VDOP values are exactly 1.80.  Under this assumption, for a 4.00 m 1-sigma URE and the more precise 95% conversion factor of 1.96 (instead of 2.0), one would deduce that the 95% global-average SIS-only vertical accuracy is: 

Vertical L95 =  URE x VDOP x 1.96 

=  4.0 m x 1.80 x 1.96 

=  14.11 m 95% 

This deduction is shown graphically in Figure B.3-3.  Observe this figure shows only one Gaussian distribution (Normal distribution with a zero mean) and that this Gaussian distribution has been rotated 90 degrees from its usual orientation to better illustrate position fix errors in the vertical dimension. 



<!-- Start of picture text -->
 +14.11 m  95% of the Vertical<br>Position Fixes (L95)<br>0 m<br>  -14.11 m<br><!-- End of picture text -->

**Figure B.3-3.  Vertical L95 for URE=4.0 m 1-sigma and VDOP=1.80** 

5th Edition 

Page B-19

--- [page 158](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=158) ---

GPS SPS PS 

April 2020 

###### B.3.3.1.2  Global Average Accuracy With DOP Distribution Information 

Say that one later finds better information which says that the distribution of the population of VDOP values is such that half of the VDOP values are exactly 1.40 and the other half of the VDOP values are exactly 2.20.  The global-average VDOP is still exactly 1.80.  In this case, with the same URE assumption, one would deduce that the L95% global-average vertical accuracy for each of the two sub-populations are: 

<u>50% Sub-Population with VDOP = 1.40</u> 

Vertical L95 =  URE x VDOP x 1.96 

- =  4.0 m x 1.40 x 1.96 =  10.98 m 95% 

###### <u>50 % Sub-Population with VDOP = 2.20</u> 

Vertical L95 =  URE x VDOP x 1.96 



These two sub-populations are illustrated in Figure B.3-4.  Observe that each sub-population is shown only half as large as in the previous Figure B.3-3, which corresponds to each subpopulation having 50% of the total population. 



<!-- Start of picture text -->
95% of the Vertical   +17.25 m  95% of the Vertical<br>Position Fixes (L95)  Position Fixes (L95)<br>for VDOP = 1.40  for VDOP = 2.20<br> +10.98 m  Sub-Population Sub-Population<br>0 m  0 m<br>+<br>  -10.98 m<br>  -17.25 m<br><!-- End of picture text -->

**Figure B.3-4.  Vertical L95 for VDOP=1.40 Sub-Population and VDOP=2.20 Sub-Population** 

Taking the simple average of the 95% global-average vertical accuracies for each of these two sub-populations will give the same result as before, namely 14.11 m 95%.  However, this is not correct because there is no mathematical basis for simply averaging two sub-populations.  To 

5th Edition 

Page B-20

--- [page 159](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=159) ---

GPS SPS PS 

April 2020 

illustrate the error, compare the sum of the two weighted fractions of each sub-population beyond the 14.11 m 95% value against the 5% of the total population beyond the 14.11 m 95% value which results from the simple average.  For reference, note that the 1-sigma equivalents of each sub-population distribution are: 

10.98 m 95% =   5.60 m 1-sigma for VDOP=1.40 Sub-Population 17.25 m 95% =  8.80 m 1-sigma for VDOP=2.20 Sub-Population 

<u>50% Sub-Population with VDOP = 1.40</u> 

- 14.11 m 95% =  2.520-sigma relative to a 5.60 m 1-sigma distribution 

   - 0.0118 = Fraction of sub-population beyond 2.520-sigma (i.e., beyond ±14.11 m) for a Gaussian distribution 

   - 0.0059 = Weighted fraction of total population beyond ±14.11 m given that this sub-population is ½ of the total population 

<u>50% Sub-Population with VDOP = 2.20</u> 

- 14.11 m 95% =  1.604-sigma relative to an 8.80 m 1-sigma distribution 

   - 0.1088 =  Fraction of sub-population beyond 1.604-sigma (i.e., beyond ±14.11 m) for a Gaussian distribution 

   - 0.0544 = Weighted fraction of total population beyond ±14.11 m given that this sub-population is ½ of the total population 

<u>Weighted Sum of Two Sub-Populations with 50% of VDOP = 1.40 and 50% of VDOP = 2.20</u> 

- Fraction of total population beyond ±14.11 m =  0.0059 + 0.0544 =  0.0603 

Equivalent accuracy statistic for total population =  14.11 m 93.97% 

Using the simple fact that the global average VDOP = 1.80 will lead one to deduce that 5% of the total population of vertical position fixes will be beyond ±14.11 m.  But using better information which defines the underlying VDOP distribution as being two equal sub-populations with VDOP = 1.40 and VDOP = 2.20 will reveal that actually 6.03% of the total population of vertical position fixes will be beyond ±14.11 m.  In this example, the statistical error introduced by using the globalaverage VDOP value by itself instead of using the underlying VDOP distribution is thus slightly greater than 1% in overall probability terms. 

The error introduced by not using information about the underlying VDOP distribution is more dramatic in scalar accuracy terms.  For the same overall probability of 95%, using the better VDOP information results in a scalar accuracy of 14.82 m which is 5% larger than the 14.11 m value which results from using the simple global average VDOP.  The numerology which produced this result is as follows. 

5th Edition 

Page B-21

--- [page 160](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=160) ---

GPS SPS PS 

April 2020 

###### <u>50% Sub-Population with VDOP = 1.40</u> 

- 0.0080 = Unweighted fraction of VDOP=1.40 sub-population greater than or equal to 14.82 m not accounting for the fact that this sub-population is ½ of the total population 

- 0.0040 = Weighted fraction of total population beyond ±14.82 m given that this sub-population is ½ of the total population 

<u>50% Sub-Population with VDOP = 2.20</u> 

- 0.0920 = Unweighted fraction of VDOP=2.20 sub-population greater than or equal to 14.82 m not accounting for the fact that this sub-population is ½ of the total population 

- 0.0460 = Weighted fraction of total population beyond ±14.82 m given that this sub-population is ½ of the total population 

<u>Weighted Sum of Two Sub-Populations with 50% of VDOP = 1.40 and 50% of VDOP = 2.20</u> 

Fraction of total population beyond ±14.82 m =  0.0040 + 0.0460 =  0.0500 

Equivalent accuracy statistic for total population =  14.82 m 95% 

###### B.3.3.1.3  Procedure for Using DOP Distribution Information 

Observe that the VDOP distribution is accounted for in this simple example by first computing the position accuracy distribution for each sub-population VDOP value, generating the weighted sum of the position accuracy distributions for each sub-population VDOP value using the probability of that sub-population VDOP value occurring, and then finally determining the statistics for the total position accuracy distribution for the full ensemble population. 

The same procedure can be generalized for use with sub-population HDOP distribution information, sub-population PDOP distribution information, sub-population TDOP distribution information, sub-population TTDOP distribution information, and so on. 

_Note:_ 

_1. The total position accuracy distribution is often called the "global ensemble” position accuracy distribution because it is the weighted-sum of many position accuracy sub-distributions._ 

###### **B.3.3.2  Basic Procedure for Computing Classic Position Accuracy Statistics** 

The classic GPS position accuracy procedure is similar to the example in the preceding paragraph, but the sub-populations are each individual T-S point by itself.  Letting each T-S point be its own sub-population simplifies the weighting since each sub-population is therefore simply weighted by 1 over the total number of T-S points.  It also accommodates different types of position accuracy computations, particularly those where the basic “UERE x DOP” equation does not apply (e.g., with aiding sensors, or with weighted solutions).  The classic GPS position accuracy procedure is: 

5th Edition 

Page B-22

--- [page 161](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=161) ---

GPS SPS PS 

April 2020 

1. The geometry at each T-S point over a sidereal day and across the Earth is computed for the particular circumstances being considered. 

2. The solution matrix is computed for the geometry at each T-S point. (This solution matrix is the same one a GPS receiver would compute based on that geometry given the same circumstances.) 

3. A Monte Carlo simulation is run for each T-S point geometry where simulated pseudorange error samples drawn from a Gaussian distribution with a 1-sigma value equal to the specified UERE are deterministically converted via the solution matrix to produce simulated position error samples (e.g., horizontal, vertical, spherical).  The position error samples at each T-S point represent the position accuracy at that T-S point. 

4. The position error samples produced by the Monte Carlo simulation for each T-S point geometry are summed together to produce a very large ensemble of position error samples from all T-S points. 

5. The ensemble of position error samples from all T-S points is then sorted to find the 95<sup><u>th</u></sup> percentile (or 50<sup><u>th</u></sup> percentile, 9 ~~0~~<sup><u>th</u></sup> percentile, 98<sup><u>th</u></sup> percentile, 99.9<sup><u>th</u></sup> percentile, etcetera) statistics.  These statistics are the classic total overall GPS position accuracy values. 

###### **B.3.3.3  Expanded Procedure for Computing Classic Position Accuracy Statistics** 

The basic procedure in paragraph B.3.3.2 applies to the circumstances being considered, such as assuming a particular set of 2 satellites are failed out of the baseline 24-slot constellation.  The basic procedure can be expanded to cover multiple circumstances by appropriately weighting and summing the ensembles of position error samples from all T-S points for each circumstance being considered into a super ensemble (an “ensemble of ensembles”). 

One of the main applications for this expanded procedure is addressing the probabilities of being in different constellation conditions.  For example, consider the standard model for constellation availability described in Table A.7-2.  The standard model has the baseline 24-slot constellation fully populated with 24 usable satellites transmitting a trackable and healthy SPS SIS 72.0% of the time, 23 usable satellites transmitting a trackable and healthy SPS SIS 17.0% of the time, 22 usable satellites transmitting a trackable and healthy SPS SIS 6.4% of the time, 21 usable satellites transmitting a trackable and healthy SPS SIS 2.6% of the time, and 20 or fewer usable satellites transmitting a trackable and healthy SPS SIS 2.0% of the time.  The appropriate weightings for each ensemble of position error samples is the constellation condition probability divided by the number of possible combinations making up each constellation condition. Specifically: 

5th Edition 

Page B-23

--- [page 162](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=162) ---

GPS SPS PS 

April 2020 

1 ensemble for the full 24-satellite constellation weighted by 0.720, plus 

24 ensembles for all possible 23-satellite constellations, each weighted by 0.170/24, plus 276 ensembles for all possible 22-satellite constellations, each weighted by 0.064/276, plus 2,024 ensembles for all possible 21-satellite constellations, each weighted by 0.026/2,024, plus 10,626 ensembles for all possible 20-satellite constellations, each weighted by 0.020/10,676. 

###### **B.3.3.4  Expanded Classic Position Accuracy Statistics** 

Following the expanded procedure in the preceding paragraph with 5 minute time steps, with a 4x4 degree grid, with an AIV solution, with a 5 degree mask angle, with no aiding sensors, with all 12,951 ensembles weighted as described in the preceding paragraph, and with the 6.0 m 1- sigma (11.8 m 95%) SPS SIS-only URE value in the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ for any trackable and healthy SPS SIS, the resulting classic GPS position accuracy statistics would have been: 

10.7 m  =  95% Horizontal Position Accuracy 19.8 m  =  95% Vertical Position Accuracy 

_Note:_ 

_1. The 3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS uses the geometry which results when the SIS from the average two slots are unavailable.  The weighted ensemble geometry used here is different._ 

The classic GPS position accuracy statistics for the 4.0 m 1-sigma (7.8 m 95%) SPS SIS-only URE value in the 4<sup>_<u>th</u>_</sup> _Edition of the SPS PS_ would have been: 

7.1 m =  95% Horizontal Position Accuracy 

13.2 m  =  95% Vertical Position Accuracy 

The corresponding classic GPS position accuracy statistics for the 3.6 m 1-sigma (7.0 m 95%) SPS SIS-only URE value over all AODs during normal operations in this _5th Edition of the SPS PS_ are: 

6.4 m  =  95% Horizontal Position Accuracy 11.8 m  =  95% Vertical Position Accuracy 

And the classic GPS position accuracy statistics for the combination of: the 1.0 m 1-sigma (2.0 m 95%) SPS SIS-only URE value over all AODs during normal operations, the modern SF SPS receiver UEE of 2.3 m 1-sigma (4.5 m 95%) in Table B.2-1, and an assumed SF ionospheric delay compensation error of 2.5 m 1-sigma (4.9 m 95%) under benign ionosphere conditions in the mid latitudes; or a total UERE of 3.6 m 1-sigma (7.0 m 95%), are: 

6.4 m  =  95% Horizontal Position Accuracy 

11.9 m  =  95% Vertical Position Accuracy 

_Note:_ 

_1. The above position accuracies all scale linearly with the UERE or SIS-only URE._ 

5th Edition 

Page B-24

--- [page 163](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=163) ---

GPS SPS PS 

April 2020 

###### **B.3.4  "Current" Position Accuracy Statistics for Receiver Specifications** 

###### **B.3.4.1  Background** 

The “current” position accuracy statistics for receiver specifications typically use some of the concepts from the classic expanded position accuracy statistics discussed in the previous section. They use a global ensemble (“global average”) and use the same constellation condition probability weighting for all possible 24- through 20-satellite constellations.  Unlike the classic expanded position accuracy statistics, the “current” position accuracy statistics will frequently ensemble the DOP distributions from each T-S point rather than ensembling the position fix error distributions.  The DOP results for the weighted mix of all possible 24- through 20-satellite constellations is shown in Table B.3-1. 

**Table B.3-1.  Global Ensemble DOPs for Weighted Mix of Constellation States** 

|Percentile|HDOP|VDOP|PDOP|
|---|---|---|---|
|50%|0.945|1.535|1.815|
|60%|0.985|1.625|1.905|
|67%|1.015|1.695|1.975|
|75%|1.055|1.795|2.075|
|80%|1.095|1.865|2.155|
|90%|1.205|2.085|2.325|
|95%|1.315|2.305|2.605|
|97%|1.405|2.475|2.795|
|98%|1.485|2.625|2.945|
|99%|1.655|2.925|3.305|
|99.9%|2.655|5.055|5.595|



_Notes:_ 

_1. Weighted based on 24 satellites 72.0% of the time, 23 satellites 17.0% of the time, 22 satellites 6.4% of the time, 21 satellites 2.6% of the time, and 20 or fewer satellites 2.0% of the time._ 

_2. 5 degree mask angle assumed._ 

###### **B.3.4.2  “Current” Position Accuracy Statistics for Receivers** 

Since many “current” receiver specifications use a given availability of 99% for the position accuracy statistics, the corresponding HDOP value from Table B.3-1 is 1.655 and the VDOP value is 2.925.  These HDOP and VDOP values are used basically as shown in equations (B-2) through (B-6) given earlier in this section to develop position accuracy statistics.  With UERE values expressed as 1-sigma quantities, the summary equations are: 

- 99% Worst DOP, Horizontal R95  =  UERE x HDOP x 1.73 =  UERE x 1.655 x 1.73 (B-9) 

99% Worst DOP, Vertical L95 =  UERE x VDOP x 1.96 =  UERE x 2.925 x 1.96 (B-10) 

5th Edition 

Page B-25

--- [page 164](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=164) ---

GPS SPS PS 

April 2020 

Typical “current” UERE specifications are: 

a. 4.5 m 1-sigma for DF SPS UERE over all AODs during normal operations, assuming a URE of 7.0 m 95% (3.6 m 1-sigma) and a UEE of 5.5 m 95% (2.8 m 1-sigma), and intentionally ignoring the contribution of the SF ionospheric delay model errors. 

b. 4.4 m 1-sigma for SF SPS UERE over all AODs during normal operations, assuming a URE of 7.0 m 95% (3.6 m 1-sigma) and a UEE of 5.0 m 95% (2.6 m 1-sigma), and intentionally ignoring the contribution of the SF ionospheric delay model errors. 

Substituting each of these UERE values into equations (B-9) and (B-10), and rounding as appropriate, produces position accuracy statistics as follows. 

- a. For the 4.5 m 1-sigma DF UERE: 



b. For the 4.4 m 1-sigma SF UERE: 99% Worst DOP, Horizontal R95 =  12.6 m 95% 99% Worst DOP, Vertical L95 =  25.2 m 95% 

###### **B.3.5  Position/Time Accuracy Standards in this Edition of the** **_SPS PS_** 

To clearly demonstrate backward compatibility, the position/time domain statistics in Section 3.8 of this edition of the _SPS PS_ differ from those in the _3_<sup>_<u>rd</u>_</sup> _Edition of the SPS PS_ and 4<sup>_<u>th</u>_</sup> _Edition of the SPS PS_ in only two ways: (1) the assumed 1-sigma URE is now 3.6 m, and (2) there are no additional margin factors – such as the square root of 2 used in the computation of the _3_<sup>_<u>rd</u>_</sup> _Edition_ HSAT and VSAT values – beyond the traditionally rounded-up statistical conversion factors as illustrated below: 

Horizontal R95 (SIS only) =  URE x HDOP x 2 =  3.6 m RMS x 1.1 x 2 =  8 m 95% 

Vertical L95 (SIS only) =  URE x VDOP x 2 =  3.6 m RMS x 1.8 x 2 =  13 m 95% 

5th Edition 

Page B-26

--- [page 165](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=165) ---

GPS SPS PS 

April 2020 

#### **SECTION B.4  Customized PVT Performance Expectations** 

This section describes some of the methods which can be employed to obtain PVT performance expectations customized to the particular circumstances of an actual "real world" mission.  These methods are general suggestions for typical SPS users and applications.  They are meant to be informative in the sense of being recipes that can optionally be followed to obtain the desired information.  They are not prescriptive in the sense of being procedures that should or must be complied with. 

###### **B.4.1  Three Timeframes** 

There are three time frames over which customized PVT performance expectations are typically desired.  They are:  (1) in advance of the mission, (2) during the mission, and (3) after the mission. The three time frames, along with the primary reasons customized PVT performance expectations are desired, are illustrated in Figure B.4-1. 



<!-- Start of picture text -->
Time Frame  Reason<br>Mission<br>Period<br>In-Advance  Planning<br>Now<br>Mission<br>Period<br>Real-Time  Safety<br>Now<br>Mission<br>Period<br>After-the-Fact  Maintenance<br>Now<br><!-- End of picture text -->

**Figure B.4-1.  Three Time Frames** 

Of the three time frames for PVT performance expectations, the most important one is almost always the real-time one.  In-advance PVT performance expectations can be important for mission planning (or for interpreting specifications like the _SPS PS_ ).  After-the-fact PVT performance expectations can be important for determining whether maintenance actions are necessary (e.g., if your SPS receiver suddenly lost accuracy during a mission, was it because the SPS receiver failed or was it because you encountered an unexpected DOP hole?).  But real-time PVT performance expectations are almost always the most important because they will alert you when unexpected conditions occur -- particularly conditions which can make the output PVT data unreliable -- and thereby help you safely accomplish your mission using your SPS receiver. 

5th Edition 

Page B-27

--- [page 166](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=166) ---

GPS SPS PS 

April 2020 

###### **B.4.2  Real-Time PVT Performance Expectations Directly from Your Receiver** 

The best (and simplest) course of action is to use the real-time PVT performance expectations produced by your SPS receiver whenever possible for your "real world" mission. 

###### **B.4.2.1  Real-Time Accuracy Estimates Directly from Your Receiver** 

Virtually all SPS receivers automatically generate real-time PVT accuracy estimates and output them for your use.  This is simple thing for a SPS receiver to do since it already has all the information it needs to generate those PVT accuracy estimates whenever the receiver is turned on and producing a PVT solution: it knows exactly where each satellite is in the sky, which SPS SISs it is tracking, and which SISs/satellites it is using to produce the PVT solution at each instant in time.  Using its own estimate of its current antenna position directly from the PVT solution, the SPS receiver precisely computes the current satellite-to-receiver geometry (all SPS receivers must precisely compute the current satellite-to-receiver geometry in order to produce their PVT solutions).  Having already precisely computed the satellite-to-receiver geometry, it only takes a few additional equations to compute and output precise DOP values in real time. 

To produce as accurate a PVT solution as possible, a modern SPS receiver will place more weight on its more accurate measurements and less weight on its less accurate measurements.  The weighting factors it uses basically amount to real-time estimates of the UERE for each SPS SIS being used in the PVT solution.  The SPS receiver begins by using the URA number transmitted by each satellite (see Subframe 1 in Figure 2.2-1 and paragraph A.5.2 in Appendix A) as the best available estimate of the current URE provided by that satellite's SPS SIS.  Following equation B- 8, these estimates of the current UREs are then RSS-ed with receiver-developed estimates of the current UEEs to produce estimates of the current UERE for each SPS SIS. 

_Notes:_ 

_1. The currently transmitted URA number is the best estimate of the current URE available to a SPS receiver.  The currently transmitted URA number automatically takes the time since last upload into account -- see the "graceful degradation effect" and the normal variations in URE as a function of AOD described in Section A.4.  Using the current URA number provides a higher fidelity estimate of the SPS SIS URE than any other method (e.g., using the SPS SIS URE performance standard in Section 3.4).  DGPS systems are not a source of better SPS SIS URE estimates.  DGPS systems do not broadcast URE estimates, they instead broadcast corrections for the instantaneous UREs along with estimates of the accuracy of those differential corrections (i.e., differential URE estimates, commonly known as “User Differential Range Error” [UDRE] estimates).  DGPS correction UDRE estimates are analogous to SPS SIS URE estimates, and DGPS receivers use the broadcast UDRE estimates the same way that a SPS receivers use the transmitted URA numbers._ 

_2. The SPS receiver computation of the current estimated UEE varies significantly from receiver to receiver, but all SPS receivers should address at least the first four components of the UEE shown in Table B.2-1; namely:  (1) ionospheric delay compensation errors, (2) tropospheric delay compensation errors, (3) receiver tracking channel noise and resolution errors, and (4) multipath errors._ 

With the current satellite-to-receiver geometry and current UERE estimates computed, it is a simple matter for the SPS receiver to perform the multiplications indicated by equations B-2 and B-3 to compute the current UHNE and UVNE values. (Note that equations B-2 and B-3 are not actually used by SPS receivers because the real-time UERE estimates are generally not identical across all pseudoranges, but the basic principle still applies and the process will be discussed in 

5th Edition 

Page B-28

--- [page 167](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=167) ---

GPS SPS PS 

April 2020 

terms of equations B-2 and B-3 for simplicity.)  For historical reasons, some SPS receivers do not use UHNE and UVNE; they use the following terminology instead: 

|EHE  =  UHNE =  UERExHDOP|(B-11)|
|---|---|
|EVE  =  UVNE =  UERExVDOP|(B-12)|
|EPE  =  (EHE<sup>2</sup>+ EVE<sup>2</sup>)<sup>½</sup>|(B-13)|



or 

EPE  =  UNE  =  UERE x PDOP (B-14) 

where: 

EHE  =  Estimated Horizontal Error (2-D, RMS, meters) EVE  =  Estimated Vertical Error (1-D, RMS, meters) EPE  =  Estimated Position Error (3-D, RMS, meters) 

and 

UNE  =  User Navigation Error (3-D, RMS, meters) 

_Note:_ 

_1. In addition to the EHE, EVE, and EPE values, many SPS receivers will also output the full set of numbers which result from the multiplication of the satellite-to-receiver geometry and the individual UERE estimates.  This full set of numbers, often called a "covariance matrix", is output over a digital interface.  Covariance matrix type outputs are typically used for integrating the output SPS PVT solution with the outputs of another sensor system like an IMU.  Covariance matrix type outputs are too complicated to be of use to a human operator.  They are therefore beyond the scope of this appendix._ 

As seen from equations B-11 through B-14, the SPS receiver does all the work for you in real time.  The EHE, EVE, and EPE values output by the SPS receiver in real time are your customized PVT performance expectations.  Even if you never need to worry about customized PVT performance expectations in advance or after the fact, it is still important to keep an eye on the EHE, EVE, and EPE values output/displayed by your SPS receiver in real time.  If something unanticipated should happen -- like a surprise DOP hole caused by multiple satellite failures, SPS SIS obscuration due to an unforeseen obstruction, or loss of SPS SIS tracking due to RFI (e.g., jamming) -- the EHE, EVE, and EPE values will let you know about it in real time. 

In fact, since DOP holes are the most likely cause of an unexpectedly bad PVT solution, and since SPS receivers are so good (reliable) at reporting any DOP holes via the EHE, EVE, and EPE values, the output EHE, EVE, and EPE values are actually the first line of defense for integrity warnings.  An unexpectedly bad PVT solution is defined to be an integrity failure unless it is accompanied by a timely warning.  The real-time EHE, EVE, and EPE values provide a timely warning whenever an unexpectedly bad PVT solution is caused by a surprise DOP hole.  The EHE, EVE, and EPE values are thus what keep surprise DOP holes from becoming integrity failures. 

Many GPS receivers will output a Figure of Merit (FOM) instead of or in addition to the EPE value (and/or the EHE and EVE values).  The FOM is actually a simplified version of the EPE.  For example, the correspondence between computed EPE value from a particular type of GPS 

5th Edition 

Page B-29

--- [page 168](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=168) ---

GPS SPS PS 

April 2020 

receiver and the displayed FOM value is shown in Table B.4-1.  Many other GPS receivers also display EPE and FOM this same way. 

Some GPS receivers, notably those which comply with RTCA/DO-236B, will output a parameter called the estimated position uncertainty (EPU).  The EPU is closely related to the EHE, and may even be equal to the EHE in certain GPS receiver implementations. 

**Table B.4-1.  EPE-to-FOM Correspondence** 

||**EPE Val**|**ue**<br>**Displayed FOM Value**|
|---|---|---|
||EPE|25 m<br>1|
|25 m|<  EPE|50 m<br>2|
|50 m|<  EPE|75 m<br>3|
|75 m|<  EPE|100 m<br>4|
|100 m|<  EPE|200 m<br>5|
|200 m|<  EPE|500 m<br>6|
|500 m|<  EPE|1,000 m<br>7|
|1,000 m|<  EPE|5,000 m<br>8|
|5,000 m|<  EPE|9|



_Note:_ 

_1. A widely used rule of thumb is to only rely on the output PVT solution when the FOM value equals 1.  For a SF SPS receiver, the UERE can be assumed to be on the order of 16.3 m 95% (URE over all AODs, average ionosphere).  The corresponding 1-sigma UERE value is 8.3 m.  For a FOM value of 1 (or equivalently an EPE value less than or equal to 25 m) with this UERE, the PDOP value would have to be less than or equal to 3.0.  This gives rise to a related rule of thumb which can be used if the FOM/EPE values are unavailable:  "Only rely on a SF SPS receiver’s output PVT solution if the PDOP is less than or equal to 3.0."_ 

###### **B.4.2.2  Real-Time Integrity Estimates Directly from Your Receiver** 

In addition to automatically generating and outputting real-time PVT accuracy estimates, many modern SPS receivers will also automatically generate and output real-time PVT integrity estimates using a RAIM algorithm (also known as a Fault Detection (FD) algorithm) when possible.  There are two parts to every RAIM algorithm:  (1) the non-measurement part, and (2) the measurement part. 

The non-measurement part of a modern SPS receiver's RAIM algorithm is similar to the receiver's PVT accuracy estimate computation.  The inputs are the same:  the computed satellite-to-receiver geometry and the current estimated UERE for each SPS SIS.  The non-measurement part of the RAIM algorithm determines whether the geometry and the UERE will be good enough to allow the receiver to reliably detect a SPS SIS integrity failure if one were to occur.  This basically comes down to a determination whether RAIM is available or not.  The geometry and the UERE are used to compute and output a quantity commonly known as the horizontal protection level (HPL).  The HPL is the radius of a circle in the horizontal plane which the RAIM algorithm will be able to assure contains the true horizontal position with a very high probability (see RTCA/DO-316). 

5th Edition 

Page B-30

--- [page 169](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=169) ---

GPS SPS PS 

April 2020 

_Notes:_ 

_1. The HPL does not depend on the actual pseudoranges.  The HPL does depend on the receiver tracking and using the SISs from at least 5 satellites unless additional sources of aiding information are available._ 

_2. The assurance level for a typical RAIM algorithm is set to a miss detection probability of 99.99999% (1 - 10_<sup>_-7_</sup> _) per hour, with a false alert probability of 0.00001% (10_<sup>_-5_</sup> _) per hour, based on the SPS SIS standards given in Section 3._ 

_3. Some receivers will also compute and output the corresponding vertical protection level (VPL) and/or time protection level (TPL)._ 

The measurement part of a SPS receiver's RAIM algorithm is where the actual pseudoranges from the SPS SISs are used to determine whether a SPS SIS integrity failure has occurred or not. The inputs to the measurement part of the RAIM algorithm are the computed satellite-to-receiver geometry, the current estimated UERE, and the current pseudoranges.  Some receiver's RAIM algorithms will only detect whether a SIS integrity failure is present or not.  Other RAIM algorithms go a step further by computing and outputting a quantity known as the horizontal uncertainty level (HUL).  The HUL is similar to the HPL except the HUL reflects the actual errors in the pseudoranges (see RTCA/DO-316). 

_Notes:_ 

_1. The HUL depends on the receiver tracking and using the SISs from at least 5 satellites unless additional sources of aiding information are available._ 

_2. Some receivers will also compute and output the corresponding vertical uncertainty level (VUL) and/or time uncertainty level (TUL)._ 

_3. Rather than simply using a RAIM algorithm for fault detection (FD), many modern receivers will also use their RAIM algorithm for fault detection and exclusion (FDE).  FDE processing requires the receiver to track and use the SISs from at least 6 satellites unless additional sources of aiding information are available._ 

There are three basic definitions which govern the integrity implications of the HPL and the HUL with respect to a known horizontal alert limit (HAL) for a particular mission phase (e.g., an aircraft conducting a non-precision approach where the HAL is defined based on the presence of nearby obstacles).  These three basic definitions are: 

1. RAIM is defined to be available to provide integrity for a particular mission phase whenever the HPL is less than or equal to the HAL for that mission phase (i.e., HPL  HAL). 

2. A SPS SIS integrity fault is defined to be detected whenever the HUL is greater than or equal to the HPL (i.e., HUL  HPL). 

3. A mission-critical SPS SIS integrity fault is defined to be detected for a particular mission phase whenever the HUL is greater than or equal to the HAL for that mission phase (i.e., HUL  HAL). 

5th Edition 

Page B-31

--- [page 170](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=170) ---

GPS SPS PS 

April 2020 

The three basic definitions governing the integrity implications of the HPL and HUL values output by a SPS receiver with respect to the HAL for a particular mission phase are illustrated in Figure B.4-2 for a variety of situations.  The illustrated situations are as follows: 

- a. The normal situation where HUL < HPL < HAL is illustrated by panel "a" at the top of Figure B.4-2.  In this situation, RAIM is available to provide integrity for this mission phase because HPL < HAL.  No SPS SIS integrity fault has been detected because HUL < HPL. These two integrity implications combine to give an "all systems go" result which is symbolized by the green light on the stoplight icon. 

- b. Panel "b" shows a situation where RAIM is not strictly available to provide integrity for this mission phase because HPL > HAL.  Even though RAIM is not strictly available, it is still working well enough to determine that no SPS SIS integrity fault is detected because HUL < HPL.  The combination of these two integrity implications gives an "exercise caution" result symbolized by the yellow light on the stoplight icon. 

- c. Panel "c" in Figure B.4-2 shows a situation where RAIM is available because HPL < HAL, and where a SPS SIS integrity fault has been detected because HUL > HPL.  The fact that HUL < HAL means that the detected SPS SIS integrity fault is defined as not being mission critical.  The combination of these three integrity implications gives a "weak should not use" result symbolized by the dim red light on the stoplight icon. 

- d. Panel "d" shows a slightly different situation than panel "c".  RAIM is still available because HPL < HAL, and a SPS SIS integrity fault has been detected because HUL > HPL.  The difference from panel "c" is that HUL > HAL which means the detected SPS SIS integrity fault is mission critical.  The combination of these three integrity implications gives a "strong do not use" result symbolized by the bright red light on the stoplight icon. 

Different SPS receivers implement their RAIM algorithms in different ways and have different displays for the real-time integrity results.  SPS receivers for aviation applications often have HAL values stored in their database for different phases of flight and will provide simple indications (like with the stoplight icon in Figure B.4-2) using flags on the pilot's navigation display.  Some handheld SPS receivers let you enter a HAL value and provide simple indications based upon that HAL.  Other SPS receivers only output the HPL and HUL values; they leave it up to you to compare those values against whatever HAL you decide is appropriate for your mission phase. 

5th Edition 

Page B-32

--- [page 171](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=171) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
HUL < HPL < HAL<br>HUL<br>HPL<br>HAL  B.  Normal Situation<br>HUL < HAL < HPL<br>HUL<br>HAL<br>b.  RAIM Not Available for this HAL<br>HPL<br>HPL < HUL < HAL<br>HPL<br>HUL<br>HAL  c.  Fault Detected, Non-Critical for this HAL<br>HPL < HAL < HUL<br>HPL<br>HAL  d. Fault Detected, Critical for this HAL<br>HUL<br><!-- End of picture text -->

**Figure B.4-2.  HPL, HUL, HAL Relationships** 

5th Edition 

Page B-33

--- [page 172](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=172) ---

GPS SPS PS 

April 2020 

The performance of a RAIM algorithm is highly dependent on the specific assumptions made by the algorithm designer about the characteristics of the UERE and on the actual characteristics of the UERE that the RAIM algorithm experiences.  Most RAIM algorithm designers tend to err on the conservative side in their assumed UERE compared to the actual UERE.  For example, some RAIM algorithms assume a conservative URE of 5.7 m 1-sigma based on an assumed SPS URA index of 3 (see Table A.5-1 in Appendix A) and others assume a conservative UEE of 5.5 m 95% (see Table B.2-1 in Appendix B).  For RAIM algorithms in SPS receivers, the dominant factor in the assumed UERE is typically the residual error due to the SF ionospheric delay model. Conservative assumptions for the SF ionospheric delay model errors, such as the ones given in RTCA/DO-316, can effectively establish the limits of RAIM availability almost independent of the assumed SPS URA or assumed UEE.  A well-designed aviation grade SPS receiver with a RAIM algorithm designed and evaluated in accordance with the conservative assumptions in RTCA/DO316 will be limited to the RAIM availabilities given in Table B.4-2. 

**Table B.4-2.  RAIM Availability Examples** 

|**Phase of Flight**|**Availability of Detection**|**Availability of Exclusion**|
|---|---|---|
|En Route<br> (HAL = 2.0 nm)|99.95%|99.30%|
|Terminal<br> (HAL = 1.0 nm)|99.90%|98.45%|
|Non-Precision Approach<br> (HAL = 0.3 nm)|99.80%|93.10%|



No matter how a SPS receiver implements its RAIM algorithm, if you are using PVT solution from that receiver for any safety critical application -- it is vitally important that you pay heed to the realtime PVT integrity information provided by your receiver.  That real-time PVT integrity information will alert you when unexpected conditions occur which make the output PVT solution unreliable and potentially unsafe. 

###### **B.4.3  In-Advance PVT Performance Expectations** 

###### **B.4.3.1  General Rule -- Don't Worry About It** 

As a general rule, most SPS users do not need customized PVT performance expectations in advance of a mission.  There are three main reasons for this general rule. 

###### B.4.3.1.1  Good SPS PVT Performance 

The SPS SIS provided by the satellites is robust enough, and sufficient satellites are kept usable in the on-orbit constellation, that good SPS PVT performance can be reasonably be assumed any time of day anywhere in the world.  For example, paragraph B.3.3.4 describes the classic position accuracies at a random time, random location, any AOD for a SPS user with conservative SF UERE assumptions as 15.5-22.0 m 95% horizontal averaged over all constellation conditions (from 24 satellites transmitting a trackable and healthy SPS SIS to only 20 of 24 satellites transmitting a trackable and healthy SPS SIS). 

High availability of good accuracy is borne out by the global average DOP values shown in Figure B.3-1.  The usual constellation condition has all 24 satellites transmitting a healthy SIS (or 23 out of 24 baseline satellites transmitting a healthy SIS combined with a few auxiliary satellites which are also transmitting a healthy SIS).  With this constellation condition, Figure B.3-1 shows that 

5th Edition 

Page B-34

--- [page 173](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=173) ---

GPS SPS PS 

April 2020 

99.9% of all the HDOP values will be less than 1.80.  Substituting this HDOP value into equation B-2 along with a very conservative 12.3 m 1-sigma UERE value, and translating to an R95 value gives: 



A 99.9% availability of a horizontal accuracy of 38.2 m 95% or better any random time at any random location is pretty good odds.  Furthermore, 38.2 m 95% is also quite accurate -- it is more than adequate for many real-world missions.  While it is certainly possible to search the entire world to find a location with worse accuracy, those locations are the 1-in-2,500 exceptions rather than the rule. 

If you don't require horizontal accuracy better than 15.5-22.0 m 95% on average, 38.2 m 95% with high availability, or if you can coast along for a few minutes if you should accidentally encounter one of those rare DOP holes, it isn't worth worrying about customized in-advance PVT performance expectations.  The odds are heavily stacked in your favor. 

B.4.3.1.2  Repetitive Constellation Geometry 

Another good reason for not worrying about customized in-advance PVT performance expectations is prior success using the SPS SIS in your particular area of operations.  Remember that the constellation geometry repeats every sidereal day (i.e., 4 minutes earlier each succeeding day because a sidereal day is shorter than a solar or "wall clock" day).  Unless something drastic happens -- like a satellite suddenly failing to transmit a trackable and healthy SPS SIS -- the PVT performance expectations for your operational area will not significantly change from sidereal day to sidereal day.  If there is a temporary DOP hole due to a satellite outage, that same DOP hole will repeat every sidereal day until the satellite is restored or the outage is repaired.  The SPS performance you got yesterday is a very good predictor of the SPS performance you will get today. 

The best, and easiest, way to keep current on satellite status changes is by subscribing to the NANUs issued by the Control Segment.  The NANUs -- both for satellite status changes that are scheduled in advance and for after-the-fact surprises -- are sent directly via e-mail almost the instant they are issued.  Civil SPS users can subscribe at https://www.navcen.uscg.gov.  This web site also posts the NANUs for subsequent downloading on demand. 

5th Edition 

Page B-35

--- [page 174](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=174) ---

GPS SPS PS 

April 2020 

###### B.4.3.1.3  Receiver and Mission Characteristics 

Certain types of SPS receivers make worrying about customized in-advance PVT performance expectations unnecessary because the expected PVT performance just doesn't vary all that much.  Certain types of missions also make worrying about customized in-advance PVT performance expectations impractical because it takes too much effort to develop reliable expectations.  Some representative illustrations include: 

- a.  Time Transfer Receivers.  Time transfer receivers, which operate from a known location, are affected by TTDOP rather than TDOP.  Fortunately for time transfer performance expectations, the TTDOP variations over time are much smaller than the TDOP variations. So long as the SPS SIS is available from at least two visible satellites (a virtual certainty), the TTDOP will be adequate to give excellent time transfer performance. 

- b.  Waterborne Receivers.  SPS receivers used for waterborne missions can normally take advantage of aiding information in the vertical direction when they encounter a DOP hole. For example, the SPS receiver on a ship in the middle of the ocean knows the (calibrated) height of its antenna above sea level.  The ability to use this information as an extra measurement effectively "fills in" any DOP holes.  As a result, waterborne SPS receivers are not usually subject to significant swings in expected PVT performance. 

- c.  Land Navigation in Obstruction-Rich Environments.  Land navigation in an environment, which offers a clear view of the sky in all directions (e.g., flat desert terrain) is one thing, but trying to navigate in an environment with nearby buildings, trees, or other obstructions is another thing altogether.  There can be so many obstructions around that they completely block every SPS SIS from reaching your SPS receiver's antenna.  Even when there is only one nearby obstruction that only blocks one SPS SIS, the loss of that SPS SIS can radically alter the DOP values.  In such obstacle-rich environments, it is difficult to try to predict in advance which satellite's SPS SIS will be blocked and when that blockage will start or end.  Obscuration angles are very sensitive to small changes in SPS receiver antenna height and location as shown in Figures B.4-3 and B.4-4 for a nearby obstacle. 

Although it is possible to compute obscuration angles for situations like those in Figures B.4-3 and B.4-4, doing so is generally a wasted effort.  Note how accurately you would have to know the height and location of your SPS receiver antenna in order to precisely compute the obscuration angle.  If you knew in advance where your SPS receiver antenna was going to be that accurately, then you would already have better height and location information than you are probably going to get from your SPS receiver!  Computing obscuration angles and expected DOP values in advance may be a waste of time in these situations, but computing them in real-time is important (as described previously). 

5th Edition 

Page B-36

--- [page 175](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=175) ---

GPS SPS PS 

April 2020 



<!-- Start of picture text -->
4.0 m<br>  9 <br>10 <br>11 <br>1.5 m<br>1.2 m<br>0.9 m<br>16 m<br>1.5 m = Holding SPS Receiver Head-High<br>1.2 m = Holding SPS Receiver Chest-High<br>0.9 m = Holding SPS Receiver Waist-High<br><!-- End of picture text -->

**Figure B.4-3.  Obscuration Angles versus SPS Receiver Antenna Height** 



<!-- Start of picture text -->
4.0 m<br>  9 <br>10 <br>11 <br>1.2 m<br>14.5 m<br>16.0 m<br>17.5m<br>17.5 m = Holding SPS Receiver Away From the Building<br>16.0 m = Holding SPS Receiver Straight Out in Front<br>14.5 m = Holding SPS Receiver Towards the Building<br><!-- End of picture text -->

**Figure B.4-4.  Obscuration Angles versus SPS Receiver Antenna Location** 

5th Edition 

Page B-37

--- [page 176](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=176) ---

GPS SPS PS 

April 2020 

###### **B.4.3.2  In-Advance PVT Performance Expectations Directly from Your Receiver** 

Certain missions which rely on the GPS SPS may be safety-related or critical enough that it is worthwhile to take a simple in-advance look to be sure that the SPS will be available at some future time at some future place to support mission accomplishment.  SPS availability is high, but it is not always 100% available everywhere.  Accuracy is more available than integrity. 

B.4.3.2.1  In-Advance Accuracy Expectations Directly from Your SPS Receiver 

Some SPS receivers include provisions to let you define a future time and location and will respond back with in-advance accuracy expectations (properly called in-advance "accuracy <u>predictions").</u> 

Generally speaking, being limited to predicted PDOP values is not too significant for mission planning purposes in the field.  In-advance predictions can never do better than use the "transmitted on-orbit average" URE values (see paragraph B.2.3.4) for each satellite's SPS SIS. Since averaging the satellite-transmitted URA numbers over time is difficult to do under field conditions, the normal approximations are:  (1) that all SPS SISs have the same UERE value, and (2) that an appropriate 1-sigma UERE value can be developed from Table 3.4-1  and Table B.2-1 for the particular type of SPS receiver in use.  Under these approximations, it is easy enough to simply follow equation B-14 and multiply the predicted PDOP value from the SPS receiver by the appropriate 1-sigma UERE value. 

B.4.3.2.2  In-Advance Integrity Expectations Directly from Your SPS Receiver 

Some SPS receivers -- particularly avionics SPS receivers -- include provisions to let you define a future time and location and will respond back to you with in-advance integrity predictions.  This capability is usually called "predictive RAIM" (see AC 20-138 for example). 

For in-advance use, an avionics SPS receiver can use its RAIM algorithm to compute predicted HPL values but it cannot compute predicted HUL values.  The HUL computation requires actual pseudoranges which are obviously not available in advance.  The HPL computation only requires satellite-to-receiver geometry and UERE estimates.  Just for accuracy predictions, the satelliteto-receiver geometry can be computed in-advance from the almanac data stored in the receiver's internal memory.  The UERE estimates for the particular type of SPS receiver can be developed in a manner comparable to Table B.2-1 and stored in the receiver's internal memory as a uniform number to be applied to all SPS SISs.  Most avionics SPS receivers which provide this predictive RAIM capability allow you to select your destination airport and your estimated time of arrival (ETA), and will respond with an automatic "RAIM YES/NO" determination over a window of time surrounding your ETA.  The automatic "RAIM YES/NO" determination is made by comparing the predicted HPL value against a HAL value of 0.3 nm for the non-precision approach phase of flight. 

_Notes:_ 

_1. Using a hard-coded, uniform UERE value is not as realistic as using "transmitted on-orbit average" URE values along with receiver-specific UEE values, but it has been found to be sufficient for inthe-cockpit predictions._ 

_2. For additional information on this predictive RAIM capability, see MSO-C129, TSO-C145, MSOC145, TSO-C146, and TSO-C196._ 

5th Edition 

Page B-38

--- [page 177](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=177) ---

GPS SPS PS 

April 2020 

###### **B.4.3.3  In-Advance PVT Performance Expectations from a Computer Model** 

If you must worry about high-fidelity in-advance PVT performance predictions, whether for accuracy or for integrity, then you can use a computer model.  There are customized computer models and general purpose computer models. 

###### B.4.3.3.1  Customized SPS Computer Model 

If your mission requires you to frequently use high-fidelity PVT performance predictions, then odds are that you will have been provided with a computer model that is set up specifically for your particular SPS receiver (e.g., see AC 20-138).  Your computer model may very well be an integral part of the mission planning system you use -- there is a natural synergy between the two because your mission planning system already knows when and where you want to go which is the same as knowing the T-S points for which the PVT performance predictions must be computed.  For the highest fidelity PVT performance expectations, your computer model may be integrated with portions of the actual SPS receiver software. 

You will need to provide the customized computer model with the appropriate almanac data for the satellites along with the satellite status in effect during the time window of interest.  The daily almanac data is available for downloading from <u>https://www.navcen.uscg.gov</u> .  This web site also has the NANUs which give the dates and times for projected changes in the satellite status settings.  For higher fidelity (if possible), you may also want to provide the computer model with the "transmitted on-orbit average" SPS URE values (see paragraph B.2.3.4) for each satellite's SPS SIS.  Estimated SPS SIS URE values averaged over a day are built into the SEM-formatted almanacs available at <u>https://www.navcen.uscg.gov ; these URE values can be input to a moving</u> average filter to compute the higher-fidelity "transmitted on-orbit average" SPS URE values.  You won't need to know too much about the SPS receiver itself (e.g., satellite selection algorithm, UEE values, mask angle), since that information will have been built directly into your customized computer model. 

_Notes:_ 

_1. The daily almanac data from many web sites is available in two formats:  the SEM format and the Yuma format.  Although the information is basically the same as what the satellites broadcast via the SPS SIS, the two formats are not interchangeable.  Be sure to download the right format for your customized computer model._ 

_2. The SEM format almanac data from both the indicated web sites already has the "transmitted onorbit average" SPS URA values built into it._ 

_3. The highest fidelity will generally be achieved with the almanac data time tagged just prior to the window of interest.  Using almanac data from preceding days or following days not recommended due to the potential for satellite repositioning events which will invalidate previous valid almanac data._ 

###### B.4.3.3.2  General-Purpose GPS Computer Model 

If you don't have a customized computer model for your SPS receiver, you can use a generalpurpose GPS computer model; however, you'll have to know some details about your SPS receiver to set up the computer model right to get good results.  In addition to the proper almanac 

5th Edition 

Page B-39

--- [page 178](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=178) ---

GPS SPS PS 

April 2020 

data, SIS health settings, and URE estimates for the satellites, you will also need to know some details about your SPS receiver which were described in general in Section B.2.  Those SPS receiver details are: 

- a.   The SPS receiver algorithm for selecting the subset of visible satellite SISs to be used in the PVT solution or time transfer solution. 

- b. _Reserved._ 

- c.   Whether the SPS receiver can use aiding data (especially details about using vertical aiding). 

- d.   The SPS receiver's internal mask angle (or its satellite visibility algorithm). 

- e.   The maximum number of SPS SISs that can/will be used in the PVT solution or time transfer solution. 

###### **B.4.4  After-the-Fact PVT Performance Expectations** 

If you need after-the-fact PVT performance expectations customized to a particular circumstance, then you can use a computer model like those described in the preceding section.  The process is usually the same.  Occasionally, there are a few exceptions. 

For high-fidelity after-the-fact PVT performance expectations, you will want to provide the computer model with the actual URA numbers from the SPS SISs during the time window of interest.  Most modern SPS receivers use those URA numbers to compute the weighting factors which modify the position solution as well as the effective satellites-to-user geometry.  Without the actual URA numbers, the computer model will not be able to replicate what the SPS receiver did in computing its weighted DOPs. 

Depending on the reason for needing after-the-fact PVT performance expectations, it may be necessary to simulate actual SPS SIS pseudorange errors (instantaneous UREs) if the problem being investigated is related to a SPS SIS integrity failure.  Sometimes, short-duration SPS SIS outages (e.g., short periods of non-standard C/A-code) may need to be simulated.  Occasionally, a computer model which handles terrain blockage or unusual receiving antenna orientations may be required.  Experience has shown that RFI is often a cause of unexpected PVT performance; specialized computer models which address SPS SIS signal strength can be useful in these cases. 

5th Edition 

Page B-40

--- [page 179](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=179) ---

GPS SPS PS 

April 2020 

# _GLOBAL POSITIONING SYSTEM STANDARD POSITIONING SERVICE PERFORMANCE STANDARD_ 

## _APPENDIX C_ 

## _KEY TERMS, DEFINITIONS, ABBREVIATIONS AND ACRONYMS_ 





## _April 2020_ 

**_Integrity - Service - Excellence_** 

5th Edition

--- [page 180](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=180) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

5th Edition

--- [page 181](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=181) ---

GPS SPS PS 

April 2020 

### **TABLE OF CONTENTS** 

|**SECTION C.1  Key Terms**.........................................................................................**C-1**|
|---|
|**SECTION C.2  Definitions**.........................................................................................**C-7**|
|**SECTION C.3  Abbreviations and Acronyms**..........................................................**C-8**|



Page C-i 

5th Edition

--- [page 182](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=182) ---

GPS SPS PS 

April 2020 

(This page intentionally left blank.) 

Page C-ii 

5th Edition

--- [page 183](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=183) ---

GPS SPS PS 

April 2020 

#### **SECTION C.1  Key Terms** 

**Alarm.** An indication requiring an immediate response (e.g., to preserve integrity). 

**Alert.** Generic term encompassing both alarm and warning. 

**Alerted Misleading Signal-in-Space Information (AMSI).** The pseudorange data set (e.g., pseudorange measurement and NAV data) provided by a SPS SIS provides alerted MSI (AMSI) when the instantaneous URE exceeds the SIS URE NTE tolerance but a timely alert (alarm or warning) is provided. 

**Auxiliary Satellite.** An operational satellite that is not occupying a defined orbital slot in the baseline 24-slot constellation or the expandable 24-slot constellation.  Auxiliary satellites are typically either newly launched satellites waiting to take their place in the baseline/expandable 24slot constellation, or are older satellites which are nearing the end of their useful lives and have been shifted out of the baseline/expandable 24-slot constellation.  The SPS SIS broadcast by an auxiliary satellite is not required to meet all of the standards in Section 3. 

**Baseline 24-Slot Constellation.** Operational satellites deployed in the 24 defined baseline orbital slots.  Each orbital slot is characterized by a near one-half sidereal day period such that the orbit ground trace repeats each sidereal day.  The orbital slots are organized by the orbit plane, with each orbit plane having multiple slots and each slot having a unique orbital ground trace.  In the baseline 24-slot constellation, there are six orbit planes, each with four slots. 

**Baseline Satellite.** An operational satellite occupying a defined orbital slot in the baseline 24slot constellation.  Not all operational satellites occupy slots in the baseline 24-slot constellation, and not all slots in the baseline 24-slot constellation are necessarily occupied by an operational satellite.  The SPS SIS broadcast by a baseline satellite is required to meet all of the standards in Section 3.  In contrast, the SPS SIS broadcast by an auxiliary satellite is not required to meet all the performance standards in Section 3. 

**Block II Satellites.** The current deployed operational constellation consists entirely of Block II series satellites (the IIA, IIR, IIR-M, and IIF). 

**Dilution of Precision (DOP).** The magnifying effect on GPS position error induced by mapping URE into a position solution within the specified coordinate system, through the relative satelliteto-receiver geometry.  The DOP may be expressed in any user local coordinate system desired. Examples include HDOP for local horizontal, VDOP for local vertical, PDOP for local horizontal and vertical together, and TDOP for time. 

**Expandable 24-Slot Constellation.** Operational satellites deployed in a constellation with at least one of the defined-as-expandable orbital slots in its expanded configuration. 

**Expanded PRN Satellite.** An operational satellite broadcasting PRN code signals numbered 33 or higher.  Expanded PRN satellites are not eligible for satisfying the availability performance standards in Section 3.7 due to backward compatibility limitations. 

**Expanded Slot Satellite.** An operational satellite occupying a defined-as-expandable orbital slot in its expanded configuration.  There can be up to 12 expanded satellites at any one time. 

Page C-1 

5th Edition

--- [page 184](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=184) ---

GPS SPS PS 

April 2020 

**Full Operational Capability (FOC).** Full Operational Capability (FOC) was achieved on 27 April 1995 when the GPS satellite constellation met all of its specified requirements.  The DoD formally announced the achievement of FOC to the public on 17 July 1995.  For SPS users, the 1995 FOC was limited to just the C/A-code signal.  As of the date of this 5<sup>th</sup> Edition of the _SPS PS_ , there are no FOCs declared for any of the other SPS signals. 

**Geometric Range.** The difference between the location of a satellite (true origin of the pseudorange measurement) and the location of a GPS receiver. 

**Global Average.** The typical (average, mean, RMS) value of a performance metric or characteristic (e.g., dilution of precision) over the specified coverage (e.g., surface of the Earth, satellite footprint). 

**Global Statistic.** The statistical (95%, RMS, 1-sigma) value of an algebraically signed performance metric or characteristic (e.g., instantaneous URE) over the specified coverage (e.g., satellite footprint).  Formerly, but improperly, also called “global average”. 

**GPS Time.** A continuous time scale maintained by the GPS Control Segment which began at midnight on the night of 5/6 January 1980 on the Coordinated Universal Time (UTC) scale as established by the U.S. Naval Observatory (USNO). 

**Hazardously Misleading Information (HMI).** The errors in the position solution output by a SPS receiver exceed the user’s particular tolerance for error in the current application. 

**Healthy Satellite.** A satellite which is transmitting at least one trackable and healthy SPS SIS. 

**Healthy SPS Signal-in-Space (SIS).** A trackable SPS SIS which:  (a) is not subject to a SPS alert indication, (b) indicates the SPS SIS is healthy in the navigation (NAV) message data, (c) does not indicate a URA index value of 8 or greater, and (d) does not indicate a User Range Accuracy (URA) alert. 

**Initial Operational Capability (IOC).** Initial Operational Capability (IOC) was declared on 8 December 1993 when the DoD formally made the SPS available to the DOT.  For SPS users, the 1993 IOC was limited to just the C/A-code signal.  As of the date of this 5<sup>th</sup> Edition of the _SPS PS_ , there are no IOCs declared for any of the other SPS signals. 

**Instantaneous User Range Error (URE).** An instantaneous URE is the difference between the pseudorange measured at a given location assuming a receiver clock that is perfectly calibrated to GPS time and the expected pseudorange as derived from the NAV message data for the given location and the assumed receiver clock.  The instantaneous SIS URE includes only those pseudorange data set error budget components assigned to the GPS Space and Control Segments (i.e., not including the error budget components assigned to the GPS User Segment such as the troposphere delay compensation error, multipath, and receiver noise). 

**Integrity Assured User Range Accuracy (IAURA).** The IAURA is a conservative representation of the upper bound on each satellite's expected RMS URE performance over the curve fit interval represented by the NAV data from which the URA is read.  The IAURA is a key parameter in determining the SIS URE not-to-exceed (NTE) tolerance for integrity.  The equations for determining the LNAV IAURA based on the LNAV URA index are given in IS-GPS-200, while the 

Page C-2 

5th Edition

--- [page 185](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=185) ---

GPS SPS PS 

April 2020 

equations for determining the CNAV IAURA based on the CNAV URAED, URANED0, URANED1, and URANED2, indexes are given in both IS-GPS-200 and IS-GPS-705. 

**Major Service Failure.** A condition during which a trackable and healthy SPS SIS's instantaneous URE exceeds the SIS URE not-to-exceed (NTE) tolerance without a timely alert (alarm or warning) being provided.  Also known as a UMSI event and/or an integrity failure. 

**Misleading Signal-in-Space Information (MSI).** The pseudorange data set (e.g., pseudorange measurement and NAV data) provided by a SPS SIS provides Misleading Signal-in-Space Information (MSI) when the instantaneous URE exceeds the SIS URE NTE tolerance. 

**Modernized Block III Satellites.** This edition of the _SPS PS_ does not address the future open access signals (e.g., L1C) that will be transmitted by Modernized Block III satellites. 

**Navigation.** The process of planning, recording, and controlling the movement of a craft or vehicle from one place to another.  Navigation is an application of position, velocity and time information. 

**Navigation (NAV) Message Data.** The data provided to a GPS receiver via each satellite's SIS containing the satellite's predicted clock correction polynomial ("clock"), the satellite's predicted orbital elements ("ephemeris"), the satellite's predicted healthy and accuracy parameters ("integrity"), optionally a reduced-precision subset of the clock/ephemeris/integrity data for all operational satellites in the constellation ("almanac"), optionally pseudorange correction data, parameters relating GPS time to UTC, SF ionospheric correction model parameters, and other system information.  The clock, ephemeris, and integrity information comprise a matched collection of information known as the CEI data set,  The C/A-code signal provides the ‘legacy’ version of the NAV data (LNAV) while the CM-code signal and I5-code signal provides the ‘civil’ version of the NAV data (CNAV).  Detailed definitions of the NAV data are provided in IS-GPS200 and IS-GPS-705. 

**Non-Standard Code.** The non-standard codes (NSCs) are used to protect the user from SIS malfunctions.  Non-standard codes are not trackable by SPS receivers which are compliant with the GPS ISs/ICDs. 

**Occupied.** A slot is occupied by a satellite when the satellite’s footprint on the surface of the Earth overlaps 95% of the slot center’s footprint on the surface of the Earth averaged over an orbit revolution. 

**Operational Satellite.** A satellite which is capable of transmitting, but is not necessarily currently transmitting, a trackable ranging signal.  For the purposes of these performance standards, any satellite in the transmitted navigation message almanac is considered an operational satellite. 

**95**<sup>**th**</sup> **Percentile (95%) URE.** A statistical measurement of the instantaneous URE performance sampled over some interval.  The 95% URE can apply to the SPS SIS from an individual satellite or to the SPS SISs from an ensemble of satellites (e.g., all usable satellites in the constellation). 

**PPS Signals.** A subset of the electromagnetic signals originating from a satellite.  The PPS signals consist of a Pseudorandom Noise (PRN) C/A-code with NAV data to support the PVT solution generation process on the GPS L1 frequency; a PRN P(Y)-code with identical NAV data to support the PVT solution generation process on the GPS L1 frequency; and a PRN P(Y)-code 

Page C-3 

5th Edition

--- [page 186](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=186) ---

GPS SPS PS 

April 2020 

with identical NAV data to support the PVT solution generation process on the GPS L2 frequency. Depending on the particular satellite, PPS signals may also include M-code signals. 

**Precise Positioning Service (PPS).** The GPS broadcast signals based on the L1 P(Y)-codes, L1 C/A-codes, L2 P(Y)-codes, and optionally M-codes, as defined in the GPS ISs/ICDs, providing constellation performance to authorized users, as established in the _PPS Performance Standard (PPS PS)_ , in accordance with U.S. Government (USG) policy. 

**Pseudorange.** Depending on context, “pseudorange” may refer to a full pseudorange data set or just to a pseudorange measurement by itself. 

**Pseudorange Data Set.** The matched combination of a corrected pseudorange measurement and a pseudorange origin, or equivalently the matched combination of a raw pseudorange measurement and the associated NAV data.  In vector terms, a pseudorange data set comprises an origin and a scalar magnitude – but no orientation information. 

**Pseudorange Measurement.** The difference between the PRN code time of reception (as defined by the SPS receiver’s clock) and the PRN code time of transmission (as defined by the satellite’s clock) multiplied by the speed of light.  May also be a short-hand reference to the corrected pseudorange measurement where the raw pseudorange measurement is adjusted to GPS system time using the broadcast satellite clock correction polynomial and related data.  The corrected pseudorange measurement is also known as an SPS signal ranging measurement. 

**Pseudorange Origin.** The point in space from which a particular pseudorange measurement originates (e.g., Earth-Centered, Earth-Fixed Cartesian coordinates), typically derived from the broadcast satellite ephemeris portion of the NAV data. 

**PVT Solution.** The use of pseudorange data sets from at least four SISs to solve for three position coordinates and time offset relative to GPS time, plus three velocity coordinates and frequency offset relative to GPS time.  In cases where the altitude is known (e.g., maritime GPS receivers), the PVT solution only requires the use of pseudorange data sets from at least three SISs to solve for two position coordinates and time offset relative to GPS time, plus two velocity coordinates and frequency offset relative to GPS time. 

**Receiver Autonomous Integrity Monitoring (RAIM).** RAIM is an algorithm used by a GPS receiver to autonomously monitor the integrity of the output position/time solution data.  There are many different RAIM algorithms.  RAIM algorithms are sometimes also known as fault detection (FD) algorithms.  All RAIM algorithms are based on the consistency of redundant measurements. 

**Root Mean Square (rms or RMS) URE.** A statistical measurement of the instantaneous URE performance sampled over some interval.  The RMS URE can apply to an individual satellite or to an ensemble of satellites (e.g., all operational satellites in the constellation). 

**Satellite Outage.** A satellite outage occurs when a satellite either stops transmitting a trackable SPS SIS or the SPS SIS becomes unhealthy. 

**SatZap.** A manual technique used by the Control Segment to temporarily remove a satellite from service by commanding the satellite to substitute transmission of an unused PRN code number (typically PRN-37) for its standard PRN code number.  May also refer to the Control Segment commanding the satellite to switch to NSC transmission. 

Page C-4 

5th Edition

--- [page 187](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=187) ---

GPS SPS PS 

April 2020 

**Selective Availability (SA).** Protection technique employed by DoD in the past to deny full system accuracy.  On May 1, 2000, President Clinton announced the discontinuance of SA effective midnight 1 May 2000.  The effects of SA went to zero at 0400 UTC on 2 May 2000. 

**Service Interruption.** A condition over a time interval during which one or more SPS performance standards are not satisfied. 

**SIS URE.** The SIS URE includes only those pseudorange data set error budget components assigned to the GPS Space and Control Segments.  The SIS URE can be expressed in different ways; e.g., on an instantaneous basis (see the definition of _instantaneous URE_ ) or on a statistical basis (see the definition of _RMS URE_ ). 

**Space Service Volume.** One of the two spatial volumes addressed by this _SPS PS._ The space service volume extends from 3,000 km above the surface of the earth up to and including 36,000 km above the earth’s surface. 

**SPS Signal Ranging Measurement.** The difference between the PRN code time of reception (as defined by the SPS receiver's clock) and the PRN code time of transmission (as defined by the satellite's clock) adjusted to GPS system time using the satellite clock correction polynomial and related data contained within the satellite's NAV data multiplied by the speed of light.  Also known as the corrected pseudorange measurement. 

**SPS Signals.** A subset of the electromagnetic signals originating from a satellite.  The SPS signals consist of at least a Pseudorandom Noise (PRN) C/A-code with LNAV data to support the PVT solution generation process on the GPS L1 frequency.  Depending on the particular satellite, the SPS signals may also include a PRN CM-code with CNAV data, a PRN CL-code without CNAV data, a PRN I5-code with CNAV data, and/or a PRN Q5-code without CNAV data to support the PVT solution generation process on the GPS L1/L2/L5 frequencies. 

**SPS SIS.** See the definition of _SPS signals_ . 

**Standard Positioning Service (SPS).** The GPS broadcast signals, as defined in IS-GPS-200 and IS-GPS-705, providing constellation performance to peaceful civil, commercial, and scientific users, as established in the _SPS Performance Standard (SPS PS)_ , in accordance with U.S. Government (USG) policy. 

**Terrestrial Service Volume.** One of the two spatial volumes addressed by this _SPS PS_ .  The terrestrial service volume covers the entire surface of the Earth up to an altitude of 3,000 kilometers.  The terrestrial service volume is thus global. 

**Trackable SPS Signal.** An SPS signal that can be preprocessed and categorized as either healthy, marginal, or unhealthy by an SPS receiver. 

**Unalerted Misleading Signal-in-Space Information (UMSI).** The pseudorange data set (e.g., raw pseudorange measurement and NAV data) provided by a SPS SIS provides unalerted MSI (UMSI) when the instantaneous URE exceeds the SIS URE NTE tolerance without a timely alert (alarm or warning) being provided. 

**Usable Satellite.** A satellite that is broadcasting a usable SPS signal. 

Page C-5 

5th Edition

--- [page 188](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=188) ---

GPS SPS PS 

April 2020 

**Usable SPS Signal.** An SPS signal that is trackable and is either healthy or marginal.  A usable SPS signal may be used to form the PVT solution. 

**User Range Accuracy (URA).** The URA is a conservative representation of each satellite's expected RMS URE performance over the curve fit interval represented by the NAV data from which the URA is read.  The URA is a coarse representation of the expected URE statistic, in that it is quantized to the levels represented by the LNAV URA index "N" as defined in IS-GPS-200 or to the levels represented by the CNAV URAED, URANED0, URANED1, and URANED2, indexes as defined in IS-GPS-200 and IS-GPS-705. 

**Warning.** An indication requiring prompt attention (e.g., to preserve integrity). 

Page C-6 

5th Edition

--- [page 189](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=189) ---

GPS SPS PS 

April 2020 

#### **SECTION C.2  Definitions** 

**Accuracy.** Accuracy is defined to be the statistical difference between the estimate or measurement of a quantity and the true value of that quantity.  For the purposes of this _SPS PS_ , the SPS SIS quantities are the pseudorange, the pseudorange rate (velocity), and the pseudorange acceleration (rate rate).  The statistical differences are expressed either as 95<sup>th</sup> percentile (95%) differences or as RMS differences. 

**Availability.** Availability is defined as the percentage of time that the SPS SISs are available to a SPS receiver.  Availability can be expressed in different ways; e.g., on a per-satellite basis or on per-constellation basis. 

**Backward Compatibility.** Backward compatibility is defined as the set of SIS characteristics which: (a) enables existing IS-GPS-200 compliant SF C/A-code receivers to continue operating and obtaining the performance specified in this standard as well as in prior editions of this standard, (b) enables new IS-GPS-200 compliant SF or DF receivers to continue operating and obtaining the performance specified in this standard, and (c) enables new IS-GPS-200 and/or ISGPS-705 compliant SF, DF, or TF receivers to continue operating and obtaining the performance specified in this standard, . 

**Continuity.** Continuity is defined to be the probability that a trackable and healthy SPS SIS will continue to be trackable and healthy without unscheduled interruption over a specified time interval.  SPS SIS continuity is directly related to SPS SIS reliability. 

**Coverage.** The surface area or spatial volume where the SPS SISs are intended to be provided in a manner to meet the specified level of accuracy.  The coverage for the SPS SISs is the terrestrial service volume. 

**Ergodic Period.** The time span containing the minimum number of samples such that the sample statistic is representative of the population statistic.  A common first-order approximation is the minimum time span containing 30 independent random samples. 

**Integrity.** Integrity is a measure of the trust which can be placed in the correctness of the information supplied by the total system.  Integrity includes the ability of the SPS SIS to provide timely alerts (alarms or warnings) to receivers when the SPS SIS should not be used.  SPS SIS integrity is directly related to SPS SIS reliability 

**Reliability.** Reliability is the ability of a SPS SIS to perform its required functions over a specified time interval.  Reliability includes continuity and integrity. 

**UTC(USNO) Accuracy.** The SPS SIS UTC(USNO) time accuracy is defined to be the statistical difference, at the 95<sup>th</sup> percentile, between the parameters contained in the SPS SIS which relate GPS time to UTC as maintained by the USNO and the true value of the difference between GPS time and UTC(USNO).  Also known as the UTC Offset Error (UTCOE). 

Page C-7 

5th Edition

--- [page 190](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=190) ---

GPS SPS PS 

April 2020 

#### **SECTION C.3  Abbreviations and Acronyms** 

###### **- A -** 

A Alongtrack ABAS Aircraft Based Augmentation System ADS-B Automatic Dependent Surveillance – Broadcast AFSPC Air Force Space Command AII Accuracy Improvement Initiative AIV All-In-View (GPS receiver SIS tracking capability) AMCS Alternate Master Control Station AMSI Alerted Misleading Signal-in-Space Information AOD Age of Data (with regards to NAV message data) AOO Area of Operations ArgLat Argument of Latitude (satellite orbital parameter) 

###### **- B -** 

BC Backwards Compatibility bps Bits Per Second BPSK Bi-Phase Shift Key 

###### **- C -** 

C Crosstrack c Speed of light (2.99792458x10<sup>8</sup> m/sec) C/A-code Coarse/Acquisition PRN ranging code modulating the carrier signal at L1 CEI Clock, Ephemeris, Integrity (data set) – LNAV or CNAV CL-code The Civil Long PRN ranging code, which is half of the L2C signal modulating the carrier signal at L2 CM-code The Civil Moderate PRN ranging code which is half of the L2C signal modulating the carrier signal at L2 CNAV Civil Navigation (as in “CNAV data” or "CNAV message") CONUS Continental U.S. cps Chips Per Second CS Control Segment CUT Contingency Upload Threshold CV Constellation Value 

###### **- D -** 

1-D One-Dimensional 2-D Two-Dimensional 3-D Three-Dimensional dBW Decibels with respect to one Watt 

Page C-8 

5th Edition

--- [page 191](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=191) ---

GPS SPS PS 

April 2020 

DF Dual Frequency DFMC Dual-Frequency Multi-Constellation DFSC Dual-Frequency Single-Constellation DGPS Differential GPS DoD Department of Defense DOP Dilution Of Precision DOT Department of Transportation 

###### **- E -** 

EOL End of Life ETA Estimated Time of Arrival EHE Estimated Horizontal Error EPE Estimated Position Error EPU Estimated Position Uncertainty EVE Estimated Vertical Error FAA Federal Aviation Administration FD Fault Detection (see RAIM) FOC Full Operational Capability FOM Figure of Merit FRP _Federal Radionavigation Plan_ (DOT-VNTSC-OST-R-15-01) 

###### **- F -** 

###### **- G -** 

GA Ground Antenna (part of the CS) GBAS Ground-Based Augmentation System GDOP Geometric Dilution Of Precision GEC Groundtrack Equatorial Crossing (satellite orbital parameter) GLAN Geographic Longitude of the Ascending Node (satellite orbital parameter) GNSS Global Navigation Satellite System (GPS is one of many different GNSSs) GPS Global Positioning System (or Navstar Global Positioning System) 

###### **- H -** 

HAL Horizontal Alert Limit (for RAIM) HDOP Horizontal Dilution Of Precision HDOP-AT Horizontal Dilution Of Precision - Availability Threshold (a DOP limit) HMI Hazardously Misleading Information HOW Handover Word (part of the NAV message) HPL Horizontal Protection Level (from RAIM) HSAT Horizontal Service Availability Threshold (an accuracy limit) HUL Horizontal Uncertainty Level (from RAIM) 

Page C-9 

5th Edition

--- [page 192](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=192) ---

GPS SPS PS 

April 2020 

###### **- I -** 

|I5|In-phase PRN ranging code modulating the carrier signal at L5|
|---|---|
|IAURA|Integrity Assured User Range Accuracy|
|ICAO|International Civil Aviation Organization|
|ICD|Interface Control Document|
|IFR|Instrument Flight Rules|
|IMU|Inertial Measurement Unit|
|IOC|Initial Operational Capability|
|IODC|Index of Data Clock (part of the LNAV message)|
|IODE|Index of Data Ephemeris (part of the LNAV message)|
|IS|Interface Specification|
|ISB|Inter-Signal Bias (a characteristic of the SIS)|
|ISC|Inter-Signal Correction (part of the CNAV message)|



###### **- J -** 

JPO Joint Program Office (predecessor of SMC Production Corps and PNT Mission Integration) JSSMO Joint Service System Management Office 

###### **- K -** 

###### **- L -** 

|L1|The SIS centered at the 1575.42 MHz frequency|
|---|---|
|L1C|A future civil signal centered at L1 (not addressed in this_SPS PS_)|
|L2|The SIS centered at the 1227.60 MHz frequency|
|L2C|The civil signal centered at L2|
|L2C-code|The chip-by-chip multiplexed combination of CM-code and CL-code|
|L5|The SIS centered at the 1176.45 MHz frequency|
|L95|95<sup>th</sup>percentile of a Linear distribution (e.g., vertical position error)|
|LNAV|Legacy Navigation (as in “LNAV data” or "LNAV message")|
|LOAN|Launch On Anticipated Need (a philosophy for constellation sustainment)|
|LON|Launch On Need (a philosophy for constellation sustainment)|
|LSB|Least Significant Bit|
|LT|Long Term|
|LTS|Long Term Scheduled (type of outage)|
|LTS|Launch To Sustain (a philosophy for constellation sustainment)|
|LTU|Long Term Unscheduled (type of outage)|



Page C-10 

5th Edition

--- [page 193](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=193) ---

GPS SPS PS 

April 2020 

###### **- M -** 

M-code Encrypted Precise PRN ranging code modulating the carrier signals at L1 and L2 Mcps Mega chips per second MCS Master Control Station (part of the CS) MNAV Military Navigation (as in “MNAV data” or "MNAV message") MS Monitor Station (part of the CS) MSB Most Significant Bit MSI Misleading Signal-in-Space Information MSO Military Standard Order (DoD document) MT Message Type (for CNAV) MT-3x Message Type 30/31/32/33/etcetera (for CNAV) MTBF Mean Time Between Failure MTBLOC Mean Time Between Loss of Continuity 

###### **- N-** 

NANU Notice Advisory to Navstar Users NATO North Atlantic Treaty Organization NAV Navigation (as in “NAV data” or "NAV message", a generic term applying to LNAV, CNAV, and MNAV data and/or LNAV, CNAV, and MNAV messages) NGA National Geospatial-Intelligence Agency NH-code Neuman-Hofman Code NOTAM Notice to Airmen ns Nanosecond NSC Non-Standard Code NSTB National Satellite Test Bed (FAA sponsored) NTE Not To Exceed (i.e., a tolerance limit) NWT No Worse Than 

###### **- O -** 

OCS Operational Control System OCX Next Generation Operational Control System O&M Operations and Maintenance 

###### **- P -** 

P-code Unencrypted Precise PRN ranging code Pconst Probability of multiple satellites being in a common-cause MSI faulted state at a given time PBN Performance Based Navigation PDOP Position Dilution of Precision PDOP-AT Position Dilution of Precision - Availability Threshold (a DOP limit) 

Page C-11 

5th Edition

--- [page 194](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=194) ---

GPS SPS PS 

April 2020 

PNT Positioning, Navigation, and Timing PPS Precise Positioning Service PRN Pseudorandom Noise (a characteristic of the SIS ranging codes) PS Performance Standard (as in _PPS PS_ or _SPS PS_ ) Psat Probability of a satellite being in an MSI faulted state at a given time PSK Phase Shift Key PVT Position, Velocity, and Time P(Y)-code Precise PRN ranging code (unencrypted or encrypted) modulating the carrier signals at L1 and L2 

###### **- Q -** 

Q5 Quadrature-phase PRN ranging code modulating the carrier signal at L5 

###### **- R -** 

R Radial R95 95<sup>th</sup> percentile of a Radial distribution (e.g., horizontal position error) RAAN Right Ascension of the Ascending Node (satellite orbital parameter) RAC Radial-Alongtrack-Crosstrack (orbital coordinate system) RAIM Receiver Autonomous Integrity Monitoring RCM Requirements Correlation Matrix RF Radio Frequency RFI Radio-Frequency Interference RHCP Right-Hand Circularly Polarized RMS Root-Mean-Square RNP Required Navigation Performance RSS Root-Sum-Square 

###### **- S -** 

SA Selective Availability SARPs Standards and Recommended Practices (see ICAO) SAT Service Availability Threshold (an accuracy limit) SBAS Satellite-Based Augmentation System SEM System Effectiveness Model SEP Spherical Error Probable (3-D accuracy, 50<sup><u>th</u></sup> percentile) SF Single Frequency SFSC Single-Frequency Single-Constellation SIS Signal In Space SMC Space and Missile Systems Center 2 SOPS 2<sup>nd</sup> Space Operations Squadron (USSF) SPS Standard Positioning Service sps Symbols Per Second SS Space Segment ST Short Term STS Short Term Scheduled (type of outage) STU Short Term Unscheduled (type of outage) 

Page C-12 

5th Edition

--- [page 195](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=195) ---

GPS SPS PS 

April 2020 

###### SV Space Vehicle (e.g., satellite) 

###### **- T -** 

|TDOP|Time Dilution Of Precision|
|---|---|
|TF|Triple Frequency|
|TFSC|Triple-Frequency Single-Constellation|
|TGD|Group Delay Time correction (for SF receivers)|
|TLM|Telemetry Word (part of the LNAV message)|
|toa|Almanac reference time (part of the LNAV message)|
|top|Propagation time of week (part of the CNAV message)|
|TPL|Time Protection Level (from RAIM)|
|T-S|Time-Space (description of a point)|
|TSO|Technical Standard Order (FAA document)|
|TTA|Time to Alert|
|TT&C|Telemetry, Tracking, and Command|
|TTDOP|Time Transfer Dilution of Precision|
|TUL|Time Uncertainty Level (from RAIM)|



###### **- U -** 

|UE<br>UEE|User Equipment (i.e., GPS receiver, antenna, display system, etcetera)<br>User Equipment Error (pseudorange inaccuracy due to the receiver)|
|---|---|
|UERE|User Equivalent Range Error (total pseudorange inaccuracy)|
|UERRE|User Equivalent Range Rate Error (total pseudorange rate inaccuracy)|
|UHNE|User Horizontal Navigation Error (user horizontalpositionerror)|
|UHVE|User Horizontal Velocity Error|
|UMSI|Unalerted Misleading Signal-in-Space Information|
|UNE|User Navigation Error (user 3-Dpositionerror)|
|URA|User Range Accuracy (a parameter in the NAV messages)|
|URAE|User Range Acceleration Error (total pseudorange acceleration inaccuracy)|
|URE|User Range Error (pseudorange inaccuracy due to the SIS)|
|URRE|User Range Rate Error (pseudorange velocity inaccuracy due to the SIS)|
|U.S.|United States (of America)|
|U.S.C.|United States Code (U.S. law)|
|USAF|U.S. Air Force|
|USG|U.S. Government|
|USNO|U.S. Naval Observatory|
|USSF|U.S. Space Force|
|UTC|Coordinated Universal Time (the acronym comes from the French)|
|UTCOE|UTC(USNO) Offset Error (relative to GPS time)|
|UTE|User Time Error (relative to GPS time)|
|UUTCE|User UTC(USNO) Error|
|UVNE|User Vertical Navigation Error (user verticalpositionerror)|
|UVVE|User Vertical Velocity Error|



###### **- V -** 

Page C-13 

5th Edition

--- [page 196](../../corpus/A/A8_GPS_SPS_Performance_Standard_5th_ed_2020.pdf#page=196) ---

GPS SPS PS 

April 2020 

VDOP Vertical Dilution Of Precision VDOP-AT Vertical Dilution Of Precision - Availability Threshold (a DOP limit) VPL Vertical Protection Level (from RAIM) VSAT Vertical Service Availability Threshold (an accuracy limit) VUL Vertical Uncertainty Level (from RAIM) 

###### **- W -** 

WGS 84 World Geodetic System 1984 WNa Almanac reference week (part of the LNAV message) 

**- X -** 

###### **- Y -** 

Y-code Encrypted Precise PRN ranging code modulating the carrier signals at L1 and L2 

###### **- Z -** 

ZAOD Zero Age Of Data (a categorization of error or accuracy) 

Page C-14 

5th Edition
