// Copyright Epic Games, Inc. All Rights Reserved.


#include "MHGameMode.h"
#include <ActionRPG/IEvent.h>
#include "../EventManager.h"

void AMHGameMode::BeginPlay()
{
	EventBeginPlay Event; 
	MHEventManager::Get()->SendEvent(&Event);
}

void AMHGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	EventEndPlay Event; 
	MHEventManager::Get()->SendEvent(&Event);

}
