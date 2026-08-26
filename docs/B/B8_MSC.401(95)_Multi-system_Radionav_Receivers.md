<!-- source: corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf -->
<!-- source_sha256: 5462f7317a4ab37f1ff4b08856c1f6ad1438b5cb5745c2a2221f54ceaf4af6ea -->
<!-- source_bytes: 643779 -->
<!-- source_pdf_link: ../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf -->
<!-- extractor: pymupdf4llm 1.28.2 / PyMuPDF 1.28.2 -->
<!-- pages: 9 -->
<!-- extracted_chars: 18278 -->
<!-- generated: 2026-08-26T22:06:22Z by tools/build_docs.py -->

--- [page 1](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=1) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS

--- [page 2](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=2) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 1</u> 

# **ANNEX 17** 

# **RESOLUTION MSC.401(95) (Adopted on 8 June 2015)** 

# **PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS** 

THE MARITIME SAFETY COMMITTEE, 

RECALLING Article 28(b) of the Convention on the International Maritime Organization concerning the functions of the Committee, 

RECALLING ALSO resolution A.886(21), by which the Assembly resolved that the functions of adopting performance standards for radio and navigational equipment, as well as amendments thereto, should be performed by the Maritime Safety Committee on behalf of the Organization, 

RECOGNIZING the need for performance standards for multi-system shipborne radionavigation receiver equipment in order to ensure that ships are provided with resilient position-fixing equipment suitable for use with available radionavigation systems throughout their voyage, 

TAKING INTO ACCOUNT present performance standards for shipborne radionavigation receivers as laid down in resolutions MSC.112(73), MSC.113(73), MSC.114(73), MSC.115(73), MSC.233(82) and MSC.379(93), 

HAVING CONSIDERED the recommendation made by the Sub-Committee on Navigation, Communications and Search and Rescue at its second regular session, 

1 ADOPTS the Performance standards for multi-system shipborne radionavigation receivers, the text of which is set out in the annex to the present resolution; and 

2 RECOMMENDS Governments to ensure that multi-system shipborne radionavigation receivers installed on or after 31 December 2017, conform to performance standards not inferior to those specified in the annex to the present resolution. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 3](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=3) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 2</u> 

ANNEX 

# **PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS** 

# **1 INTRODUCTION** 

1.1 Global Navigation Satellite Systems (GNSS), some of which are currently recognized as components of the World-Wide Radio Navigation System (WWRNS) by the Organization, are space-based systems that provide World-wide Position, Velocity and Time (PVT) determination services. Each GNSS space segment is composed of up to 30 satellites per constellation, which may be deployed in several orbital planes and orbit types. The spacing of satellites in orbit is normally arranged such that a minimum of four satellites will be in view to users, World-wide. Each satellite transmits signals that can be processed by receiver equipment to establish a three-dimensional position with a Position Dilution Of Precision (PDOP)  6 or Horizontal Dilution Of Precision (HDOP)  4, to ensure that the position information can be reliably used for navigation purposes. 

1.2 Terrestrial radionavigation systems use signals from ground-based transmitting stations to determine PVT information. Signals received from at least three stations should be processed by receiver equipment to establish a two-dimensional position. 

1.3 Augmentation systems use ground-based or space-based transmitters to provide augmentation data to improve accuracy and integrity for specific service areas (such as navigation in harbour entrances, harbour approaches and coastal waters). 

1.4 The introduction of multi-system shipborne navigation receiver performance standards will allow the combined use of current and future radionavigation as well as augmentation systems for the provision of position, velocity and time data within the maritime navigation system. 

1.5 A multi-system receiver using navigation signals from two or more GNSS, with or without augmentation, provides improved position, velocity, and time data. An improved resistance to intentional and unintentional radio frequency interference is achieved when two or more independent or frequency diverse radionavigation systems are used. Such a combined approach also provides redundancy to mitigate the loss of a single system. 

