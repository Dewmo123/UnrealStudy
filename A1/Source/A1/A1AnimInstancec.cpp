// Fill out your copyright notice in the Description page of Project Settings.


#include "A1AnimInstancec.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UA1AnimInstancec::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (OwnerCharacter) {
		MovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UA1AnimInstancec::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (OwnerCharacter == nullptr)
		return;
	if (MovementComponent == nullptr)
		return;
	Velocity = MovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();
	bShouldMove = (GroundSpeed > 3.0f);
	bIsFalling = MovementComponent->IsFalling();
}

void UA1AnimInstancec::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
	
	AttackIndex = (AttackIndex + 1) % MaxAttackCount;
	FName SectionName = FName(FString::Printf(TEXT("Attack%d"), AttackIndex));
	Montage_JumpToSection(SectionName, AttackMontage);
}
