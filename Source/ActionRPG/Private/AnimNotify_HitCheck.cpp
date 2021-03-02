// Copyright Epic Games, Inc. All Rights Reserved.


#include "AnimNotify_HitCheck.h"
#include "../IEvent.h"
#include "../EventManager.h"

void UAnimNotify_HitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{

	FVector Start = MeshComp->GetComponentTransform().TransformPosition(StartOffset); 
	FVector End = Start + MeshComp->GetComponentRotation().RotateVector(EndOffset);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes; 
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> ActorsIgnore; 

	FHitResult HitResult;
	UKismetSystemLibrary::SphereTraceSingleForObjects(
		MeshComp,
		Start, End, Radius,
		ObjectTypes, false, ActorsIgnore, 
		EDrawDebugTrace::ForDuration,
		HitResult,true);

	IEventHandler* Actor = Cast<IEventHandler>(MeshComp->GetOwner()); 
	if (Actor)
	{
		EventSetAttackHit Event;
		Event.IsAttackHit = HitResult.bBlockingHit;
		Actor->HandleEvent(&Event);
	}
}
