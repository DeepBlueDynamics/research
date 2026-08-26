<!-- source: corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf -->
<!-- source_sha256: 052fa4403493fb3a6c081d043ddd1d243dca66e71010425c7abb804277f73202 -->
<!-- source_bytes: 168328 -->
<!-- source_pdf_link: ../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf -->
<!-- extractor: pymupdf4llm 1.28.2 / PyMuPDF 1.28.2 -->
<!-- pages: 40 -->
<!-- extracted_chars: 68075 -->
<!-- generated: 2026-08-26T22:02:22Z by tools/build_docs.py -->

--- [page 1](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=1) ---

# **S-57 Appendix B Product Specifications** 

```
This document must only be used with Edition 3.1
of S-57
```

Edition 2.0

--- [page 2](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=2) ---

Page intentionally left <u>blank</u> 

# **`Important notice`** 

```
All “Clarifications” in the latest Edition of the
Maintenance Document must be taken into account
before making use of this document.
```

S-57 Appendix B 

Edition 2.0 

November 2000

--- [page 3](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=3) ---

# **S-57 Appendix B.1 ENC Product Specification** 

```
This document must only be used with Edition 3.1
of S-57
```

Edition 2.0

--- [page 4](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=4) ---

ENC Product Specification 

II 

Page intentionally left <u>blank</u> 

# **`Important notice`** 

```
All “Clarifications” in the latest Edition of the
Maintenance Document must be taken into account
before making use of this document.
```

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 5](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=5) ---

ENC Product Specification 

iii 

# **Contents** 

|1. Introduction<br>1.1 Definitions|1<br>1|
|---|---|
|1.2 Contents of the document|1|
|1.3 References<br>|1<br>|
|2. General information<br>|1<br>|
|2.1 Navigational purpose<br>|1<br>|
|2.2 Cells<br>|2<br>|
|2.3 Topology<br>|2|
|3. Objects and attributes|3|
|3.1 Feature object identifiers<br>|3<br>|
|3.2 Standard object classes and attributes<br>|3<br>|
|3.3 Objects permitted for use in ENC and their geometric primitives|3|
|3.4 Meta objects|4|
|3.5 Geo and meta object attributes|5|
|3.5.1 Missing attribute values|5|
|3.5.2 Mandatory attributes|5|
|3.5.3 Prohibited attributes|8|
|3.5.4 Numeric attribute values<br>|8<br>|
|3.5.5 Text attribute values|8|
|3.5.6 Hierarchy of meta data|9|
|3.5.7 New attribute values in Edition 3.1<br>|10<br>|
|3.6 Cartographic objects|10|
|<br>3.7 Time varying objects|10|
|3.8 Geometry|11|
|3.9 Relationships|11|
|3.10 Groups<br>|11<br>|
|3.10.1 Group 1 (skin of the earth)|11|
|3.10.2 Group 2 (all other objects)|12|
|3.11 Language and alphabet<br>|12<br>|
|3.11.1 Language|12|
|<br>3.11.2 Use of lexical level 2|12|
|4. Cartographic framework|13|
|4.1 Horizontal datum|13|
|4.2 Vertical and sounding datum|13|
|4.3 Projection|13|
|4.4 Units|13|
|5. Provision of data<br>|14|
|5.1 Implementation|14|
|<br>5.2 Compression|14|
|5.3 Encryption|14|
|5.4 Exchange set|14|
|5.4.1 Content of the exchange set<br>|14<br>|
|5.4.2 Volume naming<br>|15<br>|
|5.4.3 Directory structure<br>|15<br>|
|5.5 Data sets|16|
|5.6 File naming|16|
|<br>5.6.1 README file|16|
|5.6.2 Catalogue file|16|
|<br>5.6.3 Data set files|16|
|5.6.4 Text and picture files|17|
|5.7 Updating|17|
|5.8 Media|19|
|5.9 Error detection|19|
|5.9.1 Implementation|19|
|5.9.2 Processing<br>|19<br>|
|6. Application profiles<br>6.1 General|20<br>20|



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 6](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=6) ---

ENC Product Specification 

iv 

|6.1.1 Catalogue and data set files|20|
|---|---|
|6.1.2 Records|20|
|6.1.3 Fields|20|
|6.1.4 Subfields<br>|20|
|6.2 Catalogue file<br>|21<br>|
|6.2.1 Catalogue file structure|21|
|6.2.2 Catalogue Directory field - CATD|21|
|6.3 EN application profile|22|
|6.3.1 Base cell file structure|22|
|6.3.2 Field content (EN)|23|
|6.3.2.1 Data Set Identification field - DSID|23|
|6.3.2.2 Data Set Structure Information field - DSSI|23|
|6.3.2.3 Data Set Parameter field - DSPM|24|
|6.3.2.4 Vector Record Identifier field - VRID<br>|24<br>|
|6.3.2.5 Vector Record Attribute field - ATTV|25|
|6.3.2.6 Vector Record Pointer field - VRPT|25|
|6.3.2.7 2-D Coordinate field - SG2D|25|
|6.3.2.8 3-D Coordinate (Sounding array) field - SG3D<br>|26|
|6.3.2.9 Feature Record Identifier field - FRID|26|
|6.3.2.10 Feature Object Identifier field - FOID|26|
|6.3.2.11 Feature Record Attribute field - ATTF<br>|27<br>|
|6.3.2.12 Feature Record National Attribute field - NATF|27|
|6.3.2.13 Feature Record  to Feature Object Pointer field - FFPT|27|
|6.3.2.14 Feature Record to Spatial Record Pointer field - FSPT|27|
|6.4 ER application profile<br>|28<br>|
|6.4.1 Update cell file structure|28|
|6.4.2 Field content (ER)|29|
|6.4.2.1 Data Set Identification Field - DSID|29|
|6.4.2.2 Data Set Structure Information field - DSSI|29|
|6.4.2.3 Vector Record Identifier field - VRID|30|
|6.4.2.4 Vector Attribute field - ATTV|30|
|6.4.2.5 Vector Record Pointer Control field - VRPC|30|
|6.4.2.6 Vector Record Pointer field - VRPT|31|
|6.4.2.7 Coordinate Control field - SGCC|31|
|6.4.2.8 2-D Coordinate field - SG2D|31|
|6.4.2.9 3-D Coordinate (Sounding array) field - SG3D|31|
|6.4.2.10 Feature Record Identifier field - FRID|32|
|6.4.2.11 Feature Object Identifier field - FOID|32|
|6.4.2.12 Feature Record Attribute field - ATTF|32|
|6.4.2.13 Feature Record National Attribute field - NATF|33|
|6.4.2.14 Feature Record to Feature Object Pointer Control field - FFPC|33|
|6.4.2.15 Feature Record to Feature Object Pointer field - FFPT|33|
|6.4.2.16 Feature Record to Spatial Record Pointer Control field - FSPC|33|
|6.4.2.17 Feature Record to Spatial Record pointer field - FSPT|34|



Annex A. Use of the Object Catalogue for ENC Annex B. Example of CRC Code Annex C. Recommended ENC Validation Checks Annex D. INT 1 to S-57Cross Reference 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 7](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=7) ---

ENC Product Specification 

1 

# **1. Introduction** 

## **1.1 Definitions** 

**Cell** A cell is a geographical area containing ENC data. **ENC** The latest version of official data carried by a vessel for the intended voyage. **ENC Product Specification** The set of specifications intended to enable Hydrographic Offices to produce a consistent ENC, and manufacturers to use that data efficiently in an ECDIS that satisfies the IMO Performance Standards for ECDIS. An ENC must be produced in accordance with the rules defined in this Specification and must be encoded using the rules described in Appendix B1, Annex A  "Use of the Object Catalogue for ENC". 

## **1.2 Contents of the document** 

The ENC Product Specification contains two application profiles, one for the basic ENC used to populate the SENC (EN application profile), and one for updating the SENC (ER application profile). These application profiles are described in S-57 Part 3, clause 1.4.2. 

## **1.3 References** 

The following documents affect the ENC content : 

IHO S-52, � Specifications for Chart Content and Display Aspects of ECDIS � S-52 App 1, � Guidance on Updating the Electronic Navigational Chart S-52 App 2, � Colours & Symbols Specifications for ECDIS � IMO Resolution A.817(19) � Performance Standards for Electronic Chart Display and Information Systems (ECDIS) � ANSI/IEEE 802.3 � IEEE Standards for Local Area Networks, Carrier Sense Multiple Access with Collision Detection (CSMA/CD)Access Method and Physical Layer Specifications � 

# **2. General information** 

## **2.1 Navigational purpose** 

