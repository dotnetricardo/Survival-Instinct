// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SI/SI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SI/Projectile/Public/ProjectileMaster.h"
#include "WeaponActualMaster.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UStaticMeshComponent;
class UPointLightComponent;
class AProjectileMaster;


UCLASS()
class SI_API AWeaponActualMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponActualMaster();

	bool CanAim();

	void Aim();

	void StopAim();

	void Fire();

	bool CanFire();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsPistol;

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
	bool bIsGrenadeMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FVector ShellEjectPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int MaxGrenadeAmmp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int CurrentGrenadeAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	float FireRateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int InflictingDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int TotalMuzzles;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsGrenadeModeActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	std::pair<FHitResult, bool> GetHit(bool bDebug);

};
