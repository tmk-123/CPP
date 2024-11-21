#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long maxSum = 0;
        for (int i = 0; i < k; i++) {
            maxSum += a[i];
        }
        
        int start = 0;
        long long currentSum = maxSum;

        for (int i = 1; i + k <= n; i++) {
            currentSum += a[i + k - 1] - a[i - 1];
            if (maxSum < currentSum) {
                start = i;
                maxSum = currentSum;
            }
         }

        for (int i = start; i < start + k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}