


#include "CPlayerCameraManager.h"

#include "CameraAnimInstance.h"

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
