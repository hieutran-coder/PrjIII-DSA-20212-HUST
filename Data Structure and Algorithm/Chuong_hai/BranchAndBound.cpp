#include<iostream>
using namespace std;

 int f = 0;
int n = 10;
int f_min = 999999;
bool marked[10];
int x[10];
int cmin = 1;
int c[10][10] = {{1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1},
                    {1,2,3,4,5,6,7,2,1,1}};


void process() {
    if(f + c[x[n]][x[1]] < f_min) {
        // Tính xem nhánh đi đến tân cùng có bé thua f_min hay ko?. 
        f_min = f + c[x[n]][x[1]];
    }
}
// Cận trong nhánh cận có nghĩa là chặn dưới?. Chặn dưới mà lớn hơn min đang có đang có thì ko cần duyệt nhánh đó nữa. 
// Có 1 điểm chưa hiểu là cái cận đó ảo vcl?. Lấy min của tất cả quãng đường?.
        // Vậy thì có trường hợp nào cận này giúp ta BỚT DUYỆT hơn ko?.
        // Cần 1 ví dụ???> 
void TRY(int k) {
    for(int v = 1; v <= n; v++) {
        // Chả lẽ với mỗi thời điểm cũng duyệt từ 1/ n hay sao?.// Chắck phải có check?. Mà check ở đây là check xem có trùng cái ở trước ko?
        // Bài này lấy ý tưởng khá giống bài toán hoán vị của thầy
        if(marked[v] == false){     // Kiểm tra xem thành phố này đã duyệt qua chưa, tránh lặp lại khi duyệt?. 
            x[k] = v;       // Đi theo nhánh này
            f = f + c[x[k-1]][x[k]]; // Tổng sẽ tăng thêm 1 đoạn từ thành phố a[k-1] đến thành phố a[k]
            // f_min khác gì f: f là số được xây dựng qua 1 nhánh, f_min là giá trị min của mọi nhánh xây dựng được đến hiện tại
        }
        if(k==n){
            process();
        }else{
            // Người ta xác định cận dưới tại mỗi thời điểm xây dựng như thế nào?. 
            int g = f+ cmin*(n-k+1); 
            // Tính g làm cái gì?. g là cận dưới của nhánh này? 
                        // Với mỗi k ta có 1 f mới và 1 g mới nhỉ?.
                    // Nếu cận dưới của nhánh này hơn min--> Tức là cho dù đi sâu thì cũng ko làm nó đủ nhỏ hơn thằng min hiện tại.
                     // Nếu cận dưới nhỏ hơn min tức là có khả năg nhánh này có thể xuống nhỏ hơn f_min?. ---> Cứ đi tiếp nhánh này xem sao?.

            if(g < f_min)
                TRY(k+1); // Đi sâu đến điểm tiếp theo của nhánh
        }

        marked[v] = false; // Đã đi xong nhánh này bây giờ sẽ phải duyệt nhánh khác?.Thì đưa nó về trạng thái trước khi vào nhánh này.
                           // Ta đã thay đổi 2 giá trị mark và f, phải đem nó quay trở lại
        f = f - c[x[k-1]][x[k]];
    }
}



int main()
{
    for(int v = 1; v<= n; v++)
        marked[v] = false;
    x[1] = 1; marked[1] = true;

    TRY(2);
}

