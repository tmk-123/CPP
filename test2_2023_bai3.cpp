#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int freq[101] = {0};
    for (int j = 0; j < n; j++) freq[a[0][j]] = 1;

    for (int i = 1; i < n; i++) {
        int curr[101] = {0};
        for (int j = 0; j < n; j++) {
            if (freq[a[i][j]] == i) {
                curr[a[i][j]] = 1;
            }
        }

        for (int k = 0; k < 101; k++) {
            if (curr[k] == 1) {
                freq[k]++;
            }
        }
    }

    bool found = false;
    for (int i = 0; i < 101; i++) {
        if (freq[i] == n) {
            found = true;
            cout << i << " ";
        }
    }

    if (found == 0) cout << "NOT FOUND";
}