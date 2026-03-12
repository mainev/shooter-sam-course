// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_Shoot.h"
#include "ShooterAI.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = TEXT("Shoot at Player");
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());

	if (OwnerController)
	{
		AShooterSamCharacter* OwnerCharacter = OwnerController->MyCharacter;
		AShooterSamCharacter* PlayerCharacter = OwnerController->PlayerCharacter;

		if (OwnerCharacter && PlayerCharacter && PlayerCharacter->IsAlive)
		{
			OwnerCharacter->Shoot();

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
