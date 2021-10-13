

#pragma once

#include "CoreMinimal.h"
#include "Data/Enums.h"
#include "UObject/Interface.h"
#include "Interface_Character.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Character : public UInterface
{
	GENERATED_BODY()
};


class ADVANCEDLOCOMOTIONSYSTEM_API IInterface_Character
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	virtual void SetMovementStats(EALSMovementState MovementState);

	virtual void SetMovementAction(EALSMovementAction NewMovementAction);

	virtual void SetRotationMode(EALSRotationMode NewRotation);

	virtual void SetGaitMode(EALSGait NewGait);

	virtual void SetViewMode(EALSViewMode NewViewMode);

	virtual void SetOverlayState(EALSOverlayState NewOverlayState);

	
	virtual void GetCharacterCurrentStats(EMovementMode& PawnMovementMode, EALSMovementState& IMovementState, EALSMovementState& PrevMovementState,
									EALSMovementAction& MovementAction, EALSRotationMode& RotationMode, EALSGait& ActualGait, EALSStance& ActualStance,
									EALSViewMode& ViewMode, EALSOverlayState& OverlayState);

	virtual void GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput, bool& IsMoving
									, bool& HasMovementInput, float& Speed,
									float& MovementInputAmount, FRotator& AimingRotation, float& AimYawRate);
};
