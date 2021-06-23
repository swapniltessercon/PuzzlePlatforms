// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

		FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()


public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	//void SetServerList(TArray<FString> ServerNames);
	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

private:
	TSubclassOf<class UUserWidget> ServerRowClass;

protected:
	virtual bool Initialize();


private:
		UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
		//class UEditableTextBox* IPAddressField;
		class UPanelWidget* ServerList;

	UFUNCTION()
		 void HostServer();

	UFUNCTION()
		void JoinServer();

	UFUNCTION()
		 void OpenJoinMenu();

	UFUNCTION()
		 void OpenMainMenu();

	UFUNCTION()
		void QuitPressed();

	TOptional<uint32> SelectedIndex;
	void UpdateChildren();

};
