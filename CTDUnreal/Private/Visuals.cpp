// Fill out your copyright notice in the Description page of Project Settings.

#include "CTDUnreal.h"
#include "Visuals.h"
#include "XmlParser.h"

// Sets default values
AVisuals::AVisuals(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when game starts or when spawned
void AVisuals::BeginPlay(){
	Super::BeginPlay();

	const FXmlFile file("XmlData.xml");
	int num = file.GetElementsByTagName("Node").length;

	//Creates a rootcomponent of a sphere that will react to physics
	USphereComponent*sphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = sphere;
	sphere->InitSphereRadius(sRadius);
	sphere->SetCollisionProfileName(TEXT("Pawn"));

	// Creates and positions a mesh component that allows the sphere to be seen
	UStaticMeshComponent*sphereVisuals = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualSphere"));
	sphereVisuals->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded()){
		sphereVisuals->SetStaticMesh(SphereVisualAsset.Object);
		sphereVisuals->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		sphereVisuals->SetWorldScale3D(FVector(0.8f));
	}
	
	int x = 1;
	while (x < num) {
		FVector position = PlaceNode();
		AVisuals*SpawnSphere = GetWorld()->SpawnActor<AVisuals>(AVisuals::StaticClass(), position, rotation, params);
		
		x++;
	}
}

// Called every frame
void AVisuals::Tick( float DeltaTime ){
	Super::Tick( DeltaTime );
}

//Spawns a link between two nodes
void Link(FVector start, FVector end, float radius) {
	FVector difference = start - end;

//	AActor cylinderLink = GetWorld->SpawnActor<AVisuals>(AVisuals::StaticClass(), radius, rotation, params);
//	cylinderLink.SetActorLocation.GetActorUpVector = difference;
//	cylinderLink.SetActorRelativeLocation(FVector(start+difference/2));

}

//Finds location of nodes
FVector PlaceNode(){
	FVector vec = FVector(0.0f, 0.0f, 0.0f);
	return  vec;
}
