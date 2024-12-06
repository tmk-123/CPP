#include<bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, int> NTK;
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        int n;
        cin >> n;

        NTK[s] = n;
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        long PTK = 0;
        int digitIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                string atom = s.substr(digitIndex, i - digitIndex);
                PTK += NTK[atom] * (s[i] - '0');
                digitIndex = i + 1;
            }
        }

        cout << PTK << endl;
    }
}