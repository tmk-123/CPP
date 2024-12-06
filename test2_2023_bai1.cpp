#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[n + 1];
    a[1] = 1, a[2] = 1; 
    for (int i = 3; i <= n; i++) {
        a[i] = 2 * a[i - 1] + 3 * a[i - 2];
        a[i] %= 1000000007;
    }

    cout << a[n];
}