// Fill out your copyright notice in the Description page of Project Settings.


#include "A1Actor.h"
#include "A1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AA1Actor::AA1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	SetRootComponent(BodyMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (BodyMeshAsset.Succeeded())
	{
		BodyMesh->SetStaticMesh(BodyMeshAsset.Object);
	}

	WingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WingMesh"));
	WingMesh->SetupAttachment(BodyMesh);
	WingMesh->SetRelativeScale3D(FVector(0.5f, 5.0f, 0.2f));
	WingMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));

	if (BodyMeshAsset.Succeeded())
	{
		WingMesh->SetStaticMesh(BodyMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AA1Actor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("A1Target"), OUT Actors);
	if (Actors.Num() > 0)
	{
		TargetActor = Actors[0];
	}
}

// Called every frame
void AA1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector Location = GetActorLocation();
	//FVector NewLocation = Location + FVector::ForwardVector * MovementSpeed * DeltaTime;
	//SetActorLocation(NewLocation);

	//AddActorWorldOffset(FVector::ForwardVector * MovementSpeed * DeltaTime);

	if (TargetActor)
	{
		FVector Direction = TargetActor->GetActorLocation() - GetActorLocation();

		AddActorWorldOffset(Direction.GetSafeNormal() * MovementSpeed * DeltaTime);
	}

	// È¸Àü
	//FRotator Rotation = GetActorRotation();
	//FRotator NewRotation = FRotator(Rotation.Pitch, Rotation.Yaw * RotationRate * DeltaTime, Rotation.Roll);
	//SetActorRotation(NewRotation);

	AddActorWorldRotation(FRotator(0.0f, RotationRate * DeltaTime, 0.0f));
}

