#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        long long sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum = sum * 10 + s[i] - '0';
            sum %= n;
        }

        cout << __gcd(sum, n) << endl;
    }
}