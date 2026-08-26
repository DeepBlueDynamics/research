#pragma once

#include <pntos/aspn.h>
#include <pntos/plugins/common.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * Forward declaration. See api/include/pntos/plugins/fusion.h
 */
struct PntosStandardFusionEngine;

typedef struct PntosCommonStateModelProvider {
	PntosManagedMemory* memory;

	/**
	 * The type of fusion model used by this state model provider
	 */
	PntosFusionType engine_type;
} PntosCommonStateModelProvider;

struct PntosStandardDynamicsModel;

/**
 * Function pointer for standard dynamics model callback function
 */
typedef PntosMatrix* (*PntosStandardDynamicsModelCallback)(struct PntosStandardDynamicsModel* self,
                                                           PntosMatrix* x);

/**
 * A container for the description of a non-linear system's dynamics model.
 */
typedef struct PntosStandardDynamicsModel {
	PntosManagedMemory* memory;

	/**
	 * Jacobian of #g.
	 * (i.e. \f$ \Phi \f$ in the linearized equation \f$ x_k = \Phi x_{k-1} \f$)
	 */
	PntosMatrix* Phi;

	/**
	 * Discrete-time process noise covariance matrix.
	 */
	PntosMatrix* Qd;

	/**
	 * The non-linear discrete-time state-transition function. (i.e. \f$ g(x) \f$ in \f$ x_k =
	 * g(x_{k-1}) + w_k \f$). Accepts the state vector and returns the propagated state vector.
	 */
	PntosStandardDynamicsModelCallback g;
} PntosStandardDynamicsModel;

struct PntosStandardMeasurementModel;

/**
 * Function pointer for standard measurement model callback function
 */
typedef PntosMatrix* (*PntosStandardMeasurementModelCallback)(
    struct PntosStandardMeasurementModel* self, PntosMatrix* x);

/**
 * A measurement model suitable for use in a PntosStandardFusionEngine.
 */
typedef struct PntosStandardMeasurementModel {
	PntosManagedMemory* memory;

	/**
	 * The vector of measurements/observations.
	 */
	PntosMatrix* z;

	/**
	 * The measurement prediction function. (i.e. \f$h(x)\f$ in \f$z=h(x)+v\f$). Accepts the state
	 * vector \p x and returns the expected measurement vector.
	 */
	PntosStandardMeasurementModelCallback h;

	/**
	 * The Jacobian of #h.
	 */
	PntosMatrix* H;

	/**
	 * The measurement noise covariance matrix.
	 */
	PntosMatrix* R;
} PntosStandardMeasurementModel;


/**
 * Container for callback function PntosGenXandP.generate which will calculate estimate and
 * covariance for the provided `block_labels`.
 */
typedef struct PntosGenXandP {
	PntosManagedMemory* memory;

	/**
	 * Returns the estimate and covariance associated with the states of \p block_labels within a
	 * particular measurement processor or state block. This is used to lazily evaluate estimate and
	 * covariance.
	 *
	 * @param self This instance.
	 * @param block_labels Labels for state blocks to generate estimate and covariance for.
	 * @param num_block_labels The number of strings in \p block_labels.
	 *
	 * @return Estimate and covariance of the provided block_labels. Returns NULL if any label in \p
	 * block_labels does not correspond to a valid block (labels can be validated using
	 * PntosStandardFusionEngine.has_block).
	 */
	PntosEstimateWithCovariance* PNTOS_NULLABLE (*generate)(struct PntosGenXandP* self,
	                                                        char** block_labels,
	                                                        size_t num_block_labels);
} PntosGenXandP;

/**
 * A description of a set of state estimates, associated covariances, and the states' dynamics.
 */
