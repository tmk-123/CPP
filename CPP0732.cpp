#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> dp(a.begin(), a.end());
        dp[0] = a[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++  ) {
                if (a[i] > a[j]) {
                    dp[i]= max(dp[j] + a[i], dp[i]);
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end())  << endl;
    }
}