ENC data is compiled for a variety of navigational purposes. The navigational purpose for which an individual ENC has been compiled is indicated in the � Data Set Identification � [DSID] field, � Intended Usage � [INTU] subfield and in the name of the data set files. The following codes are used : 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 8](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=8) ---

ENC Product Specification 

2 



<!-- Start of picture text -->
Subfield content Navigational purpose<br>1 overview<br>2 general<br>3 coastal<br>4 approach<br>5 harbour<br>6 berthing<br><!-- End of picture text -->

table 2.1 

## **2.2 Cells** 

In order to facilitate the efficient processing of ENC data the geographic coverage of a given usage must be split into cells. Each cell of data must be contained in a physically separate, uniquely identified file on the transfer medium, known as a data set file (see clauses 5.4 and 5.6.3). 

The geographic extent of the cell must be chosen by the ENC producer to ensure that the resulting data set file contains no more than 5 Megabytes of data. Subject to this consideration, the cell size must not be too small in order to avoid the creation of an excessive number of cells. 

Cells must be rectangular (i.e. defined by 2 meridians and 2 parallels). 

The coordinates of the borders of the cell are encoded in decimal degrees in the � Catalogue Directory � [CATD] field. 

The area within the cell which contains data must be indicated by a meta object M_COVR with CATCOV = 1. Any other area not containing data must be indicated by a meta object M_COVR with CATCOV = 2. 

Cells with the same navigational purpose may overlap. However, data within the cells must not overlap. Therefore, in the area of overlap only one cell may contain data, all other cells must have a meta object M_COVR with CATCOV = 2 covering the overlap area. This rule applies even if several producers are involved. 

Point or line feature objects which are at the border of two cells with the same navigational purpose must be part of only one cell. They are put in the south or west cell (i.e. north and east borders of the cell are part of the cell, south and west borders are not). 

When a feature object exists in several cells its geometry must be split at the cell boundaries and its complete attribute description must be repeated in each cell. 

## **2.3 Topology** 

ENC data must be encoded using chain-node topology (see S-57 Part 2, clause 2.2.1.2). 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 9](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=9) ---

ENC Product Specification 

3 

# **3. Objects and attributes** 

## **3.1 Feature object identifiers** 

Each feature object must have a unique world-wide identifier. This identifier, called the feature object identifier, is formed by the binary concatenation of the contents of the subfields of the � Feature Object Identifier � [FOID] field. 

For ENC the feature object identifier may be used to identify multiple instances of the same object. For example, the same object may appear in different usages, or an object may be split by the cell structure. In these circumstances each instance of this object may have the same identifier. 

Feature object identifiers must not be reused, even when a feature has been deleted. 

## **3.2 Standard object classes and attributes** 

Only object classes, attributes and attribute values which are defined in the IHO Object Catalogue  (S-57, Appendix A) may be used in an ENC. Of the object classes defined in the IHO Object catalogue, the following ones are prohibited for use in ENC: 

CANBNK LAKSHR RIVBNK SQUARE M_HDAT M_PROD M_UNIT C_STAC $AREAS $LINES $CSYMB $COMPS $TEXTS 

## **3.3 Objects permitted for use in ENC and their geometric primitives** 

The following is a list of those object classes allowed in an ENC and the geometric primitives allowed for each of them (P = point, L = line, A = area, N = none). 

|ACHARE|P|A|ACHBRT|P|A|ADMARE|||A|AIRARE|P|A|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|BCNCAR|P||BCNISD|P||BCNLAT|P|||BCNSAW|P||
|BCNSPP|P||BERTHS|P<br>|L<br>A|BOYCAR|P|||BOYINB|P||
|BOYISD|P||BOYLAT|P||BOYSAW|P|||BOYSPP|P||
|BRIDGE|P<br>L|A|BUAARE|P|A|BUISGL|P||A|CANALS||L<br>A|
|CAUSWY|L|A|CBLARE||A|CBLOHD||L||CBLSUB||L|
|CGUSTA|P||CHKPNT|P|A|COALNE||L||CONVYR||L<br>A|
|CONZNE||A|COSARE||A|CRANES|P||A|CTNARE|P|A|
|CTRPNT|P||CTSARE|P|A|CURENT|P|||CUSZNE||A|
|DAMCON|P<br>L|A|DAYMAR|P||DEPARE||L|A|DEPCNT||L|
|DISMAR|P||DOCARE||A|DRGARE|||A|DRYDOC||A|
|DMPGRD|P|A|DYKCON||L<br>A|DWRTCL||L||DWRTPT||A|
|EXEZNE||A|FAIRWY||A|FERYRT||L|A|FLODOC||L<br>A|
|FNCLNE|L||FOGSIG|P||FORSTC|P|L|A|FRPARE||A|
|FSHFAC|P<br>L|A|FSHGRD||A|FSHZNE|||A|GATCON|P|L<br>A|
|GRIDRN|P|A|HRBARE||A|HRBFAC|P||A|HULKES|P|A|
|ICEARE||A|ICNARE|P|A|ISTZNE|||A|LAKARE||A|
|LNDARE|P<br>L|A|LNDELV|P<br>|L|LNDMRK|P|L|A|LNDRGN|P|A|
|LIGHTS|P||LITFLT|P||LITVES|P|||LOCMAG|P|L<br>A|
|LOGPON|P|A|LOKBSN||A|MAGVAR|P|L|A|MARCUL|P|L<br>A|



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 10](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=10) ---

ENC Product Specification 

4 

|MIPARE|P|A|MORFAC|P<br>|L<br>A|NAVLNE||L|OBSTRN|P<br>|L<br>A|
|---|---|---|---|---|---|---|---|---|---|---|---|
|OFSPLF|P|A|OSPARE||A|OILBAR||L|PILBOP|P|A|
|PILPNT|P||PIPARE|P|A|PIPOHD||L|PIPSOL|P<br>|L|
|PONTON||L<br>A|PRCARE|P|A|PRDARE|P|A|PYLONS|P|A|
|RADLNE||L|RADRNG||A|RADRFL|P||RADSTA|P||
|RAILWY||L|RAPIDS|P<br>|L<br>A|RCRTCL||L|RCTLPT|P|A|
|RDOCAL|P<br>|L|RDOSTA|P||RECTRC||L<br>A|RESARE||A|
|RETRFL|P||RIVERS||L<br>A|ROADWY|P<br>|L<br>A|RSCSTA|P||
|RTPBCN|P||RUNWAY|P<br>|L<br>A|SBDARE|P<br>|L<br>A|SEAARE|P|A|
|SILTNK|P|A|SISTAT|P||SISTAW|P||SLCONS|P<br>|L<br>A|
|SLOTOP||L|SLOGRD|P|A|SMCFAC|P|A|SOUNDG|P||
|SNDWAV|P<br>|L<br>A|SPLARE|P|A|SPRING|P||STSLNE||L|
|SUBTLN||A|SWPARE||A|TESARE||A|TIDEWY||L<br>A|
|TOPMAR|P||TSELNE||L|TSEZNE||A|TSSBND||L|
|TSSCRS||A|TSSLPT||A|TSSRON||A|TUNNEL|P<br>|L<br>A|
|TWRTPT||A|UNSARE||A|UWTROC|P||VEGATN|P<br>|L<br>A|
|WATFAL|P<br>|L|WATTUR|P<br>|L<br>A|WEDKLP|P|A|WRECKS|P|A|
|C_AGGR||N|C_ASSO||N|M_ACCY||A|M_COVR||A|
|M_CSCL||A|M_HOPA||A|M_NPUB|P|A|M_NSYS||A|
|M_QUAL||A|M_SDAT||A|M_SREL||L<br>A|M_VDAT||A|
|T_HMON|P|A|T_NHMN|P|A|T_TIMS|P|A|TS_FEB|P|A|
|TS_PAD|P|A|TS_PNH|P|A|TS_PRH|P|A|TS-TIS|P<br>t|A<br>able 3.1|



## **3.4 Meta objects** 

The maximum use must be made of meta objects to reduce the attribution on individual objects. In a base data set (EN Application profile, see clause 6.3), some meta objects are mandatory. Each of these object classes must provide an exhaustive, non-overlapping coverage of the part of the cell containing data. 

These classes are in the following list: 

M_COVR M_QUAL 

The meta object M_COVR must also cover any part of the cell that does not contain geographical data. 

The meta object M_NSYS with the attribute MARSYS (to indicate the system of navigational marks) must also provide an exhaustive non-overlapping coverage of the part of the cell containing data. However, other M_NSYS objects with the atribute ORIENT (to indicate a local direction of buoyage) may overlap these objects. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 11](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=11) ---

ENC Product Specification 

5 

