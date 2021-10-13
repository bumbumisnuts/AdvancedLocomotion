

#pragma once

#include "Enums.generated.h"

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSRotationMode : uint8
{
	VelocityDirection	UMETA(DisplayName = "VelocityDirection"),
	LookingDirection	UMETA(DisplayName = "LookingDirection"),
	Aiming				UMETA(DisplayName = "Aiming")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSGait : uint8
{
	Walking		UMETA(DisplayName = "Walking"),
	Running		UMETA(DisplayName = "Running"),
	Sprinting	UMETA(DisplayName = "Sprinting")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSStance : uint8
{
	Standing	UMETA(DisplayName = "Standing"),
	Crouching	UMETA(DisplayName = "Crouching")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSMovementState : uint8
{
	None		UMETA(DisplayName = "None"),
	Grounded	UMETA(DisplayName = "Grounded"),
	InAir		UMETA(DisplayName = "In Air"),
	Mantling	UMETA(DisplayName = "Mantling"),
	Ragdoll		UMETA(DisplayName = "Ragdoll")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSViewMode : uint8
{
	ThirdPerson		UMETA(DisplayName = "ThirdPerson"),
	FirstPerson		UMETA(DisplayName = "FirstPerson")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EALSOverlayState : uint8
{
	Default		UMETA(DisplayName = "Default"),
	Masculine	UMETA(DisplayName = "Masculine"),
	Feminine	UMETA(DisplayName = "Feminine"),
	Injured		UMETA(DisplayName = "Injured"),
	HandsTied	UMETA(DisplayName = "HandsTied"),
	Rifle		UMETA(DisplayName = "Rifle"),
	Pistol1H	UMETA(DisplayName = "Pistol 1H"),
	Pistol2H	UMETA(DisplayName = "Pistol 2H"),
	Bow			UMETA(DisplayName = "Bow"),
	Torch		UMETA(DisplayName = "Torch"),
	Binoculars	UMETA(DisplayName = "Binoculars"),
	Box			UMETA(DisplayName = "Box"),
	Barrel		UMETA(DisplayName = "Barrel")
};
UENUM(BlueprintType, Category = "MovementMode")
enum class EALSMovementAction : uint8
{
	None		UMETA(DisplayName = "None"),
	LowMantle	UMETA(DisplayName = "LowMantle"),
	HighMantle	UMETA(DsiplayName = "HighMantle"),
	Rolling		UMETA(DsiplayName = "Rolling"),
	GettingUp	UMETA(DisplayName = "GettingUp")
};

UENUM(BlueprintType, Category = "MovementMode")
enum class EGroundedEntryState : uint8
{
	None		UMETA(DisplayName = "None"),
	Roll		UMETA(DisplayName = "Roll")
};
