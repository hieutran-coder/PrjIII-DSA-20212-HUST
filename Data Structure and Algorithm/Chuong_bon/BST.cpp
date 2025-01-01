// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


//Wow, duyệt ở giữa nó ko chỉ dùng trong thread tree mà nó còn dùng trong

// inorder tranversal
void inorder(struct node *root) {
    if(root!=NULL) {
        // duyệt cây con trái
        inorder(root->left) ;// vây nêu root bằng null thì sao?>
    }

    //Duyệt root?.
    cout << root-> key <<" ->";

    //duyệt phải
    inorder(root->right);

}

// Chèn 1 node
// Sẽ chèn khi con trái và con phải là null??.
struct node *insert(struct node *node, int key) { // chèn vào đâu?.

        // trả về 1 node mới chứa data là key nếu cây rỗng
        if (node == NULL) return newNode(key); 

        // Trường hợp cơ sở là trường hợp nào?.
        // Nếu nó đã thấy được chỗ chèn rồi thì nó sẽ chèn bằng cách nào?. 
        // Việc chèn đó có đòi hỏi phải dịch các node khác nưa ko?. Ko vì nó sẽ phải chèn ở nhánh thôi. 
                            //Thế ko được phép thay đổi cấu trúc cây cũ à?
        // Nêu ko có chỗ để chèn thì sao?. 
        // Nêu thay đổi cấu trúc cây mà vẫn đản bảo cân bằng thì sao?.

        //Duyệt đến nơi bên trái và chèn node
        if(key < node->key) // Nếu key mà bé hơn giá trị gốc thì duyệt bên trái
            node->left = insert(node->left, key); // 
        else
            node->right = insert(node->right, key);

        return node;
}

// Tìm kiếm succesor là thằng đi theo sau trong khi duyệt theo giữa.
//--> Ví đó là thằng nhỏ nhất mà có giá trị lớn hơn mình hay thằng giá trị gần mình nhất. 

// Đây là tìm node giá trị min?. 
struct node *minValueNode (struct node *node ) {
    
    struct node *current = node;

    // tìm kiếm lá ở bên trái nhất
    while(current && current->left != NULL) // Giá trị mà current trả về là gì?. Tại sao cần kiểm tra cả current nữa tức tại sao chỉ kiểm tra current -> left thôi).
        current = current->left;
    // Thoát ra khỏi vòng while khi current = NULL à
        return current;
}

// Xoá 1 node

struct node *deleteNode(struct node *root, int key) {

    // trả về nêu cây là rỗng
    if (root == NULL) return root;

    // Tìm kiểm node cần delete
    if  (key < root->key)
        root->left = deleteNode(root->left, key);// Ta sẽ tìm ở bên trái, đệ quy
            // Tại sao lại cho root-left bằng nhỉ và ko phải chỉ thực hiện delete thôi
    else if(key> root->key)
        root->right = deleteNode(root->right, key);



    else { // lúc này key bằng root-> key rồi phải ko?
        // Nếu 1 node chỉ nuôi 1 con hoặc ko có con--> Tại sao lại có thê gộp 2 trơngf hợp này lại với nahu?. 
       
        if (root->left == NULL){ // ko có con trái
            struct node *temp = root->right; // temp là node con phải?

            free(root); //Thế đáng lẽ cha của root phải được nối với cháu chứ nhỉ?.
            return temp;
        }else if (root->right == NULL){
            struct node *temp = root->left; //
            free(root);
            return temp; // tại sao lại return?. Delete 1 node chứ có bắt return về đâu?. return trả về cây con phải mới cho cha?. 
        }

        // Nếu có đầy đủ cả con trái và con phải
        struct node *temp = minValueNode(root->right); // ta tìm inroder succesor. Tức gía trị bé nhất của cây bên phải?.

        // Thay giá trị tại root
        root->key = temp-> key; // Tại sao cần temp?, mục đích của temp chỉ là như thế này thôi sao?.

        // Đã thay rồi, bây giờ cập nhật cây bằng cách xoá bản cũ
        root->right = deleteNode(root->right, temp->key); 

    }
}

// Code điều khiển

int main() {
    struct node *root = NULL;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);



    cout<<"Inoder traversal";
    inorder(root);

    cout<< " Sau khi xoá node 10";
    root = deleteNode(root,8);

    cout <<"Inorder Travesal: ";
    inorder(root); 

}