// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MHAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UMHAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay();
	virtual void NativeUpdateAnimation(float DeltaSeconds); 

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed; 	

protected:
	UPROPERTY()
	class AMHCharacterBase* Character; 
};
