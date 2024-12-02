// By Pablo Garcia

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarrriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarrriorBaseCharacter
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	
	
};
