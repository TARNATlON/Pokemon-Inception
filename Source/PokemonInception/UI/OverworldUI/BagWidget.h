// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "ItemSlotWidget.h"
#include "../ButtonClick.h"
#include "BagWidget.generated.h"


UCLASS()
class POKEMONINCEPTION_API UBagWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UFUNCTION()
	void OnBackClicked();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* Back;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* WrapBox;

	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void AddToWrapBox(UItemSlotWidget* ItemWidget);

	void ClearWrapBox();

	FButtonClicked BackClicked;
};
