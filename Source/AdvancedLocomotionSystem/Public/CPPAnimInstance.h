

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UCPPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:


	//variables
	UPROPERTY()
	ACharacter* Character = nullptr;

	UPROPERTY()
	bool bJumped = false;

	float JumpplayRate;


	// the prefix A means it belongs to the anim instance class so that we dont get it confused with the interface function below
	FVector A_Velocity;

	FVector A_Acceleration;

	FVector A_MovementInput;

	bool A_IsMoving;

	bool A_HasMovementInput;

	float A_Speed;

	float A_MovementInputAmount;

	FRotator A_AimingRotation;

	float A_AimYawRate;



	
	
	virtual void NativeInitializeAnimation() override;

	void Jumped();

	void GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput, bool& IsMoving
									, bool& HasMovementInput, float& Speed,
									float& MovementInputAmount, FRotator& AimingRotation, float& AimYawRate);

	
};
