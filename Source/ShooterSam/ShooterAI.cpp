// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

	// Get player pawn so enemy can focus on it
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*	if (PlayerPawn)
		{
			if (LineOfSightTo(PlayerPawn))
			{
				// Make the enemy look/focus on the player
				SetFocus(PlayerPawn);

				// Make the enemy follow the player
				MoveToActor(PlayerPawn, 200.0f);
			}
			else
			{
				ClearFocus(EAIFocusPriority::Gameplay);

				StopMovement();
			}

		}*/
}

void AShooterAI::StartBehaviorTree(AShooterSamCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AShooterSamCharacter>(GetPawn());

		if (Player)
		{
			PlayerCharacter = Player;
		}


		RunBehaviorTree(EnemyAIBehaviorTree);

		UBlackboardComponent* MyBlackBoard = GetBlackboardComponent();
		if (MyBlackBoard && PlayerCharacter && MyCharacter)
		{
			//MyBlackBoard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
			MyBlackBoard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());
		}
	}
}
