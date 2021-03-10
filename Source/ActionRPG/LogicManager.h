#include "CoreMinimal.h"
#include "EventManager.h"

class LogicManager : IEventHandler
{
public:
	LogicManager();
	virtual ~LogicManager();

	virtual void BeginPlay() {};
	virtual void EndPlay() {};
};
