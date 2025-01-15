// By Pablo Garcia
//Specialization of UPawnCombatComponent for hero-specific functionality
#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"

#include "HeroCombatComponent.generated.h"

class AWarriorHeroWeapon;
/**
 * 
 */
UCLASS()
class WARRIOR_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	//returns hero weapon by tag
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
	
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCurrentEquippedWeapon() const;

	//returns hero weapon by tag
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	float GetHeroCurrentEquipWeaponDamageAtLevel(float InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;
};
