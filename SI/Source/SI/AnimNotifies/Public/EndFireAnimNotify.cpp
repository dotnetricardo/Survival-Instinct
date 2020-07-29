// Fill out your copyright notice in the Description page of Project Settings.

#include "SI/Player/Public/SICharacter.h"
#include "EndFireAnimNotify.h"

class ASICharacter;

void UEndFireAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{
		ASICharacter* Player = Cast<ASICharacter>(MeshComp->GetOwner());

		if (Player != nullptr)
		{
			Player->bIsFiring = false;
		}
	}
}
