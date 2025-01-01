#include<iostream>
using namespace std;

// struct BNode{
//         int id;
//         BNode* leftChild;
//         BNode* rightChild;
// };

// void inOrder(BNode * r){
//     if( r== NULL) return;

// // Duyệ tthoe thứ thự giữa
//     inOrder( r->leftChild);
//     printf("%d", r->id);
//     inOrder(r->rightChild);
// }


// void preOrder(BNode * r){
//     if(r== NULL) return;

//     printf("%d", r->id);
//     preOrder(r->leftChild);
//     preOrder(r->rightChild);
// }

// void postOrder(BNode * r) {
//     if (r==NULL) return;

//     postOrder(r->leftChild);
//     postOrder(r->rightChild);
//     printf("%d", r->id);

// }

// int count(BNode* r){
//     if (r==NULL) return;

//     return 1 + count(r->leftChild) + count(r->rightChild);
// }

// Kiểm tra có phải full Binary Tree ko?.

// struct Node {
//     int key;
//     struct Node *left, *right; 
// };

// // Tạo ra 1 new Node
// struct Node *newNode(char k) {
//     struct Node *node = (struct Node*) malloc(sizeof(struct Node)); // Cấp bộ nhớ cho node, cách trước kia là dùng new

// // Khởi tạo các gía trị cho node
//     node->key = k;
//     node->right = node->left = NULL;
//     return node;
// }

// // wow hoá ra đệ quy có thể dùng trong hỏi máy xem có full binary tree ko?. 
// bool isFullBinaryTree(struct Node *root) { // Kiểm tra cây có phải là cây full ko?

//     // Kiểm tra xem cây có rỗng ko?
//     if( root == NULL) return true;

//     // kiểm trả về sự xuất hiện của những thằng children, nếu ko có con nào cả thì trả về true và dừng, ko thực hiện thuật toán dưới?. 
//     if (root->left == NULL && root->right == NULL)   // Đây là trường hợp cơ sở?. 
//         return true;  // Bỏ qua khi có ít nhất 1 con?. 

//     // Lệnh này xem xét thực hiện khi cây có ít nhất 1 con
//     if((root->left) &&(root->right))
//         return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right)); // Đệ quy và tổng hợp lại các bài toán?. 

//     return false;
// }

// int main() {
//     struct Node *root = NULL;

//     root = newNode(1);

//     root->left = newNode(2);
//     root->right = newNode(3);

//     root->left->left = newNode(4);

//     root->left->right = newNode(5);

//     root->left->right->left = newNode(6);

//     root->left->right->right = newNode(7);

//     if (isFullBinaryTree(root))
//         cout <<" đúng rồi";


// }
// Kiểm tra có phải Perfect Binary Tree ko?.
// #include<iostream>
// using namespace std;


// struct Node{
//     int key;
//     struct Node *left, *right; 
//     };

// // Tính độ depth của 1 node?. HƠi sai sai?.
// int depth(Node *node) {
//     int d= 0;

//     while( node != NULL) {
//         d++;
//         node = node->left;
//     }
//     return d; 
// }

// // d là gì?. 
// bool isPerfectR(struct Node *root, int d, int level = 0) {  // giống tìm node ở độ sâu phải ko??.

//     if (root == NULL) return true;

// // Kiểm tra xem cả 2 thằn bằng null ko?. 
//     if(root->left == NULL && root->right == NULL) // Cáinafy là sao?. 
//         return(d == level +1); // level này đã chạy đến độ sâu cuối cùng chưa có phải ko?. 

// // NẾu chạy đến độ sâu cuôi thì return về cho hàm đã gọi nó---> Đây chắc là trường hợp cơ sở.
// // Nếu chưa chạy đến độ sâu cuói thì return về false cho hàm gọi nó. 


// // Đã qua trường hợp trên tức có 1 thằng khác null. 
//     if (root->left == NULL || root->right == NULL )  // Trường hợp cơ sở?. chú ý rằng là trường hợp này có ít nhất 1 thằng khác null rồi?
//         return false;

//     return isPerfectR(root->left, d, level+1) && isPerfectR(root->right, d, level + 1);  // Đệ quy ra 2 bài toán con và tổng hợp lại.

// }

// bool isPerfect(Node *root) {
//     int d = depth(root);
//     return isPerfectR(root, d); // Đầu vào là root với 1 độ sâu. rõ ràng chỉ cần root là được, tại sao cần d nhỉ?.
// }

// struct Node *newNode(int k) {
//     // Cấp phát bộ nhớ cho node kiểu Node
//     struct Node *node = new Node;

//     // Khởi tạo giá trị cho node
//     node->key = k;
//     node->right = node->left = NULL; // 

//     return node;
// }

// int main() {
//     struct Node *root = NULL;

//     root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);

//     root->left->left = newNode(4);
//     root->left->right = newNode(5);

//     root->right->left = newNode(6); 


