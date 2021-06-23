// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzlePlatformsGameMode.h"
#include "PuzzlePlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzlePlatformsGameMode::APuzzlePlatformsGameMode()
{

	UE_LOG(LogTemp, Warning, TEXT("In PuzzlePlatFormMode"))
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("In PuzzlePlatFormMode"))

		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