1.6 Receiver equipment, capable of combining measurements from multiple GNSS and an optional terrestrial radionavigation system, with or without augmentation, to form a single resilient PVT solution, can be used for navigation purposes on ships of speeds not exceeding 70 knots. Such equipment should, in addition to the general provisions contained in resolution A.694(17)<sup>1</sup> , comply with the minimum performance standards as stated in this document. 

1.7 It is the intention of these performance standards to define the minimum requirements, without defining the approach taken. 

1.8 The multi-system shipborne radionavigation receiver determines, as a minimum, the position, course over ground (COG), speed over ground (SOG) and timing either for navigation purposes or as input to other shipboard functions. This information should be available during static and dynamic operations. 

> 1 Refer to Publication IEC 60945. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 4](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=4) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 3</u> 

1.9 The performance standards allow the application of different methods and techniques for the provision of PVT data and related integrity information. Where guidelines dealing with the harmonized provision of PNT data as well as integrity monitoring of PNT system in use and provided data products have been approved by the Organization, these should be applied. 

# **2 RECEIVER EQUIPMENT (MODULE A)** 

- 2.1 The term "multi-system shipborne radionavigation receiver equipment" (hereafter referred to as "the equipment") as used in these performance standards includes all the components and units necessary for the system to properly perform its intended functions. The equipment should include the following minimum components and capabilities: 

   - .1 antennas capable of receiving all radionavigation signals required to support the functionality of the receiver equipment; 

   - .2 receiver(s) and processor(s) capable of processing the radionavigation signals required to support the functionality of the receiver equipment; 

   - .3 means of accessing the computed PVT information (e.g. display of latitude, longitude, COG, SOG, time, sources; and the phase(s) of navigation currently supported<sup>2</sup> ); 

   - .4 interface for supplying data controlling/ configuring the receiver; 

   - .5 display; 

   - .6 raw data output, for the provision of additional information, such as range measurements and GNSS's navigation data; 

   - .7 indication of the quality and reliability of the computed and distributed PVT data to the user; and 

   - .8 indication of radionavigation system(s) currently used for the PVT information to the user. 

2.2 The design of the antennas should be suitable for fitting at a position(s) on the ship which provides a satisfactory environment for the reception of all required radionavigation signals. Multi-path and electromagnetic compatibility (EMC) effects should be taken into consideration. 

- 2.3 The equipment should be designed to: 

   - .1 mitigate interference from authorized out-of-band sources; and 

   - .2 provide a means of: 

      - .1 integrity monitoring for each PVT source employed (e.g. RAIM, CAIM)<sup>3</sup> ; and 

      - .2 multi-source autonomous integrity monitoring<sup>4</sup> . 

> 2 The requirements for the different phases of navigation are set out in resolutions A.915(22) and A.1046(27). 

> 3 Resolution A.915(22). 

> 4 Multi-source integrity monitoring is envisioned to be a cross-check between independent PVT sources. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 5](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=5) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 4</u> 

# **3 OPERATIONAL AND FUNCTIONAL REQUIREMENTS (MODULE B)** 

The equipment should: 

- 3.1 Operate using civil access navigation signals of at least two independent GNSS recognized by the Organization as part of WWRNS, provided in the radionavigation satellite service (space-to-Earth) frequency bands designated in article 5 of the Radio Regulations<sup>5</sup> ; 

- 3.2 Provide PVT data with the necessary level of resilience and integrity, whether it is used directly as input to other equipment, or provided for use within Integrated Navigation Systems (INS); 

- 3.3 Where terrestrial radionavigation system(s) signals are provided and used in the protected frequency bands, have the possibility to operate using terrestrial radionavigation system(s) signals provided in the protected frequency bands; 

- 3.4 Have the facilities to process augmentation data, in accordance with the appropriate methods<sup>6</sup> ; 

- 3.5 Provide the facility for the user to select or deselect radionavigation and augmentation signals; 

