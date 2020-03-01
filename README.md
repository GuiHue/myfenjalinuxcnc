# myfenjalinuxcnc
This repository contains the latest stable version of my LinuxCNC configuration for my CNC Router aptly named groot. It is based on LinuxCNC Master (currently 2.9pre).

The CNC router's design is based on "Fenja" created by A. Koch of [fraeserbruch.de](https://fraeserbruch.de/ "Fenja's home"). Plans and parts are available through him. The design offers various sizes to choose from and requires the owner to chose drives, spindle and control. Furthermore, it is supported by a great community. I highly recommend Andrea's work.

All of the config options presented here are applicable to any CNC router design.

The purpose of this GIT is to have a repo for my own changes to the config. However, as the same questions pop up time and again in various communities, I have chosen to make this configuration public. Note, that LinuxCNC HAL and INI files are very specific to individual machines. While the deployed concepts can be transfered easily, specific values and hardware pins are to be analyzed carefully. Do not ever run a foreign config on your machine without checking every detail beforehand. I strongly recommend taking ideas from other configs and integrating those into to your own. If you need a minimum working example to start with, I recommend trying the [PNCConf Wizard](http://linuxcnc.org/docs/html/config/pncconf.html) when running MESA cards. I will not take responsibility for any damages to your hardware or person.

## Features
* Based on MESA card model 7i76E
* Runs on LinuxCNC 2.9 with Debian 9 (uses linuxcnc master branch)
* Uses GMOCCAPY GUI in version 3.x with a touch screen
* Connects via modbus to an Hitachi WJ-200 VFD to control a Jianken JGL80/2.2-R24-20 ATC spindle with ISO20 toolholders
* Tool change is currently done via manual tool handling and using a push button to toggle between valve settings for release and clamp. LUT5 is used to check whether spindle is enabled (=turning) or not
* Uses NC inductive limit switches on each axis and furthermore uses these for homing
* Connects LinuxCNC to a PILZ safety relais using the relais' semi conductor (Y32) output. This triggers estop in linuxcnc when a hardware button is pushed and cuts power to the drives.  
* Uses an XHC-HB04 wireless pendant with slightly modified key mapping
* Uses probe_screen_v2 (see [probe_screen_v2](https://github.com/verser-git/probe_screen_v2)) together with a wireless touch probe by [vers.by](https://vers.by/en) and a wire based tool length sensor at a fixed location on the machine table
* Includes fixed macros and probe_screen.py for use with LinuxCNC 2.8/ 2.9 (dealing with joint/axis changes and changes to command.jog in LinuxCNC Python interface; seperate fork can be found on [github](https://github.com/GuiHue/probe_screen_v2))
* Uses JMC iHSV57xxx servos on X and Y axis; JMC Closed Loop Stepper on Z, run as stepper drives with STP/DIR signals from the MESA stepgens
** Note that IHSV57 with software v5xx is used on X axis and software v604 is used on y axis
** Further note, that the timings (provided in ns) are slightly different. v604 appears to require longer timings
* Controls various relais using MESA DO depending on the present machine condition
* Controls various 3/2 valves using  MESA DO within pneumatic setup
* Checks a Festo 527467 pressure sensor (NC) and triggers a warning message when pressure drop is registered
* Provides an additional GLADE embedded tab "SpindleUI" with various information regarding spindle and ATC status

## Notes
* Common errors with probe_screen:
* Funny offset issues will arise, when gmoccapy tool change functions are still activated in gmoccapy settings while using probe_screen. Gmoccapy settings can be changed at the approriate place in the menu
  
## Hardware
* The machine consists of an aluminum extrusion design with some milled components made from plate material.
* Working envelope roughly X/Y/Z 635/1240/165 mm

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
