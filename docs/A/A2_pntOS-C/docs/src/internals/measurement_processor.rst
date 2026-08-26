Measurement Processors
======================

Given a sensor measurement, :class:`Measurement Processor
<PntosStandardMeasurementProcessor>`\ s (MPs) provide the :class:`Fusion plugin
<PntosFusionPlugin>` with a model to update the states. Given a set of
observations :math:`\mathbf{z}` which contain information about the state
estimates, :math:`\mathbf{x}`, the :class:`Measurement Processor
<PntosStandardMeasurementProcessor>` produces the model which relate the two.
Let :math:`\mathbf{x}_k` be the `Mx1` vector representing the value of
:math:`\mathbf{x}` at time :math:`t_k` and :math:`\mathbf{z}_k` be the `Nx1`
set of observations collected at :math:`t_k`. Then the :class:`Fusion plugin
<PntosFusionPlugin>` assumes that the observations are related to the state
vector :math:`\mathbf{x}` by

.. math::

    \mathbf{z}_{k}\mathbf{=h}(\mathbf{x}_{k})\mathbf{+v}_{k},\ \ \
    \mathbf{v}_{k}\overset{\mathrm{iid}}{\sim}N(0,\sigma_{v})

where :math:`\mathbf{h}` is the *measurement model function*, and
:math:`\mathbf{v}` is a white Gaussian noise source. In the special case of a
linear model, :math:`\mathbf{h}(\mathbf{x})` can be written
:math:`\mathbf{h}(\mathbf{x})=\mathbf{Hx}`, where :math:`\mathbf{H}` is the
Jacobian matrix and :math:`\mathbf{h}(\mathbf{x})`, respectively. The
discrete-time measurement noise covariance matrix is defined as
:math:`\mathbf{R}=E[\mathbf{v}_{k}\mathbf{v}_{k}^T]`.

When a :class:`Fusion plugin <PntosFusionPlugin>` wants to update a set of
states with a measurement, it queries the :class:`Measurement Processor
<PntosStandardMeasurementProcessor>` associated with that update for the update
model which contains three things: :math:`\mathbf{h}(\mathbf{x})`,
:math:`\mathbf{H}`, and :math:`\mathbf{R}`.
