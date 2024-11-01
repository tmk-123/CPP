#include<bits/stdc++.h>

using namespace std;

int cnt = 1;

class SinhVien{
public:
    string name, grade, bd, id;
    double gpa;
    
    friend istream& operator >> (istream &in, SinhVien &a){
        getline(in, a.name);
        getline(in, a.grade);
        getline(in, a.bd);
        in >> a.gpa;
        a.id = "B20DCCN" + string(3 - to_string(cnt).length(), '0') + to_string(cnt++);
        if (a.bd[1] == '/') a.bd.insert(0, "0");
        if (a.bd[4] == '/') a.bd.insert(3  , "0");
        return in;
    }
    friend ostream& operator << (ostream &out, SinhVien &a){
        out << a.id << " " << a.name << " " << a.grade << " " << a.bd << " " << fixed << setprecision(2) << a.gpa;
        return out;
    }
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}