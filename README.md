# VRProject Partial Release For Recruiter & HR

- [VRProject Partial Release For Recruiter & HR](#vrproject-partial-release-for-recruiter--hr)
  - [Introduction](#introduction)
  - [Libraries, Tools](#libraries-tools)
  - [Unreal C++ & Regular C++](#unreal-c--regular-c)
  - [(VR/Engine/AI/UI) Programmer](#vrengineaiui-programmer)
  - [Tools Programmer](#tools-programmer)
  - [Sound Designer](#sound-designer)
  - [Shaders/Materials](#shadersmaterials)
  - [Assets Modified](#assets-modified)
  - [ThirdParty Assets Used](#thirdparty-assets-used)
  - [Documentation License](#documentation-license)

## Introduction

Hi Recruiter/HR. Welcome to this partial code release.

VR Project from a programming perspective is the most complex project that I made on my own. It's already in the last stage for a beta release as Prototype/Prologue, but there are too many things to polish. (Also this document)

But you can follow the current status of the project by [this page](https://github.com/users/gabuscuv/projects/1)

So my job in this project is as:  

- Gameplay Programmer
- Tools Programmer (As Debugging Tools/Convert Files Format/Continuous Integration)
- UI Programmer (Not Bad)
- Shader/Material Programmer (For basic things ok.)
- Sound Designer (Okish?)
- Writer (An inefficient one?)
- AI Programmer (not a good one, but It's not terrible)

Other People who worked on the project were:

- Andres Castellanos Camacho
  - Graduated (In 1-2 month) as Bachelor's degree in English Philology
    - as Story Script Cleaner/ProofReader for English Language)

## Libraries, Tools

VR Project currently use OpenXR and Unreal Engine 4.27 (Started the project with 4.23 and vendor-based VR Libraries)
and is developed with these third-party libraries:

- Unreal Third-Party Plugins:
  - For Runtime
    - [NVidia Deep Learning SuperSampling (DLSS) - UE4 Plugin](https://developer.nvidia.com/dlss-getting-started#ue-version) By [Nvidia](https://www.nvidia.com/en-us/)
      - Used for improve performance for SuperHigh resolution VR Headsets like HP Reverb G2 or Pimax or improve framerate in "weak" Graphics Cards supported
      - Pending of Registration
    - [AMD FidelityFX™ Super Resolution (FSR) - UE4 Plugin](https://gpuopen.com/unreal-engine/) by [AMD](https://amd.com/)/[GPUOpen](https://gpuopen.com/) - [MIT License](https://github.com/GPUOpen-Effects/FidelityFX-FSR/blob/master/license.txt)
      - Same as Above but for AMD GPUs or no-RTX GPUs
    - [FMODStudio - UE4Integration](https://github.com/fmod/ue4integration) by [Firelight Technologies Pty Ltd](https://www.fmod.com/) - MIT License.
      - Used for improving Audio Design Workflow thanks to their similar appearance to a Digital Audio Workstation and adding features like Pitch Shifter, Random Tracks or just support for Third-Party Plugins like Steam Audio (phonon) and easy to implement to almost every Game Engine.
      - Using Free Indie License. (Revenue: under $200k, Budget: under $500k)
        - As Today (2021/10/28), I have the right to use FMOD Engine, for limited Commercial use as I can explain [here](budgets/budgetandrevenue.md)
      - Pending of Registration
    - [Steam Audio (For FMOD)](https://valvesoftware.github.io/steam-audio/)
      - One of the most powerful advanced HRTF libraries currently for Game Engines, Used for example in Half-Life: Alyx (One of the most blockbuster VR Games at the moment).
    - FMODDialogueIntegration by Gabriel Bustillo del Cuvillo (gabuscuv) - Apache License 2
      - This is a Asset-Type Format Plugin developed by me designed for Dialogues between characters, with Support for Animation Assets and customized Subtitles Formats for distinguishing every character. (Useful for accessibility)
    - [VRExpansionPlugin](https://github.com/mordentral/VRExpansionPlugin/) by [Joshua Statzer (MordenTral)](https://github.com/mordentral) - MIT License
      - When this project started, I should have used this from the beginning.
      I think it is one of the most important libraries from this list,  since it allows me to implement interactive doors, VR Physics in an easy way. Sounds like a joke but [...](https://www.ign.com/articles/putting-doors-in-video-games-is-a-nightmare-say-developers) + for my misfortune the doors that I'm using has IK Bones, So It was required extra tinkering
  - Editor/Debug Builds:
    - [UnrealImGui](https://github.com/segross/UnrealImGui) by [Sebastian Gross (segross)](https://github.com/segross) - MIT License
      - [Imgui](https://github.com/ocornut/imgui) by [Omar Cornut (ocornut)](https://github.com/ocornut) - MIT License
      - Useful for Debugging in realtime without Unreal Editor UI
        - Like events activations or subtitles testing or realtime status display
    - [VMC4UE](https://github.com/HAL9HARUKU/VMC4UE) by [Yutaka Takahashi (HAL9HARUKU)](https://github.com/HAL9HARUKU) - MIT License
      - [Real Repository](https://github.com/ruyo/UnrealEngine_VRM4UPlugin): Requires a linked Epic Games Account - UE4 EULA
      - Powered by [VirtualMotionCapture](https://akira.works/VirtualMotionCapture-en/) & [VMCProtocol](https://protocol.vmc.info/) by [sh-akira](https://akira.works/)
      - This is one of the star plugins for this project.  
          A hacky way but effective and cheap to get MotionCapture (in software-side, because you still need to have Vive Trackers)
    - [VRM4U](https://github.com/ruyo/VRM4U) by [Haruyoshi Yamamoto (Ruyo)](https://github.com/ruyo) - MIT License
      - Allows the use of VRM Avatar required for Motion Capture (For make the tracking accurate, the Skeleton from VMC and target SkeletialMesh must be equal or similar)
      - It could be useful for include a Third-Party Avatar Support via VRoid or .vrm standalone (But It's not planned for the 1.0 version)
    - [ueOSC](https://github.com/HAL9HARUKU/ueOSC/) by [Yutaka Takahashi (HAL9HARUKU)](https://github.com/HAL9HARUKU) - MIT License - I don't know, It's required for VMC4UE but no idea.
- C++ Libs:
  - [magic_enum](https://github.com/Neargye/magic_enum) By [Daniil Goncharov
(Neargye)](https://github.com/Neargye) - MIT License
    - It's a wonderful lib for C++17 when it's used with ImGui allows me to test events in real time without running manually (For Example an In-Game Action). So yeah, It was useful.
  - [FMOD Studio](https://www.fmod.com/legal) by Firelight Technologies Pty Ltd - [FMOD EULA](https://www.fmod.com/legal)
    - See above "FMODStudio - UE4Integration"
- Tools
  - [Arrow (Game Narrative Design Tool)](https://github.com/mhgolkar/Arrow) by [M.H.Golkar (mhgolkar)](https://github.com/mhgolkar)
    - It was quite useful for organizing my ideas about scenes and saves/export to json which is useful for export dialogues to csv with in-house tools for import in UE4 in a way easy. (and the Note Nodes are useful for metadata)

## Unreal C++ & Regular C++

This Project has less C++ than my previous project because of a lack of time.  

I gained some knowledge doing this project in my own way.
However the current C++ code is more about Debugging/Interfaces/Enum than actual Gameplay code and probably has more Regular C++ than Unreal C++ (somehow?).
And a lot of code is already optimized thanks to plugins like "VRExpansionPlugin", So...
A lot of code I wrote in the beginning of this project is somehow deprecated (and removed from this repo).
So This project is more Blueprint code than C++ code (But I don't have any issue porting code from BP to C++, If It's required.)

If It desired read a code with more C++ gameplay code, I would recommend look to [my Enchanted version of Ben Tristem's Exercise](https://github.com/gabuscuv/TestingGrounds-Public)  
It's has some odds decisions like don't use code interfaces for stuff like ammo or health, but It was already based of existent code, So yeah, nowdays, It's not my proudest work.

- [Using different libraries from different environment (UnrealImgui and magic_enum)](https://github.com/gabuscuv/VRProjectLiteForRecruiter-HR/blob/132c254b7358d6d55318b9084b033934f7afa85f/Source/VRProject/Utils/ImGUIComponents/ImGuiEventMenuComponent.cpp#L46)  
- [Casting between Regular C++ and Unreal C++](https://github.com/gabuscuv/VRProjectLiteForRecruiter-HR/blob/132c254b7358d6d55318b9084b033934f7afa85f/Source/VRProject/Utils/ImGUIComponents/ImGuiSubtitlesMenuComponent.cpp#L56)
- [Deprecated (for this project) but A useful explanation about how deal manually with HiddenActors but visible for SceneCaptureComponent in a direct/dynamic way](https://github.com/gabuscuv/VRProjectLiteForRecruiter-HR/blob/132c254b7358d6d55318b9084b033934f7afa85f/Source/VRProject/Utils/CameraUtilities.cpp#L7)

## (VR/Engine/AI/UI) Programmer

Almost every gif has a long version on youtube (click them!)

- [VAR (Virtual Augmented Reality)](https://youtu.be/k5hOyNus8ls)
  - [![VAR (Virtual Augmented Reality)](media/gifs/varloop.gif)](https://youtu.be/k5hOyNus8ls)

- [Cartridges](https://youtu.be/IPy99RJQ3Gk)
  - [![Cartidges](media/gifs/loop_cartridge.gif)](https://youtu.be/IPy99RJQ3Gk)

- [AI Behaviour + Animation Execution](https://youtu.be/mCGH3SsXQoI)
  - [![AI Behaviour + Animation Exectution](media/gifs/loop_aianimation.gif)](https://youtu.be/mCGH3SsXQoI)
  - The Animation played is made with MotionCapture (in-house made)

- Domotic Stairs
  - ![Domotical](media/gifs/loop_stairs.gif)

- [Multi-floor Teleport (Custom Filter NavMesh Teleport Query)](https://youtu.be/rBtKMLIUUpk)
  - [![Multi-Floor Teleport](media/gifs/loop_teleport.gif)](https://youtu.be/rBtKMLIUUpk)
  - Full Video Includes Opening Doors and Unlock Keypad Door System!!

- Highlight VR Buttons
  - ![Highlight VR Buttons](media/gifs/loop_vrbuttonhighlight.gif)

- [VR Subtitles Support (old gif/video) + Event System](https://youtu.be/rmqDWQGdOsQ)
  - [![VR Subtitles Support (old gif/video)](media/gifs/subtitles.gif)](https://youtu.be/rmqDWQGdOsQ)

- Domotic System (Disconnected) + CloudServices (HackingSystem/HelpSystem) (Old Gif)
  - ![DomoticSystem](media/gifs/loop_hacking.gif)

- [Async Level Streaming (Away from PlayerView)](https://youtu.be/tU3DUaHLQH4)

- Blueprint Example Code:
  - WBP_CameraPanel
    - https://blueprintue.com/blueprint/n4_4lrhd/

This video does not represent the current status of the project.
[A Quite old video about ASync Level Loading](https://www.youtube.com/watch?v=HB8qTsk-pT0)

## Tools Programmer

- Tools/Scripts
  - [ArrowDialogueParser](https://github.com/gabuscuv/ArrowDialogueParser)
  - [UE4 Toolkit](https://github.com/gabuscuv/UE4-Toolkit-Public)
- You can see these ones [above.](##vrengineaiui-programmer)
- For UE4Editor:
  - EventCheckingToolkit
  - HighlightButtonChecker

- For ImGUI/UE4
  - [ImGuiEventMenuComponent](https://github.com/gabuscuv/VRProjectLiteForRecruiter-HR/blob/main/Source/VRProject/Utils/ImGUIComponents/ImGuiEventMenuComponent.cpp)
  - [ImGuiSubtitlesMenuComponent](https://github.com/gabuscuv/VRProject-filtered/blob/main/Source/VRProject/Utils/ImGUIComponents/ImGuiSubtitlesMenuComponent.cpp)

## Sound Designer

[Dynamic Music with SFX Sounds - Alpha](https://www.youtube.com/watch?v=L6tU6rDpSUA)

## Shaders/Materials

- Holograph Shader
  - In Editor (with debugtime)
    - ![Holograph Shader InEditor](./media/gifs/loop_0.gif)
  - In Game
    - ![Holograph Shader InGame](./media/gifs/loop_2.gif)
- Highlight VR Buttons from VR Controllers
  - In Game
    - ![Highlight VR Buttons InGame](./media/gifs/loop_6.gif)
- Time Paradox Shader
  - In Editor
    - ![Time Paradox Shader InEditor](./media/gifs/loop_1.gif)
  - In Game (unlit lights)
    - ![Time Paradox Shader InGame](./media/gifs/timeparadox.gif)

## Assets Modified

- HQ_ResidentialHouse (Differences between originals and modded)
  - <https://cdn.knightlab.com/libs/juxtapose/latest/embed/index.html?uid=587899a6-3a80-11ec-abb7-b9a7ff2ee17c>
  - <https://cdn.knightlab.com/libs/juxtapose/latest/embed/index.html?uid=74c4c368-3a81-11ec-abb7-b9a7ff2ee17c>
  - Made with Blender

## ThirdParty Assets Used

- Wallace From MetaHumans service provided by Epic Games via Quixel
- Assets from Quixel MegaScans (Using [Unreal Unlimited](https://help.quixel.com/hc/en-us/sections/360000977797-Unlimited-Access-for-Unreal-Engine) License)
  - Decals
    - [Blood Stain (shemcaac)](https://quixel.com/assets/shemcaac)
    - [Hand Smear (se0wefxp)](https://quixel.com/assets/se0wefxp)
  - Textures
    - [Cut Grass (sfenffsa)](https://quixel.com/assets/sfenffsa)
    - [Fine Road (viciaalew)](https://quixel.com/assets/viciaalew)
    - [Marble Checkered Floor (sescnen)](https://quixel.com/assets/sescnen)
    - [Three Strand Manila Rope (ulztacqs)](https://quixel.com/assets/ulztacqs)
    - [Patterned Marble Tiles (vf5lecjv)](https://quixel.com/assets/vf5lecjv)
  - Props
    - [Wooden Table (vghpabdga)](https://quixel.com/assets/vghpabdga)
    - [Wooden Table (ukphdffaw)](https://quixel.com/assets/ukphdffaw)
    - [Old Metal Stool (ukknbeyaw)](https://quixel.com/assets/ukknbeyaw)
    - [Wodden Standing Coat Hanger (ukknbhgbw)](https://quixel.com/assets/ukknbhgbw)
    - [Electrical Box (ujyqaelga)](https://quixel.com/assets/ujyqaelga)
  
- Under [Unreal Marketplace EULA](https://www.unrealengine.com/en-US/marketplace-distribution-agreement)
  - [HQ_ResidentialHouse](https://www.unrealengine.com/marketplace/en-US/product/hq-residential-house) by [NotLonely](https://not-lonely.com/)
    - Assets Modded by me - Require original assets license & access to my private modded assets repo
  - [ProIconPack](https://www.unrealengine.com/marketplace/en-US/product/pro-icon-pack) by [Piontek](dominikgeuer.com)
  - [GenericNPCAnimPack](https://www.unrealengine.com/marketplace/en-US/product/generic-npc-anim-pack) by Siarhei Chekolian
  - [Drivable Cars Basic Pack: 3D assets and Blueprints](https://www.unrealengine.com/marketplace/en-US/product/driveable-cars-basic-pack) by [Digital Dive Studio](http://en.digitaldivestudio.com/)
    - The Blueprints assets are modified to fix some fault programming design and integration on the project
  - [SDF Robo Progress Bars](https://www.unrealengine.com/marketplace/en-US/slug/sdf-robo-progress-bars) by [Krystian Komisarek](http://imaginaryblend.com/kontakt/)

- Under [GameDevMarket PRO EULA](https://static.gamedevmarket.net/terms-conditions/#pro-licence)
  - From Humble Music & Sound Effects for Games, Films, and Content Creators Bundle Part 2
    - [User Interface Sound FX SciFi Tech](https://www.gamedevmarket.net/asset/user-interface-sound-fx-scifi-tech/) by [TomWinandySFX](https://www.gamedevmarket.net/member/tomwinandysfx/)
    - [Background Ambience City](https://www.gamedevmarket.net/asset/background-ambience-city/) by [B. Patrick](https://bpatrickvoice.wixsite.com/mysite)
    - [Interface and Item Sounds](https://www.gamedevmarket.net/asset/interface-and-item-sounds-8616/) by [Estúdio Cafofo](http://www.cafofomusic.com/)
    - [(Unused?) Anime Comedy Sound Effect Pack](https://www.gamedevmarket.net/asset/anime-comedy-sound-effect-pack/) by [WOW Sound](https://wowsound.com/)

## Documentation License

 [VRProject Partial Release For Recruiter & HR Documentation](README.md) © 2021 by [Gabriel Bustillo del Cuvillo (gabuscuv)](https://www.linkedin.com/in/gabuscuv/) is licensed under [CC BY-NC-ND 4.0](http://creativecommons.org/licenses/by-nc-nd/4.0/?ref=chooser-v1)
