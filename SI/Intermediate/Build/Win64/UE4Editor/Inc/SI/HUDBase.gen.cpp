// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SI/Widget/Public/HUDBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHUDBase() {}
// Cross Module References
	SI_API UClass* Z_Construct_UClass_AHUDBase_NoRegister();
	SI_API UClass* Z_Construct_UClass_AHUDBase();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_SI();
	SI_API UClass* Z_Construct_UClass_UUserWidgetMaster_NoRegister();
// End Cross Module References
	void AHUDBase::StaticRegisterNativesAHUDBase()
	{
	}
	UClass* Z_Construct_UClass_AHUDBase_NoRegister()
	{
		return AHUDBase::StaticClass();
	}
	struct Z_Construct_UClass_AHUDBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrossHairWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CrossHairWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHUDBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_SI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHUDBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Widget/Public/HUDBase.h" },
		{ "ModuleRelativePath", "Widget/Public/HUDBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHUDBase_Statics::NewProp_CrossHairWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "// Internal reference to the blueprint for gameplay logic\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Widget/Public/HUDBase.h" },
		{ "ToolTip", "Internal reference to the blueprint for gameplay logic" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHUDBase_Statics::NewProp_CrossHairWidget = { "CrossHairWidget", nullptr, (EPropertyFlags)0x001000000008000c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHUDBase, CrossHairWidget), Z_Construct_UClass_UUserWidgetMaster_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHUDBase_Statics::NewProp_CrossHairWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHUDBase_Statics::NewProp_CrossHairWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHUDBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHUDBase_Statics::NewProp_CrossHairWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHUDBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHUDBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHUDBase_Statics::ClassParams = {
		&AHUDBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AHUDBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AHUDBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHUDBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHUDBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHUDBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHUDBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHUDBase, 2694513321);
	template<> SI_API UClass* StaticClass<AHUDBase>()
	{
		return AHUDBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHUDBase(Z_Construct_UClass_AHUDBase, &AHUDBase::StaticClass, TEXT("/Script/SI"), TEXT("AHUDBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHUDBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
