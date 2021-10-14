


#include "ALSBaseCharacterC.h"

#include "Chaos/BoundingVolume.h"
#include "Interfaces/Interface_Animation.h"
#include "Data/MacroLibrary.h"
#include "Data/Enums.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AALSBaseCharacterC::AALSBaseCharacterC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//init Variables
	
	GroundedTraceSettings.MaxLedgeHeight = 250.f;
	GroundedTraceSettings.ReachDistance = 75.f;
	GroundedTraceSettings.DownwardTraceRadius = 30.f;
	GroundedTraceSettings.ForwardTraceRadius = 30.f;
	GroundedTraceSettings.MinLedgeHeight = 50.f;


	AutomaticTraceSettings.ReachDistance = 50.f;
	AutomaticTraceSettings.DownwardTraceRadius = 30.f;
	AutomaticTraceSettings.ForwardTraceRadius = 30.0f;
	AutomaticTraceSettings.MaxLedgeHeight = 80.f;
	AutomaticTraceSettings.MinLedgeHeight = 40.0f;

	FallingTraceSettings.MaxLedgeHeight = 150.f;
	FallingTraceSettings.MinLedgeHeight = 50.f;
	FallingTraceSettings.ReachDistance = 70.f;
	FallingTraceSettings.ForwardTraceRadius = 30.f;
	FallingTraceSettings.DownwardTraceRadius = 30.f;
	
}

// Called when the game starts or when spawned
void AALSBaseCharacterC::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AALSBaseCharacterC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AALSBaseCharacterC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AALSBaseCharacterC::Get3PTraceParams(FVector& TraceOrigin, float& TraceRadius, ETraceTypeQuery& TraceChannel)
{
	TraceOrigin = GetActorLocation();
	TraceRadius = 10.f;
	//TraceChannel = ECC_Visibility
}

void AALSBaseCharacterC::GetCameraParameters(float& TP_FOV, float& FP_FOV, bool& RightShoulder)
{
	TP_FOV = ThirdPersonFOV;
	FP_FOV = FirstPersonFOV;
	RightShoulder = CharacterRightShoulder;
}

void AALSBaseCharacterC::GetCameraTargets(FVector& Target)
{
	Target = GetMesh()->GetSocketLocation(TEXT("FP_Camera"));
}

void AALSBaseCharacterC::GetFPCameraTarget(FTransform& Transform)
{
	
}

void AALSBaseCharacterC::GetCharacterCurrentStats(EMovementMode& PawnMovementMode, EALSMovementState& IMovementState,
                                                  EALSMovementState& PrevMovementState, EALSMovementAction& MovementAction, EALSRotationMode& RotationMode,
                                                  EALSGait& ActualGait, EALSStance& ActualStance, EALSViewMode& ViewMode, EALSOverlayState& OverlayState)
{
	PawnMovementMode = GetCharacterMovement()->MovementMode;
	MovementState = EMovementState;
	PrevMovementState = EPrevMovementState;
	MovementAction = EMovementAction;
	RotationMode = ERotationMode;
	ActualGait = EGait;
	ActualStance = EStance;
	ViewMode = EViewMode;
	OverlayState = EOverlayState;
}

void AALSBaseCharacterC::GetEssentialInformation(FVector& Velocity, FVector& Acceleration, FVector& MovementInput,
	bool& IsMoving, bool& HasMovementInput, float& Speed, float& MovementInputAmount, FRotator& AimingRotation,
	float& AimYawRate)
{
	Velocity = GetVelocity();
	Acceleration = CPPAcceleration;
	MovementInput = GetCharacterMovement()->GetCurrentAcceleration();
	IsMoving = CPPIsMoving;
	HasMovementInput = CPPHasMovementInput;
	Speed = CPPSpeed;
	MovementInputAmount = CPPMovementInputAmount;
	AimingRotation = GetControlRotation();
	AimYawRate = CPPAimYawRate;
}

