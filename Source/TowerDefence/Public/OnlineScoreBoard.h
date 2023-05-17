// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ST_ScoreData.h"
#include "IScoreList.h"

#include "JsonObjectConverter.h"
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
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FST_ScoreData> ScoreList;
    UPROPERTY(BlueprintReadWrite)
    bool IsLoadingData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TScriptInterface<IIScoreList> Widget;
    UFUNCTION(BlueprintCallable)
    void RequestScoreList();
    UFUNCTION(BlueprintCallable)
    void SubmitScore(FST_ScoreData score);


protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    void OnProcessRequestSubmitComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success);
    void OnProcessRequestDataComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
private:
    FHttpModule* Http;
    FString Url;
};
