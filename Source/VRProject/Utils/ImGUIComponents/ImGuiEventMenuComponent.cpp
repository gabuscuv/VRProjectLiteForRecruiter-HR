#include "ImGuiEventMenuComponent.h"

#if WITH_IMGUI
#include "../../CompatibilityLayer/Macros.h"
#include "../EventUtilites.h"
#include "Libs/magic_enum/include/magic_enum.hpp"
#include <Runtime/Engine/Public/EngineUtils.h>

FDelegateHandle UImGuiEventMenuComponent::ImGuiMultiContextTickHandle;
// ImGui code
UImGuiEventMenuComponent::UImGuiEventMenuComponent()
{

        // Techincly Newbish
    if (IsTemplate() && !ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())
	{
		ImGuiMultiContextTickHandle = FImGuiDelegates::OnMultiContextDebug().AddStatic(&UImGuiEventMenuComponent::ImGuiMultiContextTick);
    };
}


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