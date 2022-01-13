// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CameraUtilities.generated.h"

/**
 * 
 */
UCLASS()
class VRPROJECT_API UCameraUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable,meta = (WorldContext = "WorldContextObject"))
		static void AddHiddenActorsToCamera(class APlayerController* playerController, TArray<AActor*> actors);
	UFUNCTION(BlueprintCallable,meta = (WorldContext = "WorldContextObject"))
		static void AddHiddenActorsToSceneCamera(class USceneCaptureComponent* playerController, TArray<AActor*> actors);
	private:
		static void AddHiddenActorToArray(TArray<AActor*> HiddenActorArray, AActor* ActorsforHide);

};
