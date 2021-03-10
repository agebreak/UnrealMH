// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MHGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API AMHGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay();

	/** Overridable function called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
	
};
