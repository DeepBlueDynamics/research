Virtual State Blocks
====================

:class:`Virtual State Block <PntosVirtualStateBlock>`\ s (VSBs) are a kind of
alias for :class:`State Block <PntosStandardStateBlock>`\ s (SBs). They convert
between the :class:`State Block <PntosStandardStateBlock>`'s internal state
representation and another. The most common types of conversions are:

#. Conversions between reference frames
#. Conversions between error states and whole states

VSBs might just be used to get the filter solution in the desired form. They're
often used to bridge the gap between the states a :class:`Measurement Processor
<PntosStandardMeasurementProcessor>` wants to update and what a :class:`State
Block <PntosStandardStateBlock>` actually provides.

VSBs are great for proof of concept and systems where performance has some
wiggle room. It is almost always more performant to write sets of SBs and MPs
that work directly together, though.
