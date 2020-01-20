#include <stdio.h>
#include <stdlib.h>
#include "graphAdjacencyList.h"

void graphvizPrint(Graph* g)
{
    char* mode;
    if(g->mode == DIRECTED) mode = "->";
    else mode = "--";

    for(int v =0; v < g->nodeSize; v++) {
        printf("\t\"%d\";\n", v);
    }

    for(int v = 0; v < g->nodeSize; v++) {
        Node* n = g->list[v].head;
        while (n) {
            printf("\t\%d\" %s \"%d\";\n", v, mode, n->dest);
        }
    }
}

void graphvizDriver(Graph *g)
{
    if (g->mode == DIRECTED) printf("digraph G {\n");
    else printf("graph G {\n");

    graphvizPrint(g);
    printf("}\n");
}