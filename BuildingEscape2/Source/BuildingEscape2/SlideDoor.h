// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "SlideDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlideDoorEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class BUILDINGESCAPE2_API USlideDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlideDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
		FSlideDoorEvent OnSlideOpen;

	UPROPERTY(BlueprintAssignable)
		FSlideDoorEvent OnSlideClose;
private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* SlideDoorPressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 30.f;

	AActor* Owner = nullptr; // Owning door
	float GetTotalMassOfActorsOnPlate();
		
	
};
