// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DynamicMagazineMaster.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class UBoxComponent;

UCLASS()
class SI_API ADynamicMagazineMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicMagazineMaster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	UStaticMeshComponent* MagazineStaticMesh;

	void SelfDestructAfterSec(int seconds);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* Box;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	USceneComponent* DefaultSceneRoot;

	void SelfDestroy();

};
