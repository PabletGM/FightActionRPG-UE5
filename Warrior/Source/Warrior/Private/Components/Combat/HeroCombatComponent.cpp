// By Pablo Garcia


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorDebugHelper.h"
#include "WarriorGameplayTags.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{   
    return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
    return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquipWeaponDamageAtLevel(float InLevel) const
{
    return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{

    //add actor to the array overlapped actors
    if(OverlappedActors.Contains(HitActor))
    {
        return;
    }

    OverlappedActors.AddUnique(HitActor);

    //Creates a FGameplayEventData structure to store event information
    FGameplayEventData Data;
    //The actor that caused the event (the hero).
    Data.Instigator = GetOwningPawn();
    //The actor that was hit
    Data.Target = HitActor;

    //Sends a gameplay event using Unreal Engine's GAS signaling that a melee hit occurred so the GA_LightAttackMaster or GA_HeavyAttackMaster knows
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        WarriorGameplayTags::Shared_Event_MeleeHit,
        Data
        );

    //so GA_Hero_HitPause knows
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
       GetOwningPawn(),
       WarriorGameplayTags::Player_Event_HitPause,
       FGameplayEventData()
       );
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
      GetOwningPawn(),
      WarriorGameplayTags::Player_Event_HitPause,
      FGameplayEventData()
      );
}
