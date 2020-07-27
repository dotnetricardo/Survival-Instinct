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
#include "Kismet/GameplayStatics.h"


class AMyPlayerCameraManager;

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

	// Set capsule collision presets
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("SI_CapsuleCollision"));
	GetMesh()->SetCollisionProfileName(TEXT("SI_CharacterMeshCollision"));

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
		
			FTransform SocketTransform;
			
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = this;

			FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);

			SpawnedWeapon = GetWorld()->SpawnActor<AWeaponActualMaster>(WeaponToSpawn, SocketTransform, spawnParams);

			if (GetSpawnedWeaponAsWeaponMaster()->bIsPistol)
			{
				SpawnedWeapon->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("pistolSocket"), RTS_World));
				SpawnedWeapon->AttachToComponent(GetMesh(), TransformRules, TEXT("pistolSocket"));
			}
			else
			{
				SpawnedWeapon->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("rifleSocket"), RTS_World));
				SpawnedWeapon->AttachToComponent(GetMesh(), TransformRules, TEXT("rifleSocket"));
			}
			
			
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), GetSpawnedWeaponAsWeaponMaster()->ReloadSoundFx, GetActorLocation());

			//SpawnedWeapon->K2_AttachRootComponentTo(GetMesh(), fnWeaponSocket, EAttachLocation::SnapToTarget, true);
			
		}

	}
}

//FVector ASICharacter::GetPawnViewLocation() const
//{
//	if (CameraComp)
//	{
//		return CameraComp->GetComponentLocation();
//	}
//
//	return Super::GetPawnViewLocation();
//}

// Called when the game starts or when spawned
void ASICharacter::BeginPlay()
{
	Super::BeginPlay();

	// Modes Transition Timeline Curve
	BindTimelineToCurve(ModesTransitionTimeline, FName("AnimateCameraLocation"), SwichModesCurveFloat);

	// Aim Transition Timeline Curve
	BindTimelineToCurve(AimTimeline, FName("AnimateSpringArmLength"), AimCurveFloat);

	// Crouch Transition Timeline Curve
	BindTimelineToCurve(CrouchTransitionTimeline, FName("AnimateSpringArmHeight"), SwichModesCurveFloat);
	
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

void ASICharacter::SetCrouch()
{
	if (SpawnedWeapon && bIsCombatMode)
	{
		bIsCrouching = !bIsCrouching;
		CrouchTransitionTimeline.PlayFromStart();
	}
}

void ASICharacter::EndCrouch()
{
	bIsCrouching = false;
	CrouchTransitionTimeline.PlayFromStart();
}

void ASICharacter::CombatMode()
{
	if (!SpawnedWeapon)
	{
		return;
	}

	SetWalkSpeed(DefaultRunSpeed);
	
	if (bIsCombatMode)
	{
		// Can only crouch in combat mode
		EndCrouch();

		// Can only aim in combat mode
		EndAim();

		if (bIsWalkMode)
		{
			SetWalkSpeed(DefaultWalkSpeed);
		}
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

	// Cross hair
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

void ASICharacter::BeginAim()
{

	if (SpawnedWeapon)
	{
		if (!bIsCombatMode)
		{
			CombatMode();
		}

		bIsAiming = true;
		
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bHasLaserSight || WeaponMaster->bHasMicroscopicSight)
		{
			Hud->SetCrossHairVisibility(false);
		}
		
		AimTimeline.Play();
	}
	
}

void ASICharacter::EndAim()
{
	if (bIsCombatMode)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		bIsAiming = false;

		if (WeaponMaster->bHasLaserSight || WeaponMaster->bHasMicroscopicSight)
		{
			Hud->SetCrossHairVisibility(true);
		}
		
		AimTimeline.Reverse();

		WeaponMaster->StopAim();
		
	}
}

void ASICharacter::BeginFireWeapon()
{
	
	if (bIsReloading)
	{
		return;
	}

	if (!bIsCombatMode)
	{
		CombatMode();
	}
	
	if (SpawnedWeapon)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();
		if (GetSpawnedWeaponAsWeaponMaster()->CanFire())
		{
			bIsFiring = true;

			if (ShootOnceAnimMontage && ShootGrenadeAnimMontage)
			{
				if (!WeaponMaster->bIsGrenadeMode)
				{
					if (!WeaponMaster->bIsAutomatic)
					{
						//GetSpawnedWeaponAsWeaponMaster()->ShootAudioComponent->Play();

						if (WeaponMaster->ShootSoundFx)
						{
							UGameplayStatics::PlaySoundAtLocation(GetWorld(), WeaponMaster->ShootSoundFx, SpawnedWeapon->GetActorLocation());
						}
						
						if (ShootOnceAnimMontage && ShootOnceHandgunAnimMontage)
						{
							GetMesh()->GetAnimInstance()->Montage_Play(!WeaponMaster->bIsPistol ? ShootOnceAnimMontage : ShootOnceHandgunAnimMontage);
						}
						
					}
				}
				else 
				{
					if (WeaponMaster->ShootGrenadeSoundFx)
					{
						UGameplayStatics::PlaySoundAtLocation(GetWorld(), WeaponMaster->ShootGrenadeSoundFx, SpawnedWeapon->GetActorLocation());
					}
					
					//GetSpawnedWeaponAsWeaponMaster()->ShootGrenadeAudioComponent->Play();
					if (ShootGrenadeAnimMontage)
					{
						GetMesh()->GetAnimInstance()->Montage_Play(ShootGrenadeAnimMontage);
					}
				}
			}
			GetSpawnedWeaponAsWeaponMaster()->Fire();
		
			
		}
		
		//TODO: else play sound effect of no ammo
	}
}

