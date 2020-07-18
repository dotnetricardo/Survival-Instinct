// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "ProjectileMaster.h"
#include "Kismet/GameplayStatics.h"


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
	BlastAndDestroyAfter(Hit.ImpactPoint, Hit.ImpactNormal.Rotation(), 0.2f);
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

void AProjectileMaster::BlastAndDestroyAfter(FVector EmiterSpawnLocation, FRotator EmiterSpawnRotation, float time)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, EmiterSpawnLocation, EmiterSpawnRotation);

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

