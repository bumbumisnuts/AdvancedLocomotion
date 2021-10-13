

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Interfaces/Interface_Animation.h"
#include "CPPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UCPPAnimInstance : public UAnimInstance, public IInterface_Animation
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

	int32 A_Overlaystate = 0;
	
	
	
	virtual void NativeInitializeAnimation() override;

	virtual void Jumped() override;

	void GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput, bool& IsMoving
									, bool& HasMovementInput, float& Speed,
									float& MovementInputAmount, FRotator& AimingRotation, float& AimYawRate);

	virtual void SetOverlayState(int32 GroundedEntryState) override;


	
};
