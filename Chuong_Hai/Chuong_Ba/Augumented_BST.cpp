// #include<iostream>
// using namespace std;


// // struct của binary tree node

// struct Node {
//     int data;
//     Node* left, * right;
// }; 

// //tối ưu nhữngcasi hàm new Node trên BST
// struct Node *createNode(int data) { // đầu vào là int, đầu ra là con trỏ.--> Cách cài đặt này quá là quen thuộc rồi
//     Node * new_Node = new Node; // Tạo ra bộ nhớ cho giá trị của con trỏ và bộ nhớ cho con trỏ?
    
//     // Khởi tạo giá trị cho node mới
//     new_Node->left = NULL;
//     new_Node->right = NULL;
//     new_Node->data = data;
//     return new_Node;
// };

// struct Node * insert(Node * root, int key) {

//     // Nếu tree đang rỗng thì return a new node
//     if (root == NULL)
//         return createNode(key);  // Gọi đến hàm create node để nó thực hiện và khi nó trả về rồi, mình cũng trả giá trị nó trả về lại cho hàm main
//                 // Chắc đây là trường hợp cơ sở?.
    
//     // Recur left tree
//     if (root->data>key)
//         root->left = insert(root->left, key);
    
//     else if (root-> data < key)
//         root->right = insert(root->right, key);
    
//     // Trả về root 
// };

// // Bằng với phần tử nhỏ nhất thứ k
// // Duyệt theo inorder tree?. --> Vậy gốc sẽ được duyệt sau khi duyệt hết bên trái?. 
// // Bởi vì cây này theo thứ tự tăng dầnh inorder tree ?. 
// int ksmallestElementSumRec(Node *root, int k, int & count) { // Truyền tham chiếu của biến count, chắc là biến static

//     // trường hợp cơ sở
//     if (root == NULL) return 0;
//     if (count > k) return 0; // Count để làm gì?. chắc để đếm và tăng từ từ đến bằng k.

//     // Xuống được đây thì count phải <=k
//     // Tính tổng các phần tử ở cây bên trái
//     int res = ksmallestElementSumRec(root->left, k, count); // Thực hiện hàm này chắc làm thay đổi biến count?. 

//     if (count >= k) return res; // Tại sao lại có dòng iff này 

//     // Thêm dữ liệu của root vào res
//         res+= root->data; 

//     // Thêm một node vmới
//     count++;
//     if (count== k) return res;

//     // if count bé hơn hoặc bằng k, trả về cây con phải?.
//     return res + ksmallestElementSumRec(root->right, k, count); //vừa giải bài toán con vừa tổng hợp bài toán
// }

// // Đóng gói over ksmallestElementSumRec()
// int ksmallestElementSum(struct Node * root, int k) {
//     // Giảm đi một biến count so với hàm ở trên?.
//     int count = 0;
//     ksmallestElementSumRec(root, k, count); 
// }


// int main() {
//     Node *root = NULL;

// // Chèn các node vào cây có gốc là root
//     root = insert(root, 54);
//     root = insert(root, 51);
//     root = insert(root, 49);
//     root = insert(root, 52);
//     root = insert(root, 75);
//     root = insert(root, 74);
//     root = insert(root, 85);

//     int k = 3; // 3 phần tử nhỏ nhất

//     cout <<"Sum of k phần tử nhỏ nhất là: "<< ksmallestElementSum(root,k); 
// }


#include<iostream>
using namespace std;

// node cây nhị phân

// Cấu trúc của c
struct Node {
    int data;
    int lCount;
    int Sum;

    Node* left;
    Node* right;
};

// utility function node mới của BST
struct Node *createNode(int data) {
    
    Node *new_Node = new Node;

    new_Node->left = NULL;
    new_Node->right = NULL;

    new_Node->data = data;
    new_Node->lCount = 0;
    new_Node->Sum = 0;

    return new_Node; 
}

//
struct Node *insert(Node *root, int key) {

    // Kiểm tra cây có rỗng hay không
    if (root == NULL)
        return createNode(key);

    // nêu cây không rỗng thì recur xuông

    if (root->data> key){
        // Tăng lCount của current Node
        
        root->lCount++; // Truyền vào địa chỉ nên hoàn toàn tăng được // tămg số lượng phần tử ở cây con trái?.

        // Tăng tổng của current Node bằng cách adding key into it
        root->Sum += key; // vế trái là l value, vế phải là r value; // tăng tổng

        root->left = insert(root->left, key);

    }
    else if(root->data < key)
        root->right = insert(root->right, key); // tại sao bên trái thì cộng vào còn bên phải chỉ gọi đến hàm này mà không cộng

    return root;

}

void ksmallestElementSumRec(Node *root, int k, int &temp_sum) {

    if (root== NULL) return; 

//Biến temp_sum dùng để làm gì?.
    //Nếu đã tìm được k phần tử nhỏ nhất thì kết thúc
    if(root->lCount +1 == k){
        temp_sum += root->data + root->Sum; 
        return;
    }
  else if(k > root->lCount) // Chắc lúc này sẽ phải đi sang cây con phải
    {
        //lưu trữ tổng tất cả các phần tử nhỏ hơn root hiện tại.
        temp_sum += root->data + root->Sum;

        // giảm k đi và gọi cây con phải
        k = k -(root->lCount + 1);
        ksmallestElementSumRec(root->right, k, temp_sum);
        }
        else // trường hợp k nhỏ hơn lcount;
            // gọi cây con trái
            ksmallestElementSumRec(root->left, k, temp_sum);
    }


// đóng gói nó
int ksmallestElementSum(struct Node *root, int k) {
    
    int sum = 0;
    ksmallestElementSumRec(root, k, sum);
    return sum;
}


// Chương trình driver

int main() {
    Node * root = NULL; // khởi tạo khai bbaos con tror root

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 22);

    int k = 3;
    cout <<"Tổng của k phần tử nhỏ nhất là: "<< ksmallestElementSum(root, k)<<endl; 
    return 0; 

}









