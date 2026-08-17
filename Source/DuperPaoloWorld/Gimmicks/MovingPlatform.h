// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	FRotator StartRotation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Movement")
	FVector TargetOffset = FVector(300.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category="Movement")
	FRotator RotationOffset = FRotator(0.f, 90.f, 0.f);

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 1.0f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Amplitude = 1.0f;
};
