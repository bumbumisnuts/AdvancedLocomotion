

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enums.h"
#include "Structs.h"
#include "Engine/DataTable.h"
#include "ALSBaseCharacterC.generated.h"

UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API AALSBaseCharacterC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AALSBaseCharacterC();
	
	 // Called every frame
        virtual void Tick(float DeltaTime) override;
    
    // Called to bind functionality to input
    	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    	
    	
    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "References")
	class UAnimInstance* MainAnimInstance = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSRotationMode DesiredRotationMode = EALSRotationMode::LookingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSGait DesiredGait = EALSGait::Sprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSStance DesiredStance = EALSStance::Standing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input System")
	 float LookLeftRightRate = 1.25;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input System")
	float LookUpDownRate = 1.25;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input System")
	int TimesPressedStance = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input System")
	bool BreakFall = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input System")
	bool SprintHeld = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	FVector Acceleration = FVector(0.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	bool IsMoving = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	bool HasMovementInput = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	FRotator LastVelocityRotation = FRotator(0.0f);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	FRotator LastMovementInputRotation = FRotator(0.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float Speed = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float MovementInputAmount = 0.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float AimYawRate = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	float ThirdPersonFOV = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	float FirstPersonFOV = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	bool RightShoulder = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState MovementState = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState PrevMovementState = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState MovementAction = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSRotationMode RotationMode = EALSRotationMode::LookingDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSGait Gait = EALSGait::Walking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSStance Stance = EALSStance::Standing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSViewMode ViewMode = EALSViewMode::ThirdPerson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Values")
	EALSOverlayState OverlayState = EALSOverlayState::Default;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement System")
	FDataTableRowHandle MovementModel;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement System")
	FMovementSettings MoveMentSettings;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Rotation System")
	FRotator TargetRotation = FRotator(0.0f);
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Rotation System")
	FRotator InAirRotation = FRotator(0.0f);

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Rotation System")
	float YawOffset = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantle System")
	FMantleParams MantleParams;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantle System")
	FALSComponentTransform ALSComponentAndTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantle System")
	FTransform MantleTarget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantle System")
	FTransform MantleActualStartOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mantle System")
	FTransform MantleAnimatedStartOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mantle System")
	FMantle_TraceSettings GroundedTraceSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mantle System")
	FMantle_TraceSettings AutomaticTraceSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mantle System")
	FMantle_TraceSettings FallingTraceSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ragdoll System")
	bool RagdollOnGround = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ragdoll System")
	bool RagdollFaceUp = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ragdoll System")
	FVector LastRagdollVelocity = FVector(0.f);


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cached Variables")
	FVector PreviousVelocity = FVector(0.f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cached Variables")
	float PreviousAimYaw = 0.f;



	UFUNCTION()
	void OnBeginPlay();

	UFUNCTION()
	void SetMovementModel();

	UFUNCTION()
	void OnGaitChanged(EALSGait NewactualGait);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

};
