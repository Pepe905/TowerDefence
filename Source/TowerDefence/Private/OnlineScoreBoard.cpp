// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineScoreBoard.h"

void CreateScoreString(FST_ScoreData score, FString& outString) {

    outString = outString + "name=" + score.Name;
    outString = outString + "&score=" + FString::FromInt(score.Score);
    outString = outString + "&time=" + score.Time;
    outString = outString + "&kills=" + FString::FromInt(score.Kills);
    outString = outString + "&rounds=" + FString::FromInt(score.Rounds);


}

// Sets default values
AOnlineScoreBoard::AOnlineScoreBoard()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;



    Http = &FHttpModule::Get();
    Url = "http://markusdullnig.de/highScore.php?";
    IsLoadingData = false;
}

void AOnlineScoreBoard::RequestScoreList() {
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = Http->CreateRequest();
    request->OnProcessRequestComplete().BindUObject(this, &AOnlineScoreBoard::OnProcessRequestDataComplete);
    request->SetURL(Url);
    request->SetVerb("GET");

    request->ProcessRequest();
}

void AOnlineScoreBoard::SubmitScore(FST_ScoreData score) {

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = Http->CreateRequest();

    IsLoadingData = true;

    request->OnProcessRequestComplete().BindUObject(this, &AOnlineScoreBoard::OnProcessRequestSubmitComplete);
    request->SetURL(Url);
    request->SetVerb("POST");
    request->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));

    FString scoreString ="";
    CreateScoreString(score, scoreString);

    request->SetContentAsString(scoreString);

    request->ProcessRequest();
}



// Called when the game starts or when spawned
void AOnlineScoreBoard::BeginPlay()
{
    Super::BeginPlay();


}

void AOnlineScoreBoard::OnProcessRequestSubmitComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
{
    /* if (success )
      {
          UE_LOG(LogTemp, Warning, TEXT("%s"), *response->GetContentAsString());
          
      }
      else
      {
          UE_LOG(LogTemp, Warning, TEXT("FAILED"));
      }*/
}

void AOnlineScoreBoard::OnProcessRequestDataComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success) {

    IsLoadingData = false;

      if (success) {
          FString content = *response->GetContentAsString();
          ScoreList.Empty();
          FJsonObjectConverter::JsonArrayStringToUStruct(content, &ScoreList);

          Widget->Execute_UpdateList(Widget.GetObject());

          


          //UE_LOG(LogTemp, Warning, TEXT("%s"), *response->GetContentAsString());
          }
     /* else {
          UE_LOG(LogTemp, Warning, TEXT("FAILED"));
      }*/
}


// Called every frame
void AOnlineScoreBoard::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

