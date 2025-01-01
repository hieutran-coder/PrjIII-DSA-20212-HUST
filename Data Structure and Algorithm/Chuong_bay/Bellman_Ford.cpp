#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999

// Cấu trúc của các cạnh trên graph

struct Edge{
    int u; // đỉnh bắt đầu của cạnh
    int v; // đỉnh kết thúc của cạnh
    int w; // độ dài của canh
};

//Graph- nó chứa các cạnh?.
struct Graph{
    int V;  //Số lượng các đỉnh trền đồ thị
    int E;  // Số lượng các cạnh trên đồ thị?.
    struct Edge *edge; //Danh sách các cạnh?. 
};
// Cấu trúc graph có vẻ rất đơn giản

void bellmanFord(struct Graph*g, int source);
void display(int arr[], int size);

int main() {  // Tham số void có nghĩa là gì?.
        // cấp phát bộ nhớ cho traph
        struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
        g->V = 4;
        g->E = 5;

        //Cấp phát bộ nhớ cho cạnh của graph
        g->edge = (struct Edge*) malloc(g->E*sizeof(struct Edge));

        // Tjee, cạmk vàp gra[j
        /*
                cạnh u,v đi từ đỉnh u đến đỉnh v */
    //cạnh đi 0 đến 1
    g->edge[0].v= 0;
    g->edge[0].u = 1;
    g->edge[0].w = 3;

    g->edge[1].v = 0;
    g->edge[1].u = 2;
    g->edge[1].w = 4;

    // Cạnh từ đỉnh 2 đến đỉnh 1
    g->edge[2].u = 2;
    g->edge[2].v = 1;
    g->edge[2].w = 6;

    //Cạnh đi từ 3 đến 2
    g->edge[4].u = 3;
    g->edge[4].v = 2;
    g->edge[4].w = 2;

    bellmanFord(g, 4); // đồ thị với g với 0 là đỉnh bắt đầu


    return 0; 
}

void bellman(struct Graph *g, int source){
    // các biến
    int i, j, u, v, w;

    // tất cả các đỉnh trên graph g
    int tV = g->V; 

    // Tất cả các cạnh trên Graph g
    int tE = g->E;

    // Dãy các đường đi có số lượng bằng số lượng các đỉnh trên GRAPH?
    int d[tV];

    // dãy các predecessor
    int p[tV];

    // Bước 1: fill precessor và các đường đi
    for(i = 0; i < tV; i++){
        d[i] = INFINITY;
        p[i] = 0;
    }

    // Đánh dấu đường đi đến source vertex là 0
    d[source] = 0;

    // Bước 2: Là relax mỗi cạnh V-1 lần
    for (i = 1; i <= tV-1; i++){
        for (j = 0; j < tE; j++ ){
            // lấy dữ liệu cạnh
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;

            if(d[u] != INFINITY && d[v] > d[u] + w){ // Từ thằng không phải infinity thì sẽ cập nhật thằng inifinity
                d[v] = d[u] + w;
                p[v] = u; 
            }
        }
    }

// Bước 3: PHát hiện chu trình âm<--> Nếu sau v-1 lần làm và làm thêm 1 lần nữa vẫn có cái thay đổi?.-->

for( i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;

    if (d[u] != INFINITY && d[v]> d[u] + w) { // Vẫn còn có thể cập nhật được đường đi là hỏng rồi
        printf("Đã phát hiện được chu trình âm \n"); 
        return;
    }
    }
// Không có chu trình âm--> Vậy tìm được

printf("dãy các  độ dài: ");
display(d, tV);

printf("Dãy các Predecessor:" );
display(p, tV);

}

void display(int arr[], int size){
    int i;

    for(i = 0; i < size; i++) {
        printf("%d", arr[i]);

    }
    printf("\n");
}
