// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"


DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();


	//print_transform();
	//print_string_types();
	//print_types();													
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMovement();
}

void ABaseGeometryActor::PrintTypes()
{

	UE_LOG(LogBaseGeometry, Warning, TEXT("Player name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("weapone num: %d"), weapon_num);
	UE_LOG(LogBaseGeometry, Warning, TEXT("kills num: %d"), kills_num);
	UE_LOG(LogBaseGeometry, Warning, TEXT("health: %f"), health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("isdead: %d"), is_dead);
	UE_LOG(LogBaseGeometry, Warning, TEXT("has weapone: %d"), has_weapone);
	

}

void ABaseGeometryActor::PrintTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotation %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());
	UE_LOG(LogBaseGeometry, Error, TEXT("Human Transform %s"), *Transform.ToHumanReadableString());
}

void ABaseGeometryActor::PrintStringTypes()
{
	FString name = "John Snow";
	UE_LOG(LogBaseGeometry, Display, TEXT("name : %s"), *name);

	FString weapons_num_str = "weapons num = " + FString::FromInt(weapon_num);
	FString health_str = "health = " + FString::SanitizeFloat(health);
	FString has_weapone_str = "has weapone = " + FString(has_weapone ? "true" : "false");

	FString stat = FString::Printf(TEXT("all stat \n %s \n  %s \n  %s"), *weapons_num_str, *health_str, *has_weapone_str);
	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *stat);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, stat, true, FVector2D(1.5f, 1.5f));

}

void ABaseGeometryActor::HandleMovement()
{
	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
	{
		FVector CurrentLocation = GetActorLocation();
		float Time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + GeometryData.amplitude * FMath::Sin(GeometryData.frequance * Time);
		SetActorLocation(CurrentLocation);
	}
	break;
	case EMovementType::Cos:
	{
		FVector CurrentLocation = GetActorLocation();
		float Time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + GeometryData.amplitude * FMath::Cos(GeometryData.frequance * Time);
		SetActorLocation(CurrentLocation);
	}
	break;

	case EMovementType::Static:
		break;
	default:
		break;
	}
}

