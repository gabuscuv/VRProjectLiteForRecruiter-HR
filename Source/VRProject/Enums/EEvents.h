// Copyright 2020 Gabriel Bustillo del Cuvillo

// Probably this should be self-generated
#pragma once

#include "CoreMinimal.h"
#include "EEvents.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EEvents : uint8
{
  None        UMETA(DisplayName = "None"),
  Any         UMETA(DisplayName = "Any"),
  Event1      UMETA(DisplayName = "Event1", ToolTip="1.Car Slot Event"),
  Event2      UMETA(DisplayName = "Event2", ToolTip="2.Get into the House"),
  Event3      UMETA(DisplayName = "Event3", ToolTip="4.Activate Hidden Stairs"),
  Event4      UMETA(DisplayName = "Event4", ToolTip="3."),
  Event5      UMETA(DisplayName = "Event5", ToolTip=""),
  Event6      UMETA(DisplayName = "Event6", ToolTip=""),
  Event7      UMETA(DisplayName = "Event7", ToolTip=""),
  Event8      UMETA(DisplayName = "Event8", ToolTip=""),
  Event9      UMETA(DisplayName = "Event9", ToolTip=""),
};