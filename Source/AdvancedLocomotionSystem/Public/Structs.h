

#pragma once

#include "Curves/CurveFloat.h"
#include "Curves/CurveVector.h"
#include "Structs.generated.h"

USTRUCT(BlueprintType)
struct FMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float WalkSpeed = 0;

	UPROPERTY(BlueprintReadWrite)
	float RunSpeed = 0;

	UPROPERTY(BlueprintReadWrite)
	float SprintSpeed = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCurveFloat* RotationRateCurve = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCurveVector* MovementCurve = nullptr;

	
};

USTRUCT(BlueprintType)
struct FMantleParams
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimMontage* AnimMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCurveVector* PositionCorrectionCurve;

	UPROPERTY(BlueprintReadWrite)
	float StartingPosition = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float PlayRate = 0.f;

	UPROPERTY(BlueprintReadWrite)
	FVector StartingOffset = FVector(0.f);
};

USTRUCT(BlueprintType)
struct FALSComponentTransform
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FTransform Transform;

	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent* Component;
};

USTRUCT(BlueprintType)
struct FMantle_TraceSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float MaxLedgeHeight = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float MinLedgeHeight = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float ReachDistance = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float ForwardTraceRadius = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float DownwardTraceRadius = 0.f;
};