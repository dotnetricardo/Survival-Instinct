// Copyright Epic Games, Inc. All Rights Reserved.

#include "SI/Widget/Public/HUDBase.h"
#include "SI/Player/Public/SICharacter.h"
#include "SIGameModeBase.h"

ASIGameModeBase::ASIGameModeBase() : Super()
{
	DefaultPawnClass = ASICharacter::StaticClass();
	HUDClass = AHUDBase::StaticClass();
}