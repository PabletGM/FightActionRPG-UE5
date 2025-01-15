// By Pablo Garcia


#include "Items/Weapons/WarriorWeaponBase.h"

#include "Components/BoxComponent.h"

// Sets default values
AWarriorWeaponBase::AWarriorWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent((WeaponMesh));

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::OnCollisionBoxBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this,&ThisClass::OnCollisionBoxEndOverlap);
}

//check if we hit the right target
void AWarriorWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	//Instigator =  Refers to the actor that "owns" the weapon
	APawn* WeaponOwningPawn = GetInstigator<APawn>();

	checkf(WeaponOwningPawn, TEXT("Forgot to assign an instigator as the owning pawn for the weapon: %s"), *GetName())

	if(APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if(WeaponOwningPawn != HitPawn)
		{
			//ExecuteIfBound is a helper function often used with delegates to ensure that a delegate is valid before calling it
			OnWeaponHitTarget.ExecuteIfBound(OtherActor);
		}

		//TODO: Implement hit check for enemy characters
	}
}

void AWarriorWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();

	checkf(WeaponOwningPawn, TEXT("Forgot to assign an instigator as the owning pawn for the weapon: %s"), *GetName())

	if(APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if(WeaponOwningPawn != HitPawn)
		{
			//ExecuteIfBound is a helper function often used with delegates to ensure that a delegate is valid before calling it
			OnWeaponPulledFromTarget.ExecuteIfBound(OtherActor);
		}

		//TODO: Implement hit check for enemy characters
	}
}