- 3.6 Be capable of processing the above signals and combining to provide a single PVT solution, including: 

   - .1 position information of the consistent common reference point<sup>7</sup> in latitude and longitude, referenced to an implementation of an International Terrestrial Reference Frame (ITRF)<sup>8</sup> , with coordinates in degrees and minutes to a precision reflective of the accuracy of the position information, up to four (4) decimal places; 

   - .2 COG of the consistent common reference point<sup>7</sup> in degrees to a precision reflective of the accuracy of the calculated course information, relative to true north, up to one decimal place; 

   - .3 SOG of the consistent common reference point<sup>7</sup> in knots to a precision reflective of the accuracy of the calculated speed information, up to two decimal places; and 

   - .4 time, referenced to UTC (BIPM<sup>9</sup> ), to one tenth of one second; 

> 5 "Radio Regulations" means the Radio regulations annexed to, or regarded as being annexed to, the most recent Convention of the International Telecommunication Union which is in force at any time. 

> 6 e.g. Recommendation ITU-R M.823, RTCM 10410, or other relevant standards , already existing or still to be developed in particular for Satellite Based Augmentation System (SBAS) adoption. 

> 7 A single consistent common reference point for all spatially related information. For consistency the recommended reference location should be the conning position, according to the resolution MSC 252(83). 

> 8 For example, the World Geodetic System 1984(WGS 84) used by GPS, Earth Parameters 1990 (from Russian "Parametry Zemli" 1990) (PZ-90) used by GLONASS, the Galileo Terrestrial Reference Frame (GTRF) or the China Geodetic Coordination System (CGCS2000) used by BDS. 

> 9 Bureau International de Poids et Mesures. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 6](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=6) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 5</u> 

- 3.7 Be capable of providing the PVT solution to the required accuracy<sup>10</sup> within: 

   - .1 5 min where there is no valid satellite almanac data (cold start); 

   - .2 1 min where there is valid satellite almanac data (warm start); and 

   - .3 2 min, when subjected to a power interruption or loss of signals of < 60 s; 

- 3.8 Provide time in UTC; 

- 3.9 Be capable of meeting the requirements for the phases of navigation outlined in resolution A.1046(27); 

3.10 Be capable of generating a new PVT solution at least once every 0.5 s for high-speed craft (HSC) in compliance with speed requirements as in paragraph 1.6 above and at least once every 1 s for conventional vessels; 

3.11 Be capable of assessing whether the performance of the PVT solution (e.g. accuracy and integrity) meets the requirements for each phase of navigation<sup>11</sup> . An _alert_ should be provided when such assessment cannot be determined; 

- 3.12 Provide a caution if after 2 s for HSC or 3 s for conventional vessels, equipment is unable to assess the current achieved performance (e.g. accuracy and integrity) with respect to each navigation phase; 

3.13 Provide a warning, if after 5 s for HSC or 7 s for conventional vessels, new PVT data has not been calculated. Under such conditions the last known position and the time of last valid fix, with the explicit indication of the state so that no ambiguity can exist, should be output until normal operation is resumed; 

3.14 If it is not possible to provide a new position update at the next scheduled update, output the last plausible position, SOG, COG, and the time of the last valid fix, with indication of this state so that no ambiguity can exist, until position update is resumed; 

- 3.15 Provide an indication of augmentation status, including: 

   - .1 the receipt of augmentation signals; 

   - .2 the validity of the signals received; 

   - .3 whether augmentation is applied to the position in the PVT solution; and 

   - .4 the identification of the augmentation signal(s); 

- 3.16 Provide the following information, in alphanumerical form, for the final PVT solution and for each individual source when requested, to a local display (or a separate interfaced display): 

   - .1 position; 

   - .2 COG and SOG; 

   - .3 time; 

   - .4 the PVT solution source(s); 

> 10 Resolution A.1046(27). 

> 11 Resolution A.1046(27). 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 7](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=7) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 6</u> 

