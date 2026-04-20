#include "AAlchemyManager.h"
#include "LevelSequence.h" 
#include "Engine/StaticMeshActor.h" // ЭТОТ ИНКЛУД РЕШАЕТ ВАШУ ОШИБКУ
#include "Components/StaticMeshComponent.h" // И ЭТОТ ТОЖЕ

AAlchemyManager::AAlchemyManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAlchemyManager::BeginPlay()
{
	Super::BeginPlay();
}



void AAlchemyManager::UpdatePlaceholderVisuals(FName ElementID, AStaticMeshActor* TargetActor)
{
	if (!TargetActor || !RecipeDataTable) return;

	// Ищем данные об элементе в нашей таблице элементов (нужна ссылка на DT_Elements)
	// Для простоты примера предположим, что у вас есть ссылка на нее в менеджере
	// Если нет - добавьте UDataTable* ElementDataTable в хедер.

	static const FString ContextString(TEXT("Visual Update Context"));
	FAlchemyElement* ElementData = ElementDataTable->FindRow<FAlchemyElement>(ElementID, ContextString);

	if (ElementData && ElementData->WorldMesh)
	{
		TargetActor->GetStaticMeshComponent()->SetStaticMesh(ElementData->WorldMesh);
		UE_LOG(LogTemp, Warning, TEXT("Visual updated for: %s"), *ElementID.ToString());
	}
}

bool AAlchemyManager::TryCraftElements(FName ItemA, FName ItemB, FName& OutResult, ULevelSequence*& OutSequence)
{
	OutResult = NAME_None;
	OutSequence = nullptr;

	if (!RecipeDataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("AlchemyManager: RecipeDataTable is missing!"));
		return false;
	}

	static const FString ContextString(TEXT("Alchemy Crafting Context"));
	TArray<FAlchemyRecipe*> Recipes;
	RecipeDataTable->GetAllRows<FAlchemyRecipe>(ContextString, Recipes);

	for (FAlchemyRecipe* Recipe : Recipes)
	{
		if (!Recipe) continue;

		bool bMatchStandard = (Recipe->IngredientA == ItemA && Recipe->IngredientB == ItemB);
		bool bMatchReversed = (Recipe->IngredientA == ItemB && Recipe->IngredientB == ItemA);

		if (bMatchStandard || bMatchReversed)
		{
			OutResult = Recipe->ResultElement;
			OutSequence = Recipe->CraftingSequence;

			UnlockedElements.AddUnique(OutResult);

			UE_LOG(LogTemp, Warning, TEXT("Crafting Success: Created %s"), *OutResult.ToString());
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Crafting Failed: No recipe found for %s and %s"), *ItemA.ToString(), *ItemB.ToString());
	return false;
}