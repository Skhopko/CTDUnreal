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

	int numNodes = AVisuals->file.GetElementsByTagName("Node").count;

	//Creates a invisible rootcomponent of a sphere
	USphereComponent*sphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = sphere;
	sphere->InitSphereRadius(sRadius);

	// Creates and positions a mesh component that allows the rootcomponent to be seen. It also spawns all the additional nodes relative to the rootcomponent.
	UStaticMeshComponent*sphereVisuals = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Node"));
	sphereVisuals->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded()){
		sphereVisuals->SetStaticMesh(SphereVisualAsset.Object);
		sphereVisuals->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		sphereVisuals->SetWorldScale3D(FVector(0.8f));
		Link(FVector(0.0f),FVector(0.0f),0,*RootComponent);
		int x = 1;
		while (x <= numNodes){
			FVector position = LocateNode(x);
			UStaticMeshComponent*sphereNode = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Node"));
			sphereNode->AttachTo(RootComponent);
			sphereNode->SetStaticMesh(SphereVisualAsset.Object);
			sphereNode->SetRelativeLocation(position);
			x++;
		}
	}
}

//Spawns a link between two nodes
void Link(FVector start, FVector end, float radius, USceneComponent& root){
	FVector difference = start - end;
	UStaticMeshComponent*cylinderLink = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Link"));
	cylinderLink->AttachTo(root);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (CylinderVisualAsset.Succeeded()){ 
			cylinderLink->SetStaticMesh(CylinderVisualAsset.Object);
			cylinderLink->SetRelativeLocation(start + difference / 2);
	}
}
		
//Finds location of nodes
FVector LocateNode(int x){
	FXmlNode*TestingNode = file.GetElementByID(1);
	FXmlNode*thisElement = file.GetElementByID(x.ToString);
	int localNum = file.ChildNodesByName("Links").count;
	int x= 0;
	while (x < localNum) {
		float angleTowards = 180 * (x + 1) / (localNum) ^ 2;
		//PlaceNode(x+1);
	}
	//Not sure that I want to return locations or have the locations change as nodes are placed thus making finding
	//the location of the nodes unessesary. 
	FVector vec = FVector(0.0f, 0.0f, 0.0f);
	return  vec;
}

		// Called every frame
void AVisuals::Tick( float DeltaTime ){
	Super::Tick( DeltaTime );
}