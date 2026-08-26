<!-- source: corpus/C/C2_NIST_IR_8323r1.pdf -->
<!-- source_sha256: 3e047ea2ff737f6cff94ea7942a738ed49358b5d706ecd86dc23e3d1f2700e97 -->
<!-- source_bytes: 2059140 -->
<!-- source_pdf_link: ../../corpus/C/C2_NIST_IR_8323r1.pdf -->
<!-- extractor: pymupdf4llm 1.28.2 / PyMuPDF 1.28.2 -->
<!-- pages: 132 -->
<!-- extracted_chars: 284471 -->
<!-- generated: 2026-08-26T22:07:26Z by tools/build_docs.py -->

--- [page 1](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=1) ---

# **NIST Internal Report NIST IR 8323r1 Foundational PNT Profile: Applying the Cybersecurity Framework for the Responsible Use of Positioning, Navigation, and Timing (PNT) Services** 

Michael Bartock Joseph Brule Ya-Shian Li-Baboud Suzanne Lightman James McCarthy Karri Meldorf Karen Reczek Doug Northrip Arthur Scholz Theresa Suloway 

This publication is available free of charge from: https://doi.org/10.6028/NIST.IR.8323r1

--- [page 2](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=2) ---

## **NIST Internal Report NIST IR 8323r1 Foundational PNT Profile: Applying the Cybersecurity Framework for the Responsible Use of Positioning, Navigation, and Timing (PNT) Services** 

Michael Bartock Suzanne Lightman _Computer Security Division Information Technology Laboratory_ 

Ya-Shian Li-Baboud _Software Systems Division Information Technology Laboratory_ 

James McCarthy _Applied Cybersecurity Division Information Technology Laboratory_ 

Karen Reczek _Standards Coordination Office Laboratory Programs_ 

Joseph Brule Karri Meldorf Doug Northrip Arthur Scholz Theresa Suloway _The MITRE Corporation_ 

This publication is available free of charge from: https://doi.org/10.6028/NIST.IR.8323r1 

### January 2023 



U.S. Department of Commerce _Gina M. Raimondo, Secretary_ 

National Institute of Standards and Technology _Laurie E. Locascio, NIST Director and Under Secretary of Commerce for Standards and Technology_

--- [page 3](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=3) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

Certain commercial entities, equipment, or materials may be identified in this document in order to describe an experimental procedure or concept adequately. Such identification is not intended to imply recommendation or endorsement by the National Institute of Standards and Technology (NIST), nor is it intended to imply that the entities, materials, or equipment are necessarily the best available for the purpose. 

There may be references in this publication to other publications currently under development by NIST in accordance with its assigned statutory responsibilities. The information in this publication, including concepts and methodologies, may be used by federal agencies even before the completion of such companion publications. Thus, until each publication is completed, current requirements, guidelines, and procedures, where they exist, remain operative. For planning and transition purposes, federal agencies may wish to closely follow the development of these new publications by NIST. 

Organizations are encouraged to review all draft publications during public comment periods and provide feedback to NIST. Many NIST cybersecurity publications, other than the ones noted above, are available at <u>https://csrc.nist.gov/publications.</u> 

#### **NIST Technical Series Policies** 

<u>Copyright, Use, and Licensing Statements NIST Technical Series Publication Identifier Syntax</u> 

#### **Publication History** 

Approved by the NIST Editorial Review Board on 2023-01-20 Supersedes NIST IR 8323 (February 2021) https://doi.org/10.6028/NIST.IR.8323 

#### **How to Cite this NIST Technical Series Publication:** 

Bartock M, Lightman S, Li-Baboud YS, McCarthy J, Reczek K, Brule J, Meldorf K, Northrip D, Scholz A, Suloway T (2023) Foundational PNT Profile: Applying the Cybersecurity Framework for the Responsible Use of Positioning, Navigation, and Timing (PNT) Services. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Internal Report (IR) NIST IR 8323r1. https://doi.org/10.6028/NIST.IR.8323r1 

#### **Author ORCID iDs** 

Michael Bartock: 0000-0003-0875-4555 Suzanne Lightman: 0000-0002-50007-3887 James McCarthy: 0000-0002-5559-733X Ya-Shian Li-Baboud: 0000-0003-3234-4345 Karen Reczek: 0000-0002-0174-9019 Joseph Brule: <mark>0000-0002-7987-6050</mark> Karri Meldorf: 0000-0003-3617-3846 

#### **Contact Information** 

<u>pnt-eo@list.nist.gov</u> 

National Institute of Standards and Technology Attn: Applied Cybersecurity Division, Information Technology Laboratory 100 Bureau Drive (Mail Stop 2000) Gaithersburg, MD 20899-2000 

#### **All comments are subject to release under the Freedom of Information Act (FOIA).** 

i

--- [page 4](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=4) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Abstract** 

The national and economic security of the United States (U.S.) is dependent upon the reliable functioning of the nation’s critical infrastructure. Positioning, Navigation, and Timing (PNT) services are widely deployed throughout this infrastructure. In a government-wide effort to mitigate the potential impacts of a PNT disruption or manipulation, Executive Order (EO) 13905, _Strengthening National Resilience Through Responsible Use of Positioning, Navigation and Timing Services_ , was issued on February 12, 2020. The National Institute of Standards and Technology (NIST), as part of the Department of Commerce (DoC), produced this voluntary PNT Profile in response to _Sec.4 Implementation (a),_ as detailed in the EO. The PNT Profile was created by using the NIST Cybersecurity Framework and can be used as part of a risk management program to help organizations manage risks to systems, networks, and assets that use PNT services. The PNT Profile is intended to be broadly applicable and can serve as a foundation for the development of sector-specific guidance. This PNT Profile provides a flexible framework for users of PNT to manage risks when forming and using PNT signals and data, which are susceptible to disruptions and manipulations that can be natural, manufactured, intentional, or unintentional. 

### **Keywords** 

Critical infrastructure; Cybersecurity Framework; Executive Order; GPS; GNSS; navigation; PNT; positioning; risk management; timing. 

### **Reports on Computer Systems Technology** 

The Information Technology Laboratory (ITL) at the National Institute of Standards and Technology (NIST) promotes the U.S. economy and public welfare by providing technical leadership for the Nation’s measurement and standards infrastructure. ITL develops tests, test methods, reference data, proof of concept implementations, and technical analyses to advance the development and productive use of information technology. ITL’s responsibilities include the development of management, administrative, technical, and physical standards and guidelines for the cost-effective security and privacy of other than national security-related information in federal information systems. 

### **Supplemental Content** 

Any potential updates for this document that are not yet published in an errata update or revision—including additional issues and potential corrections—will be posted as they are identified; see the NIST IR 8323r1 publication details. 

ii

--- [page 5](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=5) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Patent Disclosure Notice** 

NOTICE: ITL has requested that holders of patent claims whose use may be required for compliance with the guidance or requirements of this publication disclose such patent claims to ITL. However, holders of patents are not obligated to respond to ITL calls for patents and ITL has not undertaken a patent search in order to identify which, if any, patents may apply to this publication. 

As of the date of publication and following call(s) for the identification of patent claims whose use may be required for compliance with the guidance or requirements of this publication, no such patent claims have been identified to ITL. 

No representation is made or implied by ITL that licenses are not required to avoid patent infringement in the use of this publication. 

iii

--- [page 6](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=6) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Table of Contents** 

|**Executiv**|**e Summary ................................................................................................................. 1**|
|---|---|
|**Intr**|**oduction ...................................................................................................................... 2**|
||Purpose and Objectives .............................................................................................. 2|
||Scope ......................................................................................................................... 2|
||Audience .................................................................................................................... 3|
|**Inte**|**nded Use ..................................................................................................................... 5**|
|**Ove**|**rview ........................................................................................................................... 6**|
||Risk Management Overview ....................................................................................... 6|
||Cybersecurity Framework Overview ........................................................................... 6|
|**The**|**PNT Profile ................................................................................................................10**|
||Identify Function ........................................................................................................14|
|4.1.1.|Asset Management Category ................................................................................15|
|4.1.2.|Business Environment Category ...........................................................................19|
|4.1.3.|Governance Category ...........................................................................................22|
|4.1.4.|Risk Assessment Category ...................................................................................24|
|4.1.5.|Risk Management Strategy ...................................................................................29|
|4.1.6.|Supply Chain Risk Management Category ............................................................30|
||Protect Function ........................................................................................................32|
|4.2.1.|Access Control Category ......................................................................................33|
|4.2.2.|Awareness and Training Category ........................................................................37|
|4.2.3.|Data Security Category .........................................................................................38|
|4.2.4.|Information Protection Processes and Procedures Category ................................42|
|4.2.5.|Maintenance Category ..........................................................................................48|
|4.2.6.|Protective Technology Category ...........................................................................50|
||Detect Function .........................................................................................................53|
|4.3.1.|Anomalies and Events Category ...........................................................................53|
|4.3.2.|Security Continuous Monitoring Category .............................................................56|
|4.3.3.|Detection Processes Category ..............................................................................61|
||Respond Function .....................................................................................................63|
|4.4.1.|Response Planning Category ...............................................................................64|
|4.4.2.|Communications Category ....................................................................................65|
|4.4.3.|Analysis Category .................................................................................................67|
|4.4.4.|Mitigation Category ...............................................................................................69|
|4.4.5.|Improvements Category ........................................................................................71|
||Recover Function ......................................................................................................72|



iv

--- [page 7](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=7) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|4.5.1.<br>Re|covery Planning Category ................................................................................73|
|---|---|
|4.5.2.<br>Im|provements Category ........................................................................................74|
|4.5.3.<br>Co|mmunications Category ....................................................................................75|
|**References ....**|**..........................................................................................................................77**|
|**Appendix A.**|**Selected Bibliography ................................................................................91**|
|**Appendix B.**|**List of Symbols, Abbreviations, and Acronyms .......................................97**|
|**Appendix C.**|**Glossary .................................................................................................... 101**|
|**Appendix D.**|**Applying the PNT Profile to Cybersecurity Risk Management .............. 109**|
|**Appendix E.**|**Organization-Specific PNT Profiles ......................................................... 117**|
|**Appendix F.**|**Change Log ............................................................................................... 119**|



### **List of Tables** 

|**Table 1.**Cybersecurity Framework Functions and Categories ................................................... 8|
|---|
|**Table 2.**Mapping the EO Implementation Guidance to the Cybersecurity Framework Profile ...11|
|**Table 3.**Identify – Asset Management Subcategories Applicable to PNT .................................15|
|**Table 4.**Business Environment Subcategories Applicable to PNT............................................19|
|**Table 5.**Governance Subcategory Applicable to PNT ..............................................................22|
|**Table 6**. Risk Assessment Subcategories Applicable to PNT ....................................................24|
|**Table 7.**Risk Management Strategy Subcategories Applicable to PNT ....................................29|
|**Table 8.**Supply Chain Risk Assessment Subcategory Applicable to PNT ................................30|
|**Table 9.**Protect Access Control Categories Applicable to PNT ................................................33|
|**Table 10.**Awareness and Training Subcategory Applicable to PNT .........................................37|
|**Table 11.**Data Security Subcategories Applicable to PNT .......................................................38|
|**Table 12.**Information Protection Processes and Procedures Applicable to PNT ......................42|
|**Table 13.**Maintenance Subcategories Applicable to PNT ........................................................48|
|**Table 14.**Protective Technology Subcategories Applicable to PNT ..........................................50|
|**Table 15.**Anomalies and Events Subcategories Applicable to PNT ..........................................53|
|**Table 16.**Security Continuous Monitoring Subcategories Applicable to PNT ............................56|
|**Table 17.**Detection Processes Applicable to PNT ....................................................................61|
|**Table 18.**Response Planning Subcategory Applicable to PNT .................................................64|
|**Table 19.**Communications Subcategories Applicable to PNT ..................................................65|
|**Table 20.**Analysis - Subcategories Applicable to PNT .............................................................67|
|**Table 21.**Mitigation Subcategories Applicable to PNT ..............................................................69|
|**Table 22.**Respond - Improvements Subcategories Applicable to PNT .....................................71|
|**Table 23.**Recovery Planning Subcategory Applicable to PNT ..................................................73|
|**Table 24.**Recover - Improvements Subcategories Applicable to PNT ......................................74|
|**Table 25.**Communications Subcategories Applicable to PNT ..................................................75|
|**Table 26.**Applying the PNT Profile to User Risk Management ............................................... 110|
|**Table 27.**Change Log ............................................................................................................ 119|



### **List of Figures** 

**Fig. 1.** Example of How the PNT Profile Applies to GNSS ......................................................... 3 **Fig. 2.** Cybersecurity Framework Subcategory Example ............................................................ 9 **Fig. 3.** PNT Profile Creation Process ........................................................................................10 **Fig. 4.** Components of the PNT Profile .....................................................................................13 

v

--- [page 8](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=8) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Acknowledgments** 

The authors wish to thank all individuals and organizations, that provided special contribution to the creation of this document: Michael Striffolino, Department of Homeland Security (DHS) Cybersecurity and Infrastructure Security Agency (CISA), Mary Beth Perry, DHS CISA Associate, and John Fischer, Orolia. 

The authors also acknowledge the contributions of Thelma Allen, Lisa Carnahan, Amber Crutchfield, Katya Delak, Elizabeth Donley, James Foti, Jonathan Hardis, Judah Levine, Michael Lombardi, Kristina Rigopoulos, Matthew Scholl, Kevin Stine, James St. Pierre, and Isabel Van Wyk, National Institute of Standards and Technology (NIST); Michael Calabro, Booz Allen Hamilton; Michael Lewis, Chevron; James Platt, DHS CISA; Ernest Wong, DHS Science and Technology Directorate (S&T); Gerry Trevino of JBSA 5G Next Gen; Betsy Barron, Robin Drake, Jason Kuruvilla (former employee), and Thomas Walters, MITRE; David Howard, U.S. Department of Energy (DOE); and Karen Van Dyke, U.S. Department of Transportation (DOT). 

vi

--- [page 9](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=9) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Executive Summary** 

Executive Order 13905, Strengthening National Resilience Through Responsible Use of Positioning, Navigation, and Timing (PNT) Services, was issued on February 12, 2020 [EO- <u>13905]. It seeks to protect the national and economic security of the United States from the</u> disruption or manipulation of systems that form or use PNT data and information vital to the functioning of U.S. critical infrastructure and technology-based industries. The Executive Order (EO) directs the Department of Commerce to develop a PNT Profile that will address the four components of responsible use of PNT, as stated in the EO: 

1. Identify systems that use or form PNT data. 

2. Identify PNT data sources. 

3. Detect disruption and manipulation of the systems that form or use PNT services and data. 

4. Manage risk regarding responsible use of these systems. 

The PNT Profile provides a flexible framework for users of PNT services to manage risks when forming or using PNT signals or data, which are susceptible to disruptions and manipulations that can be natural, manufactured, intentional, or unintentional. It was created by applying the NIST Cybersecurity Framework (CSF) [NIST-CSF] and can be applied to all organizations that use PNT services, irrespective of the level of familiarity or knowledge that they have with the NIST CSF. Organizations that have fully or partially adopted, or who have not adopted the NIST CSF can benefit. 

The PNT Profile is voluntary and does not: constitute regulations, define mandatory practices, provide a checklist for compliance, or carry statutory authority. It is intended to be a foundational set of guidelines. Sector-specific agencies (SSAs) and entities may wish to augment or further develop their own PNT cybersecurity efforts via full or partial implementation of the recommended practices in this document. Any implementation of its recommendations will not necessarily protect organizations from all PNT disruption or manipulation. Each organization is encouraged to make their risk management decisions in the context of their own cyber ecosystem, architecture, and components. The PNT Profile’s strategic focus is to supplement preexisting resilience measures and elevate the postures of less mature initiatives. 

1

--- [page 10](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=10) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Introduction** 

Executive Order 13905 (EO 13905), _Strengthening National Resilience through Responsible Use of Positioning, Navigation, and Timing Services_ , was issued on February 12, 2020 [EO-13905]. It seeks to help organizations protect themselves from disruption or manipulation of positioning, navigation, and timing (PNT) services, particularly those organizations whose use of PNT services is vital to the functioning of U.S. critical infrastructure. EO 13905 directs the Department of Commerce to develop a PNT Profile for users of PNT services. 



### **Purpose and Objectives** 

The PNT Profile is designed to be used as part of a risk management program in order to help organizations manage risks to systems, networks, and assets that use PNT services. The PNT Profile provides guidance for establishing risk management approaches to achieve the desired outcomes commensurate with acceptable and responsible levels of risk that result from the disruption or manipulation of PNT data. The PNT Profile is not intended to serve as a solution or compliance checklist that would guarantee the responsible use of PNT services. 

Use of the PNT Profile will help organizations: 

- Identify systems that use PNT services and determine their operating and performance requirements; 

- Identify sources of PNT data; 

- Identify known and anticipated threats to PNT services, equipment, and data; 

- Protect systems that are dependent on PNT services by adhering to basic principles of responsible use; 

- Detect disruptions and manipulation of PNT services and data; 

- Address risk in the management and use of PNT services and data; 

- Respond to PNT service or data anomalies in a timely, effective, and resilient manner; and, 

- Recover from PNT service or data anomalies in a timely, effective, and resilient manner. 



### **Scope** 

The PNT Profile’s scope includes systems that use PNT services, including systems that consume and then rebroadcast PNT data for consumption by other organizational entities where a PNT service is defined as “any system, network, or capability that provides a reference to calculate or augment the calculation of longitude, latitude, altitude, or transmission of time or frequency data, or any combination thereof” [EO-13905]. PNT service providers include government systems, such as Global Positioning Systems (GPS), public NIST Network Time Protocol (NTP) servers, commercial services, and internal systems. The PNT Profile’s scope does not include source PNT signal generators and providers (e.g., a Global Navigation Satellite System (GNSS) control segment or space segment, as shown in Fig. 1). 

PNT services interface with PNT systems and components operated by an organization to produce PNT data, which can take the form of position, navigation, or timing information. Responsible use of PNT services requires the stakeholder to identify the dependencies of PNT 

2

--- [page 11](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=11) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

data (within their components, sub-systems, and systems), evaluate the impact should the disruption or manipulation of PNT data be realized, and manage the residual risk. 

This PNT Profile defines the responsible use of PNT services as it relates to critical infrastructure and national and economic security. In this case, responsible use by organizations includes incorporation of: 

- Risk-informed management of PNT services; 

- Risk-based approaches that minimize the potential effects of the disruption or manipulation of PNT services and data; and 

- Deliberate planning and action regarding the secure management of PNT services. 



**Fig. 1.** Example of How the PNT Profile Applies to GNSS 

The PNT Profile addresses systems and components operated by an organization to produce PNT data, which can take the form of position, navigation, or timing information. The provider (in this example, the GNSS space and ground segments) is not within the scope of the PNT Profile. 

For the purposes of the PNT Profile, PNT data include all information used by PNT equipment to form PNT solutions. This includes but is not limited to signals, waveforms, network packets, and other means to transmit PNT information. 



### **Audience** 

This document’s intended audience includes: 

- Public and private organizations that use PNT services; 

- Managers responsible for the use of PNT services; 

3

--- [page 12](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=12) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

- Risk managers, cybersecurity professionals, and others with a role in risk management for systems that use PNT services; 

- Procurement officials responsible for acquisition of PNT services; 

- Mission and business process owners responsible for achieving operational outcomes dependent on PNT services; and 

- Researchers and analysts who study systems that rely on PNT and/or study the unique cybersecurity needs of PNT services. 

The PNT Profile is intended for a general audience and is broadly applicable. The PNT Profile applies to organizations that: 

- Have already adopted the NIST Cybersecurity Framework (CSF) to help identify, assess, and manage cybersecurity risks [NIST-CSF]; 

- Are familiar with the NIST CSF and want to improve their risk postures; or 

- Are unfamiliar with the NIST CSF but need to implement risk management frameworks for the responsible use of their PNT services. 

4

--- [page 13](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=13) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Intended Use** 

The PNT Profile is a flexible tool that can be used by an organization to help meet mission and business objectives that are dependent upon the use of PNT services. The PNT Profile can also help organizations determine risks based on their assessments of potential impacts of manipulation or disruption of PNT services to business and operational objectives. The PNT Profile is intended to help users of PNT services prioritize necessary cybersecurity activities based on business objectives. Additionally, the PNT Profile can be used to help organizations identify areas where standards, practices, and other guidance could help manage risks to systems that use PNT services. An organization can use the PNT Profile in conjunction with its systematic process for identifying, assessing, and managing risk. NIST acknowledges the existing efforts being undertaken by individual entities to address the responsible use of PNT services in their sectors. The PNT Profile is intended to complement, but not replace these efforts. 

NIST also encourages the development of sector-specific guidance if more specific risk management efforts may be required. Organizations within various sectors can customize the PNT Profile by considering the following: 

- What processes and assets require PNT data (direct recipients of PNT services)? 

- What processes and assets are dependent on other assets that require PNT data (i.e., what are the secondary effects)? 

- What processes and assets are vulnerable to the disruption or manipulation of PNT services? 

- What are the integrity and availability thresholds of PNT to avoid mission impact? 

- What safeguards are available? 

- What is the impact to the organization should a process or asset be lost or degraded? 

- What techniques can be used to detect events of concern? 

- What techniques can be used to respond to events of concern? 

- What techniques can be used to recover pre-event capabilities? 

5

--- [page 14](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=14) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Overview** 



### **Risk Management Overview** 

Risk management is the ongoing process of identifying, assessing, and responding to risk as related to an organization’s mission objectives. To manage risk, organizations should understand the likelihood that an event will occur as well as its potential impacts. An organization should also consider statutory and policy requirements that may influence or inform cybersecurity decisions. 

The PNT Profile supports and is informed by cybersecurity risk management processes. Using the PNT Profile, organizations can make more informed decisions, based on business needs and risk assessments, to select and prioritize cybersecurity activities and expenditures that help identify systems dependent on PNT, identify appropriate PNT sources, detect disturbances and manipulation of PNT services, manage the risk to these systems, and promote resiliency. 

The PNT Profile provides a flexible approach for users of PNT to manage risks when forming and using PNT signals and data regardless of the source of the risk, including natural events, malicious actions, and human activities that have unintended consequences. It also provides a starting point from which organizations can customize their approach to manage risk to their PNT services and data. A customized approach provides the most appropriate measures, processes, and prioritization of resources for reliable and efficient functioning of critical infrastructure applications. 

Organizations can use the PNT Profile in conjunction with existing risk management processes. The PNT Profile assumes that the organization implements cybersecurity risk management processes, and this profile is intended to provide additional risk management considerations specific to PNT. Examples of cybersecurity risk management processes include International Organization for Standardization (ISO) 31000:2018, ISO/International Electrotechnical Commission (IEC) 27005:2018, and NIST Special Publication 800-39. A list of additional resources is included in Appendix A of the PNT Profile. 



### **Cybersecurity Framework Overview** 

Created through collaboration between industry and government, the Cybersecurity Framework <u>[NIST-CSF] provides prioritized, flexible, risk-based, and voluntary guidance based on existing</u> standards, guidelines, and practices to help organizations better understand, manage, and communicate cybersecurity risks. Although it was designed for organizations that are part of the U.S. critical infrastructure, many other organizations in the private and public sectors (including federal agencies) use the NIST Cybersecurity Framework. 

6

--- [page 15](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=15) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

The NIST Cybersecurity Framework consists of three main components:<sup><u>1</u></sup> 

1. The Framework Core provides a catalog of desired cybersecurity activities and outcomes<sup><u>2</u></sup> using common language. The Core guides organizations in managing and reducing their cybersecurity risks in a way that complements an organization’s existing cybersecurity and risk management processes. 

2. The Framework Implementation Tiers provide context for how an organization views cybersecurity risk management. The Tiers help organizations understand whether they have a functioning and repeatable cybersecurity risk management process and the extent to which cybersecurity risk management is integrated with broader organizational risk management decisions. 

3. The Framework Profiles are customized to the outcomes of the Core to align with an organization’s requirements. Profiles are primarily used to identify and prioritize opportunities for improving cybersecurity at an organization. 

The Framework Core presents standards, guidelines, and practices within five concurrent and continuous functions, which are described below. In the context of this “PNT Profile”, a “cybersecurity event” refers to a potential for the disruption or manipulation of PNT services. 

1. Identify: Develop the organizational understanding to manage cybersecurity risk to systems, assets, data, and capabilities. The activities in the Identify function are foundational to the effective use of the NIST Cybersecurity Framework, enabling an organization to focus and prioritize its efforts in a manner consistent with its risk management strategy and business needs. 

2. Protect: Develop and implement the appropriate safeguards to ensure the delivery of critical infrastructure services. The activities in the Protect function support the ability to limit or contain the impact of a potential PNT cybersecurity event. 

3. Detect: Develop and implement the appropriate activities to identify the occurrence of a cybersecurity event. The activities in the Detect function enable timely discovery of PNT cybersecurity events. 

4. Respond: Develop and implement the appropriate activities to take action regarding a detected cybersecurity event. The activities in the Respond function support the ability to contain the impact of a potential PNT cybersecurity event. 

5. Recover: Develop and implement the appropriate activities to maintain plans for resilience and to restore any capabilities or services that were impaired due to a cybersecurity event. The activities in the Recover function support timely recovery to normal operations to reduce the impact of a PNT cybersecurity event. 

When considered together, these functions provide a high-level, strategic view of the life cycle of an organization’s management of PNT cybersecurity risk. The Framework Core then identifies 

> 1 Elements of the Cybersecurity Framework—including Core, Implementation Tiers, Profile, Function, Category, and Subcategory—are normally capitalized and will be capitalized throughout this document. 

> 2 The word “outcomes” is used because the Cybersecurity Framework (CSF) focuses on the “what” rather than the “how”. In other words, the emphasis is on the cybersecurity outcomes that the organization wants to achieve rather than how they will achieve it. The References described on page 8 help organizations with the “how”. 

7

--- [page 16](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=16) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

underlying Categories and Subcategories for each Function. The 108 Subcategories are discrete cybersecurity outcomes that are organized into 23 Categories like “Asset Management” or “Protective Technology”. Table 1 shows the Five Functions and 23 Categories of the Core. 

**Table 1.** Cybersecurity Framework Functions and Categories 

|**Function**<br>**Unique**<br>**Identifier**|**Function**|**Category**<br>**Unique**<br>**Identifier**|**Category**|
|---|---|---|---|
|||ID.AM|Asset Management|
|||ID.BE|Business Environment|
|**ID**|Identify|ID.GV|Governance|
|||ID.RA|Risk Assessment|
|||ID.RM|Risk Management Strategy|
|||ID.SC|Supply Chain Risk Management|
|||PR.AC|Access Control|
|||PR.AT|Awareness and Training|
|**PR**|Protect|PR.DS|Data Security|
|||PR.IP|Information Protection Processes and Procedures|
|||PR.MA|Maintenance|
|||PR.PT|Protective Technology|
|||DE.AE|Anomalies and Events|
|**DE**|Detect|DE.CM|Security Continuous Monitoring|
|||DE.DP|Detection Processes|
|||RS.RP|Response Planning|
|||RS.CO|Communications|
|**RS**|Respond|RS.AN|Analysis|
|||RS.MI|Mitigation|
|||RS.IM|Improvements|
|||RC.RP|Recovery Planning|
|**RC**|Recover|RC.IM<br>RC.CO|Improvements<br>Communications|



**References** are existing standards, guidelines, and practices that provide practical guidance to help an organization achieve the desired outcome of each Subcategory. An example of two 

8

--- [page 17](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=17) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

Subcategories and applicable References within the Asset Management Category are shown in **Fig. 2** . 



**Fig. 2.** Cybersecurity Framework Subcategory Example 

The Subcategory outcomes are organized according to Functions and Categories and are not prioritized within the Core. Each organization has unique requirements, risk tolerance, and resources. Therefore, the prioritization of the Subcategory outcomes will vary from one organization to the next. 

The PNT Profile in Section 4 can be used as a foundation for building a custom profile, as shown in **Fig. 3** . A custom profile can be built using the business objectives, threat environment, requirements, and controls as inputs. The outcomes associated with a custom profile based on the PNT Profile are the outcomes from the Executive Order: identification of systems dependent on PNT services that identify appropriate PNT services, detect disruption and manipulation of PNT services, and manage the risk to those systems. 

9

--- [page 18](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=18) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



**Fig. 3.** PNT Profile Creation Process 

Since organizations within the PNT community sector or sub-sector share many of the same business objectives and regulatory requirements, creation of a high-level profile can provide a common starting point. The PNT Profile can make it easier for organizations to begin incorporating cybersecurity and can also be used to provide a baseline of cybersecurity for organizations within a sector or sub-sector. Individual organizations can further customize a profile by taking the sector/sub-sector profile and then tailor or augment it to address requirements, business objectives, or environmental threats unique to them. 

The PNT Profile is intended to be implemented within the larger context of an organization that is developing and executing its own cybersecurity program.<sup><u>3</u></sup> That program should be based on organizational cybersecurity risk management policies and procedures. This PNT Profile is best implemented if a cybersecurity program is in place at the organizational level. However, this caveat does not preclude any organization from implementing the PNT Profile should a cybersecurity program not be in place. 



### **The PNT Profile** 

This section was created by using the Cybersecurity Framework, as described in Sec. 3.2. The tables summarize the Subcategories for a Function and a Category. The references provided in the tables include cybersecurity guidance, PNT-specific guidance, and illustrative methods to implement the guidance. It is not intended to be a comprehensive list of all PNT references (see <u>References), but a sample of potentially relevant resources depending on the PNT service(s) the</u> 

> 3 See IEC 62443 2-1, ISO/IEC 27001 (security management), and NIST SP 800-39. 

10

--- [page 19](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=19) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

organizations use and their PNT service and data requirements. The references that correspond to the Subcategory may not necessarily apply to all sectors. The Categories and Subcategories defined by the Cybersecurity Framework will address different aspects of the four components identified in the Executive Order, as illustrated in Table 2. Sections 4.1 through 4.5 provide insight on how the Subcategories address the responsible use of PNT. Note: Not all Subcategories in the NIST CSF are listed here; only those most applicable to this PNT Profile are included. Acronyms described in the PNT Profile are listed in Appendix B. 

**Table 2.** Mapping the EO Implementation Guidance to the Cybersecurity Framework Profile 

|||**Identify systems**<br>**dependent on**<br>**PNT services**|**Identify**<br>**appropriate PNT**<br>**sources**|**Detect**<br>**disturbance or**<br>**manipulation of**<br>**PNT services**|**Manage the risk**<br>**to PNT systems**|
|---|---|---|---|---|---|
||Asset Management|**X**|**X**|**X**|**X**|
||Business Environment|**X**|**X**|**X**|**X**|
||Governance|**X**||||
|**IDENTIFY**|Risk Assessment|**X**|**X**|**X**|**X**|
||Risk Management|**X**|**X**|**X**|**X**|
||Supply Chain Risk<br>Management|**X**||**X**|**X**|
||Access Control|**X**|**X**|**X**|**X**|
||Awareness And Training|**X**||||
||Data Security|**X**|**X**|**X**|**X**|
|**PROTECT**|Information Protection<br>Processes and Procedures|**X**|**X**||**X**|
||Maintenance|**X**|**X**|**X**|**X**|
||Protective Technology||**X**|**X**|**X**|
||Anomalies and Events|**X**||**X**|**X**|
|**DETECT**|Security Continuous<br>Monitoring|**X**|**X**|**X**|**X**|
||Detection Process|**X**||**X**|**X**|



11

--- [page 20](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=20) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|||**Identify systems**<br>**dependent on**<br>**PNT services**|**Identify**<br>**appropriate PNT**<br>**sources**|**Detect**<br>**disturbance or**<br>**manipulation of**<br>**PNT services**|**Manage the risk**<br>**to PNT systems**|
|---|---|---|---|---|---|
||Response Planning||||**X**|
||Communications|**X**|||**X**|
|**RESPOND**|Analysis|||**X**|**X**|
||Mitigation|||**X**|**X**|
||Improvements||||**X**|
||Recovery Planning|**X**||**X**|**X**|
|**RECOVER**|Improvements|**X**||**X**|**X**|
||Communications|**X**||**X**|**X**|



The Executive Order defines four components, and the NIST CSF defines a set of Functions and Categories. The PNT Profile maps the components of the Executive Order to the NIST CSF. It is important to note that there are interdependencies between the NIST CSF Functions, and that each component of the Executive Order will require multiple Functions, Categories, and Subcategories. 

Successful implementations require a comprehensive approach. The CSF Functions and guidance in the PNT Profile address the generic needs of PNT users in critical infrastructure that depend on PNT services to meet their business objectives. The components of the Foundational PNT Profile are concisely summarized in **Fig. 4** . In order to support a risk-based, practical, and effective approach to the responsible use of PNT, organizations can select, tailor, and augment the security controls defined in PNT references in Sec. 4.1 through Sec. 4.5. 

