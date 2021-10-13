


#include "interfaces/Interface_Character.h"

// Add default functionality here for any IInterface_Character functions that are not pure virtual.


void IInterface_Character::SetMovementStats(EALSMovementState MovementState)
{
}

void IInterface_Character::SetMovementAction(EALSMovementAction NewMovementAction)
{
}

void IInterface_Character::SetRotationMode(EALSRotationMode NewRotation)
{
}

void IInterface_Character::SetGaitMode(EALSGait NewGait)
{
}

void IInterface_Character::SetViewMode(EALSViewMode NewViewMode)
{
}

void IInterface_Character::SetOverlayState(EALSOverlayState NewOverlayState)
{
}

void IInterface_Character::GetCharacterCurrentStats(EMovementMode& PawnMovementMode, EALSMovementState& IMovementState,
	EALSMovementState& PrevMovementState, EALSMovementAction& MovementAction, EALSRotationMode& RotationMode,
	EALSGait& ActualGait, EALSStance& ActualStance, EALSViewMode& ViewMode, EALSOverlayState& OverlayState)
{
}

void IInterface_Character::GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput,
	bool& IsMoving, bool& HasMovementInput, float& Speed, float& MovementInputAmount, FRotator& AimingRotation,
	float& AimYawRate)
{
}
