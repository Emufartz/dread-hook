# dread-hook
A Metroid Dread Practice Mod intended to remove some of the tedium of practicing and discovering tricks used in speedrunning.

# Features
This list of features is in no particular order and was last updated for version 0.3.
 Button Combos(All Button Combos need DPAD Down held unless specified):
 - Toggle Cool Spark Camera (when shinesparking): A + B
 - Toggle Instant Speed Booster (when you click the stick): X + Y
 - Toggle Room IL (teleports you to the stored room entrance when you run through any door transition): ZL + Click RStick
 - Overwrite stored (Room IL) entrance with next transition: ZR + Click RStick
 - Teleport To Stored Position (seperate from Room IL): R + Click RStick
 - Store Current Position: L + Click RStick
 - Teleport To Map Cursor (doesn't check if you are paused for now): R + ZR
 - Toggle Turbo (pauses the game for a second and turbos whatever buttons you held after): DPAD Up (doesn't need DPAD Down)
 - Toggle Freeze Frame (doesn't work on console for now): X + A
 - Frame Advance (process exactly 1 frame, this waits 300ms to allow you to release/press what keys you want processed for <b>this frame</b>): Y + A

# Upcoming Features
These are features I haven't yet added functionality for but do have the required offsets and capabilities to add:
 - Infinite HP, Missiles, and Power Bombs
 - Simulate if the player has IFrames (intagibility)
 - Simulate if the player has KnockbackFrames (same damage resistances as from IFrames but still takes knockback from hits as normal)
 - Disable Morph Ball Gravity (for funsies)
 - Disable Morph Ball Drag (same level of air and ground control as if you were mid bomb jump, also for funsies)
 - Disable All Forms Of Damage (the same flag is set as with the EMMI Door glitch in v1.0)
 - Adjust Skew angle on the fly
 - Toggle for ignoring OOB deaths

I also have the offsets for Samus' X and Y velocities for morph and unmorphed states. But I can't think of something cool to use this for.

Misc:
 - Disabled out of bounds deaths: you will not instantly die when inside of blocks or otherwise outside the "intended play area™". A combo will be added for this soon. Currently defaults to enabled

# Note
This project is a work in progress. Some features look like garbage, some of them have missing functionality.

# Credit
- Atmosphère: A great reference and guide.
- [libnx](https://github.com/switchbrew/libnx/) provides countless tools and documents that helped in the development of this mod
- [Exlaunch](https://github.com/shadowninja108/exlaunch/) by [@shadowninja108](https://github.com/shadowninja108/) used as the base of this mod (License [here](https://github.com/shadowninja108/exlaunch/LICENSE)).
