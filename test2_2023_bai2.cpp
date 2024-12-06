#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 28;
        freq[a[i]]++;
    }

    long cnt = 0;
    for (auto &x : freq) {
        if (x.second == 0) continue;
        else if (x.first == 0 || x.first == 14) {
            cnt += (long) x.second * (x.second - 1) / 2;
        }
        else if (freq.count(28 - x.first) > 0) {
            cnt += (long) freq[28 - x.first] * x.second;
            freq[28 - x.first] = 0;
        }
    }

    cout << cnt;
}