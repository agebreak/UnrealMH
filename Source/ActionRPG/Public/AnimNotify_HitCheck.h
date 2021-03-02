// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_HitCheck.generated.h"

/**
 * ��Ʈ üũ�ϴ� Ŭ���� 
 */
UCLASS()
class ACTIONRPG_API UAnimNotify_HitCheck : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);	

public:	
	// ��Ʈüũ ���� ��ġ. ������Ʈ ��ǥ��
	UPROPERTY(EditAnywhere)
	FVector StartOffset;  

	// ��Ʈüũ �� ��ġ. Start���� �������� ������
	UPROPERTY(EditAnywhere)
	FVector EndOffset;

	UPROPERTY(EditAnywhere)
	float Radius = 10.0f; 
};
