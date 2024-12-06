#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long step = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            int diff = (a[i - 1] - a[i]) / d + 1;
            a[i] += diff * d;
            step += diff;
        }
    }

    cout << step;
}