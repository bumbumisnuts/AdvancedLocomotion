

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "CPlayerCameraManager.generated.h"


UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API ACPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()


	ACPlayerCameraManager();

	public:

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* CameraBehavior;

	UPROPERTY()
	APawn* ControlledPawn_Manager;

	UPROPERTY()
	FTransform PivotTransform;

	UPROPERTY()
	FVector FPTarget;

	UPROPERTY()
	float TP_FOV;

	UPROPERTY()
	float FP_FOV;

	UPROPERTY()
	bool RightShoulder;
	
	void OnPossess(APawn* NewPawn);

	//Check the Camera Target actor for the "ALS_Character" tag. This will let the camera manager know if it should use the custom camera behavior
	 bool BlueprintUpdateCamera(AActor* CameraTarget, FVector& NewCameraLocation, FRotator& NewCameraRotation, float& NewCameraFOV);
	
	//Calculate custom camera parameters
	void CustomCameraBehavior(FVector& Location, FRotator& Rotation, float& FOV);

	
};
