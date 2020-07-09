// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponActualMaster.h"
#include "SI/Player/Public/SICharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

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

bool AWeaponActualMaster::CanAim()
{
	return bHasLaserSight || bHasMicroscopicSight;
}

void AWeaponActualMaster::Aim()
{
	std::pair<FHitResult, bool> result = GetHit(false);
	
	if (result.second)
	{
		FVector MuzzleLocation = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_1"));

		FRotator LaserRotation = UKismetMathLibrary::FindLookAtRotation(MuzzleLocation, result.first.ImpactPoint);

		float Distance = (MuzzleLocation - result.first.ImpactPoint).Size();

		FVector VectorScale = UKismetMathLibrary::MakeVector(Distance, 0, 0);

		LaserSightMesh->SetHiddenInGame(false, true);
		LaserSightMesh->SetWorldScale3D(VectorScale);
		LaserSightMesh->SetWorldRotation(LaserRotation);
		PointLight->SetWorldLocation(result.first.ImpactPoint - PointLight->GetForwardVector());
		
		if (Distance < 400)
		{
			PointLight->SetAttenuationRadius(2.0f);
		} 
		else {
			PointLight->SetAttenuationRadius(4.0f);
		}
	}
}

void AWeaponActualMaster::StopAim()
{
	LaserSightMesh->SetHiddenInGame(true, true);
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

#pragma region Private

std::pair<FHitResult, bool> AWeaponActualMaster::GetHit(bool bDebug)
{
	// Trace the world from pawn eyes to crosshair location
	AActor* MyOwner = GetOwner();
	FHitResult Hit;

	if (MyOwner)
	{
		/*FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 10000);*/

		ASICharacter* Character = Cast<ASICharacter>(MyOwner);

		FVector TraceStart = Character->CameraComp->GetComponentLocation();
		FVector TraceEnd = TraceStart + (Character->CameraComp->GetForwardVector() * 10000);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(MyOwner);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;

		
		if (GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, PROJECTILE_CHANNEL, QueryParams))
		{
			// Blocking hit! Process Damage
			return std::make_pair(Hit, true);
		}

		if (bDebug)
		{
			DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
		}

	}

	return std::make_pair(Hit, false);
}

#pragma endregion




