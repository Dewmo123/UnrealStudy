// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/A1Box.h"
#include "Components/BoxComponent.h"

// Sets default values
AA1Box::AA1Box()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	SetRootComponent(Box);
	Box->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	Box->SetHiddenInGame(false);
	Box->SetCollisionProfileName(FName("OverlapAllDynamic"));
}

// Called when the game starts or when spawned
void AA1Box::BeginPlay()
{
	Super::BeginPlay();
	if (Box) {
		Box->OnComponentBeginOverlap.AddDynamic(this, &AA1Box::OnBoxBeginOverlap);
	}
}

// Called every frame
void AA1Box::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA1Box::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, OtherActor->GetName());
}

