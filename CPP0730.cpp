#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long currentSum = a[0];
        long long maxSum = a[0];
        
        for (int i = 1; i < n; i++) {
            currentSum = max(a[i], currentSum + a[i]);
            maxSum = max(currentSum, maxSum);
        }

        cout << maxSum << endl;
    }
}