typedef struct PntosStandardStateBlock {
	PntosManagedMemory* memory;

	/**
	 * The unique name for this state block.
	 */
	char* label;
	/**
	 * The number of states represented by this state block.
	 */
	size_t num_states;

	/**
	 * Receive and use an arbitrary collection of aux data. This method will be called by the fusion
	 * engine when its PntosStandardFusionEngine.give_state_block_aux_data is called with a label
	 * corresponding to this state blocks' #label.
	 */
	void (*receive_aux_data)(struct PntosStandardStateBlock* self, PntosMessageArray* aux);

	/**
	 * @return A complete description of how to propagate this state block forward in time. For
	 * simple models, this can simply return a set of static matrices that are pre-defined. Returns
	 * NULL if \p gen_x_and_p_func is invalid (for example, it returns NULL when given a valid array
	 * of state block labels). Will return NULL if \p time_from is later than \p time_to. Otherwise
	 * guaranteed to not return NULL.
	 *
	 * @param gen_x_and_p_func A callback function that the state block can use to get the current
	 * estimate and covariance.
	 * @param time_from The time to propagate from.
	 * @param time_to The time to propagate to.
	 */
	PntosStandardDynamicsModel* PNTOS_NULLABLE (*generate_dynamics)(
	    struct PntosStandardStateBlock* self,
	    PntosGenXandP* gen_x_and_p_func,
	    AspnTypeTimestamp time_from,
	    AspnTypeTimestamp time_to);

	struct PntosStandardStateBlock* (*clone)(struct PntosStandardStateBlock* self);
} PntosStandardStateBlock;


/**
 * An object that processes raw measurements/observations into estimated states suitable for a
 * linear or linearized filter to use. Each type of measurement should correspond to a
 * PntosStandardMeasurementProcessor that is supplied to the fusion engine. Incoming measurements
 * received by the fusion engine will be routed to the corresponding measurement processor (by
 * label) and call PntosStandardMeasurementProcessor.generate_model to process the measurement. The
 * resulting PntosStandardMeasurementModel will be used by the fusion engine to call the underlying
 * PntosStandardFusionStrategy.update method to update the filter estimate/error covariance.
 */
typedef struct PntosStandardMeasurementProcessor {
	PntosManagedMemory* memory;

	/**
	 * A unique name for this measurement processor. This value will be used to select a measurement
	 * processor to handle new measurements that the strategy receives.
	 */
	char* label;

	/**
	 * A list of unique state block labels associated with measurements received by this processor.
	 * The estimate and covariance matrices passed into #generate_model will be composed of the
	 * states associated with these state blocks, and the returned PntosStandardMeasurementModel.h
	 * and PntosStandardMeasurementModel.H must respect these states.
	 *
	 * This field is an array of pointers to #num_state_block_labels `\0` terminated C strings,
	 * where `state_block_labels[i]` is the identifier for the `i`th state block this processor
	 * relates to.
	 */
	char** state_block_labels;

	/**
	 * Number of state block labels that are available in this measurement processor. This
	 * parameter describes the length of #state_block_labels.
	 */
	size_t num_state_block_labels;

	/**
	 * Receive and use an arbitrary collection of aux data. This method will be called by the fusion
	 * engine when its PntosStandardFusionEngine.give_measurement_processor_aux_data is called with
	 * a label corresponding to this measurement processor's #label.
	 */
	void (*receive_aux_data)(struct PntosStandardMeasurementProcessor* self,
	                         PntosMessageArray* aux);

	/**
	 * @return A PntosStandardMeasurementModel containing the parameters required for a filter
	 * update. Returns NULL when a measurement cannot be produced from \p message (for example, this
	 * could happen if the measurement type is unsupported by the measurement processor or if it is
	 * rejected due to residual monitoring).
	 */
	PntosStandardMeasurementModel* PNTOS_NULLABLE (*generate_model)(
	    struct PntosStandardMeasurementProcessor* self,
	    PntosMessage* message,
	    PntosGenXandP* gen_x_and_p_func);

	struct PntosStandardMeasurementProcessor* (*clone)(
	    struct PntosStandardMeasurementProcessor* self);
} PntosStandardMeasurementProcessor;

/**
 * An object that is used to convert a set of states from one representation to another, using a
 * mapping function `f()` to convert estimates, and the Jacobian of `f()` to map covariances (note
 * that this implies that the order/units of terms in the estimate vector and covariance matrix are
 * the same). Each instance is associated with two labels, 'source' and 'target', where source is
 * the label attached to the quantity to be transformed, and target is the label attached to the
 * result. Typically used with a PntosStandardFusionEngine where 'source' refers to a 'real'
 * PntosStandardStateBlock and 'target' referring to some representation that is advantageous for
 * some other element, such as a PntosStandardMeasurementProcessor, to use.
 */
