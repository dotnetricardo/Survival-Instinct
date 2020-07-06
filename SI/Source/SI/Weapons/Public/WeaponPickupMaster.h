// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponPickupMaster.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USceneComponent;
class AWeaponActualMaster;

UCLASS()
class SI_API AWeaponPickupMaster : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponPickupMaster();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	TSubclassOf<AWeaponActualMaster> WeaponActual;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UStaticMeshComponent* WeaponStaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	USceneComponent* DefaultSceneRoot;

	
		

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
