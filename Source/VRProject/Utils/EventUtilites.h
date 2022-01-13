// Gabriel Bustillo del Cuvillo

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../Enums/EEvents.h"
#include "EventUtilites.generated.h"
/**
 * 
 */
UCLASS()
class VRPROJECT_API UEventUtilites : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable,meta = (WorldContext = "WorldContextObject"))
	static void ExecuteEvent(const UObject* WorldContext, EEvents event, bool fastrun = false);
	static void ExecuteEvent(UWorld* WorldContext, EEvents event, bool fastrun = false);
};