typedef struct PntosVirtualStateBlock {
	PntosManagedMemory* memory;

	/**
	 * Receive and use an arbitrary collection of aux data. This method will be called by the fusion
	 * engine when its PntosStandardFusionEngine.give_virtual_state_block_aux_data is called with a
	 * label corresponding to this PntosVirtualStateBlock's #target.
	 */
	void (*receive_aux_data)(struct PntosVirtualStateBlock* self, PntosMessageArray* aux);

	/**
	 * Convert a full estimate/covariance pair.
	 *
	 * @param self This instance.
	 * @param estimate_with_covariance Estimate and covariance to convert.
	 * @param time Time that \p estimate_with_covariance is valid at.
	 *
	 * @return The converted value.
	 */
	PntosEstimateWithCovariance* (*convert)(struct PntosVirtualStateBlock* self,
	                                        PntosEstimateWithCovariance* estimate_with_covariance,
	                                        AspnTypeTimestamp time);

	/**
	 * Convert just an estimate vector.
	 *
	 * @param self This instance.
	 * @param estimate Estimate vector to convert, Nx1.
	 * @param time Time that \p estimate is valid at.
	 *
	 * @return The converted vector, Mx1.
	 */
	PntosMatrix* (*convert_estimate)(struct PntosVirtualStateBlock* self,
	                                 PntosMatrix* estimate,
	                                 AspnTypeTimestamp time);

	/**
	 * Obtain the Jacobian of the transform performed by this instance at an instance in time, given
	 * an estimate to differentiate with respect to.
	 *
	 * @param self This instance.
	 * @param estimate Estimate vector associated with the return value of #source, Nx1.
	 * @param time Time that \p estimate is valid at.
	 *
	 * @return An MxN matrix that may be used to pre-multiply \p estimate to obtain an M length
	 * vector in 'target' representation (to first order).
	 */
	PntosMatrix* (*jacobian)(struct PntosVirtualStateBlock* self,
	                         PntosMatrix* estimate,
	                         AspnTypeTimestamp time);

	/**
	 * The label associated with the representation this instance can transform *from*.
	 */
	char* source;

	/**
	 * The label associated with the representation this instance can transform *to*.
	 */
	char* target;

	/**
	 * Produce a deep-copy this instance.
	 *
	 * @param self This instance.
	 */
	struct PntosVirtualStateBlock* (*clone)(struct PntosVirtualStateBlock* self);
} PntosVirtualStateBlock;

/**
 * A collection of tools for modeling the propagation and innovation of state spaces using pntOS'
 * standard fusion model. Specifically, a PntosStandardStateModelProvider provides three types of
 * tools:
 *
 * 1. State Blocks - Define a set of states and a model for propagating those states
 * 2. Virtual State Blocks - Relate two statespaces to each other
 * 3. Measurement Processors - Relate measurements to a statespace
 *
 * A PntosStandardStateModelProvider conceptually models a set of zero or more
 * `PntosStandardStateBlock`s and a set of zero or more `PntosStandardMeasurementProcessor`s which
 * together model the phenomenology of sensor data that is being brought into a fusion engine. The
 * first type, state blocks, describe how a set of states propagates forward through time. The
 * second type, measurement processors, describe how a measurement relates to a set of state blocks.
 *
 * Each PntosStandardStateModelProvider consists of factory methods which generate instances of the
 * state blocks and measurement processors it provides. The
 * PntosStandardStateModelProvider.new_block method is a factory method that returns a newly created
 * state block on each invocation. Because the PntosStandardStateModelProvider can provide more than
 * one kind of state block, the PntosStandardStateModelProvider.new_block method takes a
 * `block_index` parameter which allows the user to request which kind of state block is created by
 * the factory. The number of different kinds of state block this state model provider has is given
 * by `num_blocks`. `block_identifiers[i]` gives a description of the `i`th kind of state block
 * returned when `block_index=i`.
 *
 * Similarly, PntosStandardStateModelProvider.new_processor is a factory method for returning new
 * measurement processors, `num_processors` is the number of different kinds of measurement
 * processors available in this state model provider, and `processor_identifiers` is a set of
 * identifiers for each available kind of measurement processor that can be returned by the factory.
 */
