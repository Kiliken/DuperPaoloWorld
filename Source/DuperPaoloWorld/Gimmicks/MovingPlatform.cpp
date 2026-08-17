// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	StartRotation = GetActorRotation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Time = GetWorld()->GetTimeSeconds(); // Sine wave value between -1 and 1  
	float SineValue = FMath::Sin(Time * Speed) * Amplitude; // Calculate new position

	FVector NewLocation = StartLocation + (TargetOffset * SineValue); 
	SetActorLocation(NewLocation);

	FRotator NewRotation = StartRotation + (RotationOffset * SineValue); 
	SetActorRotation(NewRotation);
}
