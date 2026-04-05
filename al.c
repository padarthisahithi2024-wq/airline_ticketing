#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define FILE_NAME "flights.txt"

/* Edge structure */
struct Edge {
    int destination;
    int price;
    struct Edge* next;
};

/* Graph structure */
struct Graph {
    int vertices;
    char airport[MAX][50];
    struct Edge* adjList[MAX];
};

/* Create Graph */
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    for(int i=0;i<v;i++)
        graph->adjList[i] = NULL;

    return graph;
}

/* CREATE - Add Flight */
void addFlight(struct Graph* graph, int src, int dest, int price) {

    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->destination = dest;
    newEdge->price = price;
    newEdge->next = graph->adjList[src];

    graph->adjList[src] = newEdge;

    printf("Flight added successfully\n");
}

/* READ - Display Flights */
void displayFlights(struct Graph* graph) {

    for(int i=0;i<graph->vertices;i++) {

        printf("\nFlights from %s:\n", graph->airport[i]);

        struct Edge* temp = graph->adjList[i];

        while(temp) {
            printf(" -> %s (Price: %d)", graph->airport[temp->destination], temp->price);
            temp = temp->next;
        }

        printf("\n");
    }
}

/* SEARCH Flight */
void searchFlight(struct Graph* graph, int src, int dest) {

    struct Edge* temp = graph->adjList[src];

    while(temp) {

        if(temp->destination == dest) {
            printf("Flight found! Ticket Price: %d\n", temp->price);
            return;
        }

        temp = temp->next;
    }

    printf("Flight not found\n");
}

/* UPDATE Flight Price */
void updateFlight(struct Graph* graph, int src, int dest, int newPrice) {

    struct Edge* temp = graph->adjList[src];

    while(temp) {

        if(temp->destination == dest) {

            temp->price = newPrice;
            printf("Flight price updated successfully\n");
            return;
        }

        temp = temp->next;
    }

    printf("Flight not found\n");
}

/* DELETE Flight */
void deleteFlight(struct Graph* graph, int src, int dest) {

    struct Edge* temp = graph->adjList[src];
    struct Edge* prev = NULL;

    while(temp) {

        if(temp->destination == dest) {

            if(prev == NULL)
                graph->adjList[src] = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Flight deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Flight not found\n");
}

/* SAVE DATA TO FILE */
void saveToFile(struct Graph* graph) {

    FILE *fp = fopen(FILE_NAME,"w");

    for(int i=0;i<graph->vertices;i++) {

        struct Edge* temp = graph->adjList[i];

        while(temp) {

            fprintf(fp,"%d %d %d\n", i, temp->destination, temp->price);

            temp = temp->next;
        }
    }

    fclose(fp);
}

/* LOAD DATA FROM FILE */
void loadFromFile(struct Graph* graph) {

    FILE *fp = fopen(FILE_NAME,"r");

    if(fp == NULL)
        return;

    int src, dest, price;

    while(fscanf(fp,"%d %d %d",&src,&dest,&price) != EOF) {

        struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));

        newEdge->destination = dest;
        newEdge->price = price;
        newEdge->next = graph->adjList[src];

        graph->adjList[src] = newEdge;
    }

    fclose(fp);
}

/* MAIN FUNCTION */
int main() {

    int v;

    printf("Enter number of airports: ");
    scanf("%d",&v);

    struct Graph* graph = createGraph(v);

    for(int i=0;i<v;i++) {

        printf("Enter airport %d name: ",i);
        scanf("%s",graph->airport[i]);
    }

    /* Load saved flights */
    loadFromFile(graph);

    int choice, src, dest, price;

    while(1) {

        printf("\n------ Airline Ticketing System ------\n");
        printf("1. Add Flight\n");
        printf("2. Delete Flight\n");
        printf("3. Update Flight Price\n");
        printf("4. Search Flight\n");
        printf("5. Display Flights\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                printf("Enter source airport index: ");
                scanf("%d",&src);

                printf("Enter destination airport index: ");
                scanf("%d",&dest);

                printf("Enter ticket price: ");
                scanf("%d",&price);

                addFlight(graph,src,dest,price);
                break;

            case 2:
                printf("Enter source airport index: ");
                scanf("%d",&src);

                printf("Enter destination airport index: ");
                scanf("%d",&dest);

                deleteFlight(graph,src,dest);
                break;

            case 3:
                printf("Enter source airport index: ");
                scanf("%d",&src);

                printf("Enter destination airport index: ");
                scanf("%d",&dest);

                printf("Enter new ticket price: ");
                scanf("%d",&price);

                updateFlight(graph,src,dest,price);
                break;

            case 4:
                printf("Enter source airport index: ");
                scanf("%d",&src);

                printf("Enter destination airport index: ");
                scanf("%d",&dest);

                searchFlight(graph,src,dest);
                break;

            case 5:
                displayFlights(graph);
                break;

            case 6:
                saveToFile(graph);
                printf("Data saved successfully. Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}