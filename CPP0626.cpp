#include<bits/stdc++.h>

using namespace std;

class GV {
public:
    int code;
    string name, subject, sb, lastName;
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
    
    return word;
}

int main () {
    int n;
    cin >> n;

    GV ds[n];
    for (int i = 0; i < n; i++) {
        ds[i].code = i + 1;
        getline(cin >> ws, ds[i].name);
        getline(cin >> ws, ds[i].subject);

        ds[i].lastName = formatStr(ds[i].name);
        
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
        stringstream ss(s);
        string word, sb;

        while (ss >> word) {
            word[0] = toupper(word[0]);
            sb += word[0];
        }

        cout << "DANH SACH GIANG VIEN BO MON " << sb << ":\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].sb == sb) {
                cout << "GV" << setfill('0') << setw(2) << ds[i].code << " "<< ds[i].name << " " << ds[i].sb << endl;
            }
        }
        
    }
    
}