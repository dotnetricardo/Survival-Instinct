// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "ProjectileMaster.h"


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
	
}

void AProjectileMaster::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &AProjectileMaster::SelfDestruct, 0.2f, false);
}

// Called when the game starts or when spawned
void AProjectileMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileMaster::SelfDestruct()
{
	Destroy();
}

