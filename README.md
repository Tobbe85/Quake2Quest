Quake2Quest
==========

**A Team Beef VR port** bringing the classic Quake 2 to standalone VR headsets — a full 6DoF, room-scale implementation of the Quake 2 engine, built on top of [Yamagi Quake 2](https://www.yamagi.org/quake2/).

Built on the open **OpenXR** standard, it supports both Meta and Pico devices:

* Meta Quest 2, Quest 3 and Quest Pro
* Pico Neo 3 and Pico 4

Older devices (the original Oculus Quest) are no longer supported.

For more from Team Beef, see [teambeefvr.com](https://www.teambeefvr.com).

The easiest way to install this on your Quest is using SideQuest, a Desktop app designed to simplify sideloading apps and games ( even beat saber songs on quest ) on Standalone Android Headsets like Oculus Quest and Oculus Go. It supports drag and drop for installing APK files!

Download SideQuest here:
https://github.com/the-expanse/SideQuest/releases



IMPORTANT NOTE
--------------

This is just an engine port; though the apk does contain the shareware version of Quake2, not the full game. If you wish to play the full game you must purchase it yourself, steam is most straightforward:  https://store.steampowered.com/app/2320/QUAKE_II/


Copying the Full Game PAK files to your Oculus Quest
----------------------------------------------------

Copy the PAK files from the installed Quake2 game folder on your PC to the /Quake2Quest folder on your Oculus Quest when it is connected to the PC. You have to have run Quake2Quest at least once for the folder to be created and if you don't see it when you connect your Quest to the PC you might have to restart the Quest.



Caveats
-------

This version of Quake2Quest is now updated and based on the excellent Yamagi Quake 2 Engine (https://www.yamagi.org/quake2/). The original project this port is _very_ loosely based on the Quake 2 port created by Stefan Welker for the Open Dive VR headset (https://www.durovis.com/en/opendive.html), however that build has been deprecated.


WARNING:  There is a good chance that unless you have your VR-legs this will probably make you feel a bit sick. The moment you start to feel under the weather YOU MUST STOP PLAYING for a good period of time before you try again. I will not be held responsible for anyone making themselves ill.


Controls
--------

All these controls are for right-handed mode, select left handed controls in the options menu and all buttons/sticks/controls will be switched:

* Open the in-game menu with the left-controller menu button (same irrespective of right/left handed control)
* A Button - Crouch
* B Button - Jump
* Y Button - Show inventory screen (use up and down on the right stick to select inventory item and fire to select)
* X Button - Show the "Help Computer" whilst X is pressed
* Dominant-Hand Controller - Weapon orientation
* Dominant-Hand Thumbstick - left/right Snap turn, up/down weapon change
* Dominant-Hand Thumbstick click - change the laser-sight mode on/off
* Dominant-Hand Trigger - Fire
* Dominant Grip Button - Not used
* Off-Hand Controller - Direction of movement (or if configured in config.cfg HMD direction is used)
* Off-Hand Thumbstick - locomotion
* Off-Hand Trigger - Run
* Off-Hand Grip Button - Weapon Stabilisation - with the machine gun this will reduce the scatter of the projectiles
* Off-Hand Thumbstick click - If cheats are enabled then this will give you ALL pickups/weapons



Things to note / FAQs:
----------------------

* Mods and Texture packs *do now work*
* The Original Soundtrack in OGG format *does now work too*!
* Multiplayer is unlikely to work very well, if at all I'm afraid. I explain reasons why can be seen here (they apply to this as well as Lambda1VR):  https://www.reddit.com/r/Lambda1VR/comments/dtutnx/so_whats_with_the_head_aiming_in_multiplayer/
* The folder into which the pak files from the full game and other things like mods and the OST shoud be copied is now called _Quake2Quest_, this is to avoid collision with the older configuration files for the previous version, it also means if you did prefer the vanilla version, you can roll back and all your saves will be intact.

Notes for Users of First released Version
-----------------------------------------

The 2nd release of Quake2Quest updates the underlying engine to Yamagi. This has a number of benefits including but not limited to modding, music support and a reworked save system. However as previously mentioned save files will not be compatible between these two versions. Moving forward any updates to the application will not break save files. To avoid conflicts and to also allow you to revert to the original version should you feel it necessary, there is a new file structure. If you have copied across the full game this will need to be redone. Complete list of installation instructions below:

1) Install the game via SideQuest or by downloading and installing the APK file
2) Run the game once
3) If you own a legal copy of Quake 2, you should copy all .pak files from baseq2 to the newly created Quake2Quest folder on your Quest. 
Optional:
4) If you wish to enjoy the Quake 2 soundtrack you can place the relevant OGG files in the folder Quake2Quest/music.

Known Issues:
-------------

* Left-handed laser sight is still not aligned correctly, I will fix at some point
* Any save games from the previous version will *NOT* work, this is due to the engine change. 
* As mentioned, multiplayer probably doesn't work very well at all, if at all..


Credits:
--------

The game includes Hi Res textures, skins and items previously collected by the user Realistic. We could not find the original author of these weapons, nor does the pack include any licensing at all. If you are the author of these textures please feel free to contact us and we would be happy to credit you or remove.

I would like to thank the following teams and individual for making this possible:

* Emile Belanger - For advice regarding converting the Android build of Yamagi. See his other Android ports [here](http://www.beloko.com/)
* [The Yamagi Team](https://www.yamagi.org/quake2/) - For the excellent engine this based upon.
* [Fighterguard](https://github.com/fighterguard) - For contributing the weapon and item selection wheels (and the option to enable/disable them)
* [Tobbe85](https://github.com/Tobbe85) - For Pico headset support (controls, permissions and the weapon wheel), the laser sight, the cheats menu, turn options and various menu and head-tracking improvements
* The [SideQuest](https://sidequestvr.com/#/news) team - For making it easy for people to install this
* [gl4es](https://github.com/ptitSeb/gl4es) for the OpenGL -> OpenGL ES 2 translation: without which this project wouldn't have worked at all
* The [Khronos Group](https://github.com/KhronosGroup/OpenXR-SDK) for the OpenXR SDK that now drives headset and controller tracking


Building:
---------

The project is a self-contained Gradle build using the Khronos OpenXR loader. You need the following:

* Android Studio
* Android SDK Platform API level 29
* Android NDK r26 (the build is pinned to NDK `26.1.10909125`)

To build:

1) Clone this repository anywhere on disk.
2) In `Projects/Android`, create a `local.properties` file containing an `sdk.dir` property pointing at your Android SDK location, e.g. `sdk.dir=C:\\Users\\you\\AppData\\Local\\Android\\Sdk`. (Android Studio will create this for you when you open the project.)
3) Open `Projects/Android` in Android Studio, or build from the command line:

```
cd Projects/Android
./gradlew assembleDebug      # debug APK
./gradlew assembleRelease    # release APK
./gradlew installDebug       # build and install to a connected headset over adb
```

The resulting APKs are written to `Projects/Android/build/outputs/apk/`. Only the `arm64-v8a` ABI is built.

Debug builds are signed automatically with the checked-in `android.debug.keystore` (located in `Projects/Android`). For a release build with your own key, pass `-Pkey.store=...`, `-Pkey.store.password=...`, `-Pkey.alias=...` and `-Pkey.alias.password=...` to Gradle.
