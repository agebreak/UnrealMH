#pragma once

#include "CoreMinimal.h"
#include "IEvent.generated.h"


UENUM()
enum class EEventID
{
	EVENT_INVALID = 0,  

	ACTOR_IS_HIT = 101, 
	ACTOR_SET_HIT,
};

USTRUCT()
struct FMHEvent
{
	GENERATED_BODY() 

	EEventID ID; 
};

#define EVENT_DECL(EventName, EventID) \
struct EventName : public FMHEvent { EventName() { ID = EventID; } 

#define EVENT_DECL_END };

EVENT_DECL(EventIsAttackHit, EEventID::ACTOR_IS_HIT)
	OUT bool IsAttackHit = false; 
EVENT_DECL_END

EVENT_DECL(EventSetAttackHit, EEventID::ACTOR_SET_HIT)
	bool IsAttackHit; 
EVENT_DECL_END