// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();
	UFUNCTION(BlueprintCallable)
		void LoadMenu();

	UFUNCTION(BlueprintCallable)
		void InGameLoadMenu();

	UFUNCTION(Exec)
		void Host() override;
	UFUNCTION(Exec)
		void Join(uint32 Index) override;

	void StartSession();


	virtual void LoadMainMenu() override;
	void RefreshServerList() override;

	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
	

private:
   TSubclassOf<class UUserWidget> MenuClass;
   TSubclassOf<class UUserWidget> InGameMenuClass;
   class UMainMenu* Menu;

   //TSharedPtr<class FOnlineSessionSearch> SessionSearch;
   
   IOnlineSessionPtr SessionInterface;
   IOnlineSubsystem* Subsystem;
   void OnCreateSessionComplete(FName SessionName, bool Success);

   void OnDestroySessionComplete(FName SessionName, bool Success);

   void OnFindSessionsComplete(bool Success);
   void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

   void CreateSession();
};
