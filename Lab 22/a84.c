// 84. Write a program to create a graph & implement the adjacency list
// representation of the graph.
// Apply DFS and BFS on the given graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node
{
    int info;
    struct Node *link;
};

struct Node *adjList[MAX];
int V;

void addEdge(int src, int dest)
{
    // Add dest to src
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->info = dest;
    newNode->link = adjList[src];

    adjList[src] = newNode;

    // Add src to dest
    // karnk ahiya apde undirected graph consider karie chiye
    newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->info = src;
    newNode->link = adjList[dest];

    adjList[dest] = newNode;
}


void displayGraph()
{
    for(int i = 0; i < V; i++)
    {
        printf("%d -> ", i);

        struct Node *save = adjList[i];

        while(save != NULL)
        {
            printf("%d -> ", save->info);
            save = save->link;
        }

        printf("NULL\n");
    }
}

// int stack[MAX];
// int top = -1;


// // Push
// void push(int x)
// {
//     stack[++top] = x;
// }


// // Pop
// int pop()
// {
//     return stack[top--];
// }


// // DFS using Stack
// void dfs(int start)
// {
//     int visited[MAX] = {0};

//     top = -1;

//     // Push starting vertex
//     push(start);

//     while(top != -1)
//     {
//         // Take vertex from stack
//         int v = pop();

//         // If not visited
//         if(visited[v] == 0)
//         {
//             visited[v] = 1;

//             printf("%d ", v);

//             // Visit all adjacent vertices
//             struct Node *save = adjList[v];

//             while(save != NULL)
//             {
//                 if(visited[save->info] == 0)
//                 {
//                     push(save->info);
//                 }

//                 save = save->link;
//             }
//         }
//     }
// }

void dfs(int v, int visited[])
{
    visited[v] = 1;
    printf("%d ", v);

    struct Node *save = adjList[v];

    while(save != NULL)
    {
        if(visited[save->info] == 0){
            dfs(save->info, visited);
        }

        save = save->link;
    }
}

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}


void bfs(int start)
{
    int visited[MAX] = {0};

    visited[start] = 1;
    enqueue(start);

    while(front <= rear) // queue empty na thai tya sudhi
    {
        int v = dequeue();
        printf("%d ", v);

        struct Node *save = adjList[v];

        while(save != NULL)  // vertex v na badha adj 
        {
            if(visited[save->info] == 0) // if jo unvisited then enqueue
            {
                visited[save->info] = 1;
                enqueue(save->info);
            }
            save = save->link;
        }
    }
}


void main()
{
    V = 5;

    // Initially all adjacency lists are empty hase
    for(int i = 0; i < V; i++)
    {
        adjList[i] = NULL;
    }

    addEdge(0, 1);
    addEdge(0, 4);

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    addEdge(2, 3);

    addEdge(3, 4);


    printf("Adjacency List:\n");

    displayGraph();


    int visited[MAX] = {0};

    printf("\nDFS starting from vertex 0 : ");

    dfs(0, visited);


    printf("\n\nBFS starting from 0:\n");

    bfs(0);


}