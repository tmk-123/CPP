#include<bits/stdc++.h>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                cnt++;
                n /= i;
                if (cnt == k) {
                    cout << i;
                    return 0;
                }
            }
        }
    }

    if (n > 1 && k - cnt == 1) cout << n;
    else cout << -1;
    return 0;
}