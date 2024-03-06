#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void topologicalSortUtil(int v, struct Graph* graph, int visited[], struct Node** stack) {
    visited[v] = 1;

    struct Node* current = graph->adjacencyList[v];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor])
            topologicalSortUtil(neighbor, graph, visited, stack);
        current = current->next;
    }

    struct Node* newNode = createNode(v);
    newNode->next = *stack;
    *stack = newNode;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i)
        visited[i] = 0;

    struct Node* stack = NULL;

    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i])
            topologicalSortUtil(i, graph, visited, &stack);
    }

    printf("Topological Sort: ");
    while (stack != NULL) {
        printf("%d ", stack->data + 1);  // Adjust indexing by adding 1
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }

    free(visited);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; ++i) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        // Adjust indexing by subtracting 1
        addEdge(graph, src - 1, dest - 1);
    }

    topologicalSort(graph);

    free(graph->adjacencyList);
    free(graph);

    return 0;
}
