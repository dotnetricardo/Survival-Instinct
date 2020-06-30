// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SI_SICharacter_generated_h
#error "SICharacter.generated.h already included, missing '#pragma once' in SICharacter.h"
#endif
#define SI_SICharacter_generated_h

#define SI_Source_SI_Player_Public_SICharacter_h_15_SPARSE_DATA
#define SI_Source_SI_Player_Public_SICharacter_h_15_RPC_WRAPPERS
#define SI_Source_SI_Player_Public_SICharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SI_Source_SI_Player_Public_SICharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASICharacter(); \
	friend struct Z_Construct_UClass_ASICharacter_Statics; \
public: \
	DECLARE_CLASS(ASICharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SI"), NO_API) \
	DECLARE_SERIALIZER(ASICharacter)


#define SI_Source_SI_Player_Public_SICharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASICharacter(); \
	friend struct Z_Construct_UClass_ASICharacter_Statics; \
public: \
	DECLARE_CLASS(ASICharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SI"), NO_API) \
	DECLARE_SERIALIZER(ASICharacter)


#define SI_Source_SI_Player_Public_SICharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASICharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASICharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASICharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASICharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASICharacter(ASICharacter&&); \
	NO_API ASICharacter(const ASICharacter&); \
public:


#define SI_Source_SI_Player_Public_SICharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASICharacter(ASICharacter&&); \
	NO_API ASICharacter(const ASICharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASICharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASICharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASICharacter)


#define SI_Source_SI_Player_Public_SICharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraComp() { return STRUCT_OFFSET(ASICharacter, CameraComp); } \
	FORCEINLINE static uint32 __PPO__SpringArmComp() { return STRUCT_OFFSET(ASICharacter, SpringArmComp); }


#define SI_Source_SI_Player_Public_SICharacter_h_12_PROLOG
#define SI_Source_SI_Player_Public_SICharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SI_Source_SI_Player_Public_SICharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	SI_Source_SI_Player_Public_SICharacter_h_15_SPARSE_DATA \
	SI_Source_SI_Player_Public_SICharacter_h_15_RPC_WRAPPERS \
	SI_Source_SI_Player_Public_SICharacter_h_15_INCLASS \
	SI_Source_SI_Player_Public_SICharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SI_Source_SI_Player_Public_SICharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SI_Source_SI_Player_Public_SICharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	SI_Source_SI_Player_Public_SICharacter_h_15_SPARSE_DATA \
	SI_Source_SI_Player_Public_SICharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SI_Source_SI_Player_Public_SICharacter_h_15_INCLASS_NO_PURE_DECLS \
	SI_Source_SI_Player_Public_SICharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SI_API UClass* StaticClass<class ASICharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SI_Source_SI_Player_Public_SICharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
