#pragma once

#include <pntos/plugins/common.h>
#include <pntos/plugins/fusion_strategy.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A dynamic estimator exposing a state model provider consuming API capable of Bayesian inference
 * on non-linear discrete-time systems. The #PntosFusionType may be used to determine the type of
 * fusion that this struct supports, and thereby which implementation of fusion strategy this struct
 * is castable to.
 */
typedef struct PntosCommonFusionEngine {
	PntosManagedMemory* memory;

	/**
	 * The type of fusion model used by this engine
	 */
	PntosFusionType engine_type;

} PntosCommonFusionEngine;

/**
 * A container for a set of covariances relating a StateBlock to a set of other StateBlocks. Suppose
 * that some StateBlock named `A` existed. Then this structure could define the cross covariance of
 * `A` with respect to other StateBlocks named `B` and `C`. In that case, this struct would set
 * `num_covariances=2` (because it contains the cross covariance of `A` to two other state blocks),
 * `block_labels` would be an array of 2 strings `B` and `C`, and `cross_covariances` would be a
 * pointer to an array of two pointers to PntosMatrix instances: The cross-covariance matrix of `A`
 * and `B` and the cross-covariance matrix of `A` and `C`.
 */
typedef struct PntosCrossCovariances {
	PntosManagedMemory* memory;

	/**
	 * The number of cross-covariance matrices this structure contains. This field may be used as
	 * the length of both #block_labels and #cross_covariances.
	 */
	size_t num_covariances;

	/**
	 * A list of labels of the `PntosStandardStateBlock`s this structure contains the
	 * cross-covariances for.
	 */
	char** block_labels;

	/**
	 * A list of cross-covariance matrices between a single StateBlock and the set of StateBlocks
	 * listed in #block_labels.
	 */
	PntosMatrix** cross_covariances;
} PntosCrossCovariances;