12

--- [page 21](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=21) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



**Fig. 4.** Components of the PNT Profile 

13

--- [page 22](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=22) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Identify Function** 

The Identify function is foundational to the risk assessment process. It is highly recommended that those who intend to implement all or part of the PNT Profile start with the Identify function. An organization needs to analyze its mission objectives related to its reliance on PNT data. 

The Identify function provides key activities that should be given strong consideration in this analysis. Consideration of the organization’s mission and business objectives, threat environment, assets, and vulnerabilities will have a significant influence on the overall risk; these are directly addressed in the other four CSF functions (i.e., Protect, Detect, Respond, Recover). 

The objectives of the Identify function include: 

- Identify the business or operational environment and organization’s purpose; 

- Identify all assets, including applications dependent on PNT data; 

- Identify sources and infrastructure that provide PNT information; and 

- Identify the vulnerabilities, threats, and impacts should the threat be realized in order to assess the risk. 

The Identify function within the NIST Cybersecurity Framework defines six categories, all of which have at least one Subcategory that applies to the PNT Profile to varying degrees, as summarized in <u>Sec. 4.1.1 through Sec. 4.1.6.</u> 

14

--- [page 23](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=23) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.1. Asset Management Category** 

The data, personnel, devices, systems, and facilities that enable the organization to achieve its business objectives are identified and managed in a manner that is consistent with their importance to organizational objectives and the organization’s risk strategy. In the context of the PNT Profile, the assets that require and support PNT services in order to fulfill the organization’s mission and business objectives are identified. 

There are five Subcategories within Asset Management that apply to the PNT Profile, as summarized in the table below. 

**Table 3.** Identify – Asset Management Subcategories Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Asset Management**|||
|**Subcategory**|||
|**AM-1:**<br>Physical devices and systems<br>within the organization are<br>inventoried.|Document and maintain an inventory of the PNT system<br>components that reflect the current system. The physical inventory<br>should include PNT system components used to support critical<br>infrastructure/operations and critical system components that rely on<br>PNT data and services to properly function.<br>PNT system components may include GNSS receivers, wireless<br>local area network (WLAN) receivers, terrestrial beacon system<br>receivers (TBS), radio navigation or timing antennas, network<br>switches, Internet of Things (IoT)/ Supervisory Control and Data<br>Acquisition (SCADA) devices, NTP and Precision Time Protocol<br>(PTP) servers, positioning sensors, clocks, etc.<br>Cryptographic modules, test and measurement equipment,<br>navigation systems, etc., are examples of hardware and devices<br>dependent on PNT services.<br>Incorporate a configuration management tool that documents<br>locations of all PNT antennas and verify with physical inspections.<br>During physical inspections, identify equipment associated with<br>PNT devices and locate PNT service provider interfaces, such as|<br>**3GPP TS**36.305 4.3<br>**DHS CISA**1.a, 2.a<br>**ICAO 9849**1.4<br>**IEEE 1588**6, 9, 10<br>**IEEE 802.1AS**7, 11<br>**IEEE 2030.101**4.6, 4.7, 4.8, 4.9<br>**NIST SP 800-53 Rev. 5**CM-8, CM-9 PM-5<br>**NIST SP 800-160 Rev. 1**2.3|



15

--- [page 24](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=24) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Asset Management**<br>**Subcategory**|||
||GNSS antennas.||
|**AM-2:**<br>Software platforms and<br>applications within the<br>organization are inventoried.|The software inventory should include PNT system components<br>used to support critical infrastructure/operations and critical<br>applications that rely on PNT data and services to properly function.<br>Document and maintain an inventory of PNT system software<br>components, such as software license information, software version<br>numbers, human-machine interface (HMI), and other industrial<br>control systems (ICS) component applications, software, and<br>operating systems. System software inventory is reviewed and<br>updated as defined by the organization.<br>Identify all software, applications, and systems that are dependent<br>on PNT data, including software that relies on distributed time,<br>using phase and frequency synchronization methods. These methods<br>may include packet-based communication protocols (e.g., NTP,<br>PTP), frequency protocols using the physical layer network (e.g.,<br>Synchronous Ethernet (SyncE)), or physical signals (e.g., 10 MHz, 1<br>PPS, Inter-range instrumentation group time code B (IRIG-B)).<br>Applications dependent on PNT data may include test and<br>measurement tools, kernels, databases, logging software,<br>cryptography/certificate management, and other software that rely<br>on synchronized clocks or positioning information to verify<br>information consistency. Some functions, such as multilateration,<br>are also sensitive to timing performance and should, therefore, be<br>inventoried.|<br> <br>**3GPP TS**36.305 4.3<br>**DHS CISA**1.a, 1.b, 1.c, 2.a<br>**DHS PNT**Appendix C<br>**ICAO 9849**1.4, 5.1.4<br>**IEEE 1588**5-14, Annex A, P<br>**IEEE 802.1AS**7, 10<br>**IEEE 2030.101**4.3<br>**IETF 5905**5-15<br>**IETF 7384**5, 7<br>**IMO 1575**Appendix C<br>**ITU-T G.8261**6, 7, Annex A, P<br>**NIST SP 800-53 Rev. 5**CM-8, PM-5|
|**AM-3:**|Identify all connections within the PNT system, as well as between|**DHS CISA**1, 2|



16

--- [page 25](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=25) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Asset Management**<br>**Subcategory**|||
|Organizational communication<br>and data flows are mapped.|the PNT system and other systems. All connections and signal<br>interfaces are documented, authorized, and reviewed.<br>Connection information may include the physical interface<br>characteristics, logical interface characteristics, data characteristics,<br>ports, port configurations, protocols, addresses, description of the<br>data, security requirements, and nature of the connection.<br>Identify the PNT data source and distribution medium for the<br>applications and systems that meets the PNT data performance and<br>resilience requirements needed. It is critical to know where each<br>system derives PNT data from. For example, the organization may<br>want to investigate software programs that can help its organization<br>identify PNT data sources to assess which sources are most<br>beneficial to organizational mission stability.|**GPS IS-200**3<br>**GPS IS-705**3<br>**GPS IS-800**3<br>**GPS SPS**B.1.2, B.1.3, 14<br>**IEEE 802.1AS**7.4, 8.5<br>**IEEE 1588**8-12<br>**IEEE 2030.101**4.2 IEC 61850-90-4 10<br>**IETF 5905**5-14<br>**IMO 1575**A-D, Appendix C<br>**ITU-T G.8261**6|
||For each software that provisions or uses PNT data, identify the<br>input and output data interfaces.|**ITU-T G.8262**6-12, Appendix III<br>**ITU-T G.8272**6-12|
|||**NIST SP 800-53 Rev. 5**AC-4, CA-3, CA- 9,<br>PL-8, SA-17|
|||**RTCA** **326**3.1.1|
|||**GAL ICD**<br>**BDS ICD**|
|**AM-4:**|Identify and catalogue all external connections for the PNT system.|**DHS CISA**3|
|External information systems<br>are catalogued.|Identify all PNT signals, data sources, and related data products that<br>pertain to an event or the status of the PNT source.<br>Examples of external systems include engineering design services<br>and those that are controlled under separate authority, personal|**GPS USER**<br>**NIST SP 800-53 Rev. 5**AC-20, PM-5, SA- 9<br>**USG FRP**Appendix B|



17

--- [page 26](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=26) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Asset Management**<br>**Subcategory**|||
||devices, and other hosted services.||
|**AM-5:**<br>Resources (e.g., hardware,<br>devices, data, time, personnel,<br>and software) are prioritized<br>based on their classification,<br>criticality, and business value.|Determine required resources to support current regulations and<br>standards requirements for the responsible use of PNT systems.<br>Provide adequate staffing with the appropriate training such that<br>PNT support is available in a timely manner (consistent with<br>thresholds defined in the organization’s business plan). Formalize<br>PNT roles provide a process for transitioning staff members (with<br>PNT expertise) to be replaced. The remaining staff members are<br>provided with necessary resources and PNT training.<br>Identify and prioritize PNT system components, processors, and<br>functions based on their classification, criticality, and business<br>value.<br>Identify the types of information in the organization’s possession,<br>custody, or control for which security safeguards are needed (e.g.,<br>sensitive or protected information).<br>Stakeholders are advised to use other functions within the CSF to<br>inform identification procedures. For example, while testing<br>business continuity procedures, use the findings of a lost PNT<br>source to identify which aspects of the mission were impacted and to<br>what degree, and reprioritize accordingly.<br>When identifying resources and prioritizing trade-offs for PNT<br>systems, holistically consider requirements, such as availability,<br>continuity, data integrity, timeliness of anomaly detection, response,<br>and recovery.|**3GPP TS22.071**4<br>**DHS CISA**3<br>**ISO/IEC/IEEE**15939:2017 6.3.2.3<br>**NIST SP 800-37**3<br>**NIST SP 800-53 Rev. 5**AC-20, RA-9<br>**USG FRP**Appendix B|



18

--- [page 27](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=27) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.2. Business Environment Category** 

The organization’s mission, objectives, stakeholders, and activities are understood and prioritized. This information is used to inform cybersecurity roles, responsibilities, and risk management decisions. In the context of this PNT Profile, identify includes activities that are facilitated by or require PNT services in order to fulfill the organization’s mission, objectives, or other stakeholders’ needs. There are four Subcategories within Business Environment that apply to the PNT Profile, as summarized in the table below. 

**Table 4.** Business Environment Subcategories Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Business Environment**|||
|**Subcategory**|||
|**BE-1:**<br>The organization’s role in the<br>supply chain is identified and<br>communicated.|Organizations that engage in the reception and rebroadcast of PNT<br>(or otherwise supply PNT) services to their consumers need to<br>understand the cascading effects of a disruption or manipulation of<br>PNT services to customers that may be a part of the critical<br>infrastructure relying on the PNT service.|**DHS S&T 2022**<br>**ISO 27001**<br>**NIST SP 800-37**<br>**NIST SP 800-53 Rev. 5**CP-2, SR-3, SR-4|
|**BE-2:**<br>The organization’s place in<br>critical infrastructure and its<br>industry sector is identified and<br>communicated.|Critical infrastructure owner/operators need to understand and<br>communicate the effects of a disruption or manipulation of PNT<br>services on the organization’s ability to fulfill its mission,<br>objectives, or other stakeholders’ needs.<br>Distribution of PNT data may rely on critical infrastructures such as<br>power and communications sectors. For example, the accuracy of<br>time and frequency transfer over fiber are sensitive to reflections,<br>and users can benefit from fiber maintenance techniques that<br>minimize reflections.|**DHS S&T 2022**<br>**NIST SP 800-53 Rev. 5**PM-11, RA-9<br>**NIST TN 2187**II.A.1|



19

--- [page 28](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=28) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Business Environment**|||
|**Subcategory**|||
|**BE-4:**<br>Dependencies and critical<br>functions for the delivery of<br>critical services are established.|Identify and prioritize internal critical business services that are<br>dependent on PNT system processes and components.<br>Identify any consumers and their requirements that rely on the<br>organization’s products or services whose delivery or production is<br>derived from or relies upon PNT data.|**DHS CISA**3.a, 3.b, 3.c<br>**GPS**2, 3, 4, 5<br>**GPS SPS**3<br>**IEEE** **2030.101**4.4-4.7|
||Recognize that different users and applications may have different<br>requirements.|**NIST SP 800-53 Rev. 5**CP-8, PE-9, PE-11,<br>PM-8, RA-9|
||Identify and prioritize supporting services for critical PNT system<br>processes and components.<br>For organizations that form PNT data, understand PNT data<br>performance, the resilience levels of the service provided, and<br>customer dependencies on PNT data.<br>The organization’s infrastructure, such as network communication<br>architectures and protocols, can impact recovery time in the event of<br>a path or node failure.|**USG FRP**4, 6|



20

--- [page 29](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=29) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Business Environment**|||
|**Subcategory**|||
|**BE-5:**<br>Resilience requirements to<br>support the delivery of critical<br>services are established for all<br>operating states (e.g., under<br>duress or attack, during<br>recovery, normal operations.)|Consider and prioritize requirements in the context of safety,<br>operational criticality, cost, and other resource availability.<br>Identify performance levels of PNT data regardless of<br>environmental threats or if applications can rely on alternatives<br>without the PNT data (systems/components).<br>Identify PNT data traceability requirements and reconcile with the<br>PNT data performance (e.g., accuracy, integrity, continuity,<br>availability, coverage) for the software, applications, systems, and<br>operating environment.<br>Where applicable and practical, identify network performance<br>parameters at the device’s ingress and egress ports, static and<br>dynamic delays between nodes, and end-to-end delay characteristics<br>for the distribution of PNT data.<br>Resiliency requirements permit an organization to determine if the<br>full capability of its current PNT service provider is needed. For<br>example, if relative time synchronization or frequency<br>synchronization is sufficient, then an organization may have more<br>complementary holdover reference options.<br>PNT applications requiring only a relative frame of reference may<br>have additional resilience capabilities using local sensors, signals of<br>opportunity, computations, and communications.|**3GPP TS 22.878**4, 5<br>**DHS CISA**6<br>**DHS PNT**III-V<br>**DHS RCF**5-7<br>**GPS SPS**3<br>**IEC 61850-90-4**14.2.4<br>**IEEE 1588**12.2<br>**IETF 8633**3.2, 3.3<br>**ITU-T G.8262**11<br>**ITU-T G.8272**7<br>**ITU-T G.8275.1**Appendices I, II<br>**NIST SP 800-53 Rev. 5**CP-2, CP-11, RA-9,<br>SA-8<br>**RTCA 229**2.1.1.4, 2.1.2.3- 2.1.2.6, 2.1.3.3-<br>2.1.3.6, 2.1.4.3- 2.1.4.7, 2.1.5.3 -2.1.5.7,<br>2.2.1.1, 2.2.1.2-2.2.1.6<br>**RTCA 235**14.2, 14.3, 14.4<br>**USG FRP**1.7, 6|



21

--- [page 30](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=30) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.3. Governance Category** 

The policies, procedures, and processes to manage and monitor the organization’s regulatory, legal, risk, environmental, and operational requirements are understood and inform the management of cybersecurity risk. In the context of this PNT Profile, identify the legal, risk, environmental, and operational requirements that are enabled or impacted using PNT services. There is one Subcategory within Governance that applies to the PNT Profile, as summarized in the table below. 

**Table 5.** Governance Subcategory Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Governance**|||
|**Subcategory**|||
|**GV-4:**<br>Governance and risk<br>management processes address<br>cybersecurity risks.|Develop a comprehensive strategy to manage risk to PNT-<br>dependent operations. Include cybersecurity considerations in the<br>risk management strategy. Review and update the risk management<br>strategy, as necessary.<br>Understand governance structure, including quality assurance and<br>oversight, of PNT sources, applications, and systems using PNT<br>data for critical applications with respect to traceability,<br>performance monitoring, and resilience requirements.<br>Implementations that include complementary or redundant PNT<br>sources need to consider governance and risk implications, such as<br>the interoperability, compatibility, and interchangeability of<br>different sources. Verify that any impacts to the PNT data output are<br>not detrimental to the mission. For example, understand how<br>multiple GNSS constellations with different geodetic reference<br>frames and time scales impact the PNT data output. GPS uses the<br>World Geodetic System 1984 (WGS 84) as the reference frame for<br>positioning, and the GPS time scale is synchronized to UTC(USNO)<br>within 1 μs.<br>Be aware of legally accepted standards and sources. For example,<br>UTC(NIST) and UTC(USNO) are the sources of legal time in the|<br> <br>**BIPM**<br>**Defraigne 2022**3<br>**DHS CISA**2.b, 2.c, 3.a<br>**DOT CMPS**<br>**FCC E911**<br>**FINRA 4590**<br>**GPS GNSS**<br>**GPS IS-200**3.3.4, 20.3.3.4.3.3.1<br>**GPS SPS**<br>**IANA TZDB**<br>**ICAO 9849**1, 6.2, 6.3, 7.2, 7.3, 7.15,<br>7.16<br>**IEEE 2030.101**Annex C<br>**IERS**Bulletin-C<br>**Matsakis 2018**|



22

--- [page 31](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=31) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Governance**|||
|**Subcategory**|||
||U.S.<br>Understand standards that support interoperability for PNT services<br>and national/international coordination to support the performance,<br>standardization, and cost minimization of user equipment.|**NIST SP 800-53 Rev. 5**, PM-3, PM-7, PM9,<br>PM-10, PM-11, PM-28, RA-1, RA- 2, RA-3,<br>SA-2<br>**NIST SP 800-160 Rev. 1**3.3.8|
||Consider the governance and risk implications of using multi-GNSS<br>receivers as well as practical considerations, such as interoperability<br>and interchangeability of the different GNSS constellations for the<br>organization’s applications. Foreign PNT service providers, such as<br>satellite constellations, should only be used in accordance with<br>current federal policy guidance and restrictions.|**NIST USNO**<br>**RTCA 229**1.3.3<br>**RTCA 326**3.1.2<br>**USG FRP**1.7.5 through 1.7.9, 6<br>**USNG**|
|||**USNO GPS**|
|||**GAL ICD**|
|||**BDS ICD**|



23

--- [page 32](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=32) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.4. Risk Assessment Category** 

The organization understands the cybersecurity risk to operations (including mission, functions, image, or reputation), assets, and individuals. In the context of this PNT Profile, the risk to organizational operations in the event of disruption or manipulation to PNT services is the main concern. 

There are five Subcategories within Risk Assessment that apply to the PNT Profile, as summarized in the table below. 

**Table 6** . Risk Assessment Subcategories Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Risk Assessment**|||
|**Subcategory**|||
|**RA-1:**<br>Asset vulnerabilities are<br>identified and documented.|Identify, document, and report vulnerabilities that exist on the<br>PNT system and the system that distributes PNT data. Where<br>safe and feasible, include the use of vulnerability scanning on<br>the PNT system, its components, or a representative system.|**DHS CISA**4.a<br>**DHS GPS CI**<br>**ICAO 9849**5, 7.13|
||Testing and characterization to assess system vulnerabilities are<br>recommended periodically or when there are changes to the<br>threat model, the organization’s reliance on PNT data, or<br>modifications to the PNT equipment.<br>Receiver or system vulnerability testing may include PNT signal<br>simulation to assess susceptibility to disruption or manipulation<br>of the PNT signal. Testing should be conducted in accordance<br>with industry best practices, laws, and regulations as well as<br>within the business continuity constraints defined for the<br>organization.<br>Vulnerabilities for an operational environment may include the<br>susceptibility to atmospheric and scintillation effects on PNT<br>signals, spoofing of unauthenticated signals, or disruptions or<br>manipulations of PNT services.|<br>**IEEE 2030.101**4.12, 4.14, 5<br>**NIST SP 800-53 Rev. 5**CA-2, CA-7, CA-8,<br>PM-15, RA-3, RA-5, SA-5, SA-11, SI-2, SI- 4, SI-5<br>**NTP SEC**<br>**RTCA 229**1.6.2, 2, 2.1.1.1.4, 2.1.1.1.5, 2.4,<br>2.5<br>**RTCA 356**3.8.1, 3.8.2<br>**USG FRP**1.7.3|



24

--- [page 33](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=33) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

### **Identify Applicability to PNT** 

### **References (PNT-Specific)** 

### **Risk Assessment** 

### **Subcategory** 

|**RA-2:**<br>Cyber threat intelligence is|Establish and maintain ongoing contact with security groups and<br>associations to receive security alerts and advisories.|**DOT CGSIC**<br>**DHS CISA**4.a|
|---|---|---|
|received from information-<br>sharing forums and sources.|Security groups and associations may include special interest<br>groups, forums, professional associations, news groups, and peer<br>groups of security professionals in similar organizations.|<br>**ICS-CERT NCCIC**<br>**NERC EISAC**|
||Implement a collaborative threat research and awareness<br>program that includes a cross-organization information- sharing<br>capability. Organizations should consider having both<br>unclassified and classified information-sharing capabilities.|**NTP SEC**<br>**NIST SP 800-53 Rev.**5 PM-15, PM-16<br>**USG FRP**Appendix B|
||The coordination of information is important in building a<br>comprehensive threat assessment indicator of evolving threats in<br>the operating environment, including the geographical and<br>temporal characteristics of the threat.||



25

--- [page 34](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=34) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

### **Identify Applicability to PNT Risk Assessment** 

### **References (PNT-Specific)** 

|**Subcategory**|||
|---|---|---|
|**RA-3:**<br>Threats, both internal and<br>external, are identified and<br>documented.|Threats in an operational environment may include natural,<br>manufactured, intentional, and unintentional disruptions and<br>manipulations, such as radio frequency interference (RFI), denial<br>of service, data manipulation, unpredictable or uncharacteristic<br>delays in the communication of PNT data, or loss of PNT<br>service.<br>The threat assessment should include internal and external<br>parties, user errors, hardware or software errors, compromise,|**DHS CISA IE**<br>**DHS GPS CI**<br>**DIA**<br>**DOT 12464**<br>**DOT CGSIC**<br>**GPS SPS**A.5.4.1|
||failure, network impairments, and environmental conditions.<br>Examples of threats to PNT data availability and integrity<br>include (i) PNT user or component errors or impaired PNT|**ICAO 9849**5.3- 5.5, Appendix F<br>**IETF 7384**3|
||components and communications; (ii) RFI, such as signal<br>blockage, multipath, atmospheric scintillations, and interference<br>from other radio frequency sources; (iii) other environmental|**IETF CMP**6<br>**ITU-T 810**6|
||threats, such as temperature variations, aging, vibrations, and<br>power outages; (iv) hostile attacks, such as jamming, spoofing,<br>High-Altitude Nuclear Detonation, High-Altitude|**ITU-T GNSS**Appendix II, V, VII<br>**Kaplan**9, 10|
||Electromagnetic Pulse, or PNT component or network<br>compromises (e.g., denial of service and delay attacks); and<br>confidentiality, especially when PNT data is bound or associated|<br>**NASIC**<br>**NIST SP 800-37**2|
||with sensitive data.|**NIST SP 800-53 Rev. 5**PM-12, PM16, RA- 3, SI-5|
|||**NIST SP 800-160 Rev. 1**2.3|
|||**NOAA SWS**|
|||**RTCA 235**4-12|
|||**RTCA 292**2-14|
|||**RTCA 326**3.2|
|||**RTCA 356**3.2, 3.3, 3.4, 3.5|



26

--- [page 35](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=35) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Risk Assessment**<br>**Subcategory**|||
|**RA-4:**<br>Potential business impacts and<br>likelihoods are identified.|The likelihood of an attack is a function of the capability and<br>intent of a potential adversary that may be influenced by non-<br>technical factors. For example, a foreign GNSS provider may<br>deny PNT to the U.S. in a time of war or heightened tensions.<br>Foreign satellite constellations should only be used in<br>accordance with current federal policy guidance and restrictions.<br>Identify the potential business impacts of the disruption or<br>manipulation of PNT service. The impact of a realized threat on<br>PNT data performance and resilience may be evaluated in a test<br>or field environment. Consider the impact of both observed and<br>anticipated threats on downstream applications and users, as well<br>as the potential interval of time during which the threat can<br>continue. For each identified threat, include the extent of impact,<br>error manifestation (step or ramp error and rate of ramp),<br>detection thresholds, and error propagation implications on<br>safety and operations.<br>Understand that the vulnerabilities for a system or component<br>may impact dependent systems (i.e., a vulnerability may have<br>impacts beyond the system that was subjected to an exploit).<br>Based on applications’ PNT data performance requirements,<br>identify, characterize, and document the error sources of PNT<br>data where applicable.<br>Documenting PNT measurement uncertainty characteristics in<br>conjunction with the assessed vulnerability exploits is useful in<br>order to assess whether the PNT data meets mission<br>requirements. For example, time signals and data are subject to<br>phase variations due to frequency drift, frequency offset, jitter,<br>wander, and discontinuities. Phase discontinuities can be caused<br>by changes in the time source or in the network topology, where<br>errors in signal regeneration or analog to digital conversion can|<br>**DOT 12464**<br>**IEEE 1139**<br>**IEEE 1193**<br>**NIST SP 1065**3-12<br>**NIST SP 800-53 Rev. 5**CP-2, PM9, PM-11,<br>PM-9, RA-2, RA-3, RA-9<br>**NIST TN 1366**<br>**RTCA 235**2.1,13<br>**RTCA 292**2.3-2.6|



27

--- [page 36](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=36) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

### **Identify Applicability to PNT** 

### **References (PNT-Specific)** 

### **Risk Assessment** 

### **Subcategory** 

||contribute to performance degradation.||
|---|---|---|
|**RA-5:**<br>Threats, vulnerabilities,<br>likelihoods, and impacts are used<br>to assess risk.|Conduct and document periodic assessments of risk to PNT<br>systems that consider the threats, vulnerabilities, the likelihood<br>that the threat will be realized, and the impact (including scale)<br>to operations and assets.|**DHS GPS CI**<br>**ICAO 9849**7.4, 7.5, Appendix F<br>**IETF 7384**3.1-3.3|
||The residual risk should be reassessed on a periodic basis, when<br>there is a substantive change to the system’s vulnerabilities (such<br>as an equipment upgrade), a change in the likelihood of threat<br>realization (such as a time of international tension), a change in<br>the impact should a threat be realized (such as an organization’s<br>increased use or dependency on PNT services), or as a result of<br>lessons learned from recovery actions.<br>The organization’s failure and fault analysis should include all<br>known threats to business processes due to a loss of PNT data<br>assurance for a given operational environment.|**IETF 8633**3-9<br>**IETF 8915**3-9<br>**IETF CMP**<br>**NIST SP 800-53 Rev. 5**CA-2, CA-7, PM- 16, PM-<br>28, RA-2<br>**NIST SP 800-160 Rev. 1**2.3, 2.4<br>**RTCA 235**2.1-2.4, 3, 14<br>**RTCA 326**2.1, 2.2, 3.1- 3.4|
||Estimate the internal, external, environmental, intentional, and<br>unintentional risks to the business or mission based the impact of<br>a PNT disruption or manipulation. Consider the feasibility of<br>continued operations.|<br>**RTCA 356**2.7, 3.5|



28

--- [page 37](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=37) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.5. Risk Management Strategy** 

The organization’s priorities, constraints, risk tolerances, and assumptions are established and used to support operational risk decisions. The risk management strategy takes into consideration and factors all aspects of the organization (to include its reliance on PNT services). The responsible use of PNT (and associated assurance measures) will augment or influence the residual risk, definition of the priorities, identification of constraints, and other aspects of the existing risk management strategy. 

There are two Subcategories in Risk Management that apply to the PNT Profile, as summarized in the table below. 

**Table 7.** Risk Management Strategy Subcategories Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT Specific)**|
|---|---|---|
|**Risk Management**<br>**Strategy**|||
|**Subcategory**|||
|**RM-1:**<br>Risk management processes<br>are established, managed,<br>and agreed to by<br>organizational stakeholders.|Responsible use of PNT services includes the consideration<br>of the acquisition, integration, deployment, operations and<br>maintenance, repair, and replacement of PNT components<br>and services. These considerations include the dependencies<br>on the PNT primary sources and evaluation of the impacts as<br>part of the PNT service acquisitions, systems integration,<br>and deployment.|**ISO 27001**<br>**ISO 15288**6.3.4<br>**ISO 17666**<br>**ISO 16085**6, 7, 8.2, Annex A, B<br>**NIST SP 800-53 Rev. 5**PM-9|
||PNT considerations are identified and then incorporated or<br>integrated into cybersecurity and operational policies.<br>Review and update the risk management strategy, as<br>necessary.|**NIST SP 800-37 Rev. 2**3.1|
|**RM-3:**<br>The organization’s<br>determination of risk<br>tolerance is informed by its<br>role in critical infrastructure<br>and sector specific risk<br>analysis.|The loss or degradation of an organization’s capabilities or<br>function may impact its customers, partners or other<br>stakeholders. Consider and communicate the organization’s<br>risk tolerance to its stakeholders and its impact on critical<br>infrastructure.|**ISO 27001**<br>**NIST SP 800-53 Rev. 5**RA-9, PM-8,<br>PM-9, PM-11|



29

--- [page 38](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=38) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.1.6. Supply Chain Risk Management Category** 

The organization’s priorities, constraints, risk tolerances, and assumptions are established and used to support risk decisions associated with managing supply chain risk. The organization has established and implemented the processes to identify, assess, and manage supply chain risks. In the context of this PNT Profile, identify the PNT service providers in order to assess and manage the risk to the PNT service. 

There is one Subcategory within Supply Chain Risk Management that applies to this PNT Profile, as summarized in the table below. 

**Table 8.** Supply Chain Risk Assessment Subcategory Applicable to PNT 

|**Identify**|**Applicability to PNT**|**References (PNT Specific)**|
|---|---|---|
|<br>**Supply Chain Risk**<br>**Management**|||
|**Subcategory**|||
|**SC-2:**<br>Suppliers and third-party<br>partners of information systems,<br>components, and services are<br>identified, prioritized, and<br>assessed using a cyber supply<br>chain risk assessment process.|Identify any external systems or services that the organization uses<br>for ingesting PNT data.<br>Remain apprised of current and future regulations related to the<br>acquisition of PNT services, sources, and devices forming,<br>transporting, or using PNT data.<br>Identify any external systems or services that the organization is<br>dependent on for its PNT data.<br>In making supply chain decisions on PNT systems, components,<br>and services, considerations may include (i) functional<br>requirements; (ii) any relevant and applicable federal law,<br>regulation, or statutory policy; (iii) the threat environment; (iv)<br>mission-level goals, criticality, and functions; (v) security policies;<br>(vi) organizational policies, vulnerabilities, risks, and risk<br>tolerance; and (vii) the business objectives.<br>Supply chain vulnerabilities include (i) systems and components;<br>(ii) the development and operational environment; and (iii) the<br>logistics or delivery environment that transports systems and<br>components (logically or physically). Consider access paths within<br>the supply chainthat would allow adversaries to gain information|**DHS GPS CI**5<br>**NDAA 889**<br>**NIST SP 800-161**2.2, 3<br>**NIST SP 800-53 Rev. 5**PM-9, RA-3, SR-2,<br>SR-3, SR-5, SR-6<br>**USG FRP**1.7|



30

--- [page 39](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=39) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Identify**|**Applicability to PNT**|**References (PNT Specific)**|
|---|---|---|
|<br>**Supply Chain Risk**<br>**Management**|||
|**Subcategory**|||
||about the PNT system and introduce hardware, software, or<br>firmware that could cause the disruption or manipulation of the<br>PNT data as well as any dependencies that may be easier to<br>subvert.||
||Supply chain threat sources include (i) hostile cyber or physical<br>attacks to either the supply chain or an information system<br>component traversing the supply chain; (ii) human errors; and (iii)<br>geopolitical disruptions, economic upheavals, and natural or<br>manufactured disasters.||
||Likelihood determination of PNT supply chain exploits include (i)<br>threat information and assumptions; (ii) PNT component exposure<br>to external access; (iii) system, process, or component<br>vulnerabilities; and (iv) empirical data on vulnerabilities from<br>system, process, and component test and analysis results.<br>Mission criticality and impact analysis of supply chain<br>vulnerabilities, threats, and likelihood of PNT systems and<br>components can be used to determine the organization’s risk and<br>guide the selection of supply chain security controls.||



31

--- [page 40](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=40) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Protect Function** 

The Protect Function includes development, implementation, and verification measures to prevent the loss of functionality in the case of PNT disruption or manipulation. Additionally, the Protect function enables the response to and recovery from cybersecurity events with planning and preparation activities, while execution of risk mitigation is addressed in the Response and Recovery functions. 

The objectives of the Protect function include: 

- Protect the systems that form, transmit, and use PNT data to support the needed level of integrity, availability, and confidentiality based on application needs. 

- Protect the deployment and use of PNT services through adherence to cybersecurity principles, including understanding the baseline characteristics and application tolerances of the PNT sources, data, and any contextual information; providing sufficient resources; managing the systems development life cycle (SDLC); and deploying needed training, authorizations, and access control. 

- Should a threat be realized, protect users and applications that are dependent on PNT data by enabling them to maintain a sufficient level of operations through verified response and recovery plans. 

- Protect organizations that rely on PNT services and data with respect to business and operational needs. 

The Protect function defines six categories, all of which have at least one Subcategory that applies to this PNT Profile in varying degrees, as summarized in Sec. 4.2.1 through Sec. 4.2.6. 

32

--- [page 41](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=41) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.2.1. Access Control Category** 

Access to physical and logical assets and associated facilities is limited to authorized users, processes, and devices and is managed consistent with the assessed risk of unauthorized access to authorized activities. In the context of this PNT Profile, assets may include GNSS antennas, receivers, servers, and subscriptions, and “physical access” may include radio frequency emanations. 

