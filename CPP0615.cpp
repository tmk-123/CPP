#include<bits/stdc++.h>

using namespace std;

int cnt = 1;

class NhanVien {
public:
    string id, name, gender, bd, address, idTax, contract, birthday;

    friend istream& operator >> (istream &in, NhanVien &a) {
        a.id = string(5 - to_string(cnt).length(), '0') + to_string(cnt);
        cnt++;
        getline(in >> ws, a.name);
        getline(in >> ws, a.gender);
        getline(in >> ws, a.bd);
        getline(in >> ws, a.address);
        getline(in >> ws, a.idTax); 
        getline(in >> ws, a.contract);

        a.birthday = a.bd.substr(6, 4) + a.bd.substr(0, 2) + a.bd.substr(3, 2);
        return in;
    }

    friend ostream& operator << (ostream &out, NhanVien a) {
        out << a.id << " " << a.name << " "  << a.gender << " " << a.bd
            << " " << a.address << " " << a.idTax << " " << a.contract << endl;
        
        return out;
    }
};

bool compare(NhanVien a, NhanVien b) {
    return a.birthday < b.birthday;
}
void sapxep(NhanVien ds[], int n) {
    sort(ds, ds + n, compare);
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}