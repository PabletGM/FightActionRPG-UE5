// By Pablo Garcia

#pragma once
#include "GameplayTagContainer.h"
#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimLayer;
class UWarriorHeroGameplayAbility;
class UInputMappingContext;
///Defines an ability set tied to the hero's weapon
USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	//A gameplay tag to categorize or trigger abilities via input
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	//specifying the ability class.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UWarriorHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};



///Encapsulates data specific to the hero's weapon.
USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	//Links a specific animation layer for the weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	//Specifies input mappings tied to the weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputMapping"))
	UInputMappingContext* WeaponInputMappingContext;

	//An array of abilities the weapon grants to the hero
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> DefaultWeaponAbilities;
};