void ASICharacter::EndFireWeapon()
{
	/*GetMesh()->GetAnimInstance()->Montage_Stop(PlayingMontage);*/
	bIsFiring = false;
}

void ASICharacter::SetWeaponGrenadeMode()
{
	if (SpawnedWeapon)
	{
		GetSpawnedWeaponAsWeaponMaster()->SetGrenadeMode();
	}
}

void ASICharacter::Reload()
{
	if (bIsCombatMode && SpawnedWeapon)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();
		
		bIsReloading = true;
	

		if (!WeaponMaster->bIsGrenadeMode)
		{
			if (WeaponMaster->ReloadSoundFx)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), WeaponMaster->ReloadSoundFx, SpawnedWeapon->GetActorLocation());
			}
			
			if (WeaponMaster->ReloadMontage)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(WeaponMaster->ReloadMontage);
			}
		}
		else
		{
			if (WeaponMaster->ReloadGrenadeSoundFx)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), WeaponMaster->ReloadGrenadeSoundFx, SpawnedWeapon->GetActorLocation());
			}
			
			
			if (WeaponMaster->ReloadGrenadeMontage)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(GetSpawnedWeaponAsWeaponMaster()->ReloadGrenadeMontage);
			}
			
		}
		
	}
}

void ASICharacter::ToggleWalkMode()
{
	bIsWalkMode = !bIsWalkMode;

	SetWalkSpeed(bIsWalkMode ? DefaultWalkSpeed : DefaultRunSpeed);
}

void ASICharacter::AddMags(int WeaponMags, int GrenadeMags)
{
	if (MaxWeaponMagsCarry < WeaponMagsCount)
	{
		WeaponMagsCount += WeaponMags;

		if (WeaponMagsCount > MaxWeaponMagsCarry)
		{
			WeaponMagsCount = MaxWeaponMagsCarry;
		}
	}

	if (MaxGrenameMagsCarry < GrenadeMagsCount)
	{
		GrenadeMagsCount += GrenadeMags;

		if (GrenadeMagsCount > MaxGrenameMagsCarry)
		{
			GrenadeMagsCount = MaxGrenameMagsCarry;
		}
	}
}
	
	

void ASICharacter::ReleaseMagazine()
{
	if (SpawnedWeapon != nullptr && GetSpawnedWeaponAsWeaponMaster() != nullptr && GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine != nullptr)
	{
		/*GetSpawnedWeaponAsWeaponMaster()->ReloadAudioComponent->Play();*/

		FTransform MagazineTransform = GetSpawnedWeaponAsWeaponMaster()->GetMagazineTransform();
		MagazineTransform.SetScale3D(FVector(1, 1, 1));
		MagazineTransform.SetRotation(FQuat(0, 0, 0, 0));

		GetSpawnedWeaponAsWeaponMaster()->SetMagazineVisible(false);

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = SpawnedWeapon;
		SpawnParams.Instigator = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ADynamicMagazineMaster* FallingMagazine = GetWorld()->SpawnActor<ADynamicMagazineMaster>(GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine, MagazineTransform, SpawnParams);

		FallingMagazine->MagazineStaticMesh->SetSimulatePhysics(true);

		/*	FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockXRotation = true;
			FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockYRotation = true;
			FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockZRotation = true;*/
			/*FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockXTranslation = true;*/
			//FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockYTranslation = true;
			//FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockZTranslation = true;
			/*FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockXTranslation = true;
			FallingMagazine->MagazineStaticMesh->GetBodyInstance()->bLockYTranslation = true;
			FallingMagazine->MagazineStaticMesh->GetBodyInstance()->SetDOFLock(EDOFMode::SixDOF);*/

			/*	FallingMagazine->MagazineStaticMesh->SetConstraintMode(EDOFMode::YZPlane);*/

				/*FallingMagazine->MagazineStaticMesh->bIgnoreRadialForce = true;
				FallingMagazine->MagazineStaticMesh->bIgnoreRadialImpulse = true;
				FallingMagazine->MagazineStaticMesh->GetBodyInstance()->ClearForces();*/
		
		FallingMagazine->SelfDestructAfterSec(3);

	}
}

