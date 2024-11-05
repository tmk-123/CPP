#include<bits/stdc++.h>

using namespace std;

// histogram

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        int dp[n][m]; // mảng lưu cạnh lớn nhất hình vuông
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) dp[i][j] = a[i][j];
                else {
                    if (a[i][j] == 0) dp[i][j] = 0;
                    else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        cout << ans << endl;
    }
}