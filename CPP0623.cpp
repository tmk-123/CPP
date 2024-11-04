#include<bits/stdc++.h>

using namespace std;

class SV {
public:
    string code, name, grade, email;
};

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

    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        string year = s.substr(2);

        cout << "DANH SACH SINH VIEN KHOA " << s << ":\n";
        for (int i = 0; i < n; i++) {
            if (year == ds[i].grade.substr(1, 2)) {
                cout << ds[i].code << " " << ds[i].name << " " << ds[i].grade << " " << ds[i].email << endl;
            }
        }
    }
}