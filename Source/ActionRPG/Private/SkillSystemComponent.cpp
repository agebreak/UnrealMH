// Copyright Epic Games, Inc. All Rights Reserved.


#include "SkillSystemComponent.h"

// Sets default values for this component's properties
USkillSystemComponent::USkillSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Bind(EEventID::ACTOR_IS_HIT).BindLambda([this](FMHEvent * Event) {
		auto pEvent = (EventIsAttackHit*)Event;
		pEvent->IsAttackHit = bIsAttackHit;
	});

	Bind(EEventID::ACTOR_SET_HIT).BindLambda([this](FMHEvent * Event) {
		auto pEvent = (EventSetAttackHit*)Event; 
		bIsAttackHit = pEvent->IsAttackHit;
	});
											
}


// Called when the game starts
void USkillSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

