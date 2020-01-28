#include "MST.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
	int i = 0;
	PQNode StartNode = { 0, StartVertex };
	PriorityQueue* PQ = PQ_Create(10);
	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;
	int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	CurrentVertex = G->Vertices;
	while (CurrentVertex != NULL) {
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(&MST, NewVertex);
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		MSTVertices[i] = NewVertex;
		Weights[i] = MAX_WEIGHT;
		CurrentVertex = CurrentVertex->Next;
		i++;
	}
	
}
void Kruskal(Graph* G, Graph* MST)
{

}

