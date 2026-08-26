controlled: no

distribution: A

# Table of Contents

[TOC]

# Notation
Unless otherwise specified (explicitly or by context), the following notation conventions are used in this documentation:
- Scalar: Italic, normally lower case.  Examples: $x$, $\phi$
- Vector: Bold, lower-case, non-italic for alpha-numeric symbols.  Examples: $\mathbf{x}$, $\pmb{\phi}$
- Matrix - Bold, upper-case letters and symbols, non-italic.  Examples: $\mathbf{A}$, $\mathbf{P}$, $\mathbf{\Phi}$
- Estimated Value: Caret (hat) above the variable.  Examples: $\hat{x}$ (scalar), $\hat{\mathbf{x}}$ (vector)
- Coordinate Frames: Used to explicitly show which coordinate frame is used.  Represented by non-italic superscript or subscript.  Examples: $\mathbf{f}^\mathrm{ECEF}$, $\mathbf{r}^\mathrm{NED}$
- Coordinate Frame Conversion: Coordinate frame being converted from as subscript non-italic font and the coordinate frame being converted to as superscript non-italic font.  Examples: $\mathbf{C}_\mathrm{N}^\mathrm{ENU}$ is a DCM that describes a rotation which transforms a vector from the $\mathrm{N}$ frame to the $\mathrm{ENU}$ frame, $\mathbf{q}_\mathrm{ECEF}^\mathrm{NED}$ is a quaternion that describes a rotation which transforms a vector from the $\mathrm{ECEF}$ frame to the $\mathrm{NED}$ frame.

