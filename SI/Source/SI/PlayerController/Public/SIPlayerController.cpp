// Fill out your copyright notice in the Description page of Project Settings.


#include "SI/CameraManager/Public/MyPlayerCameraManager.h"
#include "SIPlayerController.h"

class AMyPlayerCameraManager;

ASIPlayerController::ASIPlayerController()
{
	PlayerCameraManagerClass = AMyPlayerCameraManager::StaticClass();
	/*PlayerCameraManager->ViewPitchMax = 70.0f;
	PlayerCameraManager->ViewPitchMin = -70.0f;*/
}