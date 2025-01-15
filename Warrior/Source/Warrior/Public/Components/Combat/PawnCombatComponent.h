// By Pablo Garcia
//Extends UPawnExtensionComponentBase to add weapon registration and retrieval capabilities for characters
#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtenstionComponentBase.h"
#include "GameplayTagContainer.h"
#include "Items/Weapons/WarriorHeroWeapon.h"
#include "PawnCombatComponent.generated.h"


class AWarriorWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtenstionComponentBase
{
	GENERATED_BODY()

public:
	//Associates a weapon with a tag in the map, Ensures no duplicate tags are registered, Optionally sets the weapon as the currently equipped one
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	//Retrieves a weapon using its gameplay tag, Performs checks to ensure the tag is valid and exists in the map
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	//Represents a tag (a predefined name or identifier) used to uniquely identify the  current weapon
	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	//Retrieves the currently equipped weapon based on CurrentEquippedWeaponTag
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);
private:
	//store weapons that can be retrieved
	//A TMap (similar to a dictionary or hashmap) that maps a FGameplayTag
	//to its corresponding weapon (AWarriorWeaponBase).
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
