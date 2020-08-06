// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SI/Widget/Public/UserWidgetMaster.h"
#include "SI/Widget/Public/HealthBarUserWidgetMaster.h"
#include "SI/CameraManager/Public/MyPlayerCameraManager.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "HUDBase.generated.h"

class UUserWidgetMaster;
class UHealthBarUserWidgetMaster;
class AMyPlayerCameraManager;
class UGameplayStatics;

UCLASS()
class SI_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:
	AHUDBase();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Dynamic reference to the blueprint class
	TSubclassOf<class UUserWidget> CrossHairWidgetUIClass;

	TSubclassOf<class UUserWidget> HealthBarWidgetUIClass;

	// Internal reference to the blueprint for gameplay logic
	UPROPERTY(BlueprintReadOnly, Category = "UI")
	UUserWidgetMaster* CrossHairWidget;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	UHealthBarUserWidgetMaster* HealthBarWidget;

	void SetCrossHairVisibility(bool bIsVisible);
	void UpdateCrossHairSize(float Speed);

private:
	AMyPlayerCameraManager* CameraManager;

};
