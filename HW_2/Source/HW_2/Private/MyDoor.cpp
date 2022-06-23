// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDoor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyDoor::AMyDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Frame->SetMobility(EComponentMobility::Static);
	RootComponent = Frame;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Frame->SetMobility(EComponentMobility::Movable);
	Door->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box->SetupAttachment(RootComponent);

	Box->OnComponentBeginOverlap.AddDynamic(this, &AMyDoor::OnBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AMyDoor::OnEndOverlap);

	MaxDegreeForDoor = 100.0f;

	bIsLock = true;
}

// Called when the game starts or when spawned
void AMyDoor::BeginPlay()
{
	Super::BeginPlay();

	DoorRotation = FRotator(1.0f);

	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (PlayerController)
	{
		PlayerController->DisableInput(nullptr);
	}

	if (FloatCurve)
	{
		FOnTimelineFloat TimelineCallback;

		TimelineCallback.BindUFunction(this, FName("RotateDoor"));

		Timeline.AddInterpFloat(FloatCurve, TimelineCallback);
	}
}

void AMyDoor::RotateDoor()
{
	const float TimelineValue = Timeline.GetPlaybackPosition();
	const float FloatCurveValue = (DoorRotation * FloatCurve->GetFloatValue(TimelineValue)).Yaw * MaxDegreeForDoor;

	const FQuat NewRotation(FRotator(0.0f, FloatCurveValue, 0.0f));

	Door->SetRelativeRotation(NewRotation);
}

// Called every frame
void AMyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);

	if (PlayerController->InputEnabled() && PlayerController->WasInputKeyJustPressed(EKeys::E))
	{
		LogMsg(TEXT("Pressed E"));

		if (bIsLock == false)
		{
			if (OpenOrClose.Flip())
			{
				Timeline.Play();
			}
			else
			{
				Timeline.Reverse();
			}
		}
	}
}

void AMyDoor::SetWhetherIsLock(const bool bState) noexcept
{
	bIsLock = bState;
}

void AMyDoor::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	LogMsg(TEXT("Begin Overlap"));

	if (PlayerController)
	{
		LogMsg(TEXT("Enable Input"));
		PlayerController->EnableInput(nullptr);
	}
}

void AMyDoor::OnEndOverlap(UPrimitiveComponent* OnComponentEndOverlap, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	LogMsg(TEXT("End Overlap"));

	if (PlayerController)
	{
		LogMsg(TEXT("Disable Input"));
		PlayerController->DisableInput(nullptr);
	}
}

void AMyDoor::LogMsg(const FString& Msg) const noexcept
{
	UE_LOG(LogTemp, Log, TEXT("AMyDoor [%s]: %s"), *GetName(), *Msg);
}

