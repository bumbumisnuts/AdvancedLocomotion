

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

	void OnPossess(APawn* NewPawn);
	
};
