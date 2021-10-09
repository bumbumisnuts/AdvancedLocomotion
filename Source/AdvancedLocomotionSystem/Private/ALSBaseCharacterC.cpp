


#include "ALSBaseCharacterC.h"

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
	AALSBaseCharacterC::SetMovementModel();
	
	
}

void AALSBaseCharacterC::SetMovementModel()
{
	
}

void AALSBaseCharacterC::OnGaitChanged(EALSGait NewactualGait)
{
	
}