## **3.5 Geo and meta object attributes** 

### **3.5.1 Missing attribute values** 

In a base data set (EN application profile), when an attribute code is present but the attribute value is missing, it means that the producer wishes to indicate that this attribute value is unknown. 

In a revision data set (ER application profile), when an attribute code is present but the attribute value is missing it means: 

- that the value of this attribute is to be replaced by an unknown value if it was present in the original data set, 

- that an unknown value is to be inserted if the attribute was not present in the original data set. 

In both cases the missing attribute value is encoded by the means described in S-57 Part 3, clause 2.1. 

### **3.5.2 Mandatory attributes** 

There are four reasons why an attribute may be considered to be mandatory : 

- some attributes are necessary, as they determine whether an object is in the display base, 

- � some objects make no sense without certain attributes, 

- some attributes are necessary to determine which symbol is to be displayed, 

- some attributes are required for safety of navigation. 

The following table gives the attributes which are mandatory for each object class. When an object class is not in the list it means that there are no mandatory attributes for this class. 

The attribute COLPAT is mandatory for any object that has more than one colour. 

|**Object Class**|**Attributes**|||||
|---|---|---|---|---|---|
|ADMARE|JRSDTN|||||
|BCNCAR|BCNSHP|CATCAM|COLOUR|||
|BCNISD|BCNSHP|COLOUR||||
|BCNLAT|BCNSHP|CATLAM|COLOUR|||
|BCNSAW|BCNSHP|COLOUR||||
|BCNSPP|BCNSHP|CATSPM|COLOUR|||
|BERTHS|OBJNAM|||||
|BOYCAR|BOYSHP|CATCAM|COLOUR|||
|BOYINB|BOYSHP|COLOUR||||
|BOYISD|BOYSHP|COLOUR||||
|BOYLAT|BOYSHP|CATLAM|COLOUR|||
|BOYSAW|BOYSHP|COLOUR||||
|BOYSPP|BOYSHP|CATSPM|COLOUR|||
|BRIDGE|over naviga<br>over non na|ble water :<br>vigable water:|CATBRG<br>none|non-opening :<br>opening :<br>opening bridges with limited clearance<br>when open :|VERCLR<br>VERCCL<br>VERCOP|



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 12](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=12) ---

ENC Product Specification 

6 

|CBLOHD|Over naviga|ble water :|VERCSA|or if this is u|nknown :|VERCLR|
|---|---|---|---|---|---|---|
||other case :||none||||
|CONVYR|over navigab<br>other case :|le water :|VERCLR<br>none||||
|CONZNE|NATION||||||
|COSARE|NATION||||||
|CTNARE|at least one|of :|INFORM|TXTDSC|||
|CURENT|CURVEL|ORIENT|||||
|CUSZNE|NATION||||||
|DAYMAR|COLOUR|TOPSHP|||||
|DEPARE|DRVAL1|DRVAL2|||||
|DEPCNT|VALDCO||||||
|DRGARE|DRVAL1||||||
|DWRTCL|ORIENT|TRAFIC|CATTRK||||
|DWRTPT|ORIENT|TRAFIC|DRVAL1||||
|EXEZNE|NATION||||||
|FERYRT|CATFRY||||||
|FOGSIG|CATFOG||||||
|FSHZNE|NATION||||||
|GATCON|if navigable|at compilation s|cale :|HORCLR|||
|HRBFAC|CATHAF||||||
|ICEARE|CATICE||||||
|LIGHTS|all lights, exc|ept air obstruc|tion light or fog|detector light|COLOUR|LITCHR|
||if it is an air<br>if it is a secto<br>if it is not a fi<br>if it is directio|obstruction ligh<br>r light :<br>xed light, in ad<br>nal, or moiré e|t or fog detecto<br>dition :<br>ffect :|r light :|CATLIT<br>SECTR1<br>SIGPER<br>ORIENT|SECTR2<br>SIGGRP|
|LITFLT|COLOUR||||||
|LITVES|COLOUR||||||
|LNDELV|ELEVAT||||||
|LNDMRK|CATLMK|CONVIS|||||
|LNDRGN|at least one|of :|CATLND|OBJNAM|||
|LOCMAG|VALLMA||||||
|MAGVAR|RYRMGV|VALACM|VALMAG||||
|MARCUL|if under wate|r :|VALSOU|WATLEV|||
|MORFAC|CATMOR||||||
|NAVLNE|CATNAV|ORIENT|||||



|CATNAV<br>ORIENT|
|---|



S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 13](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=13) ---

ENC Product Specification 

7 

|OBSTRN|VALSOU|WATLEV|||||
|---|---|---|---|---|---|---|
|PIPOHD|over naviga<br>other case :|ble water :|VERCLR<br>none||||
|PRCARE|at least one|of :|INFORM|TXTDSC|||
|PRDARE|CATPRA||||||
|PYLONS|CATPYL||||||
|RADLNE|ORIENT||||||
|RCRTCL|CATTRK||||||
|RCTLPT|ORIENT||||||
|RDOCAL|ORIENT|TRAFIC|||||
|RECTRC|ORIENT|TRAFIC|CATTRK||||
|RESARE|at least one|of :|CATREA|RESTRN|||
|RTPBCN|CATRTB||||||
|SBDARE|at least one|of :|NATSUR|NATQUA|||
|SEAARE|at least one|of :|CATSEA|OBJNAM|||
|SISTAT|CATSIT||||||
|SISTAW|CATSIW||||||
|SMCFAC|CATSCF||||||
|STSLNE|NATION||||||
|SWPARE|DRVAL1||||||
|TESARE|NATION||||||
|TOPMAR|TOPSHP||||||
|TSSLPT|ORIENT|except when|the lane part i|s a junction|||
|TWRTPT|ORIENT|TRAFIC|||||
|UWTROC|VALSOU|WATLEV|||||
|VEGATN|CATVEG||||||
|WATTUR|CATWAT||||||
|WRECKS|WATLEV|at least one|of :|CATWRK|VALSOU||
|M_ACCY|at least one|of :|HORACC|VERACC|POSACC|SOUACC|
|M_COVR|CATCOV||||||
|M_CSCL|CSCALE||||||
|M_HOPA|HORDAT|SHIPAM|||||
|M_NSYS|MARSYS or|ORIENT|||||
|M_QUAL|CATZOC||||||
|M_SDAT|VERDAT||||||
|M_VDAT|VERDAT||||||
|T_TIMS|TIMEND|TIMSTA|T_HWLW||||



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 14](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=14) ---

ENC Product Specification 

8 

|T_NHMN|T_MTOD|T_THDF|||
|---|---|---|---|---|
|T_HMON|T_MTOD|T_VAHC|||
|TS_FEB|CAT_TS|CURVEL|ORIENT||
|TS_PAD|TS_TSP||||
|TS_PNH|T_MTOD|T_THDF|||
|TS_PRH|T_MTOD|T_VAHC|||
|TS_TIS|TIMEND|TIMSTA|TS_TSV|T_TINT|



table 3.2 

### **3.5.3 Prohibited attributes** 

The attributes from the following list are prohibited for any object : 

CATQUA DUNITS HUNITS PUNITS RECDAT RECIND SCAMAX 

HORDAT is only permitted for the meta object M_HOPA 

### **3.5.4 Numeric attribute values** 

Floating point or integer attribute values must not be padded by non-significant zeroes. E.g. : For a signal period of 2.5 sec, the value of SIGPER must be 2.5 and not 02.500. 

### **3.5.5 Text attribute values** 

The lexical level used for the � Feature Record Attribute � [ATTF] field must be 1 (ISO 8859-1). Lexical level 1 or 2 may be used for the � Feature Record National Attribute � [NATF] field. Format effecting (C0) characters as defined in S-57 Part 3, Annex B are prohibited. The delete character is only used in the update mechanism (see S-57 part 3, clause 8.4.2.2.a and 8.4.3.2.a). 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 15](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=15) ---

ENC Product Specification 

9 

### **3.5.6 Hierarchy of meta data** 

The following table indicates : 

- individual attributes that supersede meta object attributes, 

- meta object attributes that supersede the data set subfields (see clauses 6.3.2 and 6.4.2). 