There are seven Subcategories within Access Control that apply to this PNT Profile, as summarized in the table below. 

**Table 9.** Protect Access Control Categories Applicable to PNT 

|**Protect**<br>**Access Control**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**AC-1:**<br>Identities and credentials are<br>issued, managed, verified,<br>revoked, and audited for<br>authorized devices, users, and<br>processes.|Where applicable, establish and manage identification and<br>authentication credentials of PNT users, data sources, and<br>applications that use PNT data.<br>When warranted, authenticate PNT sources and data to verify PNT<br>data integrity. Authentication can also be used to verify that PNT<br>resources are used by authorized devices, users, and processes.<br>Revoke credentials when the authorization of PNT sources,<br>devices, users, and processes expires or is no longer needed.|**DHS GPS CI**<br>**DHS TFS**3.10, 3.11<br>**IEEE 1588**Annex P 2.1.2<br>**IETF 5906**7, 8, 10<br>**IETF 7384**5.1<br>**IETF 8915**1, 5.2, 5.6, 5.7, 8<br>**NIST SP 800-53 Rev. 5**IA-1, IA-2, IA-3, IA-4,<br>IA-5, IA-7, IA-8, IA-10, IA-11, IA-12|
|**AC-2:**<br>Physical access to assets is<br>managed and protected.|Protect physical access to the PNT equipment and resources.<br>Determine access requirements during emergency situations.<br>Maintain and review visitor access records to the facility where the<br>PNT equipment resides, including antennas.<br>The access and provisioning process may include lists of<br>authorized individuals, identity credentials, escort requirements,<br>guards, fences, turnstiles, locks, and the monitoring of facility<br>access. For example, obscure the visibility of antennas from public|**DHS GPS CI**<br>**NIST SP 800-53 Rev. 5**PE-1, PE-2, PE-3, PE-4,<br>PE-5, PE-6, PE-8, PE-9|



33

--- [page 42](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=42) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Access Control**<br>**Subcategory**|**Applicability to PNT**<br>access, or use decoy antennas.|**References (PNT-Specific)**|
|---|---|---|
|**AC-3:**<br>Remote access is managed.|Establish usage restrictions, connection requirements,<br>implementation guidance, and authorizations for remote access to<br>the systems that use or form PNT data.<br>Consider radio frequency as part of remote access and employ<br>appropriate mitigations at the receiving antennae.<br>Enable secure remote access and management to PNT systems and<br>devices. Compliance to secure standardized network management<br>protocols can facilitate remote network management and<br>monitoring.<br>Ensure safe use of service and management protocols by following<br>security alerts and adhering to latest best practices. Document the<br>use of security capabilities, such as access control lists,<br>authentication, and configuration parameters to reduce the<br>probability of cyberattacks.|**DHS GPS CI**<br>**DHS TFS**3.11<br>**IETF CMP**1, 4, 6<br>**IEEE 1588**Annex P 2.5.3<br>**IETF CMP**3-6<br>**NIST SP 800-53 Rev. 5**AC-1, AC-17, AC- 19,<br>AC-20, SC-15<br>**SNMP3**<br>**SNMPSEC**|
|**AC-4:**<br>Access permissions and<br>authorizations are managed,<br>incorporating the principles of<br>least privilege and separation of<br>duties.|Create access control lists that enforce which authenticated users<br>are authorized to use or perform actions on PNT systems.<br>Enable approved access lists for all controls that follow, such as<br>NTP and PTP time servers, signaling channels, and other PNT<br>systems.<br>Define and manage access permissions for systems that use PNT<br>services. Identify user actions that can be performed on the systems<br>that use or form PNT data without needing to verify identification<br>or authentication (e.g., during emergencies).|**IEEE 1588**Annex P 2.1.2, 2.5.2, 2.5.5<br>**IETF 8633**3.4, 5.1<br>**NIST SP 800-53 Rev. 5**AC-1, AC-2, AC-3,<br>AC5, AC-6, AC-14, AC-16, AC-24<br>**NIST SP 800-160 Rev. 1**Appendix F.1.14|
|**AC-5:**<br>Network integrity is protected|Identify and control connections between system components.<br>Monitor and control connections and communications at the|**DHS CISA**1.a, 4.a<br>**IEEE 1588**Annex P|



34

--- [page 43](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=43) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Protect**<br>**Access Control**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|(e.g., network segregation,<br>network segmentation).|external boundary and at key internal boundaries.<br>Information Assurance (IA) measures to ensure integrity should be<br>considered at the network boundaries and internal controls.<br>Boundary protection mechanisms may include boundary clocks,<br>routers, gateways, unidirectional gateways, data diodes, and<br>separating system components into logically separate networks or<br>subnetworks. Intradomain measures include network segmentation<br>and segregation where appropriate.<br>Consider the isolation of control plane, user plane, and signaling<br>plane where appropriate and practical.|**IETF 5906**6<br>**IETF 7384**5.2<br>**NIST SP 800-53 Rev. 5**AC-4, SC-7, SC-10|
|**AC-6:**<br>Identities are proofed and bound<br>to credentials and asserted in<br>interactions.|Prior to issuing identity credentials and authorizations to form or to<br>use PNT data, determine the identity and any associated contextual<br>information needed about a user, device, or process to establish a<br>satisfactory level of assurance. Contextual information used to<br>proof user or asset identity may include proximity, location,<br>movement, associations, and environmental factors.<br>PNT data sources are validated for authenticity.<br>Clients, applications, and systems are validated for the authorized<br>use of the PNT data or services.<br>Note that the sensitivity (and associated confidentiality<br>requirements) of PNT data may be impacted when bound or<br>associated with other data.|**ATIS-I-0000070**2-7<br>**DHS CISA**2.d<br>**DHS GPS CI**<br>**IEEE 1588**16.14, Annex P<br>**IETF 5906**7, 8-10<br>**NISTIR 8014**4-6<br>**NIST SP 800-53 Rev. 5**AC-1, AC-2, AC-3,<br>AC16, AC-19, AC-24, IA-1, IA-2, IA-4, IA- 5,<br>IA-8, IA-12, PE-2, PS-3|
|**AC-7:**<br>Users, devices, and other assets<br>are authenticated (e.g., single-<br>factor, multi- factor)<br>commensurate with the risk of<br>the transaction (e.g., individuals’|Ensure that PNT devices and equipment use appropriate<br>authentication for the risk associated with downstream operations,<br>which depend on accurate and reliable PNT data. Not all PNT<br>services support authentication, and alternates should be sought<br>when practical and warranted.<br>Users, devices, and assets are authenticated to prevent the|**DHS CISA**2.d, 5.b<br>**DHS GPS CI**<br>**DHS TFS**2.2<br>**IEEE 1588**16.14, Appendix P.2.1, 2.2|



35

--- [page 44](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=44) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Access Control**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|security and privacy risks and<br>other organizational risks).|realization of cyberthreats via remote connections to the PNT data<br>source.<br>Authentication protects data provenance and verifies the<br>authenticity of the data source. Implement source, client, or mutual<br>authentication based on the IA requirements of the organization<br>and be cognizant of the fact that different applications may have<br>different authentication requirements.<br>Understand that implementations may influence message delay and<br>delay variations. Verify that PNT data performance remains within<br>tolerances.|<br>**IETF 4082**2-5<br>**IETF 5906**2-12<br>**IETF 7384**5.1, 5.7<br>**IETF 7822**2-4<br>**IETF 8573**3-7<br>**IETF 8633**5.5, 5.6<br>**IETF 8915**1,4, 5.5, 8.3, 8.4<br>**NIST NTP**<br>**NIST SP 800-53 Rev. 5**AC-14, IA-1, IA-2, IA-3,<br>IA-5, IA-8, IA-9, IA-10, IA-11|



36

--- [page 45](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=45) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.2.2. Awareness and Training Category** 

The organization’s personnel and partners are provided cybersecurity awareness education and trained to perform their cybersecurityrelated duties and responsibilities consistent with related policies, procedures, and agreements. In the context of this PNT Profile, the focus is on privileged users who monitor and maintain equipment that forms, communicates, or uses PNT data. 

There are two Subcategories within Awareness and Training that apply to the PNT Profile, as summarized in the table below. 

**Table 10.** Awareness and Training Subcategory Applicable to PNT 

|**Protect**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Awareness and Training**<br>**Subcategory**|||
|**AT-2:**<br>Privileged users understand their<br>roles and responsibilities.|Determine how to establish what privileged user qualifications are,<br>what training is required to meet those qualifications, and ways to<br>validate that the qualifications have been met.<br>Consider comprehensive training programs for transitioning staff<br>assigned to the business and operational implementation of the<br>organization’s PNT services and applications that are dependent on<br>PNT data.<br>Operators, network and system administrators, and other technical<br>staff are trained to install, test, and maintain PNT systems, as well<br>as to detect and respond to compromised PNT data with respect to<br>the PNT data source and applications or systems that use PNT data.|**DHS CISA**5.a<br>**ICAO 9849**1.3.1, 1.3.4, 7.3, 7.4, 7.5.6,<br>7.6.1<br>**NIST SP 800-53 Rev. 5**AT-3, PM-13<br>**NIST SP 800-160**Appendix E<br>**USG FRP**1.7.8|
|**AT-3:**<br>Third-party stakeholders (e.g.,<br>suppliers, customers, partners)<br>understand their roles and<br>responsibilities.|Identify and communicate user boundaries and responsibilities for<br>monitoring, control, and assuring performance tolerances of PNT<br>data.<br>Owners and operators can include this Subcategory for third party<br>contracting requirements. This can apply to organizations that<br>consume and rebroadcast PNT services and organizations that<br>produce PNT related hardware to the critical infrastructure.|**DHS S&T 2022**<br>**ISO 27001**<br>**NIST SP 800-53 Rev. 5** PS-7, SA-9, SA-16<br>**NIST TN 2187** II.A.4|



37

--- [page 46](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=46) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.2.3. Data Security Category** 

Information and data are managed consistent with the organization’s risk strategy to protect the confidentiality, integrity, and availability of PNT services. In this PNT Profile, the availability and integrity of PNT services are of primary concern throughout the enterprise. PNT data that is bound or associated with personally identifiable information (PII) or other sensitive data increases confidentiality concerns. 

There are seven Subcategories within Data Security that apply to the PNT Profile, as summarized in the table below. 

**Table 11.** Data Security Subcategories Applicable to PNT 

|**Protect**<br>**Data Security**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**DS-1:**<br>Data at rest is protected.|Applications dependent on PNT data, such as location and time<br>stamp to log the position and time of an event, may need to protect<br>against repudiation and alteration. Sensitive information may need<br>to be encrypted.|**GPS ICD-870** 3.3, 3.3.1<br>**IETF CMP** 6<br>**NIST SP 800-37** 3|
||PNT data may be critical for downstream activities, such as<br>analytics and forensics. Apply measures such as access control lists,<br>encryption, and other data-at-rest protections commensurate with<br>the criticality of the activities dependent on PNT.|**NIST SP 800-53 Rev. 5** MP-3, MP-4, MP-6,<br>SC-28|
|**DS-2:**<br>Data in transit is protected.|Use encryption and transmission security in accordance with<br>availability, integrity, and confidentiality requirements. Time<br>protocols may need integrity, authentication, and—for certain use<br>cases—confidentiality protections. Prior to deploying encryption or<br>decryption implementations, understand the implementation’s<br>effects on PNT data communications delay and delay variances.<br>Verify that synchronization precision remains within the specified<br>tolerances.|**IEEE 1588** 16.14, Annex P.2.2.1.3, P.2.2.3<br>**IETF 7384** 5.1-5.3, 5.7-5.9<br>**IETF 8915** 1, 3-9<br>**IETF NTS** 1-10<br>**NIST SP 800-53 Rev. 5** SC-8, SC-11, SC- 12|



38

--- [page 47](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=47) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Data Security**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**DS-3:**<br>Assets are formally managed<br>throughout removal, transfers,<br>and disposition.|Depending on the assessment of the sensitivity of PNT data, enforce<br>accountability for all PNT system components throughout the<br>system life cycle, including removal, transfers, and disposition.<br>Some of the asset management requirements can be met by<br>implementing solutions that provide the hardware inventory,<br>software inventory, systems development life cycle management,<br>and media sanitization technical capabilities.|**DHS CISA** 4.b<br>**ISO 15288**<br>**NIST SP 800-53 Rev. 5** CM-8, MP-6, PE-16,<br>PE-20|
|**DS-4:**<br>Adequate capacity to ensure<br>availability is maintained.|Provide enough capacity to meet PNT data performance<br>requirements—including availability, stability, and timeliness—and<br>verify that the capacity will perform within predefined thresholds<br>under normal operating conditions as well as in the presence of PNT<br>service disruptions and manipulation. Consider performing<br>developmental and operational tests to verify and validate PNT<br>service performance under normal and contested conditions.<br>Consider the principle of defense in depth using independent,<br>diverse, and isolated PNT sources and communication paths. For<br>example, multi-GNSS and multi-frequency receivers may mitigate<br>interference events and spoofing attacks, as well as avoid errors due<br>to variations in ionospheric delays. However, foreign satellite<br>constellations should only be used in accordance with current<br>federal policy guidance and restrictions.|<br>**3GPP TR22.878** 4, 5<br>**3GPP TS36.305** 4.3<br>**DHS RCF**3, 5.3, 5.4<br>**DHS PNT** IV, V<br>**GPS GNSS**<br>**GPS USER**<br>**ICAO 9849** 2.2.3, 2.2.4, 5.1, 6.2, Appendix G<br>**IEC 62439-3** 4, 5<br>**IEEE 1588** Appendix P.2.3<br>**IEEE 2030.101** 4.6, 4.8, 4.9, 4.12, 4.13|
||Keep apprised of potential and scheduled disruptions from PNT<br>service providers.<br>Where needed, incorporate measures such as stand-alone and<br>holdover capabilities or other means for deriving PNT data when<br>PNT sources are unavailable.|**IETF 7384** 5.4<br>**ITU-T G.8262** 11<br>**ITU-T G.8275**7.2<br>**Kaplan**1.8, 12, 13<br>**NIST SP 800-53 Rev. 5** AU-4, CP-2, PE-11,<br>SC-5|



39

--- [page 48](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=48) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Data Security**|**Applicability to PNT**|
|---|---|
|**Subcategory**||



### **References (PNT-Specific)** 

|||**NIST SP 800-160** Appendix F.4<br>**RTCA 229** 1.5.2, 2.1.1.7- 2.1.1.9, 2.1.2.3-<br>2.1.2.6, 2.1.3.7- 2.1.3.9, 2.1.4.7- 2.1.4.9,<br>2.1.5.7- 2.1.5.9, 2.5.9.2<br>**RTCA 356** 3.5, 5.6.1<br>**USG FRP** 1.7.5.2, 6|
|---|---|---|
|**DS-5:**<br>Protections against data leaks<br>are implemented.|Protect the PNT system against data leaks. Special attention must be<br>paid to PNT data which is bound to or used in conjunction with<br>potentially sensitive data, such as PII.<br>The physical location of critical assets needs to be protected against<br>data leaks.|**IETF 8633** 5.1<br>**IETF 8915** 1, 9<br>**NIST SP 800-53 Rev. 5** AC-4, AC-5, AC-6,<br>PE19, PS-3, PS-6, SC-7, SC-8, SC-13, SC- 31,<br>SI-4|
|**DS-6:**<br>Integrity-checking mechanisms<br>|Implement methods to verify integrity in the event of PNT data<br>discrepancies among PNT sources.<br>|**3GPP TS36.305** 4.3<br>**DHS CISA** 2.c|
|are used to verify software,<br>firmware, and information<br>integrity.|Protections should also be put in place to verify that PNT input<br>signals conform with service interface specifications and prevent<br>internal data corruption.|**DHS GPS CI** 3<br>**DHS RCF** 5.2, 7, 8|
||Information integrity may be checked or verified using redundant or<br>independent PNT sources. Methods to evaluate PNT data integrity<br>include algorithms that check the consistency of PNT output data<br>and estimate the current magnitude and characteristics PNT data<br>errors and uncertainty. For example, using multiple GNSS<br>frequencies and multiple constellations can provide a means to<br>cross-check PNT data and potentially remove error sources.|**DHS S&T**<br>**DHS S&T 2021**<br>**GPS GNSS**<br>**GPS IS-200**<br>**GPS IS-705**|
||However, foreign satellite constellations should only be used in<br>accordance with current federal policy guidance and restrictions. Be<br>aware of the potential for PNT data ambiguities in the PNT system|**GPS IS-800**3<br>**GPS ICD-240**|



40

--- [page 49](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=49) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Data Security**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
||and prepare users and applications to resolve any potential<br>ambiguity (when two or more PNT systems disagree).<br>Consider PNT systems that employ authentication and encryption of<br>PNT data to preserve integrity and resist spoofing.<br>Consider using an ensemble of multiple PNT sources to improve<br>PNT data integrity and to estimate data uncertainties.|**GPS ICD-870**<br>**IANA TZDB**<br>**ICAO 9849** 2.2.2, 4.1-4.4, 7.8, 7.10<br>**IEEE 1139**<br>**IEEE 1193**|
||Consider using PNT receivers that can verify that the data has been<br>produced by a trusted identity and has not been modified.<br>Consider PNT receivers that execute data integrity checks and<br>IS/ICD/Data compliance checks to verify integrity and resist<br>spoofing.|**IEEE 1588** 16.14, Annex P 2.2<br>**IEEE 2030.101** 5<br>**IETF 5906** 4<br>**IETF 8633** 3.7, 4|
||Qualify new PNT firmware and software by verifying, validating,<br>and executing documented device and end-to-end test plans under<br>normal and failure mode conditions, and can include but not limited<br>to standards conformance and interoperability testing.|**IETF 8915** 1, 5<br>**IMO 1575** Appendix C<br>**ISO/IEC 17025**|
||Consider including potential PNT data interoperability issues in the<br>affected application systems validation test plan, including leap<br>second and GPS week rollover testing, well in advance of an event.<br>For critical systems, consider verifying and validating PNT systems,<br>components, and procedures through tests, measurements,<br>inspections, and continuous monitoring.|**NIST SP 800-53 Rev. 5** SI-7, SI-10<br>**NIST SP 800-160 Rev. 1** 2.3, 3.3.6, 3.4.9-3.4.11,<br>Appendix F<br>**RTCA 229** 1.6, 1.8.1.5, 2.1.1.1- 2.1.1.6, 2.1.1.10,<br>2.1.1.12, 2.1.2.1, 2.1.2.2, 2.1.3.1,2.1.3.2, 2.1.4.1,<br>2.1.4.2, 2.1.4.10, 2.1.4.11, 2.1.5.2, 2.2.1.6, 2.5.8,<br>2.5.9<br>**U.S. FRP** 1.7, 4.3, A.1.10<br>**GAL ICD**<br>**BDS ICD**|



41

--- [page 50](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=50) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Protect**<br>**Data Security**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**DS-8:**<br>Integrity checking mechanisms<br>are used to verify hardware<br>integrity.|<br>Verify PNT device calibration, status, orientation (e.g., antenna<br>positioning), and actual state compared to the desired state.<br>Consider standards-based mechanisms, such as Trusted Platform<br>Modules (TPM) and other device attestation measures when<br>warranted and practical.|**DHS GPS CI** 4, 6<br>**IEEE 1588** Annex M, N<br>**NISTIR 8320**<br>**NIST SP 800-53 Rev. 5** PE-11, SA-10, SI-7|



### **4.2.4. Information Protection Processes and Procedures Category** 

Security policies (that address purpose, scope, roles, responsibilities, management commitment, and coordination among organizational entities), processes, and procedures are maintained and used to manage the protection of information systems and assets. In the context of this PNT Profile, the PNT data and services are subject to the security policies of the information that the PNT data is bound or associated with (e.g., PII, location of critical assets). 

There are five Subcategories within Information Protection Processes and Procedures that apply to the PNT Profile, as summarized in the table below. 

**Table 12.** Information Protection Processes and Procedures Applicable to PNT 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**IP-1:**<br>A baseline configuration of<br>information technology /<br>industrial control systems are<br>created and maintained that<br>incorporates security principles|Document baseline information for PNT devices and components<br>(e.g., serial numbers, license information, version numbers, HMI<br>and other ICS component applications, patch information).<br>Document configuration instructions and backups, architecture, and<br>wiring diagrams, and other PNT system information so that the<br>reliance on and interdependency of PNT-related assets are|**3GPP TR22.878** 4, 5<br>**DHS CISA** 4.b, 5.b<br>**DHS GPS CI** 11<br>**DHS TFS** 1, 2|



42

--- [page 51](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=51) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|(e.g. concept of least<br>functionality) is created and<br>maintained.|understood and can be maintained.<br>Install and configure PNT devices and components per<br>manufacturer instructions using established safety and best practices<br>guidelines. Understand the limitations of the original equipment<br>manufacturer (OEM) equipment being fielded and consider the<br>ability of the PNT devices and components to be suitable for the<br>site’s environment and adaptable to new features and protection<br>mechanisms for PNT data.<br>Periodically review and simplify PNT systems to reduce unknown<br>interactions and effects. Configuring the PNT devices and<br>components in a manner such that only essential capabilities are<br>provided can reduce complexity and may reduce the attack surface.<br>Network configuration and deployment can impact recovery time in<br>the event of a path or node failure.<br>Verify that the baseline configuration results in a system that meets<br>the baseline PNT performance requirements, such as uncertainty,<br>wander, and jitter tolerances.|<br>**GPS-SPS**2.4<br>**ICAO 9849** 6.4, Appendix F 5.2, 5.3<br>**IEEE 1588** Annex P<br>**IEEE 2030.101** 4.6-4.13, 4.15<br>**IETF 5906** 5<br>**IETF 8633** 2-9<br>**IMO 1575** C.1, E<br>**ITU G. 8272** I.1<br>**ITU-T G.8275** 7, 8<br>**ITU-T GNSS** 2, 4, 5, Appendix V, VII<br>**NIST SP 800-53 Rev. 5** CM-1, CM-2, CM- 3,<br>CM-4, CM5, CM-6, CM-7, CM-9, SA-10<br>**NIST SP 800-160** 3.4.9, 3.4.10, 3.4.11<br>Appendix F, G<br>**NTP SEC**<br>**RTCA 229** 2.2.1.1, 2.4.1, 2.5.2, 2.5.3, 2.5.4,<br>2.5.7, 2.5.11<br>**RTCA 235** 2.5.2.1, 2.5.2.2, Appendix G<br>**RTCA 356**3.5, 3.6, 5.6.1, 5.6.4, 5.6.5<br>**USG FRP** Appendix A|



43

--- [page 52](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=52) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**IP-2:**<br>A System Development Life<br>Cycle to manage systems is<br>implemented.|An operational system development life cycle for PNT services is<br>established to incorporate and manage security measures throughout<br>the life cycle of components.<br>Document the requirements, approach, architectures, and<br>assumptions used to minimize risks for systems that form or use<br>PNT data, thereby verifying PNT data performance, such as the<br>availability, integrity, and confidentiality of services.|<br>**DHS CISA** 4.b<br>**IEEE 2030.101** 4.5, 4.6<br>**NIST SP 800-53 Rev. 5** PL-8, SA-3, SA-4, SA-8,<br>SA-10, SA-11, SA-15, SA-17, SI-12, SI-13, SI-<br>14, SI-16, SI-17<br>**NIST SP 800-160 Rev. 1**3.2.1, Appendix F.3|
||Consider the intended lifetime of the systems that form PNT data.<br>The system components and architecture should be designed for<br>complementary or redundant PNT sources to mitigate end-of-life<br>and reliability issues, limit the failure modes, and increase the<br>probability that the organization’s PNT systems are able to detect<br>anomalous inputs and remain available through the presence of<br>different threat models.<br>Select, use, and ensemble complementary PNT services based on<br>system priority classifications to meet business continuity<br>objectives.|**RTCA 326** 4.2<br>**USG FRP** 1.4, 1.7.2|
|**IP-3:**<br>Configuration change control<br>processes are in place.|Employ configuration change control for PNT devices and<br>components that are consistent with the software development life<br>cycle to maintain a functioning baseline and monitor all changes to<br>validate impacts and integrity.<br>Prior to deploying a change, conduct impact analyses. Identify and<br>record the effects of impact on downstream applications, users, and<br>downtime.<br>Provide a mechanism so that changes in PNT firmware and software<br>canbereturned to a properworking state and should comply with|<br>**DHS GPS CI**<br>**IMO 1575** C.1, E.3<br>**NIST SP 800-53 Rev. 5** CM-3, CM-4, SA-10<br>**NIST SP 800-160 Rev. 1**3.3.5<br>**RTCA 356**3.8.3, 3.8.4|



44

--- [page 53](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=53) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||the latest standards.<br>Change control and maintenance procedures should include<br>documentation and artifacts that will impact the performance of the<br>PNT system, such as calibration procedures.||
|**IP-9:**<br>Response plans (Incident<br>Response and Business<br>Continuity) and recovery plans<br>(Incident Recovery and Disaster<br>Recovery) are in place and<br>managed.|<br>Develop and maintain response and recovery plans that identify<br>essential functions and associated contingency requirements, as well<br>as provide a roadmap for implementing incident response. Plans<br>should incorporate recovery objectives, restoration priorities, tests,<br>metrics, contingency roles, personnel assignments, and contact<br>information. Prioritize maintaining essential functions despite<br>system disruption or manipulation, as well as the eventual<br>restoration of the PNT devices and components.<br>As part of response planning, verify that systems have capabilities<br>to mitigate PNT disruptions, such as anomaly detection with<br>holdover capabilities. If complementary PNT sources are used,<br>consider common failure modes and whether vulnerabilities of<br>alternate and complementary sources are understood.<br>Response planning should consider appropriate restrictions on the<br>downstream consumption of PNT information to limit the impact of|**DHS CISA** 1.f<br>**DHS IDM**<br>**DHS RCF** 5-7<br>**ICAO 9849** 1.5<br>**IEC 61850-90-12** 5.8<br>**IEEE 2030.101**4.12-4.14<br>**ISO / IEC / IEEE 15939:2017** 6<br>**ITU-T 8262** 11<br>**IMO 1575** E.4<br>**ITU-T 8275** 7.2<br>**NIST JRES**120.017|
||PNT disruptions.<br>Define the incident types, resources, and management support<br>needed to effectively maintain and mature the incident response and<br>contingency capabilities. For critical applications and where<br>practical, identify all known PNT system and component fault and<br>failure modes within the deployed environments with the objective<br>of increasing the probability that at least one PNT source will not be<br>susceptible to each failure mode identified. For each failure and|**NIST SP 800-53 Rev. 5** CP-1, CP-2, CP-7,<br>CP-10, CP-12, CP13, IR-1, IR-7, IR-8, IR-9,<br>PE-17<br>**NIST SP 800-160 Rev.1** Appendix F.2.6<br>**RTCA 356** 5.6.6<br>**USG FRP** 1.7.3, 6|



45

--- [page 54](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=54) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||fault mode, identify detection and compensation strategies, effects<br>on the computed PNT data, and effects on the applications<br>dependent on the data to determine whether the response and<br>recovery plans are adequate to meet business continuity objectives.<br>Implement mitigation strategies to temporary PNT disruptions and<br>manipulations for all critical services. A means to maintain business<br>continuity is leveraging complementary and holdover PNT sources<br>and redundant components, such as antennas spaced sufficiently<br>apart and high-stability oscillators. Select, use, and ensemble PNT<br>sources based on system priority classifications to meet business<br>continuity objectives. Identify complementary PNT sources with<br>multiple phenomenologies and an understanding of the benefits,<br>limitations, and dissimilar failure modes to increase the probability<br>that the PNT service's ability to detect anomalous inputs and remain<br>available in contested environments.<br>For responses to PNT data-dependent critical functions that involve<br>failures or shutdowns, define, and execute fail- secure or fail-safe<br>plans for PNT systems and components.<br>Perform PNT system acceptance testing to verify and validate<br>response and recovery plans. For example, for systems with<br>redundant or complementary time sources, validate current system<br>time delivered via a time distribution protocol by removing the<br>primary time source and confirming that the time accuracy and<br>precision, as well as any phase or frequency steps or ramps, are in<br>accordance with predefined clock requirements for the time server<br>and downstream applications.<br>Consider the creation and maintenance of developmental and<br>operational test and evaluation methods to assess, verify, and||



46

--- [page 55](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=55) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Information Protection**<br>**Processes and**<br>**Procedures**<br>**Subcategory**|**Applicability to PNT**<br>validate PNT service performance under normal and contested<br>conditions.|**References (PNT-Specific)**|
|---|---|---|
|**IP-10:**<br>Response and recovery plans<br>are tested.|Assess threat preparedness by verifying incident response and<br>recovery plans of the PNT systems.<br>For critical applications, consider qualification and periodic testing<br>to assess PNT response and recovery plans for infrequent events<br>(e.g., leap seconds) or changes to the components or operations that<br>would significantly impact the performance for the system. Review<br>the results to determine the efficiency and effectiveness of the plans<br>as well as readiness to execute the plans. Use the results of the tests<br>to inform other CSF functions, such as “Detect.”<br>Exercise the response and recovery plans to validate that the effects<br>of the anomalous events on the PNT data’s availability, integrity,<br>and continuity are within specified tolerances. For example, for<br>systems with redundant or complementary time sources, validate<br>current system time delivered via a time distribution protocol by<br>removing the primary time source and confirming that the time<br>accuracy and precision, as well as any phase or frequency steps or<br>ramps, are in accordance with pre-defined clock requirements for<br>the time server and downstream applications.<br>Testing response and recovery plans may include the use of RF<br>signals to simulate anomalous events. Any simulation that involves<br>RF transmissions must be done in in a manner that is consistent with<br>industry best practices and in accordance with laws and regulations.|<br>**DHS RCF**8<br>**DHS S&T**<br>**ICAO 9849** 5.3.2.2<br>**IEC 61850-90-4** 14.2.4<br>**IEEE 2030.101** 5.4.2.5<br>**ITU-T GNSS**Appendix VII.3, VII.4<br>**NERC GridEx**<br>**NIST SP 800-53 Rev. 5** CP-4, IR-3, PM-14<br>**RTCA 229** 2<br>**RTCA 326**3.4.2, 3.4.4|



47

--- [page 56](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=56) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.2.5. Maintenance Category** 

Maintenance and repairs to industrial control and information system components are performed consistent with policies and procedures. In the context of this PNT Profile, the systems and components of interest include GNSS receivers, antennas, modules, and time servers. 

Both Subcategories within the Maintenance category apply to the PNT Profile, as summarized in the table below. 

**Table 13.** Maintenance Subcategories Applicable to PNT 

|**Protect**<br>**Maintenance**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**MA-1:**<br>Maintenance and repair of<br>organizational assets are<br>performed and logged, with<br>approved and controlled tools.|Schedule, perform, record, and review records of maintenance and<br>repairs on PNT devices and components.<br>Assess the impacts of the maintenance and repair of the PNT<br>devices and components on the end user’s operations and verify that<br>the PNT devices and components perform within specified<br>tolerances.<br>Infrequent events, such as leap seconds, may be handled differently<br>by different sources of PNT. Understand how these events and their<br>implementations impact operations.<br>Make available and adhere to documentation and artifacts, such as<br>software maintenance procedures, configuration parameters<br>(including default values and ranges), test plans, compliance test<br>result documentation, and other pertinent information to verify<br>consistent and valid deployments.<br>Document PNT system and component calibration procedures and<br>results for applications that require legal traceability or known<br>uncertainty. The frequency of calibrations is dependent on factors<br>such as environmental conditions, changes in PNT systems,<br>components and architecture, exposure to disruptions and<br>manipulations, and PNT data performance requirements.|**Defraigne 2022**MA-1<br>**DHS CISA**4<br>**DHS GPS CI**<br>**DHS RCF**8<br>**DHS TFS**1.6, 2, 3.6, 3.8<br>**IEEE 1139**<br>**IEEE 1193**<br>**IEEE 1588**Annex N<br>**IEEE 2030.101**4.7, 6<br>**IETF 8633**3.1<br>**ISO/IEC 17025**<br>**ITU-T GNSS**2<br>**Levine**2021<br>**NIST SP 250-29**<br>**NIST SP 800-53 Rev. 5**MA-1, MA-2, MA- 3,|



48

