// By Pablo Garcia
//A generic utility component for interaction with the owning APawn and its AController
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtenstionComponentBase.generated.h"

//his UPawnExtensionComponentBase class you've written extends UActorComponent
//to provide utility functions for interacting with the owning APawn and its controller
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtenstionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	//A templated function that retrieves the APawn (or a derived type) owning this component.
	template <class T>
	T* GetOwningPawn() const
	{
		//Includes a static_assert to enforce that T is derived from APawn
		static_assert(TPointerIsConvertibleFromTo<T,APawn>::Value,"'T' Template Parameter to GetPawn must be derived from APawn");
		//Uses CastChecked<T>(GetOwner()) to ensure the owner is of type T and returns it
		return CastChecked<T>(GetOwner());
	}

	// A non-templated version that always returns the owning APawn
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}


	//Retrieves the controller (of type T) that is managing the owning pawn
	template <class T>
	T* GetOwningController() const
	{
		//Includes a static_assert to ensure T is derived from AController.
		static_assert(TPointerIsConvertibleFromTo<T,AController>::Value,"'T' Template Parameter get GetController must be derived from AController");
		//Uses GetOwningPawn<APawn>()->GetController<T>() to get the controller of type T from the owning pawn
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
