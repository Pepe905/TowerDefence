// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Http.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnlineScoreBoard.generated.h"


UCLASS()
class TOWERDEFENCE_API AOnlineScoreBoard : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AOnlineScoreBoard();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    void OnProcessRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
