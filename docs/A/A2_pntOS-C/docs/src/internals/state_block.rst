State Blocks
============

:class:`State Block <PntosStandardStateBlock>`\ s (SBs) provide the Fusion
plugin with states and the models to propagate those states.

:class:`State Block <PntosStandardStateBlock>`\ s provide a set of states,
:math:`\mathbf{x}`. Let :math:`\mathbf{x}_k` be the `Mx1` vector representing
the value of :math:`\mathbf{x}` at time :math:`t_k`. Then the :class:`Fusion
plugin <PntosFusionPlugin>` assumes that the way :math:`\mathbf{x}` changes
from one time epoch to the next is well-modeled by

.. math::

    \mathbf{x}_{k}=\mathbf{g}(\mathbf{x}_{k-1})\mathbf{+w}_{k},\ \ \
    \mathbf{w}_{k}\overset{\mathrm{iid}}{\sim}N(0,\sigma_{w})

where :math:`\mathbf{g}` is the *discrete-time propagation function*, and
:math:`\mathbf{w}` is white Gaussian noise sources.

In the special case of a linear model, :math:`\mathbf{g}(\mathbf{x})` can be
written :math:`\mathbf{g}(\mathbf{x})=\mathbf{\Phi x}`, where
:math:`\mathbf{\Phi}` is the Jacobian matrix of :math:`\mathbf{g}(\mathbf{x})`.
The discrete-time process noise covariance matrix is defined as
:math:`\mathbf{Q_d}=E[\mathbf{w}_{k}\mathbf{w}_{k}^T]`.

When a :class:`Fusion plugin <PntosFusionPlugin>` wants to propagate a set of
states from :math:`\mathbf{x}_{k-1}` to :math:`\mathbf{x}_{k}`, it queries the
:class:`State Block <PntosStandardStateBlock>` which provides those states for
the three elements of the dynamics model: :math:`\mathbf{g}(\mathbf{x})`,
:math:`\mathbf{\Phi}`, and :math:`\mathbf{Q_d}`.
