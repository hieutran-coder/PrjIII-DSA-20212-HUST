#include<iostream>
#include<vector>

#define INT_MAX 10000000

using namespace std;

void DijkstrasTest();


int main() {
    // Thay Trung khi nao cung 2 phan la input() va solve(); 
    DijkstrasTest();
    return 0;
}

class Node;
class Edge;

void Dijkstras();
vector<Node*>* AdjacentRemainingNodes(Node* node); // NO tra ve 1 danh sach cac vector hay sao?. Dau vao la 1 con tro, dau ra cung la con tro

Node* ExtractSmallest(vector<Node*>& nodes); // Lay ra nho nhat, dau vao la day cac con tro, dau ra 1 con tro?

int Distance(Node* node1, Node* node2); // Day la khoang cach gia 2 dinh?.

bool Contains(vector<Node*>& nodes, Node* node); //Tai sao lai co tham chieu o day, --> Vua truyen vao con tro va tham chieu

void PrintShortestRouteTo(Node* destination);  // Hien thi duong di ngan nhat ma tim duoc

vector<Node*> nodes; // Danh sach cac nodes
vector<Edge*> edges; // Danh sach cac edges


// Lớp đỉnh?. 
class Node{
    // Phương thức khởi tạo?. 
    public:   
        Node (char id) : id(id), previous(NULL), distanceFromStart(INT_MAX){  //? DKay 2 cham la syntax gi vay--> Khởi tạo
            nodes.push_back(this); // this là chỉ class này hay sao???. 
        }

    public:
        char id;
        Node* previous; // Node trước đó?.
        int distanceFromStart; // Khoảng cách tử đầu đến node
};


// Lớp cạn?. 
class Edge{

    public:
        Edge(Node* node1, Node* node2, int distance)
          : node1(node1), node2(node2), distance(distance) {
              edges.push_back(this);
          }
        // Hàm connect này có chức năng gì? Kiểm tra đầu vào có khớp với class??? 
        bool Connects(Node* node1, Node* node2) {
            return(
            (node1 == this->node1 && node2 == this->node2) || (node1 == this->node2 && node2 == this->node1))
        }


    public:
        Node* node1; // Nó là composition của các nodes?. 
        Node* node2; 
        int distance; 

};

void DijkstrasTest() {

// Nếu là con trỏ thì mới có * và new, 
    Node* a = new Node('a'); // Khởi tạo node a với id là a; 
    Node* b = new Node('b'); // Khởi tạo đôi tượng node b với id là b
    Node* c = new Node('c'); // khởi tạo node c với id là c
    Node* d = new Node('d'); // khởi tạo node d với id là d
    Node* e = new Node('e'); // khởi tạo node e với id là e
    Node* f = new Node('f'); // khởi tạo node f với id là f
    Node* g = new Node('g'); // Khởi tạo node g với id là g.

    Edge* e1 = new Edge(a, c, 1); // Khởi tạo cạnh e1 với 2 node a, và c và độ dài cạnh là 1
    Edge* e2 = new Edge(a, d, 2); // Khởi tại cạnh e2 với 2 nodes a, d, và đồ dại cạnh e2 là 2
    Edge* e3 = new Edge(b, c, 2); // Khởi tạo cạnh e3 với 2 nodes b, c và đồ dài là 2;
    Edge* e4 = new Edge(c, d, 1); // Khởi toạ cạnh e4 với 2 nodes c,d và đồ dại là 1;
    Edge* e5 = new Edge(b, f, 3); 
    Edge* e6 = new Edge(c, e, 3);
    Edge* e7 = new Edge(e, f, 2);
    Edge* e8 = new Edge(d, g, 1);
    Edge* e9 = new Edge(g, f, 1);

    a->distanceFromStart = 0 ; // lấy node bắt đầu
    Dijkstras();
    PrintShortestRouteTo(f); // HIện thị con đường ngắn nhất đi đến f?. 
}

////////////

void Dijkstra() {
    while(nodes.size() > 0) { //vector nodes?. 

      Node* smallest = ExtractSmallest(nodes); // 1.Lấy node khoảng cách minh nhất?. chắc khoảng cách đến shorted Path?. 

    vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest); // Lấy danh sách các node kề với node smallest và chắc là còn lại chưa được duyệt?. 

    const int  size = adjacentNodes->size();

    // 2. Update tất cả đường đi của các đỉnh kề với đỉnh smallest?. 
    for(int i = 0; i< size; ++i) {
        Node* adjacent = adjacentNodes->at(i); // duyệt 1 node
        int distance = Distance(smallest, adjacent) + smallest->distanceFromStart; // Tính khoảng cách mới 

        // So sánh khoảng cách mới với khoảng cách cũ?. Nếu relax hơn thì sẽ cập nhật, còn ko thì bỏ qua if?. 
        if(distance < adjacent->distanceFromStart) {
            adjacent->distanceFromStart = distance;
            adjacent->previous = smallest; 
        }
    }
        delete adjacentNodes; 
   
    }
}

// Tìm node có Min distance;
// Xoá nó, và trả nó về?. --> Taị sao phả xoá nó nhỉ?. Nếu như thế thì sẽ lặp lại

