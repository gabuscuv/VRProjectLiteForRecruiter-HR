// Copyright 2020 Gabriel Bustillo del Cuvillo

#include "ImGuiEventMenuComponent.h"

#if WITH_IMGUI
#include "../../CompatibilityLayer/Macros.h"
#include "../EventUtilites.h"
#include "Libs/magic_enum/include/magic_enum.hpp"
#include <Runtime/Engine/Public/EngineUtils.h>

FDelegateHandle UImGuiEventMenuComponent::ImGuiMultiContextTickHandle;
#endif
// ImGui code
UImGuiEventMenuComponent::UImGuiEventMenuComponent()
{
    #if WITH_IMGUI

        // Techincly Newbish
    if (IsTemplate() && !ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())
	{
		ImGuiMultiContextTickHandle = FImGuiDelegates::OnMultiContextDebug().AddStatic(&UImGuiEventMenuComponent::ImGuiMultiContextTick);
    };
    #endif // WITH_IMGUI
}
#if WITH_IMGUI

void UImGuiEventMenuComponent::BeginPlay()
{
	Super::BeginPlay();
	// Register object's debug delegate in current world context.
    ImGuiTickHandle = FImGuiDelegates::OnWorldDebug().AddUObject(this, &UImGuiEventMenuComponent::ImGuiTick);
}

void UImGuiEventMenuComponent::ImGuiMultiContextTick()
{	
    ImGui::Begin("ImGUI Modules Enabled");
    ImGui::Text("ImGuiEventMenuComponent");
    ImGui::End();
}

void UImGuiEventMenuComponent::ImGuiTick()
{
    EventMenuWindow();
}

// Gaby Dev Notes:
// Hi HR/Recruiter!, I would like highlight this portion of code, 
// because It's something less common than your usual Unreal C++ code because I am using 2 code libraries of different nature
// 1st It's ImGui which is usually a C++ but this time is integrated with a plugin called UnrealImGui (Located in /Plugins/UnrealImGui)
// which use some helper functions like FImGuiDelegates (You can see in the line 21 & 31 of this document)
// 2nd It's magic_enum which is a C++17 library and this is a pure C++ Library (Located in /Source/Lib/magic_enum)
// This shows my ability to use different third-party libraries from differents sources and different proposes.
// (+ I don't there is any tutorial of this two libs and much less together.)

void UImGuiEventMenuComponent::EventMenuWindow()
{
    // ImGui code
    ImGui::Begin("Run Event Window");
    ImGui::Text("Select a Event:");

    if (ImGui::BeginCombo("", std::string(magic_enum::enum_name<EEvents>(eventCurrentCombo)).data(), 0)) 
    {
        for (size_t i = 0; i < magic_enum::enum_count<EEvents>(); i++)
        {
            bool is_selected = (eventCurrentCombo == magic_enum::enum_value<EEvents>(i));
            if (ImGui::Selectable(std::string(magic_enum::enum_name<EEvents>(magic_enum::enum_cast<EEvents>(i).value())).data(), is_selected))  
            {   
                eventCurrentCombo = magic_enum::enum_value<EEvents>(i); 
            };
            
            if (is_selected) { ImGui::SetItemDefaultFocus(); }; 
        };
        ImGui::EndCombo();
    };
        if (ImGui::Button("Run"))
        {
            UEventUtilites::ExecuteEvent(GetWorld(), eventCurrentCombo);
        };

    ImGui::End();
};

void UImGuiEventMenuComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Unregister object's delegate.
	FImGuiDelegates::OnWorldDebug().Remove(ImGuiTickHandle);
}

void UImGuiEventMenuComponent::BeginDestroy()
{
	Super::BeginDestroy();

	// Unregister static multi-context delegate. Failing to do so would result with multiplication of delegates during
	// hot reloading. And we do it only once for the default object to make sure that we unregister only when class is
	// not used anymore.

	if (IsTemplate() && ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())
	{
		FImGuiDelegates::OnMultiContextDebug().Remove(ImGuiMultiContextTickHandle);
		ImGuiMultiContextTickHandle.Reset();
	}
}

#endif // WITH_IMGUI