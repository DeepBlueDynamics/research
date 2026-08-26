<!-- source: corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf -->
<!-- source_sha256: a0fa6720eb440c2c6271340f9c2a476d2bc74ce205b3f5f6b977ea5c05b5864e -->
<!-- source_bytes: 169398 -->
<!-- source_pdf_link: ../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf -->
<!-- extractor: pymupdf4llm 1.28.2 / PyMuPDF 1.28.2 -->
<!-- pages: 8 -->
<!-- extracted_chars: 10946 -->
<!-- generated: 2026-08-26T21:55:29Z by tools/build_docs.py -->

--- [page 1](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=1) ---

# **INTERNATIONAL HYDROGRAPHIC ORGANIZATION** 



# **GUIDANCE ON UPDATING THE ELECTRONIC NAVIGATIONAL CHART** 

**Edition 4.0.0 - April 2012** 

Publication S-52 APPENDIX 1 

**Published by the International Hydrographic Bureau MONACO**

--- [page 2](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=2) ---

### © Copyright International Hydrographic Organization [2012] 

This work is copyright. Apart from any use permitted in accordance with the Berne Convention for the Protection of Literary and Artistic Works (1886), and except in the circumstances described below, no part may be translated, reproduced by any process, adapted, communicated or commercially exploited without prior written permission from the International Hydrographic Bureau (IHB). Copyright in some of the material in this publication may be owned by another party and permission for the translation and/or reproduction of that material must be obtained from the owner. 

This document or partial material from this document may be translated, reproduced or distributed for general information, on no more than a cost recovery basis. Copies may not be sold or distributed for profit or gain without prior written agreement of the IHB and any other copyright holders. 

In the event that this document or partial material from this document is reproduced, translated or distributed under the terms described above, the following statements are to be included: 

_“Material from IHO publication [reference to extract: Title, Edition] is reproduced with the permission of the International Hydrographic Bureau (IHB) (Permission No ……./…) acting for the International Hydrographic Organization (IHO), which does not accept responsibility for the correctness of the material as reproduced: in case of doubt, the IHO’s authentic text shall prevail.    The incorporation of material sourced from IHO shall not be construed as constituting an endorsement by IHO of this product.”_ 

_“This [document/publication] is a translation of IHO [document/publication] [name]. The IHO has not checked this translation and therefore takes no responsibility for its accuracy. In case of doubt the source version of [name] in [language] should be consulted.”_ 

The IHO Logo or other identifiers shall not be used in any derived product without prior written permission from the IHB.

--- [page 3](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=3) ---

# **INTERNATIONAL HYDROGRAPHIC ORGANIZATION** 



# **GUIDANCE ON UPDATING THE ELECTRONIC NAVIGATIONAL CHART** 

**Edition 4.0.0 - April 2012** 

Publication S-52 APPENDIX 1 

Published by the International Hydrographic Bureau 4, Quai Antoine 1er B.P. 445 - MC 98011 MONACO Cedex Principauté de Monaco Telefax: (377) 93 10 81 40 E-mail: info@iho.int Web: www.iho.int

--- [page 4](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=4) ---

Page intentionally left blank

--- [page 5](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=5) ---

1 

## **1 INTRODUCTION** 

In its previous edition (3<sup>rd</sup> Edition, December 1996), this Appendix of publication S-52 provided the guidance, for the updating service and the ECDIS, to support the updating of ENCs issued through a Regional ENC Coordinating Centre (RENC). 

The guidance provided in 1996 applied to ENC updates production by HOs, their distribution and their acceptance by the ECDIS. In 2009, the ENC Updating Working Group (EUWG) of the IHO Hydrographic Services and Standards Committee (HSSC) was tasked to review this Appendix to consider its relevance in S-52 and the possibility of incorporation of some of the guidance into other existing IHO publications such as S-57 and S-65. 

As a result, guidance related to ENC updates production by HOs and their distribution has been reviewed and mainly integrated into Edition 2.0.0 of IHO publication S-65 “ENC Production, Maintenance and Distribution Guidance” and Edition 3.0.0 of IHO Publication S-57 Appendix B.1, Annex A “Use of the Object Catalogue for ENC”. It is now advisable to refer to S-65 and S- 57 for ENC updates production guidance and data delivery. 

Parts of the former Edition of this Appendix which are related to the acceptance of updates by the ECDIS are quoted as references in IEC61174 and MSC232(82). To avoid any impact on theses documents, the EUWG decided to not modify the paragraphs concerned, including paragraph numbering. This is why the paragraph “3.4 ECDIS Manufacturers” of the former Edition is retained (with changes underlined) in the present Edition and the content of previous numbered paragraph amended to “Not currently used”. 

