// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Components/CanvasPanelSlot.h"

AHUDBase::AHUDBase()
{
	
	
	// Create CrossHair
	static ConstructorHelpers::FClassFinder<UUserWidgetMaster> CrossHairUIBPClass(TEXT("/Game/UI/SI_Crosshair_Default.SI_Crosshair_Default_C"));

	// Create HealthBar
	static ConstructorHelpers::FClassFinder<UHealthBarUserWidgetMaster> HealthBarUIBPClass(TEXT("/Game/UI/SI_Healthbar.SI_Healthbar_C"));
	
	if (CrossHairUIBPClass.Class != nullptr && CrossHairUIBPClass.Succeeded() && HealthBarUIBPClass.Class != nullptr && HealthBarUIBPClass.Succeeded())
	{
		CrossHairWidgetUIClass = CrossHairUIBPClass.Class;
		HealthBarWidgetUIClass = HealthBarUIBPClass.Class;
	}
}

void AHUDBase::BeginPlay()
{
	Super::BeginPlay();

	CrossHairWidget = CreateWidget<UUserWidgetMaster>(GetWorld(), CrossHairWidgetUIClass);
	CrossHairWidget->AddToPlayerScreen();

	HealthBarWidget = CreateWidget<UHealthBarUserWidgetMaster>(GetWorld(), HealthBarWidgetUIClass);
	HealthBarWidget->AddToPlayerScreen();

	SetCrossHairVisibility(false);
}

void AHUDBase::SetCrossHairVisibility(bool bIsVisible)
{
	CrossHairWidget->SetVisibility(bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void AHUDBase::UpdateCrossHairSize(float Speed)
{
	if (CrossHairWidget != nullptr)
	{
		FVector2D Size(60.0f, 60.0f);
		
		UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(CrossHairWidget->crosshair_default->Slot);
		slot->SetSize(Speed > 0 ? Size * Speed : Size);
	}
}


