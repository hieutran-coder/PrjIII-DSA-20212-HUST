#include<functional> 
#include<queue>
#include<vector>
#include<iostream>
#include <initializer_list>
template<typename T> // Dòng này để làm gì?. 1. Để khai báo 1 kiểu template hay sao??

void print_queue(T q){ // passing by value--> Sử dụng bản copy thôi.
    // Trong trường hợp q khác rỗng?.
    
    while(!q.empty()) {
            std:: cout << q.top() << ' '; // Hiện thị phần tử đầu q
            q.pop(); // và lấy phần tử đầu tiên ra
    }
    std::cout << '\n'; 
}

int main() {
    std::priority_queue<int> q;

    const auto data = {1,8,5,2,3,4,6,1,1,2,5}; // data này là kiểu mảng hay sao??. hay kiểu gì

    for (int n: data) q.push(n); // đặt n vào priority queue.

    print_queue(q); //truyền q vào?. 

    //sử dụng lambda để so sánh các phần tử:
    auto cmp = [](int left, int right){
        return(left ^1)<(right^1);};
    
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n: data) q3.push(n); // Đặt n vào

    print_queue(q3);

}
