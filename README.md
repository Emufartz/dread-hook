# dread-hook
A Metroid Dread Practice Mod intended to remove some of the tedium of practicing and discovering tricks used in speedrunning.

# Features
This list of features is in no particular order and was last updated for version 0.5.
 Button Combos(All Button Combos need DPAD Down held unless specified):
 - Toggle Noclip (use Right Stick to fly around): (Only) L + DPAD Left
 - Return to Noclip start position: (Only) L + DPAD Right
 - Toggle Out of Bounds Deaths: Click LStick
 - Fully Restore Health and Missiles: Minus
 - Toggle Cool Spark Camera (when shinesparking): A + B
 - Toggle Instant Speed Booster (when you click the stick): X + Y
 - Toggle Room IL (teleports you to the stored room entrance when you run through any door transition): ZL + Click RStick
 - Overwrite stored (Room IL) entrance with next transition: ZR + Click RStick
 - Toggle IL Gauntlet (allows setting a specific door that teleports you back to the Room IL door): Y + Click RStick
 - Overwrite stored (IL Gauntlet) "finish line" with next door: X + Click RStick
 - Teleport To Stored Position (seperate from Room IL): R + Click RStick
 - Store Current Position: L + Click RStick
 - Teleport To Map Cursor (doesn't check if you are paused for now): R + ZR
 - Decrease or Increase game speed: (Only) R + DPAD Left(-) or Right(+)
 - Reset game speed to normal: (Only) R + Minus
 - Toggle Turbo (pauses the game for a second and turbos whatever buttons you held after): DPAD Up (doesn't need DPAD Down)
 - Toggle Freeze Frame: X + A
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
 - Instantly kill the player (if you are stuck or something)
 - Kill the current EMMI, Boss, or visible enemies
 - Gain all items at once (working on making items togglable before adding this. As there is no choice of which items you want/don't want)
 - Set the games framerate (still locked to 60fps)

I also have the offsets for Samus' X and Y velocities for morph and unmorphed states. But I can't think of something cool to use this for.

# Note
This project is a work in progress. Some features look like garbage, some of them have missing functionality.

#Need help?
Message me on discord @phazonjunky

# Credit
- Atmosphère: A great reference and guide.
- [libnx](https://github.com/switchbrew/libnx/) provides countless tools and documents that helped in the development of this mod
- [Exlaunch](https://github.com/shadowninja108/exlaunch/) by [@shadowninja108](https://github.com/shadowninja108/) used as the base of this mod (License [here](https://github.com/shadowninja108/exlaunch/LICENSE)).
