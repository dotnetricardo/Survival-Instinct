// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicMagazineMaster.h"

// Sets default values
ADynamicMagazineMaster::ADynamicMagazineMaster()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	DefaultSceneRoot->SetupAttachment(RootComponent);

	/*Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(DefaultSceneRoot);
	Box->SetCollisionProfileName(TEXT("SI_MagazineStaticMeshCollision"));*/

	MagazineStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MagazineStaticMesh"));
	MagazineStaticMesh->SetupAttachment(DefaultSceneRoot);

}

void ADynamicMagazineMaster::SelfDestructAfterSec(int seconds)
{
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ADynamicMagazineMaster::SelfDestroy, seconds, false);
}

// Called when the game starts or when spawned
void ADynamicMagazineMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADynamicMagazineMaster::SelfDestroy()
{
	Destroy();
}

