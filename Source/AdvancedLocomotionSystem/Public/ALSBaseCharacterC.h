

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Data/Enums.h"
#include "Data/Structs.h"
#include "Engine/DataTable.h"
#include "Interfaces/Interface_Camera.h"
#include "Interfaces/Interface_Character.h"
#include "ALSBaseCharacterC.generated.h"



UCLASS()
class ADVANCEDLOCOMOTIONSYSTEM_API AALSBaseCharacterC : public ACharacter, public IInterface_Character, public IInterface_Camera
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
	FVector CPPAcceleration = FVector(0.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	bool CPPIsMoving = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	bool CPPHasMovementInput = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	FRotator LastVelocityRotation = FRotator(0.0f);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	FRotator LastMovementInputRotation = FRotator(0.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float CPPSpeed = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float CPPMovementInputAmount = 0.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Essential Information")
	float CPPAimYawRate = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	float ThirdPersonFOV = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	float FirstPersonFOV = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera System")
	bool CharacterRightShoulder = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSMovementAction EMovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSRotationMode EDesiredRotationMode = EALSRotationMode::LookingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSGait EDesiredGait = EALSGait::Sprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input System")
	EALSStance EDesiredStance = EALSStance::Standing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState MovementState = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState EPrevMovementState = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSMovementState EMovementState = EALSMovementState::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSRotationMode ERotationMode = EALSRotationMode::LookingDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSGait EGait = EALSGait::Walking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSStance EStance = EALSStance::Standing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State Values")
	EALSViewMode EViewMode = EALSViewMode::ThirdPerson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Values")
	EALSOverlayState EOverlayState = EALSOverlayState::Default;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement System")
	UDataTable* DataTableRow;

	FDataTableRowHandle* Rowhandle;
	
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


	//Interfaces declrations.

	virtual void Get3PTraceParams(FVector& TraceOrigin, float& TraceRadius, ETraceTypeQuery& TraceChannel) override;

	virtual void GetCameraParameters(float& TP_FOV, float& FP_FOV, bool& RightShoulder) override;

	virtual void GetCameraTargets(FVector& Target) override;

	virtual void GetFPCameraTarget(FTransform& Transform) override;

	virtual void GetCharacterCurrentStats(EMovementMode& PawnMovementMode, EALSMovementState& IMovementState, EALSMovementState& PrevMovementState,
	                                      EALSMovementAction& MovementAction, EALSRotationMode& RotationMode, EALSGait& ActualGait, EALSStance& ActualStance,
	                                      EALSViewMode& ViewMode, EALSOverlayState& OverlayState) override;

	virtual void GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput, bool& IsMoving
	                                     , bool& HasMovementInput, float& Speed, float& MovementInputAmount, FRotator& AimingRotation, float& AimYawRate) override;
	
	UFUNCTION()
	void OnBeginPlay();

	void SetFriction();

	UFUNCTION()
	void SetMovementModel();

	UFUNCTION()
	void OnGaitChanged(EALSGait NewactualGait);

	void OnRotationChanged(EALSRotationMode NewRotaionMode);

	void OnViewModeChanged(EALSViewMode NewViewMode);

	void OnOverlayStateChanged(EALSOverlayState NewOverlayState);

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;
	
	void OnCharactermovementModeChanged(EMovementMode NewMovementMode);

	virtual void Landed(const FHitResult& Hit) override;

	virtual void OnJumped_Implementation() override;

	void BreakFallEvent();

	void RollEvent();

	virtual UAnimMontage* GetRollAnimation();
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
