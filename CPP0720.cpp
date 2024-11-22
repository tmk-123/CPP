#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> increasing(n, 1), decreasing(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    increasing[i] = max(increasing[i], increasing[j] + 1);
                }
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (a[j] < a[i]) {
                    decreasing[i] = max(decreasing[i], decreasing[j] + 1);
                }
            }
        }
        
        int maxBitonic = 1;
        for (int i = 0; i < n; i++) {
            maxBitonic = max(maxBitonic, increasing[i] + decreasing[i] - 1);
        }

        cout << maxBitonic << endl;
    }
}