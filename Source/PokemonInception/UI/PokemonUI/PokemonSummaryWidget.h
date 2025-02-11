// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/WrapBox.h"
#include "../MoveUI/MoveButtonWidget.h"
#include "../../Pokemon/TypeStruct.h"
#include "../../Pokemon/StatusMoveStruct.h"
#include "PokemonSummaryWidget.generated.h"


UCLASS()
class POKEMONINCEPTION_API UPokemonSummaryWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UImage* PokemonImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* EXPRequired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonDefence;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* PokemonSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UWrapBox* MoveWrapBox;

public:
	void SetImage(UTexture2D* Image);
	void SetGeneralInfo(FText Name, FName Id, FString Type, int Level, int RequiredEXP);
	void SetStats(FString HP, int Attack, int Defence, int Speed, TArray<EEffect> Effects);
	void AddMove(UMoveButtonWidget* Move);
	
	void ClearMoves();
};