The Terminology used is explained in IHO publication S-32 “Hydrographic Dictionary” (http://hd.iho.int/en (for the English version) or http://hd.iho.int/fr (for the French version)). 

Reference: IHO Publication S-57 "IHO Transfer Standard for Digital Hydrographic Data" 

Note: The detailed process for updating ENCs is described in S-57 Appendix B.1 “ENC Product Specification”. In the following clauses, if there are conflicts between the requirements of S-52, Appendix 1 and the ENC Product Specification, the requirements of the ENC Product Specification shall be used. 

**2.** _Not currently used_ 

## **3. SPECIFIC UPDATING GUIDANCE** 

- **3.1** _Not currently used_ 

- **3.2** _Not currently used_ 

- **3.3** _Not currently used_

--- [page 6](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=6) ---

```
2
```

## **3.4** 

## **ECDIS Manufacturers** 

## 3.4.1 <u>General</u> 

- (a) **Data Integrity** . The ECDIS should be able to process ENC Updates without degradation of the information content of the ENC or ENC Update.  For example, all information regarding attributes, logical relationships, geometry, and topology must be accounted for. 

- (b) **Verification of Application** . The ECDIS should provide a method to ensure that updates have been correctly applied to the SENC. Those updates are either an Official ENC Update integrated into the SENC display or temporary information that was entered manually. 

- (c) **Integrated/Non-integrated Updates Distinction** . Updates should be clearly distinguishable on the display. Once accepted, integrated updates should be indistinguishable from ENC data. Non-integrated updates (i.e., those entered manually) shall be distinguishable as described in IHO S-52, section 2.3.4. 

- (d) **Storage Separation** . ECDIS should store all updates separately from the ENC. However, such separate storage may utilize the same data storage device. 

- (e) **Recall for Display.** It should be possible on demand to review previously installed updates. 

- (f) **Compatibility** . ENC Updates comply with the ENC Product Specification of IHO S-57. 

- (g) **Non-interference** . ECDIS should be able to receive updates without interfering with its current operation. 

- (h) **Log File** . ECDIS should keep a record of updates, including time of application and identification parameters described in <u>the Product Specification of S-57, through a logfile. The logfile should contain, for each</u> update applied to or rejected by the SENC, the following information: 

   - .1 date and time of application/rejection; 

   - .2 complete and unique identification of update as described in the S-57 Product Specification; 

   - .3 any anomalies encountered during application; 

   - .4 type of application: manual/automatic. 

- (i) **Update out of sequence** . The ECDIS should warn the user when an ENC Update is applied out of sequence, terminate the update operation and restore the SENC as it was before the application of the Update File. 

3.4.2 

## <u>Automatic Update</u> 

- (a) **Interface** 

   - (i) **Fully Automatic Updates.** The ECDIS should be capable of being interfaced to an appropriate telecommunication network.

--- [page 7](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=7) ---

```
3
```

- (ii) **Semi-automatic Updates.** The ECDIS should be capable of receiving ENC Updates in standard IHO format by CDROM and from any other <u>interface or data storage media that are provided with the ECDIS for that purpose and through telecommunication.</u> 

## (b) **Reception of ENC Updates** 

   - (i) ENC Update data shall be recorded automatically in the update storage of the ECDIS. 

   - (ii) The identification of the Issuing Authority of the ENC Update should be checked for conformance with the corresponding identifier of the ENC. 

   - (iii) If any errors are detected from the receiving device, the reception procedure shall be terminated and the ENC Update flagged invalid in the record of updates. The user should be informed of the corruption. 

- (c) **Sequence Check** . The following sequence number checks should be performed at the time of application, for sequential and cumulative updates: 

   - .1 File extension of the ENC Update 

   - .2 Update number of the ENC Update 

   - .3 Update sequence number of the individual records in the ENC Update 

Refer to the ENC Product Specification of S-57 for details on how the sequence numbers are encoded in the ENC Update. 

- (d) **Consistency Check** . The mariner should be warned of any previous ENC Updates which have not been successfully applied. 

- (e) **Geographic Applicability** . ENC Updates not relating to a cell within the set of ENCs in the ECDIS may be discarded. 

- (f) **Summary Report** . A summary report for each of the Issuing Authority's Official Update Files should be given after completion of receipt containing at least: 

   - .1 identification of Issuing Authority; 

   - .2 update numbers of the Update Files; 

   - .3 Cell Identifiers of cells affected; 

   - .4 Edition Number and date of cell involved; 

   - .5 number of updates in the affected cells. 

- (g) **Review of ENC Updates** . It should be possible for the mariner to review the updates applied through displaying the SENC contents with the updates highlighted.

--- [page 8](../../corpus/B/B1_S-52_Appendix1_Ed4.0.0.pdf#page=8) ---

```
4
```

   - (h) **Modification of Updates** . Rejection or amendment of an update by the mariner shall be achieved by the manual update method. The questionable update should be noted as an anomaly in the Log File [See 3.4.1 (h)]. 

   - (i) **Formatted Non-integrated Updates** , for example a temporary military exercise area, will be processed as manual updates. 

- 3.4.3 

## <u>Manual Update</u> 

- (a) **Keying and Symbology** . The ECDIS should enable manual entry of updates for non-integrated presentation on the display.  A capacity should exist to enable the mariner to: 

   - .1 enter the update so it can be displayed as described in S-52. 

   - .2 ensure all update text information relevant to the new condition and to the source of the update, as entered by the mariner, is recorded by the system for display on demand. 

- (b) **Indications and Alarms** . The ECDIS should be capable of sensing indications and alarms related to non-integrated (manual) updates, just as it does for integrated ENC Updates. 

- (c) **Presentation** . Manual updates shall be displayed as described in S-52, section 2.3.4. 

- (d) **Text** . It should be possible to enter text into the ECDIS. 

- (e) **Archiving of Manual Updates** . It should be possible to remove from the display any manual update. The removed update should be retained in the ECDIS for future review until commencement of the next voyage, but will not be otherwise displayed.
