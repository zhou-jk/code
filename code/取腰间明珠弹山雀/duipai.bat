@echo off
:loop

make_data
bird
bird_duipai

fc bird.out bird_duipai.out
if %errorlevel%==1 pause

goto loop