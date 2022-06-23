// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyLocker.generated.h"

class AMyDoor;
class UBoxComponent;

UCLASS()
class HW_2_API AMyLocker : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyLocker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Locker")
		AMyDoor* MyDoor;

	UPROPERTY(EditAnywhere, Category = "Locker")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Locker")
		UBoxComponent* Box;

	/**
	* Change state of MyDoor calling SetWhetherIsLock method.
	*/
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
