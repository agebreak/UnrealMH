#include "EventManager.h"



void MHEventManager::SendEvent(FMHEvent* Event)
{
	// 등록된 핸들러들에게 이벤트를 브로드캐스팅 한다.
	for (auto Handler : HandlerList)
	{
		Handler->HandleEvent(Event);
	}
}

IEventHandler::IEventHandler()
{
	// Actor들은 ActorManager에서 관리한다. 
	if (Cast<AActor>(this) == nullptr)
	{
		MHEventManager::Get()->AddHandler(this);
	}

	Bind(EEventID::EVENT_BEGIN_PLAY).
		BindLambda([this](FMHEvent * Event) {
		BeginPlay();
				   });

	Bind(EEventID::EVENT_END_PLAY).
		BindLambda([this](FMHEvent * Event) {
		EndPlay();
				   });
}

void IEventHandler::HandleEvent(FMHEvent* Event)
{
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
