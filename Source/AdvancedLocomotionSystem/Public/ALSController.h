

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ALSController.generated.h"


class AALSBaseCharacterC;
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API AALSController : public APlayerController
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AALSBaseCharacterC> CharacterClass;

	UPROPERTY()
	TArray<AActor*> FoundActors;

	UPROPERTY()
	ACharacter* DebugFocusCharacter;

	UPROPERTY()
	UUserWidget* ALSWidget;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetTospawn;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void SetupInputComponent() override;

	virtual void OnUnPossess() override;

	protected:
	virtual void BeginPlay() override;

	
	
};
