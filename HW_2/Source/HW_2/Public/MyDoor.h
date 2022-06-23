// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "MyDoor.generated.h"

namespace UE::Util
{
	class HW_2_API FlipFLop
	{
	public:

		/**
		* Toggle state of bToggle.
		* @return Previous state of bToggle.
		*/
		bool Flip() noexcept
		{
			const bool bTemp = bToggle;
			bToggle = !bToggle;
			return bTemp;
		}

	private:
		bool bToggle = false;
	};
} // namespace UE::Util 

class UBoxComponent;

UCLASS()
class HW_2_API AMyDoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Door")
		UStaticMeshComponent* Frame;

	UPROPERTY(EditAnywhere, Category = "Door")
		UStaticMeshComponent* Door;

	UPROPERTY(EditAnywhere, Category = "Door")
		UBoxComponent* Box;

	UPROPERTY(EditAnywhere, Category = "Door")
		UCurveFloat* FloatCurve;

	UFUNCTION()
		void RotateDoor();

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OnComponentEndOverlap, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category = "Door")
		float MaxDegreeForDoor;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	* The setter for bIsLock.
	* @param bState - New state for bIsLock.
	*/
	void SetWhetherIsLock(const bool bState) noexcept;

private:
	/**
	* Log message with a pattern 'AMyDoor [*GetName()]: *Msg'.
	* @param Msg - Message to log.
	*/
	void LogMsg(const FString& Msg) const noexcept;

private:
	APlayerController* PlayerController;

	FTimeline Timeline;

	FRotator DoorRotation;

	UE::Util::FlipFLop OpenOrClose;

	bool bIsLock;
};
