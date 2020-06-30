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
// End Cross Module References
	void ASICharacter::StaticRegisterNativesASICharacter()
	{
	}
	UClass* Z_Construct_UClass_ASICharacter_NoRegister()
	{
		return ASICharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASICharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASICharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASICharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/Public/SICharacter.h" },
		{ "ModuleRelativePath", "Player/Public/SICharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASICharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASICharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASICharacter_Statics::ClassParams = {
		&ASICharacter::StaticClass,
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
	IMPLEMENT_CLASS(ASICharacter, 286235205);
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
