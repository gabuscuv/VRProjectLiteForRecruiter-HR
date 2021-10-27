// Copyright 2020 Gabriel Bustillo del Cuvillo

#pragma once

#include "../ImGuiCommon.h"
#if WITH_IMGUI

#include "CoreMinimal.h"
#include "../../Enums/EEvents.h"
#endif
#include "ImGuiSubtitlesMenuComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FSubtitlesPushDelegate,TArray<FSubtitleCue>)

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UImGuiSubtitlesMenuComponent : public UActorComponent
{
	GENERATED_BODY()
	public:
	UImGuiSubtitlesMenuComponent();
	
	FSubtitlesPushDelegate SubtitlesPushDelegate;

	virtual void BeginDestroy() override;

	// To register and unregister per-object world delegate.
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_IMGUI

    char InputBuf[256];
	char InputBuf2[256];
	void EventMenuWindow();
	void ImGuiTick();
	static void ImGuiMultiContextTick();

	FDelegateHandle ImGuiTickHandle;
	static FDelegateHandle ImGuiMultiContextTickHandle;
#endif // WITH_IMGUI
};