// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "../ButtonClick.h"
#include "BattleStartWidget.generated.h"


UCLASS()
class POKEMONINCEPTION_API UBattleStartWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UFUNCTION()
	void OnFightClicked();

	UFUNCTION()
	void OnPokemonClicked();

	UFUNCTION()
	void OnBagClicked();

	UFUNCTION()
	void OnRunClicked();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Fight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Pokemon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Bag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Run;

public:
	virtual void NativeOnInitialized() override;

	FButtonClicked FightClicked;
	FButtonClicked PokemonClicked;
	FButtonClicked BagClicked;
	FButtonClicked RunClicked;
	
};