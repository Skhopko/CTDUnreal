// Fill out your copyright notice in the Description page of Project Settings.

#include "CTDUnreal.h"
#include "Visuals.h"


// Sets default values
AVisuals::AVisuals(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when game starts or when spawned
void AVisuals::BeginPlay(){
	Super::BeginPlay();

	FVector positionOne = FVector(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters params;
	FRotator rotation = FRotator();
	AVisuals*SphereOne = GetWorld()->SpawnActor<AVisuals>(AVisuals::StaticClass(), positionOne, rotation, params);

	FVector position = PlaceNode();
	AVisuals*SpawnSphere = GetWorld()->SpawnActor<AVisuals>(AVisuals::StaticClass(), position, rotation, params);
	Link(positionOne, position, .16f);
}

// Called every frame
void AVisuals::Tick( float DeltaTime ){
	Super::Tick( DeltaTime );
}

//Spawns a link between two nodes
void Link(FVector start, FVector end, float radius) {
	FVector difference = start - end;

}

//Finds location of nodes
FVector PlaceNode(){
	FVector vec = FVector(0.0f, 0.0f, 0.0f);
	return  vec;
}
