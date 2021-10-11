


#include "CPPAnimInstance.h"
#include "GameFramework/Character.h"

void UCPPAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		Character = Cast<ACharacter>(Pawn);
	}
}
