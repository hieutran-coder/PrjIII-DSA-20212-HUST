#include<iostream>
#include<queue>
using namespace std;

class Plane {
    public: int fuel;
    
    public: Plane(int q) {
        (*this).fuel = fuel;
    }
    // Dấu này có nghĩa là gì?.
    friend ostream& operator<<(ostream& os, const Plane& p){  // chữ kí này có nghĩa là gì?.  Đầu vào, đầu ra đều là referene, có const reference
        os<<p.fuel<<endl;
         return os;
    } 
    // Hiện thị ra fuel của plan ??--> DDoán dung roi

    // oveloading > nay voi doi tuong tham chieu p
    bool operator>(const Plane& p) const {
        return fuel>p.fuel; // so sánh xem
    }
};

// Cấu trúc tham số này có nghĩa là gì? 
typedef priority_queue<Plane, vector<Plane>, greater<Plane> > PQPlane; // Đổi tên type, hay class

int main() {
    vector<Plane> vP;
    vP.push_back(Plane(4));
    vP.push_back(Plane(3));
    vP.push_back(Plane(7));
    vP.push_back(Plane(9));

    PQPlane PQ(vP.begin(), vP.end()); 

    while( !PQ.empty()) {
        cout<< PQ.top().fuel<<endl;
        PQ.pop();
        }
}

