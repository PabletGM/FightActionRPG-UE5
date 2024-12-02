// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Warrior/Public/GameModes/WarriorBaseGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWarriorBaseGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Warrior();
	WARRIOR_API UClass* Z_Construct_UClass_AWarriorBaseGameMode();
	WARRIOR_API UClass* Z_Construct_UClass_AWarriorBaseGameMode_NoRegister();
// End Cross Module References
	void AWarriorBaseGameMode::StaticRegisterNativesAWarriorBaseGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWarriorBaseGameMode);
	UClass* Z_Construct_UClass_AWarriorBaseGameMode_NoRegister()
	{
		return AWarriorBaseGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AWarriorBaseGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWarriorBaseGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Warrior,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorBaseGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWarriorBaseGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameModes/WarriorBaseGameMode.h" },
		{ "ModuleRelativePath", "Public/GameModes/WarriorBaseGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWarriorBaseGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWarriorBaseGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWarriorBaseGameMode_Statics::ClassParams = {
		&AWarriorBaseGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorBaseGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AWarriorBaseGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWarriorBaseGameMode()
	{
		if (!Z_Registration_Info_UClass_AWarriorBaseGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWarriorBaseGameMode.OuterSingleton, Z_Construct_UClass_AWarriorBaseGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWarriorBaseGameMode.OuterSingleton;
	}
	template<> WARRIOR_API UClass* StaticClass<AWarriorBaseGameMode>()
	{
		return AWarriorBaseGameMode::StaticClass();
	}
	AWarriorBaseGameMode::AWarriorBaseGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWarriorBaseGameMode);
	AWarriorBaseGameMode::~AWarriorBaseGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_pgmla_OneDrive_Escritorio_FightActionRPG_UE5_FightActionRPG_UE5_Warrior_Source_Warrior_Public_GameModes_WarriorBaseGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_pgmla_OneDrive_Escritorio_FightActionRPG_UE5_FightActionRPG_UE5_Warrior_Source_Warrior_Public_GameModes_WarriorBaseGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWarriorBaseGameMode, AWarriorBaseGameMode::StaticClass, TEXT("AWarriorBaseGameMode"), &Z_Registration_Info_UClass_AWarriorBaseGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWarriorBaseGameMode), 776451922U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_pgmla_OneDrive_Escritorio_FightActionRPG_UE5_FightActionRPG_UE5_Warrior_Source_Warrior_Public_GameModes_WarriorBaseGameMode_h_3436616885(TEXT("/Script/Warrior"),
		Z_CompiledInDeferFile_FID_Users_pgmla_OneDrive_Escritorio_FightActionRPG_UE5_FightActionRPG_UE5_Warrior_Source_Warrior_Public_GameModes_WarriorBaseGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_pgmla_OneDrive_Escritorio_FightActionRPG_UE5_FightActionRPG_UE5_Warrior_Source_Warrior_Public_GameModes_WarriorBaseGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
