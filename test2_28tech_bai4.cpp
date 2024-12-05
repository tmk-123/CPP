#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int remainder = 0;
    int n = 0;
    for (char c : s) {
        n = n * 2+ (c - '0');
        n %= 5;
    }

    if (n == 0) cout << "YES";
    else cout << "NO";
}