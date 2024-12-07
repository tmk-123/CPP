#include<bits/stdc++.h>

using namespace std;

int main() {
    string t;
    cin >> t;

    string s;
    string max_s;
    for (char c : t) {
        if (isdigit(c)) {
            s.push_back(c);
            while (s[0] == '0') s.erase(0, 1);
            if (s.length() > max_s.length() || (s.length() == max_s.length() && s > max_s)) {
                max_s = s;
            }
        }
        else s = "";
    }

    if (max_s == "") cout << "0";
    else cout << max_s; 
}