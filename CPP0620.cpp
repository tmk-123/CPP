#include<bits/stdc++.h>

using namespace std;

class SV {
public:
    string code, name, grade, email;
};

bool compare(SV a, SV b) {
    if (a.grade == b.grade) return a.code < b.code;
    return a.grade < b.grade;
}

int main() {
    int n;
    cin >> n;
    SV ds[n];

    for (int i = 0; i < n; i++) {
        getline(cin >> ws, ds[i].code);
        getline(cin >> ws, ds[i].name);
        getline(cin >> ws, ds[i].grade);
        getline(cin >> ws, ds[i].email);
    }

    sort(ds, ds + n, compare);

    for (int i = 0; i < n; i++) {
        cout << ds[i].code << " " << ds[i].name << " " << ds[i].grade << " " << ds[i].email << endl;
    }
}