// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarUserWidgetMaster.h"

void UHealthBarUserWidgetMaster::UpdateHealth(float Value)
{
	HealthValue->SetText(FText::AsNumber(Value));
	HealthBar->SetPercent(Value / 100);
}

void UHealthBarUserWidgetMaster::UpdateArmor(int Value)
{
	switch (Value)
	{
	case 0:
		ArmorBar1->SetPercent(0);
		break;
	case 1:
		ArmorBar2->SetPercent(0);
		break;
	case 2:
		ArmorBar3->SetPercent(0);
		break;
	case 3:
		ArmorBar4->SetPercent(0);
		break;
	case 4:
		ArmorBar5->SetPercent(0);
		break;
	case 5:
		ArmorBar6->SetPercent(0);
		break;
	case 6:
		ArmorBar7->SetPercent(0);
		break;
	case 7:
		ArmorBar8->SetPercent(0);
		break;
	default:
		break;
	}
}

void UHealthBarUserWidgetMaster::UpdateBullets(int Value)
{
	BulletsValue->SetText(FText::AsNumber(Value));
}

void UHealthBarUserWidgetMaster::UpdateMags(int Value)
{
	MagsValue->SetText(FText::AsNumber(Value));
}