--- [page 57](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=57) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Maintenance**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||Calibration procedures may include the absolute or relative<br>calibration or recalibration of components. Document procedures<br>for minimum periodic calibrations to a standard reference,<br>particularly for applications that require traceability. For example,<br>in the U.S., legal or metrological time calibration requires an<br>unbroken chain of documented calibrations to UTC(NIST) or<br>UTC(USNO).<br>Delay variations and the stability of each component due to factors<br>such as temperature or aging should be characterized in the<br>environment in which the PNT system will be deployed. The<br>calibration of component delays (e.g., antenna, surge suppressors,<br>cables, connectors, splitters, receivers, switches) should be recorded<br>to verify that the absolute accuracy and precision in the end-to-end<br>systems that form and use PNT data are within specified tolerances.|MA-5, MA-6<br>**NIST SP 1065**5-10|
|**MA-2:**<br>Remote maintenance of<br>organizational assets is<br>approved, logged, and<br>performed in a manner that<br>prevents unauthorized access.|Enforce approval requirements, control, and monitoring of remote<br>maintenance activities.<br>Employ the appropriate level of authentication, least privilege,<br>logging, record keeping, and session termination for remote<br>maintenance.|**DHS CISA**4.b<br>**DHS GPS CI**<br>**IEEE 1588**Annex P.2.5.2<br>**IEEE 2030.101**4.8.2, 4.15.2, 4.15.3, Annex<br>G.2.4<br>**IETF 8633**3.5, A.3<br>**NIST SP 800-53 Rev. 5**MA-4<br>**NIST SP 800-160 Rev. 1**Appendix F.1.14|



49

--- [page 58](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=58) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.2.6. Protective Technology Category** 

Technical security solutions are managed to verify the security and resilience of systems and assets consistent with related policies, procedures, and agreements. 

There are five Subcategories within the Protective Technology category that apply to the PNT Profile, as summarized in the table below. 

**Table 14.** Protective Technology Subcategories Applicable to PNT 

|**Protect**<br>**Protective Technology**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**PT-1:**<br>Audit/log records are<br>determined, documented,<br>implemented, and reviewed in<br>accordance with policy.|Generate audit records that contain information such as what, when,<br>the source, the outcome, and the identity of any individuals or PNT<br>components associated with the event. Consider maintaining audit<br>logs for extended periods to support forensic analysis.<br>A log file should also include entries of proper working states in<br>addition to entries of anomalies and events.<br>Wherever practical, logging and audit mechanisms should produce<br>data elements in accordance with standard data formats to facilitate<br>parsing and consumption by analytic teams.<br>PNT-dependent applications that require an audit trail often require<br>legal or metrological traceability meaning an unbroken documented<br>chain of calibrations from a standard or other trusted reference.<br>As part of characterizing the physical device using or forming PNT<br>data, determine the delay characteristics between the device clock<br>and the time stamping functions used for the audit and logs.|**Defraigne 2022**5<br>**DHS CISA** 7.a<br>**DHS GPS CI**<br>**DOT 12464**<br>**IEEE 1588** 16.14. III, IV, V 4.4.2<br>**Matsakis**2018<br>**NIST SP 800-53 Rev. 5** AU-1, AU-2, AU-3,<br>AU-6, AU-7, AU-12, AU-13, AU-14, AU- 16<br>**NIST SP 800-160 Rev. 1** 3.3.2, 3.3.5<br>**SEC 613**|
|**PT-2:**<br>Removable media is protected,<br>and its use restricted according<br>to policy.|Employ safeguards to restrict the use of portable media when used<br>on PNT devices and components.<br>Ensure that PNT devices and equipment follow organizational<br>policy on removable media.|**NIST SP 800-53 Rev. 5**MP-1, MP-2, MP-3,<br>MP-4, MP5, MP-7, MP-8|



50

--- [page 59](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=59) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Protective Technology**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**PT-3:**<br>The principle of least<br>functionality is incorporated by<br>configuring systems to provide<br>only essential capabilities.|PNT deployment should employ the principle of least functionality.<br>Configure the PNT system to provide only essential capabilities.<br>When PNT data or services do not require functionality from<br>intermediary nodes, they can be disabled to minimize attack<br>surfaces.|**IEEE 1588** Annex P2.5.1,2.5.5<br>**IETF CMP** 6<br>**IETF 7384** 7.3<br>**NIST SP 800-53 Rev. 5** AC-3, CM-7|
|**PT-4:**<br>Communications and control<br>networks are protected.|Typically, PNT systems have high availability and integrity<br>requirements. Identify communications and control network<br>requirements for availability, integrity, authentication, stability,<br>confidentiality, and other pertinent parameters based on classes of<br>applications, and provide appropriate levels of protection.<br>Observe cyber hygiene in communications and control networks.<br>Consider appropriate measures for networks that distribute PNT<br>data.|**DHS CISA**4.a, 5.a<br>**DHS GPS CI**<br>**IEEE 1588** 16.14.4.4.2, Annex P<br>**IETF 8633**4.4, 5.5, 5.6<br>**IETF NTS** 3<br>**ITU-T G.8275** 8|
||Some measures need to be considered at the architectural phase of<br>the SDLC, such as transport security implementations, while others<br>can be applied at the configuration or deployment phase, such as<br>transport security. For example, some NTP/PTP devices have<br>multiple network ports that could be configured to isolate control<br>traffic.<br>As needed, consider transport security for networks that distribute<br>PNT data. Note that implementing some transport security measures<br>(e.g., use of cryptographic algorithms and implementations) can<br>lead to time synchronization performance degradation that may be<br>problematic, especially for high-precision timing applications.<br>Verify that protective measures will not adversely affect the overall<br>system performance requirements.|<br>**NIST SP 800-53 Rev. 5** AC-12, AC-17, AC- 18,<br>CP-8, SC-5, SC-7, SC-10, SC-11, SC-20, SC-21,<br>SC-22, SC-23, SC-31, SC-37, SC-38, SC-47<br>**NIST SP 800-160 Rev. 1 **Appendix F|



51

--- [page 60](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=60) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Protect**<br>**Protective Technology**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**PT-5:**<br>Mechanisms (e.g., failsafe, load<br>balancing, hot swap) are<br>implemented to achieve<br>resilience requirements in<br>normal and adverse situations.|Mechanisms include proactive measures that reject bad PNT signals<br>and data to limit how far threats penetrate into PNT systems.<br>Reactive measures should also be present to handle threats that<br>penetrate into PNT systems, including holdover capabilities paired<br>with anomaly detection, features to limit performance degradation,<br>and recovery capabilities.<br>Resiliency measures can also be achieved through new system<br>designs that limit exposure times to attack surfaces, protect internal<br>states, and have intelligent control algorithms. Some mechanisms to<br>consider in the design phase include leveraging PNT service<br>providers with hardened signals, redundant PNT sources, fused PNT<br>sources, or others in accordance with the resiliency requirements of<br>the mission.|<br>**DHS RCF** 5-7<br>**IEEE 1588** 9.3, 16.4, 17<br>**NIST SP 800-53 Rev. 5** CP-7, CP-8, CP- 11,<br>CP-12, CP-13, PE-11, PL-8, SC-6<br>**USG FRP** 5.1|



52

--- [page 61](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=61) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Detect Function** 

The Detect Function addresses the development and deployment of appropriate activities to monitor for anomalous events and notify downstream users and applications upon their occurrence. The Detect Function is informed by the Identify Function and is enabled by the Protect Function. 

The objectives of the Detect Function include: 

- Enabling detection through monitoring and consistency checking; and 

- Establishing a process for deploying and handling detected anomalies and events. 

The Detect Function defines three categories, all of which have Subcategories that apply to the PNT Profile to varying degrees, as summarized in Sec. 4.3.1 through Sec. 4.3.3. 

### **4.3.1. Anomalies and Events Category** 

Anomalous activity is detected, and the potential impact of events is understood. In the context of this PNT Profile, this includes detection of uncharacteristic PNT data or a loss of PNT data for some period. 

There are five Subcategories within Anomalies and Events that apply to the PNT Profile, as summarized in the table below. 

**Table 15.** Anomalies and Events Subcategories Applicable to PNT 

|**Detect**<br>**Anomalies and Events**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**AE-1:**<br>A baseline of network<br>operations and expected data<br>flows for users and systems is|Verify that operational PNT data performance baselines and<br>expected data flows for relevant external PNT information systems,<br>the organization’s PNT system, and applications dependent on PNT<br>data are captured, developed, and maintained to detect events.|**DHS CISA**1.d<br>**GPS ICD-870**3.1<br>**IEEE 1588**Annex J IETF CMP|
|established and managed.|When practical, comply with standards-based solutions for data<br>formatting, message formatting, and message transmission to<br>facilitate interoperability and integration.|**IMO 1575**D, D.1, D.2<br>**NIST SP 800-53 Rev. 5**AC-4, CA-3, CM-2,<br>SC-16, SI-4<br>**RTCA 229**1.5.2, 1.7.2|



53

--- [page 62](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=62) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Detect**<br>**Anomalies and Events**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|||**USG FRP**Appendix B|
|**AE-2:**<br>Detected events are analyzed to<br>understand attack targets and<br>methods.|Review and analyze detected events within the PNT system in (i)<br>real time to maintain normalcy of operations; and (ii) forensically to<br>understand the characteristics (e.g., source, data error statistics,<br>duration, frequency, and location) of anomalous events. Be able to<br>identify potential cyber incidents and understand attack targets and<br>methods.<br>Be able to distinguish between potentially harmful events and<br>normal operations. Be able to predict harm based on events.<br>Consider the PNT system when analyzing cybersecurity events<br>involving downstream applications.<br>For RFI, include environmental monitoring with direction- finding<br>capabilities to locate the source.<br>Preserve the raw data, analysis, and characterization to aid in the<br>analysis of future events.|**DHS GPS CI**<br>**DHS RCF**5.2<br>**Kaplan 2017** Chapters 9, 10<br>**NIST SP 800-53 Rev. 5** AU-6, CA-7, IR-4,<br>RA-5, SI-4<br>**RTCA 229** Appendix R<br>**RTCA 235** 2.1|
|**AE-3:**<br>Event data are collected and<br>correlated from multiple<br>sources and sensors.|Multiple sensors and sources can be used to correlate fault modes<br>and contribute to anomaly detection models and algorithms.<br>PNT data from multiple sources may be used, cross-checked, and<br>compared for the detection of anomalous behavior.<br>Compile sufficient event data across the PNT system using various<br>sources, such as event reports, logs, audit monitoring, network<br>monitoring, physical access monitoring, environmental monitoring,<br>and user and administrator reports.<br>Standards-based data formatting and serialization promotes the<br>communication interoperability and interchangeability of PNT data<br>and supporting data.<br>Considersubscribing to orenabling usercommunity andPNT|**DOT CGSIC**<br>**GPS ICD-870**3.1<br>**GPS USER**<br>**ICAO 9849** 5.3.3.5, 7.11<br>**IEEE 1588** Annex J<br>**IEEE 2030.101** 4.7, 4.8, 4.13, 5.4.4<br>**IETF CMP**<br>**IMO 1575**2, 3<br>**NAVCEN**|



54

--- [page 63](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=63) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Detect**<br>**Anomalies and Events**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||provider communications for status on PNT data and services. Use<br>authoritative sources of PNT data products, such as informational<br>almanacs and status information, with authentication and data<br>integrity verification capabilities. For GPS, NAVCEN has<br>information on almanacs, operational advisories, NANU (Notice<br>Advisory to Navstar Users), and CGSIC (Civil GPS Service<br>Interface Committee) bulletins. Additional sector-specific advisories<br>may be provided by ISACs and sector-specific agencies.|<br>**NIST SP 800-53 Rev. 5** AU-6, CA-7, CP-2, IR-4,<br>IR-5, IR-8, SI-4<br>**NIST SP 800-160 Rev. 1** 3.3.7<br>**RTCA 229 **Appendix G.2, G.3<br>**RTCA 235** 1.1<br>**SPD-7**<br>**USG FRP** Appendix A<br>**GAL ICD**<br>**BDS ICD**|
|**AE-4:**<br>Impact of events is determined.|Identify the effects of anomalous events on the PNT data and<br>applications that are dependent on the PNT data.<br>PNT events (including infrequent events and true anomalies) can<br>have unexpected impacts on systems and operations downstream<br>from PNT devices and equipment. Users should understand how<br>such events might impact operations.|**DOT 12464**<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4, RA- 3, SI-4<br>**RTCA 229** Appendix R|
|**AE-5:**<br>Incident alert thresholds are<br>established.|Established PNT incident thresholds and understanding potential<br>impacts to the mission enables proper reporting, alerting thresholds,<br>and the development of adequate incident alert procedures.<br>For critical applications, document absolute or relative PNT data<br>error and uncertainty tolerances that serve as detection thresholds,<br>which can be expressed as a statistical distribution within the<br>confidence levels needed for operations. For PNT-dependent<br>applications, consider and document the required notification or<br>alarm communication time upon nearing and exceeding thresholds.<br>Based on mission requirements, consider reviewing and revising<br>thresholds on a routine basis.|**GPS SPS** 2.3.4<br>**ICAO 9849** 7.11<br>**IMO 1575** 2.2.1, Appendix C<br>**NIST SP 800-53 Rev. 5** IR-4, IR-5, IR-8<br>**USG FRP** Appendix A|



55

--- [page 64](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=64) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.3.2. Security Continuous Monitoring Category** 

The information system and assets are monitored to identify cybersecurity events and verify the effectiveness of protective measures. In the context of this PNT Profile, the interface to the PNT service provider, the receivers that process and form the PNT data, the intermediate nodes that transport PNT services, and the end applications consuming PNT data are monitored. 

There are eight Subcategories within the Security Continuous Monitoring Category that apply to the PNT Profile, as summarized in the table below. 

**Table 16.** Security Continuous Monitoring Subcategories Applicable to PNT 

|**Detect**<br>**Security Continuous**<br>**Monitoring**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**CM-1:**<br>The network is monitored to<br>detect potential cybersecurity<br>events.|Monitor the PNT source and associated information products, PNT<br>distribution, PNT data output characteristics, and additional<br>characteristics from applications and systems dependent on PNT<br>data against known baseline characteristics to detect anomalies,<br>including when PNT security measures may fail.<br>Heighten system monitoring activities when there is an indication of<br>increased risk.<br>Use an effective mix and fusion of data from multiple, diverse PNT<br>sources and PNT data distribution routes. Consider using fault<br>detection and exclusion algorithms to automatically detect faults<br>and exclude erroneous sources in the computation of data used to<br>form or that is dependent upon PNT data. This enables redundancy<br>and consistency checking to detect changes in propagation delays<br>and other characteristics indicating compromises in PNT data.<br>Verify that the monitoring strategy is sufficiently robust to detect<br>PNT data and other system behavior anomalies for all identified<br>fault and failure modes. Detection thresholds can be determined<br>from nominal and anomalous data for each fault and failure mode.<br>Consider relevant fault parameters and acceptance bounds based on|<br>**DHS CISA** 1.d<br>**DHS RCF** 7, 8<br>**DOT 12464**<br>**GDGPS**<br>**ICAO 9849** 5.3.1.5-5.3.1.9, 7.8<br>**IEEE 1588** 16.11, 16.12, Annex J, P.2.4<br>**IEEE 2030.101** 4.5.2<br>**IETF CMP**<br>**IMO 1575** C.2.2, Appendix C.1<br>**ITU-T GNSS** Appendix III, VI<br>**NIST SP 800-53 Rev. 5** AU-12, CA-7, CM3,<br>SC-5, SC-7, SI-4<br>**RTCA 229** 1.7.2, 1.7.3, 2.1.1.5, 2.1.3.2.2.3,<br>2.1.5.2.2, 2.2.1.6, 2.2.2.6|



56

--- [page 65](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=65) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Detect**<br>**Security Continuous**<br>**Monitoring**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||reasonable or conservative criteria for various classes of<br>applications and users.<br>Detection models can leverage correlations between fault modes<br>and minimum detectable limits. Analysis of the correlation engines<br>may be able to determine if some faults can remain undetected.<br>These findings can be used in the risk management procedures.<br>Consider providing a loopback reference timing signal to<br>continuously monitor for changes in the total network and signal<br>propagation delay.<br>Within a specified time, alert dependent users and applications<br>when monitoring is unavailable or when PNT data or service is<br>unavailable.<br>Software and hardware can be integrated into the PNT system and<br>critical infrastructure components to detect and mitigate GNSS<br>jamming and spoofing events and preserve PNT data availability,<br>continuity, and integrity.|**RTCA 235** 2.3, 2.5<br>**USG FRP** Appendix B|
|**CM-2:**<br>The physical environment is<br>monitored to detect potential<br>cybersecurity events.|Physical access to PNT devices and components is actively<br>monitored to detect potential breaches in security. Actively monitor<br>the physical environment to include the RF environment.<br>PNT devices and equipment may be in remote locations.<br>Positively identify people who access areas that contain PNT<br>devices. Where feasible, implement the use of access controls that<br>are specific to personnel, such as swipe cards and personal<br>identification numbers (PINs).|**DHS GPS CI**<br>**ICAO 9849** 5.3.7<br>**Kaplan** 10<br>**NIST SP 800-53 Rev. 5** CA-7, PE-6, PE-20|
|**CM-3:**<br>Personnel activity is monitored|Monitor personnel actions for unauthorized activity on or using<br>PNT systems or data. The scope of the monitoring can include<br>elements suchasloginattributes (e.g., time, physical location,|**NIST SP 800-53 Rev. 5** AC-2, AU-12, AU-13,<br>CA-7, CM-10, CM-11|



57

--- [page 66](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=66) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Detect**<br>**Security Continuous**<br>**Monitoring**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|to detect potential cybersecurity<br>events.|operating system, device, credentials), electronic access control<br>systems, physical access control systems (e.g., sign in/out sheets,<br>logging), security status monitoring of personnel activity associated<br>with PNT systems, detecting software use, and installation<br>restrictions.||
|**CM-4:**<br>Malicious code is detected.|Deploy malicious code detection mechanisms, such as behavioral<br>anomaly detection tools, throughout the PNT systems to detect and<br>eradicate malicious code.<br>Should a PNT data consumer experience an anomaly, consider<br>investigating the PNT system and associated applications as<br>possible sources of the anomaly.<br>Systems that use and support PNT data should be included in the<br>antivirus analysis.<br>Update malicious code protection mechanisms, such as antivirus<br>protections, when new releases are available in accordance with the<br>configuration management policy and procedures for the PNT<br>systems involved.|**DHS CISA** 4.a<br>**NIST SP 800-53 Rev. 5** SC-44, SI-3, SI-4, SI-8|
|**CM-5:**<br>Unauthorized mobile code is<br>detected.|PNT devices and equipment contain operating systems and may be<br>vulnerable to unauthorized mobile code introduced by other vectors.<br>Mobile code detection mechanisms throughout the enterprise are<br>recommended because vulnerabilities’ level of access may be<br>inherited from other applications of the mobile code.|<br>**DHS CISA** 4.a<br>**NIST SP 800-53 Rev. 5** SC-18, SI-4, SC-44|
|**CM-6:**<br>External service provider<br>activity is monitored to detect<br>potential cybersecurity events.|Detect deviation from PNT service providers’ interface<br>specifications, which are defined in a service-level agreement (SLA)<br>with the service provider. This can include signal integrity,<br>availability, continuity, and coverage.<br>Consider subscribing to or enabling user community and PNT|**DOT CMPS**3<br>**GPS IS-200**3<br>**GPS IS-705**3<br>**GPS IS-800**3|



58

--- [page 67](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=67) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Detect**<br>**Security Continuous**<br>**Monitoring**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||provider communications for status on PNT data and services. For<br>example, NAVCEN has information on almanacs, Operational<br>(OPS) Advisories, NANU (Notice Advisory to Navstar Users), and<br>CGSIC (Civil GPS Service Interface Committee) bulletins.<br>Additional sector- specific advisories may be provided by ISACs<br>and sector-specific agencies.|**ICAO 9849** 7.8, 7.11<br>**IMO 1575** 2.2, B.1, E.1<br>**NAVCEN**<br>**NIST SP 800-53 Rev. 5**CA-7, PS-7, SA-4, SA-9,<br>SI-4<br>**USG FRP** Appendix B|
|**CM-7:**<br>Monitoring for unauthorized<br>personnel, connections, devices,<br>and software is performed.|<br>Conduct ongoing security status monitoring on PNT systems for<br>unauthorized personnel, connections, devices, access points, and<br>software.<br>Monitor for system inventory discrepancies.<br>Collect, aggregate, and analyze data from systems that use and<br>support the generation and dissemination of PNT data to indicate<br>potential unauthorized access or activity.|**NIST SP 800-53 Rev. 5** AU-12, CA-7, CM- 3,<br>CM-8, PE-6, PE-20, SI-4<br>**NTP MON**|
|**CM-8:**<br>Vulnerability scans are<br>performed.|Conduct vulnerability scans on PNT systems where safe, feasible,<br>and in a manner that is consistent with industry best practices.<br>Include analysis, remediation, and information sharing in the<br>vulnerability scanning process. Ensure that scanning activities do<br>not negatively impact online PNT devices and equipment operation.<br>Vulnerability scanning may include the use of RF signals to<br>simulate events such as jamming and spoofing. Any simulation that<br>involves RF transmissions must be done in a responsible manner,<br>according to manufacturer instructions, and in accordance with laws<br>and regulations to avoid impacts on operations or to others.<br>Monitor the PNT source, network distribution characteristics (e.g.,<br>delays, jitter, bandwidth saturation), signal distribution medium<br>characteristics (e.g., timing delays), PNT data output, and additional|**DHS CISA** 1.a<br>**IEEE 2030.101** 5<br>**NIST SP 800-53 Rev. 5** RA-5<br>**NIST SP 800-115**<br>**RTCA 229** 1.6.2, 1.7.2, 2.1.1.1.5, 2.4, 2.5<br>**RTCA 326** 3.4.4|



59

--- [page 68](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=68) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Detect**<br>**Security Continuous**<br>**Monitoring**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
||characteristics from applications and systems that are dependent on<br>PNT data for anomalous behavior, including when security<br>measures may fail and the system needs to fail-secure or fail-safe.||
||All sources of PNT, including alternate or complementary PNT<br>devices, need to be tested and enabled in advance of a PNT<br>disruption event.||



60

--- [page 69](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=69) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.3.3. Detection Processes Category** 

Detection processes and procedures are maintained and tested to promote awareness of anomalous events. In the context of this PNT Profile, the process and procedures on the information systems and assets as well as the analytic processes and procedures are maintained, updated, and tested. 

There are four Subcategories within the Detection Process Category that apply to the PNT Profile, as summarized in the table below. 

**Table 17.** Detection Processes Applicable to PNT 

|**Detect**<br>**Detection Processes**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**DP-1:**<br>Roles and responsibilities for<br>detection are well- defined to<br>ensure accountability.|When feasible, provision roles and responsibilities within a<br>cooperative detection framework for data collection, data storage,<br>and data dissemination towards improving future PNT protection,<br>detection, response, and recovery capabilities.<br>Understand PNT service provider and sector specific PNT detection<br>roles and responsibilities.|**DHS IDM**<br>**DOT CMPS **1.3<br>**ICAO 9849** 7.8<br>**NIST SP 800-53 Rev. 5** CA-2, CA-7, PM- 14<br>**USG FRP** 2.1-2.4, 3.2.11|
|**DP-3:**<br>Detection processes are tested.|Validate that event detection processes are operating as intended.<br>PNT devices and components that are upgraded are re-validated<br>with end-to-end testing by the users.<br>Perform periodic testing to verify the performance of the detection<br>process against the most current threat profiles and vulnerabilities.|**DHS RCF**6<br>**DHS S&T**<br>**NIST SP 800-53 Rev. 5**CA-2, CA-7. PM- 14,<br>SI-3, SI-4<br>**RTCA 229**1.7.2, 1.7.3, 1.8.2.3, 2.1.1.4.1, 2.1.1.5,<br>2.1.1.13, 2.1.2.2, 2.1.3.2, 2.1.4.2, 2.1.4.9, 2.1.5.2,<br>2.4.1.1, 2.5.3, 2.5.7, 2.5.9-2.5.11<br>**RTCA 326** 3.4.4|
|**DP-4:**<br>Event detection information is<br>communicated.|Communicate PNT data anomaly detection and the current best<br>estimate of PNT data quality to personnel, partners, analytics, and<br>downstream application users.<br>When the cause of a PNT service disruption event is suspected to be<br>external, share event detection with the appropriate external|**ICAO 9849** 7.12, Appendix F<br>**IEEE 1588** 7.6.2, 16.11, 16.12<br>**IEEE C37.238** 6.2.1, 6.3|



61

--- [page 70](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=70) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Detect**<br>**Detection Processes**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
||stakeholders for further investigation.|**IETF CMP**<br>**IMO 1575** 2.3, B.2.2.1|
|||**ITU-T G.8275** Appendix II, IV|
|||**NAVCEN**|
|||**NIST SP 800-53 Rev. 5** AU-6, CA-2, CA-7,<br>RA5, SI-4|
|||**RTCA 229** 2.1.1.4|
|||**USG FRP** Appendix B|
|**DP-5:**<br>Detection processes are<br>continuously improved.|Modify and improve the monitoring strategy as new fault modes are<br>identified and until detection performance is acceptable.<br>Periodically examine the organization’s PNT anomaly detection<br>processes and seek to improve them continuously.|**NIST SP 800-53 Rev. 5** CA-2, CA-5, CA-7,<br>PL-2, PM-14, RA-5, SI-4|



62

--- [page 71](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=71) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Respond Function** 

Develop and implement the appropriate activities to respond to a detected cybersecurity or anomalous event. The activities in the Respond Function support the ability to contain the impacts of a disruption or manipulation to PNT services or data. 

The Respond Function serves as a list of recommended actions and is triggered by the outputs generated by the Detect Function. The Protect Function provides the ability for the Respond Function to execute the proper response to an event according to a predefined plan. 

The objectives of the Respond Function are to: 

- Contain PNT events using a verified response procedure 

- Communicate the occurrence and impact of the event on PNT data to PNT data users, applications, and stakeholders 

- Develop processes to respond to and mitigate new known or anticipated threats or vulnerabilities; and 

- Evolve response strategies and plans based on lessons learned 

The Respond Function within the Cybersecurity Framework defines five Categories, all of which have at least one Subcategory that applies to the PNT Profile to varying degrees, as summarized in Sec. 4.4.1 through <u>Sec. 4.4.5.</u> 

63

--- [page 72](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=72) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.4.1. Response Planning Category** 

Response processes and procedures are executed and maintained after detected cybersecurity incidents. 

There is one Subcategory within Response Planning that applies to the PNT Profile, as summarized in the table below. 

**Table 18.** Response Planning Subcategory Applicable to PNT 

|**Respond**<br>**Response Planning**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**RP-1:**<br>Response plan is executed<br>during or after an incident.|Execute the response plan during or after a cybersecurity event that<br>affects PNT systems in accordance with the predefined threshold.<br>Document the steps and results of the response plans as they are<br>being executed. Include categories of incidents and PNT resilience<br>level requirements based on application criticality and impact.<br>Update the response plans to address changes to the organization,<br>such as PNT system, attack vectors, environment of operation, and<br>problems encountered during plan implementation, execution, and<br>testing.|<br>**DHS RCF**5.3, 5.4, 6<br>**IMO 1575**C.2.1, C.2.2<br>**NIST SP 800-53 Rev. 5**CP-2, CP-10, IR-4, IR-8|



64

--- [page 73](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=73) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.4.2. Communications Category** 

Response activities are coordinated with internal and external stakeholders (e.g., external support from law enforcement agencies). In the context of this PNT Profile, external stakeholders may include sources that announce events that will impact the PNT service, such as PNT interference or corrections for leap seconds. 

There are four Subcategories within the Communications category that apply to the PNT Profile, as summarized in the table below. 

**Table 19.** Communications Subcategories Applicable to PNT 

|**Respond**<br>**Communications**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**CO-1:**<br>Personnel know their roles and<br>order of operations when a<br>response is needed.|Ensure that personnel are trained to respond to PNT disruptions and<br>manipulations and understand recovery time objectives (RTO),<br>recovery point objectives (RPO), restoration priorities, task<br>sequences, and assignment responsibilities for event response<br>programs and processes in a manner that is consistent with business<br>continuity objectives.|**DHS CISA**1.f, 7.a<br>**DHS RCF**5.2, 8.3<br>**IMO 1575**C.2.2<br>**NIST SP 800-61**<br>**NIST SP 800-34 Rev.1**3.2.1, CP-2, CP-3, IR-3,<br>IR-8<br>**NIST SP 800-53 Rev. 5**CP-2, CP-3, IR-3, IR-8<br>**USG FRP**5.1.2.5|
|**CO-2:**<br>Incidents are reported consistent<br>with established criteria.|<br>Ensure that cybersecurity events on the PNT system are reported in a<br>manner consistent with the response plan.<br>Suspected intentional interference should be reported to stakeholders<br>through the appropriate channels and procedures. For example,<br>suspected land-based RFI can be reported to NAVCEN, National<br>Aeronautics and Space Administration (NASA) Aviation Safety<br>Reporting System for aeronautics, or the North American Electric<br>Reliability Corporation (NERC) E-ISAC for the electric utility<br>sector.|<br>**DHS CISA IE**<br>**DHS IDM**<br>**FCC**<br>**GPS USER**<br>**ICAO 9849**7.12, Appendix F 6.1.1<br>**NAVCEN**<br>**NIST SP 800-53 Rev. 5**AU-6, IR-6, IR-8<br>**NIST SP 800-61 Rev. 2**4|



65

--- [page 74](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=74) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Respond**<br>**Communications**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|||**NERC CIP-008-6**<br>**NERC EISAC**<br>**USG FRP**|
|**CO-3:**<br>Information is shared consistent<br>with response plans.|Share cybersecurity incident information with relevant stakeholders<br>as defined in the organizational sharing policies.<br>Where feasible, consider enabling PNT systems and PNT data<br>information sharing to alert downstream users and applications of a<br>disruption or manipulation of PNT data, allowing applications and<br>users to respond in near real-time based on application tolerances.|**DHS CISA**1.d, 1.f<br>**DHS IDM**<br>**FCC**<br>**GPS USER**<br>**ICAO 9849**7.12, Appendix F 6.1.1<br>**IEEE 1588**7.6.2, 16.11, 16.12<br>**IETF CMP**<br>**NAVCEN**<br>**NERC EISAC**<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8<br>**NIST SP 800-61 Rev. 2**2.4|
|**CO-4:**<br>Coordination with stakeholders<br>occurs consistent with response<br>plans.|In the event of PNT disruption or manipulation, coordinate PNT<br>cybersecurity incident response actions with all relevant stakeholders<br>in accordance with predefined agreements.<br>When agreed upon between stakeholders, common data formats<br>facilitate information sharing to strengthen the protection of the user<br>community.|**DHS IDM**<br>**NERC EISAC**<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8, PE-6<br>**NIST SP 800-61 Rev. 2**2.4|



66

--- [page 75](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=75) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.4.3. Analysis Category** 

Analysis is conducted to verify effective response and support recovery activities. In the context of this PNT Profile, the analysis will include the direct recipients of PNT services as well as secondary or downstream effects. 

There are five Subcategories within the Analysis Category that apply to the PNT Profile, as summarized in the table below. 

**Table 20.** Analysis - Subcategories Applicable to PNT 

|**Respond**<br>**Analysis**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**AN-1:**|Investigate cybersecurity-related notifications generated from PNT<br>|**DHS IDM**|
|Notifications from detection<br>systems are investigated.|anomaly detection systems.<br>Identify and locate potential sources of RFI.<br>After determining that the source of a PNT data anomaly is<br>external to the organization’s system, partner with the appropriate<br>external stakeholders for further investigation. DHS coordinates<br>development, implementation, and exercise of procedures to enable<br>federal agencies with assigned responsibilities, authorities, and<br>jurisdictions to investigate and mitigate GNSS-based PNT<br>interference.|**ICAO 9849**Appendix F 6.2<br>**NIST SP 800-53 Rev. 5**AU-6, CA-7, IR-4, IR-5,<br>PE-6, RA-5, SI-4<br>**RTCA 235**14.1.2|
||Should multiple sensors report data anomaly events, analytics can<br>be used to determine if the events are correlated or otherwise<br>traced to a common causal agent.||
|**AN-2:**<br>The impact of the incident is<br>understood.|Understand the full implication of a cybersecurity incident based<br>on thorough investigation and analysis results.<br>Consider the organizational impacts on PNT services that may<br>affect downstream applications, users, and systems that are<br>dependent on PNT.<br>Understand downstream impacts and relationships through<br>leveraging mapped services and outlined policies.|**ITU-T G.8275.1**Annex D<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4, RA-3<br>**NIST SP 800-61 Rev. 2**3|



67

