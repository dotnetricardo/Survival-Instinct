// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SI/SI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SI/Projectile/Public/ProjectileMaster.h"
#include "SI/Weapons/Public/DynamicMagazineMaster.h"
#include "Particles/ParticleSystemComponent.h"
#include "Animation/AnimInstance.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "WeaponActualMaster.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UStaticMeshComponent;
class UPointLightComponent;
class AProjectileMaster;
class ADynamicMagazineMaster;
class UAnimMontage;
class UAnimSequence;
class USoundCue;
class UAudioComponent;




UCLASS()
class SI_API AWeaponActualMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponActualMaster();

	void Aim();

	void StopAim();

	void Fire();

	bool CanFire();

	void SetGrenadeMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* MuzzleFlashParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* GrenadeMuzzleFlashParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsPistol;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsAutomatic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FName Category;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bHasLaserSight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bHasMicroscopicSight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bHasGrenadeLauncher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	TSubclassOf<AProjectileMaster> ProjectileToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	TSubclassOf<AProjectileMaster> GrenadeProjectileToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsGrenadeMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FVector ShellEjectPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int MaxGrenadeAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int CurrentGrenadeAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	float FireRateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int InflictingDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int TotalMuzzles;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* ReloadMontage;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* ReloadGrenadeMontage;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimSequence* BarrelOpenAnimation;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimSequence* BarrelCloseAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	TSubclassOf<ADynamicMagazineMaster> DynamicMagazine;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	USoundCue* ReloadSoundFx;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	USoundCue* ReloadGrenadeSoundFx;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	USoundCue* ShootSoundFx;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	USoundCue* ShootGrenadeSoundFx;

	void SetMagazineVisible(bool bVisible);

	FTransform GetMagazineTransform();

	void AnimatePistolBarrel();

	FORCEINLINE bool CanAim() const { return bHasLaserSight || bHasMicroscopicSight; }

	/*UAudioComponent* ReloadAudioComponent;
	UAudioComponent* ShootAudioComponent;
	UAudioComponent* ShootGrenadeAudioComponent;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	USkeletalMeshComponent* WeaponActualSkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UStaticMeshComponent* LaserSightMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	USceneComponent* DefaultSceneRoot;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	std::pair<FHitResult, bool> GetHit(bool bDebug);

	void CreateMuzzleFlash();

	bool bIsPistolBarrelOpen;

};
