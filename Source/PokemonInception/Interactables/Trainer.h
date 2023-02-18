// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "../Pokemon/PokemonStruct.h"
#include "Trainer.generated.h"


UCLASS()
class POKEMONINCEPTION_API ATrainer : public AInteractable
{
	GENERATED_BODY()
	
public:
	ATrainer();

	UFUNCTION()
	virtual void Interact(APlayerController* Controller) override;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* SkeletalMesh = nullptr;

	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* Capsule = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<FName> PokemonIDs;

	UPROPERTY(EditAnywhere)
	TArray<int> PokemonLevels;

};
