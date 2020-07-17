// Fill out your copyright notice in the Description page of Project Settings.


#include "SI/Player/Public/SICharacter.h"

#include "MagReleaseAnimNotify.h"


class ASICharacter;


void UMagReleaseAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	
	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{

		ASICharacter* Player = Cast<ASICharacter>(MeshComp->GetOwner());

		if (Player != nullptr)
		{
			Player->ReleaseMagazine();
		}
	
	}


	//UE_LOG(LogTemp, Warning, TEXT("UMagReleaseAnimNotify Called"));

	/*int MagBoneIndex = MeshComp->GetBoneIndex(TEXT("Magazine"));

	MeshComp->HideBone(MagBoneIndex, PBO_None);*/
}
