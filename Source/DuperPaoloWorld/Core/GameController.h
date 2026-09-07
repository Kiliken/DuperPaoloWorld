// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameController.generated.h"

class ADuperPaoloWorldCharacter;

UCLASS()
class AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int score = 0;
	float playerHp = 50.f;
	float playerSt = 100.f;

private:
	APlayerController* PC;
	ADuperPaoloWorldCharacter* charController;
	APawn* playerPawn;
	
	void ShowStatBarUI();
};
