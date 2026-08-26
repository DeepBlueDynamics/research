controlled: no

distribution: A

# Multiple PVA Sources

The PVA message (`measurement_position_velocity_attitude.yaml`) is very versatile; a sensor or subsystem may report an combination of the following:
- 1-d position
- 2-d position
- 3-d position
- 1-d velocity
- 2-d velocity
- 3-d velocity
- 3-d attitude

Additionally, the covariance matrix under zero-mean, additive, white Gaussian noise (AWGN) assumptions must be provided.

Finally, an optional error model may be used for error models other than zero-mean, additive, white Gaussian noise (AWGN) assumptions.

## PVAs from a subsystem

Often times the result of a subsystem is a subset or complete set of the PVA information.  The subsystem shall report the covariance of the measurement, and optionally, provide another error model. Subsystem examples may include an inertial navigation system (IMU, baro, etc.) or a vision-aided navigation system (IMU, baro, camera).

## Special Case: INS

Typically, an INS will generate a PVA (measurement_position_velocity_attitude) message with various aiding techniques, such as
- vertical aiding using a barometer
- vertical aiding using a laser altimeter
- zero-velocity updates (ZUPT)
- vector velocity aiding

### Single PVA

An INS may send a PVA for any one of those cases aiding cases by first using `metadata_generic` to share metadata such as mounting information, where that metadata is tagged with a (`vendor_id`, `device_id`, `context_id`).  The INS then generates PVA measurements with the same corresponding (`vendor_id`, `device_id`, `context_id`) and reports the PVA measurement, its error covariance, and an error model that addresses the aiding type if desired.  For example, a INS with vertical aiding using a barometer will may provide an error model that describes a stochastic model particular to that aiding case.

### Multiple PVAs

Now consider a more advanced case where a single INS sends multiple PVA messages with differing aiding techniques.  The INS itself is identified by the `vendor_id` and `device_id`.  The `context_id` is used to identify each measurement stream.  (Note: in the previous example with a single PVA being produced, we just used the (`vendor_id`, `device_id`, `context_id`)).

In the multiple PVA case, we can use a unique  `context_id` for each PVA measurement stream.  For example, consider an INS that generates a PVA solution which uses vertical channel aiding from a barometer _and_ a PVA solution which uses baro aiding and zero-velocity updates.  To convey this, generate a `metadata_generic` metadata message for (vendor_id, device_id, `context_id` = 0) for the baro aided PVA _and_ a `metadata_generic` metadata message for (vendor_id, device_id, `context_id` = 1) for the baro aided with ZUPT PVA.  The INS may then generate two PVA message streams.  The first message stream should use (`vendor_id`, `device_id`, `context_id` = 0) and provide an error model consistent with baro aiding.  The second message stream should use (`vendor_id`, `device_id`, `context_id` = 1) and provide an error model consistent with a baro aiding with ZUPT.
