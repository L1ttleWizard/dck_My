#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AlchemyDataTypes.generated.h"

class UTexture2D;
class UStaticMesh;
class ULevelSequence;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy Element")
	UStaticMesh* WorldMesh;
};

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