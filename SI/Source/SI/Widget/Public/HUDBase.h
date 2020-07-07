// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SI/Widget/Public/UserWidgetMaster.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class SI_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:
	AHUDBase();
	virtual void BeginPlay() override;

	// Dynamic reference to the blueprint class
	TSubclassOf<class UUserWidget> CrossHairWidgetUIClass;

	// Internal reference to the blueprint for gameplay logic
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUserWidgetMaster* CrossHairWidget;

	void SetCrossHairVisibility(bool bIsVisible);

};
