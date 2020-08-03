// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "ProjectileMaster.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "SI/Player/Public/SICharacter.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "Camera/CameraComponent.h"
#include "SI/SI.h"

class UPhysicalMaterial;
//class UCharacterMovementComponent;


// Sets default values
AProjectileMaster::AProjectileMaster()
{
	BulletComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BulletComponent"));
	BulletComponent->SetupAttachment(RootComponent);
	BulletComponent->SetNotifyRigidBodyCollision(true);
	BulletComponent->SetCollisionProfileName(TEXT("SI_ProjectileCollision"));
	BulletComponent->OnComponentHit.AddDynamic(this, &AProjectileMaster::OnCompHit);


	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(BulletComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(BulletComponent);

	/*AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);*/

	SetRootComponent(BulletComponent);
}

void AProjectileMaster::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSoundFx, Hit.Location);

	ASICharacter* OtherCharacter = Cast<ASICharacter>(OtherActor);



	if (OtherCharacter)
	{
		OtherCharacter->Hit(Hit.BoneName, 1200.0f);
		//float InflictingDamage = 10.0f;
		//OtherCharacter->GetCharacterMovement()->AddImpulse(OtherActor->GetActorForwardVector() * InflictingDamage, true);
		/*OtherCharacter->GetMesh()->AddImpulse(Hit.ImpactNormal, Hit.BoneName);*/

		/*USkeletalMeshComponent* CharacterMesh = OtherCharacter->GetMesh();

		CharacterMesh->GetBodyInstance(Hit.BoneName)->SetInstanceSimulatePhysics(true);
		CharacterMesh->AddImpulse(FVector(100.0f), Hit.BoneName);*/
	}
	
	

	EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
	
	BlastAndDestroyAfter(Hit.ImpactPoint, Hit.ImpactNormal.Rotation(), SurfaceType, 0.2f);
}

void AProjectileMaster::ExplodeWhenNotCollided()
{
	if (DestroyOnSpawnAfterSec > 0)
	{

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(
			UnusedHandle, this, &AProjectileMaster::SelfDestructWithBlast, DestroyOnSpawnAfterSec, false);

	}
}

// Called when the game starts or when spawned
void AProjectileMaster::BeginPlay()
{
	/*AudioComponent->SetSound(ImpactSoundFx);*/
	Super::BeginPlay();
	
}

void AProjectileMaster::BlastAndDestroyAfter(FVector EmiterSpawnLocation, FRotator EmiterSpawnRotation, EPhysicalSurface SurfaceType, float time)
{
	UParticleSystem* ParticleSystem = nullptr;
	
	switch (SurfaceType)
	{
	case SURFACE_FLESHDEFAULT:
		ParticleSystem = FleshImpactParticle;
		break;
	case SURFACE_FLESHVULNERABLE:
		ParticleSystem = VulnerableFleshImpactParticle;
		break;
	default:
		ParticleSystem = ImpactParticle;
		break;
	}
	
	if (ParticleSystem)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, EmiterSpawnLocation, EmiterSpawnRotation);
	}

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &AProjectileMaster::SelfDestruct, time, false);
}

void AProjectileMaster::SelfDestruct()
{
	Destroy();
}

void AProjectileMaster::SelfDestructWithBlast()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSoundFx, GetActorLocation());
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, GetActorLocation(), FRotator(0,0,0));

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &AProjectileMaster::SelfDestruct, 0.2, false);
}

