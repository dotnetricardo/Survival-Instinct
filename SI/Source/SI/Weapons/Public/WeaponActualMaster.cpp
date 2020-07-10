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

void AWeaponActualMaster::Fire()
{
	FTransform Shoot1To;
	FTransform Shoot2To;
	FVector Muzzle1Location;
	FVector Muzzle2Location;
	FVector GrenadeMuzzleLocation;
	FRotator LookAtRotation;
	/*AProjectileMaster* SpawnedProjectile1;
	AProjectileMaster* SpawnedProjectile2;*/

	AActor* MyOwner = GetOwner();
	ASICharacter* Character = Cast<ASICharacter>(MyOwner);

	FVector TraceStart = Character->CameraComp->GetComponentLocation();
	FVector TraceEnd = TraceStart + (Character->CameraComp->GetForwardVector() * 10000);

	std::pair<FHitResult, bool> result = GetHit(true);


	if (result.second)
	{
		// It will hit something
		UE_LOG(LogTemp, Warning, TEXT("will hit"));
		if (bIsGrenadeMode)
		{
			GrenadeMuzzleLocation = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_Grenade"));
			LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GrenadeMuzzleLocation, result.first.ImpactPoint);
			Shoot1To = UKismetMathLibrary::MakeTransform(GrenadeMuzzleLocation, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));

		}
		else
		{
			Muzzle1Location = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_1"));
			LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Muzzle1Location, result.first.ImpactPoint);
			Shoot1To = UKismetMathLibrary::MakeTransform(Muzzle1Location, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));

			if (TotalMuzzles == 2)
			{
				Muzzle2Location = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_2"));
				LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Muzzle2Location, result.first.ImpactPoint);
				Shoot2To = UKismetMathLibrary::MakeTransform(Muzzle2Location, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));
			}
		}

	}
	else
	{
		// It will not hit anything
		UE_LOG(LogTemp, Warning, TEXT("will not hit"));
		if (bIsGrenadeMode)
		{
			GrenadeMuzzleLocation = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_Grenade"));
			LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GrenadeMuzzleLocation, TraceEnd);
			Shoot1To = UKismetMathLibrary::MakeTransform(GrenadeMuzzleLocation, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));

		}
		else
		{
			Muzzle1Location = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_1"));
			LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Muzzle1Location, TraceEnd);
			Shoot1To = UKismetMathLibrary::MakeTransform(Muzzle1Location, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));

			if (TotalMuzzles == 2)
			{
				Muzzle2Location = WeaponActualSkeletalMesh->GetSocketLocation(TEXT("Muzzle_2"));
				LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Muzzle2Location, TraceEnd);
				Shoot2To = UKismetMathLibrary::MakeTransform(Muzzle2Location, LookAtRotation, FVector(1.0f, 1.0f, 1.0f));
			}
		}
	}

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Cast<APawn>(MyOwner);
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//if (bIsGrenadeMode)
	//{
	//	// TODO: Change ProjectileToSpawn to a new Projectile Grenade BP class
	//	SpawnedProjectile1 = GetWorld()->SpawnActor<AProjectileMaster>(ProjectileToSpawn, Shoot1To, spawnParams);
	//}
	//else
	//{
	//	// Single Shot
	//	SpawnedProjectile1 = GetWorld()->SpawnActor<AProjectileMaster>(ProjectileToSpawn, Shoot1To, spawnParams);

	//	if (TotalMuzzles == 2)
	//	{
	//		SpawnedProjectile2 = GetWorld()->SpawnActor<AProjectileMaster>(ProjectileToSpawn, Shoot2To, spawnParams);
	//	}
	//}

	// NOTE: Projectile Components will auto destroy as AProjectileMaster implements on component hit.

}

bool AWeaponActualMaster::CanFire()
{
	return CurrentAmmo > 0;
}

void AWeaponActualMaster::Aim()
{
	std::pair<FHitResult, bool> result = GetHit(true);

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

		if (bDebug)
		{
			DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
		}

		if (GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, PROJECTILE_CHANNEL, QueryParams))
		{
			// Blocking hit! Process Damage
			return std::make_pair(Hit, true);
		}

	}

	return std::make_pair(Hit, false);
}

#pragma endregion




