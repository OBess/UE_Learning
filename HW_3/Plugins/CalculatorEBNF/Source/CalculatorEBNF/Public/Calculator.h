// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Calculator.generated.h"

/**
* ACalculator implements EBNF algorithm (https://en.wikipedia.org/wiki/Extended_Backus–Naur_form)
* to compute some math expression. Current expression can contain +,-,*,/ operations and can use brackets.
* All spaces are ignored. There is no validation check in this implementation !!!
*/
UCLASS()
class CALCULATOREBNF_API ACalculator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACalculator() = default;

public:

	/**
	 * Finds result of an expression using the EBNF algoritm. Can be used in Blueprints.
	 * @param Expression - Expression to compute [1 + 1]; can contain spaces.
	 * @return Expression compution result
	 */
	UFUNCTION(BlueprintCallable, meta = (Category = "CalculatorEBNF"))
		static float Compute(const FString& Expression);

};
