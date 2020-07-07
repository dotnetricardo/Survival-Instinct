// Fill out your copyright notice in the Description page of Project Settings.


#include "SICharacter.h"
#include "SI/Weapons/Public/WeaponPickupMaster.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathVectorCommon.h"



// Sets default values
ASICharacter::ASICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;

	// Allow player to crouch
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	bUseControllerRotationYaw = false;
	
	// rotate the Character toward the direction of acceleration
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->bUsePawnControlRotation = false;
	CameraComp->SetupAttachment(SpringArmComp);

	// Set defaults
	MaxWeaponsCarry = 2;

	
}

void ASICharacter::SpawnWeapon(TSubclassOf<AWeaponActualMaster> WeaponToSpawn)
{
	if (WeaponToSpawn)
	{
		if (!bIsCombatMode && !SpawnedWeapon)
		{
			CombatMode();
		}
		
		int index = WeaponInventory.AddUnique(WeaponToSpawn);

		if (index != -1)
		{
			WeaponInventoryIndex = index;

			// Spawn Weapon
			if (SpawnedWeapon)
			{
				SpawnedWeapon->Destroy();
			}

			FName fnWeaponSocket = TEXT("WeaponSocket");
			
			FTransform SocketTransform = GetMesh()->GetSocketTransform(TEXT("WeaponSocket"), RTS_World);
			
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = this;

			FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);

			SpawnedWeapon = GetWorld()->SpawnActor<AWeaponActualMaster>(WeaponToSpawn, SocketTransform);

			SpawnedWeapon->AttachToComponent(GetMesh(), TransformRules, fnWeaponSocket);

			//SpawnedWeapon->K2_AttachRootComponentTo(GetMesh(), fnWeaponSocket, EAttachLocation::SnapToTarget, true);
			
		}

	}
}

// Called when the game starts or when spawned
void ASICharacter::BeginPlay()
{
	Super::BeginPlay();

	// Timeline Curve
	if (SwichModesCurveFloat)
	{
		FOnTimelineFloat ProgressFunction;

		ProgressFunction.BindUFunction(this, FName("AnimateCameraLocation"));
		ModesTransitionTimeline.AddInterpFloat(SwichModesCurveFloat, ProgressFunction);
		ModesTransitionTimeline.SetLooping(false);
	}
}

void ASICharacter::MoveFoward(float Value)
{
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(Direction * Value);
}

void ASICharacter::MoveRight(float Value)
{
	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement in that direction
	AddMovementInput(Direction, Value);
}

void ASICharacter::Turn(float Value)
{
	InputAxisYawValue = Value;
	AddControllerYawInput(Value);
}

void ASICharacter::BeginCrouch()
{
	Crouch();
}

void ASICharacter::EndCrouch()
{
	UnCrouch();
}

void ASICharacter::CombatMode()
{
	if (!SpawnedWeapon)
	{
		return;
	}
	
	bIsCombatMode = !bIsCombatMode;

	if (bIsCombatMode)
	{
		Controller->SetControlRotation(SpringArmComp->GetComponentRotation());
	}
	
	
	GetCharacterMovement()->bOrientRotationToMovement = !bIsCombatMode;
	
	GetCharacterMovement()->bUseControllerDesiredRotation = bIsCombatMode;
	
	GetMesh()->SetRelativeRotation(bIsCombatMode ? CombatModeCharacterRotation : DefaultModeCharacterRotation);	
	
	ModesTransitionTimeline.PlayFromStart();

	Hud = Cast<AHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	Hud->SetCrossHairVisibility(bIsCombatMode);

}


void ASICharacter::IncrementInventory()
{
	if (WeaponInventory.Num() > 1)
	{
		if (WeaponInventoryIndex >= WeaponInventory.Num() - 1)
		{
			WeaponInventoryIndex = 0;
		}
		else
		{
			WeaponInventoryIndex+=1;
		}

		SpawnWeapon(WeaponInventory[WeaponInventoryIndex]);
		
	}
}

void ASICharacter::DecrementInventory()
{
	if (WeaponInventory.Num() > 1)
	{
		if (WeaponInventoryIndex > 0)
		{
			WeaponInventoryIndex -= 1;
		}
		else
		{
			WeaponInventoryIndex = WeaponInventory.Num() - 1;
		}

		SpawnWeapon(WeaponInventory[WeaponInventoryIndex]);
	}
}

//void ASICharacter::Interact()
//{
//	TArray<AActor*> OverlappingActors;
//	TSubclassOf<AWeaponPickupMaster> ClassFilter;
//	GetOverlappingActors(&OverlappingActors, ClassFilter);
//
//	if (OverlappingActors)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Overlapping"));
//	}
//
//
//}

void ASICharacter::AnimateCameraLocation(float Value)
{
	FVector NewLocation = bIsCombatMode ? FMath::Lerp(DefaultModeSpringArmVector, CombatModeSpringArmVector, Value) : FMath::Lerp(CombatModeSpringArmVector, DefaultModeSpringArmVector, Value);
	SpringArmComp->SetRelativeLocation(NewLocation);

	FRotator NewRotation = bIsCombatMode ? FMath::Lerp(DefaultModeCamRotation, CombatModeCamRotation, Value) : FMath::Lerp(CombatModeCamRotation, DefaultModeCamRotation, Value);
	CameraComp->SetRelativeRotation(NewRotation);
}


// Called every frame
void ASICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ModesTransitionTimeline.TickTimeline(DeltaTime);

	if (bIsCombatMode && Hud)
	{
		float VelocityMagnitude = GetVelocity().Size();
		

		float RangeUnclampled = UKismetMathLibrary::MapRangeUnclamped(VelocityMagnitude, 0, 600.0f, 1.0f, 1.3f);

		Hud->UpdateCrossHairSize(RangeUnclampled);
	}

}


// Called to bind functionality to input
void ASICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASICharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASICharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ASICharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ASICharacter::Turn);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASICharacter::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASICharacter::EndCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	
	PlayerInputComponent->BindAction("CombatMode", IE_Pressed, this, &ASICharacter::CombatMode);

	PlayerInputComponent->BindAction("IncrementInventory", IE_Pressed, this, &ASICharacter::IncrementInventory);

	PlayerInputComponent->BindAction("DecrementInventory", IE_Pressed, this, &ASICharacter::DecrementInventory);

}

