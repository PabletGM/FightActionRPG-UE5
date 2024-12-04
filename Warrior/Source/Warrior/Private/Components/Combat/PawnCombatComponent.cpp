// By Pablo Garcia


#include "Components/Combat/PawnCombatComponent.h"
#include "WarriorDebugHelper.h"
#include "Items/Weapons/WarriorWeaponBase.h"

// registration and management of weapons for a character
void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
	AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	// Check if the weapon tag is already in use (prevent duplicates).
	//Ensures that the InWeaponTagToRegister is not already in the CharacterCarriedWeaponMap
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A tag named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
	// Ensure the weapon being registered is valid (not null)
	check(InWeaponToRegister);

	//Adds the weapon to the CharacterCarriedWeaponMap, associating it with its tag
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);

	if(bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(),*InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	// Ensure the tag is valid before proceeding
	if (!InWeaponTagToGet.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Weapon Tag passed to GetCharacterCarriedWeaponByTag."));
		return nullptr;
	}

	// Look up the weapon in the TMap using the tag
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		// Return the weapon associated with the tag
		if(AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	// Log a warning if the weapon is not found
	UE_LOG(LogTemp, Warning, TEXT("No weapon found with the tag: %s"), *InWeaponTagToGet.ToString());
	return nullptr;
	
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	// Ensure the tag is valid before proceeding
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Weapon Tag passed to GetCharacterCarriedWeaponByTag."));
		return nullptr;
	}
	
	// Return the weapon associated with the tag
	if(AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(CurrentEquippedWeaponTag))
	{
		return *FoundWeapon;
	}
	UE_LOG(LogTemp, Warning, TEXT("No weapon found with current tag: %s"), *CurrentEquippedWeaponTag.ToString());
	return nullptr;
}
