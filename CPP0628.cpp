#include<bits/stdc++.h>

using namespace std;

class Company {
public:
    string code, name;
    int quantity;
};

bool compare(Company a, Company b) {
    if (a.quantity == b.quantity) return a.code < b.code;
    return a.quantity > b.quantity;
}

int main() {
    int n;
    cin >> n;
    Company ds[n];

    for (int i = 0; i < n; i++) {
        getline(cin >> ws, ds[i].code);
        getline(cin >> ws, ds[i].name);
        cin >> ds[i].quantity;
    }

    sort(ds, ds + n, compare);
    
    for (int i = 0; i < n; i++) {
        cout << ds[i].code << " " << ds[i].name << " " << ds[i].quantity << endl;
    }
}