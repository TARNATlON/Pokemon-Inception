// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "../ButtonClick.h"
#include "PokemonStorageWidget.generated.h"


UCLASS()
class POKEMONINCEPTION_API UPokemonStorageWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UFUNCTION()
	void OnBackClicked();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Back;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* PartyWrapBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* StorageWrapBox;

	virtual void NativeConstruct() override;

public:
	/*UFUNCTION()
	void AddToWrapBox(UPokemonSlotWidget* PokemonWidget);

	UFUNCTION()
	void AddToInfoWrapBox(UPokemonSummaryWidget* PokemonSummaryWidget);

	void ClearWrapBox();

	void ClearSummaryBox();*/

	FButtonClicked BackClicked;
};