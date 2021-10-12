

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CameraAnimInstance.generated.h"


UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UCameraAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:


	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void UpdateCharacterInfo();

	UPROPERTY()
	APawn* ControlledPawn = nullptr;

	UPROPERTY()
	APlayerController* PLayerControllerRef = nullptr;
	
};