// if(isPerfect(root))
//         cout << " Tree là cây hoàn hảo";
//     else
//         cout << " Tree ko phải là cây hoàn hảo";

// }

////////////////////////

// Kiểm tra xem binary Tree có phải là comlete binary tree ko?. 


// #include<iostream>

// using namespace std;

// // Cấu trúc này thì có vẻ là tree nào cũng dùng cả.
// struct Node {
//     int key;
//     struct Node *left, *right;
// };

// // Tạo ra Node
// struct Node *newNode(char k) {

//         // Cấp phát bộ nhớ cho cấu trúc
//         struct Node *node = (struct Node *)malloc(sizeof(struct Node));

//         // khởi tạo giá trị cho con trỏ?.
//         node->key = k;
//         node->right = node->left = NULL;
//         return node;
// }

// //Tính toán số lượng Node : Tương tự như cách tính 1 cây nhị phân bâst kì

// int countNumNodes(struct Node *root) {
//     if(root == NULL) return 0;

//     return (1 + countNumNodes(root->left) + countNumNodes(root->right));  // Đếm bằng đệ quy và chia ra 2 bài toán con và tổng hợp lại 
// }

// // kiểm tra liệu cây nhị phân này có complete ko?
// // index này là index của root?. 

// // Cái đầu ra của hàm trên là đầu vào của hàm này?. --> Remind idea COupoling vs cohesion chắc sẽ phải tập hợp question lại?. Đợi hẹ thồi.
// bool checkComplete(struct Node *root, int index, int numberNodes) {

//     // Kiểm tra xem cây có rỗng hay ko?
//     if(root == NULL) return true; 

//     // Xuống đây thì root khác null rồi?. 
//     if (index >= numberNodes) return false; // Index là gi?. Trường hợp cơ này xảy ra khi nào?. --> Khi đã xem xét hết index của nháh.
//         // Ồ, hoá ra nếu tồn tại 1 Index > numbers nodes thì nó sẽ ko lệch trái hết?. --> Ko phải complete?
//         // complete-<-> phải có điều kiện này đúng với tất cả thằng index

//         // Tại sao lại 2* +1 và 2* +2?. Nó liên quang dến dãy số hay sao?. 
//                  // index nó trỏ đến vị trí của phần tử của cây, 2* là lever cao hơn?. Nó chính xác là index của root luôn

//     return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2*index + 2, numberNodes)); 
//                    // Trong trường hợp ko có right Sibling thì return về có true nữa ko?
//                    // Tại sao lại đơn giản thế?.
// }




// int main() {
//     struct Node *root = NULL; 

// // Khởi tạo các node?. 
//     root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);
//     root->right->right = newNode(6);



//     int node_count = countNumNodes(root);
//     int index = 0;

//     if (checkComplete(root, index, node_count))
//         cout << " Tree này là completion"<<endl;
//     else   
//         cout << " Tree này ko phải là completion \n";
// }

//

// Checking if a binary tree is height balanced in C++



#include<iostream>
using namespace std;

#define bool int; 

// ko giống như chủ đề complete--> sử dụng cách khác để toạ node

class node {
    public:
         int item;
         node *left;
        node *right;
};

// Tạo ra 1 node mới

node *newNode(int item) // Đầu vào là 1 int, còn đầu ra là 1 con trỏ
{
    node *Node = new node(); // Cách tạo 1 đói tượng đây sao?. 
    Node->item = item;
    Node->left = NULL;
    Node->right = NULL;

    return (Node); 
}

// kiểm tra sự ballance
bool int checkHeightBalance(node *root, int *height) {
    // Kiểm tra sự trống rỗng
    int leftHeight = 0, rightHeight = 0;

    int l =0, r = 0; // l, r dùng để làm gì?.

    if (root == NULL){  // cây rỗng. 
        *height = 0;
        return 1;
    }

    l = checkHeightBalance(root->left, &leftHeight); // đệ quy với trường hợp cây con trái
    r = checkHeightBalance(root->right, &rightHeight); // đệ quy với trường hợp cây con phải

    // Tính giá trị của height trỏ đến
    *height =(leftHeight >rightHeight? leftHeight: rightHeight) + 1;// đây là 1 cách viết khác cấu trúc if,else, nó chỉ quan tâm đến giá trị, giống excel.

    if( std:: abs(leftHeight-rightHeight >=2)) return 0; // Nếu cây mà ko cân bằng 
    // Nếu mà return 0 trong hàm con thì chương trình cũng kết thúc luôn phải ko? --> KO vô lý, nó chỉ return về hàm được gọi thôi chứ.

    else return 1&& r; //là sao?. Tại sao lại cả r ữa?. Tức là r khác ko thì return 1 r bằng 0 thì return 0. 
}


int main() {
    int height = 0;

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 


    if (checkHeightBalance(root, &height))
        cout <<" Cây là cân bằng";
    else
        cout <<" Cây ko cân bằng";

}