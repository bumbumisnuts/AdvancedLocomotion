

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "OverlayStateButton.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UOverlayStateButton : public UUserWidget
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditDefaultsOnly)
	UTextBlock* Text;
};
