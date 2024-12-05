#include<bits/stdc++.h>

using namespace std;

int n;
int a[101][101];
int maxPath;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (j == 0) dp[i][j] += a[i][j];
            else if (i == 0) dp[i][j] += max(dp[0][j - 1], dp[1][j - 1]) + a[i][j];
            else if (i == n - 1) dp[i][j] += max(dp[i - 1][j - 1], dp[i][j - 1]) + a[i][j];
            else dp[i][j] += max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];

            if (j == n - 1) maxPath = max(maxPath, dp[i][j]);
        }
    }

    cout << maxPath;
}