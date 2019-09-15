[XHC_HB04_BUTTONS]
# use button names according to layout file LIB:xhc-hb04-layout{n}.cfg
# note: "start-pause" is connected for standard behavior
#        controlling halui.pause/halui.resume/halui.run
# these are examples, edit as required:

goto-zero   = halui.mdi-command-00
# synthesized per-axis buttons for goto-zero button:
goto-zero-x = ""
goto-zero-y = ""
goto-zero-z = ""
#goto-zero-a = ""

start-pause = std_start_pause
rewind      = halui.program.step
# probe-input for simulating a probe:
#probe-z     = motion.probe-input
macro-3     = halui.mdi-command-03

#half        = halui.mdi-command-16
half        = halui.spindle.0.stop
                                                                                                       
# synthesized per-axis buttons for half button:
half-x      = ""
half-y      = ""
half-z      = ""
#half-a      = ""

zero        = ""
# synthesized per-axis buttons for zero button:
zero-x      = halui.mdi-command-12
zero-y      = halui.mdi-command-13
zero-z      = halui.mdi-command-14
#zero-a      = halui.mdi-command-15

safe-z      = halui.mdi-command-10
home        = halui.home-all
macro-1     = halui.mdi-command-01
macro-2     = halui.mdi-command-02
macro-3     = halui.mdi-command-04 

spindle     = halui.spindle.0.forward

step        = xhc-hb04.stepsize-up
# go back to manual mode/ useful when probing
mode        = halui.mode.manual
macro-6     = halui.mdi-command-06
macro-7     = halui.mdi-command-07
stop        = halui.program.stop
reset       = halui.estop.activate

[HALUI]
# these are examples, edit as required:
# a halui hal pin is created for each MDI_COMMAND below
# halui.mdi-command-00, halui.mdi-command-01,... etc
# these are the first definitions of MDI_COMMAND in this config
#0
MDI_COMMAND=G53 G0 X0 Y0 Z0
#1 Turn on MIST M7
MDI_COMMAND=M7
#2 Turn on Flood M8
MDI_COMMAND=M8
#3 Turn off aux M9
MDI_COMMAND=M9
#4 
MDI_COMMAND=(debug, example: mdi-04)
#5
MDI_COMMAND=(debug, example: mdi-05)
#6
MDI_COMMAND=(debug, example: mdi-06)
#07 
MDI_COMMAND=(debug, example: mdi-07)
#8
MDI_COMMAND=(debug, example: mdi-08)
#9
MDI_COMMAND=(debug, example: mdi-09)
#10 safe z in g53
MDI_COMMAND=G53 G01 z0 f1000
#11
MDI_COMMAND=(debug, example: mdi-11)
#12
MDI_COMMAND= G10 L20 P0 X0
#13
MDI_COMMAND= G10 L20 P0 Y0
#14
MDI_COMMAND= G10 L20 P0 Z0
#15
MDI_COMMAND= G10 L20 P0 C0
#16
MDI_COMMAND= M3 S300
#17
MDI_COMMAND= M5