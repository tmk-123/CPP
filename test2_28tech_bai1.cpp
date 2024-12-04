#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long ans = n;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int mu = 0;
            while (n % i == 0) {
                mu++;
                n /= i;
            }
            if (mu % 2 == 1) ans *= i;
        }
    }

    if (n > 1) ans *= n;
    cout << ans;
}