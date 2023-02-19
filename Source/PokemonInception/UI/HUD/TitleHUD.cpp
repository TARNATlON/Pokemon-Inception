// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleHUD.h"
#include "../../GameModes/TitleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"


void ATitleHUD::BeginPlay()
{
	Super::BeginPlay();
	ATitleGameMode* GameMode = Cast<ATitleGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	PlayerController->SetInputMode(FInputModeUIOnly());
	PlayerController->bShowMouseCursor = true;

	TitleWidget = CreateWidget<UTitleWidget>(UGameplayStatics::GetGameInstance(GetWorld()), TitleWidgetClass);
	ControlsWidget = CreateWidget<UControlsWidget>(UGameplayStatics::GetGameInstance(GetWorld()), ControlsWidgetClass);

	TitleWidget->PlayClicked.AddDynamic(GameMode, &ATitleGameMode::StartGame);
	TitleWidget->ControllsClicked.AddDynamic(this, &ATitleHUD::ShowControlls);
	TitleWidget->QuitClicked.AddDynamic(GameMode, &ATitleGameMode::QuitGame);

	ControlsWidget->BackClicked.AddDynamic(this, &ATitleHUD::ShowTitle);

	ShowTitle();
}

void ATitleHUD::ShowTitle()
{
	ControlsWidget->RemoveFromViewport();

	if (PlayerOwner && TitleWidget) {
		TitleWidget->AddToViewport();
	}
}

void ATitleHUD::ShowControlls()
{
	TitleWidget->RemoveFromViewport();

	if (PlayerOwner && ControlsWidget) {
		ControlsWidget->AddToViewport();
	}
}