--- [page 76](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=76) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Respond**<br>**Analysis**<br>**Subcategory**|**Applicability to PNT**<br>Understand the scope and necessary actions required for<br>remediation.|**References (PNT-Specific)**|
|---|---|---|
|**AN-3:**<br>Forensics are performed.|Conduct forensic analysis on collected cybersecurity event<br>information to determine if the adversary left a footprint or if there<br>are any residual effects to the system.<br>Conduct forensic analysis to aid in determination of the root cause<br>of PNT disruption or manipulation.|**ICAO 9849**Appendix F 6.2<br>**NIST SP 800-53 Rev. 5**AU-7, IR-4<br>**NIST SP 800-61 Rev. 2**3|
|**AN-4:**<br>Incidents are categorized<br>consistent with response plans.|Categorize cybersecurity incidents according to the level of<br>severity and impact consistent with the response plan.|**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-5, IR-8,<br>RA-3<br>**NIST SP 800-61 Rev. 2**2 3.2|
|**AN-5:**<br>Processes are established to<br>receive, analyze, and respond to<br>vulnerabilities disclosed to the<br>organization from internal and<br>external sources (e.g., internal<br>testing, security bulletins, or<br>security researchers).|For PNT components and applications that are dependent on PNT<br>data, identify verification and validation procedures and processes<br>for anticipated and known threats in response to existing and newly<br>identified PNT fault and failure modes, including interfering<br>signals, natural phenomena, and internal system failures.<br>Reference available public and private trusted sources of threat and<br>vulnerability intelligence information as it relates to PNT.<br>Update PNT disruption event characterization documentation as<br>well as organization or industry-shared databases to track the<br>observed probability of occurrence in order to continuously update<br>the risk assessment and response plans. Analyze the impact of the<br>PNT data anomaly on user and application errors. Characterize<br>nominal and anomalous PNT data from the incident for improving<br>future monitoring and detection.|<br>**DHS RCF**7, 8<br>**DOT 12464**<br>**GPS-ICD-240**<br>**ICAO 9849**7.6, 7.7<br>**NCCIC**<br>**NIST SP 800-53 Rev. 5**CA-1, CA-2, PM-4,<br>PM-15, RA-1, RA-7, SI-5, SR-6<br>**NIST SP 800-61 Rev. 2**3, 3.2<br>**NIST SP 800-160 Rev. 1**3.4.9, 3.4.11<br>**NTP SEC**<br>**RTCA 326**3.4.4<br>**RTCA 356**3.8<br>**USG FRP**Appendix B|



68

--- [page 77](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=77) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.4.4. Mitigation Category** 

Activities are performed to contain an event, mitigate its effects, and resolve the incident. In the context of PNT, mitigation measures may include failover to alternate or a fusion of PNT sources, notification to or from external stakeholders of ongoing PNT anomalies, and other activities. 

There are three Subcategories within the Mitigation Category that apply to the PNT Profile, as summarized in the table below. 

**Table 21.** Mitigation Subcategories Applicable to PNT 

|**Respond**<br>**Mitigation**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**MI-1:**<br>Incidents are contained.|Contain cybersecurity incidents to minimize impacts on the PNT<br>system.<br>Containment of a PNT event may require notification of<br>downstream users and the transition to alternate or complementary<br>PNT sources in accordance with resiliency level requirements and<br>the business continuity plan for containment.|**DHS GPS CI**<br>**NIST SP 800-53 Rev. 5**IR-4<br>**NIST SP 800-61 Rev. 2**3.4.1|
|**MI-2:**<br>Incidents are mitigated.|Given successful containment measures, implement PNT- based<br>mitigation measures that can include alternate or complementary<br>sources in order to operate through the incident.<br>Once the effects of the incident are contained, take steps to return<br>the PNT system to a proper working state. These steps may include<br>resetting, recalibration, and replacement of units in a manner that<br>does not impact forensic efforts.<br>Apply patches and updates to mitigate the vulnerability or incident.<br>Mitigation procedures or measures should be part of the business<br>continuity plan.|<br> <br>**3GPP TR22.878**4, 5<br>**DHS GPS CI**<br>**DHS RCF**5.3, 5.4<br>**IMO 1575**C.2.1, C.2.2<br>**ITU-T G.8262**V<br>**ITU-T G.8272**7<br>**Kaplan**1.8, 13<br>**NIST SP 800-53 Rev. 5**IR-4|
||Consider mitigation strategies such as PNT source and data path<br>redundancy, diversity, and segmentation to minimize the impacts<br>of PNT disruption or manipulation.|**NIST SP 800-61 Rev. 2**3.4<br>**NTP SEC**|



69

--- [page 78](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=78) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Respond**<br>**Mitigation**<br>**Subcategory**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
||Complementary or alternative PNT sources may include on-board<br>sensors, clocks with acceptable holdover characteristics, other<br>satellite constellations, signal frequencies, terrestrial RF sources<br>(e.g., cellular, TBS), network-based PNT sources (e.g., NTP, PTP),<br>and other signals of opportunity.|**USG FRP**4|
|**MI-3:**<br>Newly identified vulnerabilities<br>are mitigated or documented as<br>accepted risks.|Risk assessments (refer to RA-1) should be updated with newly<br>identified PNT vulnerabilities and mitigated or documented as<br>acceptable risks.<br>Maintain an RFI incident database in order to inform future<br>mitigation strategies.|**NIST SP 800-53 Rev. 5**CA-2, CA-7, RA-3,<br>RA-5, RA-5<br>**NIST SP 800-61 Rev. 2**3<br>**NTP SEC**<br>**RTCA 235**14.1.4, 14.2-14.4<br>**RTCA 356**3.8|



70

--- [page 79](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=79) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.4.5. Improvements Category** 

Organizational response activities are improved by incorporating lessons learned from current and previous detection and response activities. Both Subcategories within the Improvements Category apply to the PNT Profile, as summarized in the table below. 

**Table 22.** Respond - Improvements Subcategories Applicable to PNT 

|**Respond**<br>**Improvements**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**IM-1:**<br>Response plans incorporate<br>lessons learned.|PNT response plans incorporate lessons learned from ongoing<br>incident handling activities into incident response procedures,<br>training, and testing and implement the resulting changes<br>accordingly.|**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8<br>**NIST SP-800-61 Rev. 2**|
|**IM-2:**<br>Response strategies are<br>updated.|Enable a process for the response plan to evolve to reflect new<br>threats, improved technology, and lessons learned.<br>Analyze detected event information and incident responses to gain<br>perspective on the impacts to the organization. Then correlate with<br>and, if necessary, update the risk assessment.|**DHS IDM**<br>**DOT 12464**<br>**ICAO 9849**6.3, 6.4, 6.5, 6.7, 6.8, 6.9<br>**IMO 1575**E.1|
||Determine preventative actions for fault modes by reviewing the<br>identification, protection, and detection functions and updating as<br>applicable.<br>Revise protection, monitoring, detection, response, and recovery<br>capabilities as needed to mitigate newly identified vulnerabilities in<br>a timely manner.<br>Industry standards may also need to evolve with new PNT<br>capabilities, taking into account changes in threat models as well as<br>technical, operational, and economic factors.|**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8<br>**NTP SEC**<br>**RTCA 326**3.4.1|



71

--- [page 80](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=80) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 



### **Recover Function** 

The Recover Function develops and implements the appropriate activities to maintain plans for resilience and restore any capabilities or services that were impaired due to a cybersecurity event. 

The activities in the Recover Function support timely recovery to normal operations and return the organization back to its proper working state after a disruption or manipulation of PNT services has occurred. The effectiveness of the Recover Function is dependent upon implementation of the previous functions—Identify, Protect, Detect, and Respond. 

The objectives of the Recovery Function are to: 

- Restore systems dependent upon PNT services to a proper working state using a verified recovery procedure 

- Communicate recovery activities and status of the PNT services to PNT data users, applications, and stakeholders; and 

- Evolve recovery strategies and plans based on lessons learned 

The Recover Function within the NIST Cybersecurity Framework defines three Categories. Other than identify appropriate PNT sources, all these Categories and Subcategories correlate with all the components of the EO. 

72

--- [page 81](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=81) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.5.1. Recovery Planning Category** 

Recovery processes and procedures are executed and maintained to restore systems or assets affected by cybersecurity incidents to a proper working state. 

There is one Subcategory within Recovery Planning that applies to the PNT Profile. 

**Table 23.** Recovery Planning Subcategory Applicable to PNT 

|**Recover**<br>**Recovery Planning**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Subcategory**|||
|**RP-1:**<br>Recovery plan is executed<br>during or after a cybersecurity<br>incident.|The business continuity plan should include a recovery plan.<br>Execute the recovery plan during or after a cybersecurity incident<br>on the PNT system.<br>Restore the PNT system within a predefined, acceptable time period<br>from configuration-controlled and integrity- protected information<br>representing a known, operational state for the components.<br>Perform system acceptance testing.<br>The recovery plan can include specific actions for restoration,<br>recalibration, resetting, and test validation of equipment.|<br>**DHS RCF**5, 6<br>**ICAO 9849**7.7<br>**IEEE 2030.101**5<br>**NIST SP 800-34 Rev. 1**<br>**NIST SP 800-53 Rev. 5**CP-10, IR-4, IR-8<br>**NIST SP 800-160 Rev. 1**3.4.11, Appendix F.2.6<br>**NIST SP 800-184**<br>**RTCA 229**2.4, 2.5|



73

--- [page 82](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=82) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.5.2. Improvements Category** 

Recovery planning and processes are improved by incorporating lessons learned into future activities. In the context of this PNT Profile, the efficacy of the recovery actions, such as restoration of the PNT system, test plans, user notification and failover, are evaluated and improved should a similar event occur. 

There are two Subcategories within the Improvements Category that apply to the PNT Profile, as summarized in the table below. 

**Table 24.** Recover - Improvements Subcategories Applicable to PNT 

|**Recover**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Improvements**|||
|**Subcategory**|||
|**IM-1:**<br>Recovery plans incorporate<br>lessons learned.|PNT recovery plans incorporate lessons learned from ongoing<br>incident handling activities into incident recovery procedures,<br>training, and testing and implement the resulting changes<br>accordingly.<br>Update the vulnerability, threat, impact, and risk assessment. The<br>data and resulting analysis will assist in the analyses of future<br>events, updating risk assessments, and the development of<br>monitoring, detection, response, and recovery features.|**DOT 12464**<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8<br>**NIST SP 800-61 Rev. 2**3.4<br>**NTP SEC**|
|**IM-2:**<br>Recovery strategies are updated.|Update the recovery plan to incorporate lessons learned, reflect<br>new threats, improve technology, and address changes to the<br>organization, PNT system, operating environment, and problems<br>encountered during plan implementation, execution, and testing.<br>Recovery timeliness and prioritization based on application<br>criticality are key to reducing impacts. Evaluate incident<br>characteristics to determine the optimal recovery strategy and<br>revise the recovery plan as needed.|**NIST SP 800-53 Rev. 5**CP-2, IR-4, IR-8<br>**NIST SP 800-61 Rev. 2**3.4<br>**RTCA 326**3.4.1|



74

--- [page 83](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=83) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **4.5.3. Communications Category** 

Restoration activities are coordinated with internal and external parties. In the context of this PNT Profile, external parties may include industry associations that provide insight with respect to how PNT services are restored after a PNT event, such as RFI. Restoration activities can include corrections for anomalies, calibrations, verification, and validation procedures. 

There are three Subcategories within the Communications Category that apply to the PNT Profile, as summarized in the table below. 

**Table 25.** Communications Subcategories Applicable to PNT 

|**Recover**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Communications**|||
|**Subcategory**|||
|**CO-1:**<br>Public relations are managed.|Centralize and coordinate information distribution and manage<br>the public-facing representation of the organization.<br>Public relations management may include managing media<br>interactions, creating privacy policies, coordinating and logging<br>all requests for interviews, handling and ‘triaging’ phone calls<br>and email requests, matching media requests with appropriate<br>and available internal experts who are ready to be interviewed,<br>screening all of the information provided to the media, and<br>ensuring that personnel are familiar with public relations.|**NIST SP 800-34 Rev. 2**4<br>**NIST SP 800-53 Rev. 5**IR-4<br>**NIST SP 800-184**2.4|
|**CO-2:**<br>Reputation is repaired after an<br>incident.|Employ a crisis response strategy to protect against negative<br>impacts and repair organizational reputation.<br>Crisis response strategies may include actions to shape<br>attributions of the crisis, change perceptions of the organization<br>in crisis, and reduce the negative effects generated by the crisis.|**NIST SP 800-53 Rev. 5**IR-4<br>**NIST SP 800-184**(all sections)|
|**CO-3:**<br>Recovery activities are<br>communicated to internal and<br>external stakeholders as well as<br>executive and management teams.|Communicate recovery activities to all relevant internal and<br>external stakeholders, executive teams, and management teams.|**DOT 12464**<br>**DHS S&T**<br>**NIST SP 800-34 Rev. 2**<br>**NIST SP 800-53 Rev. 5**CP-2, IR-4|



75

--- [page 84](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=84) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Recover**|**Applicability to PNT**|**References (PNT-Specific)**|
|---|---|---|
|**Communications**|||
|**Subcategory**|||
|||**NIST SP 800-184**|
|||**NTP SEC**|



76

--- [page 85](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=85) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **References** 

|[3GPP-TS22.071]|3rd Generation Partnership Project (2022) Location Services (LCS)<br>Service description Stage 1(Release 17) March 2022. (Technical<br>Specification Group Services and System Aspects, Sophia Antipolis,<br>France). Specification 22.071. Available at<br>https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDet<br>ails.aspx?specificationId=584|
|---|---|
|[3GPP-TR22.826]|3rd Generation Partnership Project (2021) Study on Communication<br>Services for Critical Medical Applications (Release 17.2) March 2021.<br>(Technical Specification Group Services and System Aspects, Sophia<br>Antipolis, France). Specification 22.826. Available at<br>https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDet<br>ail s.aspx?specificationId=3546|
|[3GPP-TR22.878]|3rd Generation Partnership Project (2021); Feasibility Study on 5G<br>Timing Resiliency System (Release 18.2) December 2021. (Technical<br>Specification Group Services and System Aspects, Sophia Antipolis,<br>France). Specification TR.878. Available at<br>https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDet<br>ail s.aspx?specificationId=3769|
|[3GPP-TS36.305]|3rd Generation Partnership Project (2022) Stage 2 functional<br>specification of User Equipment (UE) positioning in E-UTRAN<br>(Release 17) (Radio Access Network Evolved Universal Terrestrial<br>Radio Access Network (E- UTRAN,) March 2022. Specification<br>TS36.305. Available at<br>https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDet<br>ail s.aspx?specificationId=2433|
|[ATIS-I-0000070]|ATIS-I-0000070 (2018)_Context-Aware Identity Management_<br>_Framework_. (ATIS, Washington, DC). Available at<br>https://access.atis.org/apps/group_public/download.php/43565/ATIS-I-<br>0000070.pdf|
|[Barret2018]|Barrett M (2018)_Framework for Improving Critical Infrastructure_<br>_Cybersecurity Version 1.1, NIST Cybersecurity Framework_. Available<br>at:https://doi.org/10.6028/NIST.CSWP.04162018|
|[BDS-ICD]|China Satellite Navigation Office (2019)_BeiDou Navigation Satellite_<br>_System Signal In Space Interface Control Document Open Service_<br>_Signal B1I Version 3.0_.|
|[BIPM]|Bureau of Weights and Measures (2022)_Realizing and disseminating_<br>_international reference time scales UTC, UTCr and TT(BIPM)_(BIPM,<br>Paris, France). Available athttps://www.bipm.org/en/time-metrology|



77

--- [page 86](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=86) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[CNSSI-4009]|Committee on National Security Systems (2015)_Committee on_<br>_National Security Systems Glossary_. Committee on National Security<br>Systems Instruction (CNSSI) No. 4009, April 2015. Available at<br>https://rmf.org/wp-content/uploads/2017/10/CNSSI-4009.pdf|
|[Defraigne2022]|Defraigne P, Achkar J, Coleman MJ, Gertsvolf M, Ichikawa R, Levine<br>J, Uhrich P, Whibberley P, Wouters M, Bauch A. Achieving<br>traceability to UTC through GNSS measurements. Metrologia. 2022<br>Oct 28;59(6):064001. Available at<br>https://iopscience.iop.org/article/10.1088/1681-7575/ac98cb/pdf|
|[DHS-CISA]|Cybersecurity & Infrastructure Security Agency (2022) Time Guidance<br>for Network Operators, Chief Information Officers, and Chief<br>Information Security Officers, (DHS, Washington, DC). Available at<br>https://www.cisa.gov/sites/default/files/publications/time_guidance_net<br>work_operators_cios_cisos_508_0.pdf|
|[DHS-CISA-IE]|Cybersecurity & Infrastructure Security Agency (2022) Global<br>Positioning System Interference Event, (DHS, Washington, DC).<br>Available athttps://www.cisa.gov/sites/default/files/publications/CISA-<br>Insights_GPS-Interference_508.pdf|
|[DHS-GPS-CI]|Department of Homeland Security. Improving the Operation and<br>Development of Global Positioning System (GPS) Equipment Used by<br>Critical Infrastructure. (DHS, Washington, DC). Available at<br>https://www.cisa.gov/uscert/sites/default/files/documents/Improving_th<br>e_Operation_and_Development_of_Global_Positioning_System_%28<br>GPS%29_Equipment_Used_by_Critical_Infrastructure_S508C.pdf|
|[DHS-IDM]|Department of Homeland Security (2008) United States Positioning,<br>Navigation, and Timing Interference Detection and Mitigation Plan<br>Summary. (DHS, Washington, DC). Available at<br>https://www.gps.gov/news/2008/2008-04-idm-public-summary.pdf|
|[DHS-PNT]|Department of Homeland Security (2020) Report on Positioning,<br>Navigation, and Timing (PNT) Backup and Complementary<br>Capabilities to the Global Positioning System (GPS.) (DHS,<br>Washington, DC).Available at<br>https://www.cisa.gov/sites/default/files/publications/report- on-pnt-<br>backup-complementary-capabilities-to-gps_508.pdf|
|[DHS-RCF]|Department of Homeland Security (2022) Resilient PNT Conformance<br>Framework. (DHS, Washington, DC). Available at<br>https://www.dhs.gov/sites/default/files/2022-<br>05/22_0531_st_resilient_pnt_conformance_framework_v2.0.pdf|
|[DHS-S&T]|Department of Homeland Security (2020)_Science and Technology_<br>_Position, Navigation, and Timing (PNT) Program._(DHS, Washington,<br>DC). Available athttps://www.dhs.gov/science-and-technology/pnt-<br>program|



78

--- [page 87](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=87) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[DHS-S&T-2021]|Department of Homeland Security (2021)_GPS Receiver Allow List_<br>_Development Guide._(DHS, Washington, DC).Available at<br>https://www.dhs.gov/sites/default/files/2022-<br>11/22_1109_st_gps_allow_list_development_duide_v1.1.pdf|
|[DHS-S&T-2022]|Department of Homeland Security (2022)_Resilient Positioning,_<br>_Navigation, and Timing (PNT) Reference Architecture_ _Version 1.0_.<br>(DHS, Washington, DC). Available athttps://www.dhs.gov/science-<br>and-technology/publication/resilient-pnt-reference-architecture|
|[DHS-TFS]|Department of Homeland Security (2015) Best Practices for Improved<br>Robustness of Time and Frequency Sources in Fixed Locations_._(DHS,<br>Washington, DC). Available at<br>https://www.dhs.gov/sites/default/files/publications/GPS-PNT-Best-<br>Practices-Time-Frequency-Sources-Fixed-Locations-508.pdf|
|[DIA]|Defense Intelligence Agency (2022) DIA Challenges to Security in<br>Space. (DIA, Washington, DC). Available at<br>https://www.dia.mil/Portals/110/Documents/News/Military_Power_Pu<br>blications/Challenges_Security_Space_2022.pdf|
|[DOT]|Department of Transportation._What is Positioning, Navigation and_<br>_Timing (PNT)?_(Department of Transportation, Washington, DC).<br>Available athttps://www.transportation.gov/pnt/what-positioning-<br>navigation-and-timing-pnt|
|[DOT-CGSIC]|Department of Transportation. (2020)_Civil GPS Service Interface_<br>_Committee._(Department of Transportation. Washington, DC.)<br>Available athttps://www.gps.gov/cgsic/|
|[DOT-CMPS]|Department of Transportation (2020)_Global Positioning System (GPS)_<br>_Civil Monitoring Performance Specification, 3rd Edition_. (Department<br>of Transportation, Washington, DC), GPS Civil Monitoring<br>Performance Specification DOT-VNTSC-FAA-20-08. Available at<br>https://www.gps.gov/technical/ps/2020-civil-monitoring-performance-<br>specification.pdf|
|[DOT-12464]|Van Dyke K, Kovach K, Lavrakas J (2004) Status Update on GPS<br>Integrity Failure Modes and Effects Analysis. (Department of<br>Transportation, Washington, DC). Available at<br>https://rosap.ntl.bts.gov/view/dot/12464/dot_12464_DS1.pdf|
|[EO-13905]|Executive Order 13905 (2020) Strengthening National Resilience<br>Through Responsible Use of Positioning, Navigation, and Timing<br>Services. (The White House, Washington, DC), February 12, 2020.<br>https://www.govinfo.gov/app/details/FR-2020-02-18/2020-03337|
|[FCC]|Federal Communications Commission (2020) Jammer Enforcement.<br>(FCC, Washington DC). Available at<br>https://www.fcc.gov/general/jammer-enforcement|



79

--- [page 88](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=88) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[FCC-E911]|Federal Communications Commission (2020) Wireless E911 Location<br>Accuracy Requirements  Sixth Report and Order and Order on<br>Reconsideration-PS Docket No. 07-114 (FCC, Washington DC).<br>Available athttps://docs.fcc.gov/public/attachments/DOC-<br>365168A1.pdf|
|[FINRA-4590]|Financial Industry Regulatory Authority (2016)_4590. Synchronization_<br>_of Member Business Clocks._(FINRA, Washington, DC). Available at<br>https://www.finra.org/rules-guidance/rulebooks/finra-rules/4590|
|[GAL-ICD]|European GNSS (Galileo) Open Service (2021)_Signal-in-Space_<br>_Interface Control Document Issue 2.0._(European Union). Available at<br>https://www.gsceuropa.eu/sites/default/files/sites/all/files/Galileo_OS_<br>SIS_ICD_v2.0.pdf|
|[GDGPS]|National Aeronautics and Space Administration (2020)_The Global_<br>_Differential GPS System_(Jet Propulsion Laboratory, NASA, Pasadena,<br>CA). Available at https://www.gdgps.net/.|
|[GPS]|Department of Homeland Security, U.S. Coast Guard (1996)_Navstar_<br>_GPS User Equipment Introduction._(U.S. Coast Guard Navigation<br>Center, Department of Homeland Security, Alexandria, VA),<br>September 1996. Available at<br>https://www.navcen.uscg.gov/sites/default/files/pubs/gps/gpsuser/gpsus<br>er.pdf|
|[GPS-ICD-240]|SAIC (GPS SE&I) (2021)_Navstar GPS Control Segment to User_<br>_Support Community._(Air Force Space Command, Department of<br>Homeland Securit~~y,~~and the U.S. Coast Guard, Washington, DC),<br>Global Positioning System Interface Control Document ICD-GPS-<br>240C. Available athttps://www.gps.gov/technical/icwg/ICD-GPS-<br>240D.pdf|
|[GPS-ICD-870]|SAIC (GPS SE&I) (2020)_Navstar Next Generation GPS Control_<br>_Segment (OCX) to User Support Community Interface_. (Air Force<br>Space Command, Department of Homeland Security, Department of<br>Transportation, Federal Aviation Administration, and the U.S. Coast<br>Guard, Washington, DC), Global Positioning System Interface Control<br>Document ICD-GPS-870E. Available at<br>https://www.gps.gov/technical/icwg/ICD-GPS-870E.pdf|
|[GPS-GNSS]|National Coordination Office for Space-Based Positioning, Navigation,<br>and Timing (2020)_Other Global Navigation Satellite Systems (GNSS)._<br>Available athttps://www.gps.gov/systems/gnss/|
|[GPS-IS-200]|SAIC (GPS SE&I) (2022)_Navstar GPS Space Segment/Navigation_<br>_User Segment Interfaces_. (Air Force Space Command, Washington,<br>DC), Global Positioning System Interface Specification Document IS-<br>GPS- 200N. Available athttps://www.gps.gov/technical/icwg/IS-GPS-<br>200N.pdf|



80

--- [page 89](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=89) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[GPS-IS-705]|SAIC (GPS SE&I) (2021)_Navstar GPS Space Segment/User Segment_<br>_L5 Interfaces_. (Air Force Space Command, Washington, DC) , Global<br>Positioning System Interface Specification Document IS-GPS-705D.<br>Available athttps://www.gps.gov/technical/icwg/IS-GPS-705H.pdf|
|---|---|
|[GPS-IS-800]|SAIC (GPS SE&I) (2021)_Navstar GPS Space Segment/User Segment_<br>_L1C Interfaces_. (Air Force Space Command, Washington, DC) , Global<br>Positioning System Interface Specification Document IS-GPS-800D.<br>Available athttps://www.gps.gov/technical/icwg/IS-GPS-800H.pdf|
|[GPS-SPS]|U.S. Department of Defense (2020)_Global Positioning System (GPS)_<br>_Standard Positioning Service Performance Standard_, 5th Edition.<br>(Department of Defense, Washington, DC). Available at<br>https://www.gps.gov/technical/ps/2020-SPS-performance-standard.pdf|
|[GPS-USER]|Department of Transportation (2022)_Global Positioning System (GPS)_<br>_Service Outages and Status Reports_. (Department of Transportation,<br>Washington, DC). Available athttps://www.gps.gov/support/user/|
|[IANA-TZDB]|Internet Assigned Numbers Authority (2022)_Time Zone Database_.<br>(IANA, Los Angeles, CA). Available athttps://www.iana.org/time-<br>zones|
|[ICAO-9849]|International Civil Aviation Organization (2017)_Doc 9849 Global_<br>_Navigation Satellite System Manual._Third edition. (Montréal, Québec).<br>Available at<br>https://www.icao.int/Meetings/anconf12/Documents/Doc.%209849.pdf|
|[ICS-CERT]|Cybersecurity & Infrastructure Security Agency (2020) Industrial<br>Control Systems. (DHS, Washington, DC). Available athttps://us-<br>cert.cisa.gov/ics|
|[IEC-61850-90-4]|International Electrotechnical Commission (2020)_IEC 61850-90-4:_<br>_2020 Communication Networks and Systems for Power Utility_<br>_Automation - Part 90-4: Network Engineering Guidelines_(IEC,<br>Geneva, Switzerland). Available at<br>https://webstore.iec.ch/publication/64801|
|[IEC-61850-90-12]|International Electrotechnical Commission (2020)_IEC 61850-90-_<br>_12:2020 Communication networks and systems for power utility_<br>_automation - Part 90-12: Wide area network engineering guidelines._<br>(IEC Geneva, Switzerland). Available at<br>https://webstore.iec.ch/publication/63706|
|[IEC-62439-3]|International Electrotechnical Commission (2021)_IEC 62439-3_<br>_Industrial communication networks - High availability automation_<br>_networks - Part 3: Parallel Redundancy Protocol (PRP) and High-_<br>_availability Seamless Redundancy (HSR)._(IEC, Geneva, Switzerland).<br>Available athttps://webstore.iec.ch/publication/64423|



81

--- [page 90](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=90) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[IEEE-C37.238]|IEEE Standards Association (2017)_IEEE C37.238:2017 IEEE_<br>_Standard Profile for Use of IEEE 1588 Precision Time Protocol in_<br>_Power System Applications_(IEEE SA, Piscataway, NJ). Available at<br>https://standards.ieee.org/standard/C37_238-2017.html|
|---|---|
|[IEEE-802.1AS]|IEEE Standards Association (2020)_IEEE 802.1AS Timing and_<br>_Synchronization for Time Sensitive Applications_(IEEE SA,<br>Piscataway, NJ). Available at<br>https://standards.ieee.org/ieee/802.1AS/7121/|
|[IEEE-1588]|IEEE Standards Association (2019)_IEEE 1588:2019 IEEE Standard_<br>_for a Precision Clock Synchronization Protocol for Networked_<br>_Measurement and Control System_(IEEE SA, Piscataway, NJ).<br>Available athttps://standards.ieee.org/standard/1588-2019.html|
|[IEEE-1139]|IEEE Standards Association (2008)_IEEE 1139:2008 Standard_<br>_Definitions of Physical Quantities for Fundamental Frequency and_<br>_Time Metrology---Random Instabilities_(IEEE SA, Piscataway, NJ).<br>Available at doi:https://doi.org/10.1109/IEEESTD.2008.4797525.|
|[IEEE-1193]|IEEE Standards Association (2003)_IEEE 1193:2003 IEEE Guide for_<br>_Measurement of Environmental Sensitivities of Standard Frequency_<br>_Generators_(IEEE SA, Piscataway, NJ). Available at doi:<br>https://doi.org/10.1109/IEEESTD.2004.94440.(_Undergoing Revision)_|
|[IEEE-2030.101]|IEEE Standards Association (2018)_IEEE 2030.101:2018 Guide for_<br>_Designing a Time Synchronization System for Power Substations_(IEEE<br>SA, Piscataway, NJ). Available at<br>https://standards.ieee.org/standard/2030_101-2018.html|
|[IERS]|International Earth Rotation and Reference Systems Service (2022)<br>_IERS Bulletins_(IERS, Paris, France). Available at<br>https://datacenter.iers.org/bulletins.php|
|[IETF-4082]|Perrig A, Song D, Canetti D, Tygar, JD, Briscoe, B (2005) Timed<br>Efficient Stream Loss-Tolerant Authentication (TESLA): Multicast<br>Source Authentication Transform Introduction (Internet Engineering<br>Task Force (IETF) Network Working Group), IETF Request for<br>Comments (RFC) 4082. Available athttps://tools.ietf.org/html/rfc4082|
|[IETF-5905]|Mills D, Martin J, Burbank J, and Kach W._Network Time Protocol_<br>_Version 4: Protocol and Algorithms Specification._(Internet<br>Engineering Task Force (IETF) Network Working Group) Available at<br>https://datatracker.ietf.org/doc/html/rfc5905|
|[IETF-7384]|Mizrahi T (2014) Security Requirements for Time Protocols in Packet<br>Switched Networks. Introduction (Internet Engineering Task Force<br>(IETF) Network Working Group), IETF Request for Comments (RFC)<br>7384. Available athttps://tools.ietf.org/html/rfc7384|



82

--- [page 91](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=91) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[IETF-8573]|Malhotra A, Goldberg S (2019) Message Authentication Code for the<br>Network Time Protocol (Internet Engineering Task Force (IETF)<br>Network Working Group), IETF Request for Comments (RFC) 8573.<br>Available athttps://tools.ietf.org/html/rfc8573|
|[IETF-8633]|Reilly D, Stenn H, Sibold D (2019) Network Time Protocol Best<br>Current Practices. (Internet Engineering Task Force (IETF) Network<br>Working Group), IETF Request for Comments (RFC) 8633. Available<br>athttps://tools.ietf.org/html/rfc8633|
|[IETF-8915]|Franke D, Sibold D, Danserie M, Sunblad R, Teichel K (2020) Using<br>the Network Time Security Specification to Secure the Network Time<br>Protocol. (Internet Engineering Task Force (IETF) Network Working<br>Group), IETF Request for Comments (RFC) 88915. Available at<br>https://tools.ietf.org/html/rfc8915|
|[IETF-CMP]|Haberman B (2020) Control Messages Protocol for Use with Network<br>Time Protocol. Internet Engineering Task Force (IETF) Network<br>Working Group), V4 Draft. Available at<br>https://datatracker.ietf.org/doc/html/draft-ietf-ntp-mode-6-cmds-10|
|[IETF-NTS]|Franke D, Sibold D, Teichel K, Dansarie M, Sundblad R (2020)<br>Network Time Security for the Network Time Protocol Internet<br>Engineering Task Force (IETF) Network Time Protocol Working<br>Group). Available athttps://tools.ietf.org/html/draft-ietf-ntp-using-nts-<br>for-ntp-28|
|[IMO-1575]|International Maritime Organization (2017) MSC.1/Circular.1575 -<br>Guidelines for Shipborne Position, Navigation and Timing (PNT) Data<br>Processing Guidelines for Shipborne Position, Navigation and Timing.<br>(IMO, London, England). Available at<br>https://www.imorules.com/MSCCIRC_1575.html|
|[ISO-15288]|International Organization for Standardization (2015)_ISO/IEC/IEEE_<br>_15288 Systems and software engineering – Life cycle processes_(ISO,<br>Geneva, Switzerland), May. 2015. Available at<br>https://www.iso.org/standard/63711.html|
|[ISO-16085]|International Organization for Standardization (2021)_ISO/IEC/IEEE_<br>_16085 Systems and software engineering – Life cycle processes – Risk_<br>_management_. (ISO, Geneva, Switzerland), Jan. 2021. Available at<br>https://www.iso.org/standard/74371.html|
|[ISO-17025]|International Organization for Standardization (2017)_ISO/IEC 17025_<br>_General Requirements for the Competence of Testing and Calibration_<br>_Laboratories_. (ISO, Geneva, Switzerland), Corrigendum 1, Mar. 2018.<br>Available athttps://www.iso.org/standard/66912.html|
|[ISO-17666]|International Organization for Standardization (2016)_ISO/IEC 17666_<br>_Space systems – Risk management_. (ISO, Geneva, Switzerland), Nov.<br>2016. Available athttps://www.iso.org/standard/69239.html|



