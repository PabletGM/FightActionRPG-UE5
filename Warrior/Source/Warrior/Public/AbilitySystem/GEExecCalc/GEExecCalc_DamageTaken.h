// By Pablo Garcia

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExecCalc_DamageTaken.generated.h"

/**
 * 
 */

//  implementation of a custom Gameplay Effect Execution Calculation
//  (UGEExecCalc_DamageTaken) in Unreal Engine's Gameplay Ability System (GAS).

///define how damage calculations are performed in a game for a "Warrior" character, leveraging Unreal's Attribute Capture system.
UCLASS()
class WARRIOR_API UGEExecCalc_DamageTaken : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UGEExecCalc_DamageTaken();
	
};
