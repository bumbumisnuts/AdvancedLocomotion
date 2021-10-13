

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Interfaces/Interface_Animation.h"
#include "Overlayoverride_notifyState.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UOverlayoverride_notifyState : public UAnimNotifyState, public IInterface_Animation
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere)
	int32 OverlayOverrideState = 0;


	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;

	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	virtual FString GetNotifyName_Implementation() const override;


	
};



