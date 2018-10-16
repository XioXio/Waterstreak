// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WaterBottle.generated.h"

UCLASS()
class WATERSTREAK_API AWaterBottle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWaterBottle();

    UPROPERTY(EditAnywhere)
        UStaticMeshComponent* CubeMesh;

    UPROPERTY(EditAnywhere)
        class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Sprint(float Value);
};