|**Field**|**Subfield**|**Meta object class**|**Meta object attribute**|**Geo or spatial object attribute**|
|---|---|---|---|---|
|DSID|AGEN|The use of M_PROD is|prohibited||
|DSID|UADT|The use of M_PROD is|prohibited||
|DSID|ISDT|The use of M_PROD is|prohibited||
|DSPM|HDAT|The use of M_HDAT is p|rohibited|The use of HORDAT is prohibited|
|DSPM|VDAT|M_VDAT|VERDAT|VERDAT|
|DSPM|SDAT|M_SDAT|VERDAT|VERDAT|
|DSPM|CSCL|M_CSCL|CSCALE||
|DSPM|DUNI|The use of M_UNIT is pr|ohibited|The use of DUNITS is prohibited|
|DSPM|HUNI|The use of M_UNIT is pr|ohibited|The use of HUNITS is prohibited|
|DSPM|PUNI|The use of M_UNIT is p|rohibited|The use of PUNITS is prohibited|
|||M_ACCY|HORACC|HORACC|
|||M_ACCY|POSACC|POSACC|
|||M_ACCY|SOUACC|SOUACC|
|||M_ACCY|VERACC|VERACC|
|||M_NSYS|MARSYS|MARSYS|
|||M_NSYS|ORIENT|Attribute ORIENT of an individual object<br>does not supersede the meta object<br>attribute.|
|||M_QUAL|CATZOC|POSACC,SOUACC and TECSOU|
|||M_QUAL|SOUACC|SOUACC|
|||M_QUAL|POSACC|POSACC|
|||M_SREL|SURATH|SORIND|
|||M_SREL|SUREND|SORDAT|
|||M_SREL|SURSTA|SORDAT|
|||M_SREL|TECSOU|TECSOU|



table 3.3 

When there is no meta object attribute, an individual attribute can supersede a data set subfield. 

It is prohibited to use an attribute on an individual object, if this attribute has the same value as the general value defined by the meta object or the equivalent data set subfield. It is prohibited to use a meta object, if the information given by this meta object is the same as the value given by the equivalent data set subfield. 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 16](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=16) ---

ENC Product Specification 

10 

### **3.5.7 New attribute values in Edition 3.1** 

For reasons of backward compatibility with Edition 3.0, attribute values which appear for the first time in Edition 3.1 which are listed below, must have their meaning described in the attribute INFORM (e.g. wellhead mark). 

|CATACH|10:|anchorage for a limited period of time|
|---|---|---|
|CATCOA<br>|11:<br>|shelly shore<br>|
|CATFOR|6:|redoubt|
|CATGAT<br>|6:<br>|sluice<br>|
|CATHAF|12:<br>|syncrolift<br>|
||13:|straddle carrier|
|CATLND<br>|20:<br>|cay<br>|
|CATLMK|21:|large rock or boulder on land|
|CATMFA<br>|5:<br>|pearl culture farm<br>|
|CATOBS|10:|boom|
|CATPRA|10:|slag heap/spoil heap|
|CATRSC|7:<br>|aid radio station<br>|
||8:|first aid equipment|
|CATREA<br>|26:<br>|water skiing area<br>|
|CATSEA|54:|reach|
|CATSLC|17:|log ramp|
|CATSIT<br>|10:<br>|traffic control light<br>|
|CATSIW|15:|water level gauge|
|CATSCF|32:|mechanics workshop|
||33:|guard and/or security service|
|CATSPM|53:|wellhead mark|
||54:<br>|channel separation mark<br>|
||55:|marine farm mark|
||56:|artificial reef mark|
|RESTRN|16:|discharging prohibited|
||17:|discharging restricted|
||18:|industrial or mineral exploration/development prohibited<br>|
||19:|industrial or mineral exploration/development restricted|
||20:|drilling prohibited|
||21:|drilling restricted|
||22:|removal of historical artifacts prohibited|
||23:|cargo transhipment (lightering) prohibited|
||24:|dragging prohibited|
||25:|stopping prohibited|
||26:|landing prohibited|
||27:|speed restricted|
|VERDAT|30:|highest astronomical tide (HAT)|
|WATLEV|7:|floating|



## **3.6 Cartographic objects** 

The use of cartographic objects is prohibited. 

## **3.7 Time varying objects** 

The ENC may contain information about magnetic variation, tides, tidal streams and currents. Depth information should only be displayed as it has been provided in the ENC and not adjusted by tidal height. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 17](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=17) ---

ENC Product Specification 

11 

## **3.8 Geometry** 

Edges must be encoded using SG2D fields only. ARCC fields (curves) must not be used. Despite the saving in data volume offered by the use of arcs/curves, the disadvantages are such (e.g. during updating, generating warnings/alarms) that they must not be used for ENC. Linear features must not be encoded at a point density greater than 0.3 mm at compilation scale. 

The presentation of symbolised lines may be affected by line length. Therefore, the encoder must be aware that splitting a line into numerous small edges may result in poor symbolisation. In certain circumstances, the symbolisation of an edge may need to be suppressed. This is done using the value {1} in the � Masking Indicator � [MASK] subfield of the � Feature Record to Spatial Record Pointer � [FSPT] field. If the value in the � Usage Indicator � [USAG] subfield is set to {3} (exterior boundary truncated by the data limit), the MASK subfield must be set to {255} (null), in all other cases it must set to {2}. 

## **3.9 Relationships** 

There are two ways to define relationships between objects : 

- nominated master feature record, 

- collection objects of classes � aggregation � (C_AGGR), or � association � (C_ASSO). 

The use of the Catalogue Cross Reference record is prohibited. The use of the collection object class C_STAC is prohibited. 

All hierarchical relationships (master to slave) must be encoded by using a nominated � master � feature record carrying the pointers to the � slave � objects in the � Relationship Indicator � [RIND] subfield in the � Feature Record to Feature Object Pointer � [FFPT] field with the value {2} = slave. 

All association or aggregation relationships using collection objects are assumed to be peer to peer. The � Relationship Indicator � [RIND] subfield of these collection feature records must be {3} = peer. 

The use of these relationships is described in Appendix B1, Annex A � Use of the Object Catalogue for ENC". 

## **3.10 Groups** 

There are two groups defined for ENC. These are Group 1 (skin of the earth) and Group 2 for all other geo feature objects. 

The group number is indicated in the � Group � [GRUP] subfield of the � Feature Record Identifier � [FRID] field. 

### **3.10.1 Group 1 (skin of the earth)** 

Each area covered by a meta object M_COVR with CATCOV = 1 must be totally covered by a set of geo objects of type area that do not overlap each other (the skin of the earth). These objects make up Group 1. 

The list below contains the objects that must always be in Group 1, if they appear in the dataset and if they are of type area. 

DEPARE DRGARE FLODOC HULKES LNDARE PONTON UNSARE 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 18](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=18) ---

ENC Product Specification 

12 

### **3.10.2 Group 2 (all other objects)** 

All feature objects which are not in Group 1 are in Group 2. 

## **3.11 Language and alphabet** 

### **3.11.1 Language** 

The exchange language must be English. Other languages may be used as a supplementary option. In general this means that, when a national language is used in textual national attributes (NINFOM, NOBJNM, NPLDST), the English translation must exist in the international attributes (INFORM, OBJNAM, PILDST). However, national geographic names do not need to be translated in the international attributes, they may be left in their original national language form or may be transliterated or transcribed. 

### **3.11.2 Use of lexical level 2** 

If the national language cannot be expressed in lexical levels 0 or 1, the following rules apply: 

- the exact spelling in the national language is encoded in the � National Attributes � [NATF] field using lexical level 2. 

- translated text, including transliterated or transcribed national geographic names is encoded in the � International Attributes � [ATTF] field using lexical level 0 or 1. 

Where possible international standards should be used for the transliteration of non-Latin alphabets. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 19](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=19) ---

ENC Product Specification 

13 

# **4. Cartographic framework** 

## **4.1 Horizontal datum** 

The horizontal datum must be WGS 84. Therefore, the � Horizontal Geodetic Datum � [HDAT] subfield in the � Data Set Parameter � [DSPM] field must have the value of {2}. 

The mariner may have to display information other than ENC data and ENC updates. In cases where this information is based on a horizontal datum other than WGS 84, it can be converted to WGS 84 by means of the meta object Horizontal datum shift parameter (M_HOPA). 

## **4.2 Vertical and sounding datum** 

The various levels which are used on paper charts for elevations and soundings will be used. The default values are encoded in the � Vertical Datum � [VDAT] subfield and the � Sounding Datum � [SDAT] subfield in the � Data Set Parameter � [DSPM] field. 

## **4.3 Projection** 

No projection is used, therefore the � Data Set Projection � [DSPR] field must not be used. Coordinates must be encoded as geographical positions (latitude, longitude). 

## **4.4 Units** 

Units to be used in an ENC are : 

- Position : latitude and longitude in decimal degrees (converted into integer values, see below). 

- Depth : metres. 

- Height : metres. 

- Positional accuracy: metres. 

- Distance : nautical miles and decimal miles, or metres as defined in the IHO Object Catalogue (see S-57, Appendix A ). 

