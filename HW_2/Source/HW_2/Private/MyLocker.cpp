// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLocker.h"
#include "MyDoor.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyLocker::AMyLocker()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(RootComponent);
	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	Box->OnComponentBeginOverlap.AddDynamic(this, &AMyLocker::OnBeginOverlap);
}

// Called when the game starts or when spawned
void AMyLocker::BeginPlay()
{
	Super::BeginPlay();

}

void AMyLocker::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && MyDoor)
	{
		UE_LOG(LogTemp, Log, TEXT("AMyLocker [%s]: Unlocked"), *GetName());
		MyDoor->SetWhetherIsLock(false);
	}
}

// Called every frame
void AMyLocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

