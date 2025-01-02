// By Pablo Garcia

// utility library in Unreal Engine that provides helper functions to
// manage gameplay tags on actors using the Gameplay Ability System with functionality for
// blueprints and c++

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;

//Defines an EWarriorConfirmType enumeration with two values: Yes and No
UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//Retrieves the UWarriorAbilitySystemComponent from an actor.
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	//Adds a gameplay tag to an actor if it doesn't already have it.
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	//Removes a gameplay tag from an actor if it exists.
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	//Checks if an actor has a specific gameplay tag (C++ only)
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	//Blueprint-friendly version of NativeDoesActorHaveTag, using EWarriorConfirmType
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType);
};
