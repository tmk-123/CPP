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
        for (int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }

        stringstream ss(s);
        int cnt = 0;
        string word, NGANH;
        while (ss >> word && cnt < 2) {
            cnt++;
            NGANH += word[0];
        }

        cout << "DANH SACH SINH VIEN NGANH " << s << ":\n";
        for (int i = 0; i < n; i++) {
            string industry = ds[i].code.substr(5, 2);

            if (ds[i].grade[0] == 'E' && (industry == "CN" || industry == "AT")) continue;
            if (industry == NGANH) {
                cout << ds[i].code << " " << ds[i].name << " " << ds[i].grade << " " << ds[i].email << endl;
            }
        }
    }
}