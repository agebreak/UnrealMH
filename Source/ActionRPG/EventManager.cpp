#include "EventManager.h"



void MHEventManager::SendEvent(FMHEvent* Event)
{
	// ��ϵ� �ڵ鷯�鿡�� �̺�Ʈ�� ��ε�ĳ���� �Ѵ�.
	for (auto Handler : HandlerList)
	{
		Handler->HandleEvent(Event);
	}
}

IEventHandler::IEventHandler()
{
	// Actor���� ActorManager���� �����Ѵ�. 
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
