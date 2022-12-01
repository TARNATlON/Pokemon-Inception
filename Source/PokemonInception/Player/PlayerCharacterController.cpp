// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "../PokemonInception.h"
#include "../Interactables/Interactable.h"
#include "../GameModes/OverworldGameMode.h"
#include "PokemonInceptionCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../UI/OverworldUI/OverworldHUD.h"

void APlayerCharacterController::Interact()
{
	APokemonInceptionCharacter* PlayerOwner = Cast<APokemonInceptionCharacter>(GetPawn());

	FHitResult HitResult;

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(PlayerOwner);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	FVector BoxHalfSize = FVector(50, 50, 100);
	FRotator PlayerFaceDirection = PlayerOwner->GetActorRotation();
	FVector BoxLocation = PlayerOwner->GetActorLocation();

	BoxLocation += PlayerFaceDirection.Vector() * BoxHalfSize.Y;
	

	FRotator BoxDirection = PlayerFaceDirection;
	BoxDirection.Yaw += 90;


	if (UKismetSystemLibrary::BoxTraceSingleForObjects(GetWorld(), BoxLocation, BoxLocation, BoxHalfSize, BoxDirection,
		ObjectTypes, false, ActorsToIgnore, EDrawDebugTrace::None, HitResult, true,
		FLinearColor(1, 0, 0), FLinearColor(0, 1, 0), 1.f) == false) 
	{
		return;
	}
	
	AInteractable* CurrentInteractable = Cast<AInteractable>(HitResult.GetActor());
	if (CurrentInteractable != nullptr) {
		CurrentInteractable->Interact(this);
	}
}

void APlayerCharacterController::ObtainItem(FName ItemID)
{
	AOverworldGameMode* GameMode = Cast<AOverworldGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDT();

	FItemBaseStruct* AddedItem = ItemTable->FindRow<FItemBaseStruct>("ItemID", "");


	if (AddedItem) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Recieving item!"));
		Inventory.Add(*AddedItem);
	}
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacterController::Interact);
}
