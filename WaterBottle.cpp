// Fill out your copyright notice in the Description page of Project Settings.

#include "WaterBottle.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"

// Sets default values
AWaterBottle::AWaterBottle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

}

// Called when the game starts or when spawned
void AWaterBottle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaterBottle::Tick(float DeltaTime)
{

}

// Called to bind functionality to input
void AWaterBottle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AWaterBottle::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AWaterBottle::MoveRight);
    PlayerInputComponent->BindAxis("Sprint", this, &AWaterBottle::Sprint);
}

void AWaterBottle::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value*.5);
}

void AWaterBottle::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(), Value*.5);

}

void AWaterBottle::Sprint(float Value)
{
    AddMovementInput(GetPendingMovementInputVector(), Value * 2);
}
