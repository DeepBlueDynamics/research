<!-- crawl_url: https://insidegnss.com/gnss-interference-complicates-navigation-as-hormuz-shipping-disruption-deepens/ -->
<!-- crawl_ts: 1787788296 -->
<!-- quality: sufficient -->
<!-- char_count: 6398 -->
<!-- word_count: 951 -->

[USS Mitscher (DDG 57), USNS Charles Drew (T-AKE 10), USNS Guadalupe (T-AO 300), and USS Mobile Bay (CG 53) transit the Strait of Hormuz. U.S. Navy photo by Mass Communication Specialist Seaman Apprentice Jarrod A. Schad)](https://insidegnss.com/wp-content/uploads/2026/03/4994892-1.jpg)Reports of widespread GNSS interference in the Gulf and Strait of Hormuz region are coinciding with a sharp disruption in commercial shipping, turning the area into a real-world test of how resilient maritime navigation and monitoring are when satellite positioning becomes unreliable.

Over the last several days, maritime analytics providers have documented interference events affecting more than 1,000 ships in the Middle East Gulf, alongside a growing pattern of AIS anomalies and “dark” operations. At the same time, tanker and container traffic has slowed or stopped near the Strait of Hormuz, and leading war-risk insurers are withdrawing cover for the region.

The episode illustrates in practical terms what a contested RF environment means for ships that still rely heavily on satellite-derived position for navigation, tracking and compliance.

### Interference profile: GPS jamming and AIS spoofing on a regional scale

Maritime intelligence firm Windward reports that more than 1,100 vessels experienced GPS and AIS interference across the Middle East Gulf within a single 24-hour period following the outbreak of hostilities between Iran, the United States and Israel. Ships’ reported positions were displaced onto airports, inland locations in Iran and the Gulf states, and even over a nuclear power plant, producing track histories that are clearly inconsistent with physical reality.

A parallel assessment reported by*Wired*, based on analysis of satellite navigation attacks since the start of the air campaign against Iran, arrives at a similar figure of roughly 1,100 ships affected, underscoring that interference is not limited to a small subset of vessels or a single narrow area.

Dryad Global notes “heightened risk of GPS jamming and AIS spoofing” in the Gulf of Oman and Strait of Hormuz, explicitly linking recent anomalies to Iranian naval exercises and electronic warfare activity.

Taken together, the data suggests:

- GNSS-derived position can become systematically biased over wide areas, not only momentarily lost.
- AIS tracks based on those positions may show vessels apparently transiting over land, clustered around inland targets, or moving in circular or jagged patterns that reflect repeated loss and reacquisition of signal.
- Some operators respond by switching AIS off altogether, which protects them from misinterpretation of spoofed positions but reduces visibility for collision-avoidance and traffic management.

From a PNT standpoint, this is a textbook case of how GNSS jamming and spoofing propagate through downstream systems that treat satellite position as authoritative.

### Shipping, insurance and security advisories

The interference is occurring against the backdrop of a broader shipping disruption centered on the Strait of Hormuz.

Reuters reports that around 150 ships, including oil and LNG tankers, are currently stranded near the Strait of Hormuz, with at least five tankers damaged and crew casualties following drone and missile attacks. In the wake of US and Israeli strikes, Iran has announced that it is closing the strait, and many market participants now characterize conditions as a “de facto” closure of a route that normally carries about one-fifth of global oil exports and substantial volumes of gas.

In response to the increased risk:

- Major war-risk underwriters, including Gard, Skuld, NorthStandard, the American Club and others, are cancelling war-risk cover for ships operating in Gulf and Iranian waters from early March, with premiums for any residual cover rising sharply.
- Container carriers such as Maersk and CMA CGM have begun rerouting or suspending services that would normally pass through Hormuz, adding to the reduction in commercial traffic through the area.

On the governmental side, a recent advisory from the US Maritime Administration designates the Strait of Hormuz, Persian Gulf, Gulf of Oman and parts of the Arabian Sea as an area of active military operations and potential retaliatory strikes by Iranian forces. The advisory highlights the risk of hailing, boarding or detention of commercial vessels and directs operators to closely monitor updates and guidance from US Naval Forces Central Command.

Although these notices are primarily focused on kinetic threats, several security circulars from P&I clubs and risk advisers now explicitly call out the likelihood of GPS interference and AIS anomalies in the region and recommend that ships treat GNSS-based position with caution when operating there.

### Implications for PNT resilience

The current pattern of events around Hormuz reinforces several points that have been discussed in standards bodies and industry forums for some time:

- GNSS reliability is not uniform. In certain strategic waterways, including parts of the Gulf and Strait of Hormuz, interference can reach a level where satellite-based positioning should be treated as advisory rather than authoritative.
- Spoofed or displaced positions can have regulatory and commercial consequences, not just navigational ones, when automated compliance systems interpret false AIS tracks as evidence of port calls or territorial incursions.
- “Going dark” on AIS reduces exposure to mis-located tracks but increases dependence on radar and visual watchkeeping, especially in confined waters.

For PNT system designers and policy-makers, the current situation underscores the value of alternative and complementary positioning sources, whether that means terrestrial systems, inertial aids, or hardened multi-constellation receivers, and the need to assume that in some regions, GNSS degradation will not be an exception but a recurring operating condition.

In that sense, the developments around Hormuz are less an isolated crisis than another data point in an evolving pattern: satellite navigation has become a routine instrument in regional competition, and maritime navigation practices are having to adjust accordingly.

### Related Posts:

- [Antenova Now Shipping its Ultra-Small GNSS Active…](https://insidegnss.com/antenova-now-shipping-its-ultra-small-gnss-active-antenna-module-radionova-m20047-1/)
- [NAL Research, SGM Technology AS, and Tschudi…](https://insidegnss.com/nal-research-sgm-technology-as-and-tschudi-shipping-company-partner-to-deliver-resilient-navigation-for-commercial-maritime-vessels/)
- [TrustPoint and NovAtel Demonstrate C-Band Navigation…](https://insidegnss.com/trustpoint-and-novatel-demonstrate-c-band-navigation-through-gnss-interference/)
- [IFEN: SX-NSR Receivers Shipping; Final GATE Certification](https://insidegnss.com/ifen-sx-nsr-receivers-shipping-final-gate-certification/)