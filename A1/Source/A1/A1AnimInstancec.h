// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "A1AnimInstancec.generated.h"

/**
 * 
 */
UCLASS()
class A1_API UA1AnimInstancec : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
#pragma region AnimationMontage
public:
	UFUNCTION()
	void PlayAttackMontage();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Montage)
	TObjectPtr<class UAnimMontage> AttackMontage;

protected:
	int32 AttackIndex = -1;
	UPROPERTY(EditAnywhere)
	int32 MaxAttackCount = 3;
#pragma endregion
protected:
	UPROPERTY(BlueprintReadonly);
	TObjectPtr<class ACharacter>OwnerCharacter;
	UPROPERTY(BlueprintReadonly)
	TObjectPtr<class UCharacterMovementComponent> MovementComponent;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	FVector Velocity = FVector::ZeroVector;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float GroundSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bShouldMove;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsFalling;
};
