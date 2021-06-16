// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float Deltatime) {

	Super::Tick(Deltatime);

	if (ActivTriggers > 0)
	{
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			float JurneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JurneyTravelled = (Location - GlobalStartLocation).Size();
			if (JurneyTravelled > JurneyLength)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;

			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += speed * Deltatime * Direction;
			SetActorLocation(Location);
		}
	}


}
void AMovingPlatform:: AddActiveTrigger() {

	ActivTriggers++;

}
void AMovingPlatform:: RemoveActiveTrigger() {

	if (ActivTriggers > 0)
	{
		ActivTriggers--;
	}

}
