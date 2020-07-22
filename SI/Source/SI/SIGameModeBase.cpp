// Copyright Epic Games, Inc. All Rights Reserved.

#include "SI/Widget/Public/HUDBase.h"
#include "SI/Player/Public/SICharacter.h"
#include "SI/PlayerController/Public/SIPlayerController.h"
#include "SIGameModeBase.h"

class ASIPlayerController;

ASIGameModeBase::ASIGameModeBase() : Super()
{
	DefaultPawnClass = ASICharacter::StaticClass();
	HUDClass = AHUDBase::StaticClass();
	PlayerControllerClass = ASIPlayerController::StaticClass();
}