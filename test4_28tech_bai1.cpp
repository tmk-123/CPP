#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "28tech " << 0;
            return 0;
        }
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    freq[i]++;
                    x /= i;
                }
            }
        }
        if (x > 1) freq[x]++;
    }

    long res = 1;
    for (auto x : freq) {
        if (x.second % 2 == 1) {
            cout << "29tech";
            return 0;
        }
        x.second /= 2;
        while (x.second > 0) {
            res *= x.first;
            res %= mod;
            x.second--;
        }
    }
    cout  << "28tech " << res;
    return 0;
}