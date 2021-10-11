

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UCPPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:

	UPROPERTY()
	ACharacter* Character = nullptr;
	
	virtual void NativeInitializeAnimation() override;
	
};
