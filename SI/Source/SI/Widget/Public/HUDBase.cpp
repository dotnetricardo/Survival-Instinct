// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Components/CanvasPanelSlot.h"



AHUDBase::AHUDBase()
{
	//PrimaryActorTick.bCanEverTick = true;
	
	// Create CrossHair
	static ConstructorHelpers::FClassFinder<UUserWidgetMaster> CrossHairUIBPClass(TEXT("/Game/UI/SI_Crosshair_Default.SI_Crosshair_Default_C"));

	// Create HealthBar
	//static ConstructorHelpers::FClassFinder<UHealthBarUserWidgetMaster> HealthBarUIBPClass(TEXT("/Game/UI/SI_Healthbar.SI_Healthbar_C"));
	
	/*if (CrossHairUIBPClass.Class != nullptr && CrossHairUIBPClass.Succeeded() && HealthBarUIBPClass.Class != nullptr && HealthBarUIBPClass.Succeeded())
	{
		CrossHairWidgetUIClass = CrossHairUIBPClass.Class;
		HealthBarWidgetUIClass = HealthBarUIBPClass.Class;
	}*/

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

	/*HealthBarWidget = CreateWidget<UHealthBarUserWidgetMaster>(GetWorld(), HealthBarWidgetUIClass);
	HealthBarWidget->AddToPlayerScreen();*/

	//CameraManager = Cast<AMyPlayerCameraManager>(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0));

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
//
//void AHUDBase::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	if (CameraManager)
//	{
//		APawn* OwningPawn = GetOwningPawn();
//		FVector Location = OwningPawn->GetActorLocation();
//		FVector FwdVector = OwningPawn->GetActorForwardVector() * 350.0f;
//
//		/*FVector LookAtVector = Location + (FwdVector * 10000);*/
//
//		//UE_LOG(LogTemp, Warning, TEXT("FwdVector is %d"), FwdVector.X)
//		
//		/*HealthBarWidget->SetRenderScale(FVector2D(0.8f, 0.8f));*/
//		
//		/*if (FwdVector.X > 0)
//		{
//			HealthBarWidget->SetRenderShear(FVector2D(44.0f, -38.0f));
//			HealthBarWidget->SetRenderTransformAngle(45.0f);
//		}
//		else if (FwdVector.X < 0)
//		
//		{
//			HealthBarWidget->SetRenderShear(FVector2D(44.0f, -38.0f));
//			HealthBarWidget->SetRenderTransformAngle(35.0f);
//		}
//
//		else 
//		{
//			HealthBarWidget->SetRenderShear(FVector2D(0.0f, 0.0f));
//			HealthBarWidget->SetRenderTransformAngle(0.0f);
//		}*/
//		
//		HealthBarWidget->SetRenderTranslation(FVector2D(FwdVector.X, 150.0f));
//		
//	}
//
//	
//}


