// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_HitCheck.generated.h"

/**
 * 히트 체크하는 클래스 
 */
UCLASS()
class ACTIONRPG_API UAnimNotify_HitCheck : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);	

public:	
	// 히트체크 시작 위치. 오브젝트 좌표계
	UPROPERTY(EditAnywhere)
	FVector StartOffset;  

	// 히트체크 끝 위치. Start에서 더해지는 오프셋
	UPROPERTY(EditAnywhere)
	FVector EndOffset;

	UPROPERTY(EditAnywhere)
	float Radius = 10.0f; 
};
