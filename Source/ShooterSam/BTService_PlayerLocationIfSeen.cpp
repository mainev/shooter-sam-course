// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update PlayerLocation If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AShooterAI* OwnerController =  Cast<AShooterAI>(OwnerComp.GetAIOwner());
	AShooterSamCharacter* Player = OwnerController->PlayerCharacter;
	UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

	if (OwnerController && Player && Blackboard)
	{
		// Check if enemy has line of sight to the player
		if (OwnerController->LineOfSightTo(Player))
		{
			// Make the enemy look/focus on the player
			Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
			OwnerController->SetFocus(Player);

			// Make the enemy follow the player
			//MoveToActor(PlayerPawn, 200.0f);
		}
		else
		{
			Blackboard->ClearValue(GetSelectedBlackboardKey());
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);

			//StopMovement();
		}
	}
}
