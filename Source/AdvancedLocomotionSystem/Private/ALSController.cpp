


#include "ALSController.h"
#include "Blueprint/UserWidget.h"
#include "ALSBaseCharacterC.h"
#include "ToolBuilderUtil.h"
#include "Kismet/GameplayStatics.h"

void AALSController::OnPossess(APawn* MovieSceneBlends)
{
	Super::OnPossess(MovieSceneBlends);

	
}

void AALSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}

void AALSController::BeginPlay()
{
	Super::BeginPlay();

	ALSWidget = CreateWidget(this, WidgetTospawn);
	ALSWidget->AddToViewport();


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), CharacterClass, FoundActors);

	DebugFocusCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	
}