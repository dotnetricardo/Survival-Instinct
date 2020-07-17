// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SI/Player/Public/SICharacter.h"
#include "AmmoPickupMaster.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USceneComponent;
class UCameraComponent;
class ASICharacter;

UCLASS()
class SI_API AAmmoPickupMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoPickupMaster();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UStaticMeshComponent* AmmoStaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int WeaponMags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int GrenadeMags;


};
