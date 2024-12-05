#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int minDiff = 1e9;
    for (int i = 0; i <= n - k; i++) {
        minDiff = min(a[i + k - 1] - a[i], minDiff);
    }

    cout << minDiff;
}