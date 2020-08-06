// Fill out your copyright notice in the Description page of Project Settings.


#include "SICharacter.h"
#include "SI/Weapons/Public/WeaponPickupMaster.h"
#include "SI/CameraManager/Public/MyPlayerCameraManager.h"
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

	// Add health component
	HealthComponent = CreateDefaultSubobject<USI_HealthComponent>(TEXT("HealthComp"));

	// Add healthWidget component
	static ConstructorHelpers::FClassFinder<UHealthBarUserWidgetMaster> HealthBarUIBPClass(TEXT("/Game/UI/SI_Healthbar.SI_Healthbar_C"));

	if (HealthBarUIBPClass.Class != nullptr && HealthBarUIBPClass.Succeeded())
	{
		HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidgetComp"));
		HealthWidgetComponent->SetupAttachment(RootComponent);
		HealthWidgetComponent->SetWidgetClass(HealthBarUIBPClass.Class);
	}

}

void ASICharacter::EquipWeapon()
{
	// Move from holster or backpack socket to hand socket
	AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

	if (WeaponMaster)
	{
		bIsWeaponEquiped = true;

		if (!bIsCombatMode)
		{
			ToggleCombatMode();
		}

		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);

		if (WeaponMaster->bIsKnife)
		{
			SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("knifeSocket"), RTS_World));
			SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("knifeSocket"));

			if (bIsCrouching)
			{
				EndCrouch();
			}

		}
		else if (WeaponMaster->bIsPistol)
		{
			SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("pistolSocket"), RTS_World));
			SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("pistolSocket"));
			/*EndCrouch();
			EndAim();*/
		}
		else
		{
			SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("rifleSocket"), RTS_World));
			SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("rifleSocket"));
		}

		LaserSightOff();



		//UGameplayStatics::PlaySoundAtLocation(GetWorld(), GetSpawnedWeaponAsWeaponMaster()->ReloadSoundFx, GetActorLocation());

	}


}

void ASICharacter::UnequipWeapon(bool bForceLast)
{
	int index = bForceLast ? WeaponInventory.Num() - 1 : WeaponInventoryIndex;
	AWeaponActualMaster* WeaponMaster = !bForceLast ? GetSpawnedWeaponAsWeaponMaster() : Cast<AWeaponActualMaster>(SpawnedWeapons[index]);

	if (WeaponMaster)
	{
		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);

		if (WeaponMaster->bIsKnife)
		{
			SpawnedWeapons[index]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("knifeHolsterSocket"), RTS_World));
			SpawnedWeapons[index]->AttachToComponent(GetMesh(), TransformRules, TEXT("knifeHolsterSocket"));
		}
		else if (WeaponMaster->bIsPistol)
		{
			SpawnedWeapons[index]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("holsterSocket"), RTS_World));
			SpawnedWeapons[index]->AttachToComponent(GetMesh(), TransformRules, TEXT("holsterSocket"));
		}
		else
		{
			bRifleHolsterSocketIsTaken = !bRifleHolsterSocketIsTaken;
			if (bRifleHolsterSocketIsTaken)
			{
				SpawnedWeapons[index]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("rifleHolsterSocket2"), RTS_World));
				SpawnedWeapons[index]->AttachToComponent(GetMesh(), TransformRules, TEXT("rifleHolsterSocket2"));
			}
			else
			{
				SpawnedWeapons[index]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("rifleHolsterSocket"), RTS_World));
				SpawnedWeapons[index]->AttachToComponent(GetMesh(), TransformRules, TEXT("rifleHolsterSocket"));

			}
		}

		if (index == 0 && WeaponInventory.Num() == 1 && bIsCombatMode)
		{
			ToggleCombatMode();
		}

		bIsWeaponEquiped = false;
	}

}



