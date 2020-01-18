@echo off
:loop

make_data
white
white_duipai

fc white.out white_duipai.out
if %errorlevel%==1 pause

goto loop