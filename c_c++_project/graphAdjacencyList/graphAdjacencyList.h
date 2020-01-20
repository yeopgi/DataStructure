#ifndef _GRAPH_ADJACENCY_LIST_H
#define _GRAPH_ADJACENCY_LIST_H

typedef enum {UNDIRECTED = 0, DIRECTED =1 } GraphType;
typedef struct Node {
    int dest;
    Node *next;
}Node;

typedef struct HeadNodes {
    int nodeSize;
    GraphType mode;
    struct HeadNodes* list;
}Graph;

void graphvizDriver(Graph *g);
void graphvizPrint(Graph* g);

Graph* create(int nodeNo, GraphType mode);
void destory(Graph* g);
void insertEdge(Graph* g, int from, int to);
void deleteEdge(Graph* g, int from, int to);
Node* newNode(int dest);
void print(Graph g);

#endif