void ASICharacter::SpawnWeapon(TSubclassOf<AWeaponActualMaster> WeaponToSpawn)
{
	if (WeaponToSpawn)
	{
		/*if (!bIsCombatMode && !bIsWeaponEquiped)
		{
			ToggleCombatMode();
		}*/

		int index = WeaponInventory.AddUnique(WeaponToSpawn);

		if (index != -1)
		{
			//WeaponInventoryIndex = index;

			FTransform SocketTransform;

			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = this;

			SpawnedWeapons.Add(GetWorld()->SpawnActor<AWeaponActualMaster>(WeaponToSpawn, SocketTransform, spawnParams));
			UnequipWeapon(true);

			/*if (bIsWeaponEquiped)
			{
				bIsWeaponEquiped->Destroy();
			}*/

			/*FTransform SocketTransform;

			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = this;*/

			//FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);



			//AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

			/*if (WeaponMaster->bIsPistol)
			{
				SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("holsterSocket"), RTS_World));
				SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("holsterSocket"));
			}
			else if (WeaponMaster->bIsKnife)
			{
				SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("knifeHolsterSocket"), RTS_World));
				SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("knifeHolsterSocket"));
				EndCrouch();
			}
			else
			{
				SpawnedWeapons[WeaponInventoryIndex]->SetActorTransform(GetMesh()->GetSocketTransform(TEXT("rifleSocket"), RTS_World));
				SpawnedWeapons[WeaponInventoryIndex]->AttachToComponent(GetMesh(), TransformRules, TEXT("rifleSocket"));
			}*/

			/*	if (WeaponMaster->bIsKnife)
				{
					EndAim();
				}

				LaserSightOff();


				UGameplayStatics::PlaySoundAtLocation(GetWorld(), GetSpawnedWeaponAsWeaponMaster()->ReloadSoundFx, GetActorLocation());*/

				//bIsWeaponEquiped->K2_AttachRootComponentTo(GetMesh(), fnWeaponSocket, EAttachLocation::SnapToTarget, true);

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

	// Hit Reaction Transition Timeline Curve
	BindTimelineToCurve(HitReactionTimeline, FName("AnimateHitBlendWeight"), HitReactionCurveFloat);
	BindTimelineFinished(HitReactionTimeline, FName("ResetHitReaction"));

	// Listen for health changed events
	HealthComponent->OnHealthChanged.AddDynamic(this, &ASICharacter::OnHealthChanged);

	if (HealthWidgetComponent)
	{
		HealthWidgetComponent->GetUserWidgetObject()->AddToPlayerScreen();
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

void ASICharacter::SetCrouch()
{
	if (bIsWeaponEquiped && bIsCombatMode)
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

void ASICharacter::ToggleCombatMode()
{
	if (!bIsWeaponEquiped)
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
	if (bIsEquipingWeapon)
	{
		return;

	}
	if (bIsWeaponEquiped && WeaponInventory.Num() == 1)
	{
		return;
	}
	else if (WeaponInventory.Num() >= 1)
	{
		UnequipWeapon(false);

		if (WeaponInventoryIndex >= WeaponInventory.Num() - 1)
		{
			WeaponInventoryIndex = 0;
		}
		else
		{
			WeaponInventoryIndex += 1;
		}

		PlayEquipWeaponMontage();

		//EquipWeapon();
		//SpawnWeapon(WeaponInventory[WeaponInventoryIndex]);

	}
}

void ASICharacter::DecrementInventory()
{
	if (bIsEquipingWeapon)
	{
		return;
	}

	if (WeaponInventory.Num() >= 1)
	{
		UnequipWeapon(false);

		if (WeaponInventoryIndex > 0)
		{
			WeaponInventoryIndex -= 1;
		}
		else
		{
			WeaponInventoryIndex = WeaponInventory.Num() - 1;
		}

		if (WeaponInventory.Num() > 1)
		{
			PlayEquipWeaponMontage();
		}


		//SpawnWeapon(WeaponInventory[WeaponInventoryIndex]);
	}
}

void ASICharacter::BeginAim()
{

	if (bIsWeaponEquiped)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (!bIsCombatMode)
		{
			ToggleCombatMode();
		}

		bIsAiming = true;

		AimTimeline.Play();
	}

}

void ASICharacter::EndAim()
{
	if (bIsWeaponEquiped)
	{
		if (bIsCombatMode)
		{
			bIsAiming = false;

			Hud->SetCrossHairVisibility(true);

			AimTimeline.Reverse();

			GetSpawnedWeaponAsWeaponMaster()->StopAim();
			LaserSightOff();
		}
	}
}

void ASICharacter::Fire()
{
	if (bIsEquipingWeapon)
	{
		return;
	}
	if (bIsWeaponEquiped)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bIsAutomatic && !WeaponMaster->bIsGrenadeMode)
		{
			StartAutoFire();
		}
		else
		{
			BeginFireWeapon();
		}
	}
	else
	{
		if (WeaponInventory.Num() > 0)
		{
			EquipWeapon();
		}
	}

}

void ASICharacter::BeginFireWeapon()
{

	if (bIsReloading)
	{
		return;
	}

	if (bIsWeaponEquiped)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bIsKnife && bIsFiring)
		{
			return;
		}

		if (WeaponMaster && WeaponMaster->CanFire())
		{
			if (!WeaponMaster->bIsGrenadeMode)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(WeaponMaster->ShootAnimMontage);
			}
			else
			{
				GetMesh()->GetAnimInstance()->Montage_Play(WeaponMaster->ShootGrenadeAnimMontage);
			}
			bIsFiring = true;

			WeaponMaster->Fire();

			LastFireTime = GetWorld()->TimeSeconds;
		}

		//TODO: else play sound effect of no ammo
	}
}

