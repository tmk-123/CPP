#include<bits/stdc++.h>

using namespace std;

int cnt = 1;

class SinhVien{
public:
    string name, grade, bd, id;
    double gpa;
    
    void nhap(){
        getline(cin, name);
        getline(cin, grade);
        getline(cin, bd);
        cin >> gpa;
        id = "B20DCCN" + string(3 - to_string(cnt).length(), '0') + to_string(cnt++);
        if (bd[1] == '/') bd.insert(0, "0");
        if (bd[4] == '/') bd.insert(3  , "0");
    }
    void xuat(){
        cout << id << " " << name << " " << grade << " " << bd << " " << fixed << setprecision(2) << gpa;
    }
};

int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}