void ASICharacter::SpawnMagazine()
{
	if (SpawnedWeapon != nullptr && GetSpawnedWeaponAsWeaponMaster() != nullptr && GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine != nullptr)
	{
		if (SpawnedMagazine)
		{
			SpawnedMagazine->Destroy();
		}

		FName fnMagazineSocket = TEXT("magazineSocket");

		FTransform SocketTransform = GetMesh()->GetSocketTransform(TEXT("magazineSocket"), RTS_World);

		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Instigator = this;

		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);

		SpawnedMagazine = GetWorld()->SpawnActor<ADynamicMagazineMaster>(GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine, SocketTransform, spawnParams);

		SpawnedMagazine->AttachToComponent(GetMesh(), TransformRules, fnMagazineSocket);
	}
}

void ASICharacter::AttachMagazine()
{
	if (SpawnedWeapon != nullptr && GetSpawnedWeaponAsWeaponMaster() != nullptr)
	{
		if (SpawnedMagazine)
		{
			SpawnedMagazine->Destroy();
		}

		GetSpawnedWeaponAsWeaponMaster()->SetMagazineVisible(true);
	}
	
}

bool ASICharacter::CanAddMags()
{
	return WeaponMagsCount < MaxWeaponMagsCarry || GrenadeMagsCount < MaxGrenameMagsCarry;
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

void ASICharacter::AnimateSpringArmLength(float Value)
{
	SpringArmComp->TargetArmLength = Value;
}

void ASICharacter::AnimateSpringArmHeight(float Value)
{
	FVector CombatModeWithZOffsetVector = FVector(CombatModeSpringArmVector.X, CombatModeSpringArmVector.Y, CombatModeSpringArmVector.Z * 0.5f);
	FVector NewLocation = bIsCrouching ? FMath::Lerp(CombatModeSpringArmVector, CombatModeWithZOffsetVector, Value) : FMath::Lerp(CombatModeWithZOffsetVector, CombatModeSpringArmVector, Value);

	SpringArmComp->SetRelativeLocation(NewLocation);
}


// Called every frame
void ASICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ModesTransitionTimeline.TickTimeline(DeltaTime);
	
	AimTimeline.TickTimeline(DeltaTime);

	CrouchTransitionTimeline.TickTimeline(DeltaTime);

	if (bIsCombatMode && Hud)
	{
		// Cross hair size variation according to speed
		float VelocityMagnitude = GetVelocity().Size();

		float RangeUnclampled = UKismetMathLibrary::MapRangeUnclamped(VelocityMagnitude, 0, 600.0f, 1.0f, 1.3f);

		Hud->UpdateCrossHairSize(RangeUnclampled);
	}

	if (bIsAiming)
	{
		/*GetSpawnedWeaponAsWeaponMaster()->UpdateAimLocation(CameraComp->GetComponentToWorld().GetLocation(), CameraComp->GetForwardVector())*/

		GetSpawnedWeaponAsWeaponMaster()->Aim();
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

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASICharacter::SetCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	
	PlayerInputComponent->BindAction("CombatMode", IE_Pressed, this, &ASICharacter::CombatMode);

	PlayerInputComponent->BindAction("IncrementInventory", IE_Pressed, this, &ASICharacter::IncrementInventory);

	PlayerInputComponent->BindAction("DecrementInventory", IE_Pressed, this, &ASICharacter::DecrementInventory);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ASICharacter::BeginAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ASICharacter::EndAim);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASICharacter::BeginFireWeapon);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASICharacter::EndFireWeapon);

	PlayerInputComponent->BindAction("GrenadeMode", IE_Pressed, this, &ASICharacter::SetWeaponGrenadeMode);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ASICharacter::Reload);

	PlayerInputComponent->BindAction("ToggleWalkMode", IE_Pressed, this, &ASICharacter::ToggleWalkMode);
}

#pragma region Private
void ASICharacter::BindTimelineToCurve(FTimeline &Timeline, FName FunctionName, UCurveFloat* Curve)
{
	if (Curve != nullptr)
	{
		FOnTimelineFloat TimelineFunction;

		TimelineFunction.BindUFunction(this, FunctionName);
		Timeline.AddInterpFloat(Curve, TimelineFunction);
		Timeline.SetLooping(false);
	}
}

void ASICharacter::SetWalkSpeed(float Speed)
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

#pragma endregion


