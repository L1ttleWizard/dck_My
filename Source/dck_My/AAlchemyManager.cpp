#include "AAlchemyManager.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "LevelSequence.h"

AAlchemyManager::AAlchemyManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAlchemyManager::BeginPlay()
{
	Super::BeginPlay();

	UnlockedElements.AddUnique(FName("Fire"));
	UnlockedElements.AddUnique(FName("Water"));
	UnlockedElements.AddUnique(FName("Earth"));
}

void AAlchemyManager::UpdatePlaceholderVisuals(FName ElementID, AStaticMeshActor* TargetActor)
{
	if (!TargetActor || !ElementDataTable || ElementID.IsNone()) return;

	static const FString ContextString(TEXT("VisualUpdateContext"));
	FAlchemyElement* ElementData = ElementDataTable->FindRow<FAlchemyElement>(ElementID, ContextString);

	if (ElementData && ElementData->WorldMesh)
	{
		UStaticMeshComponent* MeshComp = TargetActor->GetStaticMeshComponent();
		if (MeshComp)
		{
			MeshComp->SetStaticMesh(ElementData->WorldMesh);
			TargetActor->SetActorHiddenInGame(false);
		}
	}
}

bool AAlchemyManager::TryCraftElements(FName ItemA, FName ItemB, FAlchemyRecipe& OutRecipe)
{
	if (!RecipeDataTable) return false;

	static const FString ContextString(TEXT("CraftingContext"));
	TArray<FAlchemyRecipe*> Recipes;
	RecipeDataTable->GetAllRows<FAlchemyRecipe>(ContextString, Recipes);

	for (FAlchemyRecipe* Recipe : Recipes)
	{
		if ((Recipe->IngredientA == ItemA && Recipe->IngredientB == ItemB) ||
			(Recipe->IngredientA == ItemB && Recipe->IngredientB == ItemA))
		{
			OutRecipe = *Recipe;
			UnlockedElements.AddUnique(Recipe->ResultElement);
			return true;
		}
	}
	return false;
}