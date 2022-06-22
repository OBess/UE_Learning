// Fill out your copyright notice in the Description page of Project Settings.


#include "Calculator.h"

static float ParseExpression(const FString& Expression, int32& OutPosition);

float ACalculator::Compute(const FString& Expression)
{
	int32 Position = 0;
	return ParseExpression(Expression, Position);
}

/**
* Skips all spaces between key symbols.
* @param Expression - Expression to compute.
* @param OutPosition - Position of parser in expression.
*/
static void SkipSpaces(const FString& Expression, int32& OutPosition) noexcept
{
	for (; OutPosition < Expression.Len() && Expression[OutPosition] == ' '; ++OutPosition)
	{
	}
}

/**
* Compute value of expression.
* @param Lhs - Left hand side value of expression.
* @param Rhs - Right hand side value of expression.
* @param Operation - The operation being performed.
*/
static float Compute(const float Lhs, const float Rhs, const char Operation)
{
	switch (Operation)
	{
	case '-':
		return Lhs - Rhs;
		break;

	case '+':
		return Lhs + Rhs;
		break;

	case '*':
		return Lhs * Rhs;
		break;

	case '/':
		return Lhs / Rhs;
		break;

	default:
		break;
	}

	return 0.0f;
}

/**
* Parse a float number from expression.
* @param Expression - Expression to compute.
* @param OutPosition - Position of parser in expression.
* @return Parsed number
*/
static float ParseNumber(const FString& Expression, int32& OutPosition) noexcept
{
	// Left hand side of float number
	float Lhs = 0;

	for (; OutPosition < Expression.Len(); ++OutPosition)
	{
		if (Expression[OutPosition] < '0' || Expression[OutPosition] > '9')
		{
			break;
		}

		Lhs = Lhs * 10 + (Expression[OutPosition] - '0');
	}

	// Find right hand side of float number only if we have '.' sign
	if (OutPosition < Expression.Len() && Expression[OutPosition] != '.')
	{
		return Lhs;
	}

	++OutPosition;

	// Right hand side of float number
	float Rhs = 0;
	float grade = 10;

	for (; OutPosition < Expression.Len(); ++OutPosition)
	{
		if (Expression[OutPosition] < '0' || Expression[OutPosition] > '9')
		{
			break;
		}

		Rhs = Rhs + (Expression[OutPosition] - '0') / grade;
		grade *= 10;
	}

	return Lhs + Rhs;
}

/**
* Whether it is a operation of first group.
* @param Operation - The operation being performed.
* @return True - if Operation is '-' or '+' and not equal ')'
*/
static bool IsOperation1(const char Operation) noexcept
{
	return (Operation == '-' || Operation == '+') && Operation != ')';
}

/**
* Whether it is a operation of second group.
* @param Operation - The operation being performed.
* @return True - if Operation is '*' or '/' and not equal ')'
*/
static bool IsOperation2(const char Operation) noexcept
{
	return (Operation == '*' || Operation == '/') && Operation != ')';
}

/**
* Parse sub-exspression, sub-factor or parse number.
* @param Expression - Expression to compute.
* @param OutPosition - Position of parser in expression.
* @return Parsed sub-exspresion, sub-factor or number
*/
static float ParseFactor(const FString& Expression, int32& OutPosition)
{
	SkipSpaces(Expression, OutPosition);

	float Result = 0;

	switch (Expression[OutPosition])
	{
	case '(':
		// Start of new expression
		Result = ParseExpression(Expression, ++OutPosition);
		++OutPosition;
		break;

	case '-':
		Result = ParseFactor(Expression, ++OutPosition) * -1;
		break;

	default:
		Result = ParseNumber(Expression, OutPosition);
		break;
	}

	SkipSpaces(Expression, OutPosition);

	return Result;
}

/**
* Parse term which can contain some factors and perform computing.
* @param Expression - Expression to compute.
* @param OutPosition - Position of parser in expression.
* @return Parsed sub-exspresion
*/
static float ParseTerm(const FString& Expression, int32& OutPosition)
{
	SkipSpaces(Expression, OutPosition);

	float Result = ParseFactor(Expression, OutPosition);

	// End of expression
	if (OutPosition >= Expression.Len())
	{
		return Result;
	}

	char Operation = Expression[OutPosition];

	while (IsOperation2(Operation))
	{
		Result = Compute(Result, ParseFactor(Expression, ++OutPosition), Operation);

		if (OutPosition >= Expression.Len())
		{
			break;
		}			

		Operation = Expression[OutPosition];
	}

	return Result;
}

/**
* Parse expression which can contain some terms and perform computing.
* @param Expression - Expression to compute.
* @param OutPosition - Position of parser in expression.
* @return Parsed sub-exspresion
*/
static float ParseExpression(const FString& Expression, int32& OutPosition)
{
	SkipSpaces(Expression, OutPosition);

	float Result = ParseTerm(Expression, OutPosition);

	if (OutPosition >= Expression.Len())
	{
		return Result;
	}

	char Operation = Expression[OutPosition];

	while (IsOperation1(Operation))
	{
		Result = Compute(Result, ParseTerm(Expression, ++OutPosition), Operation);

		if (OutPosition >= Expression.Len())
		{
			break;
		}

		Operation = Expression[OutPosition];
	}

	return Result;
}
