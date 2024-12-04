#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    string dp[n][n];
    if (a[0][0] == '1') dp[0][0] = "1";
    else dp[0][0] = "0"; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == 0) dp[i][j] = dp[i - 1][j] + a[i][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    string res = dp[n - 1][n - 1];
    while (res.size() > 1 && res[0] == '0') res.erase(0, 1);
    while (res.size() % 4 != 0) res.insert(0, "0");
    for (int i = 0; i < res.size(); i += 4) {
        int x = (res[i] - '0') * 8 + (res[i + 1] - '0') * 4 + (res[i + 2] - '0') * 2 + (res[i + 3] - '0');
        if (x < 10) cout << x;
        else cout << char((x % 10) + 'A');
    }
}