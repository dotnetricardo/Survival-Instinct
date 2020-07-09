// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SI/SI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponActualMaster.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UStaticMeshComponent;
class UPointLightComponent;


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
	FVector ShellEjectPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int TotalAmno;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int TotalGrenadeAmno;

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