The default values for depth units, height units and positional accuracy units are encoded in the � Units of Depth Measurement � [DUNI], � Units of Height Measurement � [HUNI] and � Units of Positional Accuracy � [PUNI] subfields in the � Data Set Parameter � [DSPM] field. 

Latitude and longitude values are converted from decimal degrees to integers by means of the � Coordinate Multiplication Factor � [COMF] subfield value in the � Data Set Parameter � [DSPM] field. The integer values are encoded in the � Coordinate in Y-axis � [YCOO] subfield and the � Coordinate in X-axis � [XCOO] subfield. The number of decimal digits is chosen by the data producer and is valid through out the data set. 

E.g. : If the producer chooses a resolution of 0.0001 � (10<sup>-4</sup> ), then the value of COMF is 10 000 (10<sup>4</sup> ). A longitude = 34.5678 � is converted into XCOO = longitude * COMF = 34.5678*10 000 = 345678. The integer value of the converted coordinate is encoded in binary form. 

Depths are converted from decimal meters to integers by means of the � 3-D (Sounding) Multiplication Factor � [SOMF] subfield value in the � Data Set Parameter � [DSPM] field. The integer values are encoded in the � 3-D (Sounding) Value � [VE3D] subfield. Soundings are never encoded with a resolution greater than one decimeter, so the value of SOMF must be 10 encoded in binary form. 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 20](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=20) ---

ENC Product Specification 

14 

# **5. Provision of data** 

## **5.1 Implementation** 

The binary implementation of S-57 must be used for ENC. Therefore, the � Implementation � [IMPL] subfield of the � Catalogue Directory � [CATD] field must be set to � BIN � for the data set files. 

## **5.2 Compression** 

The use of compression algorithms is prohibited. 

## **5.3 Encryption** 

ENC data may be protected from unauthorised use, possibly by the use of encryption algorithms. 

## **5.4 Exchange set** 

### **5.4.1 Content of the exchange set** 

The records defined in the main part of this standard are grouped in two file types : catalogue and data set files. 

An exchange set is composed of one and only one catalogue file and at least one data set file. 

Text and picture files may also be included in the ENC exchange set. These files may be included in an exchange set by a data producer to provide additional information such as that normally contained in sailing directions or coastal pilots. These files must be in ASCII text format or TIF format. Files in other formats (including application files which may be used to manipulate text or picture files) may be included in an exchange set by private agreement between the producer and the receiver. 

An exchange set may also contain a README file. 

Exchange set 

| |--<1>-- README file | |--<1>-- Catalogue file | |--<R>-- Data set file | |--<R>-- Text file | |--<R>-- Picture file 

The README file is an optional ASCII file of general information. 

The catalogue file acts as the table of contents for the exchange set. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 21](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=21) ---

ENC Product Specification 

15 

Each data set file contains data for one cell (see clause 2.2). This includes: 

- data set descriptive information that is specific to the data set, 

- the description and location of the real-world entities. 

Text and picture files do not conform to ISO/IEC 8211 and are not described in the main body of S-57. These files are specific to this Product Specification. 

### **5.4.2 Volume naming** 

An exchange set may be split across several media volumes, therefore, each media volume must be uniquely identified within the exchange set. A file must not be split across volumes. Individual volumes must conform to the following naming convention: 

VSSXNN 

where: 

V is the mandatory first character. SS is the sequence number of the specific volume within the exchange set. X is the mandatory separator character. NN is the total number of media volumes within the exchange set. 

For example, volume one of a three volume exchange set would be named V01X03. 

### **5.4.3 Directory structure** 

The following directory structure is mandatory. 

On each volume within an exchange set there must be a root directory called ENC_ROOT. The  catalogue file for the exchange set must be in the ENC_ROOT directory of the first volume of the exchange set. The ENC_ROOT directory of the first volume may also contain a README file, containing ASCII text. Further directories and sub-directories may be defined under the root directory on any volume in the exchange set. The following example shows an example directory structure for a MS-DOS volume: 

```
Volume in drive A is V01X02
Directory of A:\ENC_ROOT
```

|`.              <DIR>`||`09-15-96 12:40p .`|
|---|---|---|
|`..             <DIR>`||`09-15-96 12:40p ..`|
|`CATALOG  031`|`1,584`|`09-15-96 12:46p CATALOG.031`|
|`NL600021 000`|`45,584`|`09-15-96 12:50p NL600021.000`|
|`NL600021 001`|`1,095`|`09-15-96 12:54p NL600021.001`|
|`NL600021 002`|`722`|`09-15-96 12:54p NL600021.002`|
|`README   TXT`|`504`|`09-15-96 12:44p README.TXT`|
|`5 file(s)`|`4`|`9,489 bytes`|
|`2 dir(s)`|`1,40`|`5,952 bytes free`|



For each file in the exchange set the catalogue file must contain the name of the volume on which it is held and the full path name relative to the root directory of that volume. The full path name relative to the root directory must be encoded in the FILE subfield of the � Catalogue Directory � [CATD] field. The LFIL subfield of the CATD field may be used for other purposes. The full path name of the NL600021.000 file shown in the example is NL600021.000. 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 22](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=22) ---

ENC Product Specification 

16 

In the interests of efficient processing, it is recommended that a sub-directory contains no more than sixtyfour files. 

## **5.5 Data sets** 

Four kinds of data sets may be produced : 

- new data set : no ENC data has previously been produced for this area and for the same navigational purpose. 

- update : changing some information in an existing data set. 

- re-issue of a data set : including all the updates applied to the original data set up to the date of the reissue. A re-issue does not contain any new information additional to that previously issued by updates. 

- � new edition of a data set : including new information which has not been previously distributed by updates. 

Each new data set, re-issue, or new edition is called a base cell file. 

A data set containing updates to one base cell file is called an update cell file. 

## **5.6 File naming** 

### **5.6.1 README file** 

README.TXT is the mandatory name for this file. 

### **5.6.2 Catalogue file** 

The catalogue file of the exchange set must be named CATALOG.EEE. Where EEE is the edition number of S-57 used for this exchange set, i.e. 031 for this edition (3.1). No other file may be named CATALOG. 

### **5.6.3 Data set files** 

The data set files are named according to the specifications given below : 

CCPXXXXX.EEE 

| | | | | | | |----- EEE = update number | | |-------------- XXXXX = individual cell code | |------------------- P = navigational purpose |----------------------- CC = producer code 

The main part forms an eight character identifier where : 

- the first two characters identify the producer. This list is given in Annex A to Appendix A (IHO Object Catalogue). 

- the third character indicates the navigational purpose (see clause 2.1). 

- the fourth to eighth characters are used for the cell code. This code can be used in any way by the producer to provide the unique file name. If characters other than numbers are used only uppercase letters are allowed. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 23](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=23) ---

ENC Product Specification 

17 

A valid base cell file must be uniquely identified world wide by its name, and have the extension 000. 

The extension is used for updating (see clause 5.7). 

Update cell files have the same name as the original base cell file, with an extension number greater than or equal to 001. They cover the same geographical area as the base cell file to which they apply. 

### **5.6.4 Text and picture files** 

The text and picture files must be named according to the specifications given below : 

CCXXXXXX.EEE | | | | | |------EEE = usual extension code (.TIF and .TXT) | |------------------XXXXX = individual file code |------------------------ CC = producer code 

The main part forms an eight character identifier where : 

- the first two characters identify the producer. This list is given in Annex A of the IHO Object Catalogue (S-57, Appendix A). 

- the third to eighth characters can be used in any way by the producer to provide the unique file name. If characters other than numbers are used only uppercase letters are allowed. 

The extension is used to identify the type of the file. It must be the usual extension for these types of files, i.e. . TXT for ASCII files and .TIF for picture files. These three characters are also indicated in the � Implementation � [IMPL] subfield of the � Catalogue Directory � [CATD] field. 

Files in other formats, provided through private agreements, should follow the same general naming convention and use the appropriate file extension to indicate their format. 

## **5.7 Updating** 

In order to ensure that updates are incorporated into the SENC in the correct sequence without any omission, the file extension and a number of subfields in the � Data Set Identification � [DSID] field are used in the following way : 

**file extension** every new data set, re-issue or new edition must have a � 000 � extension. For update cell files the extension is the number of the update, ranging from � 001 � to � 999". These numbers must be used sequentially, without omission. Number � 001 � is the first update after a new data set or a new edition, but not after a reissue. The update sequence is not interrupted by a re-issue. After a re-issue, subsequent updates may be incorporated into the SENC created from this reissue or to the SENC created from the original data and kept continuously updated. 

