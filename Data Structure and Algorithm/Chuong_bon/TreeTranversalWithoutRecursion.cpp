// Tao ra 1 stack rong
// Khoi tao current note giong nhu root
// Day node hien tai vao stack va di den node left cho den khi node null
// Neu current node dang null va stack ko rng
        // Lay item ra tu stack
        // Hien thi Item vua lay ra duoc, va di den con phai cua no
        // quay lai buoc 3

// Neu current noe dang null va stack dang null thi end luon?.

#include<iostream>
using namespace std;
#include<stack>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data) // wow struct cũng có khởi toạ giống class; --> ko thấy trong slide hay sách có nói đến vấn đê fnayf?. 
    {
        this->data = data;
        left = right = NULL;
    }
};

// duyệt giữa: Tức là cây con trái sau đó đến gốc rồi đến cây con phải?.
//

void inOrder(struct Node *root) {

    stack<Node *> s; // Stack các con trỏ?

    Node *curr = root; // Khai báo và khởi tạo con trỏ curr


// Điều kiện đầu giúp ta in nó ra (Sai) và đi tiếp, đk thứ 2 giúp ta nếu điều kiện đầu ko đúng nũa?.
    while( curr != NULL || s.empty() == false) // Nếu con trỏ đang trỏ đến 1 node nào hoặc stack vẫn còn phần tử?.
    {
            // Đi đến node bên trái nhất
            while(curr != NULL)
            {
                //đặt node này vào stack, sau đó đi đến node tiếp theo?.// Duyệt đến thằng mới nào cũng đặt vào stack cả
                s.push(curr);
                curr = curr->left;
            }
            // Lúc này chắc curr = NULL rồi
            // Pop từ stack ra
            curr = s.top();
            s.pop();
            cout<< curr->data << " "; // Vậy 1 node được xem xét 2 lần, 1 lần khi duyệt, 1 lần khi lấy ra--> lần thứ 2 mơi in
                                    // Vậy tại sao ta ko in khi duyệt luôn mà bỏ vào stack rồi mới in?. 
            // Chúng ta mới chỉ duyệt cây con trái, ta cần duyệt sang cây con phải nữa?.
            curr = curr->right; 
    }
}
// Chương trình driver đế kiểm tra những hàm ở trên
int main() {

    // Khởi tạo 1 cây
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0; 
}


