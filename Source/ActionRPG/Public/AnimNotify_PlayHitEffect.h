// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "AnimNotify_PlayHitEffect.generated.h"

/**
 * 히트시에만 이펙트를 생성하는 노티파이 클래스 
 */
UCLASS()
class ACTIONRPG_API UAnimNotify_PlayHitEffect : public UAnimNotify_PlayParticleEffect
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
