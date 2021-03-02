#pragma once
#include "CoreMinimal.h"
#include "IEvent.h"
#include "EventManager.generated.h"

DECLARE_DELEGATE_OneParam(FMHEventHandler, FMHEvent*);

UINTERFACE()
class UEventHandler : public UInterface
{
	GENERATED_BODY()
};

// 이벤트 핸들러 인터페이스. 이벤트를 처리하는 클래스는 인터페이스를 상속받으면 된다.
class IEventHandler
{
	GENERATED_BODY()

public:	
	virtual void HandleEvent(FMHEvent* Event) {
		if (EventMap.Contains(Event->ID))
		{
			EventMap[Event->ID].Execute(Event);
		}

		// 컴포넌트 순환 
		AActor* Actor = Cast<AActor>(this); 
		if (Actor)
		{
			for (auto Comp : Actor->GetComponents())
			{
				auto Handler = Cast<IEventHandler>(Comp);
				if (Handler)
					Handler->HandleEvent(Event);
			}
		}
	}

	FMHEventHandler& Bind(EEventID EventID)
	{
		return EventMap.FindOrAdd(EventID);
	}

	TMap<EEventID, FMHEventHandler> EventMap;
};