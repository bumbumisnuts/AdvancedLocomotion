


#include "OverlayStateSwtich.h"

#include "interfaces/Interface_Character.h"
#include "Kismet/KismetTextLibrary.h"

void UOverlayStateSwtich::NativeConstruct()
{
	Super::NativeConstruct();

	IInterface_Character* InterfaceRef = Cast<IInterface_Character>(GetOwningPlayer()->GetPawn());

	if (InterfaceRef)
	{
		EMovementMode MovementMode;
		EALSMovementState MovementState;
		EALSMovementAction MovementAction;
		EALSRotationMode RotationMode;
		EALSGait Gait;
		EALSStance Stance;
		EALSViewMode ViewMode;
		InterfaceRef->GetCharacterCurrentStats(MovementMode, MovementState, MovementState, MovementAction,
			RotationMode, Gait, Stance, ViewMode, NewOverlayState);
		CreateButtons();
		UpdateButtonFocus();
		
	}
}

void UOverlayStateSwtich::CreateButtons()
{

	

	for (EALSOverlayState Overlay : TEnumRange<EALSOverlayState>())
	{
		
		Button = Cast<UOverlayStateButton>(CreateWidget(GetOwningPlayer(), WidgetClass));


		FString EnumAsString = StaticEnum<EALSOverlayState>()->GetValueAsString(Overlay);
		
		Button->Text->SetText(UKismetTextLibrary::Conv_StringToText(EnumAsString));
		
	}

	
	
}

void UOverlayStateSwtich::UpdateButtonFocus()
{

	for (EALSOverlayState Overlay : TEnumRange<EALSOverlayState>())
	{


		
	}
	
	
}
