// CopyRight J&J

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class IMMORTAL_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

	void LaunchProjectile(float Speed);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage;

	class UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* CollisionMesh = nullptr;
	
};
