// By Pablo Garcia


#include "Characters/WarrriorBaseCharacter.h"

// Sets default values
AWarrriorBaseCharacter::AWarrriorBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

}
