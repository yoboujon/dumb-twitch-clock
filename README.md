# Dumb Twitch Clock
![Dtc](/resources/TwitchDumbClock_banner.png)
### Goal
This app is not this useful because OBS now integrates in itself a clock. But I made this project to train myself into programming!
The most important part is that the app is working, right?

The app main goal is to create a text file that can be displayed inside OBS. It will count time for your viewers to see !
# How to use it
First, start the program and insert the hours, minutes and seconds you want your clock to run. Minutes and seconds can't go more than 60.
A prompt will ask you if you are sure, then it proceeds what it had to furfill !

Now, inside OBS create a new Text (GDI+) and check **Read from file**, a file named "dtc.txt" will be created and will generate the clock for you.
# Build my Project [Windows]
First things first you need multiple programs to actually build this program :
- Cmake : https://cmake.org/download/
- G++/Gcc : https://www.msys2.org/ or https://www.mingw-w64.org/downloads/#cygwin

Then to build this project I recommend you to create a file named _**build**_ in the root of the project, once there start a command prompt and type :
> cmake ..

> cmake --build . --config Release

Once this done you can enjoy modifying my code and try different things !

*NB : you can modify the config release by typing Debug instead*

> *Wrote with https://markdownlivepreview.com/*