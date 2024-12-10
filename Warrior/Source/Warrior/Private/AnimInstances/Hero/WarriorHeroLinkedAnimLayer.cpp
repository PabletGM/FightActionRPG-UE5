// By Pablo Garcia


#include "AnimInstances/Hero/WarriorHeroLinkedAnimLayer.h"

#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	UWarriorHeroAnimInstance*  heroAnimInstance = Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
	return heroAnimInstance;
}
