#include<iostream>
#include<string>
using namespace std;



// Struct có vẻ được dùng trong nhiều cái nhỉ!. 
struct Node{
    int id;
    // Tại sao cây lưu 2 thông tin này mà ko lưu những thông tin khac?
    Node* leftMostChild; // Con bên trái nhất
    Node* rightSibling;
    // NẾu là cây nhị phân thầy sẽ lưu theo kiểu khác?. 
};

Node* root; // trỏ đến nút gốc

// finding node have label. 

// HÌnh như quy luật tìm là đi từ gốc đến trái rồi đến phải phải ko?
Node* find(Node* r, int v) {
    if( r== NULL) return NULL; // KIểm tra cây có rỗng hay ko, r là gốc nhỉ?. 
    /// Khi nào ta cần kiểm tra r == null hay ko?. nếu bỏ lênh này thì sao?.
            // Ko được. đây ko phải trường hợp cơ sở?. mà trường hợp đầu tiên luôn?. 

    if(r->id == v) return r; // Đây là trường hợp cơ sở. NÓ sẽ đi đệ quy đến nút lá?. con trái của lá bằn null tức p bằng null --> retunr về là null

    Node* p = r->leftMostChild; // Đi đến cây con trái. 



    // Khi nào thì p = NULL?, điều gì khiến p = NULL? -> khi trước đó đến nút lá rồi.
    while(p != NULL){
        Node* h = find(p,v); // sử dụng đệ quy trong cây?. // Đây là bài toán con, vây trường hợp cơ sở là gì?. 
            //DĐã find(p,v)--> p là gốc và và p khác NULL. Khi đệ quy thì lệnh if đầu tiên luôn PassK?. 

        if(h != NULL) return h; // Trả về node đó khi tìm được nút đó. KO thực hiện lệnh sang trái anh em nữa?. 
                                // Đây là trường hợp cơ sở?. 
        
        // Nếu h= NULL--> Cái nhánh đi vào chắc chắn phải ko tìm được v?.
        // Nếu h khác NULL--> Cái nhánh đi vào chắn đã tìm được nút chứa dữ liệu v
        p = p ->rightSibling; 
    }


    return NULL;// trong trường hợp nút p =NULL, hay trỏ đến con của lá?. đây là trường hợp cơ sở phải không?. 

}

// DUyệt cây theo thứ tự trước
void preOrder(Node* r) {
    if(r == NULL) return; // Trường hợp cơ sở phải ko?. 
    
    printf("%d", r->id); // output giá trị tại nút đó

    Node* p = r->leftMostChild; // Trỏ đến con trái nhất

// Kiểm tra p ! =null có khác gì kiểm tra r bằng null hay ko?. 
    while( p != NULL) {
        preOrder(p);
        // Sau khi duyệt hết nhánh bên p rồi thì duyệt sang các nhánh khác
        p = p->rightSibling;
    }
    // Ko cần return false nữa giống như hàm find trên nhỉ? 
}

void inOrder(Node* r) {
    
    if(r == NULL) return;

    Node* p = r->leftMostChild;


// Duyệt sang trái?. Con trái của r
    inOrder(p);  // Tại sao lại inOrder P ở thời diểm này?. BỎ lệnh này ở đây đi d có được o?. 
  
  // Hiện thị r. 
    printf("%d", r->id);

    // 2 lệnh p = p -> RightSibling có khác gì nhau?. Tại sao cần đến 2 lệnh này?.
            //Lệnh đầu tiên NẾu ko có anh em thì nó sẽ NULL--> KO duyệt vòng while nữa?. và đi hết inOrder()
    
    // Duyệt anh em của p, hay con phải của r
    if(p != NULL) // Tại sao lại cần phải kiểm tra?> trường hợp nào p = NULL và nhảy đến câu lệnh này?. 
        p = p->rightSibling;

    while(p != NULL) {
        inOrder(p); // inOder này khác inOrder ở trên ở chỗ nào?. 
                            //Ở chỗ ở trên là duyệt sang con trái, ở đây là duyệt anh em, không sure lắm.
        p = p->rightSibling; // Nếu bỏ câu lệnh này đi có được ko?.
    }

}

void postOrder(Node* r) {
    if( r== NULL) return; // câu lệnh này cả 3 cách duyệt đều có; đây là trường hộp cơ sở.

    Node* p = r->leftMostChild; // Đi đến con trái?

    while(p!= NULL) { // kiểm tra con trái có NULL ko?
        postOrder(p); // duyệt con trái
        p = p->rightSibling; // tiếp tục duyệt con phải
    }
    printf("%d", r->id);

}

