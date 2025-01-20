// By Pablo Garcia

#include "AbilitySystem/WarriorAttributeSet.h"
#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"

//sets up attribute capture definitions for two gameplay attributes (AttackPower and DefensePower) defined in the UWarriorAttributeSet
//logic for capturing attributes and provides a clean way to access them in the execution calculation
struct FWarriorDamageCapture
{
	//macros to capture an attribute definition
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);

	// Defines the capture of an attribute (The attribute's owning class, Name of the attribute,  Whether the attribute is captured from the source or the target,  Whether to snapshot the attribute value)
	FWarriorDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet,AttackPower,Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet,DefensePower,Target,false);
	}
};

//GETTER of struct FWarriorDamageCapture
//static function ensures that the FWarriorDamageCapture struct is
//only instantiated once (singleton pattern) and can be reused wherever needed
static const FWarriorDamageCapture& GetWarriorDamageCapture()
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}


UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	/*Slow Way of doing Capture*/
	
	// //look for property in any class, in this case in WarriorAttributeSet attackPower
	// FProperty* AttackPowerProperty =  FindFieldChecked<FProperty>(UWarriorAttributeSet::StaticClass(),
	// 	GET_MEMBER_NAME_CHECKED(UWarriorAttributeSet, AttackPower)
	// );
	//
	// FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(
	// 		AttackPowerProperty,
	// 		EGameplayEffectAttributeCaptureSource::Source,
	// 		false);
	//
	// RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);



	
	/*Fast Way using MACRO*/

	//Attributes are added to RelevantAttributesToCapture using the pre-defined FWarriorDamageCapture struct and its macros
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
}
