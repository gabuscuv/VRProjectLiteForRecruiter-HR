// Copyright 2020 Gabriel Bustillo del Cuvillo

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "../Enums/EEvents.h"
#include "EventTrigger.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEventTrigger : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VRPROJECT_API IEventTrigger
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "VR")
	void ExecuteEvent(EEvents CurrentEvent, bool fastrun = false);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "VR")
	EEvents GetEventEnum() const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "VR")
	bool IsEventAvailable() const;
	FORCEINLINE bool IsEventAvailable_Implementation() const{return true;}
};
