SOMANET xSCOPE Usage wrapper
============================

:scope: General Use
:description: An xSCOPE wrapper to turn xSCOPE on and off in SOMANET blocks
:keywords: xSCOPE
:boards: SOMANET

Key Features
------------

  * Enabling and disabling xSCOPE without removing xSCOPE functions from the SOMANET code 

Description
-----------

The module allows enabling/disabling xSCOPE without removing the function calls from the code.

- To enable the xSCOPE use: ::

  #define USE_XSCOPE

- To disable the xSCOPE remove the define. All xSCOPE functions will be replaced with NOPs

- This may be added to CFLAGS in your project's Makefile: ::

   CFLAGS += -DUSE_XSCOPE
