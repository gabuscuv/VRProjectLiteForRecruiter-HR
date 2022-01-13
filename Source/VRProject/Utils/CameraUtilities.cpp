// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraUtilities.h"
#include "../Interfaces/HideableItem.h"
#include "GameFramework/PlayerController.h" 

void UCameraUtilities::AddHiddenActorsToCamera(APlayerController* playerController, TArray<AActor*> actors)
{
	// TODO: Unified Code, See TODO below
	
 	for (AActor* actor : actors)
	{

		for ( AActor* actorToHide : IHideableItem::Execute_GetActorsForHide(actor))
		{
			playerController->HiddenActors.Add(actorToHide);
		};
	};
};

void UCameraUtilities::AddHiddenActorsToSceneCamera(USceneCaptureComponent* playerController, TArray<AActor*> actors)
{
	// TODO	
};

void UCameraUtilities::AddHiddenActorToArray(TArray<AActor*> HiddenActorArray, AActor* ActorsforHide )
{
	// TODO
};