void AALSBaseCharacterC::OnBeginPlay()
{

	//Make sure the mesh and animbp update after the CharacterBP to ensure it gets the most recent values.
	AddTickPrerequisiteActor(this);


	//Set Reference to the Main Anim Instance.
	USkeletalMeshComponent* MeshComponent = GetMesh();
	UAnimInstance* TempAnimInstance = MeshComponent->GetAnimInstance();

	if (TempAnimInstance)
	{
		MainAnimInstance = TempAnimInstance;
	}

	//Set the Movement Model
	SetMovementModel();



	//Update states to use the initial desired values.
	
	OnGaitChanged(EDesiredGait);

	OnRotationChanged(EDesiredRotationMode);

	OnViewModeChanged(EViewMode);

	OnOverlayStateChanged(EOverlayState);


	switch (EDesiredStance)
	{

		case EALSStance::Standing:

			GetCharacterMovement()->UnCrouch();
			break;

		case EALSStance::Crouching:

			GetCharacterMovement()->Crouch();
			break;
	}



	//Set default rotation values.

	TargetRotation = GetActorRotation();
	LastVelocityRotation = GetActorRotation();
	LastMovementInputRotation = GetActorRotation();
	
}

void AALSBaseCharacterC::SetFriction()
{
	GetCharacterMovement()->BrakingFriction = 0.0f;
}

void AALSBaseCharacterC::SetMovementModel()
{
	 // MoveMentSettings = DataTableRow->FindRow<FMovementSettings>(TEXT("Normal"));
}

void AALSBaseCharacterC::OnGaitChanged(EALSGait NewactualGait)
{
	
}

void AALSBaseCharacterC::OnRotationChanged(EALSRotationMode NewRotaionMode)
{
	
}

void AALSBaseCharacterC::OnViewModeChanged(EALSViewMode NewViewMode)
{
}

void AALSBaseCharacterC::OnOverlayStateChanged(EALSOverlayState NewOverlayState)
{
	
}

void AALSBaseCharacterC::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);

	switch (PrevMovementMode)
	{
		case EMovementMode::MOVE_Walking:
			SetMovementStats(EALSMovementState::Grounded);
			break;
		
		case EMovementMode::MOVE_NavWalking:
			SetMovementStats(EALSMovementState::Grounded);
			break;

		case EMovementMode::MOVE_Falling:
			SetMovementStats(EALSMovementState::InAir);
			break;


		default:
			;
	}
	
}

void AALSBaseCharacterC::OnCharactermovementModeChanged(EMovementMode NewMovementMode)
{
	
}

void AALSBaseCharacterC::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	
	if (BreakFall)
	{
		
	}else
	{
		FLatentActionInfo LatentActionInfo;
		LatentActionInfo.ExecutionFunction = "SetFriction";
		
		if (CPPHasMovementInput)
		{
			GetCharacterMovement()->BrakingFriction = 0.5f;
			UKismetSystemLibrary::RetriggerableDelay(GetWorld(), 0.5, LatentActionInfo);

		}
		else
		{
			GetCharacterMovement()->BrakingFriction = 3.0f;

			UKismetSystemLibrary::RetriggerableDelay(GetWorld(), 0.5, LatentActionInfo);
			
		}	
	}
}

void AALSBaseCharacterC::OnJumped_Implementation()
{
	Super::OnJumped_Implementation();

	if (CPPSpeed > 100.f)
	{
		InAirRotation = LastVelocityRotation;
		if (MainAnimInstance)
		{
			IInterface_Animation* Interface_Animation = Cast<IInterface_Animation>(MainAnimInstance);
			if (Interface_Animation)
			{
				Interface_Animation->Jumped();
			}
		}
	}
	else
	{
		InAirRotation = GetActorRotation();

		if (MainAnimInstance)
		{
			IInterface_Animation* Interface_Animation = Cast<IInterface_Animation>(MainAnimInstance);
			if (Interface_Animation)
			{
				Interface_Animation->Jumped();
			}
		}
	}
}

void AALSBaseCharacterC::BreakFallEvent()
{
	if (MainAnimInstance)
	{
		MainAnimInstance->Montage_Play(GetRollAnimation(), 1.35f);
	}
}

void AALSBaseCharacterC::RollEvent()
{
	if (MainAnimInstance)
	{
		MainAnimInstance->Montage_Play(GetRollAnimation(), 1.15f);
	}
}


UAnimMontage* AALSBaseCharacterC::GetRollAnimation()
{
	
}






