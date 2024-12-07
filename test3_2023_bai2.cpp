#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    // lưu tổng từ vị trí đầu và vị trí đầu tiên đạt được tổng đấy
    // nếu prefix ở vị trí i = prefix ở vị trí j thì từ i -> j có tổng bằng 0
    unordered_map<long, int> prefix_map; 
    int prefix_sum = 0, max_len = 0;
    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];

        // trường hợp tổng từ 0 -> i bằng 0, ta xét luôn 
        if (prefix_sum == 0) {
            if (max_len < i + 1) {
                max_len = i + 1;
                start = 0;
                end = i;
            }
        }
        
        if (prefix_map.find(prefix_sum) != prefix_map.end()) {
            int len = i - prefix_map[prefix_sum];
            if (len > max_len) {
                max_len = len;
                start = prefix_map[prefix_sum] + 1;
                end = i;
            }
        }
        else prefix_map[prefix_sum] = i;
    }

    if (max_len > 0) {
        for (int i = start; i <= end; i++) {
            cout << a[i] << " ";
        }
    }
    else cout << "NOT FOUND";
}