void ASICharacter::EndFireWeapon()
{
	/*GetMesh()->GetAnimInstance()->Montage_Stop(PlayingMontage);*/

	//GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);

	if (bIsWeaponEquiped && !GetSpawnedWeaponAsWeaponMaster()->bIsKnife)
	{
		bIsFiring = false;
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bIsAutomatic)
		{
			StopAutoFire();
		}
	}

}

void ASICharacter::StartAutoFire()
{
	AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();
	float FirstDelay = FMath::Max(LastFireTime + WeaponMaster->TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);

	GetWorldTimerManager().SetTimer(
		TimeBetweenShotsTimerHandle, this, &ASICharacter::BeginFireWeapon, GetSpawnedWeaponAsWeaponMaster()->TimeBetweenShots, true, FirstDelay);
}

void ASICharacter::StopAutoFire()
{
	GetWorldTimerManager().ClearTimer(TimeBetweenShotsTimerHandle);
}

void ASICharacter::SetWeaponGrenadeMode()
{
	if (bIsWeaponEquiped)
	{
		GetSpawnedWeaponAsWeaponMaster()->SetGrenadeMode();
	}
}

void ASICharacter::Reload()
{
	if (bIsCombatMode && bIsWeaponEquiped)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bIsKnife)
		{
			return;
		}

		bIsReloading = true;


		if (!WeaponMaster->bIsGrenadeMode)
		{
			/*if (WeaponMaster->ReloadSoundFx)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), WeaponMaster->ReloadSoundFx, SpawnedWeapons[WeaponInventoryIndex]->GetActorLocation());
			}*/

			GetMesh()->GetAnimInstance()->Montage_Play(WeaponMaster->ReloadMontage);
		}
		else
		{
			GetMesh()->GetAnimInstance()->Montage_Play(GetSpawnedWeaponAsWeaponMaster()->ReloadGrenadeMontage);
		}

	}
}

void ASICharacter::ToggleWalkMode()
{
	bIsWalkMode = !bIsWalkMode;

	SetWalkSpeed(bIsWalkMode ? DefaultWalkSpeed : DefaultRunSpeed);
}

void ASICharacter::ToggleLaserSight()
{
	if (bIsCombatMode && bIsWeaponEquiped)
	{
		AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

		if (WeaponMaster->bHasLaserSight)
		{
			if (!WeaponMaster->bLaserSightOn)
			{
				Hud->SetCrossHairVisibility(false);
				WeaponMaster->bLaserSightOn = true;
				return;
			}
		}

		LaserSightOff();
	}
}

