// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CalculatorEBNF/Public/Calculator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCalculator() {}
// Cross Module References
	CALCULATOREBNF_API UClass* Z_Construct_UClass_ACalculator_NoRegister();
	CALCULATOREBNF_API UClass* Z_Construct_UClass_ACalculator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CalculatorEBNF();
// End Cross Module References
	DEFINE_FUNCTION(ACalculator::execCompute)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Expression);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=ACalculator::Compute(Z_Param_Expression);
		P_NATIVE_END;
	}
	void ACalculator::StaticRegisterNativesACalculator()
	{
		UClass* Class = ACalculator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Compute", &ACalculator::execCompute },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACalculator_Compute_Statics
	{
		struct Calculator_eventCompute_Parms
		{
			FString Expression;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Expression_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Expression;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_Expression_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_Expression = { "Expression", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Calculator_eventCompute_Parms, Expression), METADATA_PARAMS(Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_Expression_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_Expression_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Calculator_eventCompute_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACalculator_Compute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_Expression,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACalculator_Compute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACalculator_Compute_Statics::Function_MetaDataParams[] = {
		{ "Category", "CalculatorEBNF" },
		{ "Comment", "/**\n\x09 * Finds result of an expression using the EBNF algoritm. Can be used in Blueprints.\n\x09 * @param Expression - Expression to compute [1 + 1]; can contain spaces.\n\x09 * @return Expression compution result\n\x09 */" },
		{ "ModuleRelativePath", "Public/Calculator.h" },
		{ "ToolTip", "Finds result of an expression using the EBNF algoritm. Can be used in Blueprints.\n@param Expression - Expression to compute [1 + 1]; can contain spaces.\n@return Expression compution result" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACalculator_Compute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACalculator, nullptr, "Compute", nullptr, nullptr, sizeof(Calculator_eventCompute_Parms), Z_Construct_UFunction_ACalculator_Compute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACalculator_Compute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACalculator_Compute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACalculator_Compute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACalculator_Compute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACalculator_Compute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACalculator_NoRegister()
	{
		return ACalculator::StaticClass();
	}
	struct Z_Construct_UClass_ACalculator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACalculator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CalculatorEBNF,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACalculator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACalculator_Compute, "Compute" }, // 4278238670
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACalculator_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* ACalculator implements EBNF algorithm (https://en.wikipedia.org/wiki/Extended_Backus?Naur_form)\n* to compute some math expression. Current expression can contain +,-,*,/ operations and can use brackets.\n* All spaces are ignored. There is no validation check in this implementation !!!\n*/" },
		{ "IncludePath", "Calculator.h" },
		{ "ModuleRelativePath", "Public/Calculator.h" },
		{ "ToolTip", "ACalculator implements EBNF algorithm (https://en.wikipedia.org/wiki/Extended_Backus?Naur_form)\nto compute some math expression. Current expression can contain +,-,*,/ operations and can use brackets.\nAll spaces are ignored. There is no validation check in this implementation !!!" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACalculator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACalculator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACalculator_Statics::ClassParams = {
		&ACalculator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACalculator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACalculator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACalculator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACalculator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACalculator, 4039960681);
	template<> CALCULATOREBNF_API UClass* StaticClass<ACalculator>()
	{
		return ACalculator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACalculator(Z_Construct_UClass_ACalculator, &ACalculator::StaticClass, TEXT("/Script/CalculatorEBNF"), TEXT("ACalculator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACalculator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
