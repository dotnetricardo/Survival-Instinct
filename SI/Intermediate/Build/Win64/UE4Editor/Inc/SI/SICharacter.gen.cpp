// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SI/Player/Public/SICharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSICharacter() {}
// Cross Module References
	SI_API UClass* Z_Construct_UClass_ASICharacter_NoRegister();
	SI_API UClass* Z_Construct_UClass_ASICharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_SI();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SI_API UClass* Z_Construct_UClass_AWeaponActualMaster_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASICharacter::execAnimateSpringArmHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimateSpringArmHeight(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASICharacter::execAnimateSpringArmLength)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimateSpringArmLength(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASICharacter::execAnimateCameraLocation)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimateCameraLocation(Z_Param_Value);
		P_NATIVE_END;
	}
	void ASICharacter::StaticRegisterNativesASICharacter()
	{
		UClass* Class = ASICharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimateCameraLocation", &ASICharacter::execAnimateCameraLocation },
			{ "AnimateSpringArmHeight", &ASICharacter::execAnimateSpringArmHeight },
			{ "AnimateSpringArmLength", &ASICharacter::execAnimateSpringArmLength },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics
	{
		struct SICharacter_eventAnimateCameraLocation_Parms
		{
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventAnimateCameraLocation_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "AnimateCameraLocation", nullptr, nullptr, sizeof(SICharacter_eventAnimateCameraLocation_Parms), Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_AnimateCameraLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_AnimateCameraLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics
	{
		struct SICharacter_eventAnimateSpringArmHeight_Parms
		{
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventAnimateSpringArmHeight_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "AnimateSpringArmHeight", nullptr, nullptr, sizeof(SICharacter_eventAnimateSpringArmHeight_Parms), Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics
	{
		struct SICharacter_eventAnimateSpringArmLength_Parms
		{
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventAnimateSpringArmLength_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "AnimateSpringArmLength", nullptr, nullptr, sizeof(SICharacter_eventAnimateSpringArmLength_Parms), Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASICharacter_NoRegister()
	{
		return ASICharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASICharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShootGrenadeAnimMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShootGrenadeAnimMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShootOnceAnimMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShootOnceAnimMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AimCurveFloat_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AimCurveFloat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SwichModesCurveFloat_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SwichModesCurveFloat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WeaponInventory;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WeaponInventory_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponInventoryIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WeaponInventoryIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsFiring_MetaData[];
#endif
		static void NewProp_bIsFiring_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsFiring;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCrouching_MetaData[];
#endif
		static void NewProp_bIsCrouching_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCrouching;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputAxisYawValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InputAxisYawValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxWeaponsCarry_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxWeaponsCarry;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCombatMode_MetaData[];
#endif
		static void NewProp_bIsCombatMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCombatMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASICharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASICharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASICharacter_AnimateCameraLocation, "AnimateCameraLocation" }, // 1445427505
		{ &Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight, "AnimateSpringArmHeight" }, // 604125465
		{ &Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength, "AnimateSpringArmLength" }, // 327589450
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/Public/SICharacter.h" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootGrenadeAnimMontage_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootGrenadeAnimMontage = { "ShootGrenadeAnimMontage", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, ShootGrenadeAnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootGrenadeAnimMontage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootGrenadeAnimMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootOnceAnimMontage_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootOnceAnimMontage = { "ShootOnceAnimMontage", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, ShootOnceAnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootOnceAnimMontage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootOnceAnimMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat = { "AimCurveFloat", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, AimCurveFloat), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat = { "SwichModesCurveFloat", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, SwichModesCurveFloat), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory = { "WeaponInventory", nullptr, (EPropertyFlags)0x0014000000000004, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, WeaponInventory), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_Inner = { "WeaponInventory", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AWeaponActualMaster_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex = { "WeaponInventoryIndex", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, WeaponInventoryIndex), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring_SetBit(void* Obj)
	{
		((ASICharacter*)Obj)->bIsFiring = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring = { "bIsFiring", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASICharacter), &Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching_SetBit(void* Obj)
	{
		((ASICharacter*)Obj)->bIsCrouching = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching = { "bIsCrouching", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASICharacter), &Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue = { "InputAxisYawValue", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, InputAxisYawValue), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry = { "MaxWeaponsCarry", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, MaxWeaponsCarry), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode_SetBit(void* Obj)
	{
		((ASICharacter*)Obj)->bIsCombatMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode = { "bIsCombatMode", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASICharacter), &Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASICharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootGrenadeAnimMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_ShootOnceAnimMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCombatMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASICharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASICharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASICharacter_Statics::ClassParams = {
		&ASICharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASICharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASICharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASICharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASICharacter, 3864931579);
	template<> SI_API UClass* StaticClass<ASICharacter>()
	{
		return ASICharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASICharacter(Z_Construct_UClass_ASICharacter, &ASICharacter::StaticClass, TEXT("/Script/SI"), TEXT("ASICharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASICharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
