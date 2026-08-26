Frequently Asked Questions
==========================

Is pntOS an operating system?
*****************************

pntOS is analogous to an operating system in the sense that, like a computer
operating system manages basic computer functions like task scheduling and
executing programs, it manages the basic functions in a PNT system. Similar to
Robot Operating System (ROS), it is a meta-operating system or tool for building
systems. It is not a replacement for a complete computer operating system like
Linux, Windows, or OSX, however. pntOS can either run as a daemon (application)
inside of an environment like Linux, or as a freestanding single process on bare
metal (with the appropriate plugin implementations available). But it does not
provide an abstraction layer for managing and scheduling processes, abstracting
hardware for other software to utilize, or other common functions of an OS
kernel. pntOS either runs as a user space application or a bare metal process.
