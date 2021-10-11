

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
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


	void SetMovementStats(EALSMovementState MovementState);

	void SetMovementAction(EALSMovementAction NewMovementAction);

	void SetRotationMode(EALSRotationMode NewRotation);

	void SetGaitMode(EALSGait NewGait);

	void SetViewMode(EALSViewMode NewViewMode);

	void SetOverlayState(EALSOverlayState NewOverlayState);

	
	void GetCharacterCurrentStats(EMovementMode& PawnMovementMode, EALSMovementState& IMovementState, EALSMovementState& PrevMovementState,
									EALSMovementAction& MovementAction, EALSRotationMode& RotationMode, EALSGait& ActualGait, EALSStance& ActualStance,
									EALSViewMode& ViewMode, EALSOverlayState& OverlayState);

	void GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput, bool& IsMoving
									, bool& HasMovementInput, float& Speed, float& MovementInputAmount, FRotator& AimingRotation, float& AimYawRate);
};
