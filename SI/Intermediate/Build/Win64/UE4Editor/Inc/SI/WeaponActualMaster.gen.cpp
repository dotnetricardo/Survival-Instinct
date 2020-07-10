// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SI/Weapons/Public/WeaponActualMaster.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponActualMaster() {}
// Cross Module References
	SI_API UClass* Z_Construct_UClass_AWeaponActualMaster_NoRegister();
	SI_API UClass* Z_Construct_UClass_AWeaponActualMaster();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SI();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SI_API UClass* Z_Construct_UClass_AProjectileMaster_NoRegister();
// End Cross Module References
	void AWeaponActualMaster::StaticRegisterNativesAWeaponActualMaster()
	{
	}
	UClass* Z_Construct_UClass_AWeaponActualMaster_NoRegister()
	{
		return AWeaponActualMaster::StaticClass();
	}
	struct Z_Construct_UClass_AWeaponActualMaster_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsGrenadeModeActive_MetaData[];
#endif
		static void NewProp_bIsGrenadeModeActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsGrenadeModeActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultSceneRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultSceneRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointLight_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PointLight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LaserSightMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LaserSightMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponActualSkeletalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WeaponActualSkeletalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TotalMuzzles_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TotalMuzzles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InflictingDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_InflictingDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireRateDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FireRateDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentGrenadeAmmo_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentGrenadeAmmo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxGrenadeAmmp_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxGrenadeAmmp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentAmmo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxAmmo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShellEjectPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ShellEjectPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsGrenadeMode_MetaData[];
#endif
		static void NewProp_bIsGrenadeMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsGrenadeMode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileToSpawn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasGrenadeLauncher_MetaData[];
#endif
		static void NewProp_bHasGrenadeLauncher_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasGrenadeLauncher;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasMicroscopicSight_MetaData[];
#endif
		static void NewProp_bHasMicroscopicSight_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasMicroscopicSight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasLaserSight_MetaData[];
#endif
		static void NewProp_bHasLaserSight_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasLaserSight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Category;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsPistol_MetaData[];
#endif
		static void NewProp_bIsPistol_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsPistol;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWeaponActualMaster_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/Public/WeaponActualMaster.h" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bIsGrenadeModeActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive = { "bIsGrenadeModeActive", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_DefaultSceneRoot_MetaData[] = {
		{ "Category", "Default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_DefaultSceneRoot = { "DefaultSceneRoot", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, DefaultSceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_DefaultSceneRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_DefaultSceneRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_PointLight_MetaData[] = {
		{ "Category", "Default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_PointLight = { "PointLight", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, PointLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_PointLight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_PointLight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_LaserSightMesh_MetaData[] = {
		{ "Category", "Default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_LaserSightMesh = { "LaserSightMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, LaserSightMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_LaserSightMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_LaserSightMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_WeaponActualSkeletalMesh_MetaData[] = {
		{ "Category", "Default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_WeaponActualSkeletalMesh = { "WeaponActualSkeletalMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, WeaponActualSkeletalMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_WeaponActualSkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_WeaponActualSkeletalMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_TotalMuzzles_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_TotalMuzzles = { "TotalMuzzles", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, TotalMuzzles), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_TotalMuzzles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_TotalMuzzles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_InflictingDamage_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_InflictingDamage = { "InflictingDamage", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, InflictingDamage), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_InflictingDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_InflictingDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_FireRateDelay_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_FireRateDelay = { "FireRateDelay", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, FireRateDelay), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_FireRateDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_FireRateDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentGrenadeAmmo_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentGrenadeAmmo = { "CurrentGrenadeAmmo", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, CurrentGrenadeAmmo), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentGrenadeAmmo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentGrenadeAmmo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxGrenadeAmmp_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxGrenadeAmmp = { "MaxGrenadeAmmp", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, MaxGrenadeAmmp), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxGrenadeAmmp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxGrenadeAmmp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, CurrentAmmo), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentAmmo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentAmmo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, MaxAmmo), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxAmmo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxAmmo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ShellEjectPosition_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ShellEjectPosition = { "ShellEjectPosition", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, ShellEjectPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ShellEjectPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ShellEjectPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bIsGrenadeMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode = { "bIsGrenadeMode", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ProjectileToSpawn_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ProjectileToSpawn = { "ProjectileToSpawn", nullptr, (EPropertyFlags)0x0014000000000015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, ProjectileToSpawn), Z_Construct_UClass_AProjectileMaster_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ProjectileToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ProjectileToSpawn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bHasGrenadeLauncher = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher = { "bHasGrenadeLauncher", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bHasMicroscopicSight = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight = { "bHasMicroscopicSight", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bHasLaserSight = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight = { "bHasLaserSight", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, Category), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Category_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Category_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponActualMaster, Name), METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Weapons/Public/WeaponActualMaster.h" },
	};
#endif
	void Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol_SetBit(void* Obj)
	{
		((AWeaponActualMaster*)Obj)->bIsPistol = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol = { "bIsPistol", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWeaponActualMaster), &Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWeaponActualMaster_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeModeActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_DefaultSceneRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_PointLight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_LaserSightMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_WeaponActualSkeletalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_TotalMuzzles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_InflictingDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_FireRateDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentGrenadeAmmo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxGrenadeAmmp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_CurrentAmmo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_MaxAmmo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ShellEjectPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsGrenadeMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_ProjectileToSpawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasGrenadeLauncher,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasMicroscopicSight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bHasLaserSight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponActualMaster_Statics::NewProp_bIsPistol,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWeaponActualMaster_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWeaponActualMaster>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWeaponActualMaster_Statics::ClassParams = {
		&AWeaponActualMaster::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWeaponActualMaster_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWeaponActualMaster_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponActualMaster_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWeaponActualMaster()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWeaponActualMaster_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWeaponActualMaster, 3121628544);
	template<> SI_API UClass* StaticClass<AWeaponActualMaster>()
	{
		return AWeaponActualMaster::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWeaponActualMaster(Z_Construct_UClass_AWeaponActualMaster, &AWeaponActualMaster::StaticClass, TEXT("/Script/SI"), TEXT("AWeaponActualMaster"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWeaponActualMaster);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
