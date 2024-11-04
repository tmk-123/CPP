#include<bits/stdc++.h>

using namespace std;

class SV {
public:
    string code, name, grade, email;
    friend istream& operator >> (istream &in, SV &a) {
        getline(cin >> ws, a.code);
        getline(cin >> ws, a.name);
        getline(cin >> ws, a.grade);
        getline(cin >> ws, a.email);

        return in;
    }
};

bool compare(SV a, SV b) {
    return a.code < b.code;
}

int main() {
    SV *ds = new SV[1000];
    int n = 0;

    while (cin >> ds[n++]) {
    }

    sort(ds, ds + n, compare);

    for (int i = 0; i < n; i++) {
        cout << ds[i].code << " " << ds[i].name << " " << ds[i].grade << " " << ds[i].email << endl;
    }

    delete [] ds;
}