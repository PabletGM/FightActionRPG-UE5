// By Pablo Garcia

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()

		public:
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta = (Categories = "InputTag"))
		FGameplayTag InputTag;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		UInputAction* InputAction;
	
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
	public:
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		UInputMappingContext* DefaultMappingContext;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(TitleProperty = "InputTag"))
	    TArray<FWarriorInputActionConfig> NativeInputActions;

		UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag);
};