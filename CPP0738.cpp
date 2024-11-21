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

        int remainder = 0, maxCount = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (a[i] > 0) {
                if (a[i] % 2 == 0) {
                    a[i] /= 2;
                    cnt++;
                }
                else {
                    remainder++;
                    a[i]--;
                }
            }
            maxCount = max(maxCount, cnt);
        }
        
        cout << maxCount + remainder << endl;
    }
}