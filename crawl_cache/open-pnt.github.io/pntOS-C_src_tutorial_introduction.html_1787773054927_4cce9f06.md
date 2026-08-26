<!-- crawl_url: https://open-pnt.github.io/pntOS-C/src/tutorial/introduction.html -->
<!-- crawl_ts: 1787773054 -->
<!-- quality: sufficient -->
<!-- char_count: 14327 -->
<!-- word_count: 2061 -->

- »
- Introduction
- [View page source](https://open-pnt.github.io/pntOS-C/_sources/src/tutorial/introduction.rst.txt)

# Introduction

pntOS (position, navigation, and timing Operating System) is a government-owned
fully-modular architecture for building navigation systems. It is designed so
that a system can be created from a mixture of proprietary and government-owned
components.

## Motivation

Most PNT systems are “stovepipe” systems that are designed for a specific
configuration of sensors to solve a particular PNT need. PNT threats are
evolving rapidly. In particular, GPS-denied environments are becoming more
common. Complementary PNT approaches mitigate these threats but changing
current PNT systems is a slow and expensive process.

pntOS is designed to address this situation. It has broken up the concept of a PNT system into its
component pieces (called plugins) and defined an Application Programming Interface (API) to
standardize their interactions, allowing for plugins to be individually swappable. In order to
foster community use and development, pntOS is fully government-owned. While some plugins may be
open-source, plugins could be closed-source, allowing for proprietary algorithms to be used in
pntOS.

While pntOS is analogous to an operating system in its functionality, it is not
a true operating system. For more information, see[Is pntOS an operating system?](https://open-pnt.github.io/pntOS-C/src/tutorial/faq.html#is-pntos-an-operating-system).

## pntOS High Level Overview

First let’s look at pntOS as a black box. It accepts measurements from various
sensors, performs data fusion or filtering, and produces a navigation solution.
All navigation data used internally in pntOS is ASPN-formatted data. Most
sensors do not output ASPN data so the data needs to be converted before it can
be used. This can happen in a few places:

1. In between the sensor and pntOS
2. In the pntOS[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)

3. In the sensor itself

The following image illustrates these operating modes in order from top to
bottom respectively:

![../../_images/pntos_overview.png](https://open-pnt.github.io/pntOS-C/_images/pntos_overview.png)Next we’ll open up the pntOS box and discuss some of the core components and
plugins that make up pntOS.

## pntOS Components

We will start at the bottom of the diagram with the`Loader`and work our way
through the control flow.

![../../_images/pntos_overview2.png](https://open-pnt.github.io/pntOS-C/_images/pntos_overview2.png)

### Loader (Hosted Environment)

Although pntOS can run on[bare metal](https://en.wikipedia.org/wiki/Bare_machine), in this section we will assume
we are running in a hosted environment, like running as an application on Linux
or a real-time operating system (RTOS).

The pntOS daemon starts by the user calling the`Loader`with a list of
plugins. This is typically done by the user running a binary executable which in
turn invokes the main function in the loader. A list of paths to the locations
of dynamically-linked libraries containing plugins is passed to the executable
as command line parameters. The`Loader`then opens the dynamic library file
corresponding to each plugin and component it was passed. It scans the list of
plugins for one (and only one)[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin). Then the`Loader`hands

over control (by calling[take_control](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv4N21PntosControllerPlugin12take_controlE)) of the

process to the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin). When this occurs, the loader passes

the list of all the other plugins it found in the shared libraries earlier to
the controller as a parameter.

### Controller

From this point forward, the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)is responsible for all activity

in the daemon. It may use any of the plugins it was passed as desired. The[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)defines any and all I/O (Input/Output) it supports, which pntOS plugins

are loaded or used, and the type of fusion being done. The[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)should be written generically to support arbitrary run-time environment sensing.

Outside of some initialization in the`Loader`, the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)is the

conceptual “main” function of the pntOS daemon.

The controller’s main responsibility is to choose and initialize the
concurrency model being used by pntOS. For example, a controller might decide
on a multithreaded implementation, or a multiprocessed implementation for
better isolation and security. A simple controller might create a single thread
for each plugin it was given and then set up thread-safe communication pipes
between those plugins.

### Mediator

Named after the computer science “mediator design pattern” concept, the[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)is an object created by the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)and handed to each

plugin. It encapsulates communication and shared state between the plugins.

Before the controller may use any of the plugins it was passed, it must first
call the[init_plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosCommonPlugin.html#_CPPv4N17PntosCommonPlugin11init_pluginE)function on that plugin and

pass into it a[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator). The[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)object is the only way that plugins

may communicate back to the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin), by invoking the function

pointers on the object.

The[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)therefore is where concurrency and synchronization are decided.

Continuing the example of a multithreaded implementation where each plugin is in
a separate thread, the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)might implement a simple[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)by creating and storing internally a set of mutex locks, one per thread, and

