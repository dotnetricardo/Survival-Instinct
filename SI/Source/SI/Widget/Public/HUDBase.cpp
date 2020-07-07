// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"

AHUDBase::AHUDBase()
{
	// Create CrossHair
	static ConstructorHelpers::FClassFinder<UUserWidgetMaster> CrossHairUIBPClass(TEXT("/Game/UI/SI_Crosshair_Round.SI_Crosshair_Round_C"));

	if (CrossHairUIBPClass.Class != nullptr && CrossHairUIBPClass.Succeeded())
	{
		CrossHairWidgetUIClass = CrossHairUIBPClass.Class;

	}
}

void AHUDBase::BeginPlay()
{
	Super::BeginPlay();

	CrossHairWidget = CreateWidget<UUserWidgetMaster>(GetWorld(), CrossHairWidgetUIClass);
	CrossHairWidget->AddToPlayerScreen();
	SetCrossHairVisibility(false);
}

void AHUDBase::SetCrossHairVisibility(bool bIsVisible)
{
	CrossHairWidget->SetVisibility(bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
