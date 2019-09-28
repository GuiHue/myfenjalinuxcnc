# myfenjalinuxcnc
This repository holds the latest stable version of my LinuxCNC configuration for my CNC Router. It follows LinuxCNC Master (at the time of creation 2.8).

The CNC router's design is based on "Fenja" created by A. Koch of [fraserbruch.de](https://fraeserbruch.de/ "Fenja's home"). Plans and parts are available through him. The design offers various sizes to choose from and requires the owner to chose drives, spindle and control. Furthermore, it is supported by a great community. 

All of the config option presented here are applicable to any CNC router design.

The purpose of this GIT is to have a repo for my own changes to the config. However, as the same questions pop up time and again in various communities, I have chosen to make this public. Note, that LinuxCNC HAL and INI files are very specific to each machines. While the deplyoed concepts can be trrasnfered easily, specific values and hardware pins are to be analyzed carefully. Do not ever run a foreign config on your machine without checking every detail before hand. I strongly recommend taking ideas from other configs and integrating those into to your own. If you need a minimum working example to start with, I recommend trying the [PNCConf Wizard](http://linuxcnc.org/docs/html/config/pncconf.html) when running MESA cards. I will not take responsibility for any damages to your hardware or person.

A word on licensing: I habe chosen GPL3.0 as the license, hoping it does not interfer with any other licenses the used components are subject to. Please contact me asap if this is the case so that this can be resolved.

## Features
* Based on MESA 7i76E
* Runs on LinuxCNC 2.8 with Debian 9 (actually operates on master branch)
* Uses GMOCCAPY GUI in version 3.x with a touch screen
* Connects to an Hitachi WJ-200 VFD to control a typical "China Spindle" with 2.2 kW as it's readily available by various suppliers 
* Uses NC inductive limit switches on each axis and furthermore uses these for homing
* Connects LinuxCNC to als PILZ safety relais using the relais' semi conductor (Y32) output. THis triggers estop in linuxcnc when a hardware based button is pushed and cuts power to various drives.  
* Uses an XHC-HB04 wireless pendant with slightly modified key mapping
* Uses probe_screen_v2 (see [probe_screen_v2](https://github.com/verser-git/probe_screen_v2)) together with a wireless touch probe by [vers.by](https://vers.by/en) and a wirebased tool length sensor
..** Includes fixed macros and probe_screen.px for use with LinuxCNC 2.8 (dealing with joint/axis changes and changes to command.jog in LinuxCNC Python interface; seperate fork can be found on [github](https://github.com/GuiHue/probe_screen_v2))
* Uses JMC iHSV57xxx servos on X and Y axis; JMC Closed Loop Stepper on Z, run as stepper drives with STP/DIR signals
* Controls various relais depending on the present machine condition
* Controls various 3/2 valves from MESA DO within pneumatic setup
* Checks a Festo 527467 pressure sensor (NC) and triggers a warning message when pressure drop is registered

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
+ http://linuxcnc.org/docs/devel/html/config/python-interface.html

### Remapping & Tool change 
* http://linuxcnc.org/docs/devel/html/remap/remap.html#remap:interpreter-action-on-m6
* https://forum.linuxcnc.org/10-advanced-configuration/36810-implementing-a-tool-changer-is-classicladder-the-way-to-go?start=10
* https://forum.linuxcnc.org/10-advanced-configuration/4733-rack-tool-changer

### XHC-HB04
* http://linuxcnc.org/docs/html/man/man1/xhc-hb04.1.html
* https://github.com/LinuxCNC/linuxcnc/tree/master/configs/sim/axis/xhc-hb04


### Python / GUI / QTpyVCP / GALDE
* http://linuxcnc.org/docs/2.6/html/common/python-interface.html
* https://qtpyvcp.kcjengr.com/
* http://gnipsel.com/linuxcnc/uspace/index.html
* http://linuxcnc.org/docs/html/gui/gladevcp.html
