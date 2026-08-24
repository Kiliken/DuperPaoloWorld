// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CoinScript.h"

#include "utils/PUtils.h"

// Sets default values
ACoinScript::ACoinScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	thisComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = thisComponent;
	
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube"));
	thisComponent->SetStaticMesh(Mesh);
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
	thisComponent->SetMaterial(0, Material);

	thisComponent->SetCollisionProfileName(TEXT("Trigger"));
    thisComponent->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void ACoinScript::BeginPlay()
{
	Super::BeginPlay();

	thisComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoinScript::OnCoinOverlap);

	gameController = Cast<AGameController>(PUTILS::GetFirstActorByTag("Controller",this->GetWorld()));

	if(gameController == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("GameController Found"));
}

// Called every frame
void ACoinScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator rot = this->GetActorRotation();

	if (rot.Yaw < 360.f) {
		this->SetActorRotation(rot + FRotator(0, 15, 0) * DeltaTime);
	}
	else this->SetActorRotation(FRotator(0));

}


void ACoinScript::OnCoinOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
                                bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {

		APawn* PlayerPawn = Cast<APawn>(OtherActor);
        if (PlayerPawn && PlayerPawn->IsPlayerControlled())
        {
            if (gameController)
            {
                gameController->score += 1;
                
                UE_LOG(LogTemp, Log, TEXT("HP Collected! New HP: %f"), gameController->playerHp);
                Destroy();
            }
        }
    }
}
