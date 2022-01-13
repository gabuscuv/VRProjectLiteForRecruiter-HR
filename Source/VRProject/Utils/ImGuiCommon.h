#pragma once

#if UE_BUILD_DEBUG
#ifdef IMGUI_API
#define WITH_IMGUI 1
#else
#define WITH_IMGUI 0
#endif // IMGUI_API
#else
#define WITH_IMGUI 0
#endif // UE_BUILD_DEBUG

#if WITH_IMGUI
#include <ImGuiModule.h>
#include <ImGuiDelegates.h>
#include <imgui.h>
#endif