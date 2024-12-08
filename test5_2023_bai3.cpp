#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) dp[i][j] = a[i][j];
            else if (i == 0) dp[0][j] = dp[0][j - 1] + a[i][j];
            else if (j == 0) dp[i][0] = dp[i - 1][0] + a[i][j];
            else dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + a[i][j]; 
        }
    }

    cout << dp[n - 1][m - 1];
}