/**
 * An implementation of a fusion engine that supports the standard fusion model.
 *
 * Assumes the system is described by discrete-time matrices and noise inputs are zero-mean white
 * Gaussian. In addition, all covariance matrices / mean vectors are descriptions of
 * jointly-Gaussian multivariate distributions. All noise sources are jointly-Gaussian distributed.
 *
 * This object requires a PntosStandardFusionStrategy to work. Some implementations may be able to
 * provide their own. Others will require a strategy to be provided via the
 * PntosStandardFusionEngine.set_strategy method. It is possible to check whether a fusion engine
 * needs to be provided a fusion strategy by calling the PntosStandardFusionEngine.get_strategy
 * method (if the return is NULL then this fusion engine needs to be provided a strategy). While
 * PntosStandardFusionEngine.get_strategy returns NULL, all other methods are unsafe to be called.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosStandardFusionEngine {
	PntosCommonFusionEngine common;

	/**
	 * Set the current time of the filter to the parameter.
	 */
	void (*set_time)(struct PntosStandardFusionEngine* self, AspnTypeTimestamp time);

	/**
	 * Get the current time of the filter
	 */
	AspnTypeTimestamp (*get_time)(struct PntosStandardFusionEngine* self);

	/**
	 * Set the underlying algorithm used for Bayesian inference - the type of filter (EKF, UKF,
	 * etc.)
	 */
	void (*set_strategy)(struct PntosStandardFusionEngine* self,
	                     PntosStandardFusionStrategy* strategy);

	/**
	 * @return The underlying algorithm used for Bayesian inference - the type of filter (EKF, UKF,
	 * etc.). Returns NULL if this fusion engine does not have a strategy. If that is the case, the
	 * fusion engine must be provided with a strategy via #set_strategy.
	 */
	PntosStandardFusionStrategy* PNTOS_NULLABLE (*get_strategy)(
	    struct PntosStandardFusionEngine* self);

	/**
	 * Get the total number of states currently in the fusion engine that are associated with
	 * `PntosStandardStateBlock`s.
	 */
	size_t (*get_num_states)(struct PntosStandardFusionEngine* self);

	/**
	 * Gets a list of the `PntosStandardStateBlock`s labels that have been added to this fusion
	 * engine. Returns NULL if no state blocks have been added. Guaranteed to not return NULL if
	 * #get_num_states returns a value other than 0.
	 */
	PntosStringArray* PNTOS_NULLABLE (*get_state_block_labels)(
	    struct PntosStandardFusionEngine* self);

	/**
	 * Returns true if the fusion engine has a `PntosStandardStateBlock` with a matching label.
	 */
	bool (*has_block)(struct PntosStandardFusionEngine* self, char* block_label);

	/**
	 * Add the given PntosStandardStateBlock to the fusion engine. This will expand the state vector
	 * being estimated by the value of `block->get_num_states()`. The \p initial_estimate_covariance
	 * parameter contains the initial conditions of the states, with
	 * `initial_estimate_covariance->estimate` being an Nx1 matrix and
	 * `initial_estimate_covariance->covariance` being an NxN matrix, where N is
	 * `block->get_num_states()`. The \p cross_covariances are an optional parameter which, if
	 * non-NULL, contains a description of the newly added StateBlock's cross covariances with
	 * respect to a set of StateBlocks which already exist inside the filter (specified by
	 * `cross_covariances->block_labels`). If the \p cross_covariance parameter is NULL, cross
	 * covariance between the existing states and the added states will be set to zeroes.
	 */
	void (*add_state_block)(struct PntosStandardFusionEngine* self,
	                        PntosStandardStateBlock* block,
	                        PntosEstimateWithCovariance* initial_estimate_covariance,
	                        PntosCrossCovariances* PNTOS_NULLABLE cross_covariances);

	/**
	 * Find a `PntosStandardStateBlock` or `PntosVirtualStateBlock` within the fusion engine
	 * matching \p block_label, and return a copy of its current estimate vector. If \p block_label
	 * references a virtual state block (VSB) this will return a converted estimate, converted into
	 * the VSBs coordinate frame. Returns NULL if \p block_label does not correspond to a block that
	 * has been added to the fusion engine. Guaranteed to not return NULL when #has_block returns
	 * true for \p block_label and #get_strategy does not return NULL.
	 */
	PntosMatrix* PNTOS_NULLABLE (*get_state_block_estimate)(struct PntosStandardFusionEngine* self,
	                                                        char* block_label);

	/**
	 * Find a `PntosStandardStateBlock` or `PntosVirtualStateBlock` within the fusion engine
	 * matching \p block_label, and return a copy of its current covariance matrix. If \p
	 * block_label references a virtual state block (VSB) this will return a converted covariance,
	 * converted into the VSBs coordinate frame. Returns NULL if \p block_label does not correspond
	 * to a block that has been added to the fusion engine. Guaranteed to not return NULL when
	 * #has_block returns true for \p block_label and #get_strategy does not return NULL.
	 */
	PntosMatrix* PNTOS_NULLABLE (*get_state_block_covariance)(
	    struct PntosStandardFusionEngine* self, char* block_label);

	/**
	 * Find the `PntosStandardStateBlocks` within the fusion engine matching \p block_label1 and \p
	 * block_label2, and return the cross-covariance matrix between them. Returns NULL if \p
	 * block_label1 or \p block_label2 do not correspond to blocks that gave been added to the
	 * fusion engine. Guaranteed to not return NULL when #has_block returns true for both \p
	 * block_label and \p block_label2 and #get_strategy does not return NULL.
	 */
	PntosMatrix* PNTOS_NULLABLE (*get_state_block_cross_covariance)(
	    struct PntosStandardFusionEngine* self, char* block_label1, char* block_label2);

	/**
	 * Find a `PntosStandardStateBlock` within the fusion engine matching \p block_label, and change
	 * its current estimate vector. Note that this function may lead to performance degradation with
	 * some implementations and thus its use is discouraged if other options are available.
	 */
	void (*set_state_block_estimate)(struct PntosStandardFusionEngine* self,
	                                 char* block_label,
	                                 PntosMatrix* estimate);

	/**
	 * Find a `PntosStandardStateBlock` within the fusion engine matching \p block_label, and change
	 * its current covariance matrix. Note that this function may lead to performance degradation
	 * with some implementations and thus its use is discouraged if other options are available.
	 */
	void (*set_state_block_covariance)(struct PntosStandardFusionEngine* self,
	                                   char* block_label,
	                                   PntosMatrix* covariance);

	/**
	 * Find the `PntosStandardStateBlock`s within the fusion engine matching \p block_label1 and \p
	 * block_label2, and change the current covariance matrix between them. Note that this function
	 * may lead to performance degradation with some implementations and thus its use is discouraged
	 * if other options are available.
	 */
	void (*set_state_block_cross_covariance)(struct PntosStandardFusionEngine* self,
	                                         char* block_label1,
	                                         char* block_label2,
	                                         PntosMatrix* covariance);

	/**
	 * Remove the `PntosStandardStateBlock` previously added to the fusion engine using
	 * #add_state_block based on a matching \p block_label. This will reduce the state vector
	 * being estimated by the number of states that the block represents.
	 */
	void (*remove_state_block)(struct PntosStandardFusionEngine* self, char* block_label);

	/**
	 * Gets a list of the target labels of virtual state blocks that have been added to this fusion
	 * engine.
	 *
	 * A label being returned by this list is not a guarantee that the virtual state block has a
	 * valid source. For that, call has_virtual_state_block().
	 *
	 * Returns NULL if no virtual state blocks have been added to this fusion engine.
	 */
	PntosStringArray* PNTOS_NULLABLE (*get_virtual_state_block_target_labels)(
	    struct PntosStandardFusionEngine* self);

	/**
	 * Returns true if the fusion engine has a `PntosVirtualStateBlock` with a matching target label
	 * that is capable of generating an estimate. That is, the VSB's source exists and is in a
	 * continuous chain to a concrete state block which also exists in the fusion engine.
	 */
	bool (*has_virtual_state_block)(struct PntosStandardFusionEngine* self, char* vsb_target_label);

	/**
	 * Add the given `PntosVirtualStateBlock` to the fusion engine. A virtual state block (VSB)
	 * convert from an underlying block coordinate frame into the VSB coordinate frame.
	 */
	void (*add_virtual_state_block)(struct PntosStandardFusionEngine* self,
	                                PntosVirtualStateBlock* virtual_state_block);

	/**
	 * Remove the `PntosVirtualStateBlock` previously added to the fusion engine using
	 * #add_virtual_state_block based on a matching \p vsb_target_label.
	 */
	void (*remove_virtual_state_block)(struct PntosStandardFusionEngine* self,
	                                   char* vsb_target_label);

	/**
	 * Gets a list of the labels of measurement processors that have been added to this fusion
	 * engine. Returns NULL if no measurement processors have been added to this fusion engine.
	 */
	PntosStringArray* PNTOS_NULLABLE (*get_measurement_processor_labels)(
	    struct PntosStandardFusionEngine* self);

	/**
	 * Returns true if the fusion engine has a measurement processor with a matching label.
	 */
	bool (*has_processor)(struct PntosStandardFusionEngine* self, char* processor_label);

	/**
	 * Add a PntosStandardMeasurementProcessor which can be used to process future measurements that
	 * correspond to `processor->get_label()`;
	 */
	void (*add_measurement_processor)(struct PntosStandardFusionEngine* self,
	                                  PntosStandardMeasurementProcessor* processor);

	/**
	 * Remove the PntosStandardMeasurementProcessor previously added to the fusion engine using
	 * #add_measurement_processor based on a matching \p processor_label.
	 */
	void (*remove_measurement_processor)(struct PntosStandardFusionEngine* self,
	                                     char* processor_label);

	/**
	 * Propagate the filter estimate forward in time. May be evaluated lazily (when results are
	 * requested).
	 */
	void (*propagate)(struct PntosStandardFusionEngine* self, AspnTypeTimestamp time);

	/**
	 * Update the filter with the given measurement. Will propagate first if needed to reach the
	 * time encoded inside the measurement.
	 */
	void (*update)(struct PntosStandardFusionEngine* self,
	               char* processor_label,
	               PntosMessage* message);

	/**
	 * Calculates the estimate and covariance at a requested time using the state blocks listed in
	 * \p block_labels, without changing the state of the fusion engine or its underlying filter.
	 * Blocks are assembled in the order that the labels are passed in.
	 *
	 * \p block_labels is an array of \p num_block_labels pointers to `\0` terminated C strings.
	 *
	 * If all of the following are true:
	 *
	 * - \p time is equal to or after the filter time (which can be checked with #get_time)
	 * - all labels in \p block_labels correspond to a block that has been added to the fusion
	 *   engine (which can be checked with #has_block)
	 * - \p num_block_labels is greater than zero
	 *
	 * Then the result returned is guaranteed to not be NULL. Otherwise, if any of the above are
	 * false then the result will be NULL.
	 */
	PntosEstimateWithCovariance* PNTOS_NULLABLE (*peek_ahead)(
	    struct PntosStandardFusionEngine* self,
	    AspnTypeTimestamp time,
	    char** block_labels,
	    size_t num_block_labels);

	/**
	 * Generates the current estimate and covariance built corresponding to a list of State Block
	 * labels. Blocks are assembled in the order that the labels are passed in.
	 *
	 * \p block_labels is an array of \p num_block_labels pointers to `\0` terminated C strings.
	 *
	 * If all of the following are true:
	 *
	 * - all labels in \p block_labels correspond to a block that has been added to the fusion
	 *   engine (which can be checked with #has_block)
	 * - \p num_block_labels is greater than zero
	 *
	 * Then the result returned is guaranteed to not be NULL. Otherwise, if any of the above are
	 * false then the result will be NULL.
	 */
	PntosEstimateWithCovariance* PNTOS_NULLABLE (*generate_x_and_p)(
	    struct PntosStandardFusionEngine* self, char** block_labels, size_t num_block_labels);

	/**
	 * Route a `PntosMessageArray` of aux data to a `PntosStandardStateBlock` previously registered
	 * using #add_state_block based on a matching \p block_label.
	 */
	void (*give_state_block_aux_data)(struct PntosStandardFusionEngine* self,
	                                  char* block_label,
	                                  PntosMessageArray* aux);

	/**
	 * Route a `PntosMessageArray` of aux data to a `PntosStandardMeasurementProcessor` previously
	 * registered using #add_measurement_processor based on a matching \p processor_label.
	 */
	void (*give_measurement_processor_aux_data)(struct PntosStandardFusionEngine* self,
	                                            char* processor_label,
	                                            PntosMessageArray* aux);

	/**
	 * Route a `PntosMessageArray` of aux data to a `PntosVirtualStateBlock` previously registered
	 * using #add_virtual_state_block based on a matching \p target_label.
	 */
	void (*give_virtual_state_block_aux_data)(struct PntosStandardFusionEngine* self,
	                                          char* target_label,
	                                          PntosMessageArray* aux);

	/**
	 * Produce a deep-copy this fusion engine instance. All state blocks and measurement processors
	 * held by the fusion engine will also be cloned. The fusion strategy used by the fusion engine
	 * will also be cloned.
	 */
	struct PntosStandardFusionEngine* (*clone)(struct PntosStandardFusionEngine* self);
} PntosStandardFusionEngine;

/**
 * Plugin that provides a `PntosCommonFusionEngine`, allowing data from multiple sensors to be
 * integrated into a unified state estimate.
 */
typedef struct PntosFusionPlugin {
	/** Core plugin structure. See PntosCommonPlugin */
	PntosCommonPlugin common;

	/**
	 * Return if the plugin supports a given type of fusion. See #PntosFusionType.
	 */
	bool (*is_fusion_type_supported)(struct PntosFusionPlugin* self, PntosFusionType type);

	/**
	 * Create an instance of #PntosCommonFusionEngine. The #PntosFusionType parameter specifies the
	 * type of fusion that the returned value will support. For example, if the user passes in
	 * #PNTOS_FUSION_STANDARD_MODEL, then the returned value will be castable to
	 * #PntosStandardFusionEngine. Returns NULL if \p type is not supported by this fusion plugin
	 * (#is_fusion_type_supported can be used to check the type before calling this method).
	 * Otherwise the return is guaranteed to not be NULL.
	 */
	PntosCommonFusionEngine* PNTOS_NULLABLE (*new_fusion_engine)(struct PntosFusionPlugin* self,
	                                                             PntosFusionType type);
} PntosFusionPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
