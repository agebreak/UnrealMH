#pragma once

#include "CoreMinimal.h"
#include "IEvent.generated.h"


UENUM()
enum class EEventID
{
	EVENT_INVALID = 0,  
	EVENT_BEGIN_PLAY, 
	EVENT_END_PLAY, 

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

EVENT_DECL(EventBeginPlay, EEventID::EVENT_BEGIN_PLAY)
EVENT_DECL_END 

EVENT_DECL(EventEndPlay, EEventID::EVENT_END_PLAY)
EVENT_DECL_END

EVENT_DECL(EventIsAttackHit, EEventID::ACTOR_IS_HIT)
	OUT bool IsAttackHit = false; 
EVENT_DECL_END

EVENT_DECL(EventSetAttackHit, EEventID::ACTOR_SET_HIT)
	bool IsAttackHit; 
EVENT_DECL_END

