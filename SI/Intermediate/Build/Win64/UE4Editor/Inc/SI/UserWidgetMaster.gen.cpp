// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SI/Widget/Public/UserWidgetMaster.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUserWidgetMaster() {}
// Cross Module References
	SI_API UClass* Z_Construct_UClass_UUserWidgetMaster_NoRegister();
	SI_API UClass* Z_Construct_UClass_UUserWidgetMaster();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SI();
	UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
// End Cross Module References
	void UUserWidgetMaster::StaticRegisterNativesUUserWidgetMaster()
	{
	}
	UClass* Z_Construct_UClass_UUserWidgetMaster_NoRegister()
	{
		return UUserWidgetMaster::StaticClass();
	}
	struct Z_Construct_UClass_UUserWidgetMaster_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_crosshair_default_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_crosshair_default;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUserWidgetMaster_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUserWidgetMaster_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widget/Public/UserWidgetMaster.h" },
		{ "ModuleRelativePath", "Widget/Public/UserWidgetMaster.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUserWidgetMaster_Statics::NewProp_crosshair_default_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UserWidgetMaster" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Widget/Public/UserWidgetMaster.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUserWidgetMaster_Statics::NewProp_crosshair_default = { "crosshair_default", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUserWidgetMaster, crosshair_default), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UUserWidgetMaster_Statics::NewProp_crosshair_default_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUserWidgetMaster_Statics::NewProp_crosshair_default_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUserWidgetMaster_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUserWidgetMaster_Statics::NewProp_crosshair_default,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUserWidgetMaster_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUserWidgetMaster>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUserWidgetMaster_Statics::ClassParams = {
		&UUserWidgetMaster::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UUserWidgetMaster_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UUserWidgetMaster_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUserWidgetMaster_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUserWidgetMaster_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUserWidgetMaster()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUserWidgetMaster_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUserWidgetMaster, 1695708599);
	template<> SI_API UClass* StaticClass<UUserWidgetMaster>()
	{
		return UUserWidgetMaster::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUserWidgetMaster(Z_Construct_UClass_UUserWidgetMaster, &UUserWidgetMaster::StaticClass, TEXT("/Script/SI"), TEXT("UUserWidgetMaster"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUserWidgetMaster);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
