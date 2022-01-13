// Copyright 2020 Gabriel Bustillo del Cuvillo

#pragma once

#include "../ImGuiCommon.h"
#if WITH_IMGUI

#include "CoreMinimal.h"
#include "../../Enums/EEvents.h"
#endif
#include "ImGuiEventMenuComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UImGuiEventMenuComponent : public UActorComponent
{
	GENERATED_BODY()
#if WITH_IMGUI
	public:
	UImGuiEventMenuComponent();
	virtual void BeginDestroy() override;

	// To register and unregister per-object world delegate.
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	EEvents eventCurrentCombo;
	void EventMenuWindow();
	void ImGuiTick();
	static void ImGuiMultiContextTick();

	FDelegateHandle ImGuiTickHandle;
	static FDelegateHandle ImGuiMultiContextTickHandle;
#endif // WITH_IMGUI
};