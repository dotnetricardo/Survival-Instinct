// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickupMaster.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAmmoPickupMaster::AAmmoPickupMaster()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	DefaultSceneRoot->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(DefaultSceneRoot);
	Box->SetCollisionProfileName(TEXT("SI_WeaponPickupCollision"));

	AmmoStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoStaticMesh"));
	AmmoStaticMesh->SetupAttachment(Box);

}

void AAmmoPickupMaster::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ASICharacter* PlayerCharacter = Cast<ASICharacter>(OtherActor);

	//UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	if (PlayerCharacter)
	{
		if (PlayerCharacter->CanAddMags())
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSoundFx, OtherActor->GetActorLocation());
			PlayerCharacter->AddMags(WeaponMags, GrenadeMags);
			Destroy();
		}
	}
}

// Called when the game starts or when spawned
void AAmmoPickupMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