then locking each call to a[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)function using a mutex. The[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)function calls would then consist of locking logic followed by routing calls

from one plugin to another. In our current example illustrated in the above
diagram, we are routing data the[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)received from a sensor through

the[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator), which in turn (after synchronization according to its

concurrency model) sends the data on to the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin).

As another example, suppose instead we were writing a multiprocessed controller.
In this case, the controller might`fork()`to put plugins into their own
processes, and then write a[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)that opens IPC communication primitives

(such as`/dev/shm`or sockets) in order to route the data from the[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)to the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin), which are now in different processes. Thus the[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator)that is constructed by the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin)is tied closely to the

concurrency model chosen by the[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin).

### Transport

The[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)receives messages from various sensors, sends responses

back to sensors as needed, and broadcasts the pntOS solution from the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin). Its primary responsibility is receiving sensor data from

the network, converting it to ASPN format, and then forwarding it onward to the
mediator.

### Orchestration

The pntOS[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)contains the core navigation data fusion and

filtering functionality. It is responsible for calculating a navigation
solution from the incoming sensor data. It performs this task by calling out to
various plugins which define the actual sensor fusion algorithm, state space,
and sensor error models. Thus its primary duties are to orchestrate the flow of
data into/out of filters, and picking the set of navigation-related plugins which
are used to model errors and generate estimates.

### Platform Integration

The[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)is an optional plugin. It converts the outgoing

navigation solution from an ASPN format to any other format required by the
user. We’ll look at how this plugin interacts with the rest of the system in
more detail in[Platform Integration Plugin Interactions](https://open-pnt.github.io/pntOS-C/src/tutorial/introduction.html#platform-integration-plugin-interactions).

## Orchestration Plugin Components

Next, let’s dive into the components and plugins that make up the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin).

