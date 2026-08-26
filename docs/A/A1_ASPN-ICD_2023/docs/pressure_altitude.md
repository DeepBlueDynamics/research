controlled: no

distribution: A

# Pressure Altitude

For pressure ($p$) given in millibars, pressure altitude ($h$) in meters MSL can be calculated using the equation
$$
h = 444307.69396 \times{} [1 − (\frac{p}{1013.25})^{0.190284}]
$$
Go [here](https://www.weather.gov/media/epz/wxcalc/pressureConversion.pdf) to see how to convert pressure to millibars.

Likewise, for pressure altitude ($h$) in meters MSL, pressure ($p$) in millibars can be calculated using the equation
$$
p = 1013.25 \times{} (1 − \frac{h}{444307.69396})^{5.255303}
$$

### References
From https://www.weather.gov/media/epz/wxcalc/pressureAltitude.pdf