#include<bits/stdc++.h>

using namespace std;

class Student {
public:
    string msv, name, bd, lop;
    double gpa;

};

bool compare(Student a, Student b) {
    if (a.gpa == b.gpa) return a.msv < b.msv;
    return a.gpa > b.gpa;
}
int main() {
    int n;
    cin >> n;
    Student ds[n];

    for (int i = 0; i < n; i++) {
        string s = to_string(i + 1);
        ds[i].msv = "SV" + string(3 - s.length(), '0') + s;
        getline(cin >> ws, ds[i].name);
        cin >> ds[i].lop >> ds[i].bd >> ds[i].gpa;

        if (ds[i].bd[1] == '/') ds[i].bd.insert(0, "0");
        if (ds[i].bd[4] == '/') ds[i].bd.insert(3, "0");

        stringstream ss(ds[i].name);
        string word, t;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); i++) {
                word[i] = tolower(word[i]);
            }
            t += word;
            t += " ";
        }
        t.pop_back();
        ds[i].name = t;
    }

    sort(ds, ds + n, compare);

    for (int i = 0; i < n; i++) {
        cout << ds[i].msv << " " << ds[i].name << " " << ds[i].lop << " " << ds[i].bd << " " << fixed << setprecision(2) << ds[i].gpa << endl; 
    }
}