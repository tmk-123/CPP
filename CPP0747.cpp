#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int cnt = 0;
        while (s.find("100") != string::npos) {
            cnt += 3;
            s.erase(s.find("100"), 3);
        }
        if (cnt) cout << cnt << endl;
        else cout << endl;
    }
}