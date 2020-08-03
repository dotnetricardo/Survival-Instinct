// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SI/Weapons/Public/WeaponActualMaster.h"
#include "SI/Widget/Public/HUDBase.h"
#include "SI/Weapons/Public/DynamicMagazineMaster.h"
#include "SI/Health/Public/SI_HealthComponent.h"
#include "GameFramework/Character.h"
#include "Components/TimelineComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "TimerManager.h"
#include "SICharacter.generated.h"



class UCameraComponent;
class USpringArmComponent;
class UCurveFloat;
class AHUDBase;
class AWeaponActualMaster;
class UCapsuleComponent;
class UAnimMontage;
class ADynamicMagazineMaster;
class USI_HealthComponent;


UCLASS()
class SI_API ASICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASICharacter();

	UPROPERTY(BlueprintReadWrite, Category = "Default")
	bool bIsCombatMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float DefaultWalkSpeed = 300;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float DefaultRunSpeed = 600;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	float InputAxisYawValue = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	bool bIsCrouching;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	bool bIsFiring;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	bool bIsWalkMode;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int WeaponInventoryIndex;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	TArray<TSubclassOf<AWeaponActualMaster>> WeaponInventory;

	bool bIsWeaponEquiped;

	bool bIsEquipingWeapon;
	
	UPROPERTY(BlueprintReadOnly, Category = "Default")
	TArray<AActor*> SpawnedWeapons;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	void SpawnWeapon(TSubclassOf<AWeaponActualMaster> WeaponToSpawn);
	
	void EquipWeapon();

	void UnequipWeapon(bool bForceLast);

	bool CanAddMags();

	void AddMags(int WeaponMags, int GrenadeMags);

	void ReleaseMagazine();
	
	void SpawnMagazine();

	void AttachMagazine();

	void Hit(FName HitBone, float HitMagnitude);
	
	//virtual FVector GetPawnViewLocation() const override;

	FORCEINLINE AWeaponActualMaster* GetSpawnedWeaponAsWeaponMaster() const { return SpawnedWeapons.Num() > 0 ? Cast<AWeaponActualMaster>(SpawnedWeapons[WeaponInventoryIndex]) : nullptr; }

	AActor* SpawnedMagazine;

	bool bIsReloading;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveFoward(float Value);
	
	void MoveRight(float Value);

	void Turn(float Value);

	void SetCrouch();

	void EndCrouch();

	void ToggleCombatMode();

	void IncrementInventory();

	void DecrementInventory();

	void BeginAim();

	void EndAim();

	void Fire();

	void BeginFireWeapon();

	void EndFireWeapon();

	void StartAutoFire();

	void StopAutoFire();

	void SetWeaponGrenadeMode();

	void Reload();
	
	void ToggleWalkMode();

	void ToggleLaserSight();
	
	void LaserSightOff();

	void HolsterEquipedWeapon();

	USI_HealthComponent* HealthComponent;

	FTimerHandle TimeBetweenShotsTimerHandle;

	/*FTimerHandle HitReactionTimerHandle;*/

	AHUDBase* Hud;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* SwichModesCurveFloat;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* AimCurveFloat;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* HitReactionCurveFloat;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int WeaponMagsCount;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int GrenadeMagsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	int MaxWeaponMagsCarry;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	int MaxGrenameMagsCarry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	int MaxWeaponsCarry = 4;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	bool bDied;
	
	FRotator CombatModeCharacterRotation = FRotator(0, -81.0f, 0); //y (pitch), z (yaw), x (roll)
	
	FRotator DefaultModeCharacterRotation = FRotator(0, -90.0f, 0);

	FVector CombatModeSpringArmVector = FVector(0, 33.0f, 76.0f); // x, y, z

	FVector DefaultModeSpringArmVector = FVector(0, 28.0f, 76.0f);

	FRotator CombatModeCamRotation = FRotator(0, 3.6f, 0);

	FRotator DefaultModeCamRotation = FRotator(0, 0, 0);

	FTimeline ModesTransitionTimeline;

	FTimeline AimTimeline;

	FTimeline CrouchTransitionTimeline;

	FTimeline HitReactionTimeline;

	bool bIsAiming;

	UFUNCTION()
	void OnHealthChanged(USI_HealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
private:

	bool bRifleHolsterSocketIsTaken;

	bool bIsHit;

	bool bAppliedForceToBone;

	float LastFireTime;

	float HitBlendWeight;

	FName HitBoneName;

	UFUNCTION()
	void AnimateCameraLocation(float Value);

	UFUNCTION()
	void AnimateSpringArmLength(float Value);

	UFUNCTION()
	void AnimateSpringArmHeight(float Value);

	UFUNCTION()
	void AnimateHitBlendWeight(float Value);

	UFUNCTION()
	void ApplyForceToHitBone();

	UFUNCTION()
	void ResetHitReaction();

	void BindTimelineToCurve(FTimeline &Timeline, FName FunctionName, UCurveFloat* Curve);

	void BindTimelineFinished(FTimeline& Timeline, FName FunctionName);

	/*float PlayingMontage;*/

	void SetWalkSpeed(float Speed);

	void PlayEquipWeaponMontage();

	void Die();	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};


