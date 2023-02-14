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
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Destructible));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	FVector BoxHalfSize = FVector(50, 50, 100);
	FRotator PlayerFaceDirection = PlayerOwner->GetActorRotation();
	FVector BoxLocation = PlayerOwner->GetActorLocation();

	BoxLocation += PlayerFaceDirection.Vector() * BoxHalfSize.Y;

	FRotator BoxDirection = PlayerFaceDirection;
	BoxDirection.Yaw += 90;

	if (UKismetSystemLibrary::BoxTraceSingleForObjects(GetWorld(), BoxLocation, BoxLocation, BoxHalfSize, BoxDirection,
		ObjectTypes, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true,
		FLinearColor(1, 0, 0), FLinearColor(0, 1, 0), 1.f) == false) 
	{
		return;
	}
	
	AInteractable* CurrentInteractable = Cast<AInteractable>(HitResult.GetActor());
	if (CurrentInteractable != nullptr) {
		CurrentInteractable->Interact(this);
	}
}

bool APlayerCharacterController::bIsPartyDefeated()
{
	for (FPokemonStruct Pokemon : PokemonParty) {
		if (Pokemon.bIsFainted == false) {
			return false;
		}
	}
	return true;
}

void APlayerCharacterController::TogglePause()
{
	PauseDelegate.Broadcast();
}

void APlayerCharacterController::ObtainItem(FItemBaseStruct Item)
{
	Inventory.Add(Item);
}

void APlayerCharacterController::LoseItem(FItemBaseStruct Item)
{
	Inventory.RemoveSingle(Item);
}

void APlayerCharacterController::ObtainPokemon(FPokemonStruct Pokemon)
{
	if (bIsRegisteredInPokedex(Pokemon.SpeciesData.PokemonID) == false) {
		RegisterToPokedex(Pokemon.SpeciesData);
	}

	if (PokemonParty.Num() == 6) {
		PokemonStorage.Add(Pokemon);
	}
	else PokemonParty.Add(Pokemon);
}

void APlayerCharacterController::MovePokemonToParty(int PokemonID)
{
	return;
}

void APlayerCharacterController::MovePokemonToStorage(int PokemonID)
{
	return;
}

void APlayerCharacterController::ReleasePokemonFromParty(int PokemonID)
{
	return;
}

void APlayerCharacterController::ReleasePokemonFromStorage(int PokemonID)
{
	return;
}

void APlayerCharacterController::RegisterToPokedex(FPokemonBaseStruct Species)
{
	Pokedex.Add(Species);
}

bool APlayerCharacterController::bIsRegisteredInPokedex(FName ID)
{
	for (FPokemonBaseStruct PokemonData : Pokedex) {
		if (PokemonData.PokemonID == ID) {
			return true;
		}
	}
	return false;
}

void APlayerCharacterController::FullRestoreAllPokemon()
{
	for (int i = 0; i < PokemonParty.Num(); i++) {
		PokemonParty[i].FullRestore();
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Green, TEXT("RESTORED!"));
	}
	for (int i = 0; i < PokemonStorage.Num(); i++) {
		PokemonStorage[i].FullRestore();
	}
}

int APlayerCharacterController::GetMoney() const
{
	return money;
}

void APlayerCharacterController::RecieveMoney(int AddedMoney)
{
	money += AddedMoney;
}

void APlayerCharacterController::LoseMoney(int LostMoney)
{
	money -= LostMoney;
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacterController::Interact);
	InputComponent->BindAction("Menu", IE_Pressed, this, &APlayerCharacterController::TogglePause).bExecuteWhenPaused = true;
}
