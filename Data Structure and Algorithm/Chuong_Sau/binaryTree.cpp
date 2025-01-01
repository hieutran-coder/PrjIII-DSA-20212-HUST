#include<iostream>

using namespace std;

struct Node{
    int key;

    Node* leftChild;
    Node* rightChild;
};

Node* root;

Node* makeNode(int v) {
    Node* p =new Node;

    p-> key = v;
    p->leftChild = NULL;
    p->rightChild = NULL;
}

Node* insert(Node* r, int v) {
    if( r== NULL)
        r = makeNode(v); // nếu cây rỗng thì tạo gốc
    else if(r->key > v)
        r->leftChild = insert(r->leftChild, v);
    else if(r->key <= v)
        r->rightChild = insert(r->rightChild, v);
    return r; // Có node đầu tiên là đủ để trỏ đến các node khác??. 
}

// Tìm kiếm trên cây BST

Node* search(Node* r, int v) {
    if( r== NULL) 
        return NULL;

    if(r->key == v) return r; // Trường hợp cơ sở khi đệ quy

    else if(r->key> v)
        return search(r->leftChild, v);
    return  search(r->rightChild, v); 
}

// Nêu ta tráo đổi lệnh ở dòng 53 với lệnh ở dòng 54 thì sao?. 
// Tìm node có giá trị min
Node* findMin(Node* r) {
    if (r == NULL) // Nếu cây rỗng?. / nêu cây rỗng thì trả về NULL--> KO tìm được, Đây cũng là trường hợp cơ sở
                    // Nếu việc search đến nút lá thì con bằng nULL 
                    // Lệnh này chỉ được thực hiện khi chạy qua nút lá. 
        return NULL;

    Node* lmin = findMin(r->leftChild);
    if(lmin !=NULL) return lmin;  // Nếu con bằng NULL hay nút là thì hàm con cuối cúng return nút lá đó?.
                                // Nếu con khác NULL thì tức là ko phải NÚT LÁ?. return về chính lmin, là các hàm đệ quy ở giữa?. Tức là nút lá.
    return r;

}

// Delete: Có 4 trường hợp
// Con kế cận thì có 2 cách: xác định theo duyệt giữa và xác định theo con trái nhất của cây con phải(Con bé nhất trong tất cả thằng con lớn hơn m)

Node* del(Node* r, int v) {

    if(r == NULL) return NULL;

    else if(v < r->key) r ->leftChild = del(r->leftChild, v); // nếu v nằm bên bên trái?. đi vào del bên trái
    else if(v > r->key) r->rightChild = del(r->rightChild, v); // nếu v nằm bên phải?. đi vào del bên phải?.

    else{
        if (r->leftChild != NULL && r->rightChild != NULL){ // NẾu v = r-> key và có cả 2 con
                Node* tmp = findMin(r->rightChild); 
                r-> key = tmp->key; // Thay cho nút con kế cận nhất lớn hơn mình. 

                // Và xoá nút tmp?. 
                r->rightChild = del(r->rightChild, tmp->key); // Việc xoá cũng ko đơn gỉan nhỉ?. 
        }
        else{ // chỉ có con trái hoặc con phải--> Lúc này gán thẳng ông vào con trái hay con phải, cách thầy ko phải vậy. 
             // --> Thầy xoá bằng cách trỏ r đến con trái hay con phải của nó?. thì *r cũng thay đổi mà *r-> left
            Node * tmp = r;
            if (r->leftChild == NULL) r = r->rightChild;
            else r = r->leftChild;
            delete tmp; // Xoá con trỏ chứa key?. 
        }
    }

    return r;
}