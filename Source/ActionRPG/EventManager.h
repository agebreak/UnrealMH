#pragma once
#include "CoreMinimal.h"
#include "IEvent.h"
#include "EventManager.generated.h"

class IEventHandler;

class MHEventManager
{
public:
	MHEventManager() {};
	~MHEventManager() {};

	static MHEventManager* Get() {
		static MHEventManager Instance;
		return &Instance;
	}

	void SendEvent(FMHEvent* Event);

	void AddHandler(IEventHandler* Handler)
	{
		HandlerList.Add(Handler);
	}

private:
	TArray<IEventHandler*> HandlerList;
};

DECLARE_DELEGATE_OneParam(FMHEventHandler, FMHEvent*);

UINTERFACE()
class UEventHandler : public UInterface
{
	GENERATED_BODY()
};

// 이벤트 핸들러 인터페이스. 이벤트를 처리하는 클래스는 인터페이스를 상속받으면 된다.
// NOTE : 회사라면 네이티브 클래스로 만들어서 커플링을 제거했을거다. 
// 하지만 개인 플젝이라 그냥 언리얼 기반으로 만든다. (재경이 때문임)
class IEventHandler
{
	GENERATED_BODY()

public:	
	IEventHandler();

	virtual void HandleEvent(FMHEvent* Event);

	FMHEventHandler& Bind(EEventID EventID)
	{
		return EventMap.FindOrAdd(EventID);
	}

	// 자식 클래스용 인터페이스 함수들 
	virtual void BeginPlay() {};
	virtual void EndPlay() {};

	TMap<EEventID, FMHEventHandler> EventMap;
};