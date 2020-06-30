// Fill out your copyright notice in the Description page of Project Settings.


#include "SICharacter.h"

// Sets default values
ASICharacter::ASICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASICharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ASICharacter::MoveFoward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void ASICharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// Called every frame
void ASICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveFoward", this, &ASICharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASICharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ASICharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ASICharacter::AddControllerYawInput);
}