Node* ExtractSmallest(vector<Node*>& nodes) {
        int size = nodes.size();

        if (size == 0) return NULL; //  Nếu nodes rỗng


// Chọn thằng nào min thôi?. 
        int smallestPosition = 0;  // Chọn vị trí thấp nhất
        Node* smallest = nodes.at(0);// Khởi tạo giá trị cho con trỏ smallest?. 

        for (int i = 1; i < size; ++i){
            Node* current = nodes.at(i); 
            if(current->distanceFromStart < smallest->distanceFromStart){
                smallest = current;
                smallestPosition = i; // Giống như selection sort nhỉ?. 
            }
        }
    nodes.erase(nodes.begin() + smallestPosition); // Xoá bỏ nodes smallest sau khi đã xác định được node đó ở vị trí nào rồi. 
            // nodes.begin() nó kiểu gì?.

    return smallest; // erase thì ko có nghĩa là nó mất đi trong bộ nhớ hay sao?. 
}

// Trả về tất cả các nodes kề với node hiện tại vẫn trong collection các nodes. // Truyền vào 1 con trỏ và trả về 1 danh sách các
// con trỏ kề với nó. 
vector<Node*>* AdjacentRemainingNodes(Node* node) {   //* ngoiaf ám chỉ con trỏ trỏ đến 1 tập các con trỏ?.
    vector<Node*>* adjacentNodes = new vector<Node*>(); // KHởi tạo đối tượng danh sách các con trỏ node.

    const int size = edges.size(); // là biến hằng--> Hằng có bộ nhớ. 


    for (int i = 0; i < size; ++i){ // duyệt tất cả các cạnh?. 
        Edge* edge = edges.at(i); 
        Node* adjacent = NULL;
// Trong trường hợp là cạnh kề với node?. 
// Cái này có nghĩa là adjacent sẽ trỏ đến đầu bên kia của cạnh?. tức khác điểm mút là node?. 
        if(edge->node1 == node) {
            adjacent = edge->node2; 
        }else if(edge->node2 == node){
            adjacent = edge->node1;
        }

// Cái đầu chắc tránh adjacent = NULL?. 
        if(adjacent && Contains(nodes, adjacent)){ // Kiểm tra xem trong nodes có đã duyệt trước đó chưa?. Nếu chưa tức là nodes vẫn còn chứa nó
        // Thì sẽ bỏ vào trong danh sách kề của node
            adjacentNodes->push_back(adjacent); 
        }
    }
    return adjacentNodes; // Trả về danh sách các đỉnh kề chưa duyệt của 1 node?. 
    // Và danh sách này hiện tại pảhi nằm trong nodes.
}

// Trả về khoảng cách giữa 2 nodes được kết nối với nhau?. 
int Distance(Node* node1, Node* node2) {
    const int size = edges.size();

    for(int i = 0; i < size; ++i){ // Duyệt tất cả các edges?. xem Edges nào match vs 2 nodes đầu vào?. 
        Edge* edge = edges.at(i);

        if(edge->Connects(node1, node2)) {
            return edge->distance; // Trả về khoảng cách giữa 2 node đó?. 
        }
    }
    return -1; // Không bao giờ xảy ra?. 
}

// Liệu vector nodes có chứa node không?.
bool Contains(vector<Node*>& nodes, Node* node) {
    const int size = nodes.size(); // tại sao khi nào cũng lấy biến hằng nhỉ, biến thường ko được hay sao?.

// Duyệt từng thành phần của vector?. 
    for (int i = 0; i< size; ++i){
        if(node == nodes.at(i)) {
            return true; 
        }
    }
    return false; 
}

////////////////////

// Hiện thị đường đi ngắn nhất
void PrintShortestRouteTo(Node* destination) {
    Node* previous = destination; 

    // Khoảng cách
    cout << " khoảng cách từ start: "
    << destination->distanceFromStart << endl;

    // Các địa điểm trên path đi đến destination.
    while(previous) {
        cout << previous->id <<" ";
        previous = previous->previous; // Con trỏ duyệt ngược giống trong linker list?. 
    }
    cout << endl;
}


vector<Edge*>* AdjacentEdges(vector<Edge*>& Edges, Node* node) {// Truyền vào 1 tham chiếu và 1 con trỏ?.
}; 

void RemoveEdge(vector<Edge*>& Edges, Edge* edge); 

// Ta sẽ cài đặt 2 hàm này?.

vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node) {
    
    vector<Edge*>* adjacentEdges = new vector<Edge*>();

    const int size = edges.size();

    for (int i = 0; i < size; ++i){
        Edge* edge = edges.at(i); // Là 1 cạnh tại vị trí thứ i
        if (edge->node1 == node){
            cout << "adjacent: " <<edge->node2->id <<endl;
            adjacentEdges->push_back(edge);
        } else if(edge->node2 == node) {
            cout <<"adjacent: "<<edge->node1->id <<endl;
            adjacentEdges->push_back(edge);
        }
    }
    return adjacentEdges; 
}

void RemoveEdge(vector<Edge*>& edeges, Edge* edge) {    
    
    vector<Edge*>::iterator it;

    for(it = edges.begin(); it < edges.end(); ++it) {
        if( *it == edge) {
            edges.erase(it); // Xoá cạnh match với cạnh input di?. 
            return; 
        }
    }
}