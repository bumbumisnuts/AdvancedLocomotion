


#include "CPPAnimInstance.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

void UCPPAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		Character = Cast<ACharacter>(Pawn);
	}
}

void UCPPAnimInstance::Jumped()
{
	bJumped = true;

	JumpplayRate = UKismetMathLibrary::MapRangeClamped(A_Speed, 0.0f, 600.f, 1.2f, 1.5f);
	
}

void UCPPAnimInstance::GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput,
	bool& IsMoving, bool& HasMovementInput, float& Speed, float& MovementInputAmount, FRotator& AimingRotation,
	float& AimYawRate)
{
	A_Velocity = Velocity;
	A_Acceleration = Acceleration;
	A_MovementInput = MovementInput;
	A_IsMoving = IsMoving;
	A_HasMovementInput = HasMovementInput;
	A_Speed = Speed;
	A_MovementInputAmount = MovementInputAmount;
	A_AimingRotation = AimingRotation;
	A_AimYawRate = AimYawRate;
}

void UCPPAnimInstance::SetOverlayState(int32 OverlayState)
{
	A_Overlaystate = OverlayState;
}
