#pragma once

#include <pntos/plugins/common.h>
#include <pntos/stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * An enumeration of the different types of initialization strategies.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef enum PntosInitializationType {
	/**
	 * Produces an ASPN solution to initialize an inertial. Also produces estimates of the inertial
	 * errors and covariances associated with each.
	 */
	PNTOS_INERTIAL_INITIALIZATION_STRATEGY,
	/**
	 * Produces an arbitrary estimate-with-covariance (EWC) solution.
	 */
	PNTOS_EWC_INITIALIZATION_STRATEGY
} PntosInitializationType;

/**
 * An enumeration that allows the user to know the initialization status.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef enum PntosInitializationStatus {
	/**
	 * Waiting to start initialization process.
	 */
	PNTOS_WAITING,
	/**
	 * Attempting to initialize and produce a navigation solution.
	 */
	PNTOS_INITIALIZING_COARSE,
	/**
	 * A coarse initialization has been calculated by the algorithm, and the initialization is being
	 * tested or adjusted before producing a navigation solution.
	 */
	PNTOS_INITIALIZING_FINE,
	/**
	 * We have a good initialization, provided solution can be used to kickoff inertial and fusion.
	 */
	PNTOS_INITIALIZED_GOOD,
	/**
	 * The initialization process failed in some way, and may attempt to restart.
	 */
	PNTOS_INITIALIZATION_FAILED
} PntosInitializationStatus;

/**
 * An enumeration that specifies what type of motion is required by the initialization strategy.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef enum PntosInitializationMotionNeeded {
	/**
	 * Stationary data is needed.
	 */
	PNTOS_NO_MOTION,
	/**
	 * Dynamic data is needed.
	 */
	PNTOS_MOTION_NEEDED,
	/**
	 * No particular type of motion is required.
	 */
	PNTOS_ANY_MOTION
} PntosInitializationMotionNeeded;

/**
 * A common base type for initialization algorithms.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosCommonInitializationStrategy {
	PntosManagedMemory* memory;

	/**
	 * The type of initialization strategy this struct can be downcast to. For example, if this
	 * field is `PNTOS_INERTIAL_INITIALIZATION_STRATEGY`, then this struct is actually a
	 * PntosInertialInitializationStrategy.
	 */
	PntosInitializationType type;

	/**
	 * @return The type of motion (if any) needed.
	 */
	PntosInitializationMotionNeeded (*request_motion_needed)(
	    struct PntosCommonInitializationStrategy* self);

	/**
	 * @return The current initialization status.
	 */
	PntosInitializationStatus (*request_current_status)(
	    struct PntosCommonInitializationStrategy* self);

	/**
	 * @param message A new message to be incorporated into the initialization algorithm and return
	 * the initialization state.
	 */
	void (*process_pntos_message)(struct PntosCommonInitializationStrategy* self,
	                              PntosMessage* message);
} PntosCommonInitializationStrategy;

/**
 * A container that holds both the current solution, inertial errors (and their associated
 * covariance), and the current status. Coupling these avoids time-of-check to time-of-use (TOCTOU)
 * issues.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosInitialInertialSolution {
	PntosManagedMemory* memory;

	/**
	 * The initial solution.
	 */
	PntosMessage* PNTOS_NULLABLE solution;

	/**
	 * The inertial errors.
	 */
	PntosStandardInertialErrors* PNTOS_NULLABLE inertial_errors;

	/**
	 * The covariance matrix associated with the terms in #inertial_errors.
	 */
	PntosMatrix* PNTOS_NULLABLE inertial_error_covariance;

	/**
	 * Indicates the current initialization status. Should be checked before using any of the other
	 * fields.
	 */
	PntosInitializationStatus status;
} PntosInitialInertialSolution;

/**
 * A struct produced by a PntosInitializationPlugin that generates an inital ASPN solution from
 * sensor data.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosInertialInitializationStrategy {
	PntosCommonInitializationStrategy common;

	/**
	 * @return the current initial solution.
	 */
	PntosInitialInertialSolution* (*request_solution)(
	    struct PntosInertialInitializationStrategy* self);

} PntosInertialInitializationStrategy;

/**
 * A container that holds both the current estimate and its associated covariance as well as the
 * current status. Coupling these avoids time-of-check to time-of-use (TOCTOU) issues.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosInitialEstimateWithCovariance {
	PntosManagedMemory* memory;

	/**
	 * The time at which #estimate_with_covariance is valid.
	 */
	AspnTypeTimestamp time;

	/**
	 * The current estimate of the initial solution. Check #status for its validity (can be NULL if
	 * #status is anything other than PNTOS_INITIALIZED_GOOD).
	 */
	PntosEstimateWithCovariance* PNTOS_NULLABLE estimate_with_covariance;

	/**
	 * Indicates the current initialization status. Should be checked before using
	 * #estimate_with_covariance.
	 */
	PntosInitializationStatus status;
} PntosInitialEstimateWithCovariance;

/**
 * A struct produced by a PntosInitializationPlugin that generates an inital
 * estimate-with-covariance (EWC) solution from sensor data.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosEwcInitializationStrategy {
	PntosCommonInitializationStrategy common;

	/**
	 * @return the current initial solution. Will be NULL if the initialization strategy has not yet
	 * finished. Use #PntosCommonInitializationStrategy.request_current_status to check current
	 * status of the strategy. If the status is PNTOS_INITIALIZING_FINE or PNTOS_INITIALIZED_GOOD,
	 * then the result is guaranteed to not be NULL.
	 */
	PntosInitialEstimateWithCovariance* PNTOS_NULLABLE (*request_solution)(
	    struct PntosEwcInitializationStrategy* self);

} PntosEwcInitializationStrategy;

/**
 * An implementation of an initialization plugin. This plugin generates
 * PntosCommonInitializationStrategy instances which may be used to generate an initial solution
 * from additional external sensor data, such as IMU data.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosInitializationPlugin {
	PntosCommonPlugin common;

	/**
	 * Return true if the plugin supports a given type of mechanization, false otherwise.
	 */
	bool (*is_initialization_type_supported)(struct PntosInitializationPlugin* self,
	                                         PntosInitializationType type);

	/**
	 * Create an instance of PntosCommonInitializationStrategy.
	 *
	 * @param type Specifies the type of initializer that the returned value will support. For
	 * example, if the user passes in #PNTOS_INERTIAL_INITIALIZATION_STRATEGY, then the returned
	 * value will be castable to PntosInitialInertialSolution. If \p type is unsupported by the
	 * plugin, then NULL will be returned. Please use #is_initialization_type_supported to check if
	 * the type is supported by the plugin.
	 * @param config_group An optional parameter which can be used to specify which group in the
	 * config should be used to set up the new initialization strategy. This allows for multiple
	 * initialization strategy instances to exist with unique settings.
	 *
	 * @return The new initialization strategy instance. Returns NULL if \p type is unsupported by
	 * this plugin (this can be checked using #is_initialization_type_supported) or if \p
	 * config_group is invalid.
	 */
	PntosCommonInitializationStrategy* PNTOS_NULLABLE (*new_initialization_strategy)(
	    struct PntosInitializationPlugin* self,
	    PntosInitializationType type,
	    char* PNTOS_NULLABLE config_group);
} PntosInitializationPlugin;

#ifdef __cplusplus
}
#endif

PNTOS_ASSUME_NONNULL_END
