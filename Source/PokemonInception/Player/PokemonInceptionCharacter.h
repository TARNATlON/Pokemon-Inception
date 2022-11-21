// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Pokemon/PokemonBase.h"
#include "PokemonInceptionCharacter.generated.h"

DECLARE_DELEGATE(FInteractSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPauseSignature);

UCLASS(config=Game)
class APokemonInceptionCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	class UAIPerceptionStimuliSourceComponent* stimulus;

	void SetupStimulus();

public:
	APokemonInceptionCharacter();

	void ObtainPokemon(APokemonBase* AddedPokemon);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FPauseSignature PauseDelegate;
	FInteractSignature InteractDelegate;

protected:
	UPROPERTY(VisibleAnywhere)
	TArray<APokemonBase*> PokemonTeam;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void TogglePause();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void Interact();
};
