// Copyright Epic Games, Inc. All Rights Reserved.


#include "MHAnimInstance.h"
#include "MHCharacterBase.h"

void UMHAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay(); 

	Character = Cast<AMHCharacterBase>(GetOwningActor()); 
}

void UMHAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds); 

	if (!Character)
		return; 

	Speed = Character->GetVelocity().Size2D(); 
}