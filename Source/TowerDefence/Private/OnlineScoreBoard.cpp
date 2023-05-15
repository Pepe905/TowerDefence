// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineScoreBoard.h"


// Sets default values
AOnlineScoreBoard::AOnlineScoreBoard()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;




}

// Called when the game starts or when spawned
void AOnlineScoreBoard::BeginPlay()
{
    Super::BeginPlay();

    


    FHttpModule* Http = &FHttpModule::Get();
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = Http->CreateRequest();

   

    request->OnProcessRequestComplete().BindUObject(this, &AOnlineScoreBoard::OnProcessRequestComplete);
    request->SetURL("http://markusdullnig.de/highScore.php");
    request->SetVerb("POST");
    request->SetHeader(TEXT("Content-Type"),TEXT("application/x-www-form-urlencoded"));
    request->SetContentAsString(TEXT("name=testing999&score=9000&time=04:00:00"));
  
    request->ProcessRequest();

    


}

void AOnlineScoreBoard::OnProcessRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool success)
{
     if (success)
      {
          UE_LOG(LogTemp, Warning, TEXT("%s"), *response->GetContentAsString());
          *response->
      }
      else
      {
          UE_LOG(LogTemp, Warning, TEXT("FAILED"));
      }
}


// Called every frame
void AOnlineScoreBoard::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

