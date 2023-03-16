#include "ImGuiSubtitlesMenuComponent.h"

#if WITH_IMGUI
#include "../../CompatibilityLayer/Macros.h"
#include <Runtime/Engine/Public/EngineUtils.h>
#include "Kismet/GameplayStatics.h"

#include "../../Interfaces/SubtitleExecute.h"

FDelegateHandle UImGuiSubtitlesMenuComponent::ImGuiMultiContextTickHandle;
// ImGui code
UImGuiSubtitlesMenuComponent::UImGuiSubtitlesMenuComponent()
{
    if(IsTemplate() && !ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())    
    {
        ImGuiMultiContextTickHandle = FImGuiDelegates::OnMultiContextDebug().AddStatic(&UImGuiSubtitlesMenuComponent::ImGuiMultiContextTick);
    }

}

void UImGuiSubtitlesMenuComponent::BeginPlay()
{
	Super::BeginPlay();
    ImGuiTickHandle = FImGuiDelegates::OnWorldDebug().AddUObject(this, &UImGuiSubtitlesMenuComponent::ImGuiTick);
	// Register object's debug delegate in current world context.
}

void UImGuiSubtitlesMenuComponent::ImGuiMultiContextTick()
{	
    ImGui::Begin("ImGUI Modules Enabled");
    ImGui::Text("ImGuiSubtitlesMenuComponent");
    ImGui::End();
}

void UImGuiSubtitlesMenuComponent::ImGuiTick()
{
    EventMenuWindow();
}

void UImGuiSubtitlesMenuComponent::EventMenuWindow()
{
    // ImGui code
    ImGui::Begin("Send Subtitles Window");
    ImGui::Text("Subtitles: ");
    ImGui::InputText("", InputBuf, IM_ARRAYSIZE(InputBuf));
    ImGui::Text("Duration: ");
    ImGui::InputText("d", InputBuf2, IM_ARRAYSIZE(InputBuf2));

        if (ImGui::Button("Run"))
        {
            FAdvancedSubtitleCue cue;
            TArray<FAdvancedSubtitleCue> test;
            // Gaby Dev Notes:
            /*
                Hi HR/Recruiter, This portion of the code is interesting because
                I'm dealing with transform C++ types (for example char[]) to Unreal C++ (FString)
                This is important because there are some libraries doesn't work in the way that Unreal does.
                because they are more Regular C++ than Unreal C++
                This shows my abilities to deal with uncommon macros and use differents variable types from Unreal Environment.
            */
            cue.Text=FText::FromString(FString(ANSI_TO_TCHAR(InputBuf)));
            cue.Time=std::atof(InputBuf2);
            cue.bOverride=true;
            test.Push(cue);
            TArray<AActor*> Array;
            UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USubtitleExecute::StaticClass(), Array);
            for (auto& actor : Array)
            {
                ISubtitleExecute::Execute_PushSubtitles(actor,test);
            };
            //    SubtitlesPushDelegate.Broadcast(test);
        };

    ImGui::End();
};

void UImGuiSubtitlesMenuComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Unregister object's delegate.
	FImGuiDelegates::OnWorldDebug().Remove(ImGuiTickHandle);
}

void UImGuiSubtitlesMenuComponent::BeginDestroy()
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