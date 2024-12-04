// By Pablo Garcia


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
	int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities,InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities,InASCToGive, ApplyLevel);
}

//InAbilitiesToGive -> A list (array) of ability classes (TSubclassOf<UWarriorGameplayAbility>) to be granted
//InASCToGive -> The UWarriorAbilitySystemComponent (a subclass of UAbilitySystemComponent) to which the abilities will be granted. This component manages abilities, effects, and attributes for the actor

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if(InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	//Iterate through the list of ability classes
	for(const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if(!Ability) continue;

		//Create a FGameplayAbilitySpec-> structure that contains information about the ability to grant
		//It initializes the spec with the ability class (Ability
		FGameplayAbilitySpec AbilitySpec(Ability);
		//Set the source object for the ability spec -> it retrieves the actor associated with the ability system component (InASCToGive
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		//Grant the ability via the ability system component
		InASCToGive->GiveAbility(AbilitySpec);
	}
		
}
