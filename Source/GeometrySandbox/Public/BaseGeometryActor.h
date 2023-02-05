// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"


UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Cos,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Movement")
		float amplitude = 50.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float frequance = 2.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		EMovementType MoveType = EMovementType::Static;
};

UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Geometry Data")
	FGeometryData GeometryData;

	UPROPERTY(EditAnywhere, Category = "Weapone")
	int32 weapon_num = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float health = 45.14;

	UPROPERTY(EditInstanceOnly, Category = "Weapone")
	bool has_weapone = true;

	UPROPERTY(EditAnywhere, Category = "Stat")
	int32 kills_num = 10;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	bool is_dead = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;

	void PrintTypes();
	void PrintTransform();
	void PrintStringTypes();
	void HandleMovement();

};
