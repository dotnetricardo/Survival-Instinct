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
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	SI_API UClass* Z_Construct_UClass_USI_HealthComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SI_API UClass* Z_Construct_UClass_AWeaponActualMaster_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASICharacter::execResetHitReaction)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetHitReaction();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASICharacter::execApplyForceToHitBone)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyForceToHitBone();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASICharacter::execAnimateHitBlendWeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimateHitBlendWeight(Z_Param_Value);
		P_NATIVE_END;
	}
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
	DEFINE_FUNCTION(ASICharacter::execOnHealthChanged)
	{
		P_GET_OBJECT(USI_HealthComponent,Z_Param_HealthComp);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Health);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HealthDelta);
		P_GET_PROPERTY(FIntProperty,Z_Param_Armor);
		P_GET_OBJECT(UDamageType,Z_Param_DamageType);
		P_GET_OBJECT(AController,Z_Param_InstigatedBy);
		P_GET_OBJECT(AActor,Z_Param_DamageCauser);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHealthChanged(Z_Param_HealthComp,Z_Param_Health,Z_Param_HealthDelta,Z_Param_Armor,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser);
		P_NATIVE_END;
	}
	void ASICharacter::StaticRegisterNativesASICharacter()
	{
		UClass* Class = ASICharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimateCameraLocation", &ASICharacter::execAnimateCameraLocation },
			{ "AnimateHitBlendWeight", &ASICharacter::execAnimateHitBlendWeight },
			{ "AnimateSpringArmHeight", &ASICharacter::execAnimateSpringArmHeight },
			{ "AnimateSpringArmLength", &ASICharacter::execAnimateSpringArmLength },
			{ "ApplyForceToHitBone", &ASICharacter::execApplyForceToHitBone },
			{ "OnHealthChanged", &ASICharacter::execOnHealthChanged },
			{ "ResetHitReaction", &ASICharacter::execResetHitReaction },
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
	struct Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics
	{
		struct SICharacter_eventAnimateHitBlendWeight_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventAnimateHitBlendWeight_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "AnimateHitBlendWeight", nullptr, nullptr, sizeof(SICharacter_eventAnimateHitBlendWeight_Parms), Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight_Statics::FuncParams);
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
	struct Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "ApplyForceToHitBone", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics
	{
		struct SICharacter_eventOnHealthChanged_Parms
		{
			USI_HealthComponent* HealthComp;
			float Health;
			float HealthDelta;
			int32 Armor;
			const UDamageType* DamageType;
			AController* InstigatedBy;
			AActor* DamageCauser;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstigatedBy;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageType;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Armor;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealthDelta;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_InstigatedBy = { "InstigatedBy", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageType_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_Armor = { "Armor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, Armor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthDelta = { "HealthDelta", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, HealthDelta), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, Health), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthComp = { "HealthComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SICharacter_eventOnHealthChanged_Parms, HealthComp), Z_Construct_UClass_USI_HealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageCauser,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_InstigatedBy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_DamageType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_Armor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthDelta,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::NewProp_HealthComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "OnHealthChanged", nullptr, nullptr, sizeof(SICharacter_eventOnHealthChanged_Parms), Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_OnHealthChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_OnHealthChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASICharacter, nullptr, "ResetHitReaction", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASICharacter_ResetHitReaction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASICharacter_ResetHitReaction_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDied_MetaData[];
#endif
		static void NewProp_bDied_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDied;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxWeaponsCarry_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxWeaponsCarry;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxGrenameMagsCarry_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxGrenameMagsCarry;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxWeaponMagsCarry_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxWeaponMagsCarry;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrenadeMagsCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_GrenadeMagsCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponMagsCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WeaponMagsCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DieAudioFx_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DieAudioFx;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitAudioFx_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitAudioFx;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitReactionCurveFloat_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitReactionCurveFloat;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnedWeapons_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SpawnedWeapons;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpawnedWeapons_Inner;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthWidgetComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthWidgetComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsWalkMode_MetaData[];
#endif
		static void NewProp_bIsWalkMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsWalkMode;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultRunSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultRunSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultWalkSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultWalkSpeed;
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
		{ &Z_Construct_UFunction_ASICharacter_AnimateHitBlendWeight, "AnimateHitBlendWeight" }, // 4272799109
		{ &Z_Construct_UFunction_ASICharacter_AnimateSpringArmHeight, "AnimateSpringArmHeight" }, // 604125465
		{ &Z_Construct_UFunction_ASICharacter_AnimateSpringArmLength, "AnimateSpringArmLength" }, // 327589450
		{ &Z_Construct_UFunction_ASICharacter_ApplyForceToHitBone, "ApplyForceToHitBone" }, // 647108356
		{ &Z_Construct_UFunction_ASICharacter_OnHealthChanged, "OnHealthChanged" }, // 2489310364
		{ &Z_Construct_UFunction_ASICharacter_ResetHitReaction, "ResetHitReaction" }, // 1655510260
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/Public/SICharacter.h" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied_SetBit(void* Obj)
	{
		((ASICharacter*)Obj)->bDied = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied = { "bDied", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASICharacter), &Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry = { "MaxWeaponsCarry", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, MaxWeaponsCarry), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxGrenameMagsCarry_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxGrenameMagsCarry = { "MaxGrenameMagsCarry", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, MaxGrenameMagsCarry), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxGrenameMagsCarry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxGrenameMagsCarry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponMagsCarry_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponMagsCarry = { "MaxWeaponMagsCarry", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, MaxWeaponMagsCarry), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponMagsCarry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponMagsCarry_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_GrenadeMagsCount_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_GrenadeMagsCount = { "GrenadeMagsCount", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, GrenadeMagsCount), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_GrenadeMagsCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_GrenadeMagsCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponMagsCount_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponMagsCount = { "WeaponMagsCount", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, WeaponMagsCount), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponMagsCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponMagsCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_DieAudioFx_MetaData[] = {
		{ "Category", "AudioFx" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_DieAudioFx = { "DieAudioFx", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, DieAudioFx), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_DieAudioFx_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_DieAudioFx_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_HitAudioFx_MetaData[] = {
		{ "Category", "AudioFx" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_HitAudioFx = { "HitAudioFx", nullptr, (EPropertyFlags)0x0020080000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, HitAudioFx), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_HitAudioFx_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_HitAudioFx_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_HitReactionCurveFloat_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_HitReactionCurveFloat = { "HitReactionCurveFloat", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, HitReactionCurveFloat), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_HitReactionCurveFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_HitReactionCurveFloat_MetaData)) };
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons = { "SpawnedWeapons", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, SpawnedWeapons), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons_Inner = { "SpawnedWeapons", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory = { "WeaponInventory", nullptr, (EPropertyFlags)0x0014000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, WeaponInventory), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_Inner = { "WeaponInventory", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AWeaponActualMaster_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData[] = {
		{ "Category", "Components" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex = { "WeaponInventoryIndex", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, WeaponInventoryIndex), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_HealthWidgetComponent_MetaData[] = {
		{ "Category", "Default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_HealthWidgetComponent = { "HealthWidgetComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, HealthWidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_HealthWidgetComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_HealthWidgetComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	void Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode_SetBit(void* Obj)
	{
		((ASICharacter*)Obj)->bIsWalkMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode = { "bIsWalkMode", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASICharacter), &Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode_MetaData)) };
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultRunSpeed_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultRunSpeed = { "DefaultRunSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, DefaultRunSpeed), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultRunSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultRunSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultWalkSpeed_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultWalkSpeed = { "DefaultWalkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASICharacter, DefaultWalkSpeed), METADATA_PARAMS(Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultWalkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultWalkSpeed_MetaData)) };
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
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bDied,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponsCarry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxGrenameMagsCarry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_MaxWeaponMagsCarry,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_GrenadeMagsCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponMagsCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_DieAudioFx,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_HitAudioFx,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_HitReactionCurveFloat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_AimCurveFloat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SwichModesCurveFloat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SpringArmComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_CameraComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_SpawnedWeapons_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventory_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_WeaponInventoryIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_HealthWidgetComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsWalkMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsFiring,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_bIsCrouching,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_InputAxisYawValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultRunSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASICharacter_Statics::NewProp_DefaultWalkSpeed,
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
	IMPLEMENT_CLASS(ASICharacter, 358056490);
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