# Units
ASPN uses the [International System of Units (SI)](https://www.nist.gov/pml/weights-and-measures/metric-si/si-units).  If there is a significant, compelling reason to do otherwise, it will be clearly annotated in the documentation.

# Coordinate Frames
This section describes the coordinate frames used in the ASPN ICD and the relationships between them.  Many of the frame definitions and notation are consistent with those presented in [Savage2007], but some changes have been made to accommodate a broader application space than the INS-focused work of Savage.

## Standard Coordinate Frames
These are the coordinate frames that are used throughout ASPN ICD.  Note that they are not all Cartesian frames.

* **Earth-Centered, Inertial (ECi) Frame** -  Earth-centric, inertial frame defined using the Conventional Geocentric Celestial Reference System (GCRS), an Earth-centered inertial system based on epoch J2000.0, as specified in Appendix A of the [WGS-84 Specification](https://earth-info.nga.mil/coordsys/coord-download.php?file=website/NGA.STND.0036_1.0.0_WGS84.pdf).  Briefly summarized here, *earth-centered, inertial* means the frame origin is not accelerating (or its acceleration is negligible) and is located at an agreed upon earth center, and the frame axes are non-rotating with respect to the fixed stars.  Generally, the $$Z$$ axis is aligned normal to the mean equator, or approximately the Earth's spin axis orientation, at an epoch specified in the standard, the $$X$$ axis is aligned along the intersection of the equatorial and ecliptic planes, and the $$Y$$ axis completes a right-handed coordinate system.
* **Earth-Centered, Earth-Fixed (ECEF) Frame** - ECEF frame defined in the [WGS-84 Specification](https://earth-info.nga.mil/coordsys/coord-download.php?file=website/NGA.STND.0036_1.0.0_WGS84.pdf).  Briefly summarized here, the origin is at an agreed upon earth center, $$Z$$ axis is aligned with the north polar axis, the $$Y$$ axis in the earth equatorial plane, and the $$X$$ axis is in the Greenwich meridian plane.  This is a global coordinate frame.
* **North-East-Down (NED) Frame** - Locally level geographic coordinate frame defined with its $$Z$$ axis downward along the local geodetic vertical, $$X$$ axis north (and horizontal), and $$Y$$ axis east (and horizontal). Note that north and east are undefined at the poles, so the NED frame is undefined at the poles.  The term *locally level* means that the attitude of this frame is dependent on the position of the origin of the frame.  The north and east axes directions are defined to be "locally level" with respect to the WGS-84 ellipsoid at the origin location (meaning that they are parallel to the surface of the ellipsoid).  Sometimes a locally level frame is fixed to a single spot on the earth, and in other cases the origin of a locally level frame may be fixed to a vehicle or sensor (such as an INS) which is in motion relative to the earth.  In that case, as the origin moves, the frame definition rotates in order to continually maintain the local level characteristics.
* **Platform Frame (P Frame)** The platform frame is a coordinate frame that is defined relative to the body of the vehicle, system, or person in which measurements are being taking and solutions are being generated.  This frame is system specific, but the preferred frame definition for ASPN is with the axes aligned in the forward, right, and down directions.  An example of a platform frame would be a coordinate frame with the origin at the center of gravity of an aircraft, with the $$X$$, $$Y$$, and $$Z$$ axes corresponding to the nose, right wing, and down through the belly directions, respectively.  Note that the platform frame is defined according to the need of any particular system, and in some cases, the platform frame will be identical to the inertial sensor frame.  However, in the general case, the P frame is not required to be aligned with any particular sensor.  Note that what we define as the platform frame has been referred to by some as a "body frame".  We have intentionally avoided the use of the term "body", because body can be ambiguous.  Some communities use body frame to refer to a platform frame, and other communities use body frame to refer to an IMU sensor frame.
* **Sensor Frame (S Frame)** The sensor coordinate frame represents the coordinate frame native to any particular sensor. For example, IMU gyroscope and accelerometer measurements would be expressed in the IMU sensor frame.  Likewise, a radar Doppler sensor would have its own sensor frame.  (Note that in [Savage2007], this frame is referred to as the B frame.)  Within ASPN, each S frame (for each sensor) origin and axes are defined relative to the P frame through the `mounting` information.
## Other Standard Coordinate Frames
These frames are not currently used in the ASPN ICD, but these definitions are useful to relate the common frames used in ASPN with common frames not used in ASPN.
* **East-North-Up (ENU) Frame** - Locally level geographic coordinate frame defined with its $$Z$$ axis upward along the local geodetic vertical, $$Y$$ axis north (and horizontal), and $$X$$ axis east (and horizontal). Note that north and east are undefined at the poles, so the ENU frame is undefined at the poles.  (Note: the ENU frame is called the "Geo" frame in [Savage2007].)  See the definition for the NED frame for a definition of a "locally level" frame.
* **N Frame** - Navigation coordinate frame having its $$Z$$ axis parallel to the upward vertical at the local earth surface referenced position. The $$X$$ and $$Y$$ axes of the N frame are in the local level plane and are related to the ENU frame by the wander angle $\alpha$, as described below.  See the definition for the NED frame for a definition of a "locally level" frame.  Note: This frame is consistent with the N frame as defined in [Savage2007].
* **E Frame** - Earth fixed coordinate frame, with $$Y$$ axis along north polar axis, the $$X$$ axis in the earth equatorial plane, and the $$Z$$ axis in the Greenwich meridian plane.

  *Note:* The E frame axes are aligned with standard WGS-84 ECEF frame axes, but with the axes swapped: $X^\text{E} = Y^\text{ECEF}$ , $Y^\text{E} = Z^\text{ECEF}$, and $Z^\text{E} = X^\text{ECEF}$. Also note that the E frame is defined such that the E frame axes are aligned with the ENU frame axes when latitude and longitude are both 0 deg.

  *Note:* This frame is consistent with the E frame as defined in [Savage2007].

* **L Frame** - Local level coordinate frame parallel to the N frame but with $$Z$$ axis parallel to the downward vertical, and $$X$$, $$Y$$ axes along N frame $$Y$$, $$X$$ axes, respectively. This frame is used as the reference for describing the strapdown sensor coordinate frame orientation.  See the definition for the NED frame for a definition of a "locally level" frame.

  *Note:* This frame is consistent with the L frame as defined in [Savage2007].

* **I Frame** - Non-rotating, generic inertial coordinate frame used as a reference for angular rotation measurements.

## Coordinate Frame Orientation Relationships
This section describes some of the key orientation relationships between the coordinate frames given in the previous section. These relationships will be expressed by direction cosine matrices to aide the user in understanding the various frames and their relationship with each other.  These DCMs are not used in the ASPN messaging, and depending on the application, some of these transformations may not be necessary.  (See [Attitude Expressed as Direction Cosine Matrices](#attitude-expressed-as-direction-cosine-matrices) for a description of notation and characteristics of direction cosine matrices).

The relationship between the four local-level coordinate frames (NED, ENU, N, L) and $\alpha$ is shown below.

<center><img src="./figures/WanderAngleDefinitionAll.svg" width="400px" /></center>
*Relationship between local-level coordinate frames and wander angle $\alpha$*

The ECEF and E frames are related to each other by swapping axes as the direction cosine matrix (DCM)
$$
\textbf{C}_\text{ECEF}^\text{E} =
\begin{bmatrix}
0 & 1 & 0\\
0 & 0 & 1\\
1 & 0 & 0
\end{bmatrix}
\label{eqn:ecef2e}
$$
Likewise, the N frame and L frame are related by another swapping of axes
$$
\textbf{C}_\text{N}^\text{L} = \textbf{C}_\text{L}^\text{N} =
\begin{bmatrix}
0 & 1 & 0\\
1 & 0 & 0\\
0 & 0 & -1
\end{bmatrix}
\label{eqn:n2l}
$$
as are the ENU and NED frames:
$$
\textbf{C}_\text{ENU}^\text{NED} = \textbf{C}_\text{NED}^\text{ENU} =
\begin{bmatrix}
0 & 1 & 0\\
1 & 0 & 0\\
0 & 0 & -1
\end{bmatrix}
\label{eqn:enu2ned}
$$
The NED frame is related to the N frame through the wander angle $\alpha$ according to

$$
\textbf{C}_\text{NED}^\text{N} =
\begin{bmatrix}
-\sin \alpha  & \cos \alpha & 0 \\
\cos \alpha & \sin \alpha  & 0 \\
0 & 0 & -1
\end{bmatrix}
\label{eqn:ned2n}
$$
Next, the direction cosine matrix $C_\text{N}^\text{E}$ which describes the rotation between the N frame and the E frame. This matrix is a function of latitude $l$, longitude $L$, and wander angle $\alpha$ (see Equation 4.4.2.1-2 in [Savage2007]):
$$
\textbf{C}_\text{N}^\text{E} = \begin{bmatrix}
c_{11} & c_{12} & c_{13} \\
c_{21} & c_{22} & c_{23} \\
c_{31} & c_{32} & c_{33}
\end{bmatrix}
\label{eqn:n2e}
$$
where
$$
\begin{aligned}
c_{11} &= \cos L \cos \alpha - \sin L \sin l \sin \alpha \\
c_{12} &= -\cos L \sin\alpha -\sin L \sin l \cos \alpha \\
c_{13} &= \sin L \cos l \\
\\
c_{21} &= \cos l \sin \alpha \\
c_{22} &= \cos l \cos \alpha \\
c_{23} &= \sin l \\
\\
c_{31} &= -\sin L \cos \alpha - \cos L \sin l \sin \alpha \\
c_{32} &= \sin L \sin \alpha - \cos L \sin l \cos \alpha \\
c_{33} &= \cos L \cos l
\end{aligned}
\label{eqn:n2e_expanded}
$$
All of the orientation relationships between the NED, ENU, ECEF, N, L, and E frames can be determined by a combination of the $\textbf{C}_\text{ENU}^\text{NED}$ , $\textbf{C}_\text{ECEF}^\text{E}$, $\textbf{C}_\text{N}^\text{L}$, $\textbf{C}_\text{NED}^\text{N}$, and $\textbf{C}_\text{N}^\text{E}$ matrices, using the rules of DCM operations described in [Attitude Expressed as Direction Cosine Matrices](#attitude-expressed-as-direction-cosine-matrices).  Some of these additional relationships include

$$
\textbf{C}_\text{E}^\text{NED} = \begin{bmatrix}
-\sin L \sin l & \cos l  & - \cos L \sin l \\
\cos L   &  0  & -\sin L \\
-\sin L \cos l  &  -\sin l  & -\cos L \cos l
\end{bmatrix}
\label{eqn:e2ned}
$$

$$
\textbf{C}_\text{ECEF}^\text{NED} = \begin{bmatrix}
- \cos L \sin l & -\sin L \sin l & \cos l \\
-\sin L & \cos L & 0    \\
-\cos L \cos l& -\sin L \cos l & -\sin l
\end{bmatrix}
\label{eqn:ecef2ned}
$$

Finally, Appendix A of the [WGS-84 Specification](https://earth-info.nga.mil/coordsys/coord-download.php?file=website/NGA.STND.0036_1.0.0_WGS84.pdf) provides a complete description in transforming between the $ECi$ and $ECEF$ frames.

# Position Representations
This section describes how position can be described in a global reference frame.
## Position Expressed as $\textbf{llh}$
This is the standard way to describe coordinates using latitude ($l$, in some references referred to as $\phi$), longitude ($L$, in some references referred to as $\lambda$), and height ($h$). These are all defined relative to the WGS-84 ellipsoid, so $h$ is height above the ellipsoid, and $l$ is geodetic latitude. Sometimes the three values will be given in vector form as
$$
\textbf{llh} \triangleq
\begin{bmatrix}
l \\
L \\
h
\end{bmatrix}
\label{eqn:lladef}
$$
Unless otherwise stated, units are radians (for $l$ and $L$) and meters (for $h$).

## Position Expressed as $\textbf{p}^\textrm{ECEF}$
ECEF coordinates describe position in the Cartesian ECEF frame. This is normally expressed in vector form as
$$
\textbf{p}^\text{ECEF} \triangleq
\begin{bmatrix}
p_x^\textrm{ECEF} \\
p_y^\textrm{ECEF} \\
p_z^\text{ECEF}
\end{bmatrix}
\label{eqn:pecef}
$$
Unless otherwise stated, units are in meters.

## Position Expressed as $\textbf{C}_\text{N}^\text{E}$, $h$
Another way to express position is through a combination of the ellipsoidal height $h$ and the $\textbf{C}_\text{N}^\text{E}$ matrix. The values for latitude $l$, longitude $L$, and wander angle $\alpha$ can be extracted from $\textbf{C}_\text{N}^\text{E}$ according to
$$
\begin{aligned}
l &= \tan^{-1}\begin{pmatrix}
\dfrac{c_{23}}{\sqrt{c_{21}^2+c_{22}^2}}
\end{pmatrix} \\
L &= \tan^{-1}\begin{pmatrix}
\dfrac{c_{13}}{c_{33}}
\end{pmatrix} \\
\alpha &= \tan^{-1}\begin{pmatrix}
\dfrac{c_{21}}{c_{22}}
\end{pmatrix}
\end{aligned}
\label{eqn:llapha}
$$
where $c_{ab}$ is the 1-indexed $(a,b)$ element of $\textbf{C}_\text{N}^\text{E}$.  The $\textbf{C}_\text{N}^\text{E}$ matrix is often used to represent position rather than $l$ and $L$, because $l$ and $L$ are singular over the north and south poles, but $\textbf{C}_\text{N}^\text{E}$ is not. Velocity integration into position involves simply applying a rotation to the $\textbf{C}_\text{N}^\text{E}$ matrix, which works over the poles, avoiding any singularity.

## Position Expressed as $\textbf{p}^\text{E}$
This is the same as $\textbf{p}^\text{ECEF}$, except the vector is expressed in the E frame rather than the ECEF frame. Position expressed as $\textbf{p}^\text{E}$ is normally related to inertial processing, and is not generally used as a generic way to express position, since the more standard $\textbf{p}^\text{ECEF}$ is to be preferred for this purpose. It is normally expressed in vector form as
$$
\textbf{p}^\text{E} \triangleq
\begin{bmatrix}
p_x^\text{E} \\
p_y^\text{E} \\
p_z^\text{E}
\end{bmatrix}
\label{eqn:pe}
$$
Unless otherwise stated, units are in meters. The relationship between $\textbf{p}^\text{E}$ and $\textbf{p}^\text{ECEF}$ is
$$
\textbf{p}^\text{E} = \textbf{C}_\text{ECEF}^\text{E} \textbf{p}^\text{ECEF}=
\begin{bmatrix}
0 & 1 & 0 \\
0 & 0 & 1 \\
1 & 0 & 0
\end{bmatrix}
\begin{bmatrix}
p_x^\text{ECEF} \\
p_y^\text{ECEF} \\
p_z^\text{ECEF}
\end{bmatrix}
\label{eqn:pe_ecef}
$$
# Velocity Representations
This section describes how velocity can be described in a global reference frame.

## Velocity Expressed as $\textbf{v}^\text{ECEF}$
One way to describe velocity is the time rate of change of $\textbf{p}^\text{ECEF}$:
$$
\textbf{v}^\text{ECEF} = \frac{d}{dt}\textbf{p}^\text{ECEF} \equiv \dot{\textbf{p}}^\text{ECEF}
$$
This is normally expressed as a vector with three components
$$
\textbf{v}^\text{ECEF}=
\begin{bmatrix}
v_x^{\text{ECEF}} \\
v_y^{\text{ECEF}} \\
v_z^{\text{ECEF}}
\end{bmatrix}
\label{eqn:vecef}
$$
Unless otherwise stated, units are in meters/second.

## Velocity Expressed as $\textbf{v}^\text{E}$
Velocity can also be expressed as the time rate of change of $\textbf{p}^\text{E}$:
$$
\textbf{v}^\text{E} = \frac{d}{dt}\textbf{p}^\text{E} \equiv \dot{\textbf{p}}^\text{E}
$$
This is normally expressed as a vector with three components
$$
\textbf{v}^\text{E}=
\begin{bmatrix}
v_x^{\text{E}} \\
v_y^{\text{E}} \\
v_z^{\text{E}}
\end{bmatrix}
\label{eqn:ve}
$$
It is related to $\textbf{v}^\text{ECEF}$ according to
$$
\textbf{v}^\text{E} = \textbf{C}_\text{ECEF}^\text{E} \textbf{v}^\text{ECEF}
$$
Unless otherwise stated, units are in meters/second.

## Velocity Expressed as $\textbf{v}^\text{NED}$
Another more intuitive way to express velocity is in the NED frame.  This is normally expressed as a vector with three components
$$
\textbf{v}^\text{NED}=
\begin{bmatrix}
v_x^{\text{NED}} \\
v_y^{\text{NED}} \\
v_z^{\text{NED}}
\end{bmatrix}
\label{eqn:vned}
$$
This is related to $\textbf{v}^\text{ECEF}$ according to $\textbf{v}^\text{NED} = \textbf{C}_\text{ECEF}^\text{NED}\textbf{v}^\text{ECEF}$.  The $\textbf{C}_\text{ECEF}^\text{NED}$ direction cosine matrix was described in [Coordinate Frame Orientation Relationships](#coordinate-frame-orientation-relationships).  Unless otherwise stated, units are in meters/second.

# Attitude Representations
Attitude refers to the relative orientation between two coordinate frames. If one of the frames is a geographically-referenced frame (such as ECEF), we sometimes refer to attitude as "absolute attitude", although fundamentally, it's still just relating two different coordinate frames.

There are several common ways to express relative orientation between two frames. In this section we will describe five of them:

1. Rotation vector
2. Angle-axis
3. Direction cosine matrix
4. Attitude quaternion
5. Euler angles

There are tradeoffs between each of these, but in general, computation is most readily done using either direction cosine matrices or quaternions. Euler angles are useful for human conceptualization/visualization, but they are highly nonlinear and have singularities, making them less desirable for computational purposes. Rotation vectors and angle-axis representations are also good for visualization and are useful when relating to rotation sensors (like gyros) which fundamentally output a rotation vector (or rotation rate vector).

This section summarizes the basics of working with attitude. Refer to Chapter 3 in [Savage2007] for a much more thorough coverage of these topics.

## Attitude Expressed as Rotation Vectors
A good description of rotation vectors is given in Section 3.2.2 of [Savage2007], so we will just quote that here:

> Another way of describing the attitude of an arbitrary coordinate frame B relative to another arbitrary coordinate frame A is through the \"rotation vector\" concept. The \"rotation vector\" defines an axis of rotation and magnitude for a rotation about the rotation vector (using the standard right hand convention for rotation about a vector). Imagine frame A being rotated from its starting attitude to a new attitude by rotation about the \"rotation vector\" through an angle equal to the rotation vector magnitude. Now call frame B the new attitude of frame A. By this definition of frame B, an arbitrarily defined rotation vector uniquely defines the attitude of frame B  relative to the original frame A attitude. Conversely, for a given frame B attitude, relative to frame A, a rotation vector can be defined that is consistent with this attitude. Thus a rotation vector can be used to define the attitude of frame B relative to frame A.
>

We will denote a three dimensional rotation vector as
$$
\pmb{\phi} =\begin{bmatrix}
\phi_x \\
\phi_y \\
\phi_z
\end{bmatrix}
$$
It is interesting to note that a *rotation vector* that rotates frame A to become frame B is identical when expressed in either frame A or frame B.  That is, $\pmb{\phi} = \pmb{\phi}^\text{A} = \pmb{\phi}^\text{B}$, where $\pmb{\phi}^\text{A}$ is the rotation vector expressed in frame A and $\pmb{\phi}^\text{B}$ is the rotation vector expressed in frame B.  Because they are identical, there is no need to specify the frame.  Unless otherwise specified, $\pmb{\phi}$ will be expressed in units of radians.

The figure below shows a simple example of two different Cartesian coordinate frames that are related by rotation vector, $\pmb{\phi}$,  defined as
$$
\pmb{\phi} =  \begin{bmatrix}
0 \\
0 \\
\beta
\end{bmatrix}
$$
<center><img src="./figures/FrameRotation.svg" width="400px" /></center>
*Frame Rotation Example ($\pmb{\phi} = [0,0,\beta]^T$)*

Note that $\pmb{\phi}$ vector describes a coordinate frame rotation.  This is related to, but is not the same as the rotation that is required to transform a vector expressed in frame A to that same vector expressed in frame B.  A more detailed discussion of this difference can be found in [Appendix: Coordinate Frame Rotations vs. Vector Rotations](#appendix-coordinate-frame-rotations-vs-vector-rotations).


## Attitude Expressed in Axis-Angle Form
Rather than express the rotation vector as a scaled vector as described in the previous section, it is often useful to express it in axis-angle form.  Starting with a rotation vector $\pmb{\phi}$  we can define
$$
\begin{aligned}
\pmb{\phi} &= \phi \textbf{u}_{\phi} \\
\phi &= \sqrt{\pmb{\phi} \cdot \pmb{\phi}} \\
\phi  \text{ } \textbf{u}_{\phi} &= \pmb{\phi}/{\phi}
\end{aligned}
$$
where
$$
\begin{aligned}
\phi &= \text{magnitude of the rotation vector} \\
\textbf{u}_{\phi} &= \text{unit vector in the rotation vector direction}
\end{aligned}
$$
A rotation vector as described above would be expressed in axis-angle form as
$$
\left( \textbf{u}_\phi, \phi \right)
$$
Note that the unit vector is undefined when $\phi=0$.  Unless otherwise specified, $\phi$ will be expressed in radians.  (The vector $\textbf{u}_\phi$ is unitless.)

Using the previous example, the rotation vector
$$
\pmb{\phi} =  \begin{bmatrix}
0 \\
0 \\
\beta
\end{bmatrix}
\label{eqn:phi_example2}
$$
expressed in axis-angle form would be
$$
\left(
\begin{bmatrix}
0 \\
0 \\
1
\end{bmatrix}, \beta \right)
\label{eqn:angle_axis}
$$
## Attitude Expressed as Direction Cosine Matrices
A direction cosine matrix (DCM) is a 3$\times$3 matrix that describes a rotation between two frames.  By way of notation, a DCM that rotates an arbitrary vector $\textbf{w}$ expressed in frame X ($\textbf{w}^\text{X}$) to the same vector expressed in frame Y ($\textbf{w}^\text{Y}$) is expressed as $\textbf{C}_\text{X}^\text{Y}$:
$$
\textbf{w}^\text{Y} = \textbf{C}_\text{X}^\text{Y}\textbf{w}^\text{X}
$$
Direction cosine matrices are *orthonormal* matrices and have the characteristics
$$
\begin{aligned}
\textbf{C}_\text{Y}^\text{X} &= (\textbf{C}_\text{X}^\text{Y})^T = (\textbf{C}_\text{X}^\text{Y})^{-1} \\
\textbf{C}_Z^\text{X} &= \textbf{C}_\text{Y}^\text{X}\textbf{C}_Z^\text{Y} \\
\end{aligned}
$$
As a downside, a direction cosine matrix has redundant information with 9 elements, but it is convenient for rotating vectors between different frames using a matrix multiplication operation.  Additionally, the direction cosine matrix relating frame A to frame B, which is the same as saying the rotation from frame B to frame A, can be expressed in terms of the rotation vector $\pmb{\phi}$ as
$$
\textbf{C}_\text{B}^\text{A} = I+\frac{\sin\phi}{\phi}\left(\pmb{\phi}\times \right)
+\frac{(1-\cos \phi)}{\phi^2}\left(\pmb{\phi}\times \right)\left(\pmb{\phi}\times \right)
\label{eqn:rotvec2dcm}
$$
where$\left(\pmb{\phi}\times \right)$ is the cross product operator made up of the components of $\pmb{\phi}$:
$$
\left(\pmb{\phi}\times \right)=\begin{bmatrix}
0 & -\phi_z & \phi_y \\
\phi_z & 0 & -\phi_x \\
-\phi_y & \phi_x & 0
\end{bmatrix}
\label{eqn:phi_cross}
$$
Note that the DCM $\textbf{C}_\text{B}^\text{A}$ describes the vector rotation to transform a vector from frame B to frame A as
$$
\textbf{w}^\text{A} = \textbf{C}_\text{B}^\text{A} \textbf{w}^\text{B}
\label{eqn:rotb_to_a}
$$
## Attitude Expressed as Quaternions
In general, quaternions are represented in the form $$a+b\textbf{i}+c\textbf{j}+d\textbf{k}$$ where $a$, $b$, $c$, and $d$ are real numbers and $\textbf{i}$, $\textbf{j}$, and $\textbf{k}$ are quaternion units.  An attitude quaternion is a specially defined quaternion that has unit length and which expresses a rotation defined by rotation vector $\pmb{\phi}$.  The components of the attitude quaternion are
$$
\textbf{q} = \begin{bmatrix}
a \\ b \\ c \\ d
\end{bmatrix}
\label{eqn:quat_def}
$$
where
$$
a=\cos\frac{\phi}{2} \qquad
b = \frac{\phi_x}{\phi}\sin \frac{\phi}{2} \qquad
c = \frac{\phi_y}{\phi}\sin \frac{\phi}{2}  \qquad
d = \frac{\phi_z}{\phi}\sin \frac{\phi}{2}
\label{eqn:abcd_def}
$$
where $\phi_x$, $\phi_y$, and $\phi_z$ are the components of $\pmb{\phi}$.  It should be noted that sometimes a quaternion is represented as
$$
\textbf{q}_{alt} = \begin{bmatrix}
b \\ c \\ d \\ a
\end{bmatrix}
\label{eqn:qalt}
$$
(In other words, the ordering of the cosine and sine terms are switched.)  This is an arbitrary convention, and the ASPN ICD has chosen to represent quaternions consistently using the $\textbf{q} = [\begin{matrix} a & b & c & d ]\end{matrix}^T$ convention.  t is helpful to define some quaternion operations.  If $\textbf{q}$ is defined as above, then the quaternion conjugate $\textbf{q}^*$ is
$$
\textbf{q}^* = \begin{bmatrix}
a \\ -b \\ -c \\ -d
\end{bmatrix}
\label{eqn:qalt_mat}
$$
If there are two attitude quaternions describing rotation between frames B and A, $\textbf{q}_\text{B}^\text{A}$, and rotations between frames C and B, $\textbf{q}_\text{C}^\text{B}$, quaternion multiplication can be used to calculate the attitude quaternion from C to A.  For example, given
$$
\textbf{q}_\text{B}^\text{A} = \begin{bmatrix}
a \\ b \\ c \\ d
\end{bmatrix}
\qquad
\textbf{q}_C^\text{B} = \begin{bmatrix}
e \\ f \\ g \\ h
\end{bmatrix}
\label{eqn:qmult2}
$$
Then the attitude quaternion describing rotation from frame C to B to A, or from frame C to A, $\textbf{q}_\text{C}^\text{A}$, is given by
$$
\begin{aligned}
\textbf{q}_C^\text{A} &= \textbf{q}_\text{B}^\text{A}\textbf{q}_C^\text{B} \\
&= \begin{bmatrix}
ae-bf-cg-dh \\
be+af-dg+ch \\
ce+df+ag-bh \\
de-cf+bg+ah
\end{bmatrix}   \\
&=\begin{bmatrix}
a & -b & -c & -d \\
b & a & -d & c \\
c & d & a & -b \\
d & -c & b & a
\end{bmatrix}
\begin{bmatrix}
e \\ f \\ g \\ h
\end{bmatrix}
\end{aligned}
\label{eqn:qmult_details}
$$
The direction of the quaternion rotation can be reversed by taking the quaternion conjugate:
$$
\textbf{q}_\text{A}^\text{B} =
\begin{pmatrix}
{\textbf{q}_\text{B}^\text{A}}
\end{pmatrix}^*
\label{eqn:qconj}
$$
Additionally, note that for small rotation angle magnitudes, elements $b$-$d$ of the quaternion are approximately $\frac{1}{2}$ of the rotation vector.  Finally, the direction cosine matrix $\textbf{C}_\text{B}^\text{A}$ corresponding to the $\textbf{q}_\text{B}^\text{A}$ quaternion as described above is [Savage2007]
$$
\textbf{C}_\text{B}^\text{A} = \begin{bmatrix}
(a^2+b^2-c^2-d^2) & 2(bc-ad) & 2(bd+ac) \\
2(bc+ad) & (a^2-b^2+c^2-d^2) & 2(cd-ab) \\
2(bd-ac) & 2(cd+ab) & (a^2-b^2-c^2+d^2)
\end{bmatrix}
\label{eqn:q_to_dcm}
$$
## Attitude Expressed as Euler Angles
Euler angles represent relative orientation between two coordinate frames by a sequence of three rotations about individual axes.  After the first rotation, the second and third rotations operate on *rotated* coordinate frames, which makes Euler angle approaches very nonlinear.  Additionally, at particular attitudes Euler angles have a singularity which makes the Euler angles become undefined.  As a result, Euler angles are almost never used as a way to computationally maintain or propagate knowledge of attitude.  However, Euler angles are perhaps the most "human understandable" attitude parameters, so they are often used as a way to express attitude or to take in attitude inputs by human interaction.

The most common Euler angle sequence from frame A to frame B is a $3-2-1$ frame rotation by angles $\psi$ (heading or yaw), $\theta$ (pitch), and $\phi$ (roll).  In other words, starting with frame A, we perform a frame rotation as follows:
1. Rotate frame A about third axis of frame A by value of yaw ($\psi$) to yield intermediate frame 1
2. Rotate intermediate frame 1 about its second axis by value of pitch ($\theta$) to yield intermediate frame 2
3. Rotate intermediate frame 2 about its first axis by value of roll ($\phi$) to yield frame B

This is called a $3-2-1$ rotation to go from frame A to frame B, because that is the order in which each of the axes are rotated (rotation about 3rd, then 2nd, then first axis).  The direction cosine matrix that describes the relationship from frame A to B is given by
$$
\textbf{C}_\text{A}^\text{B} = \begin{bmatrix}
c_{11} & c_{12} & c_{13} \\
c_{21} & c_{22} & c_{23} \\
c_{31} & c_{32} & c_{33}
\end{bmatrix}
\label{eqn:cba_terms}
$$
where
$$
\begin{aligned}
c_{11} &= \cos\theta\cos\Psi \\
c_{12} &= -\cos\phi\sin\Psi + \sin\phi\sin\theta\cos\Psi \\
c_{13} &= \sin\phi\sin\Psi + \cos\phi\sin\theta\cos\Psi \\
\\
c_{21} &= \cos\theta\sin\Psi \\
c_{22} &= \cos\phi\cos\Psi + \sin\phi\sin\theta\sin\Psi \\
c_{23} &= -\sin\phi\cos\Psi + \cos\phi\sin\theta\sin\Psi \\
\\
c_{31} &= -\sin\theta \\
c_{32} &=  \sin\phi\cos\theta \\
c_{33} &= \cos\phi\cos\theta \\
\end{aligned}
\label{eqn:cba_details}
$$
Note that the description above described a *frame rotation* from frame A to frame B, but this is the same as performing a *vector rotation* to rotate a vector from frame B to frame A .  See Appendix [Coordinate Frame Rotations vs. Vector Rotations](#appendix-coordinate-frame-rotations-vs-Vector-rotations) for a more detailed explanation.

A common use for Euler angles is to describe the orientation of a vehicle (such as an aircraft) or the orientation of inertial sensors relative to the NED frame.  If the aircraft frame (what we would call a  platform frame, or P frame) is defined as $+X$ through the nose, $+Y$ through the right wing, and $+Z$ down, then an aircraft flying straight an level to the north will have all zeroes for the Euler angles, and non-zero Euler angle values for an aircraft at any other attitude.  This is the situation in which we normally picture the concepts of *roll*, *pitch*, and *yaw*.

It is possible to define an Euler angle sequence between frames which are not aligned when a vehicle or sensor is in a nominal orientation (such as straight and level flying north).  An example of such a case would be to define the orientation of an aircraft platform frame (as defined above) relative to an ENU frame.  However, in this case a "zero-rotation" situation (all Euler angles zero) is one in which the aircraft is flying upside-down to the east, which is *not* what is mentally pictured by "zero rotation".  As a result, we generally reserve the use of Euler angles to describe the orientation of a vehicle or sensor, expressed in a "nose-right wing-down" like coordinate frame, relative to the NED frame.

## Conversion Between Angle Representations

Coming soon... The ASPN team is adding (at the next revision of this document) the equations needed to convert Euler to quaternion, quaternion to Euler, DCM to quaternion, and quaternion to DCM.

## Representation of Attitude Error

Attitude as expressed in this document has three degrees of freedom, so it is ideal to express attitude error as a three-dimensional quantity.  Sometimes, attitude error is expressed as (roll error, pitch error, heading/yaw error).  However, there are two significant reasons that we are not using this approach:

1. *Euler angles are highly nonlinear and have singularities.*  Because the Euler angles roll, pitch, and yaw represent a sequence of rotations, the errors in roll, pitch, and yaw are highly nonlinear, with interdependence between the three values, especially as the pitch approaches +/- 90 degrees, where there is a singularity, where only two of the three Euler angles have meaning.  As a result, it is very difficult to represent errors in attitude in the general case using just Euler angle errors without significant care and complication.
2. *Meaning can be ambiguous.*  Sometimes, what is referred to as roll error, pitch error, and heading/yaw error are actually the rotation angle corrections to be applied about the body axes, which in some cases are described as the roll axis, pitch axis, and heading/yaw axis.  As such, they would be a rotation vector expressed in the roll axis/pitch axis/yaw or heading axis coordinate frame.  However, those values are definitely _NOT_ the same thing as the error in the roll angle, pitch angle, and yaw/heading Euler angles--in other words, using this "rotation about the roll/pitch/yaw axes" definition, roll error is not the error in the roll angle, pitch error is not the error in the pitch angle, and heading/yaw error is not the error in the heading/yaw angle.  However, some could naively look at a value called "roll error", and assume that if they have a roll angle, they can just add (or subtract) the roll error to get a corrected roll angle, but this actually is incorrect.  We want to avoid this confusion.

Consider an estimated or measured attitude represented by a quaternion $\textbf{q}_\text{B}^\text{A}$ which expresses the vector rotation from frame $\text{B}$ to frame $\text{A}$, as described above.  However, this attitude is not perfectly known, so it is not exactly the same as the _true_ quaternion with no errors, which can be represented as $\textbf{q}_\text{B}^{\text{A}_\text{true}}$.  We can then calculate the difference between the estimated/measured attitude and the true attitude  as

$$
\textbf{q}_\text{A}^{\text{A}_\text{true}} = \textbf{q}_\text{B}^{\text{A}_\text{true}}
\begin{pmatrix}
{\textbf{q}_\text{B}^\text{A}}
\end{pmatrix}^* = \textbf{q}_\text{B}^{\text{A}_\text{true}} \textbf{q}_\text{A}^\text{B}
$$

Now, this quaternion $\textbf{q}_\text{A}^{\text{A}_\text{true}}$ represents the correction to be applied to the original attitude quaternion in order to convert it to the true (error-free) quaternion:

$$
\textbf{q}_\text{B}^{\text{A}_\text{true}} = \textbf{q}_\text{A}^{\text{A}_\text{true}} \textbf{q}_\text{B}^\text{A}
$$

This $\textbf{q}_\text{A}^{\text{A}_\text{true}}$ quaternion could be represented as a rotation vector instead of a quaternion using the relationship between a rotation vector and a quaternion described above.  This rotation vector is sometimes referred to as the "tilt error" vector which represents the attitude error in the $\textbf{q}_\text{B}^\text{A}$ quaternion.  In ASPN, the uncertainty of this tilt error is sometimes represented as a jointly Gaussian error using a covariance matrix.

Note that in the example above, the "tilt error" is applied in the $\text{A}$ frame.  By way of example, if the attitude of a sensor relative to the NED frame is expressed as $\textbf{q}_\text{sensor}^\text{NED}$, then the tilt errors would be expressed in the $\text{NED}$ frame.  There is a different representation of the tilt error which could actually be expressed in the $\text{B}$ frame (or in the example, the sensor frame).


# Direction 2D to Point (Scalar Angle) Reference Enum Definitions

This section describes several scalar angle definitions between two points, a sensor and a remote
point. Three coordinate frames are of interest when defining the angles: the sensor's coordinate
frame (defined in its mounting metadata), a local-level NED frame whose origin is located at the
sensor, and a local-level NED frame whose origin is located at the remote point. These frames are
depicted below.

<center><img src="./figures/AngleCoordinateFrames.png" width="400px" /></center>

In each of the definitions below, the depictions of the different angle definitions will all utilize
this same geometry.

## NE_TO

Angle between the sensor's local level N-axis and the vector from the sensor to the point projected
onto the sensor's local level North-East plane. Positive angle is defined as a rotation towards the
E-axis.

<center><img src="./figures/AngleNeToDefinition.png" width="400px" /></center>

## NE_FROM

Angle between the point's local level N-axis and the vector from the point to the sensor projected
onto the point's local level North-East plane. Positive angle is defined as a rotation towards the
E-axis.

The significant difference between NE_TO and NE_FROM is where the NED frame originates (NE_FROM has
its origin located at the point's location).

<center><img src="./figures/AngleNeFromDefinition.png" width="400px" /></center>

## ELEVATION

Angle between the sensor's local level North-East plane and the vector from the sensor to the point.
Positive angle is defined as a rotation towards the negative D-axis of the NED frame.

<center><img src="./figures/AngleElevationDefinition.png" width="400px" /></center>

## SENSOR

Angle between the sensor's x-axis and the vector from the sensor to the point projected onto the
sensor frame x-y plane. Positive angle is defined as a rotation towards the y-axis.

<center><img src="./figures/AngleSensorDefinition.png" width="400px" /></center>

# References
[Savage2007] Savage, P.G. *Strapdown Analytics II, Part 1*. Strapdown Associates, Inc., 2007

# Appendix: Coordinate Frame Rotations vs. Vector Rotations
There can be significant confusion regarding attitude, and one common point of confusion is understanding the difference between rotating a coordinate frame and rotating a vector to transform between frames.  In the definition of rotation vectors given in the previous section, the rotation vector $\pmb{\phi}$ describes the rotation that would rotate a Cartesian coordinate frame A in order to turn it into coordinate frame B.  This can be thought of as rotating all of the orthogonal basis vectors (coordinate axes) from frame A by the rotation vector to get frame B.  From the example given in the in `Figure 2`, frame B is defined by rotating frame A by the rotation vector $\pmb{\phi} = [0,0,\beta]^T$. More specifically, the basis vectors for frame A are rotated by $\pmb{\phi}$ to get the basis vectors of frame B.  Therefore, the rotation vector defines the *frame rotation* to go from frame A to frame B.

When using different coordinate frames, we often want to take a vector expressed in one frame and transform it to be represented in a different frame.  Let's consider an example of a vector $\textbf{w}$ as shown below.

<center><img src="./figures/FrameRotationWithW.svg" width="600px" /></center>
*Frame Rotation Example ($\pmb{\phi} = [0,0,\beta]^T$)*

In this example, $\textbf{w}$ can be expressed in frame A as
$$
\textbf{w}^\text{A}=
\begin{bmatrix}
0 \\
1 \\
0 \\
\end{bmatrix}
\label{eqn:wa}
$$
The same vector, expressed in frame B, is
$$
\textbf{w}^\text{B}
=\begin{bmatrix}
\sin \beta \\
\cos \beta \\
1 \\
\end{bmatrix}
=\begin{bmatrix}
0.5 \\
0.866 \\
1 \\
\end{bmatrix}
\label{eqn:wb}
$$
The vector $\textbf{w}$ is rendered separately in frames A and B as
<center><img src="./figures/FrameABComparison.svg" width="700px" /></center>
*Vector $\textbf{w}$ expressed in Frames A and B*

In this case, the *frame rotation* is done by rotating the coordinate frame axes about the rotation vector $[0, 0, \beta]^T$ (which is how we originally defined the rotation vector in [Attitude Expressed as Rotation Vectors](#attitude-expressed-as-rotation-vectors).  However, if we start with the vector $\textbf{w}$ expressed in frame A ($\textbf{w}^\text{A}$), and want to transform it so that it is expressed in frame B ($\textbf{w}^\text{B}$), we actually have to rotate the vector in the *opposite* direction as the frame rotation--in this case, we rotate $\textbf{w}^\text{A}$ by the rotation vector $ [0, 0,-\beta]^T$ to obtain $\textbf{w}^\text{B}$.  We can also go in the opposite direction, starting with the vector $\textbf{w}^\text{B}$, and rotating it about the original vector which defines the frame rotation $[0, 0, \beta]^T$ in order to obtain $\textbf{w}^\text{A}$.

So, in effect, the same rotation vector $\pmb{\phi}$ defines the *frame rotation* from from frame A to frame B and the *vector rotation* to rotate from $\textbf{w}^\text{B}$ to $\textbf{w}^\text{A}$. In practice, these two ways of expressing attitude (as a frame rotation or a vector rotation) are equivalent--they are just a different ways of representing the same thing.

By convention, some ways of expression attitude tend to be expressed using frame rotations, and others tend to be expressed using vector rotations.  Here are the conventions used in this tutorial:
- **Rotation Vectors** - frame rotation from A to B
- **Angle-Axis** - frame rotation from A to B
- **Direction Cosine Matrices** - vector rotation from B to A
- **Quaternions** - both: defined using frame rotation from A to B, but often used to express vector rotations from B to A
- **Euler Angles** - define a frame rotation from A to B

All of the attitude representations expressed in this document are consistent with each other in terms of how they represent the two arbitrary frames A and B, even though they follow different (but fairly standard) conventions of how these transformations are described.