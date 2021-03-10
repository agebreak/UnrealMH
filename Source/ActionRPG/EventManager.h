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

// �̺�Ʈ �ڵ鷯 �������̽�. �̺�Ʈ�� ó���ϴ� Ŭ������ �������̽��� ��ӹ����� �ȴ�.
// NOTE : ȸ���� ����Ƽ�� Ŭ������ ���� Ŀ�ø��� ���������Ŵ�. 
// ������ ���� �����̶� �׳� �𸮾� ������� �����. (����� ������)
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

	// �ڽ� Ŭ������ �������̽� �Լ��� 
	virtual void BeginPlay() {};
	virtual void EndPlay() {};

	TMap<EEventID, FMHEventHandler> EventMap;
};