#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DirectArrayGraphType
{
    int nodeCount;
    int** ppEdge;
} DirectArrayGraph;

DirectArrayGraph* createDirectArrayGraph(int nodeCount) 
{
    int i = 0;
    DirectArrayGraph* pReturn = NULL;
    pReturn = (DirectArrayGraph *)malloc(sizeof(DirectArrayGraph));
    if (pReturn == NULL) {
        return NULL;
    }

    pReturn->nodeCount = nodeCount;
    pReturn->ppEdge = (int**)malloc(sizeof(int) * nodeCount);
    if(pReturn->ppEdge == NULL) {
        free(pReturn);
        return NULL;        
    }
    for(i = 0; i < nodeCount; i++) {
        pReturn->ppEdge[i] = (int*)malloc(sizeof(int)*nodeCount);
        if(pReturn->ppEdge[i] == NULL) {
            return NULL;
        }

        memset(pReturn->ppEdge[i], 0, sizeof(int) * nodeCount);
    }

    return pReturn;
}

int checkVertexValid(DirectArrayGraph* pGraph, int node) 
{
    if(pGraph != NULL && node < pGraph->nodeCount && node >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int addEdgeDAG(DirectArrayGraph* pGraph, int fromNode, int toNode)
{
    int ret = 0;
    if(pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        pGraph->ppEdge[fromNode][toNode] = 1;
    } else {
        ret = -1;
    }

    return ret;
}

int removeEdge(DirectArrayGraph* pGraph, int fromNode, int toNode)
{
    int ret = 0;
    if(pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        pGraph->ppEdge[fromNode][toNode] = 0;
    } else {
        ret = -1;
    }

    return ret;
}

int getEdgeDAG(DirectArrayGraph* pGraph, int fromNode, int toNode)
{
    int ret = 0;
    if(pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode)) {
        ret = pGraph->ppEdge[fromNode][toNode];
    }

    return ret;
}

void displayGraphDAG(DirectArrayGraph* pGraph)
{
    int i = 0,j = 0;
    int count = 0;
    if(pGraph != NULL) {
        count = pGraph->nodeCount;
        for(int i =0; i < count; i++) {
            for(int j = 0; j < count; j++) {
                printf("%d ",getEdgeDAG(pGraph, i, j));
            }

            putchar('\n');
        }
    }
}

void deleteGraphDAG(DirectArrayGraph* pGraph)
{
    int i = 0;
    if (pGraph != NULL) {
        for(int i = 0 ; i < pGraph->nodeCount; i++) {
            free(pGraph->ppEdge[i]);
        }

        free(pGraph->ppEdge);
        free(pGraph);
    }
}

int main(void)
{
    int nodeCOunt = 6;
    DirectArrayGraph* pG2 = createDirectArrayGraph(nodeCOunt);
    if(pG2 != NULL) {
        addEdgeDAG(pG2, 0, 1);
        addEdgeDAG(pG2, 1, 2);
        addEdgeDAG(pG2, 2, 0);
        addEdgeDAG(pG2, 2, 3);
        addEdgeDAG(pG2, 3, 2);
        addEdgeDAG(pG2, 3, 4);
        addEdgeDAG(pG2, 4, 5);
        addEdgeDAG(pG2, 5, 3);

        printf("G2 : 방향 그래프\n");
        
        displayGraphDAG(pG2);

        deleteGraphDAG(pG2);
    }

    return 0;
}