void ASICharacter::LaserSightOff()
{
	if (bIsWeaponEquiped && bIsCombatMode)
	{

		Hud->SetCrossHairVisibility(!GetSpawnedWeaponAsWeaponMaster()->bIsKnife);
		GetSpawnedWeaponAsWeaponMaster()->bLaserSightOn = false;
	}

}

void ASICharacter::HolsterEquipedWeapon()
{
	if (bIsWeaponEquiped)
	{
		if (bIsCombatMode)
		{
			ToggleCombatMode();
		}

		UnequipWeapon(false);
	}

}

void ASICharacter::OnHealthChanged(USI_HealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType,
	class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Health <= 0.0f && !bDied)
	{
		// Die
		Die();
	}
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
	if (bIsWeaponEquiped && GetSpawnedWeaponAsWeaponMaster() != nullptr && GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine != nullptr)
	{
		/*GetSpawnedWeaponAsWeaponMaster()->ReloadAudioComponent->Play();*/

		FTransform MagazineTransform = GetSpawnedWeaponAsWeaponMaster()->GetMagazineTransform();
		MagazineTransform.SetScale3D(FVector(1, 1, 1));
		MagazineTransform.SetRotation(FQuat(0, 0, 0, 0));

		GetSpawnedWeaponAsWeaponMaster()->SetMagazineVisible(false);

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = SpawnedWeapons[WeaponInventoryIndex];
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
	if (bIsWeaponEquiped && GetSpawnedWeaponAsWeaponMaster() != nullptr && GetSpawnedWeaponAsWeaponMaster()->DynamicMagazine != nullptr)
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
	if (bIsWeaponEquiped && GetSpawnedWeaponAsWeaponMaster() != nullptr)
	{
		if (SpawnedMagazine)
		{
			SpawnedMagazine->Destroy();
		}

		GetSpawnedWeaponAsWeaponMaster()->SetMagazineVisible(true);
	}

}

void ASICharacter::Hit(FName HitBone, float HitMagnitude)
{
	if (!bIsHit)
	{
		if (!bDied)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), HitAudioFx, GetActorLocation());
		}

		if (HitBone != "pelvis")
		{
			bIsHit = true;
			HitBoneName = HitBone;
			HitReactionTimeline.PlayFromStart();
		}

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


void ASICharacter::AnimateHitBlendWeight(float Value)
{
	HitBlendWeight = Value;
}

void ASICharacter::ResetHitReaction()
{
	/*HitBlendWeight = 0.0f;*/
	/*GetWorldTimerManager().SetTimer(
		HitReactionTimerHandle, this, &ASICharacter::ApplyForceToHitBone, 0.048f, true);*/
		/*UE_LOG(LogTemp, Warning, TEXT("ResetHitReaction"));*/
	HitBlendWeight = 0.0f;
	GetMesh()->SetAllBodiesPhysicsBlendWeight(HitBlendWeight);
	GetMesh()->SetAllBodiesSimulatePhysics(false);
	bIsHit = false;
	bAppliedForceToBone = false;
	/*GetWorld()->GetTimerManager().ClearTimer(HitReactionTimerHandle);*/

}

void ASICharacter::ApplyForceToHitBone()
{
	/*FVector ForceVector = GetActorForwardVector(CameraComp->GetComponentRotation()) * 1200.0f;*/
	bAppliedForceToBone = true;

	AMyPlayerCameraManager* CameraManager = Cast<AMyPlayerCameraManager>(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0));
	if (CameraManager)
	{
		/*UE_LOG(LogTemp, Warning, TEXT("ApplyForceToHibBone"));*/
		FVector FowardVector = UKismetMathLibrary::GetForwardVector(CameraManager->K2_GetActorRotation());
		FVector ForceVector = FowardVector * 1150.0f;

		GetMesh()->AddImpulse(ForceVector, HitBoneName, true);

		/*GetWorldTimerManager().SetTimer(
		HitReactionTimerHandle, this, &ASICharacter::ResetHitReaction, 0.048f, true);*/
	}

}


