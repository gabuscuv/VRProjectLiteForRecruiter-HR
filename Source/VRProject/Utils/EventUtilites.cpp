// Copyright 2020 Gabriel Bustillo del Cuvillo

#include "EventUtilites.h"
#include "Kismet/GameplayStatics.h"
#include "../Interfaces/EventTrigger.h"

void UEventUtilites::ExecuteEvent(const UObject* worldContext, EEvents event, bool fastrun)
{
    ExecuteEvent(worldContext->GetWorld(), event, fastrun);
}

void UEventUtilites::ExecuteEvent(UWorld* world, EEvents event, bool fastrun)
{
    TArray<AActor*> EventTriggers;
    UGameplayStatics::GetAllActorsWithInterface(world, UEventTrigger::StaticClass(), EventTriggers);
    for (auto& actor : EventTriggers)
    {
        if(IEventTrigger::Execute_GetEventEnum(actor) == event || IEventTrigger::Execute_GetEventEnum(actor) == EEvents::Any)
        {
            IEventTrigger::Execute_ExecuteEvent(actor,event, fastrun);
        };
        
    };
}