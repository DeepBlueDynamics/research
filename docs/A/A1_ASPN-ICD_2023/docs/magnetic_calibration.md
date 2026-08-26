controlled: no

distribution: A

# Magnetic Field Calibration

This document provides a very brief introduction to common magnetic field calibration parameters, so users have a clear understanding on how to provide magnetic field calibration parameters in the magnetic field metadata.

## Introduction
Magnetometer outputs suffer from magnetic field distortions and sensor errors, including the hard iron effect, soft iron effect, zero bias error, scale factor error, non-orthogonal error, misalignment error, and noise (See Gebre-Egziabher, D.; Elkaim, G.H.; Powell, J.D.; Parkinson, B.W. _A non-linear, two-step estimation algorithm for calibrating solid-state strapdown magnetometers_. In Proceedings of the 8th International Conference on Navigation Systems, St. Petersburg, Russia, 27–31 May 2001; pp. 200–299.)

The hysteresis errors, temperature-dependent errors, and time-varying errors are not be addressed in the magnetic field metadata. Calibration parameters that account for these effects should be included as an optional error model within the measurement message.

## Magnetic Field Distortions

 - Hard iron effect is a constant additional magnetic field produced by permanent magnets on the assembled platform.  It is represented as a 3 × 1 vector, denoted as `hard_iron`, and has the same units as the measurement. 
 - Soft iron effect is produced by the magnetization of soft magnets. It exerts effects on the magnitude and orientation of the magnetic field according to the external field orientation, which is represented as a 3 × 3 matrix, denoted as `C_soft_iron`. The i-row, j-column element in the matrix indicates the influence of the external j-direction field to the i-direction field.

## Sensor Errors

Includes zero bias error, scale factor error, non-orthogonal error, misalignment error, and noise.  These errors are mainly due to machining and installation defects. 
 - Zero bias error makes constant offsets to each axis of the magnetometer, which is represented as a 3 × 1 vector, denoted as `zero_bias`, and has the same units as the measurement (nT).
 - The scale factor error comes from the sensitivity inconsistencies of each sensor. It is represented as a 3 × 3 diagonal matrix, denoted as `Csf`. The elements on the diagonal represent the sensitivities of each axis sensor. 
 - The non-orthogonality between individual sensors introduces an inter-axis coupling output error, which is represented as a 3 × 3 upper triangular matrix, denoted as `Cno`. In general conditions of small angle errors, the diagonal elements of `Cno` are close to 1. 
 - The misalignment error represents the angular misalignment between the tri-axis magnetometer set and the assembled platform, which is represented as a 3 × 3 unit rotation matrix, denoted as `Cm`. It can be simplified into an anti-symmetric matrix, with diagonal elements equal to 1.

## Calibration Equation

The error model of the tri-axis magnetometer is given as (See Yang, Deng; You, Zheng; Li, Bin; Duan, Wenrui; Yuan, Binwen. _Complete Tri-Axis Magnetometer Calibration with a Gyro Auxiliary_, https://pubmed.ncbi.nlm.nih.gov/28587115/):

    m_measured = Cno * Csf * C_soft_iron * Cm * (m_calibrated + hard_iron) + zero_bias

or equivalently,

    m_calibrated = inv(Cno * Csf * C_soft_iron * Cm) * (m_measured - zero_bias) - hard_iron

This may be re-written in the form 

    m_calibrated = K * m_measured - b

by noting 

    K = inv(Cno * Csf * C_soft_iron * Cm)                      (3 x 3 matrix, unitless)
    
    b = inv(Cno * Csf * C_soft_iron * Cm) * zero_bias + hard_iron  (3 x 1 vector in nT)

## Summary

In summary, the terms K (3 x 3 matrix, unitless) and b (3 x 1 vector in nT) are used in the magnetic field metadata and should be used as 

    m_calibrated = K * m_measured - b

In general, for an num-meas dimensional measurement, the magnetic field calibration metadata (K and b) should be used as 

    m_calibrated = K * m_measured - b

where m_calibrated, m_measured, and b are num-meas x 1 vectors (scalar for num-meas = 1) and K is an num-meas x num-meas matrix (scalar for num-meas = 1).