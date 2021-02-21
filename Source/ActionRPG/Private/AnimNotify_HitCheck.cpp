// Copyright Epic Games, Inc. All Rights Reserved.


#include "AnimNotify_HitCheck.h"


void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	//MeshComp->GetWorld()->
	MeshComp->PlayAnim("Hit");	
	Delay(0.5f);
	MeshComp->PlayAnim("Idle");
}
