


#include "ALSController.h"
#include "Blueprint/UserWidget.h"
#include "ALSBaseCharacterC.h"
#include "CPlayerCameraManager.h"
#include "ToolBuilderUtil.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/GameplayStatics.h"

void AALSController::OnPossess(APawn* MovieSceneBlends)
{
	Super::OnPossess(MovieSceneBlends);

	
}

void AALSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("OpenOverlayMenu", IE_Pressed, this,  &AALSController::OpenOverlayMenu);
	InputComponent->BindAction("OpenOverlayMenu", IE_Released, this,  &AALSController::OpenOverlayMenu);

}

void AALSController::OnUnPossess()
{
	Super::OnUnPossess();
	

	ACPlayerCameraManager* CustomPlayer = Cast<ACPlayerCameraManager>(PlayerCameraManager);

	
}

void AALSController::BeginPlay()
{
	Super::BeginPlay();

	ALSWidget = CreateWidget(this, WidgetTospawn);
	ALSWidget->AddToViewport();


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), CharacterClass, FoundActors);

	DebugFocusCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	
}

void AALSController::OpenOverlayMenu()
{
	if (IsOverlayOpen)
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1);
		IsOverlayOpen = false;
	}
	else
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.35f);
		IsOverlayOpen = true;
		 CreateWidget(this, );
	}
}