**edition number** when a data set is initially created, the edition number 1 is assigned to it. The edition number is increased by 1 at each new edition. Edition number remains the same for a re-issue. 

**update number** update number 0 is assigned to a new data set. The first update cell file associated with this new data set must have update number 1. The update number must be increased by one for each consecutive update, until a new edition is released. The new edition must have update number 0. A re-issue of a data set must have the update number of the last update applied to the data set. In the case of an update cell file the file extension is the same as the update number. 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 24](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=24) ---

ENC Product Specification 

18 

### **update application** 

this date is only used for the base cell files (i.e. new data sets, re-issue and new edition), not update cell files. All updates dated on or before this date must have been applied by the producer. 

### **issue date** 

date on which the data was made available by the data producer. 

Table 5.1 gives examples of the way to manage the file extension, the � Edition Number � [EDTN], the � Update Number � [UPDN], the � Update Application Date � [UADT] and the � Issue Date � [ISDT] subfields. 

|**Event**|**File extension**|**EDTN**|**UPDN**|**UADT**|**ISDT**|
|---|---|---|---|---|---|
|New data set|.000|1|0|19950104|19950104|
|Update 1|.001|1|1|prohibited|19950121|
|Update 2|.002|1|2|prohibited|19950225|
|...||||||
|Update 31|.031|1|31|prohibited|19950905|
|Re-issue of a data set|.000|1|31|19950905|19950910|
|Update 32|.032|1|32|prohibited|19951023|
|...||||||
|Update 45|.045|1|45|prohibited|19951112|
|New edition|.000|2|0|19951201|19951201|
|Update 1 to edition 2|.001|2|1|prohibited|19960429|
|...||||||



table 5.1 

This example table relates to the specifications given in S-52 App 1, � Guidance on Updating the Electronic Navigational Chart � , in the following way: 

- The update information encoded in each individual cell file is called a sequential update. 

- The collection of the update information encoded in the update cell files which have been issued since the last new data set, the last re-issue of a data set or since the last update was applied to the SENC is called a cumulative update. In the example, the cumulative update for the new data set starts with update number 1. The cumulative update for the re-issue of a data set starts with update number 32. The cumulative update for a data set to which update number n has been applied starts with update number n+1. 

- The update information which has been incorporated in a re-issue of a data set is called a compilation update. 

Each re-issue or new edition of a data set must have the same name as the base cell file which it replaces. 

The update mechanism is described in S-57 Part 3, clause 8. 

In order to delete a data set, an update cell file is created, containing only the Data Set General Information record with the � Data Set Identifier � [DSID] field. The � Edition Number � [EDTN] subfield must be set to 0. This message is only used to cancel a base cell file. 

To inform the mariner that a new edition is available, an update cell file is created, containing only the Data Set General Information record with the � Data Set Identifier � [DSID] field. The � Edition Number � [EDTN] subfield must contain a value one higher than the current edition number. 

In order to modify a text, picture or application file, a new file with the same name is created. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 25](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=25) ---

ENC Product Specification 

19 

When an object pointing to a text, picture or application file is deleted or updated so that it no longer references the file, the ECDIS software should check to see whether any other object reference the same file, before that file is deleted. 

An exchange set may contain base cell files and update cell files for the same cells. Under these circumstances the update cell files must follow on in the correct sequential order from the last update applied to the base cell file. 

The record version of each feature or vector record is indicated in the � Record Version � [RVER] subfield of the � Feature Record Identifier � [FRID] field or the � Vector Record Identifier � [VRID] field. At each update of a record, this version number is incremented by 1. 

## **5.8 Media** 

Data must be made available on CD-ROM or 3.5 � MS-DOS formatted diskettes. It may also be made available on any other physical media by private arrangement. Data may be provided via telecommunication links. 

## **5.9 Error detection** 

File integrity checks are based on the CRC-32 algorithm (a 32 bit Cyclic Redundancy Check algorithm) as defined in ANSI/IEEE Standard 802.3, the reference for which is given in clause 1.3. 

### **5.9.1 Implementation** 

The checksums for each data set are held in the � CRC � [CRCS] subfield of the � Catalogue Directory � [CATD] field. They allow the integrity of each file in the exchange set to be checked on receipt. The CRC value computed on the received file must the same as the CRC value transmitted. 

The CRC values are recorded in ASCII as a hexadecimal number least significant byte first. 

### 5.9.2 **Processing** 

Encoding is defined by the following generating polynomial : 

G(x) = x<sup>32</sup> + x<sup>26</sup> + x<sup>23</sup> + x<sup>22</sup> + x<sup>16</sup> + x<sup>12</sup> + x<sup>11</sup> + x<sup>10</sup> + x<sup>8</sup> + x<sup>7</sup> + x<sup>5</sup> + x<sup>4</sup> + x<sup>2</sup> + x + 1 

Processing is applied to relevant files as they appear in the exchange set. 

The CRC value of the file is defined by the following process : 

1. The first 32 bits of the data are complemented. 

2. The n bits of the data are then considered to be the coefficients of a polynomial M(x) of degree n-1. 

3. M(x) is multiplied by x<sup>32</sup> and divided by G(x), producing a remainder R(x) of degree <31. 

4. The coefficients of R(x) are considered to be a 32-bit sequence. 

5. The bit sequence is complemented and the result is the CRC. 

The hexadecimal format of CRCs are converted to ASCII characters and stored in the � Catalogue Directory � [CATD] field. 

An example of coding in C language is given in Annex B. 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 26](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=26) ---

ENC Product Specification 

### 20 

# **6. Application profiles** 

## **6.1 General** 

The application profiles define the structure and content of the catalogue file and data set file in an exchange set. 

### **6.1.1 Catalogue and data set files** 

These files are composed of the records and fields defined in the following tree structure diagrams (see clauses 6.2.1, 6.3.1 and 6.4.1). 

The order of data in each base or update cell file is described below : 

Data set file 

Data set general information record Data set geographic reference record (for EN application profile) Vector records Isolated nodes (SG3D) Isolated nodes (SG2D) Connected nodes Edges Feature records Meta features Geo features (ordered from slave to master) Collection features 

This order of records will enable the import software to check that the child record exists each time the parent record references it (i.e. it will already have read the child record so it will know if it exists or not). 

### **6.1.2 Records** 

Records and fields that do not appear in the following tree structure diagrams are prohibited. The order of records in the files must be the same as that described in these tree structure diagrams. The combination of the file name and the � Name � of the record must provide a unique world-wide identifier of the record. 

### **6.1.3 Fields** 

For base cell files, some fields may be repeated (indicated by <R>) and all of their content may be repeated (indicated by *). In order to reduce the volume of data, the encoder should repeat the sequence of subfields, in preference to creating several fields. 

### **6.1.4 Subfields** 

Mandatory subfields must be filled by a non-null value. Prohibited subfields must be encoded as missing subfields values (see S-57 Part 3, clause 2.1). The exact meaning of missing attribute values is defined in clause 3.5.1. 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 27](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=27) ---

ENC Product Specification 

21 

In the tables following the tree structure diagrams, mandatory subfields are shown by � M � in the � use � column and prohibited subfields by � P � in the same column. If there is nothing in this column, it means that the use of this subfield is optional. When a subfield value is prescribed, it is indicated in the � value � column. The � comment � column contains general comments and an indication of whether the subfield is ASCII or binary coded. 

## **6.2 Catalogue file** 

The catalogue has the same structure for EN and ER application profiles. 

### **6.2.1 Catalogue file structure** 

Catalogue file 

| 

- |--<R>-Catalogue Directory record 

| 

- |--0001-- ISO/IEC 8211 Record identifier | 

   - |--<1>-- CATD - Catalogue directory field 

### **6.2.2 Catalogue Directory field - CATD** 

NB : All subfield values are encoded as ASCII. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|CD||
|RCID|Record identification number|M|||
|FILE|File name|M||full path from ENC_ROOT directory|
|LFIL|File long name||||
|VOLM|Volume|M||name of volume on which file appears|
|IMPL|Implementation|M|ASC<br>BIN<br>TXT<br>TIF<br>...|for  the catalogue file<br>for the data set files<br>for ASCII text files (including the README.TXT file)<br>for picture files<br>or any other usual file extension for file provided<br>through private agreements (see clause 5.6.4)|
|SLAT|Southernmost latitude|||mandatory for data set files|
|WLON|Westernmost longitude|||mandatory for data set files|
|NLAT|Northernmost latitude|||mandatory for data set files|
|ELON|Easternmost longitude|||mandatory for data set files|
|CRCS|CRC|M||except for README and catalogue files|
|COMT|Comment||||



table 6.1 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 28](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=28) ---

ENC Product Specification 

22 

## **6.3 EN application profile** 

