// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/A1Sphere.h"

// Sets default values
AA1Sphere::AA1Sphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionProfileName(FName("A1Enemy"));
}

// Called when the game starts or when spawned
void AA1Sphere::BeginPlay()
{
	Super::BeginPlay();
	if (Mesh) {
		Mesh->OnComponentHit.AddDynamic(this, &AA1Sphere::OnHit);
	}
}

// Called every frame
void AA1Sphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA1Sphere::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