![../../_images/pntos_overview3.png](https://open-pnt.github.io/pntOS-C/_images/pntos_overview3.png)The[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)could be a single black box solution or broken up

into more modular components. In the latter case, a bank of one or more filters
has access to a bank of filtering plugins. Filtering plugins might include the:

1. `Orchestration Strategy`plugin
2. [Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin)

3. [State Modeling plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a370fada2572ce031930446e154c9f67a.html#_CPPv424PntosStateModelingPlugin)

4. [Inertial plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_inertial_8h_1a55233932d1b3c2c2cc27b4ffa3df1045.html#_CPPv419PntosInertialPlugin)

5. [Initialization plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/enum_common_8h_1a48664ff328a2802f2df1e33b5dbc4e93.html#_CPPv4N16PntosPluginTypes27PNTOS_INITIALIZATION_PLUGINE)

### Orchestration Strategy

The`Orchestration Strategy`plugin is relatively tightly involved with the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin). It is responsible for ensuring that the pntOS solution

is robust and resilient to sensor faults. This could range from protecting
against faulty sensors, to improper state models, to malicious attacks from an
outside party.

### Fusion

The[Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin)accepts sensor measurements (and possibly a reference

Position-Velocity-Attitude (PVA) solution from the[Inertial plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_inertial_8h_1a55233932d1b3c2c2cc27b4ffa3df1045.html#_CPPv419PntosInertialPlugin)) via the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)and passes them to the[Fusion Strategy plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionStrategyPlugin.html#_CPPv425PntosFusionStrategyPlugin). It does

all the book-keeping to keep track of which state blocks and measurement
processors correspond to which states in the[Fusion Strategy plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionStrategyPlugin.html#_CPPv425PntosFusionStrategyPlugin).

### Fusion Strategy

The[Fusion Strategy plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionStrategyPlugin.html#_CPPv425PntosFusionStrategyPlugin)does the core estimation work. It determines what

type of estimator is used, such as an Extended Kalman Filter (EKF),
Rao-Blackwellized Particle Filter (RBPF), or something else. It receives models
from the state blocks and measurement processors in the[State Modeling plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a370fada2572ce031930446e154c9f67a.html#_CPPv424PntosStateModelingPlugin)s via

the[Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin)and propagates and updates its states accordingly.

### Inertial

The[Inertial plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_inertial_8h_1a55233932d1b3c2c2cc27b4ffa3df1045.html#_CPPv419PntosInertialPlugin)receives an initial PVA alignment and IMU (Inertial

Measurement Unit) measurements which it mechanizes to produce an INS (Inertial
Navigation System) solution. This plugin may also handle resets and feedback
from the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin).

### Initialization

This plugin uses sensor data and user inputs received from the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)to calculate

an initial solution. This could be a PVA used as the starting point for the INS solution generated
by the[Inertial plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_inertial_8h_1a55233932d1b3c2c2cc27b4ffa3df1045.html#_CPPv419PntosInertialPlugin)or an estimate and covariance used to initialize a state block.

## State Modeling Plugin Components

Last, let’s take a deeper look into the[State Modeling plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a370fada2572ce031930446e154c9f67a.html#_CPPv424PntosStateModelingPlugin).

![../../_images/state_modeling_plugin.png](https://open-pnt.github.io/pntOS-C/_images/state_modeling_plugin.png)This plugin contains lists of[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)s,[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s, and[Virtual State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a8a62a7f57979df93adb27cfbbc5aba1b.html#_CPPv422PntosVirtualStateBlock)s and a factory to construct them. At the[Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin)’s request it constructs these objects and returns them to the[Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin).

Below is some very brief information about[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)s,[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s, and[Virtual State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a8a62a7f57979df93adb27cfbbc5aba1b.html#_CPPv422PntosVirtualStateBlock)s, as well as links to sections with

more information.

### Measurement Processor

[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)s are responsible for providing the model that the

Filter Strategy uses to update its states given a sensor measurement. For more
detailed information on the function of[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)s, see[Measurement Processors](https://open-pnt.github.io/pntOS-C/src/internals/measurement_processor.html#measurement-processors).

### State Block

[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s provide the Filter Strategy with states and a model to

propagate those states. For more detailed information on the function of[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s, see[State Blocks](https://open-pnt.github.io/pntOS-C/src/internals/state_block.html#state-blocks).

### Virtual State Block

Consider the case where a given[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)provides three

Latitude-Longitude-Altitude (LLH) states and a given[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)provides a model to update three Earth Centered, Earth Fixed (ECEF) position

states. Normally this[Measurement Processor](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1ac8c5f9cbd335aac5b12ba6c2272fcb85.html#_CPPv433PntosStandardMeasurementProcessor)and[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)would be

incompatible with each other, but a Virtual State Block that converts between
ECEF position and LLH position could bridge the gap.

In short,[Virtual State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a8a62a7f57979df93adb27cfbbc5aba1b.html#_CPPv422PntosVirtualStateBlock)s convert the states provided by[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s. For more detailed information on the function of[State Block](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a3a40f02c725e1c507ffc8ad7f2d4d6ca.html#_CPPv423PntosStandardStateBlock)s,

see[Virtual State Blocks](https://open-pnt.github.io/pntOS-C/src/internals/virtual_state_block.html#virtual-state-blocks).

## Platform Integration Plugin Interactions

Let’s move back to the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)to examine it in more

detail. One of the tasks of this plugin is to handle all of the
platform-specific messages that might be needed and it is impossible to
enumerate all the possibilities here. Instead, we’ll try to focus on some of
the most common interactions here.

![../../_images/platform_integration_plugin.png](https://open-pnt.github.io/pntOS-C/_images/platform_integration_plugin.png)The graphic above shows some of the typical interactions between the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)and other pieces of the system.

As alluded to in the[Platform Integration](https://open-pnt.github.io/pntOS-C/src/tutorial/introduction.html#platform-integration)section, when a platform needs

the navigation solution in a non-ASPN format, it is the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)’s job to convert the ASPN navigation solution from the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)into the desired format and send it to the platform output.

The system may need the sensors to change operation. In this case, the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)may send mode messages to the sensors with

instructions to change the output frequency, consume a different amount of
power, etc. Conversely, the sensors may have non-navigation data to send to the
system. The[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)will convert and forward any such data

from the sensors to relevant parts of the system.

Similarly, the platform and pntOS may need to exchange non-ASPN data or
instructions. For example, the platform may instruct pntOS to start filtering,
enter a standby state, change the output rate, etc. The[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)will handle all these interactions as well, acting as the liaison

between the platform and pntOS.

## Another View of pntOS

At this point, now that we’ve gotten some understanding of the core components
and plugins in pntOS, let’s take a look at everything all together and define
some of the smaller plugins.

![../../_images/pntos_another_view.png](https://open-pnt.github.io/pntOS-C/_images/pntos_another_view.png)This graphic shows how the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)relates to pntOS as a whole,

but also the relationship of the plugins that make up the[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin)by encapsulating them all within a dotted octagon.

The figure also shows an optional relationship between the[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)and the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)by using a dotted arrow line. This

indicates that the[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin)is allowed to use the[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin)for input and output.

So far we’ve discussed the`Loader`,[Controller Plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosControllerPlugin.html#_CPPv421PntosControllerPlugin),[Mediator](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_common_8h_1a806a49ee4d3182e046b498d24dd8dff9.html#_CPPv413PntosMediator),[Transport plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_transport_8h_1acba7719ef84863a2eb3abfd54f54b763.html#_CPPv420PntosTransportPlugin),[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin),[Orchestration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_orchestration_8h_1a9f431f31bfbab3a17bc7136ef037dae5.html#_CPPv424PntosOrchestrationPlugin),[Fusion plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionPlugin.html#_CPPv417PntosFusionPlugin),[Fusion Strategy plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/structPntosFusionStrategyPlugin.html#_CPPv425PntosFusionStrategyPlugin),[State Modeling plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_state__modeling_8h_1a370fada2572ce031930446e154c9f67a.html#_CPPv424PntosStateModelingPlugin),[Inertial plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_inertial_8h_1a55233932d1b3c2c2cc27b4ffa3df1045.html#_CPPv419PntosInertialPlugin),[Initialization plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/enum_common_8h_1a48664ff328a2802f2df1e33b5dbc4e93.html#_CPPv4N16PntosPluginTypes27PNTOS_INITIALIZATION_PLUGINE), and`Orchestration Strategy`plugin. Next we’ll move on to the

remaining plugins: the[Database plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/enum_common_8h_1a48664ff328a2802f2df1e33b5dbc4e93.html#_CPPv4N16PntosPluginTypes21PNTOS_DATABASE_PLUGINE),[Logging plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_logging_8h_1a2b466e111baec4d7c26712c821746859.html#_CPPv418PntosLoggingPlugin),[Registry plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_registry_8h_1af6641809de4b96624157240433fe8aab.html#_CPPv419PntosRegistryPlugin),

and[User Interface plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_ui_8h_1ac5bfed8d44da846f8430d4fe67d82659.html#_CPPv413PntosUiPlugin).

### Database

[Database plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/enum_common_8h_1a48664ff328a2802f2df1e33b5dbc4e93.html#_CPPv4N16PntosPluginTypes21PNTOS_DATABASE_PLUGINE)s provide the system with navigation data. For example, some

systems might require DTED (Digital Terrain Elevation Data).

### Logging

The[Logging plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_logging_8h_1a2b466e111baec4d7c26712c821746859.html#_CPPv418PntosLoggingPlugin)records messages to an arbitrary sink (e.g. console, file,

network, etc.).

### Registry

The[Registry plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_registry_8h_1af6641809de4b96624157240433fe8aab.html#_CPPv419PntosRegistryPlugin)implements a global key-value registry. See[pntOS Registry Overview](https://open-pnt.github.io/pntOS-C/src/internals/registry.html#pntos-registry-overview)for more information on the[Registry plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_registry_8h_1af6641809de4b96624157240433fe8aab.html#_CPPv419PntosRegistryPlugin).

### UI

The[User Interface plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_ui_8h_1ac5bfed8d44da846f8430d4fe67d82659.html#_CPPv413PntosUiPlugin)implements a UI that is integrated directly into

pntOS. While it is always possible to write a Graphical User Interface (GUI)
that listens to pntOS outputs and interacts with it externally, this plugin
allows users to write a GUI that has direct access to pntOS via the plugin API.
This allows for low latency and high performance GUI/UIs to be generated. Note
that this plugin is designed for developer or research style UIs and not
production environments. A user display in a production environment is better
modeled as a[Platform Integration plugin](https://open-pnt.github.io/pntOS-C/pntos-api-exhale/typedef_platform__integration_8h_1a95c15d76bcff10d1707f1ca3a22f8b45.html#_CPPv430PntosPlatformIntegrationPlugin), as that is designed to represent

requests from the system and not simply status updates.