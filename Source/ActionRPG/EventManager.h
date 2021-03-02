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

// �̺�Ʈ �ڵ鷯 �������̽�. �̺�Ʈ�� ó���ϴ� Ŭ������ �������̽��� ��ӹ����� �ȴ�.
class IEventHandler
{
	GENERATED_BODY()

public:	
	virtual void HandleEvent(FMHEvent* Event) {
		if (EventMap.Contains(Event->ID))
		{
			EventMap[Event->ID].Execute(Event);
		}

		// ������Ʈ ��ȯ 
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