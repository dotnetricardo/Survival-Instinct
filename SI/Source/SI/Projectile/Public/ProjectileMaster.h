// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "ProjectileMaster.generated.h"

class UParticleSystem;
class UProjectileMovementComponent;
class USoundCue;
class UAudioComponent;

UCLASS()
class SI_API AProjectileMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileMaster();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	float DestroyOnSpawnAfterSec;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void ExplodeWhenNotCollided();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void BlastAndDestroyAfter(FVector EmiterSpawnLocation , FRotator EmiterSpawnRotation, EPhysicalSurface SurfaceType, float time);

	void SelfDestruct();

	void SelfDestructWithBlast();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* BulletComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* ImpactParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* FleshImpactParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* VulnerableFleshImpactParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	UParticleSystem* WaterImpactParticle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* ParticleSystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
	USoundCue* ImpactSoundFx;

	/*UAudioComponent* AudioComponent;*/

};
