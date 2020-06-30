// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SI_SIGameModeBase_generated_h
#error "SIGameModeBase.generated.h already included, missing '#pragma once' in SIGameModeBase.h"
#endif
#define SI_SIGameModeBase_generated_h

#define SI_Source_SI_SIGameModeBase_h_15_SPARSE_DATA
#define SI_Source_SI_SIGameModeBase_h_15_RPC_WRAPPERS
#define SI_Source_SI_SIGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SI_Source_SI_SIGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASIGameModeBase(); \
	friend struct Z_Construct_UClass_ASIGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ASIGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/SI"), NO_API) \
	DECLARE_SERIALIZER(ASIGameModeBase)


#define SI_Source_SI_SIGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASIGameModeBase(); \
	friend struct Z_Construct_UClass_ASIGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ASIGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/SI"), NO_API) \
	DECLARE_SERIALIZER(ASIGameModeBase)


#define SI_Source_SI_SIGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASIGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASIGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASIGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASIGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASIGameModeBase(ASIGameModeBase&&); \
	NO_API ASIGameModeBase(const ASIGameModeBase&); \
public:


#define SI_Source_SI_SIGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASIGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASIGameModeBase(ASIGameModeBase&&); \
	NO_API ASIGameModeBase(const ASIGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASIGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASIGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASIGameModeBase)


#define SI_Source_SI_SIGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define SI_Source_SI_SIGameModeBase_h_12_PROLOG
#define SI_Source_SI_SIGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SI_Source_SI_SIGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	SI_Source_SI_SIGameModeBase_h_15_SPARSE_DATA \
	SI_Source_SI_SIGameModeBase_h_15_RPC_WRAPPERS \
	SI_Source_SI_SIGameModeBase_h_15_INCLASS \
	SI_Source_SI_SIGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SI_Source_SI_SIGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SI_Source_SI_SIGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	SI_Source_SI_SIGameModeBase_h_15_SPARSE_DATA \
	SI_Source_SI_SIGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SI_Source_SI_SIGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	SI_Source_SI_SIGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SI_API UClass* StaticClass<class ASIGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SI_Source_SI_SIGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
