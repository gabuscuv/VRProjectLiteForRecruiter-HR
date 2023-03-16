// Copyright 2020 Gabriel Bustillo del Cuvillo

#include "CameraUtilities.h"
#include "../Interfaces/HideableItem.h"
#include "GameFramework/PlayerController.h" 

// (Gaby) Dev Notes:
/*
	This is deprecated (for this project) But It's a good demonstration of abilities for research about obscure/obfuscated properties (Hi Recluter/HR!).
	But If you are looking for something like this, I highly recommend you check this property "UPrimitiveComponent::bVisibleInSceneCaptureOnly" or
	On your PrimitiveComponent (like a UMeshComponent/StaticMeshComponent/SkeleticalMeshComponent) blueprint properties in the "Rendering" section
	tick or untick "Visible In Scene Capture Only" (It's the same property)
	This function may be still useful for multiplayer games (this is not the case) where you don't want to hide a mesh for everyone but for example by roles
	when you are using SceneCaptureComponent, otherwise I would just recommend setting to false to Visible Property.
	(The HiddenActors are controlled by PlayerController or USceneCaptureComponents) 
*/

void UCameraUtilities::AddHiddenActorsToCamera(APlayerController* playerController, TArray<AActor*> actors)
{
	
 	for (AActor* actor : actors)
	{

		for ( AActor* actorToHide : IHideableItem::Execute_GetActorsForHide(actor))
		{
			playerController->HiddenActors.Add(actorToHide);
		};
	};
};

// Deprecated 
void UCameraUtilities::AddHiddenActorsToSceneCamera(USceneCaptureComponent* playerController, TArray<AActor*> actors)
{
	// TODO	
};

// Deprecated 
void UCameraUtilities::AddHiddenActorToArray(TArray<AActor*> HiddenActorArray, AActor* ActorsforHide )
{
	// TODO
};