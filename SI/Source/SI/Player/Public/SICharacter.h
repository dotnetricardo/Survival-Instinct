// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SI/Weapons/Public/WeaponActualMaster.h"
#include "SI/Widget/Public/HUDBase.h"
#include "SI/Weapons/Public/DynamicMagazineMaster.h"
#include "GameFramework/Character.h"
#include "Components/TimelineComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "SICharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UCurveFloat;
class AHUDBase;
class AWeaponActualMaster;
class UCapsuleComponent;
class UAnimMontage;
class ADynamicMagazineMaster;


UCLASS()
class SI_API ASICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASICharacter();

	UPROPERTY(BlueprintReadWrite, Category = "Default")
	bool bIsCombatMode;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	float InputAxisYawValue = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	bool bIsCrouching;

	UPROPERTY(BlueprintReadOnly, Category = "Default")
	bool bIsFiring;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int WeaponInventoryIndex;

	UPROPERTY(BlueprintReadWrite, Category = "Default")
	TArray<TSubclassOf<AWeaponActualMaster>> WeaponInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	void SpawnWeapon(TSubclassOf<AWeaponActualMaster> WeaponToSpawn);

	bool CanAddMags();

	void AddMags(int WeaponMags, int GrenadeMags);

	void ReleaseMagazine();
	
	void SpawnMagazine();

	void AttachMagazine();

	//virtual FVector GetPawnViewLocation() const override;

	FORCEINLINE AWeaponActualMaster* GetSpawnedWeaponAsWeaponMaster() const { return Cast<AWeaponActualMaster>(SpawnedWeapon); }

	AActor* SpawnedWeapon;

	AActor* SpawnedMagazine;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveFoward(float Value);
	
	void MoveRight(float Value);

	void Turn(float Value);

	void SetCrouch();

	void EndCrouch();

	void CombatMode();

	void IncrementInventory();

	void DecrementInventory();

	void BeginAim();

	void EndAim();

	void BeginFireWeapon();

	void EndFireWeapon();

	void SetWeaponGrenadeMode();

	void Reload();

	AHUDBase* Hud;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* SwichModesCurveFloat;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* AimCurveFloat;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UAnimMontage* ShootOnceAnimMontage;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UAnimMontage* ShootGrenadeAnimMontage;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int WeaponMagsCount;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	int GrenadeMagsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	int MaxWeaponMagsCarry;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	int MaxGrenameMagsCarry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	int MaxWeaponsCarry;

	FRotator CombatModeCharacterRotation = FRotator(0, -81.0f, 0); //y (pitch), z (yaw), x (roll)
	
	FRotator DefaultModeCharacterRotation = FRotator(0, -90.0f, 0);

	FVector CombatModeSpringArmVector = FVector(0, 33.f, 58.5f); // x, y, z

	FVector DefaultModeSpringArmVector = FVector(0, 0, 58.5f);

	FRotator CombatModeCamRotation = FRotator(0, 3.6f, 0);

	FRotator DefaultModeCamRotation = FRotator(0, 0, 0);

	FTimeline ModesTransitionTimeline;

	FTimeline AimTimeline;

	FTimeline CrouchTransitionTimeline;

	bool bIsAiming;

	
private:
	UFUNCTION()
	void AnimateCameraLocation(float Value);

	UFUNCTION()
	void AnimateSpringArmLength(float Value);

	UFUNCTION()
	void AnimateSpringArmHeight(float Value);

	void BindTimelineToCurve(FTimeline &Timeline, FName FunctionName, UCurveFloat* Curve);

	/*float PlayingMontage;*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};


