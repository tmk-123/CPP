#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    map<int, int> m;
    for (auto x : freq) {
        m[x.second]++;
    }
    if (m.size() > 2) cout << "29tech";
    else if (m.size() == 1) cout << "28tech";
    else {
        int a1 = -1, a2 = -1, b1 = -1, b2 = -1;
        for (auto x : m) {
            if (a1 == -1) {
                a1 = x.first;
                a2 = x.second;
            }
            else {
                b1 = x.first;
                b2 = x.second;
            }
        }
        
        if (abs(a1 - b1) == 1 && (a2 == 1 || b2 == 1)) cout << "28tech";
        else if ((a1 == 1 && a2 == 1) || (b1 == 1 && b2 == 1)) cout << "28tech";
        else cout << "29tech";
    }
}