// Called every frame
void ASICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ModesTransitionTimeline.TickTimeline(DeltaTime);

	AimTimeline.TickTimeline(DeltaTime);

	CrouchTransitionTimeline.TickTimeline(DeltaTime);

	HitReactionTimeline.TickTimeline(DeltaTime);

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

	if (HitBlendWeight > 0.0f && !bAppliedForceToBone)
	{
		GetMesh()->SetAllBodiesBelowSimulatePhysics(HitBoneName, true);
		GetMesh()->SetAllBodiesBelowPhysicsBlendWeight(HitBoneName, HitBlendWeight);
		ApplyForceToHitBone();

	}

	if (HealthWidgetComponent)
	{
		PositionHealthBar();
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

	PlayerInputComponent->BindAction("CombatMode", IE_Pressed, this, &ASICharacter::ToggleCombatMode);

	PlayerInputComponent->BindAction("IncrementInventory", IE_Pressed, this, &ASICharacter::IncrementInventory);

	PlayerInputComponent->BindAction("DecrementInventory", IE_Pressed, this, &ASICharacter::DecrementInventory);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ASICharacter::BeginAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ASICharacter::EndAim);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASICharacter::Fire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASICharacter::EndFireWeapon);

	PlayerInputComponent->BindAction("GrenadeMode", IE_Pressed, this, &ASICharacter::SetWeaponGrenadeMode);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ASICharacter::Reload);

	PlayerInputComponent->BindAction("ToggleWalkMode", IE_Pressed, this, &ASICharacter::ToggleWalkMode);

	PlayerInputComponent->BindAction("ToggleLaserSight", IE_Pressed, this, &ASICharacter::ToggleLaserSight);

	PlayerInputComponent->BindAction("HolsterEquipedWeapon", IE_Pressed, this, &ASICharacter::HolsterEquipedWeapon);
}

#pragma region Private
void ASICharacter::BindTimelineToCurve(FTimeline& Timeline, FName FunctionName, UCurveFloat* Curve)
{
	if (Curve != nullptr)
	{
		FOnTimelineFloat TimelineFunction;

		TimelineFunction.BindUFunction(this, FunctionName);
		Timeline.AddInterpFloat(Curve, TimelineFunction);
		Timeline.SetLooping(false);
	}
}

void ASICharacter::BindTimelineFinished(FTimeline& Timeline, FName FunctionName)
{
	FOnTimelineEventStatic TimelineFinishedFunction;

	TimelineFinishedFunction.BindUFunction(this, FunctionName);
	Timeline.SetTimelineFinishedFunc(TimelineFinishedFunction);
}

void ASICharacter::SetWalkSpeed(float Speed)
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

void ASICharacter::PlayEquipWeaponMontage()
{
	AWeaponActualMaster* WeaponMaster = GetSpawnedWeaponAsWeaponMaster();

	if (WeaponMaster)
	{
		bIsEquipingWeapon = true;

		GetMesh()->GetAnimInstance()->Montage_Play(WeaponMaster->EquipAnimMontage);
	}

}

void ASICharacter::Die()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), DieAudioFx, GetActorLocation());

	bDied = true;

	GetMovementComponent()->StopMovementImmediately();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	DetachFromControllerPendingDestroy();

	SetLifeSpan(10.0f);

}

void ASICharacter::PositionHealthBar()
{
	FVector Location = GetActorLocation();
	FVector FwdVector = GetActorForwardVector() * 350.0f;
	UUserWidget* UserWidget = HealthWidgetComponent->GetUserWidgetObject();
	//if (FwdVector.X >= 0)
	//{
	//	UserWidget->SetRenderShear(FVector2D(0.0f, 15.0f));
	//	//UserWidget->SetRenderTransformAngle(45.0f);
	//}
	//else if (FwdVector.X < 0)

	//{
	//	UserWidget->SetRenderShear(FVector2D(-6.0f, -15.0f));
	//	UserWidget->SetRenderTransformAngle(-7.0f);
	//}
	
	
	UserWidget->SetRenderTranslation(FVector2D(FwdVector.X, 150.0f));
}

#pragma endregion


