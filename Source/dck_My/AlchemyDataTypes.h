#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
class ULevelSequence; // Forward declaration вместо прямого инклуда
#include "AlchemyDataTypes.generated.h" // СТРОГО ПОСЛЕДНИЙ ИНКЛУД!

// --- Структура Элемента (Ингредиента) ---
USTRUCT(BlueprintType)
struct FAlchemyElement : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	FText ElementName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	FName Category;

	// Ссылка на 3D модель предмета
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	UStaticMesh* WorldMesh;
};

// --- Структура Рецепта ---
USTRUCT(BlueprintType)
struct FAlchemyRecipe : public FTableRowBase
{
	GENERATED_BODY()	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Recipe")
	FName IngredientA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Recipe")
	FName IngredientB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Recipe")
	FName ResultElement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Recipe")
	ULevelSequence* CraftingSequence;
};