// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "AnimNotify_PlayHitEffect.generated.h"

/**
 * ��Ʈ�ÿ��� ����Ʈ�� �����ϴ� ��Ƽ���� Ŭ���� 
 */
UCLASS()
class ACTIONRPG_API UAnimNotify_PlayHitEffect : public UAnimNotify_PlayParticleEffect
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
