#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(a, a + n);
    long cnt = 0;

    if (k == 0) {
        for (auto it : freq) {
            cnt += (long) it.second * (it.second - 1) / 2; 
        }
    }
    else {
        for (auto it : freq) {
            int x = it.first + k;
            if (freq.find(x) != freq.end()) cnt += (long) it.second * freq[x];
        }
    }

    cout << cnt;
    return 0;
}
