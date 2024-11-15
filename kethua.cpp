#include <bits/stdc++.h>

using namespace std;

class Diem {
public:
    int x, y;

    Diem(int x = 0, int y = 0) : x(x), y(y) {};
    void hienThi() {
        cout << "(" <<  x << "," << y << ")";
    }

};
class HinhTron : public Diem {
public:
    int r;
    HinhTron(int x, int y, int r) : Diem(x, y), r(r) {}

    void hienThi() {
        Diem::hienThi();
        cout << " " << r;
    }
};

class HinhTru : public HinhTron {
public:
     int h;
     HinhTru(int x = 0, int y = 0, int r = 0, int h = 0) : HinhTron(x, y, r), h(h) {}
     void hienThi () {
        HinhTron::hienThi();
        cout << " " << h;
     }
     void nhap() {
        cin >> x >> y >> r >> h;
     }
};

int main(){
     HinhTru a;
     a.nhap();
     a.Diem::hienThi(); cout<<endl;
     a.HinhTron::hienThi(); cout<<endl;
     a.HinhTru::hienThi();cout<<endl;
  return 0;
 }