// Làm sao để đểm số nút trên cây-> Duyệt theo 3 cách rồi cout thôi thay cho print?. Giải quyết vấn đề đếm bằng tái sử dụng code của duyệt
// PreORder
int count(Node* r) {
    if( r== NULL) return 0; // không có trường hợp nào trong khi duyệt return từ câu lệnh này phải ko?. Chỉ khi gốc ban đầu chứ ko phải gốc theo đê quy?.
                        // Chú ý ở trên là return còn đây là return 0;  BỎ lệnh này cũng được. 
    int s = 1; // Trường hợp cơ sở nè?. 

    Node* p = r->leftMostChild; // duyệt đến con trái?. Tất cả thằng có con trái đều phải qua lệnh này?. và duyệt đến con trái chỉ có lệnh này?. 

    while(p != NULL) {// Câu lệnh này để kiểm tra có phải là lá ko?. 
         s += count(p); // Gọi đến Bài toán con và thực hiện luôn bước tổng hợp bài toán của mô hình đệ quy ? ; con trái và con phải return về cho r là s
         p = p->rightSibling;
    }
}


// Cout number leaves in trees.
int countLeaves(Node* r) {
    if( r== NULL) return 0;

    int s = 0;

    Node* p = r->leftMostChild;

    if(p == NULL) s = 1; // nếu r ko có con thì r là leaves?. s= 1;

    while(p != NULL) {
        s += countLeaves(p); // tương tự count trên
        p = p->rightSibling;
    }
    return s; 
}   




int height(Node* p) {  // Ko cần care đến gốc luôn.
    if(p == NULL) return 0;
    int maxh = 0; // tại sao là maxh?. max của các nhánh khác nhau phải không?. 

    Node* q= p ->leftMostChild;

    while(q != NULL){
        int h = height(q); // Con trái vào con phải return về cho thằng p là h?. 
        if(h> maxh) maxh = h; // Càng left thì kiểu gì chả lớn hơn?. Sao phải xét if ?. Bởi sang nhánh khác thì nó có thể thấp hơn, khá giống nhánh cận nhỉ.
                // Lối tư duy ở đây là chắc là lấy max con trái và con phải?. Còn có mục đích khác nữa ko?. 
        q = q->rightSibling; // Duyệt bên phải .q trở thành các con tiếp theo rồi?. 

    }
    return maxh + 1; // Tại sao phải +1?. Nếu ko thì ko tăng được?. return về cho ai?. --> cho cha?. cho hàm đệ quy trước đó?. 

}


int depth(Node* r, int v, int d) { // v là gì?. 
    // d là độ sâu nút r--> r không phải nút gốc hay sao?.
                // v là giá trị của nút nằm sâu hơn nút r?. ko phải, rằng ta sẽ tìm v ở mức sâu d
                 // Vậy thì lúc đầu ta tìm nút chứa nhãn v sau thì đi ngược tìm cha?. cũng là 1 cách?. 
  
    if( r== NULL) return -1; // 
    if( r->id == v) return d; // giá trị của r là v thì return là độ sâu

    Node* p = r->leftMostChild; // Trỏ đến phần tử child bên trái

    while(p != NULL) {
        if(p->id == v) return d+1;   // sâu thêm 1 tầng

        int dv = depth(p,v,d+1); // đệ quy; dv là local variable của rất nhiều hàm?. 1 lần của con trái nhất, và có thể nhiều lần của anhem


        if(dv>0) return dv; // ko thực hiện sang phải nữa à?. 
        p = p -> rightSibling;  // dv nhỏ hơn 0? để thực hiện lệnh này?. Vậy khi nào dv<0?. khi dv = -1, hay là  cây con trái ko tìm được v?.

    }
    return -1; 
}

int depth(Node* r, int v) {
    return depth(r,v,1); 
}


// Ý tưởng giống hệt bài depth phải không ?. 
Node* parent(Node* p, Node* r) {  // Đầu vào là 2 Con trỏ và trả về cũng là con trỏ?. 

    if( r== NULL) return NULL; // Cho dù ko return hay return null hay return -1, thì đều có bước kt này

    Node* q = r->leftMostChild; // khi nào vào thời điểm này cũng có bước này?.

    while( q != NULL) {     // Khi nào cũng có cái lệnh này?. 
        if( p == q ) return r; // nếu p là q thì return là cha, trường hợp cơ sở
        // Nếu q ko phải là con
        Node* pp = parent(p,q); // đệ quy ko phải r là nút gốc mà q là nút gốc?.
        if( pp != NULL) return pp; // 
        q = q->rightSibling; // pp = null hay nhánh cũ ko tìm ra parent cho con p lúc đầu?. 

    }
    return NULL;
}
