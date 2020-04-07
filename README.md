# myfenjalinuxcnc
This repository contains the latest stable version of my LinuxCNC configuration for my CNC Router aptly named groot. It is based on LinuxCNC Master (currently 2.9pre).

The CNC router's design is based on "Fenja" created by A. Koch of [fraeserbruch.de](https://fraeserbruch.de/ "Fenja's home"). Plans and parts are available through him. The design offers various sizes to choose from and requires the owner to chose drives, spindle and control. Furthermore, it is supported by a great community. I highly recommend Andreas' work.

The purpose of this GIT is to have a repo for my own changes to the config. However, as the same questions pop up time and again in various communities, I have chosen to make this configuration public. Note, that LinuxCNC HAL and INI files are very specific to individual machines. While the deployed concepts can be transfered easily, specific values and hardware pins are to be analyzed carefully. Do not ever run a foreign config on your machine without checking every detail beforehand. I strongly recommend taking ideas from other configs and integrating those into to your own. If you need a minimum working example to start with, I recommend trying the [PNCConf Wizard](http://linuxcnc.org/docs/html/config/pncconf.html) when running MESA cards. I will not take responsibility for any damages to your hardware or person.


All of the config options presented here are applicable to any CNC router design.

## Features
* Based on MESA card model 7i76E
* Runs on LinuxCNC 2.9 with Debian 9 (uses linuxcnc master branch)
* Uses GMOCCAPY GUI in version 3.x with a touch screen
* Connects via modbus to an Hitachi WJ-200 VFD to control a Jianken JGL80/2.2-R24-20 ATC spindle with ISO20 toolholders
* Tool change is currently done via manual tool handling and using a push button to toggle between valve settings for tool release and clamping. LUT5 components are used to check whether spindle is enabled (=turning) or not and ensures, that ATC functions are not triggered while the spindle is in operation. This will lead to the destruction of the spindle.
* Uses NC inductive limit switches on each axis (one each) and furthermore uses these for homing. Axis limits are doen using soft limits
* Connects LinuxCNC software to a PILZ safety relais (PNOZ 11) using the relais' semi conductor output (Y32). This triggers estop in linuxcnc when a hardware button is pushed and cuts power to the axis drives and is wired to the vfd.  
* Provide the Option to use two different pendants
  * XHC-HB04 wireless pendant with slightly modified key mapping: needs to be activated by removing '# from groot.ini at two places
  * Alternatively uses TSHW by surmetall (Tom) and Talla83; see http://www.talla83.de/Tshw.html; see hallib/tshw.hal further changes in estop.hal and groot.ini to load different hal files
* Uses probe_screen_v2 (see [probe_screen_v2](https://github.com/verser-git/probe_screen_v2)) together with a wireless touch probe by [vers.by](https://vers.by/en) and a wire based tool length sensor at a fixed location on the machine table
* Includes fixed macros and probe_screen.py for use with LinuxCNC 2.8/ 2.9 (dealing with joint/axis changes and changes to command.jog in LinuxCNC Python interface; seperate fork can be found on [github](https://github.com/GuiHue/probe_screen_v2))
* Uses JMC iHSV57xxx servos on X and Y axis; JMC Closed Loop Stepper on Z, run as stepper drives with STP/DIR signals from the MESA stepgens
  * Note that IHSV57 with software v5xx is used on X axis and software v604 is used on y axis
  * Further note, that the timings (provided in ns) are slightly different. v604 appears to require longer timings
* Controls various relais using MESA DO depending on the present machine condition
* Controls various 3/2 valves using MESA DO for the pneumatic setup
* Checks a Festo 527467 pressure sensor (NC) and triggers a warning message when pressure drop is registered
* Provides an additional GLADE embedded tab "SpindleUI" with various information regarding spindle and ATC status (hallib/spindleUI.glade and hallib/spindleUI.hal).

## Notes
* Common errors with probe_screen:
  * Funny offset issues will arise, when gmoccapy tool change functions are still activated in gmoccapy settings while using probe_screen. Gmoccapy settings can be changed at the approriate place in the menu
* Config contains various comments hoping to clarify net commands
* HAL files in the config are located in folder "hallib" and are split by various topics
  * mesa.hal is the basic file for the setup, containing hostmot2 setup, mesa related commands and all loadrt calls for common hal components such as not, and2, etc. These are called by name, not by number.
  * io.hal contains all net commands regarding the 32 inputs of MESA 7i76e (AI00-Ai03 and DI04-DI31) and 16 outputs DO00-DO15, it is called last

## Misc Router Hardware and Setup Information
* The machine consists of an aluminum extrusion design with some milled components made from milled plate material in EN AW 5083.
* Working envelope is roughly X/Y/Z 635/1240/165 mm
* control cabinet uses 400V16A three phase power split into 3 x 16A 230V single phase power. All components run of single phase power
* Spindle is cooled using a CW-3000 chiller

## Useful links
### LinuxCNC General
* http://linuxcnc.org/docs/html/gcode/m-code.html
* http://linuxcnc.org/docs/html/gcode/g-code.html
* http://linuxcnc.org/docs/html/gcode/o-code.html
* http://linuxcnc.org/docs/devel/html/hal/basic-hal.html
* http://linuxcnc.org/docs/html/man/man1/halui.1.html
* http://linuxcnc.org/docs/html/config/ini_config.html
* http://linuxcnc.org/docs/html/config/core-components.html#_iocontrol
* http://linuxcnc.org/docs/devel/html/config/python-interface.html
* http://gnipsel.com/linuxcnc/uspace/index.html

### Remapping & Tool change 
* http://linuxcnc.org/docs/devel/html/remap/remap.html#remap:interpreter-action-on-m6
* https://forum.linuxcnc.org/10-advanced-configuration/36810-implementing-a-tool-changer-is-classicladder-the-way-to-go?start=10
* https://forum.linuxcnc.org/10-advanced-configuration/4733-rack-tool-changer

### XHC-HB04
* http://linuxcnc.org/docs/html/man/man1/xhc-hb04.1.html
* https://github.com/LinuxCNC/linuxcnc/tree/master/configs/sim/axis/xhc-hb04

### Python / GUI / QTpyVCP / GLADE
* http://linuxcnc.org/docs/2.6/html/common/python-interface.html
* https://qtpyvcp.kcjengr.com/
* http://linuxcnc.org/docs/html/gui/gladevcp.html
* Install GLADE 3.8 on debian 9 https://forum.linuxcnc.org/9-installing-linuxcnc/34719-setting-up-linuxcnc-stretch-uspace-to-build-glade-linuxcnc#112162

### Other configurations
* https://github.com/dremeier/RedDragon_machine (with modified Probe Basic https://github.com/dremeier/probe_basic)
* https://github.com/HendrikRoth/hildegard

### New QTPYVCP based GUI (Which may well be the future GUI to use!)
* https://github.com/kcjengr/probe_basic
* https://kcjengr.github.io/probe_basic/dev_install.html

###
* halcompile for buttonrow: halcompile --install buttonrow.comp
