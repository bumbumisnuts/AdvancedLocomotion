

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_Camera.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Camera : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADVANCEDLOCOMOTIONSYSTEM_API IInterface_Camera
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void GetCameraParameters(float& TP_FOV, float& FP_FOV, bool& RightShoulder);

	virtual void GetCameraTargets(FVector& Target);

	virtual void GetFPCameraTarget(FTransform& Transform);

	virtual void Get3PTraceParams(FVector& TraceOrigin, float& TraceRadius, ETraceTypeQuery& TraceChannel);

	
};
