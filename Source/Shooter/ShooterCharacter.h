#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "ShooterCharacter.generated.h"


//------------------------------------------------------------------------------------------------------------
UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forwards/backwards input
	void MoveForward(float Value);

	// Called for side to side input
	void MoveRight(float Value);

	
	/**
	 * Called via input to turn at a give rate.
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to look up/down at a given rate.
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired rate
	 */
	void LookUpAtRate(float Rate);

private:
	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	USpringArmComponent *CameraBoom;

	// Camera that follows the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	UCameraComponent *FollowCamera;

	// Base turn rate, in deg/sec/ Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	float BaseTurnRate;

	// Base look up/down rate, in deg/sec. other scalling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	float baseLookUpRate;
	
public:
	// Returns CameraBoom subobject
	FORCEINLINE USpringArmComponent *GetCameraBoom() const { return CameraBoom; };

	// Returns FollowCamera subobject
	FORCEINLINE UCameraComponent *GetFollowCamera() const { return FollowCamera; }
};
//------------------------------------------------------------------------------------------------------------
