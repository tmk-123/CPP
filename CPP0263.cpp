#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // mang luu duong cheo chinh va phu
    int main_diagonal[n][n], sec_diagonal[n][n];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // luu cac duong cheo chinh tu (0, 0) den (i, j)
            if (i > 0 && j > 0) main_diagonal[i][j] = a[i][j] + main_diagonal[i - 1][j - 1];
            else main_diagonal[i][j] = a[i][j];

            // luu cac duong cheo phu tu (0, n - 1) den (i, j)
            if (i > 0 && j < n - 1) sec_diagonal[i][j] = a[i][j] + sec_diagonal[i - 1][j + 1];
            else sec_diagonal[i][j] = a[i][j];
        }
    }
    
    int maxValue = -1e9;

    // k la kich thuoc cua mang con. k >= 2 vi mang 1 * 1 khong cho duong cheo chinh va duong cheo phu rieng
    for (int k = 2; k <= n; k++){
        // (i, j) la phan tu dau tien tren duong cheo chinh cua mang con
        for (int i = 0; i <= n - k; i++){
            for (int j = 0; j <= n - k; j++){
                // i + k - 1 la phan tu cuoi
                int main_diagonal_sum = main_diagonal[i + k - 1][j + k - 1];
                if (i > 0 && j > 0) main_diagonal_sum -= main_diagonal[i - 1][j - 1];

                int sec_diagonal_sum = sec_diagonal[i + k - 1][j];
                if (i > 0 && j + k < n) sec_diagonal_sum -= sec_diagonal[i - 1][j + k];

                maxValue = max(maxValue, main_diagonal_sum - sec_diagonal_sum);
            }
        }
    }
    cout << maxValue;
}
