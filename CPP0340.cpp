#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        string s;
        cin >> s;

        // dp[i][j] trong đó i : 0->m là chữ cái thứ i, và j : 0->n là số dư khi chia cho n 
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[0][(s[0] - '0') % n]++;

        for (int i = 1; i < m; i++) {
            int digit = s[i] - '0';

            dp[i][digit % n]++;

            for (int j = 0; j < n; j++) {
                // xét các xâu trước đó mà chưa tính i
                dp[i][j] += dp[i - 1][j];

                // thêm i vào, tính phần dư mới
                dp[i][(j * 10 + digit) % n] += dp[i - 1][j];
            }
        }
        
        cout << dp[m - 1][0] << endl;; // xuất số dư = 0
    }
}