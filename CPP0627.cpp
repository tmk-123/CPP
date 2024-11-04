#include<bits/stdc++.h>

using namespace std;

class GV {
public:
    int code;
    string name, subject, sb, tolowerName;
};

string formatStr(string &s) {
    stringstream ss(s);
    string word, temp;

    while (ss >> word) {
        word[0] = toupper(word[0]);

        for (int i = 1; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }

        temp += word;
        temp += " ";
    }

    temp.pop_back();
    s = temp;
    temp = "";

    for (int i = 0; i < s.length(); i++) {
        temp += towlower(s[i]);    
    }

    return temp;
}

int main () {
    int n;
    cin >> n;

    GV ds[n];
    for (int i = 0; i < n; i++) {
        ds[i].code = i + 1;
        getline(cin >> ws, ds[i].name);
        getline(cin >> ws, ds[i].subject);

        ds[i].tolowerName = formatStr(ds[i].name);
        
        stringstream ss(ds[i].subject);
        string word;

        while (ss >> word) {
            word[0] = toupper(word[0]);
            ds[i].sb += word[0];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        string temp = s;

        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }

        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << temp << ":\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].tolowerName.find(s) != string::npos) {
                cout << "GV" << setfill('0') << setw(2) << ds[i].code << " "<< ds[i].name << " " << ds[i].sb << endl;
            }
        }
        
    }
    
}