83

--- [page 92](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=92) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[ISO-27001]|International Organization for Standardization (2022)_ISO/IEC 27001_<br>_Information security, cybersecurity and privacy protection –_<br>_Information security management systems - Requirements_. (ISO,<br>Geneva, Switzerland), Oct. 2022. Available at<br>https://www.iso.org/standard/82875.html|
|[ITRF]|International Earth Rotation and Reference Systems Service (2022)<br>_ITRF2020 International Terrestrial Reference Frame_. (IERS<br>International Terrestrial Reference System Centre, Paris, France), Oct.<br>2022. Available athttps://itrf.ign.fr/en/homepage|
|[ITU-T-810]|International Telecommunications Union Telecommunications<br>Standardization Sector (1996)_ITU-T G.810, Definitions and_<br>_Terminology for Synchronization Networks._(ITU-T, Geneva,<br>Switzerland), Corrigendum 1, Nov. 2001. Available at<br>https://www.itu.int/rec/T-REC-G.810/en|
|[ITU-T-G.8261]|International Telecommunications Union Telecommunications<br>Standardization Sector (2019)_ITU-T G.8261/Y.1361 Timing and_<br>_synchronization aspects in packet networks._(ITU-T, Geneva,<br>Switzerland). Available athttps://www.itu.int/rec/T-REC-G.8261-<br>201908-I/en|
|[ITU-T-G.8262]|International Telecommunications Union Telecommunications<br>Standardization Sector (2018)_ITU-T G.8262/Y.1367 Timing_<br>_Characteristics of Primary Reference Time Clocks._(ITU-T, Geneva,<br>Switzerland). Available athttps://www.itu.int/rec/T-REC-G.8262|
|[ITU-T-G.8272]|International Telecommunications Union Telecommunications<br>Standardization Sector (2018)_ITU-T G.8262/Y.1367 Timing_<br>_Characteristics of Primary Reference Time Clocks._(ITU-T, Geneva,<br>Switzerland). Available athttps://www.itu.int/rec/T-REC-G.8272/en|
|[ITU-T-G.8275.1]|International Telecommunications Union Telecommunications<br>Standardization Sector (2022) ITU-T G.8275.1/Y.1369.1 Amendment 3<br>_Precision Time Protocol Telecom Profile for Phase/Time_<br>_Synchronization with Full Timing Support from The Network._(ITU-T,<br>Geneva, Switzerland). Available athttps://www.itu.int/rec/T-REC-<br>G.8275.1/en|
|[ITU-T-GNSS]|International Telecommunications Union Telecommunications<br>Standardization Sector (2020)_ITU-T GSTR-GNSS Considerations on_<br>_the use of GNSS as a primary time reference in telecommunications_<br>(ITU-T, Geneva, Switzerland). Available at<br>https://www.itu.int/dms_pub/itu- t/opb/tut/T-TUT-HOME-2020-PDF-<br>E.pdf|
|[Kaplan2017]|Kaplan E, Hegarty C. (2017)._Understanding GPS/GNSS: principles_<br>_and applications._(Artech House, Boston MA). 3rd ed.|



84

--- [page 93](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=93) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[Levine2021]|Levine J (2021) Distributing Time and Frequency Information.<br>Position, Navigation, and Timing Technologies in the 21st Century:<br>Integrated Satellite Navigation, Sensor Systems, and Civil Applications<br>Volume 1, Chapter 29:821-848 (IEEE Press, Piscataway, NJ).<br>Available athttps://tf.nist.gov/general/pdf/2940.pdf|
|---|---|
|[Matsakis2018]|Matsakis D, Levine J, Lombardi, M (2018) Metrological and legal<br>traceability of time signals. (National Institute of Standards and<br>Technology, Gaithersburg, MD). Available at<br>https://tf.nist.gov/general/pdf/2941.pdf|
|[NASIC]|National Air and Space Intelligence Center (2019) Competing in Space.<br>(NASIC, Dayton, OH). Available at<br>https://media.defense.gov/2019/Jan/16/2002080386/-1/-1/1/190115-F-<br>NV711-0002.PDF|
|[NAVCEN]|Department of Homeland Security. U.S. Coast Guard (2020)_GPS_<br>_Problem Reporting._(DHS, USCG, Washington DC). Available at<br>https://www.navcen.uscg.gov/report-a-problem|
|[NCCIC]|Department of Homeland Security (2012)_National Cybersecurity &_<br>_Communications Integration Center (NCCIC) Overview_(DHS,<br>Washington, DC). Available at<br>https://csrc.nist.gov/CSRC/media/Events/ISPAB-OCTOBER-2012-<br>MEETING/documents/ispab_oct2012_lzelvin_nccic-overview.pdf|
|[NDAA]|Department of Defense, General Services Administration, and National<br>Aeronautics and Space Administration (2019) Interim Rule Issued by<br>DoD, GSA, and NASA (DoD, GSA, and NASA, Washington, DC).<br>Available athttps://www.acquisition.gov/FAR-Case-2019-<br>009/889_Part_B|
|[NERC-CIP-008-6]|North American Electric Reliability Corporation (2020)_CIP-008-6_<br>_Cyber Security Incident Reporting and Response Planning._Available at<br>https://www.nerc.com/pa/Stand/Reliability%20Standards/CIP-008-<br>6.pdf|
|[NERC-EISAC]|North American Electric Reliability Corporation (2020)_Electricity_<br>_Information Sharing and Analysis Center._Available at<br>https://www.nerc.com/pa/CI/ESISAC/Pages/default.aspx|
|[NERC-GRIDEX]|North American Electric Reliability Corporation (2020)_GridEx._<br>Available athttps://www.nerc.com/pa/CI/ESISAC/Pages/GridEx.aspx|
|[NIST-CSF]|National Institute of Standards and Technology (2018) Framework for<br>Improving Critical Infrastructure Cybersecurity, Version 1.1. (National<br>Institute of Standards and Technology, Gaithersburg, MD).<br>https://doi.org/10.6028/NIST.CSWP.04162018|
|[NIST-CSRC]|NIST Information Technology Laboratory (2022) Computer Security<br>Resource Center_Glossary_. Available athttps://csrc.nist.gov/glossary|



85

--- [page 94](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=94) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[NIST-FIPS-200]|National Institute of Standards and Technology (2006) Minimum<br>Security Requirements for Federal Information and Information<br>Systems. (U.S. Department of Commerce, Washington, DC), Federal<br>Information Processing Standards Publication (FIPS) 200.<br>https://doi.org/10.6028/NIST.FIPS.200|
|[NISTIR-8014]|Hastings N, Franklin, J (2015) Considerations for Identity Management<br>in Public Safety Mobile Networks. (National Institute of Standards and<br>Technology, Gaithersburg, MD), NIST Interagency or Internal Report<br>(IR) 8014.https://doi.org/10.6028/NIST.IR.8014|
|[NISTIR-8320]|Bartock M, Souppaya M, Savino R, Knoll T, Shetty U, Cherfaoui M,<br>Yeluri R, Malhotra, Banks D, Jordan M, Pendarakis D, Rao, JR,<br>Romness P, Scarfone K (2022) Hardware-Enabled Security: Enabling a<br>Layered Approach to Platform Security for Cloud and Edge Computing<br>Use Cases. (National Institute of Standards and Technology,<br>Gaithersburg, MD).<br>https://nvlpubs.nist.gov/nistpubs/ir/2022/NIST.IR.8320.pdf|
|[NIST-JRES-120.017]|Yao J, Levine J, Weiss M (2015) Toward Continuous GPS Carrier-<br>Phase Time Transfer: Eliminating the Time Discontinuity at an<br>Anomaly. NIST Journal of Research 120: 280-292.<br>https://doi.org/10.6028/jres.120.017|
|[NIST-SP-250-29]|Kamas G, Lombardi, M (2004) Remote Frequency Calibrations: The<br>NIST Frequency Measurement and Analysis Service. (National<br>Institute of Standards and Technology, Gaithersburg, MD), NIST<br>Special Publication (SP) 250-29, Rev. E. Available<br>athttps://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=105424|
|[NIST-SP-800-30]|Joint Task Force Transformation Initiative (2012) Guide for<br>Conducting Risk Assessments. (National Institute of Standards and<br>Technology, Gaithersburg, MD), NIST Special Publication (SP) 800-<br>30, Rev. 1.https://doi.org/10.6028/NIST.SP.800-30r1|
|[NIST-SP-800-34]|Swanson MA, Bowen P, Phillips AW, Gallup D, Lynes D (2010)<br>Contingency Planning Guide for Federal Information Systems.<br>(National Institute of Standards and Technology, Gaithersburg, MD),<br>NIST Special Publication (SP) 800-34, Rev. 1, Includes updates as of<br>November 11, 2010.https://doi.org/10.6028/NIST.SP.800-34r1|
|[NIST-SP-800-37]|Joint Task Force (2018) Risk Management Framework for Information<br>Systems and Organizations: A System Life Cycle Approach for<br>Security and Privacy. (National Institute of Standards and Technology,<br>Gaithersburg, MD), NIST Special Publication (SP) 800-37, Rev. 2.<br>https://doi.org/10.6028/NIST.SP.800-37r2|



86

--- [page 95](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=95) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[NIST-SP-800-39]|Joint Task Force Transformation Initiative (2011) Managing<br>Information Security Risk: Organization, Mission, and Information<br>System View. (National Institute of Standards and Technology,<br>Gaithersburg, MD), NIST Special Publication (SP) 800-39.<br>https://doi.org/10.6028/NIST.SP.800-39|
|---|---|
|[NIST-SP-800-53]|Joint Task Force Transformation Initiative (2020) Security and Privacy<br>Controls for Federal Information Systems and Organizations. (National<br>Institute of Standards and Technology, Gaithersburg, MD), NIST<br>Special Publication (SP) 800-53, Rev. 5, Includes updates as of<br>December 10, 2020.https://doi.org/10.6028/NIST.SP.800-53r5|
|[NIST-SP-800-61]|Cichonski PR, Millar T, Grance T, Scarfone KA (2012) Computer<br>Security Incident Handling Guide. (National Institute of Standards and<br>Technology, Gaithersburg, MD), NIST Special Publication (SP) 800-<br>61, Rev. 2.https://doi.org/10.6028/NIST.SP.800-61r2|
|[NIST-SP-800-98]|Karygiannis T, Eydt B, Barber G, Bunn L, Phillips T (2007) Guidelines<br>for Securing Radio Frequency Identification (RFID) Systems. (National<br>Institute of Standards and Technology, Gaithersburg, MD), NIST<br>Special Publication (SP) 800-98.https://doi.org/10.6028/NIST.SP.800-<br>98|
|[NIST SP 800-115]|Scarfone KA, Souppaya MP, Cody A, Orebaugh AD (2008) Technical<br>Guide to Information Security Testing and Assessment. (National<br>Institute of Standards and Technology, Gaithersburg, MD), NIST<br>Special Publication (SP) 800-115.<br>https://doi.org/10.6028/NIST.SP.800-115|
|[NIST-SP-800-160]|Ross R, Graubart R, Bodeau D, McQuaid R (2016) Systems Security<br>Engineering: Cyber Resiliency Considerations for the Engineering of<br>Trustworthy Secure Systems (National Institute of Standards and<br>Technology, Gaithersburg, MD), NIST Special Publication (SP) 800-<br>160,Vol. 1, Rev.1.https://doi.org/10.6028/NIST.SP.800-160v1|
|[NIST-SP-800-160-2]|Ross R, Pillitteri VY, Graubart R, Bodeau D, McQuaid R (2021)<br>Systems Security Engineering: Cyber Resiliency Considerations for the<br>Engineering of Trustworthy Secure Systems (National Institute of<br>Standards and Technology, Gaithersburg, MD), NIST Special<br>Publication (SP) 800-160,Vol. 2, Rev. 1.<br>https://doi.org/10.6028/NIST.SP.800-160v2r1|
|[NIST-SP-800-161]|Boyens J, Bartol N, Winkler K, Holbrook A, Fallon M (2022) Supply<br>Chain Risk Management Practices for Federal Information Systems and<br>Organizations, (National Institute of Standards and Technology,<br>Gaithersburg, MD), NIST Special Publication (SP) 800-161, Rev. 1.<br>Available at<br>https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-<br>161r1.pdf|



87

--- [page 96](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=96) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[NIST-SP-800-184]|Bartock MJ, Scarfone KA, Smith MC, Witte GA, Cichonski JA,<br>Souppaya MP (2016) Guide for Cybersecurity Event Recovery.<br>(National Institute of Standards and Technology, Gaithersburg, MD),<br>NIST Special Publication (SP) 800-184.<br>https://doi.org/10.6028/NIST.SP.800-184|
|---|---|
|[NIST-SP-1065]|Riley W, Howe DA (2008) Handbook of Frequency Stability Analysis.<br>(National Institute of Standards and Technology, Gaithersburg, MD),<br>NIST Special Publication (SP) 1065. Available at<br>https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=50505|
|[NIST-T&F-Glossary]|NIST Physical Measurement Laboratory, Time and Frequency Division<br>(2020)_Time and Frequency Glossary from A to Z_. Available at<br>https://www.nist.gov/pml/time-and-frequency-division/popular-<br>links/time- frequency-z|
|[NIST-TN-1366]|Volk CM, Levine J (1994) Analytical Estimation of Carrier Multipath<br>Bias on GPS Position Measurements. (National Institute of Standards<br>and Technology, Gaithersburg, MD), NIST Technical Note (TN) 1366.<br>Available athttp://doi.org/10.6028/NIST.TN.1366|
|[NIST-TN-2187]|Sherman JA, Arissian L, Brown RC, Deutch MJ, Donley EA, Gerginov<br>V, Levine J, Nelson GK, Novick AN, Patla BR, Parker TE, Stuhl BK,<br>Sutton DD, Yao J, Yates WC, Zhang V, Lombardi MA (2021) A<br>Resilient Architecture for the Realization and Distribution of<br>Coordinated Universal Time to Critical Infrastructure Systems in the<br>United States. (National Institute of Standards and Technology,<br>Gaithersburg, MD), NIST Technical Note (TN) 2187.  Available at<br>https://nvlpubs.nist.gov/nistpubs/TechnicalNotes/NIST.TN.2187.pdf|
|[NIST-USNO]|NIST Physical Measurement Laboratory, Time and Frequency Division<br>(2022) NIST USNO. Available athttps://www.nist.gov/pml/time-and-<br>frequency-division/time-services/nist-usno|
|[NOAA-SWS]|NOAA Space Weather Prediction Center (2022) NOAA Space Weather<br>Scales. Available athttps://www.swpc.noaa.gov/noaa-scales-<br>explanation|
|[NTP-MON]|Network Time Protocol (2020)_Who is using my NTP server?_Available<br>at<br>http://support.ntp.org/bin/view/Support/MonitoringAndControllingNTP<br>#Who_is_using_my_NTP_server|
|[NTP-SEC]|Network Time Protocol (2020)_NTP Security Notice._Available at<br>http://support.ntp.org/bin/view/Main/SecurityNotice|
|[PPD-21]|Presidential Policy Directive (PPD)-21 (2013) Critical Infrastructure<br>Security and Resilience. (The White House, Washington, DC),<br>DCPD201300092, February 12, 2013.<br>https://www.govinfo.gov/content/pkg/DCPD-201300092/html/DCPD-<br>201300092.htm|



88

--- [page 97](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=97) ---

Foundational PNT Profile 

|NIST IR 8323r1<br>January 2023|Foundational PNT Profile|
|---|---|
|[RTCA-229]|Radio Technical Commission for Aeronautics (2020)_RTCA DO-229_<br>_Minimum Operational Performance Standards for Global Positioning_<br>_Systems/Satellite-Based Augmentation System Airborne Equipment_.<br>(RTCA, Washington, DC). Available at<br>https://my.rtca.org/NC__Product?id=a1B36000001IcklEAC|
|[RTCA-235]|Radio Technical Commission for Aeronautics (2008)_RTCA DO-235A_<br>_Assessment of Radio Frequency Interference Relevant to the GNSS LI_<br>_Frequency Band_. (RTCA, Washington, DC). Available at<br>https://my.rtca.org/NC__Product?id=a1B36000001IckKEAS|
|[RTCA-292]|Radio Technical Commission for Aeronautics (2004)_RTCA DO-292_<br>_Assessment of Radio Frequency Interference Relevant to the GNSS_<br>_L5/E5A Frequency Band_. (RTCA, Washington, DC). Available at<br>https://my.rtca.org/nc__store?search=292|
|[RTCA-316]|Radio Technical Commission for Aeronautics (2009)_RTCA DO-316_<br>_Minimum Operational Performance Standards for Global Positioning_<br>_System/Aircraft Base Augmentation System._(RTCA, Washington, DC).<br>Available athttps://my.rtca.org/nc__store?search=316|
|[RTCA-326]|Radio Technical Commission for Aeronautics (2010)_RTCA D DO-326_<br>_- Airworthiness Security Process Specification_. (RTCA, Washington,<br>DC). Available athttps://my.rtca.org/nc__store?search=326|
|[RTCA-356]|Radio Technical Commission for Aeronautics (2018)_RTCA DO-356A_<br>_Airworthiness Security Methods and Considerations_. (RTCA,<br>Washington, DC). Available athttps://my.rtca.org/NC<br>Product?id=a1B36000001IcelEAC|
|[SEC-613]|Securities Exchange Commission (2020) Rule 613 (Consolidated Audit<br>Trail.) (SEC, Washington, DC). Available at<br>https://www.sec.gov/divisions/marketreg/rule613-info.htm|
|[SNMP3]|Case J, et al. Simple Network Management Protocol, Version 3<br>(Internet Engineering Task Force (IETF) Network Working Group),<br>IETF Request for Comments (RFC) 3410 through (RFC) 3418.<br>Available athttps://tools.ietf.org/html/rfc3410,<br>https://tools.ietf.org/html/rfc3411, https://tools.ietf.org/html/rfc3412,<br>https://tools.ietf.org/html/rfc3413, https://tools.ietf.org/html/rfc3414,<br>https://tools.ietf.org/html/rfc3415, https://tools.ietf.org/html/rfc3416,<br>https://tools.ietf.org/html/rfc3417, https://tools.ietf.org/html/rfc3418|
|[SNMPSEC]|Cybersecurity & Infrastructure Security Agency (2017) Reducing the<br>Risk of SNMP Abuse. Alert (TA17-156A) (DHS, Washington, DC).<br>Available athttps://us-cert.cisa.gov/ncas/alerts/TA17-156A|
|[SPD-7]|Space Policy Directive 7 (SPD)-7 (2021) The United States Space-<br>Based Positioning, Navigation, and Timing Policy. (The White House,<br>Washington, DC), DCPD-202100025, January 15, 2021. Available at<br>https://www.govinfo.gov/app/details/DCPD-202100025|



89

--- [page 98](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=98) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|[USG-FRP]|Department of Defense, Department of Homeland Security, and<br>Department of Transportation (2021) 2021 Federal Radionavigation<br>Plan (Department of Transportation, Washington DC). Available at<br>https://www.navcen.uscg.gov/nav-pubs-and-documents-general-library|
|---|---|
|[USNG]|Federal Geographic Data Committee (2001) Standard for A U.S.<br>National Grid, FGDC-STD-011-2001. (FGDC, Reston, VA). Available<br>at<br>https://www.fgdc.gov/standards/projects/usng/TFIGURES_6.pdf/at_do<br>wn load/file|
|[USNO-GPS]|United States Naval Observatory (2022) GPS Time Transfer (U.S.<br>Navy, Washington DC). Available<br>athttps://www.cnmoc.usff.navy.mil/Our-Commands/United-States-<br>Naval-Observatory/Precise-Time-Department/Global-Positioning-<br>System/USNO-GPS-Time-Transfer/|
|[VIM]|Joint Committee on Guides in Metrology (2012) International<br>Vocabulary of Metrology – Basic and General Concepts and Associated<br>Terms (VIM 3rd Edition), (BIPM, Cedex France). 200:2012. Available<br>athttps://www.bipm.org/en/publications/guides/#vim|



90

--- [page 99](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=99) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix A. Selected Bibliography** 

3rd Generation Partnership Project (2020) _3GPP TS 22.104 Service Reequipments for Cyberphysical Control Applications in Vertical Domains._ (3GPP, Sophia Antipolis, France). Available at 

<u>https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId</u> =3528 

3rd Generation Partnership Project (2018) _R2-1817172 Overview of UE Time Synchronization Methods._ (3GPP, Sophia Antipolis, France). Available at <u>https://www.3gpp.org/ftp/TSG_RAN/WG2_RL2/TSGR2_104/Docs/R2-1817172.zip</u> 

3rd Generation Partnership Project (2020) _SID: Feasibility Study on 5G Timing Resiliency System FS_5TRS._ (3GPP, Sophia Antipolis, France). Available at <u>https://portal.3gpp.org/ngppapp/CreateTDoc.aspx?mode=view&contributionUid=S1-202281</u> 

https://www.afrl.af.mil/News/Article/2874807/afrls-pnt-agilepod-achieves-flight-testobjectives/https://doi.org/10.21236/ADA290597 or <u>https://afresearchlab.com/technology/sensors/agilepod/</u> 

ATIS (2017) _ATIS-0900005 GPS Vulnerability_ . (ATIS, Washington, DC). Available at <u>https://access.atis.org/apps/group_public/download.php/36304/ATIS-0900005.pdf</u> 

Allan DW, Weiss MA (1980) Accurate Time and Frequency Transfer During Common-View of a GPS Satellite, _34th Annual Frequency Control Symposium_ , (U.S. Army Electronic Research and Development Command, Philadelphia, PA) pp. 334-346. Available at <u>https://apps.dtic.mil/dtic/tr/fulltext/u2/a213670.pdf</u> 

Anand DM, Freiheit C, Weiss, MA, Shenoi K, Ossareh H (2019) A Timing Impairment Module for Electrical Synchrometrology. _2019 IEEE International Symposium on Precision Clock Synchronization for Measurement, Control, and Communication (ISPCS)_ , (IEEE, Portland, OR), pp. 1-7. Available at https://ieeexplore.ieee.org/document/8886638 

Boehm BW (1991) Software risk management: Principles and practices. _IEEE Software_ , vol. 8, no.1, pp. 32–41. Available at https://doi.org/10.1109/52.62930 

Communications Security, Reliability, And Interoperability Council VII (2020) Final Report - Risks to 5G from Legacy Vulnerabilities and Best Practices for Mitigation. _(Working Group 2: Managing Security Risk in the Transition to 5, CSRIC, Washington, DC)._ Available at <u>https://www.fcc.gov/file/18918/download</u> 

CTIA (2019) Protecting America’s Next-Generation Networks (CTIA, Washington, DC). Available at https://api.ctia.org/wp- <u>content/uploads/2018/07/ProtectingAmericasNetworks_FINAL.pdf</u> 

Department of Defense. (2015) _DoD Program Manager’s Guidebook for Integrating the Cybersecurity Risk Management Framework (RMF) into the System Acquisition Lifecycle_ . (DOD, Washington, DC). Available at 

91

--- [page 100](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=100) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

<u>https://www.dau.edu/tools/Lists/DAUTools/Attachments/37/DoD%20%20Guidebook,%20Cybersecurity%20Risk%20Management%20Framework,%20v1.08,%20Se p%202015.pdf</u> 

Dropping B, Coggins K, Platt J. (2018) Timing Security: Mitigating Threats in a Changing Landscape Webinar. (ATIS, Washington, DC). Available at https://www.atis.org/wp- <u>content/uploads/01_news_events/webinar-pptslides/Timing-Security5222018.pdf</u> 

Egea-Roca D, Arizabaleta-Diez M, Pany T, Antreich F, Lopez-Salcedo JA, Paonni M, SecoGranados G (2022) GNSS User Technology: State-of-the-Art and Future Trends. _IEEE Access_ , vol. 10, pp.39939–39968. Available at https://doi.org/10.1109/ACCESS.2022.3165594 

Electric Power Research Institute (2020) Roadmap for Resilient Positioning, Navigation, and Timing (PNT) For the Electricity Subsector. (EPRI, Washington, DC). Available at <u>https://www.epri.com/research/products/000000003002020266</u> 

European Securities and Markets Authority (2017) Guidelines Transaction Reporting, Order Record Keeping and Clock Synchronisation Under MiFID II. (EMSA, Lison, Portugal). Available at https://www.esma.europa.eu/sites/default/files/library/2016- <u>1452_guidelines_mifid_ii_transaction_reporting.pdf</u> 

Executive Order 13636 (2013) Improving Critical Infrastructure Cybersecurity. (The White House, Washington, DC), DCPD-201300091, February 12, 2013. Available at <u>https://www.govinfo.gov/content/pkg/FR-2013-02-19/pdf/2013-03915.pdf</u> 

Federal Aviation Administration, Department of Transportation (2020) _NOTAMS, TFRs, Aircraft Safety Alerts_ (Department of Transportation, Washington, DC). Available at <u>https://www.faa.gov/pilots/safety/notams_tfr/</u> 

Federal Aviation Administration, U.S. Department of Transportation (2021) _Wide Area Augmentation System._ Available at https://www.faa.gov/sites/faa.gov/files/about/office_org/headquarters_offices/ato/WAAS_QF <u>Sheet.pdf</u> 

Federal Aviation Administration, U.S. Department of Transportation (2021) _SBAS Worldwide._ Available at https://www.faa.gov/sites/faa.gov/files/2021- <u>12/SBAS_Worldwide_quick_facts.pdf</u> 

Federal Trade Commission (2020) _Jammer Enforcement._ (FCC, Washington, DC). Available at <u>https://www.fcc.gov/general/jammer-enforcement</u> 

Hopkin P (2018) Fundamentals of risk management: Understanding, evaluating and implementing effective risk management. Kogan Page Publishers. Available at <u>http://dspace.vnbrims.org:13000/xmlui/bitstream/handle/123456789/5077/Fundamentals%20of% 20Risk%20Management.pdf?sequence=1</u> 

International Maritime Organization (2002) IMO Resolution A.915(22) Revised Maritime Policy and Requirements for a Future GNSS. (IMO, London, England). Available at 

92

--- [page 101](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=101) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

<u>https://wwwcdn.imo.org/localresources/en/KnowledgeCentre/IndexofIMOResolutions/Assembly Documents/A.915(22).pdf</u> 

International Organization for Standardization (2018) ISO 31000:2018 – Risk management – Guidelines (ISO, Geneva, Switzerland). Available at https://www.iso.org/standard/65694.html 

International Organization for Standardization/International Electrotechnical Commission (2018) ISO/IEC 27005:2018 – Information technology – Security techniques – Information security risk management (ISO, Geneva, Switzerland). Available at https://www.iso.org/standard/75281.html 

Joint Task Force Transformation Initiative (2011) Managing Information Security Risk: Organization, Mission, and Information System View. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Special Publication (SP) 800-39. <u>https://doi.org/10.6028/NIST.SP.800-39</u> 

Haimes, Y. Y., Kaplan, S., & Lambert, J. H. (2002). Risk filtering, ranking, and management framework using hierarchical holographic modeling. Risk Analysis, 22(2), 383-397. 

Lambert JH, Keisler JM, Wheeler WE, Collier ZA, Linkov I (2013). Multiscale approach to the security of hardware supply chains for energy systems. _Environment Systems and Decisions_ , vol. 33 no.3, pp.326-334. Available at https://doi.org/10.1007/s10669-013-9465-2 

Levine J (1999) Introduction to time and frequency metrology. _Review of scientific instruments_ 70(6):2567-2596. Available at https://tf.nist.gov/general/pdf/1288.pdf 

Levine J (2016) Measuring Time and Comparing Clocks. (National Institute of Standards and Technology, Gaithersburg, MD). Available at https://tf.nist.gov/general/pdf/2718.pdf 

Lightman S, Suloway T, Brule J (2022) Satellite Ground Segment: Applying the Cybersecurity Framework to Assure Satellite Command and Control (National Institute of Standards and Technology, Gaithersburg, MD), NIST Interagency or Internal Report (IR) 8401 (Draft). Available at https://nvlpubs.nist.gov/nistpubs/ir/2022/NIST.IR.8401.ipd.pdf 

Linkov I, Bridges T, Creutzig F, Decker J, Fox-Lent C, Kröger W, Lambert JH, Levermann A, Montreuil B, Nathwani J, Nyer R (2014) Changing the resilience paradigm. Nature Climate Change. vol.4, no. 6, pp.407-9. 

National Institute of Standards and Technology (2020) _NIST Time Calibration Services._ (National Institute of Standards and Technology, Gaithersburg, MD). Available at <u>https://www.nist.gov/programs-projects/time-measurement-and-analysis-service-tmas</u> 

National Oceanic and Atmospheric Association (2020) _National Geodetic Survey. Antenna Calibrations._ (NOAA, Washington, DC). Available at https://www.ngs.noaa.gov/ANTCAL/ 

Nighswander T, Ledvina B, Diamond J, Brumley R, Brumley D (2012) GPS Software Attacks. _Proceedings of the 2012 ACM Conference on Computer and Communications Security._ (Association for Computer Machinery, Raleigh, NC), pp. 450-461. <u>https://dl.acm.org/doi/10.1145/2382196.2382245</u> 

93

--- [page 102](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=102) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

North American Electrical Reliability Corporation (2020) _Reliability Standards for the Bulk Electric Systems of North America, Standard BAL-001-2 – Real Power Balancing Control Performance_ . (NERC, Washington, DC). Available at <u>https://www.nerc.com/pa/Stand/Reliability%20Standards%20Complete%20Set/RSCompleteSet. pdf</u> 

Paulsen C, Boyens JM, Bartol N, Winkler K (2018) Criticality Analysis Process Model: Prioritizing Systems and Components. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Interagency or Internal Report (IR) 8179. <u>https://doi.org/10.6028/NIST.IR.8179</u> 

Plumb J, Larson KM, White J, Powers E (2005) Absolute calibration of a geodetic time transfer system. _IEEE Transactions on Ultrasonics, Ferroelectrics, and Frequency Control_ 52(11):190411. Available at <u>https://ieeexplore.ieee.org/abstract/document/1561658</u> 

Psiaki M, Humphreys T (2016) GNSS Spoofing and Detection _. Proceedings of the IEEE,_ (IEEE, Piscataway, NJ), pp 1258-1270. 

Savory J, Sherman J, Romisch S (2018) White rabbit-based time distribution at NIST. _IEEE International Frequency Control Symposium (IFCS)_ (IEEE, Piscataway, NJ), pp. 1-5. Available at https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=925954 

Stouffer KA, Lightman S, Pillitteri VY, Abrams M, Hahn A (2015) Guide to Industrial Control Systems (ICS) Security. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Special Publication (SP) 800-82, Rev. 2. https://doi.org/10.6028/NIST.SP.800-82r2 

Sullivan DB, Allan DW, Howe DA, Walls FL eds. (1990) Characterization of Clocks and Oscillators. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Technical Note (TN) 1337. <u>https://doi.org/10.6028/NIST.TN.1337</u> 

University of Texas (2020) _Texas Spoofing Test Battery (TEXBAT)._ (University of Texas, Austin, TX). Available at <u>https://radionavlab.ae.utexas.edu/index.php?option=com_content&view=article&id=289:texasspoofing-test-battery-texbat&catid=50&Itemid=27</u> 

Lombardi MA (2002) Fundamentals of Time and Frequency. _The Mechatronics Handbook_ . Available at https://tf.nist.gov/general/pdf/1498.pdf 

Lombardi MA (2010) A NIST disciplined oscillator: Delivering UTC (NIST) to the calibration laboratory. _NCSLi Measure_ 5(4):46-54. Available at https://tf.nist.gov/general/pdf/2478.pdf 

Lombardi MA, Nelson LM, Novick AN, Zhang VS (2001) Time and Frequency Measurements Using the Global Positioning System. _Cal. Lab. Int. J. Metrology_ July-September:26-33. Available at https://tf.nist.gov/general/pdf/1424.pdf 

Mader GL (1999) GPS antenna calibration at the National Geodetic Survey. _GPS solutions_ 3(1):50-8. https://link.springer.com/article/10.1007/PL00012780 

94

--- [page 103](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=103) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

