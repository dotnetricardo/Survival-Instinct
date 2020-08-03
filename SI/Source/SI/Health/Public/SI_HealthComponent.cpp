// Fill out your copyright notice in the Description page of Project Settings.


#include "SI_HealthComponent.h"

// Sets default values
USI_HealthComponent::USI_HealthComponent()
{
	DefaultHealth = 100;
}

// Called when the game starts or when spawned
void USI_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	

	AActor* MyOwner = GetOwner();

	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &USI_HealthComponent::HandleTakeAnyDamage);
	}

	Health = DefaultHealth;
}

void USI_HealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	/*UE_LOG(LogTemp, Log, TEXT("HandleTakeAnyDamage"));*/

	if (Damage <= 0.0f)
	{
		return;
	}

	// Update health clamped
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

	//UE_LOG(LogTemp, Log, TEXT("Health Changed %s"), *FString::SanitizeFloat(Health));
}

