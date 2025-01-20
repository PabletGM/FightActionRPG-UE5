// By Pablo Garcia

#include "AbilitySystem/WarriorAttributeSet.h"
#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "WarriorGameplayTags.h"

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

//calculate the final damage with the values
//responsible for determining the final damage value by using captured attributes and SetByCaller values provided at runtime
void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	//The EffectSpec contains metadata about the effect such as Source/Target Tags, SetByCaller Values, Context Information
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	// EffectSpec.GetContext().GetSourceObject();
	// EffectSpec.GetContext().GetAbility();
	// EffectSpec.GetContext().GetInstigator();
	// EffectSpec.GetContext().GetEffectCauser();

	//These tags are used for conditional calculations
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();


	
	//Retrieves the real-time values of the AttackPower (from the source) and DefensePower (from the target)
	//These values are captured based on the definitions in FWarriorDamageCapture
	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;
	
	for(const TPair <FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if(TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
		}

		if(TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
		}

		if(TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
		}
	}
	
	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().DefensePowerDef, EvaluateParameters,TargetDefensePower );
}