The EN application profile applies to any base cell file (i.e. new data set, re-issue and new edition of a data set). 

### **6.3.1 Base cell file structure** 

Base cell file 

| 

|--<1>--Data Set General Information record | | | |--0001 - ISO/IEC 8211 Record Identifier | | | |--<1>-- DSID - Data Set Identification field | | | |--<1>--DSSI - Data Set Structure Information field | |--<1>--Data Set Geographic Reference record | | | |--0001 - ISO/IEC 8211 Record Identifier | | | |--<1>--DSPM - Data Set Parameter field | |--<R>--Vector record | | | |--0001 - ISO/IEC 8211 Record Identifier | | | |--<1>--VRID - Vector Record Identifier field | | | |--<R>--ATTV* - Vector Record Attribute field | | | |--<R>--VRPT* - Vector Record Pointer field | | | | |--<R>--SG2D* - 2-D Coordinate field | |--or--- | | |--<R>--SG3D* - 3-D Coordinate (Sounding array) field | |--<R>--Feature record | |--0001 - ISO/IEC 8211 Record Identifier | |--<1>--FRID - Feature Record Identifier field | |--<1>--FOID - Feature Object Identifier field | |--<R>--ATTF* - Feature Record Attribute field | |--<R>--NATF* - Feature Record National Attribute field | |--<R>--FFPT* - Feature Record to Feature Object Pointer field | |--<R>--FSPT* - Feature Record to Spatial Record Pointer field 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 29](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=29) ---

ENC Product Specification 

23 

### **6.3.2 Field content (EN)** 

### **6.3.2.1 Data Set Identification field - DSID** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{10}|= DS, binary|
|RCID|Record identification number|M||binary|
|EXPP|Exchange purpose|M|{1}|data set is new, binary|
|INTU|Intended usage|M|{1} to {6}|navigational purpose, see clause 2.1, binary|
|DSNM|Data set name|M||file name with extension excluding path, ASCII|
|EDTN|Edition number|M||see clause 5.7, ASCII|
|UPDN|Update number|M||ASCII|
|UADT|Update application date|M||ASCII|
|ISDT|Issue date|M||ASCII|
|STED|Edition number of S-57|M|03.1|ASCII|
|PRSP|Product specification|M|{1}|= ENC, binary|
|PSDN|Product specification description|P||empty, ASCII|
|PRED|Product specification edition<br>number|M|2.0|ASCII|
|PROF|Application profile identification|M|{1}|= EN, binary|
|AGEN|Producing agency|M||binary|
|COMT|Comment|||ASCII|



table 6.2 

### **6.3.2.2 Data Set Structure Information field - DSSI** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|DSTR|Data structure|M|{2}|= chain node|
|AALL|ATTF lexical level|M|{0} or {1}||
|NALL|NATF lexical level|M|{0}, {1}<br>or {2}||
|NOMR|Number of meta records|M|||
|NOCR|Number of cartographic records|M|{0}|cartographic records are not permitted|
|NOGR|Number of geo record|M|||
|NOLR|Number of collection records|M|||
|NOIN|Number of isolated node records|M|||



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 30](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=30) ---

ENC Product Specification 

24 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NOCN|Number of connected node<br>records|M|||
|NOED|Number of edge records|M|||
|NOFA|Number of face records|M|{0}|faces are not permitted in chain node structure|



table 6.3 

### **6.3.2.3 Data Set Parameter field - DSPM** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{20}|= DP, binary|
|RCID|Record identification number|M||binary|
|HDAT|Horizontal geodetic datum|M|{2}|= WGS 84, binary|
|VDAT|Vertical datum|M||binary|
|SDAT|Sounding datum|M||binary|
|CSCL|Compilation scale of data|M||binary|
|DUNI|Units of depth measurement|M|{1}|=metres, binary|
|HUNI|Units of height measurement|M|{1}|=metres, binary|
|PUNI|Units of positional accuracy|M|{1}|=metres, binary|
|COUN|Coordinate units|M|{1}|= lat/long, binary|
|COMF|Coordinate multiplication factor|M||binary, see clause 4.4|
|SOMF|3-D (sounding) multiplication<br>factor|M|{10}|binary, see clause 4.4|
|COMT|Comment|||ASCII|



table 6.4 

### **6.3.2.4 Vector Record Identifier field - VRID** 

NB: All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{110}<br>or {120}<br>or {130}|= VI, isolated node<br>= VC, connected node<br>= VE, edge|
|RCID|Record identification number|M|||
|RVER|Record version|M|||
|RUIN|Record update instruction|M|{1}|= insert|



table 6.5 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 31](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=31) ---

ENC Product Specification 

25 

### **6.3.2.5 Vector Record Attribute field - ATTV** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||binary code for an attribute|
|ATVL|Attribute value|M||ASCII value. Missing attribute value = attribute is<br>relevant but value is unknown.|



table 6.6 

### **6.3.2.6 Vector Record Pointer field - VRPT** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NAME|Name|M|||
|ORNT|Orientation|M|{255}|= null|
|USAG|Usage indicator|M|{255}|= null|
|TOPI|Topology indicator|M|{1}<br>or {2}|= beginning node<br>= end node|
|MASK|Masking indicator|M|{255}|= null|



table 6.7 

### **6.3.2.7 2-D Coordinate field - SG2D** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|YCOO|Coordinate in Y axis|M||latitude (see clause 4.4)|
|XCOO|Coordinate in X axis|M||longitude (see clause 4.4)|



table 6.8 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 32](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=32) ---

ENC Product Specification 

26 

### **6.3.2.8 3-D Coordinate (Sounding array) field - SG3D** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|YCOO|Coordinate in Y axis|M||latitude (see clause 4.4)|
|XCOO|Coordinate in X axis|M||longitude (see clause 4.4 )|
|VE3D|3-D (sounding) value|M||value of sounding (see clause 4.4)|



table 6.9 

### **6.3.2.9 Feature Record Identifier field - FRID** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{100}|= FE|
|RCID|Record identification number|M|||
|PRIM|Object geometric primitive|M|{1}<br>or {2}<br>or {3}<br>or {255}|= point<br>= line<br>= area<br>= no geometry|
|GRUP|Group|M|{1}<br>or {2}|Group 1, see clause 3.10.1<br>Group 2, see clause 3.10.2|
|OBJL|Object label|M||binary code for an object class|
|RVER|Record version|M|||
|RUIN|Record update instruction|M|{1}|= insert|



table 6.10 

### **6.3.2.10 Feature Object Identifier field - FOID** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|AGEN|Producing agency|M|||
|FIND|Feature identification number|M|||
|FIDS|Feature identification subdivision|M|||



table 6.11 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 33](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=33) ---

ENC Product Specification 

27 

### **6.3.2.11 Feature Record Attribute field - ATTF** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||binary code for an attribute|
|ATVL|Attribute value|||ASCII value. Missing attribute value = attribute is<br>relevant but value is unknown.|



table 6.12 

### **6.3.2.12 Feature Record National Attribute field - NATF** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||binary code for an attribute|
|ATVL|Attribute value|||ASCII value. Missing attribute value = attribute is<br>relevant but value is unknown|



table 6.13 

### **6.3.2.13 Feature Record  to Feature Object Pointer field - FFPT** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|LNAM|Long name|M||binary|
|RIND|Relationship indicator|M|{2}<br>or {3}|= slave, binary<br>= peer, binary|
|COMT|Comment|||ASCII|



table 6.14 

### **6.3.2.14 Feature Record to Spatial Record Pointer field - FSPT** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NAME|Name|M|||
|ORNT|Orientation|M|{1}<br>or {2}<br>or {255}|= forward<br>= reverse<br>= null|
|USAG|Usage indicator|M|{1}<br>or {2}<br>or {3}<br>or {255}|= exterior<br>= interior<br>=exterior boundary, truncated by the data limit<br>= null|
|MASK|Masking indicator|M|{1}<br>or {2}<br>or {255}|= mask<br>= show<br>= null|



table 6.15 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 34](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=34) ---

ENC Product Specification 

28 

## **6.4 ER application profile** 

The ER application profile only applies to update cell files. 

### **6.4.1 Update cell file structure** 

Update cell file 

| 

|--<1>--Data Set General Information record | | | |--0001 - ISO/IEC 8211 Record Identifier | | | |--<1>--DSID - Data Set Identification field | | | |--<1>--DSSI - Data Set Structure Information field | |--<R>--Vector record | | | |--0001 - ISO/IEC 8211 Record identifier | | | |--<1>--VRID - Vector Record Identifier field | | | |--<R>--ATTV* - Vector Record Attribute field | | | |--<1>--VRPC - Vector Record Pointer Control field | | | |--<R>--VRPT* - Vector Record Pointer field | | | |--<1>--SGCC - Coordinate Control field | | | | |--<R>--G2D* - 2-D Coordinate field | |---or-- | | |--<R>--G3D* - 3-D Coordinate (Sounding array) field 

