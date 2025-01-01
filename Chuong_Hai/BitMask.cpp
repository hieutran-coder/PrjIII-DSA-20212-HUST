 #include<iostream>

using namespace std;
#include<vector>; 
// #define LOG_ERRORS 1 // 2^0, bit 0
// #define LOG_WARNINGS 2 // 2^1, bit 1
// #define LOG_NOTICES 4// 2^2, bit 2
// #define LOG_INCOMING 8// 2^3, bit 3
// #define LOG_OUTGOING  16
// #define LOG_LOOPBACK 32

// //chỉ có 6 cờ/ bit; thế nên kiểu char là đủ
// int main() {
// unsigned char flags;

// // Khởi toạ flags
// flags = LOG_ERRORS; // set 1 tu bit 0

// //Khởi tạo rất nhiều values với OR
// flags = LOG_ERRORS| LOG_WARNINGS|LOG_INCOMING;
// // set các bit 1+2+8 hay bits 0,1,3

// // set 1 cờ bật, các cờ khác giữ nguyên
// flags |= LOG_INCOMING;

// //kiểm tra 1 flag
// if((flags& LOG_WARNINGS)==LOG_WARNINGS){

// };

// // kiểm tra 1 lần nhiều flag
// if((flags&(LOG_INCOMING| LOG_OUTGOING)) == (LOG_INCOMING|LOG_OUTGOING));
// //loại bỏ 1 flag, phần còn lại thì giữ nguyên
// flags&= ~LOG_OUTGOING;

// //lât 1 flag
// flags^= LOG_LOOPBACK; 
// }

// Tỉnh tổng tất cả các số của tất cả tập con
int sum_of_all_subset( vector<int> s) {
    int n = s.size();
    int results[(1<<n)]; // Con số này thì có nghĩa là gì?. 1 dịch trái n lần

    // khởi tạo mảng result thành 0
    memset(results, 0, sizeof( results));

    // Duyệt qua tất cả các subsets

    for(int i = 0; i <(1<<n); ++i){ 
        for(int j = 0; j <n; j++) // xét các phần tử
            if((i&(1<<j)) != 0) 
                results[i] += s[j]; // với một tập thì check xem phần tử nào thuộc, phần tử nào không thuọcc, nếu thuộc thì sẽ cộng và results?.
    }
}
