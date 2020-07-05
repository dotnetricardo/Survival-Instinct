// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponActualMaster.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"

// Sets default values
AWeaponActualMaster::AWeaponActualMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	DefaultSceneRoot->SetupAttachment(RootComponent);

	WeaponActualSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponActualSkeletalMesh"));
	WeaponActualSkeletalMesh->SetupAttachment(DefaultSceneRoot);

	LaserSightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserSightMesh"));
	
	/*LaserSightStaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh /Imports/Laser/SI_LaserMesh.Mesh"));*/

	/*LaserSightMesh->SetStaticMesh(LaserSightStaticMesh);*/

	LaserSightMesh->SetupAttachment(WeaponActualSkeletalMesh);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->SetupAttachment(LaserSightMesh);
	
}

// Called when the game starts or when spawned
void AWeaponActualMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponActualMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

