#include "Graph.h"

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = NULL;
    graph->VertexCount = 0;
    return graph;
}

void DestroyGraph(Graph* G)
{
    while (G->Vertices != NULL) {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;
    }

    free(G);
}

Vertex* CreateVertex(ElementType Data)
{
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));
    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyLst = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex(Vertex* V)
{
    while(V->AdjacencyLst != NULL) {
        Edge* Edge = V->AdjacencyLst->Next;
        DestroyEdge(V->AdjacencyLst);

        V->AdjacencyLst = Edge;
    }

    free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->From = From;
    E->Target = Target;
    E->Next = NULL;
    E->Weight = Weight;

    return E;
}

void DestroyEdge(Edge* E)
{
    free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
    Vertex* VertexList = G->Vertices;
    if (VertexList == NULL) {
        G->Vertices = V;
    } else {
        while (VertexList->Next != NULL) {
            VertexList = VertexList->Next;
        }

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
    if (V->AdjacencyLst == NULL) {
        V->AdjacencyLst = E;
    } else {
        Edge* AdjacencyList = V->AdjacencyLst;
        while (AdjacencyList->Next != NULL) {
            AdjacencyList = AdjacencyList->Next;
        }

        AdjacencyList->Next = E;
    }
}

void PrintGraph(Graph* G)
{
    Vertex* V = NULL;
    Edge* E = NULL;
    if ((V = G->Vertices) == NULL) {
        return;
    }

    while (V!= NULL) {
        printf("%c : ", V->Data);

        if ((E = V->AdjacencyLst) == NULL) {
            V = V->Next;
            printf("\n");
            continue;
        }

        while (E != NULL) {
            printf("%c[%d] ", E->Target->Data, E->Weight);
            E = E->Next;
        }

        putchar('\n');

        V = V->Next;
    }

    putchar('\n');
}
