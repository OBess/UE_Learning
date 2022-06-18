// Fill out your copyright notice in the Description page of Project Settings.

#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "Test/TestCalculator.h"
#include "CoreMinimal.h"
#include "CalculatorEBNF/Public/Calculator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCalculatorEBNF_Compute, "CalculatorEBNF.Compute",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FCalculatorEBNF_Compute::RunTest(const FString& Parameters)
{
	struct TestPayLoad
	{
		const FString Expression;
		const float Expected;
	};

	const TArray<TestPayLoad> TestData
	{
		{TEXT("1+1"), 2},
		{TEXT("1 - 1"), 0},
		{TEXT("2 *   3"), 6},
		{TEXT("3 /3"), 1},
		{TEXT("1+1-3"), -1},	// More than one operation
		{TEXT("1-(1+3   ) + 5"), 2},	// Using ordering of operations
		{TEXT("3.3*3 /2.0"), 4.95},		// Can compute float data
		{TEXT("3.03*3 /2.01"), 4.52}		// More float
	};

	const float Tolerance = 1e-2;

	for (const auto& Data : TestData)
	{
		const float Computed = ACalculator::Compute(Data.Expression);
		TestEqual(FString::Printf(TEXT("Expression: %s; Expected: %f; Actual: %f"),
			*Data.Expression, Data.Expected, Computed), Computed, Data.Expected, Tolerance);
	}

	return true;
}

#endif