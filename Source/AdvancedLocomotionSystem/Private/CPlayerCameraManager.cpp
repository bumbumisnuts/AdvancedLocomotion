


#include "CPlayerCameraManager.h"
#include "CameraAnimInstance.h"
#include "Interface_Camera.h"

ACPlayerCameraManager::ACPlayerCameraManager()
{
	CameraBehavior = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Camera Behavior"));
	CameraBehavior->SetupAttachment(GetRootComponent());
}

void ACPlayerCameraManager::OnPossess(APawn* NewPawn)
{
	ControlledPawn_Manager = NewPawn;


	UCameraAnimInstance* CameraAnimInstance = Cast<UCameraAnimInstance>(	CameraBehavior->GetAnimInstance());

	CameraAnimInstance->ControlledPawn = ControlledPawn_Manager;
	CameraAnimInstance->PLayerControllerRef = GetOwningPlayerController();
	
}

bool ACPlayerCameraManager::BlueprintUpdateCamera(AActor* CameraTarget, FVector& NewCameraLocation,
	FRotator& NewCameraRotation, float& NewCameraFOV)
{
	if (CameraTarget->ActorHasTag(TEXT("ALS_Character")))
	{
		CustomCameraBehavior(NewCameraLocation, NewCameraRotation, NewCameraFOV);
	}else
	{
		Super::BlueprintUpdateCamera(CameraTarget, NewCameraLocation, NewCameraRotation, NewCameraFOV);
	}	
}

void ACPlayerCameraManager::CustomCameraBehavior(FVector& Location, FRotator& Rotation, float& FOV)
{
	IInterface_Camera* INTRef;

	INTRef = Cast<IInterface_Camera>(ControlledPawn_Manager);
	if (INTRef)
	{
		INTRef->GetFPCameraTarget(PivotTransform);
		INTRef->GetCameraTargets(FPTarget);
		INTRef->GetCameraParameters(TP_FOV, FP_FOV, RightShoulder);
	}
}

