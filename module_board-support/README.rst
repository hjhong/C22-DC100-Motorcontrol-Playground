SOMANET Board Support Packages
==============================

:scope: General Use
:description: Contains BSPs for all available SOMANET hardware modules
:keywords: SOMANET, BSP, board support package, port mapping
:boards: All SOMANET boards

Key Features
------------

  * Port mappings for all SOMANET Modules
 
Description
-----------

The module contains all board support package files needed to use SOMANET hardware modules with convenience. Please include the appropriate *.inc* files in the first lines of your main application file (e.g. main.xc) file like this::
      #include <CORE_C22-rev-a.inc>;
      #include <COM_ECAT-rev-a.inc>;
      #include <IFM_CDC100-rev-b.inc>;
