#include<bits/stdc++.h>

using namespace std;

int cnt = 1;

class NhanVien {
public:
    string name, gender, bd, address, idTax, contract;

    friend istream& operator >> (istream &in, NhanVien &a) {
        getline(in >> ws, a.name);
        getline(in >> ws, a.gender);
        getline(in >> ws, a.bd);
        getline(in >> ws, a.address);
        getline(in >> ws, a.idTax);
        getline(in >> ws, a.contract);

        return in;
    }

    friend ostream& operator << (ostream &out, NhanVien &a) {
        out << setfill('0') << setw(5) << cnt++ << " "
            << a.name << " "  << a.gender << " "
            << a.bd << " " << a.address << " "
            << a.idTax << " " << a.contract << endl;
        
        return out;
    }
};

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}