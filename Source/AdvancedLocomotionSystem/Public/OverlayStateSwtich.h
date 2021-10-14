

#pragma once

#include "CoreMinimal.h"
#include "OverlayStateButton.h"
#include "Blueprint/UserWidget.h"
#include "Data/Enums.h"
#include "OverlayStateSwtich.generated.h"


ENUM_RANGE_BY_COUNT(EALSOverlayState, EALSOverlayState::Default);
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API UOverlayStateSwtich : public UUserWidget
{
	GENERATED_BODY()


	public:


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY()
	UOverlayStateButton* Button;
	
	EALSOverlayState NewOverlayState;

	virtual void NativeConstruct() override;

	void CreateButtons();

	void UpdateButtonFocus();
	
};
