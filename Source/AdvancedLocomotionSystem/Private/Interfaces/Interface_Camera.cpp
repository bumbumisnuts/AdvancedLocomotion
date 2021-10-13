


#include "Interfaces/Interface_Camera.h"

// Add default functionality here for any IInterface_Camera functions that are not pure virtual.

void IInterface_Camera::GetCameraParameters(float& TP_FOV, float& FP_FOV, bool& RightShoulder)
{
}

void IInterface_Camera::GetCameraTargets(FVector& Target)
{
}

void IInterface_Camera::GetFPCameraTarget(FTransform& Transform)
{
}

void IInterface_Camera::Get3PTraceParams(FVector& TraceOrigin, float& TraceRadius, ETraceTypeQuery& TraceChannel)
{
}
