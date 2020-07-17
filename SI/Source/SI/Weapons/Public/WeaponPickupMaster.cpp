// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickupMaster.h"
#include "SI/Player/Public/SICharacter.h"
#include "WeaponActualMaster.h"

//#include "Kismet/KismetArrayLibrary.h"


// Sets default values
AWeaponPickupMaster::AWeaponPickupMaster()
{

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	DefaultSceneRoot->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(DefaultSceneRoot);
	Box->SetCollisionProfileName(TEXT("SI_WeaponPickupCollision"));
	
	WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponStaticMesh"));
	WeaponStaticMesh->SetupAttachment(Box);

}

void AWeaponPickupMaster::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ASICharacter* PlayerCharacter = Cast<ASICharacter>(OtherActor);

	//UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	if (PlayerCharacter)
	{
		PlayerCharacter->SpawnWeapon(WeaponActual);

		Destroy();
	}

}

// Called when the game starts or when spawned
void AWeaponPickupMaster::BeginPlay()
{
	Super::BeginPlay();
	
}