| 

|--<R>--Feature record | 

|--0001 - ISO/IEC 8211 Record identifier | |--<1>--FRID - Feature Record Identifier field | |--<1>--FOID - Feature Object Identifier field | |--<R>--ATTF* - Feature Record Attribute field | |--<R>--NATF* - Feature Record National Attribute field | |--<1>--FFPC - Feature Record to Feature Object Pointer Control field | |--<R>--FFPT* - Feature Record to Feature Object Pointer field | |--<1>--FSPC - Feature Record to Spatial Record Pointer Control field | |--<R>--FSPT* - Feature Record to Spatial Record Pointer field 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 35](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=35) ---

ENC Product Specification 

29 

### **6.4.2 Field content (ER)** 

### **6.4.2.1 Data Set Identification Field - DSID** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{10}|= DS, binary|
|RCID|Record identification number|M||binary|
|EXPP|Exchange purpose|M|{2}|data set is a revision, binary|
|INTU|Intended usage|M|{1} to {6}|navigational purpose, see clause 2.1, binary|
|DSNM|Data set name|M||file name with extension excluding path, ASCII|
|EDTN|Edition number|M||see clause 5.7, ASCII|
|UPDN|Update number|M||ASCII|
|UADT|Update application date|P||empty, ASCII|
|ISDT|Issue date|M||ASCII|
|STED|Edition number of S-57|M|03.1|ASCII|
|PRSP|Product specification|M|{1}|= ENC, binary|
|PSDN|Product specification description|P||empty, ASCII|
|PRED|Product specification edition<br>number|M|2.0|ASCII|
|PROF|Application profile identification|M|{2}|= ER, binary|
|AGEN|Producing agency|M||binary|
|COMT|Comment|||ASCII|



table 6.16 

### **6.4.2.2 Data Set Structure Information field - DSSI** 

NB: All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|DSTR|Data structure|M|{2}|= chain node|
|AALL|ATTF lexical level|M|{0} or {1}||
|NALL|NATF lexical level|M|{0} or {1}<br>or {2}||
|NOMR|Number of meta records|M|||
|NOCR|Number of cartographic records|M|{0}|cartographic records are not permitted|
|NOGR|Number of geo records|M|||
|NOLR|Number of collection records|M|||
|NOIN|Number of isolated node records|M|||
|NOCN|Number of connected node<br>records|M|||



S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 36](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=36) ---

ENC Product Specification 

30 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NOED|Number of edge records|M|||
|NOFA|Number of face records|M|{0}|faces are not permitted in chain node structure|



table 6.17 

### **6.4.2.3 Vector Record Identifier field - VRID** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{110}<br>or {120}<br>or {130}|= VI, isolated node<br>= VC, connected node<br>= VE, edge|
|RCID|Record identification number|M|||
|RVER|Record version|M|||
|RUIN|Record update instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|



table 6.18 

### **6.4.2.4 Vector Attribute field - ATTV** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||binary code for an attribute|
|ATVL|Attribute value|||ASCII value, missing attribute value = attribute value<br>is deleted or unknown (see clause 3.5.1)|



table 6.19 

### **6.4.2.5 Vector Record Pointer Control field - VRPC** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|VPUI|Vector record pointer update<br>instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|
|VPIX|Vector record pointer index|M|||
|NVPT|Number of vector record<br>pointers|M|||



table 6.20 

S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 37](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=37) ---

ENC Product Specification 

31 

### **6.4.2.6 Vector Record Pointer field - VRPT** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NAME|Name|M|||
|ORNT|Orientation|M|{255}|= null|
|USAG|Usage indicator|M|{255}|= null|
|TOPI|Topology indicator|M|{1}<br>or {2}|= beginning node<br>= end node|
|MASK|Masking indicator|M|{255}|= null|



table 6.21 

### **6.4.2.7 Coordinate Control field - SGCC** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|CCUI|Coordinate update instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|
|CCIX|Coordinate index|M|||
|CCNC|Number of coordinates|M|||



table 6.22 

### **6.4.2.8 2-D Coordinate field - SG2D** 

NB: All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|YCOO|Coordinate in Y axis|M||latitude (see clause 4.4)|
|XCOO|Coordinate in X axis|M||longitude (see clause 4.4)|



table 6.23 

### **6.4.2.9 3-D Coordinate (Sounding array) field - SG3D** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|YCOO|Coordinate in Y axis|M||latitude (see clause 4.4)|
|XCOO|Coordinate in X axis|M||longitude (see clause 4.4)|
|VE3D|3-D (sounding) value|M||value of sounding (see clause  4.4)|



table 6.24 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 38](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=38) ---

ENC Product Specification 

32 

### **6.4.2.10 Feature Record Identifier field - FRID** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|RCNM|Record name|M|{100}|= FE|
|RCID|Record identification number|M|||
|PRIM|Object geometric primitive|M|{1}<br>or {2}<br>or {3}<br>or {255}|= point<br>= line<br>= area<br>= no geometry|
|GRUP|Group|M|{1}<br>or {2}|Group 1, see clause 3.10.1<br>Group 2, see clause 3.10.2|
|OBJL|Object label|M||binary code for an object class|
|RVER|Record version|M|||
|RUIN|Record update instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|



table 6.25 

### **6.4.2.11 Feature Object Identifier field - FOID** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|AGEN|Producing agency|M|||
|FIND|Feature identification number|M|||
|FIDS|Feature identification subdivision|M|||
|||||table 6.26|



### **6.4.2.12 Feature Record Attribute field - ATTF** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||binary code for an attribute|
|ATVL|Attribute value|||ASCII value. Missing attribute value = attribute value<br>is deleted or unknown (see clause 3.5.1)|
|||||table 6.27|



S-57 Appendix B.1 

Edition 2.0 

November 2000

--- [page 39](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=39) ---

ENC Product Specification 

33 

### **6.4.2.13 Feature Record National Attribute field - NATF** 

NB: Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**Comment**|
|---|---|---|---|---|
|ATTL|Attribute label/code|M||Binary code for an attribute|
|ATVL|Attribute value|||ASCII value. Missing attribute value = attribute value<br>is deleted.|



table 6.28 

### **6.4.2.14 Feature Record to Feature Object Pointer Control field - FFPC** 

NB: All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**Comment**|
|---|---|---|---|---|
|FFUI|Feature object pointer update<br>instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|
|FFIX|Feature object pointer index|M|||
|NOPT|Number of feature object<br>pointers|M|||



table 6.29 

### **6.4.2.15 Feature Record to Feature Object Pointer field - FFPT** 

NB : Subfield values are encoded as ASCII or binary as indicated. 

|**Tag**|**subfield name**|**use**|**value**|**Comment**|
|---|---|---|---|---|
|LNAM|Long name|M||Binary|
|RIND|Relationship indicator|M|{2}<br>or {3}|= slave, binary<br>= peer, binary|
|COMT|Comment|||ASCII|



table 6.30 

### **6.4.2.16 Feature Record to Spatial Record Pointer Control field - FSPC** 

NB : All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**Comment**|
|---|---|---|---|---|
|FSUI|Feature to spatial record pointer<br>update instruction|M|{1}<br>or {2}<br>or {3}|= insert<br>= delete<br>= modify|
|FSIX|Feature to spatial record pointer<br>index|M|||
|NSPT|Number of feature to spatial<br>record pointers|M|||



table 6.31 

S-57 Appendix B.1 

November 2000 

Edition 2.0

--- [page 40](../../corpus/B/B2_S-57_Appendix_B1_ENC_Product_Spec.pdf#page=40) ---

ENC Product Specification 

34 

### **6.4.2.17 Feature Record to Spatial Record pointer field - FSPT** 

NB: All subfield values are encoded as binary. 

|**Tag**|**subfield name**|**use**|**value**|**comment**|
|---|---|---|---|---|
|NAME|name|M|||
|ORNT|orientation|M|{1}<br>or {2}<br>or {255}|= forward<br>= reverse<br>= null|
|USAG|usage indicator|M|{1}<br>or {2}<br>or {3}<br>or {255}|= exterior<br>= interior<br>= exterior boundary, truncated by the data limit<br>= null|
|MASK|Masking indicator|M|{1}<br>or {2}<br>or {255}|= mask<br>= show<br>= null|



table 6.32 

S-57 Appendix B.1 

Edition 2.0 

November 2000
