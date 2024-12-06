#include<bits/stdc++.h>

using namespace std;

int main() {
    long n;
    cin >> n;

    long snt, mu = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int cnt = 0;

            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            
            if (mu < cnt) {
                mu = cnt;
                snt = i;
            }
        }
    }

    if (n > 1 && mu < 1) {
        snt = n;
        mu = 1;
    }

    cout << snt << " " << mu;
}