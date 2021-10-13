

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_Animation.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Animation : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADVANCEDLOCOMOTIONSYSTEM_API IInterface_Animation
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	void Jumped();
};
