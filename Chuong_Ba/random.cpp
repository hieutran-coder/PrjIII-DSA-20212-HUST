// Ví dụ random: Đoán số

#include<stdio.h> // Thư viện printf, scanf, puts, null
#include<stdlib.h>  //srand, rand
#include<time.h>

// Nhuoc diem la no lang nhang qua den 3 ham
int main() {

    int iSecret,iGuess;

    // khoi tao random seed
    srand(time(NULL));

    // Khoi tao 1 so trong khoang 1 den 10
    iSecret = rand()%10 + 1;

    do {
        printf(" Đoán số từ 1 đến 10 ");
        scanf("%d", &iGuess); // Đọc vào biến iGuess;

        if(iSecret < iGuess) puts("Số bí nhật là số bé hơn");
        else if (iSecret> iGuess) puts("Số bí mật là số lớn hơn");
    } while(iSecret != iGuess); 

    puts("Chúc mừng !");
    return 0; 
}


