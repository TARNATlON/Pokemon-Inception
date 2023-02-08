// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "../ButtonClick.h"
#include "../../Items/ItemBaseStruct.h"
#include "ItemSlotWidget.generated.h"


UCLASS()
class POKEMONINCEPTION_API UItemSlotWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnItemClicked();

	int ItemID;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UButton* ItemButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UImage* ItemImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ItemCount;

public:
	virtual void NativeOnInitialized() override;

	void SetItemID(int InID);

	UFUNCTION()
	void SetItemName(FText Name);

	UFUNCTION()
	void SetItemImage(UTexture2D* Image);

	UFUNCTION()
	void SetItemCount(int Count);

	FElementIDSignature ItemClicked;
};