McCarthy J, Mamula D, Brule J, Meldorf K (2022) Cybersecurity Profile for Hybrid Satellite Networks (HSN) Cybersecurity. (National Institute of Standards and Technology, Gaithersburg, MD), NIST Cybersecurity White Paper (CSWP) 27 (Initial Public Draft). Available at <u>https://nvlpubs.nist.gov/nistpubs/CSWP/NIST.CSWP.27.ipd.pdf</u> 

Morton YJ, van Diggelen F, Spilker Jr JJ, Parkinson BW, Lo S, Gao G (2021) Position, Navigation, and Timing Technologies in the 21st Century, Volumes 1 and 2: Integrated Satellite Navigation, Sensor Systems, and Civil Applications. (IEEE Press, Piscataway, NJ). Available at <u>https://ieeexplore.ieee.org/book/9304973</u> 

NASPI Time Synchronization Task Force (2017) _Time Synchronization in the Electric Power System. NASPI Technical Report._ (North American Synchrophasor Initiative). Available at <u>https://www.naspi.org/sites/default/files/reference_documents/tstf_electric_power_system_report _pnnl_26331_march_2017_0.pdf</u> 

National Emergency Number Association (2022) _NENA-STA-026.5 NENA PSAP Master Clock Standard_ (NENA, Alexandria, VA). Available at https://cdn.ymaws.com/www.nena.org/resource/resmgr/standards/nena-sta-026.5- <u>2022_psap_mas.pdf</u> 

National Institute of Standards and Technology (2006) Minimum Security Requirements for Federal Information and Information Systems. (U.S. Department of Commerce, Washington, DC), Federal Information Processing Standards Publication (FIPS) 200. <u>https://doi.org/10.6028/NIST.FIPS.200</u> 

National Institute of Standards and Technology (2020) _NIST Frequency Calibration Services._ (National Institute of Standards and Technology, Gaithersburg, MD). Available at <u>https://www.nist.gov/programs-projects/frequency-measurement-and-analysis-service-fmas</u> 

National Institute of Standards and Technology (2020) _NIST Internet Time Service._ (National Institute of Standards and Technology, Gaithersburg, MD). Available at <u>https://www.nist.gov/time-distribution/internet-time-service-its</u> 

Ray J, Senior, K (2005) Geodetic techniques for time and frequency comparisons using GPS phase and code measurements. _Metrologia_ , 42(4), 215. 

Scholl M, Suloway T (2022) Introduction to Cybersecurity for Commercial Satellite Operations (National Institute of Standards and Technology, Gaithersburg, MD), NIST Interagency or Internal Report (IR) 8270  (2<sup>nd</sup> Draft). Available at <u>https://nvlpubs.nist.gov/nistpubs/ir/2022/NIST.IR.8270-draft2.pdf</u> 

Wang F, Li H, Lu M (2017) GNSS Spoofing Detection and Mitigation Based on Maximum Likelihood Estimation. _Sensors,_ 17:1532. 

Wong E. (2020) Responsible Use of PNT for DLT in the Financial Services Sector ATIS Time and Money Conference (New York, NY). Available at <u>https://www.gps.gov/multimedia/presentations/2020/ATIS/wong.pdf</u> 

95

--- [page 104](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=104) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

Yao J, Lombardi MA, Novick N, Patla B, Sherman JA, Zhang VS. (2016) The Effects of the January 2016 UTC Offset Anomaly on GPS-Controlled Clocks Monitored At NIST. (National Institute of Standards and Technology, Gaithersburg, MD.) Available at <u>https://tf.nist.gov/general/pdf/2886.pdf</u> 

Yao J, Weiss M, Curry C, Levine J (2016) GPS Jamming and GPS Carrier-Phase Time Transfer. _Proceedings of the 2016 Precise Time and Time Interval Meeting, ION-PTTI 2016_ (Monterey CA), pp 80-85. Available at https://www.nist.gov/publications/gps-jamming-and-gps-carrier- <u>phase-time-transfer</u> 

96

--- [page 105](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=105) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix B. List of Symbols, Abbreviations, and Acronyms** 

#### **CISA** 

Cybersecurity and Infrastructure Security Agency 

#### **CRPA** 

Controlled Reception Pattern Antenna 

#### **CSF** 

Cybersecurity Framework 

#### **DHS** 

Department of Homeland Security 

#### **DOT** 

Department of Transportation 

#### **EISAC** 

Electricity Information Sharing and Analysis Center 

#### **EO** 

Executive Order 

#### **FCC** 

Federal Communications Commission 

#### **FPGA** 

Field-programmable Gate Array 

#### **GDGPS** 

Global Differential GPS System 

#### **GNSS** 

Global Navigation Satellite System 

#### **GPS** 

Global Positioning System 

#### **HMI** 

Human Machine Interface 

#### **ICS** 

Industrial Control System 

#### **IDM** 

Interference Detection and Mitigation 

#### **IEC** 

International Electrotechnical Commission 

#### **IEEE** 

Institute of Electrical and Electronics Engineers 

#### **IERS** 

International Earth Rotation and Reference Systems Service 

#### **IETF** 

Internet Engineering Task Force 

97

--- [page 106](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=106) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **IMO** 

International Maritime Organization 

#### **IMU** 

Inertial Measurement Units 

#### **INS** 

Inertial Navigation Systems 

#### **IoT** 

Internet of Things 

#### **IRIG** 

Inter-range Instrumentation Group Time Code 

#### **IRIG-B** 

Inter-range Instrumentation Group Time Code B 

#### **ISAC** 

Information Sharing and Analysis Center 

#### **ISO** 

International Organization for Standardization 

#### **IT** 

Information Technology 

#### **ITRS** 

International Terrestrial Reference System 

#### **ITRF** 

International Terrestrial Reference Frame 

#### **ITU-T** 

International Telecommunication Union International Telecommunications Standardization Sector 

#### **NANU** 

Notice Advisory to Navstar Users 

#### **NASA** 

National Aeronautics and Space Administration 

#### **NAVCEN** 

U.S. Coast Guard Navigation Center 

#### **NCCIC** 

National Cybersecurity and Communications Integration Center 

#### **NERC** 

North American Electric Reliability Corporation 

#### **NGS** 

National Geodetic Survey 

#### **NIST** 

National Institute of Standards and Technology 

#### **NOTAM** 

Notices to Air Missions 

98

--- [page 107](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=107) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **NTP** 

Network Time Protocol 

#### **NTP SEC** 

NTP Security Notice 

#### **OEM** 

Original Equipment Manufacturer 

#### **PII** 

Personally Identifiable Information 

#### **PIN** 

Personal Identification Number 

#### **PNT** 

Positioning, Navigation, And Timing 

#### **PNT Profile** 

Foundational PNT Profile: Applying the Cybersecurity Framework for the Responsible Use of Positioning, Navigation, and Timing (PNT) Services 

#### **PPS** 

Pulse Per Second 

#### **PTP** 

Precision Time Protocol 

#### **RAIM** 

Receiver Autonomous Integrity Monitoring 

#### **RF** 

Radio Frequency 

#### **RFC** 

Request for Comments 

#### **RFI** 

Radio Frequency Interference 

#### **RPO** 

Recovery Point Objective 

#### **RTO** 

Recovery Time Objective 

#### **SCADA** 

Supervisory Control and Data Acquisition 

#### **SLA** 

Service-Level Agreement 

#### **SP** 

Special Publication 

#### **SPS** 

Standard Positioning Service 

#### **TAI** 

International Atomic Time 

99

--- [page 108](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=108) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **TBS** 

Terrestrial Beacon System 

#### **USG FRP** 

U.S. Government Federal Radionavigation Plan 

#### **USNO** 

United States Naval Observatory 

#### **UTC** 

Coordinated Universal Time 

#### **VPN** 

Virtual Private Network 

#### **WAAS** 

Wide Area Augmentation System 

#### **WLAN** 

Wireless Local Area Network 

#### **WGS 84** 

World Geodetic System 1984 

100

--- [page 109](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=109) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix C. Glossary** 

#### **accuracy (absolute)** 

The degree of conformity of a measured or calculated value to the true value, typically based on a global reference system. For time, the global reference can be based on the following time scales: UTC, International Atomic Time (TAI), or GPS. For position, the global reference can be WGS 84. 

#### **accuracy (relative)** 

The degree of agreement between measured or calculated values among the devices and applications dependent on the position, navigation, or time data at an instant in time. 

#### **agility** 

The property of a system or an infrastructure that can be reconfigured, in which resources can be reallocated, and in which components can be reused or repurposed so that cyber defenders can define, select, and tailor cyber courses of action for a broad range of disruptions or malicious cyber activities. [NIST-SP-800-160-2] 

#### **Allan deviation** 

A non-classical statistic used to estimate stability. The NIST equation for the Allan deviation (with non-overlapping samples) is 



#### **atomic clock** 

A clock referenced to an atomic oscillator. Only clocks with an internal atomic oscillator qualify as atomic clocks. [NIST-T&F-Glossary, adapted] 

#### **atomic oscillator** 

An oscillator that uses the quantized energy levels in atoms or molecules as the source of its resonance. The laws of quantum mechanics dictate that the energies of a bound system, such as an atom, have certain discrete values. An electromagnetic field at a particular frequency can boost an atom from one energy level to a higher one, or an atom at a high energy level can drop to a lower level by emitting energy. The resonance frequency, fo, of an atomic oscillator is the difference between the two energy levels divided by Planck’s constant, _h_ . 

The principle underlying the atomic oscillator is that since all atoms of a specific element are identical, they should produce exactly the same frequency when they absorb or release energy. In theory, the atom is a perfect “pendulum” whose oscillations are counted to measure a time interval. The national frequency standards developed by NIST and other laboratories derive their resonance frequency from the cesium atom and typically use cesium fountain technology. Rubidium oscillators are the lowest priced and most common atomic oscillators, but cesium beam and hydrogen maser atomic oscillators are also sold commercially in much smaller quantities. [NIST-T&F-Glossary] 

#### **attack** 

Any kind of malicious activity that attempts to collect, disrupt, deny, degrade, or destroy information system resources or the information itself. [CNSSI-4009] 

101

--- [page 110](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=110) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **availability (PNT)** 

The availability of a PNT system is the percentage of time that the services of the system are usable. Availability is an indication of the ability of the system to provide usable service within the specified coverage area. Signal availability is the percentage of time that PNT signals transmitted from external sources are available for use. Availability is a function of both the physical characteristics of the environment and the technical capabilities of the PNT service provider. [USG-FRP (Appendix E), adapted] 

#### **calibration** 

A comparison between a device under test and an established standard, such as UTC(NIST). When the calibration is finished, it should be possible to state the estimated time offset and/or frequency offset of the device under test with respect to the standard, as well as the measurement uncertainty. Calibrations can be absolute or relative. Absolute calibrations are not biased by the calibration reference and would, therefore, be more reproducible. However, absolute calibrations can be more complex to determine. The bias in relative calibrations would be consistent if all the devices in the system are calibrated against the same calibration reference. Calibrations may also be performed relative to other devices without reference to an absolute standard. Relative calibrations are generally simpler to perform than absolute calibrations. [NIST-T&F-Glossary, adapted] 

#### **characterization** 

An extended test of the performance characteristics of a clock or oscillator. A characterization involves more work than a typical calibration. The device under test is usually measured for a long period of time (days or weeks), and sometimes, a series of measurements is made under different environmental conditions. A characterization is often used to determine the types of noise that limit the uncertainty of the measurement and the sensitivity of the device to environmental changes. [NIST-T&F-Glossary] 

#### **clock** 

A device that generates periodic, accurately spaced signals for timekeeping applications. A clock consists of at least three parts: an oscillator, a device that counts the oscillations and converts them to units of time interval (such as seconds, minutes, hours, and days), and a means of displaying or recording the results. [NIST-T&F-Glossary] 

#### **component** 

A hardware, software, firmware part or element of a larger PNT system with well-defined inputs and outputs and a specific function. [NIST-SP-800-160, adapted] [DHS-RCF, adapted] 

#### **confidentiality** 

Preserving authorized restrictions on information access and disclosure, including means for protecting personal privacy and proprietary information. [NIST-FIPS-200] 

#### **continuity** 

The probability that the specified PNT system performance will be maintained for the duration of a phase of operation, presuming that the PNT system was available at the beginning of that phase of operation. [USG-FRP] 

#### **coverage** 

The surface area or space volume in which the signals are adequate to permit the user to determine a position to a specified level of accuracy. Coverage is influenced by system geometry, signal power levels, receiver sensitivity, atmospheric noise conditions, and other factors that affect signal availability. [USG-FRP] 

#### **cybersecurity** 

Prevention of damage to, protection of, and restoration of computers, electronic communications systems, electronic communications services, wire communication, and electronic communication, including information contained therein, to ensure its availability, integrity, authentication, confidentiality, and nonrepudiation. For example, PNT data is generated by cyber systems. Protection of the devices and systems used to generate PNT data should be considered part of cybersecurity. [NIST-SP-800-53] 

#### **delay (path delay)** 

The [signal] delay between a transmitter and a receiver. Path delay is often the largest contributor to time transfer uncertainty. For example, consider a radio signal broadcast over a 1000 km path. Since radio signals travel at the speed of light (with a delay of about 3.3 µs/km), we can calibrate the 1000 km path by estimating the path delay as 3.3 ms and applying a 3.3 ms correction to our measurement. Sophisticated time transfer systems, such as GPS, 

102

--- [page 111](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=111) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

automatically correct for path delay. The absolute path delay is not important to frequency transfer systems because on-time pulses are not required, but variations in path delay still limit the frequency uncertainty. [NIST-T&F- <u>Glossary, adapted]</u> 

#### **disciplined oscillator** 

An oscillator whose output frequency is continuously adjusted (often through the use of a phase locked loop) to agree with an external reference. For example, a GPS disciplined oscillator (GPSDO) usually consists of a quartz or rubidium oscillator whose output frequency is continuously adjusted to agree with signals broadcast by the GPS satellites. 

#### **frequency** 

The rate of a repetitive event. If _T_ is the period of a repetitive event, then the frequency _f_ is its reciprocal, 1/ _T_ . Conversely, the period is the reciprocal of the frequency, _T_ = 1/ _f_ . Because the period is a time interval expressed in seconds (s), it is easy to see the close relationship between time interval and frequency. The standard unit for frequency is the hertz (Hz), defined as the number of events or cycles per second. The frequency of electrical signals is often measured in multiples of hertz, including kilohertz (kHz), megahertz (MHz), or gigahertz (GHz). [NIST- <u>T&F-Glossary]</u> 

#### **frequency accuracy** 

The degree of conformity of a measured or calculated frequency to its definition. Because accuracy is related to the offset from an ideal value, frequency accuracy is usually stated in terms of the frequency offset. [NIST-T&F- <u>Glossary]</u> 

#### **frequency drift** 

An undesired progressive change in frequency with time. Frequency drift can be caused by instability in the oscillator and environmental changes, although it is often hard to distinguish between drift and oscillator aging. Frequency drift may be in either direction (resulting in a higher or lower frequency) and is not necessarily linear. [NIST-T&F-Glossary] 

#### **frequency offset** 

The difference between a measured frequency and an ideal frequency with zero uncertainty. This ideal frequency is called the nominal frequency. [NIST-T&F-Glossary] 

Frequency offset can be measured in either the frequency domain or the time domain. A simple frequency domain measurement involves directly counting and displaying the output frequency of the device under test with a frequency counter. The frequency offset is calculated as **𝑜**<sup>**𝑚𝑚**</sup> 

𝑓𝑓𝑜 **𝑜** 𝑜𝑜 =<sup>𝑓𝑓𝑚</sup><sup>**𝑚**𝑚</sup> _f_<sup>**𝑚**</sup> _nom_<sup>−𝑓𝑓𝑛𝑛𝑜𝑜𝑚𝑚</sup> 𝑓𝑓𝑛𝑛𝑜𝑜𝑚𝑚 

where _fmeas_ is the reading from the frequency counter, and **𝑜**<sup>**𝑚**</sup> _f_<sup>**𝑚**</sup> _nom_ is the specified output frequency of the device under test. 

Frequency offset measurements in the time domain involve measuring the time difference between the device under test and the reference. The time interval measurements can be made with an oscilloscope or a time interval counter. If at least two time interval measurements are made, frequency offset can be estimated as where ∆ _t_ is the difference between time interval measurements (phase difference), and 𝑓𝑓𝑜 **𝑜** 𝑜𝑜 = −<sup>∆𝑡𝑡</sup> _T_ is the measurement period. 𝑇𝑇 

where ∆ _t_ is the difference between time interval measurements (phase difference), and 𝑓𝑓𝑜 **𝑜** _T_ is the measurement period. [NIST-T&F-Glossary, Adapted] 

#### **frequency stability** 

The degree to which an oscillating signal produces the same frequency for a specified interval of time. It is important to note the time interval—some devices have good short-term stability while others have good long-term stability. Stability does not determine whether the frequency of a signal is right or wrong. It only indicates whether that frequency stays the same. The Allan deviation is the most common metric used to estimate frequency stability, but several similar statistics are also used. [NIST-T&F-Glossary] 

103

--- [page 112](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=112) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **Global Navigation Satellite System** 

GNSS collectively refers to the worldwide positioning, navigation, and timing (PNT) determination capability available from one or more satellite constellations. Each GNSS system employs a constellation of satellites that operate in conjunction with a network of ground stations. Receivers and system integrity monitoring are augmented as necessary to support the required position, navigation, and timing performance for the intended operation. [USG- <u>FRP, adapted] [ICAO-9849, adapted]</u> 

#### **Global Positioning System** 

The Global Positioning System (GPS) is a U.S.-owned utility that provides users with positioning, navigation, and timing (PNT) services. This system consists of three segments: the space segment, the control segment, and the user segment. The U.S. Space Force develops, maintains, and operates the space and control segments. [GPS-GNSS] 

#### **holdover** 

An operating condition of a clock that has lost its controlling reference input, is using its local oscillator, and can be augmented with stored data acquired while locked to the reference input or a frequency reference to control its output. 

#### **integrity** 

A measure of the trust that can be placed in the correctness of the information supplied by a PNT service provider. Integrity includes the ability of the system to provide timely warnings to users when the PNT data should not be used. [USG-FRP] 

#### **interchangeable** 

The ability to combine signals from multiple PNT data sources into a single PNT solution, as well as the ability to provide a solution from an alternative source when a primary source is not available. [USG-FRP] 

#### **interference (electromagnetic)** 

Any electromagnetic disturbance that interrupts, obstructs, degrades, or otherwise limits the performance of user equipment. [USG-FRP (Appendix E)] 

#### **jamming** 

An attack that attempts to interfere with the reception of broadcast communications. [CNSSI-4009] 

A deliberate communications disruption meant to degrade the operational performance of the RF subsystem. Jamming is achieved by interjecting electromagnetic waves on the same frequency that the reader to tag uses for communication. [NIST-SP-800-98] 

The deliberate radiation, reradiation, or reflection of electromagnetic energy for the purpose of preventing or reducing the effective use of a signal. [USG-FRP (Appendix E)] 

#### **jitter** 

The short-term variations of the significant instants of a timing signal from their ideal positions in time (where shortterm implies that these variations are of frequency greater than or equal to 10 Hz). [ITU-T-810] 

#### **leap second** 

A second added to Coordinated Universal Time (UTC) to make it agree with astronomical time to within 0.9 second. UTC is an atomic time scale based on the performance of atomic clocks. Astronomical time is based on the rotational rate of the Earth. Since atomic clocks are more stable than the rate at which the Earth rotates, leap seconds are needed to keep the two time scales in agreement. [NIST-T&F-Glossary, adapted] 

#### **multipath** 

The propagation phenomenon that results in signals reaching the receiving antenna by two or more paths. When two or more signals arrive simultaneously, wave interference results. The received signal fades if the wave interference is time varying or if one of the terminals is in motion. [USG-FRP (Appendix E)] 

#### **navigation** 

The ability to determine a current and desired position (relative or absolute) and apply corrections to course, orientation, and speed to attain a desired position. Navigation coverage requirements could be global, from subsurface to surface and from surface to space. [DOT, adapted] 

104

--- [page 113](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=113) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **nominal frequency** 

An ideal frequency with zero uncertainty. The nominal frequency is the frequency labeled on an oscillator’s output. For this reason, it is sometimes called the nameplate frequency. For example, an oscillator whose nameplate or label reads 5 MHz has a nominal frequency of 5 MHz. The difference between the nominal frequency and the actual output frequency of the oscillator is the frequency offset. [NIST-T&F-Glossary] 

#### **oscillator** 

An electronic device used to generate an oscillating signal. The oscillation is based on a periodic event that repeats at a constant rate. The device that controls this event is called a resonator. The resonator needs an energy source so it can sustain oscillation. Taken together, the energy source and resonator form an oscillator. Although many simple types of oscillators (both mechanical and electronic) exist, the two types of oscillators primarily used for time and frequency measurements are quartz oscillators and atomic oscillators. [NIST-T&F-Glossary] 

#### **PNT data** 

All information used to form or disseminate PNT solutions, including signals, waveforms, and network packets. 

#### **PNT solution** 

The full solution provided by a PNT system or source, including time, position, and velocity. A PNT system or source may provide a full PNT solution or a part of it. For example, a GNSS receiver provides a full PNT solution, while a local clock provides only a timing or frequency solution. [DHS-RCF] 

#### **PNT source** 

A PNT system component that is used to produce a PNT solution. Examples include GNSS receivers, networked and local clocks, inertial navigation systems (INS), and timing services provided over a wired or wireless connection. [DHS-RCF] 

#### **PNT system** 

The components, processes, and parameters that collectively produce the final PNT solution for the consumer. [DHS-RCF] 

#### **phase** 

The position of a point in time (instant) on a waveform cycle. A complete cycle is defined as the interval required for the waveform to retain its arbitrary initial value. [NIST-T&F-Glossary] 

#### **phenomenologies** 

Physical phenomena such as radio frequencies, inertial sensors, and scene mapping, as well as diverse sources and data paths using those physical phenomena (e.g., multiple radio frequencies) to provide interchangeable solutions to users to ensure robust availability. [USG-FRP] 

#### **positioning** 

The ability to accurately and precisely determine one’s location and orientation two-dimensionally (or threedimensionally, when required) referenced to a standard reference frame, such as the World Geodetic System 1984, WGS 84, or the International Terrestrial Reference Frame ITRF2020 [ITRF]. [DOT, adapted] 

#### **precision** 

Refers to how closely individual PNT measurements agree with each other. [USG-FRP] 

#### **proper working state** 

A condition in which the device or system contains no compromised internal components or data fields (e.g., data stored to memory) and from which the device or system can recognize and process valid input signals and output valid PNT solutions. An initial pre-deployment configuration is a basic example. The accuracy of the immediate PNT solution is not specified in this definition, as it will depend on the specifics of the device or system’s performance and the degradation allowed by different resilience levels. [DHS-RCF] 

#### **reliability** 

The probability of performing a specified function without failure under given conditions for a specified period of time. [USG-FRP] 

105

--- [page 114](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=114) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **residual risk** 

Portion of risk remaining after security measures have been applied. [CNSSI-4009] 

#### **resilience** 

The ability to prepare for and adapt to changing conditions and withstand and recover rapidly from disruptions. Resilience includes the ability to withstand and recover from deliberate attacks, accidents, or naturally occurring threats or incidents. [PPD-21] 

#### **risk** 

A measure of the extent to which an entity is threatened by a potential circumstance or event, and typically a function of: (i) the adverse impacts that would arise if the circumstance or event occurs; and (ii) the likelihood of occurrence. [NIST-SP-800-37] 

#### **risk assessment** 

The process of identifying, estimating, and prioritizing risks to organizational operations (including mission, functions, image, reputation), organizational assets, individuals, other organizations, and the Nation, resulting from the operation of an information system. Part of risk management incorporates threat and vulnerability analyses, and considers mitigations provided by security controls planned or in place. Synonymous with risk analysis. [NIST-SP- <u>800-30]</u> 

#### **risk management** 

The program and supporting processes to manage information security risk to organizational operations (including mission, functions, image, reputation), organizational assets, individuals, other organizations, and the Nation and includes (i) establishing the context for risk-related activities, (ii) assessing risk, (iii) responding to risk once determined, and (iv) monitoring risk over time. [NIST-SP-800-39] 

#### **Risk Management Framework** 

The Risk Management Framework (RMF), presented in NIST SP 800-37, provides a disciplined and structured process that integrates information security and risk management activities into the system development life cycle. [NIST-SP-800-37] 

#### **secure** 

To reduce the risks of intrusions and attacks as well as the effects of natural or manmade disasters on critical infrastructure by physical means or defensive cyber measures. [PPD-21] 

#### **short-term stability** 

The stability of a time or frequency signal over a short measurement interval, usually an interval of 100 seconds or less in duration. [NIST-T&F-Glossary] 

#### **spoofing** 

Faking the sending address of a transmission to gain illegal entry into a secure system. [CNSSI-4009] 

The deliberate inducement of a user or resource to take incorrect action. Note: Impersonating, masquerading, piggybacking, and mimicking are forms of spoofing. [CNSSI-4009] 

<mark>Two classes of spoofing include (1)</mark> _<mark>measurement spoofing</mark>_ <mark>: introduces signal or signal delay that cause the target receiver to produce incorrect measurements of time of arrival or frequency of arrival or their rates of change; and (2)</mark> _<mark>data spoofing</mark>_ <mark>: introduces incorrect digital data to the target receiver for its use in processing of signals and the calculation of PNT. [DHS-GPS-CI, adapted]</mark> 

<mark>Within the context of this document, spoofing includes manipulation of legitimate GNSS signals with intent to corrupt PNT data or signal measurement integrity. For example, it includes, but is not limited to: the transmission of delayed or false GNSS signals with intent to manipulate an asset’s computed position or time and frequency.</mark> 

#### **stability** 

An inherent characteristic of an oscillator that determines how well it can produce the same frequency over a given time interval. Stability does not indicate whether the frequency is right or wrong, but only whether it stays the same. The stability of an oscillator does not necessarily change when the frequency offset changes. An oscillator can be 

106

--- [page 115](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=115) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

adjusted, and its frequency moved either further away from or closer to its nominal frequency without changing its stability at all. 

The stability of an oscillator is usually specified by a statistic, such as the Allan deviation, that estimates the frequency fluctuations of the device over a given time interval. Some devices, such as an OCXO [Oven Controlled Crystal (Xtal) Oscillator] have good short-term stability and poor long-term stability. Other devices, such as a GPS disciplined oscillator (GPSDO), typically have poor short-term stability and good long-term stability. [NIST-T&F- <u>Glossary, adapted]</u> 

#### **synchronization** 

The process of setting two or more clocks to the same time. [NIST-T&F-Glossary] 

#### **syntonization** 

The process of setting two or more oscillators to the same frequency. [NIST-T&F-Glossary] 

#### **threat** 

Any circumstance or event with the potential to adversely impact organizational operations, organizational assets, individuals, other organizations, or the Nation through a system via unauthorized access, destruction, disclosure, modification of information, or denial of service. [NIST-SP-800-53] 

#### **traceability, metrological** 

Property of a measurement result whereby the result can be related to a reference through a documented, unbroken chain of calibrations, each contributing to the measurement uncertainty. [VIM] 

#### **time interval** 

The elapsed time between two events. In time and frequency metrology, time interval is usually measured in small fractions of a second, such as milliseconds, microseconds, or nanoseconds. Higher-resolution time interval measurements are often made with a time interval counter. [NIST-T&F-Glossary] 

#### **time scale** 

An agreed upon system for keeping time. All time scales use a frequency source to define the length of the second, which is the standard unit of time interval. Seconds are then counted to measure longer units of time interval, such as minutes, hours, or days. Modern time scales, such as UTC, define the second based on an atomic property of the cesium atom, and thus standard seconds are produced by cesium oscillators. Earlier time scales (including earlier versions of Universal Time) were based on astronomical observations that measured the frequency of the Earth’s rotation. [NIST-T&F-Glossary] 

#### **validation** 

Confirmation (through the provision of strong, sound, and objective evidence and demonstration) that requirements for a specific intended use or application have been fulfilled and that the system, while in use, fulfills its mission or business objectives while being able to provide adequate protection for stakeholder and mission or business assets, minimize or contain asset loss and associated consequences, and achieve its intended use in its intended operational environment with the desired level of trustworthiness. [NIST-SP-800-160 (§3.4.11), adapted] 

#### **verification** 

Process of producing objective evidence that sufficiently demonstrates that the system satisfies its security requirements and security characteristics with the level of assurance that applies to the system. [NIST-SP-800-160 (§3.4.9), adapted] 

#### **vulnerability** 

A weakness in an information system, system security procedures, internal controls, or implementation that could be exploited or triggered by a threat source. [NIST-SP-800-30] 

#### **wander** 

The long-term variations—random walk frequency noise—of the significant instants of a digital signal from their ideal position in time (where long-term implies that these variations are of frequency less than 10 Hz). [ITU-T-810, adapted] 

107

--- [page 116](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=116) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

#### **World Geodetic System 1984** 

An Earth-centered, Earth-fixed terrestrial reference system and geodetic datum. WGS 84 is based on a consistent set of constants and model parameters that describe the Earth’s size, shape, gravity, and geomagnetic fields. WGS 84 is the standard U.S. Department of Defense definition of a global reference system for geospatial information and is the reference system for GPS. It is consistent with the International Terrestrial Reference System (ITRS). [USG- <u>FRP]</u> 

108

--- [page 117](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=117) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix D. Applying the PNT Profile to Cybersecurity Risk Management** 

The PNT Profile can be used to augment an organization’s pre-existing risk management program.  This section further tailors the PNT Profile in context of a few notional fault scenarios to illustrate how the guidance can be applied to assess and manage PNT related risks in the context of a loss or degradation of PNT data or services.  Organizations using the PNT data have the responsibility for mitigating temporary PNT disruptions _._ An effective PNT risk management strategy provides a dynamic and flexible approach to control risks in evolving environments. A comprehensive risk management strategy requires proper preparation, which is further detailed in <u>Appendix E. Organizations are encouraged to apply the PNT Profile with their risk management</u> approach from concept to acquisitions to acceptance, integration, and deployment, to operations and maintenance. Leveraging the organization’s existing risk management program enables a system-level shared context. Furthermore, setting priorities for privacy and security risk management affords additional assurance from component to system implementation. 

Each organization selects PNT Profile Subcategories, the cybersecurity outcomes relevant to their mission and business objectives and implements associated controls proportional to their risk exposure. The organization verifies and validates the implementation throughout the PNT system lifecycle. A PNT system lifecycle can include the consideration of the acquisition, integration, deployment, operations and maintenance, repair, and replacement of PNT components and services. A comprehensive, well-documented, and disciplined risk management process for PNT systems allows for continuous monitoring of threats, likelihoods, and impacts, in order to provide efficient identification and analysis of risks and effectiveness of the controls applied to manage those risks. Equally important, an agile risk management approach enables continuous adaptation to evolving threats through adoption of innovative and rapid advances in technology and current best practices. 

Organizations evolve the operational reliability and effectiveness throughout a PNT system’s lifecycle by continuously monitoring risks and assessing risk mitigation strategies, such as: 

- new techniques and technologies to improve the ability to identify, protect, detect, respond, and recover from PNT system attacks 

- the emergence of exploitable PNT vulnerabilities 

- methods to mitigate vulnerabilities and operational impacts 

- operational environment changes in which the PNT-dependent system is deployed to determine if updates are required to the system’s cybersecurity controls 

Table 26 illustrates how the PNT Profile can be used by a notional organization to address example scenarios and apply the five functions of the CSF to manage the risk to PNT systems. Equipment manufacturers and end users can address the scenarios through resiliency and redundancy. 

109

--- [page 118](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=118) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

