// Fill out your copyright notice in the Description page of Project Settings.

#include "SI/Player/Public/SICharacter.h"
#include "PistolBarrellAnimNotify.h"

class ASICharacter;

void UPistolBarrellAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{
		ASICharacter* Player = Cast<ASICharacter>(MeshComp->GetOwner());

		if (Player != nullptr)
		{
			Player->GetSpawnedWeaponAsWeaponMaster()->AnimatePistolBarrel();
		}
	}
}
