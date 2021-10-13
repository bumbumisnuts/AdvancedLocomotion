


#include "AnimNotifies/Overlayoverride_notifyState.h"
#include "Kismet/KismetStringLibrary.h"


void UOverlayoverride_notifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	IInterface_Animation* AnimationInterface = Cast<IInterface_Animation>(MeshComp->GetAnimInstance());

	if (AnimationInterface)
	{
		AnimationInterface->SetOverlayState(OverlayOverrideState);
	}

}

void UOverlayoverride_notifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	IInterface_Animation* AnimationInterface = Cast<IInterface_Animation>(MeshComp->GetAnimInstance());
	AnimationInterface->SetOverlayState(0);
}

FString UOverlayoverride_notifyState::GetNotifyName_Implementation() const
{
	return Super::GetNotifyName_Implementation();
	
	return UKismetStringLibrary::Conv_IntToString(OverlayOverrideState);
}