**Table 26.** Applying the PNT Profile to User Risk Management 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
|**User:**A human<br>action or inaction<br>with a system<br>resulting in faults or<br>failure in the PNT<br>system or data. User<br>risks include both<br>unintentional and<br>intentional threats.|_Identify personnel_<br>_qualifications and user_<br>_equipment training._<br>Baseline personnel<br>qualifications and training<br>on designing, deploying,<br>testing, securing, and<br>maintaining PNT user<br>equipment are<br>implemented and verified.<br>[AM-1 through AM-5]<br>_Identify vulnerabilities and_<br>_threats_related to personnel<br>integrating, maintaining,<br>and relying on PNT user<br>equipment and services.<br>[RA-1, RA-2, RA-3]|Awareness and adherence<br>to_installation and_<br>_maintenance best practices_.<br>[IP-1, MA-1, MA-2]<br>_Configuration change_<br>_control process_are<br>established and adhered to.<br>[IP-3]<br>Enable event logging<br>including identification of<br>users and components<br>associated with an event.<br>[PT-1]<br>Assure sound systems<br>engineering and integration<br>and administration teams<br>have_adequate_<br>_cybersecurity, user_<br>_equipment, testing, and_<br>_maintenance training_.<br>Users have training and<br>experience in using<br>complementary sources of<br>PNT data and signals. [AT-<br>2]<br>Understand_user_<br>_responsibilities_with<br>respect to PNT data<br>performance. [AT-3]<br>_User identities are securely_<br>_managed_with access|_End-to-end systems_<br>_testing_to verify user<br>configuration after<br>firmware, software,<br>equipment integration<br>and upgrades. [DS-4]<br>Newly deployed or<br>updated PNT data<br>streams are<br>continuously monitored<br>against established PNT<br>data sources to correlate<br>faults. [AE-3]<br>PNT data alert<br>thresholds are<br>established. [AE-5]<br>_Integrity monitoring_.<br>Continuous monitoring<br>of user actions and<br>related risk<br>management controls.<br>[CM-1]|_Execute response plan._<br>Apply proper working<br>configuration.<br>Document steps and<br>results and address<br>changes relative to user<br>interactions with the<br>PNT system, in<br>addition to any<br>software and hardware<br>configuration changes,<br>in the response plan.<br>Record new threats and<br>vulnerabilities. [RP-1,<br>MI-2, MI-3]<br>Continue to_log data_<br>from all PNT sources<br>as feasible. [AN-1]<br>_Operational constraints_<br>due to loss or<br>compromise of the<br>PNT data are<br>_understood and_<br>_communicated_before<br>continuing operations_._<br>[AN-2]<br>_Alert stakeholders_<br>including downstream<br>users describing the<br>limitations and extent<br>of disruption in PNT<br>source integrity and|_Execute recovery plan._<br>Restore PNT system<br>within an acceptable<br>time period. Perform<br>system acceptance<br>testing. The recovery<br>plan can include<br>specific actions for<br>restoration,<br>recalibration, resetting,<br>and test validation of<br>equipment. [RP-1]<br>_Periodically verify_<br>_personnel are_<br>_adequately trained_to<br>execute recovery plans_._<br>[CO-1]<br>_Update risk assessment._<br>Improve PNT training,<br>testing, monitoring,<br>detection, response,<br>recovery procedures,<br>and resiliency features.<br>[IM-1]<br>_Update the recovery_<br>_plan_to incorporate<br>lessons learned, reflect<br>new threats, improve<br>technology, and address<br>changes to the<br>organization, PNT<br>system, operating|



110

--- [page 119](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=119) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
|||control limited to their<br>roles and responsibilities.<br>[AC-1, AC-4, AC-6, AC-7]||availability. [CO-2,<br>CO-3]|environment, and<br>problems encountered<br>during plan<br>implementation,<br>execution, and testing.<br>[IM-2]|
|**Software:**Fault or<br>failure in the PNT<br>user equipment<br>firmware or<br>application code and<br>associated impact on<br>other systems that<br>are dependent on the<br>software. The faults<br>or failures<br>encompass<br>unintentional<br>performance<br>degradation due to<br>malicious breaches.|_Inventory software_<br>_applications producing or_<br>_relying on PNT data or_<br>_signals._PNT software and<br>intended use, users,<br>applicable regulations, and<br>environment, including<br>baseline performance<br>characteristics,<br>performance limitations<br>are understood and<br>verified. [AM-1 through<br>AM-5]<br>_Identify vulnerabilities and_<br>_threats_to PNT user<br>software and downstream<br>applications. [RA-1, RA-2,<br>RA-3]|A baseline software<br>configuration adhering to<br>cybersecurity principles for<br>applications providing and<br>using PNT data is applied.<br>[IP-1]<br>Systematic calibration and<br>characterization procedures<br>of PNT system uncertainty<br>and integrity alert<br>thresholds. [MA-1]<br>_End-to-end systems testing_<br>to verify firmware,<br>software, equipment<br>integration and upgrades.<br>[DS-4]<br>Adopt appropriate software<br>assurance methods.<br>Consider verification of<br>PNT systems such as<br>device conformance and<br>systems interoperability<br>testing and certification<br>needed to meet<br>organizational<br>requirements. [DS-6]|_Event logging_including<br>both normal and<br>anomalous software<br>operating states. [AE-3]<br>PNT data_alert_<br>_thresholds_are<br>established. [AE-5]<br>_Integrity monitoring_.<br>Continuous monitoring<br>of the PNT device<br>outputs and applications<br>relying on the PNT data<br>from the device and<br>associated risk<br>management controls.<br>[CM-1]|_Execute response plan._<br>Notify downstream<br>users of potential PNT<br>data availability and<br>integrity impacts.<br>Apply proper working<br>configuration_._<br>Document steps and<br>results and address<br>changes in software or<br>software configuration<br>with the PNT system in<br>the response plan.<br>Record new threats and<br>vulnerabilities. [RP-1,<br>MI-1, MI-2, MI-3]<br>Continue to_log data_<br>from all PNT sources<br>as feasible. [AN-1]<br>_Operational constraints_<br>due to loss or<br>compromise of the<br>PNT data are<br>_understood and_<br>_communicated_before<br>continuing operations_._[<br>AN-2]|_Execute recovery plan._<br>Restore PNT system<br>within an acceptable<br>time period. Perform<br>system acceptance<br>testing. The recovery<br>plan can include<br>specific actions for<br>restoration,<br>recalibration, resetting,<br>and test validation of<br>equipment. [RP-1]<br>_Update risk assessment._<br>Improve PNT training,<br>testing, monitoring,<br>detection, response,<br>recovery procedures,<br>and resiliency features.<br>[IM-1]<br>_Update the recovery_<br>_plan_to incorporate<br>lessons learned, reflect<br>new threats, improve<br>technology, and address<br>changes to the<br>organization, PNT<br>system, operating|



111

--- [page 120](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=120) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
|||Firmware and software<br>updates are verified to<br>conform to standards and to<br>understand impact of<br>changes on user<br>applications. Backup<br>configuration files of<br>known proper working<br>states. [IP-3]<br>Enable event logging<br>including both normal and<br>anomalous software<br>operating states. [PT-1]||_Alert stakeholders_<br>including the device<br>manufacturer about<br>hardware faults or<br>failures describing the<br>limitations and extent<br>of disruption in PNT<br>source integrity. [CO-2,<br>CO-3]|environment, and<br>problems encountered<br>during plan<br>implementation,<br>execution, and testing.<br>[IM-2]|
|**Hardware**: Fault<br>or failure in the<br>PNT user<br>equipment design,<br>or implementation<br>or integration,<br>such as gateware.|_Inventory all physical_<br>_devices._PNT user<br>equipment and intended<br>use, users, applicable<br>regulations, and<br>environment, including<br>baseline performance<br>characteristics, are<br>understood and verified.<br>[AM-1 through AM-5]<br>_Identify vulnerabilities_<br>_and threats_to PNT<br>devices and<br>components. [RA-1,<br>RA-2, RA-3]<br>_Identify hardware_<br>_resilience capabilities._<br>Consider how other|_Consider redundant or_<br>_complementary PNT_<br>_sources._Consider<br>objective metrics in the<br>recovery plan such as (1)<br>recovery point objective<br>(RPO), which is the<br>maximum tolerable<br>period of time in which<br>PNT data might be lost<br>and can be applied in<br>determining holdover<br>capabilities of the PNT<br>system; and (2) recovery<br>time objective (RTO),<br>which is how quickly an<br>application must recover<br>following a PNT service<br>disruption. Additional|_Integrity monitoring_.<br>Continuous<br>monitoring of the<br>PNT user equipment<br>and associated<br>components including<br>effectiveness of<br>mitigation controls.<br>[CM-1]<br>_Event logging_<br>including both normal<br>and anomalous<br>hardware operating<br>states. [AE-3]<br>PNT data_alert_<br>_thresholds_are<br>established. [AE-5]<br>_Verify PNT device_|_Execute response_<br>_plan._Notify<br>downstream users of<br>potential PNT data<br>availability and<br>integrity impacts.<br>Apply proper<br>working<br>configuration_._<br>Document steps and<br>results and address<br>changes in hardware<br>or hardware<br>configuration with<br>the PNT system in<br>the response plan.<br>Record new threats<br>and vulnerabilities.<br>[RP-1, MI-1, MI-2,|_Execute recovery_<br>_plan._Restore PNT<br>system within an<br>acceptable time<br>period. Perform<br>system acceptance<br>testing. The recovery<br>plan can include<br>specific actions for<br>restoration,<br>recalibration,<br>resetting, and test<br>validation of<br>equipment._Verify_<br>_backup PNT sources_<br>are serviceable,<br>operational, and<br>sufficient before<br>continuing operations|



112

--- [page 121](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=121) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
||sensors can be leveraged<br>to monitor and detect<br>anomalies in PNT<br>sources. [BE-5]|sources such as NTP and<br>WWVB, and sensors<br>such as Inertial<br>Navigation Systems<br>(INS) and Inertial<br>Measurement Units can<br>provide (IMUs) can be<br>used to continue to<br>provide PNT information<br>to the user. [IP-9]<br>_Calibration and_<br>_characterization of PNT_<br>_system uncertainty_<br>including establishment<br>of testing, certification,<br>and continuous<br>monitoring and integrity<br>alert thresholds<br>expectations under<br>operational<br>environmental<br>conditions. [MA-1]<br>_Event logging_including<br>both normal and<br>anomalous hardware<br>operating states. [PT-1]<br>_Redundancy_or<br>_complementary sensors_<br>_and sensor fusion_<br>_algorithms._User<br>equipment technologies:|_integrity and_<br>_availability_. Identify<br>and document known<br>limitations. [DS-1,<br>DS-4, DS-6, DS-8]|MI-3]<br>Continue to_log data_<br>from all PNT sources<br>as feasible. [AN-1]<br>_Operational_<br>_constraints_due to<br>loss or compromise<br>of the PNT data are<br>_understood and_<br>_communicated_before<br>continuing<br>operations_._[ AN-2]<br>_Alert stakeholders_<br>including the device<br>manufacturer of<br>hardware faults or<br>failures describing<br>the limitations and<br>extent of disruption<br>in PNT source<br>integrity. [CO-2, CO-<br>3]|safely_._[RP-1]<br>_Update risk_<br>_assessment._Improve<br>PNT training, testing,<br>monitoring, detection,<br>response, recovery<br>procedures, and<br>resiliency features.<br>[IM-1]<br>_Update the recovery_<br>_plan_to incorporate<br>lessons learned,<br>reflect new threats,<br>improve technology,<br>and address changes<br>to the organization,<br>PNT system,<br>operating<br>environment, and<br>problems encountered<br>during plan<br>implementation,<br>execution, and testing.<br>[IM-2]|



113

--- [page 122](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=122) ---

Foundational PNT Profile 

NIST IR 8323r1 

January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
|||Holdover clocks, inertial<br>measurement/navigation<br>systems, simultaneous<br>localization and<br>mapping, and redundant<br>power supplies. [PT-5]<br>Physical and remote<br>access to devices are<br>secured and properly<br>managed. [AC-1 through<br>AC-4]<br>Protect PNT user<br>equipment data. [DS-4]||||
|**Data in transit**:<br>Includes adversarial<br>and non-adversarial<br>sources of disruption<br>and manipulation of<br>PNT data or signal<br>in transit. Examples<br>of transmission<br>threats include path<br>delay variations,<br>multipath<br>interference,<br>jamming, and<br>spoofing.|_Identify vulnerabilities and_<br>_threats_to the<br>communication modes<br>from external PNT sources<br>and internal networks<br>transmitting and receiving<br>PNT data and signals.<br>[RA-1, RA-3]<br>_Identify PNT signal and_<br>_data communication_<br>_threats._Follow<br>information sources from<br>ISACs and bulletins such<br>as NANUs, Notice to Air<br>Missions (NOTAMs),<br>Safety Information<br>Bulletins (SIBs) to be<br>aware of possible<br>disruption of PNT sources|_Consider multiple_<br>_communication paths and_<br>_complementary PNT_<br>_sources._A resilient<br>communications network<br>topology can limit the<br>impact of communication<br>attacks. Consider objective<br>metrics in the recovery plan<br>such as RPO and RTO.<br>Additional PNT sources<br>such as NTP and WWVB,<br>and sensors such as INS<br>and IMUs can be used to<br>continue to provide PNT<br>information to the user.<br>[IP-9]<br>_Apply communication_<br>_technologies_thatpreserves|_Integrity monitoring._<br>Continuous monitoring<br>of the PNT data in<br>transit and control<br>effectiveness. [CM-1]<br>_Event logging_including<br>both normal and<br>anomalous<br>communication states.<br>[AE-3]<br>PNT data_alert_<br>_thresholds_are<br>established. [AE-5]|Execute_contingency_<br>_procedures_and assess<br>functionality of systems<br>relying on<br>complementary PNT<br>sources or alternative<br>modes of PNT<br>communications_._<br>Notify downstream<br>users of potential PNT<br>data availability and<br>integrity impacts.<br>Record new threats and<br>vulnerabilities. [RP-1,<br>MI-1, MI-2, MI-3]<br>Continue to_log data_<br>from all PNT sources<br>as feasible. [AN-1]|_Execute recovery plan._<br>Equipment with<br>adaptive algorithms and<br>networks can switch to<br>use available<br>communication<br>channels with minimal<br>PNT availability and<br>integrity degradation_._<br>Verify backup PNT<br>sources are serviceable,<br>operational, and<br>sufficient before<br>continuing operations<br>safely_._[RP-1]<br>_Update risk assessment._<br>Improve PNT training,<br>testing, monitoring,<br>detection,response,|



114

--- [page 123](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=123) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
||in each area and time<br>frame. [RA2]<br>_Identify communication_<br>_resilience capabilities._<br>Consider how other<br>sensors can be leveraged to<br>monitor and detect<br>anomalies in PNT sources.<br>[BE-5]|integrity and improves the<br>reliability and resilience of<br>the PNT information.<br>Consider using controlled<br>reception pattern antenna<br>(CRPA) to reduce impacts<br>of RF interference. Note<br>that such antenna may be<br>subject to export controls.<br>[DS-2, PT-4, IP-2]<br>_Use latest software and_<br>_firmware_after testing and<br>characterization. [MA-1] <br>_Calibration and_<br>_characterization of PNT_<br>_system uncertainty_<br>including establishment of<br>testing, certification, and<br>continuous monitoring and<br>integrity alert thresholds<br>expectations under<br>operational environmental<br>conditions. [MA-1]<br>_Network integrity_<br>_protection_. Consider<br>redundant, resilient,<br>adaptive, and agile<br>practices for network<br>engineering, management,<br>operational and<br>maintenance procedures<br>that protect the types of<br>data at issue. [AC-5]||_Operational constraints_<br>due to the loss of the<br>PNT data are<br>_understood and_<br>_communicated_before<br>continuing operations_._[<br>AN-2]<br>_Alert user community_<br>of communication<br>disruptions describing<br>the limitations and<br>extent of disruption in<br>PNT source_integrity_<br>_and availability._[CO-2,<br>CO-3]|recovery procedures,<br>and resiliency features.<br>[IM-1]<br>_Update the recovery_<br>_plan_to incorporate<br>lessons learned, reflect<br>new threats, improve<br>technology, and address<br>changes to the<br>organization, PNT<br>system, operating<br>environment, and<br>problems encountered<br>during plan<br>implementation,<br>execution, and testing.<br>[IM-2]|



115

--- [page 124](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=124) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Example**<br>**Scenarios**|**Identify**|**Protect**|**Detect**|**Respond**|**Recover**|
|---|---|---|---|---|---|
|**Supply chain:**<br>Includes<br>disruptions,<br>degradations, or<br>compromise of<br>PNT services,<br>software or<br>hardware<br>components,<br>including<br>counterfeiting,<br>leading to<br>components that<br>may not be as<br>reliable or<br>components that<br>have been<br>maliciously<br>modified.|_Identify the role of the_<br>_organization or critical_<br>_infrastructure in_<br>_providing PNT services._<br>Organizations using a<br>PNT source to re-<br>broadcast or transmit<br>PNT data must be aware<br>of how changes can<br>impact PNT data and<br>signals downstream.<br>[BE-1, BE-2]<br>_Suppliers and third-party_<br>_testing and certification_.<br>Consider relevant<br>conformance testing,<br>certification<br>requirements, and<br>processes. [SC-2]<br>_Identify vulnerabilities,_<br>_including sources of_<br>_errors, and threats_in the<br>PNT supply chain. For<br>example, when PNT<br>services are transferred<br>through multiple parties<br>and locations. [RA-1,<br>RA-3]<br>Assure_the total_<br>_uncertainty_remains<br>within industry standards<br>and regulatory<br>requirements. [GV-4]|_Suppliers and third-party_<br>_partners understand their_<br>_roles and responsibilities._<br>[AT-3]<br>_Hardware component_<br>_authentication_such as<br>radio-frequency<br>identification (RFIDs),<br>physically unclonable<br>functions (PUFs), or other<br>markers.  [AC-1, AC-6,<br>AC-7]<br>_Hardware lifecycle_<br>_management_can include,<br>but not limited to,<br>consideration of the<br>acquisition, integration,<br>deployment, operations<br>and maintenance, repair,<br>and replacement of PNT<br>components and services.<br>[DS-3]|_Clarify monitoring and_<br>_detection_<br>_responsibilities_and<br>support open<br>communication<br>channels among<br>supply chain to<br>analyze and support<br>root cause<br>determination of<br>anomalous PNT data<br>or signal output_._[AE-<br>3]<br>_Understand risk_<br>_impacts among supply_<br>_chain partners_.<br>Policies and<br>procedures, including<br>lessons learned over<br>time, are adequately<br>documented and<br>shared with<br>stakeholders.  [AE-4]<br>PNT data_alert_<br>_thresholds_are<br>established. [AE-5]<br>_Verify PNT device_<br>_integrity_. Identify and<br>document known<br>limitations. [DS-6,<br>DS-8]|Execute_contingency_<br>_procedures_and assess<br>functionality of<br>systems relying on<br>complementary PNT<br>services or other third-<br>party services_._Notify<br>downstream users of<br>potential PNT data<br>availability and<br>integrity impacts.<br>Record new threats<br>and vulnerabilities.<br>[RP-1, MI-1, MI-2,<br>MI-3]<br>_Operational_<br>_constraints_due to the<br>loss or compromise of<br>the PNT services or<br>components are<br>_understood and_<br>_communicated_before<br>continuing operations_._<br>[ AN-2]<br>_Alert user community_<br>of supply chain<br>disruptions and threats<br>describing the<br>limitations and extent<br>of the threat in PNT<br>source_integrity and_<br>_availability._[CO-2,<br>CO-3]|_Execute recovery_<br>_plan._Equipment and<br>applications can<br>switch to use<br>available services or<br>components with<br>minimum PNT<br>availability and<br>integrity degradation_._<br>_Verify backup PNT_<br>_sources_are<br>serviceable,<br>operational, and<br>sufficient before<br>continuing operations<br>safely_._[RP-1]<br>_Update the recovery_<br>_plan_to incorporate<br>lessons learned,<br>reflect new threats,<br>improve technology,<br>and address changes<br>to the organization,<br>PNT system,<br>operating<br>environment, and<br>problems encountered<br>during plan<br>implementation,<br>execution, and<br>testing. [IM-2]|



116

--- [page 125](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=125) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix E. Organization-Specific PNT Profiles** 

NISTIR 8323 provides the foundational set of cybersecurity outcomes based on the five functions of the NIST Cybersecurity Framework relevant to the responsible use of PNT sources and data. The set of outcomes selected by the organization based on its mission and business objectives are intended to manage the risks associated with the use of PNT data. However, it should be noted that implementation of the foundational profile is necessary but not complete compliance with Executive Order 13905. This appendix will provide guidance to PNT stakeholders on applying the NISTIR 8323 to create sector-specific and organization PNT user profiles and to address other aspects of the Executive Order. 

Creating a custom PNT profile based on the foundational profile is beneficial to an organization, especially if they are part of a critical infrastructure. Each custom PNT profile is intended to capture the requirements of an organizations PNT source and data and a prioritized set of PNT data security outcomes. The custom PNT profile can be used to inform new PNT source and services acquisitions process when researching and evaluating PNT services and sources. In accordance with EO 13905, the U.S. government will develop contractual language to include relevant cybersecurity outcomes from the foundational PNT profile as potential requirements in federal contracts for products, systems, and services that use or integrate PNT services. It is important to consider adaptability and flexibility in contractual clauses in order to address evolving context-dependent risks. A custom profile will facilitate a flexible, systematic risk management process for the use of PNT data to meet sector-specific regulatory and standards requirements. In addition, an organizational PNT profile would enable assessment of their ability to satisfy the contract when using and providing PNT sources and data. 

Organizations have different assets, architectures, cybersecurity resources, and tolerances to PNT denial or disruption. Risk-based, accurate, comprehensive, and systematic assessments regarding responsible use of PNT requires knowledge of assets, any cybersecurity measures in place, knowledge of any external dependencies, and the impact should there be a loss or degradation of PNT data that is in the context of the individual organization. Organization-specific PNT profiles can augment PNT guidance provided by the U.S. government through the relevant agencies. Organizations can adopt a risk-based approach to diverse PNT uses, building on this and other documents; the intent is not to impose one uniform approach. Generating the assessment and definition of a way forward to achieve the appropriate level of PNT assurance will require leadership and a cadre of subject matter expertise such as: 

- The Chief Information Officer (CIO). Manages people, processes, and technologies within the IT organization with the ability to influence the direction of resources for greater assurance or accept the residual risk. 

- Cybersecurity Experts. Provide knowledge of cyber-threats and the ability of the current or proposed IT infrastructure’s ability to mitigate attacks. 

- Operators and Operations Management. Provides knowledge of daily operations and the impact of an incident or the impact of changes to the information technology (IT) system on operations. 

- Users of PNT Data. Provide insight on the impact should the organization’s products or services be delayed, degraded, or lost. Provide knowledge of PNT application uses cases and PNT data performance, reliability, and resilience measures. 

117

--- [page 126](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=126) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

- System Administration. Configures systems or gather information to provide data for engineering, analysis or enforce technical and managerial controls. 

- IT and System Design. Provides knowledge of current or proposed designs and propose new or modified components or systems. 

- System Engineering. Integrates modifications or designs of systems providing or transmitting PNT information. 

- Marketing, Sales, Engineering Personnel of vendors and manufacturers of PNT user equipment and services. 

Aggregation or easy access to relevant information will expedite the PNT Profile development process for an organization. This is especially important for the Identify function and will aid in the ability to evaluate the degree of the organization’s implementation of the Categories and Subcategories within all of the functions. The type of information that will be needed will include: 

- Any standards, guides, policy, regulations, best practices, concept of operations, continuity plans, cybersecurity incident response and recovery plans, risk management documentation, and other documentation that applies to the organization’s business and mission objectives. 

- Network and system architecture and diagrams with details such as: 

   - Boundaries 

   - Interfaces 

   - Information flows 

   - Connectivity 

   - Any external dependencies (especially PNT related dependencies) 

- Network access points to include any temporary access points (such as wireless access points) or hardware interfaces (such as Universal Serial Bus (USB) drives, compact discs (CDs)) 

- Inventory of assets and their deployment. 

Once the team is assembled and the background information is made available, a systematic analysis of the foundational profile can be made in the context of the individual organization. Some of the Subcategories will require much more robust implementations (relative to other organizations) while other Subcategories may not be as critical. 

The organization will have applicable knowledge of their specific protection measures and the organization’s personnel will provide information that is unique to the organization. As a part of its findings, the team can provide references, documentation, and other artifacts to supplement the informative references provided by the Foundational PNT profile. The findings of the team will enable executives and leaders to make informed decisions regarding the “As is” or “Proposed” PNT posture. 

118

--- [page 127](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=127) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

### **Appendix F. Change Log** 

This table contains changes that have been incorporated into NIST Interagency or Internal Report (NIST IR) 8323 revision 1 from the initial public draft. Change log updates can include corrections, clarifications, and or other major and minor changes in the publication that are either _editorial_ or _substantive_ in nature. 

**Table 27.** Change Log 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
|NIST IR 8323<br>ipd|01-25-2023|Editorial|Updated [DHS-S&T-2021] and<br>addressed editorial comments.|81,<br>multiple<br>pages|
|NIST IR 8323<br>ipd|12-15-2022|Substantive|Added [ITRF], published October<br>2022, to references section.<br>Referenced ITRF2020 in glossary<br>definition for positioning. Added<br>ITRF acronym to Acronyms<br>section.|86, 100,<br>107|
|NIST IR 8323<br>ipd|12-15-2022|Editorial|Updated NOTAM acronym after<br>change.|99|
|NIST IR 8323<br>ipd|12-15-2022|Substantive|Added [GDGPS] to DE.CM-1 and<br>references section. Added GDGPS<br>to acronyms list.|58, 82, 99|
|NIST IR 8323<br>ipd|12-15-2022|Substantive|Added reference [DHS-CISA-IE]<br>to ID.RA-3, RS.CO-2, and<br>references section.|26, 66, 79|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added references to profiles related<br>to the space and ground segments.|96|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added acronym RPO.|100|
|NIST IR 8323<br>ipd|11-02-2022|Editorial|Revised formatting and grammar.|Multiple<br>pages|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added reference [GPS USER] to<br>ID.AM-4, PT.DS-4, DE.AE-3,<br>RS.CO-2, RS.CO-3, and references|17, 39, 54,<br>66, 67, 81|



119

--- [page 128](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=128) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
||||section.||
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added [ISO 16085] to ID.RM-1<br>and references section.|29, 84|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added [ISO 15288] to ID.RM-1,<br>ID.DS-3, and references section.|29, 39, 84|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added [ISO 27001] to ID.BE-1,<br>ID.RM-1, ID.RM-3, PT.AT-3, and<br>references section.|19, 29, 37,<br>84|
|NIST IR 8323<br>ipd|11-02-2022|Substantive|Added [ISO 17666] to ID.RM-1<br>and references section.|29, 84|
|NIST IR 8323<br>ipd|11-07-2022|Substantive|Added [BIPM] and [IERS] to<br>ID.GV-4 and references section.<br>Added IERS to acronyms section.|22, 78, 83,<br>99|
|NIST IR 8323<br>ipd|11-07-2022|Substantive|Added [IANA TZDB] to ID.GV-4,<br>PT.DS-6 and references section.|22, 40, 82|
|NIST IR 8323<br>ipd|11-07-2022|Substantive|Added reference [Defraigne 2022]<br>to ID.GV-4, PT.MA-1, PT.PT-1<br>and references section.|22, 48, 50,<br>79|
|NIST IR 8323<br>ipd|10-19-2022|Substantive|Added reference to [NIST-CSRC].<br>Revised glossary term for<br>“jamming” and added “spoofing”.|86, 105,<br>107|
|NIST IR 8323<br>ipd|07-17-2022|Substantive|Added DHS S&T guidelines [DHS<br>S&T 2021] to PT.DS-6 and<br>references section.|40, 80|
|NIST IR 8323<br>ipd|06-14-2022|Substantive|Added references [GAL-ICD] and<br>[BDS-ICD] to ID.AM-3, ID.GV-4,<br>PT.DS-6, DE.AE-3, and references<br>section.|17, 22, 40,<br>54, 78, 81|
|NIST IR 8323<br>ipd|06-14-2022|Substantive|Added additional sensor controls to<br>Acronyms and Glossary sections.|98,99|



120

--- [page 129](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=129) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
|NIST IR 8323<br>ipd|06-14-2022|Substantive|Added reference [GPS SPS] for<br>additional GPS performance<br>expectations to ID.GV-4.|22|
|NIST IR 8323<br>ipd|06-14-2022|Substantive|Added informative reference<br>[NOAA SWS] to ID.RA-3 and<br>references section.|26, 89|
|NIST IR 8323<br>ipd|06-14-2022|Substantive|Added informative reference [SPD-<br>7] to DE.AE-3 and references<br>section to understand sector-<br>specific agencies responsible for<br>monitoring the civil performance of<br>space-based PNT services.|55, 91|
|NIST IR 8323<br>ipd|06-03-2022|Substantive|Added reference [3GPP TS22.071]<br>to ID.AM-5 and references section.|17, 79|
|NIST IR 8323<br>ipd|06-03-2022|Substantive|Added reference [FCC E911] to<br>ID.GV-4 and references section.|22,81|
|NIST IR 8323<br>ipd|06-03-2022|Editorial|Updated references [3GPP<br>TS36.305], [3GPP TR22.826],<br>[3GPP TR22.878], [DHS GPS CI],<br>[DHS RCF], [DIA], [GPS], [GPS<br>IS-200], [GPS IS-705], [GPS IS-<br>800], [GPS ICD-240], [IEC 62439-<br>3], [IEEE 802.1AS], [ITU-T<br>G.8275.1], [NAVCEN], [NIST SP<br>800-161], [NISTIR 8320]  to reflect<br>the latest versions and links.|79-92|
|NIST IR 8323<br>ipd|06-03-2022|Substantive|Added [IETF 5905] to references<br>section.|84|
|NIST IR 8323<br>ipd|06-03-2022|Substantive|Added reference [DHS S&T 2022]<br>to ID.BE-1, ID.BE-2, PT.AT-3, and<br>references section.|19, 38, 80,<br>81|
|NIST IR 8323<br>ipd|06-03-2022|Substantive|Added reference [NIST TN 2187]<br>to IE.BE-2, PT.AT-3, and<br>references section.|19, 38, 90|



121

--- [page 130](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=130) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|RTCA 229: Reference was<br>misplaced, moved from ID.AM-1<br>to ID.BE-5|15, 21|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|RCTA 292: Reference was<br>misplaced, moved from ID.AM-1<br>to ID.RA-1|15, 24|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|RCTA 326: This is an<br>airworthiness specification.  Does<br>not apply to ID.AM-1. Deleted<br>reference.|15|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|USG FRP: Reference was<br>misplaced.  Moved from ID.AM-1<br>to ID.GV-4.|15, 22|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added ID.BE-1 with informative<br>references.  Applicable to<br>organizations that receive and<br>rebroadcast PNT|19|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added ID.BE-2 and informative<br>references.  PNT supports and is<br>impacted by other elements of the<br>critical infrastructure|19|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added reference to ID.GV-4;<br>UTC(USNO) and UTC(NIST) for<br>data products on time difference<br>between UTC(NIST) from<br>UTC(USNO)|22|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added reference to ID.GV-4;<br>Obtaining USNO data products to<br>establish time differences between<br>GPS and UTC(USNO)|22|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed VIM reference in ID.GV-<br>4.  Is a general document providing<br>definitions on metrology for<br>accuracy and traceability.|22|



122

--- [page 131](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=131) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed two references in ID.RA-<br>1, DE.CM-8.  Out of date threat<br>documents. (1995 and 2001)|24, 61|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed CSF references for any<br>specific Subcategory.  The CSF<br>applies equally to all the<br>Subcategories|Multiple<br>pages|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added the Risk Management<br>Strategy category and added<br>ID.RM-1 and ID.RM-3<br>Subcategories with informative<br>references.|29|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added the Protect Awareness and<br>Training category and added<br>PT.AT-3 Subcategory with<br>informative references.|37|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Added “residual risk” to the<br>glossary|107|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed NISTIR 8250 reference<br>from PT.DS-8.  Is a general<br>reference for calibration procedures<br>and does not apply to hardware<br>integrity measures.|42|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed IETF 7882 from<br>reference section.  Was not<br>specifically referenced in any<br>Subcategory.|84|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Removed NISTIR 8250 from<br>reference section.  Was a general<br>reference for calibration<br>procedures.|84|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|UpdatedNIST SP 800-160-2<br>reference to current version.|88|



123

--- [page 132](../../corpus/C/C2_NIST_IR_8323r1.pdf#page=132) ---

Foundational PNT Profile 

NIST IR 8323r1 January 2023 

|**Publication**<br>**Identifier**|**Date**|**Type**|**Change**|**Pages**|
|---|---|---|---|---|
|NIST IR 8323<br>ipd|06-01-2022|Editorial|Added “agility” to glossary.|102|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Appendix D PNT User Risk<br>Management.|110|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Appendix E Proposed summary of<br>CISA language in a new appendix<br>to include reference to contract<br>language.|118|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added reference [IEEE 1139] to<br>ID.RA-4, PT.DS-6, PT.MA-1, and<br>references section.|27, 40, 48,<br>84|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added reference [IEEE 1193] to<br>ID.RA-4, PT.DS-6, PT.MA-1, and<br>references section.|27, 40, 48,<br>84|
|NIST IR 8323<br>ipd|06-01-2022|Substantive|Added reference [ISO 17025] to<br>PT.DS-6, PT.MA-1, and references<br>section.|40, 48, 85|
|NIST IR 8323<br>ipd|10-16-2019|Editorial|Fixed misspellings in Executive<br>Summary.|1|
|NIST IR 8323<br>ipd|10-16-2019|Substantive|Replaced introductory paragraph in<br>Section 2.|5|



124
