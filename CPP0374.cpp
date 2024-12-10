#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> dpA(n, 0); // số bước đổi thành full A
    vector<int> dpB(n, 0);
    if (s[0] == 'A') dpA[0] = 0;
    else dpA[0] = 1;

    if (s[0] == 'B') dpB[0] = 0;
    else dpB[0] = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'A') {
            dpA[i] = min(dpA[i - 1], dpB[i - 1] + 1);
            dpB[i] = min(dpA[i - 1] + 1, dpB[i - 1] + 1);
        }
        else {
            dpA[i] = min(dpA[i - 1] + 1, dpB[i - 1] + 1);
            dpB[i] = min(dpA[i - 1] + 1, dpB[i - 1]);
        }
    }

    cout << dpA[n - 1];
}