typedef struct PntosStandardStateModelProvider {
	PntosCommonStateModelProvider common;

	/**
	 * The number of different kinds of measurement processors that this
	 * PntosStandardStateModelProvider can create. This field describes the length of
	 * #processor_identifiers as well as the set of valid values for the `processor_index` parameter
	 * to #new_processor.
	 */
	size_t num_processors;

	/**
	 * A list of identifying strings for each kind of measurement processor that this
	 * PntosStandardStateModelProvider can create instances of.
	 *
	 * The field is a #num_processors sized array of pointers to `\0` terminated C strings. The
	 * `processor_index` parameter of #new_processor is an index into this array.
	 *
	 * This field will be null when this state model provider does not provide any measurement
	 * processors.
	 */
	char** PNTOS_NULLABLE processor_identifiers;

	/**
	 * @return A newly created PntosStandardMeasurementProcessor, which describes the relationship
	 * between a measurement and a set of state blocks. Returns null when no measurement processor
	 * can be produced with the given \p processor_index, \p engine, and \p config_group.
	 *
	 * @param processor_index Since the PntosStandardStateModelProvider can create #num_processors
	 * different kinds of measurement processors, the \p processor_index parameter is used to select
	 * which kind of measurement processor to create a new instance of. The #processor_identifiers
	 * field contains identifying strings for the kinds of processors. For example, if the model can
	 * create 45 different processors, the identifier of the last processor that can be created is
	 * found in `processor_identifiers[44]`. An instance of this processor can be created by calling
	 * `new_processor(self, 44, ...)`. Note that `0 <= processor_index < num_processors`.
	 *
	 * @param engine is an optional parameter that may be provided to the new processor, such that
	 * the processor may interact with the fusion engine it is being used in (for example, to
	 * add/remove states). Set it to null when no engine is available for the processor to use.
	 *
	 * @param label is a string which will be used to populate the `label` field of the newly
	 * created processor. This label will be the unique name for the returned instance of a
	 * processor, and used to track the processor throughout its lifecycle. Note that it differs
	 * from `processor_identifiers` which is the model's mechanism for selecting the kind of
	 * processor to create.
	 *
	 * @param state_block_labels is a \p num_state_block_labels sized array of pointers to `\0`
	 * terminated C strings which will be used to populate the `state_block_labels` field of the
	 * newly created processor.
	 *
	 * @param num_state_block_labels The length of \p state_block_labels.
	 *
	 * @param config_group Indicates which (if any) parameter group in the registry may be used to
	 * obtain additional configuration values to generate the new processor. If the processor
	 * requires no outside configuration, \p config_group may be null.
	 */
	PntosStandardMeasurementProcessor* PNTOS_NULLABLE (*new_processor)(
	    struct PntosStandardStateModelProvider* self,
	    size_t processor_index,
	    struct PntosStandardFusionEngine* PNTOS_NULLABLE engine,
	    char* label,
	    char** state_block_labels,
	    size_t num_state_block_labels,
	    char* PNTOS_NULLABLE config_group);

	/**
	 * The number of different kinds of state blocks that this PntosStandardStateModelProvider can
	 * create. This field describes the length of #block_identifiers as well as the set of valid
	 * values for the `block_index` parameter to #new_block.
	 */
	size_t num_blocks;

	/**
	 * A list of identifying strings for each kind of state block that this
	 * PntosStandardStateModelProvider can create instances of.
	 *
	 * The field is a #num_blocks sized array of pointers to `\0` terminated C strings. The
	 * `block_index` parameter of #new_block is an index into this array.
	 *
	 * This field will be null when this state model provider does not provide any state blocks.
	 */
	char** PNTOS_NULLABLE block_identifiers;

	/**
	 * @return a newly created PntosStandardStateBlock, which describes a set of states and how they
	 * propagate over time. The return value will be null when no state block can be produced with
	 * the given \p block_index, \p engine, and \p config_group.
	 *
	 * @param block_index Since the PntosStandardStateModelProvider can create #num_blocks different
	 * kinds of state blocks, the \p block_index parameter is used to select which kind of state
	 * block to create a new instance of. The #block_identifiers field contains identifying strings
	 * for the kinds of state blocks. For example, if the model can create 45 different state
	 * blocks, the identifier of the last state block that can be created is found in
	 * `block_identifiers[44]`. An instance of this state block can be created by calling
	 * `new_block(self, 44, ...)`. Note that `0 <= block_index < num_blocks`.
	 *
	 * @param engine An optional parameter that may be provided to the new block, such that the
	 * block may interact with the fusion engine it is being used in (for example, to add/remove
	 * states). Set it to null when no engine is available for the block to use.
	 *
	 * @param label A string which will be used to populate the `label` field of the newly
	 * created state block. This label will be the unique name for the returned instance of a state
	 * block, and used to track the state block throughout its lifecycle. Note that it differs from
	 * `block_identifiers` which is the model's mechanism for selecting the kind of state block to
	 * create.
	 *
	 * @param config_group Indicates which (if any) parameter group in the registry may be used to
	 * obtain additional configuration values to generate the new state block. If the state block
	 * requires no outside configuration, \p config_group may be null.
	 */
	PntosStandardStateBlock* PNTOS_NULLABLE (*new_block)(
	    struct PntosStandardStateModelProvider* self,
	    size_t block_index,
	    struct PntosStandardFusionEngine* PNTOS_NULLABLE engine,
	    char* label,
	    char* PNTOS_NULLABLE config_group);

	/**
	 * The number of different kinds of virtual state blocks that this
	 * PntosStandardStateModelProvider can create. This field describes the length of
	 * #virtual_block_identifiers as well as the set of valid values for the `virtual_block_index`
	 * parameter to #new_virtual_block.
	 */
	size_t num_virtual_blocks;

	/**
	 * A list of identifying strings for each kind of virtual state block that this
	 * PntosStandardStateModelProvider can create instances of.
	 *
	 * The field is a #num_virtual_blocks sized array of pointers to `\0` terminated C strings. The
	 * `virtual_block_index` parameter of #new_virtual_block is an index into this array.
	 *
	 * This field will be null when this state model provider does not provide any virtual state
	 * blocks.
	 */
	char** PNTOS_NULLABLE virtual_block_identifiers;

	/**
	 * @return A newly created PntosVirtualStateBlock, which is used to convert a set of states from
	 * one representation to another. Returns null when no virtual state block can be produced with
	 * the given \p virtual_block_index and \p config_group.
	 *
	 * @param virtual_block_index Since the PntosStandardStateModelProvider can create
	 * #num_virtual_blocks different kinds of virtual state blocks, the \p virtual_block_index
	 * parameter is used to select which kind of virtual state block to create a new instance of.
	 * The #virtual_block_identifiers field contains identifying strings for the kinds of virtual
	 * state blocks. For example, if the model can create 45 different virtual state blocks, the
	 * identifier of the last virtual state block that can be created is found in
	 * `virtual_block_identifiers[44]`. An instance of this virtual state block can be created by
	 * calling `new_virtual_block(self, 44, ...)`. Note that `0 <= virtual_block_index <
	 * num_virtual_blocks`.
	 *
	 * @param source_label The label of the state block or virtual state block whose states this
	 * virtual state block transforms.
	 *
	 * @param target_label A unique identifier for this virtual state block.
	 *
	 * @param config_group Indicates which (if any) parameter group in the registry may be used to
	 * obtain additional configuration values to generate the new virtual state block. If the
	 * virtual state block requires no outside configuration, \p config_group may be null.
	 */
	PntosVirtualStateBlock* PNTOS_NULLABLE (*new_virtual_block)(
	    struct PntosStandardStateModelProvider* self,
	    size_t virtual_block_index,
	    char* source_label,
	    char* target_label,
	    char* PNTOS_NULLABLE config_group);
} PntosStandardStateModelProvider;

/**
 * A PntosCommonPlugin subclass that provides a collection of `PntosStandardMeasurementProcessor`s,
 * `PntosStandardStateBlock`s, and `PntosVirtualStateBlock`s that can be used for sensor fusion.
 */
typedef struct PntosStateModelingPlugin {
	PntosCommonPlugin common;

	/**
	 * Return if the plugin supports a given type of fusion. See #PntosFusionType.
	 */
	bool (*is_fusion_type_supported)(struct PntosStateModelingPlugin* self, PntosFusionType type);

	/**
	 * @return An instance of PntosCommonStateModelProvider. Returns NULL if \p type is not
	 * supported
	 * (#is_fusion_type_supported can be used to check \p type).
	 * @param type Specifies the type of fusion that the returned value will support. For example,
	 * if the user passes in #PNTOS_FUSION_STANDARD_MODEL, then the returned value will be castable
	 * to PntosStandardStateModelProvider.
	 */
	PntosCommonStateModelProvider* PNTOS_NULLABLE (*new_state_model_provider)(
	    struct PntosStateModelingPlugin* self, PntosFusionType type);
} PntosStateModelingPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
