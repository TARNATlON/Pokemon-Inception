// Fill out your copyright notice in the Description page of Project Settings.


#include "TextBoxWidget.h"

void UTextBoxWidget::ReturnMessage(FString MessageToDisplay)
{
	Message->SetText(FText::FromString(MessageToDisplay));
}
