#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long cnt = 0;

    sort(a, a + n);
    int left = 0, right = n - 1;
    while (left < right) {
        if (a[left] + a[right] < k) {
            // left ghép với left + 1 -> right
            cnt += right - left;
            left++;
        }
        else right--;
    }

    cout << cnt;
} 