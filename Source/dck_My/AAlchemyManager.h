#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlchemyDataTypes.h" // Подключаем наши структуры ДО generated
class ULevelSequence; // Forward declaration
class AStaticMeshActor; // ДОБАВЛЕНО: Forward declaration для мешей
#include "AAlchemyManager.generated.h" // СТРОГО ПОСЛЕДНИЙ ИНКЛУД!

UCLASS()
class DCK_MY_API AAlchemyManager : public AActor
{
	GENERATED_BODY()

public:
	AAlchemyManager();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Alchemy Logic")
	void UpdatePlaceholderVisuals(FName ElementID, AStaticMeshActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Alchemy Data")
	UDataTable* RecipeDataTable;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Alchemy Data")
	UDataTable* ElementDataTable;

	UFUNCTION(BlueprintCallable, Category = "Alchemy Logic")
	bool TryCraftElements(FName ItemA, FName ItemB, FName& OutResult, ULevelSequence*& OutSequence);

private:
	TArray<FName> UnlockedElements;
};