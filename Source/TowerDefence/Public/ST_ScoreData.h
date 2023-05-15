// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ScoreData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct TOWERDEFENCE_API FST_ScoreData
{
	

public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ID;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Score;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Kills;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Rounds;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Time;
	

	FST_ScoreData();
	~FST_ScoreData();
};
