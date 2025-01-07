// By Pablo Garcia

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "Characters/WarriorEnemyCharacter.h"
#include "WarriorEnemyGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorEnemyGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorEnemyCharacter* GetEnemyCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AWarriorEnemyCharacter> CachedWarriorEnemyCharacter;
};
