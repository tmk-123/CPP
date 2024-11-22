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

        long long maxProduct = a[0];
        long long maxCurrent = a[0], minCurrent = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < 0) {
                swap(maxCurrent, minCurrent);
            }
            
            maxCurrent = max(maxCurrent * a[i], a[i]);
            minCurrent = min(minCurrent * a[i], a[i]);
            maxProduct = max(maxProduct, maxCurrent);
        }

        cout << maxProduct << endl;
    }
}
 
// cách dài nhưng AC
// int n;
// cin >> n;
// int a[n];

// for (int i = 0; i < n; i++) cin >> a[i];

// ll max = -100000;

// for (int i = 0; i < n; i++){
//     ll tich = a[i];
//     if (tich > max) max = tich;
//     for (int j = i + 1; j < n; j++){
//         tich *= a[j];
//         if (tich > max) max = tich;
//     }
// }
// cout << max << endl;