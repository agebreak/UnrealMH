// Copyright Epic Games, Inc. All Rights Reserved.


#include "AnimNotify_PlayHitEffect.h"
#include "MHCharacterBase.h"
#include "../IEvent.h"

void UAnimNotify_PlayHitEffect::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	// ��Ʈ�ÿ��� ��ƼŬ�� �����Ѵ�. 
	bool bHit = false;

	if (MeshComp->GetWorld()->IsPreviewWorld())
	{
		bHit = true;
	}
	else if (MeshComp->GetOwner())
	{
		auto Actor = Cast<IEventHandler>(MeshComp->GetOwner()); 
		if (!Actor)
			return; 

		EventIsAttackHit Event; 
		Actor->HandleEvent(&Event); 

		bHit = Event.IsAttackHit;
	}

	if(bHit)
		SpawnParticleSystem(MeshComp, Animation);
}