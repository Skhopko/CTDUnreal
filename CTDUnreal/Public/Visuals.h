#pragma once
#include "XmlParser.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Visuals.generated.h"

UCLASS()
class CTDUNREAL_API AVisuals : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AVisuals();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FXmlFile*file = new FXmlFile("XmlData.xml");
	float sRadius = 1.0f;
	FRotator rotation = FRotator();
};