- .5 the assessment of the navigation phase(s) for which performance requirements are supported; 

- .6 the identification of the augmentation signal(s) applied to the position solution; and 

- .7 any alert information. 

# **4 INTERFACING AND INTEGRATION (MODULE C)** 

The equipment should: 

- 4.1 Provide the following interfaces in accordance with the relevant international standards:<sup>12</sup> 

   - .1 at least one interface from which the PVT solution should be available in the WGS 84 (i.e. including position information, COG, SOG, time, PVT source(s) (available and used), assessment of phase(s) of navigation for which performance requirements are met, and augmentation information) can be provided. Means may be provided for transforming the computed position based upon WGS 84 into data compatible with the datum of the navigational chart in use; 

   - .2 at least one interface from which data from all available sources can be provided (e.g. to an Integrated Navigation System (INS) for enhanced assessment of PVT information which should be available in WGS 84); 

   - .3 an interface for _alert_ management (i.e. with the Bridge Alert Management (BAM); and 

   - .4 facilities to accept the input of augmentation signals from at least one source;<sup>13</sup> 

- 4.2 Be capable of operating satisfactorily under normal interference conditions, consistent with the requirements of resolution A.694(17)<sup>14</sup> , and taking into account the typical electromagnetic and radio frequency spectrum environment on board and from outside a vessel; 

4.3 Ensure that no permanent damage can result from an accidental short circuit or grounding of the antenna or any of its input or output connections or any of the inputs or outputs. 

# **5 DOCUMENTATION (MODULE D)** 

Documentation for the equipment should be provided, preferably in an electronic format, and should include: 

- 5.1 Operating manuals, which should contain an overall function description including: 

   - .1 the multi-system concept and the benefits and limitations of using GNSS and terrestrial radionavigation systems and augmentation (i.e. as source(s) for the PVT solution); 

> 12 Refer to Publication IEC 61162. 

> 13 Recommendation ITU-R M.823. 

> 14 

> Refer to resolution A.694(17) and IEC 60945. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 8](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=8) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS 

MSC 95/22/Add.2 Annex 17, <u>page 7</u> 

   - .2 a statement on which GNSS and terrestrial radionavigation systems and augmentation(s) are supported (i.e. as sources for the PVT solution); 

   - .3 a statement on which navigation phase(s) are supported and by which PVT source(s); 

   - .4 user guidance for receiver adjustments necessary to achieve the navigation phase requirements; 

   - .5 an explanation of the method used for the applied indicators and thresholds; .6 an explanation of the fusion process and input selection for multiple systems; and 

   - .7 a description of possible failures and their effects on the receiver equipment; 

- 5.2 Installation manuals, which should contain: 

   - .1 details of the components and the interconnections between them; 

   - .2 details of interfaces and connections for data input/output, and interconnection diagrams; 

   - .3 configuration options and commissioning instructions; 

   - .4 power supply and earthing arrangements; and 

   - .5 recommendations on the physical layout of equipment, including antenna mounting requirements and necessary space for installation and maintenance; 

- 5.3 Familiarization material, which should explain all configurations, functions, limitations, controls, displays, alerts, indications and standard operator checks of the equipment; 

- 5.4 A failure analysis,<sup>15</sup> at the functional level, which should verify that the equipment is designed using safe design principles and ensuring that the equipment includes "fail-to-safe" actions. The failure analysis should consider the impact of all failure modes (e.g. those caused by electrical, component, radiofrequency interference or jamming, etc.); and 

- 5.5 Information which should support maintenance of the equipment. 

*** 

> 15 Publication IEC 60812. 

I:\MSC\95\MSC 95-22-Add.2.docx

--- [page 9](../../corpus/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.pdf#page=9) ---

RESOLUTION MSC.401(95) (Adopted on 8 June 2015) PERFORMANCE STANDARDS FOR MULTI-SYSTEM SHIPBORNE RADIONAVIGATION RECEIVERS
