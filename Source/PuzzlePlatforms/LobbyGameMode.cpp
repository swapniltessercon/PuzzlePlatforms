// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "PuzzlePlatformsGameInstance.h"

ALobbyGameMode::ALobbyGameMode()
{
 
}

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer) {
		
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("In PostLogin"))
	++NumberOfPlayers;

	if (NumberOfPlayers >= 3)
	{
		FTimerHandle TimerHandle;
		UWorld* World = GetWorld();
		if (ensure(World != nullptr)) 
		{
		World->GetTimerManager().SetTimer(TimerHandle, this, &ALobbyGameMode::LobbyDelay, 0.5f, false, 10.0f);
		}
		
	}
}
void ALobbyGameMode::Logout(AController* Exiting) {

	Super::Logout(Exiting);

	--NumberOfPlayers;

	UE_LOG(LogTemp, Warning, TEXT("LogOut"))
}


void ALobbyGameMode::LobbyDelay()
{

	auto GameInstance = Cast<UPuzzlePlatformsGameInstance>(GetGameInstance());

	if (GameInstance == nullptr) return;

	GameInstance->StartSession();

	UWorld* World = GetWorld();
	if (ensure(World != nullptr))
	{
		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/PuzzlePlatform/Map/Game?listen");
	}
}