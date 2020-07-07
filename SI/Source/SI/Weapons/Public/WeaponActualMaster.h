// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsPistol;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FName Category;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bHasLaserSight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	FVector ShellEjectPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int TotalAmno;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	float FireRateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int InflictingDamage;
	
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

};
