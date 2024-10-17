#include<iostream>
#include<vector>

using namespace std;

int kadane(vector<int> &a){
    int max_sum = a[0];
    int current_sum = a[0];

    for (int i = 1; i < a.size(); i++){
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;

        int a[n][m];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        int max_sum = -1e9;

        // duyệt qua tất cả các cột
        for (int left = 0; left < m; left++){
            // vector tạm để lưu tổng các hàng 
            vector<int> temp(n, 0);

            // duyệt qua các cột bên phải của left
            for (int right = left; right < m; right++){
                // cập nhập tổng hiện tại
                for (int i = 0; i < n; i++){
                    temp[i] += a[i][right];
                }

                // cập nhập tổng lớn nhất dựa vào thuật toán kadane
                max_sum = max(max_sum, kadane(temp));
            }
        }
        cout << max_sum << endl;
    }
}