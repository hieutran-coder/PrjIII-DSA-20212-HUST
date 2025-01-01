#include<stdio.h>
#include<stdlib.h>
#define SIZE 40 // trong C thif co su dung define nhi?

struct queue{
    int items[SIZE]; // Ta se ung dung cau truc queue vao day
    int front;
    int rear;
}; // Ko co con tro nhi?.

// Xay dung cac thao tac voi queue
struct queue* createQueue();
void enqueue(struct queue* q, int); // dau vao la q va bien int
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node{
    int vertex;
    struct node* next;
}; // Cau truc node?.

struct node* createNode(int); // Co the co bien, hoac chac kieu du lieu khi declaring tham so

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

//Thuat toan BFS-> Tuong tu BFS da hoc trong mon AI--> Dang le phai tu code het cac bai do roi
void bfs(struct Graph* graph, int startVertex){ // bfs nay ko dung recursion?. 
    struct queue* q = createQueue(); //Tao ra queue?.

    graph->visited[startVertex] = 1; //mark thang dau tien da duyet; visit la 1 mang?
    enqueue(q, startVertex); // day no vao hang doi

    while(!isEmpty(q)){ // Khi nao queue rong, tuc tat ca cac dinh da duoc duyet het
        printQueue(q); // Hien thi queue, dang le chi hien thi 1 dinh thoi nhi?.

        int currentVertex = dequeue(q); //
        printf("visited %d\n", currentVertex); // hien thi dinh vua moi deuque;

        struct node* temp = graph->adjLists[currentVertex]; // danh sach cac dinh ke voi dinh currentVertex;

        while(temp){
            int adjVertex = temp->vertex; //xet 1 dinh ke dinh thoi
            
            if(graph->visited[adjVertex] == 0){ // neu dinh chua duoc duyet 
                graph->visited[adjVertex] = 1; // mark dinh do da duye?.
                enqueue(q,adjVertex); // Them dinh do vao q
            }
            temp = temp->next; 
        }
    }

}

// Tao ra 1 queue
struct queue* createQueue() {
    // Cap phat bo nho
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); // Tao ra 1 con tro tro den cau truc q , 
    // Tai sao nguoi ta lai tai queue nhu cau truc, nhung ko bang linker list hay la mang--> quen queue nay dung cau truc mang

// Khoi tao du lieu
    q->front = -1; // Tai sao lai khoi tao bang -1
    q->rear = -1;
// output
    return q; 
}

// Kiem tra queue co rong hay ko?.
int isEmpty(struct queue* q) { // Kiem tra queue co rong hay ko?.
    if (q->rear == -1)  // Tai sao ko phai q->front= -1?. ma lai chon dk nay?.
        return 1;
    else   
        return 0; 
}

// Them cac phan tu vao queue
void enqueue(struct queue* q, int value){
    if (q->rear == SIZE -1) // neu queu da day
        printf("\n queue da day");
    else {
        if(q->front == -1) // Chac la luc khoi tao?.
            q->front = 0;
        q->rear++; // them 1 cho moi
        q->items[q->rear] = value; // Dat gia tri vao duoi cua hang doi
    }
}

//Loai bo 1 phan tu ra khoi queue
int dequeue(struct queue* q) {
    int item;
    if(isEmpty(q)) { // q co bi rong hay ko
        printf("queue dang rong");
        item = -1; // item dung de lam gi
    }else {
        item = q->items[q->front];
        q->front++; // bot 1 cho
        if(q->front > q -> rear) {// neu truoc khi lay ra q->front = q->rear;
            //set up lai q->front giong khoi tao
            q->front = q->rear = -1;
        }
    }
    return item; 
}
// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph =(struct Graph*) malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists =(struct node**) malloc(vertices * sizeof(struct node*));
  graph->visited = ( int*) malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}
// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
// hien thi queue
void printQueue(struct queue* q) {
    int i = q->front;

    if(isEmpty(q)) { // trong truong hop hang doi rong
        printf("Queue la rong");
    } else { // trong truong hop hang doi khong rong
        printf("\n Hang doi chua \n");
        for(i = q->front; i < q->rear + 1; i++)
            printf("%d", q->items[i]);   // Neu 
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    bfs(graph, 0);
    return 0;
}


