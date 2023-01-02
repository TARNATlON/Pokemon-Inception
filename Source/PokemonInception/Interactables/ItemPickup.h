// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ItemPickup.generated.h"


UCLASS()
class POKEMONINCEPTION_API AItemPickup : public AInteractable
{
	GENERATED_BODY()
	
public:
	AItemPickup();

	UFUNCTION()
	virtual void Interact(APlayerController* Controller) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;
};