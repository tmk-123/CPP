#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const double esp = 1e-9;

int solve(vector<vector<double>> &a, int n, int m){
    int rank = 0;

    for (int col = 0; col < m; col++){
        // gọi điểm trục, tìm hàng có số lớn nhất để swap 2 hàng
        // hàng to nhất lên đầu để tránh sai sót, đẻ tránh số 0 ở ngay đầu tiên
        int pivotRow = rank;

        for (int i = rank + 1; i < n; i++){
            if (fabs(a[i][col]) > fabs(a[pivotRow][col])){
                pivotRow = i;
            }
        }
        
        // bỏ qua số bằng 0
        if (fabs(a[pivotRow][col]) < esp) continue;

        swap(a[rank], a[pivotRow]);

        // chia cột đầu cho số đầu tiên
        double pivot = a[rank][col];
        for (int i = col; i < m; i++){
            a[rank][i] /= pivot;
        }

        for (int i = rank + 1; i < n; i++){
            if (i != rank && fabs(a[i][col]) > esp){
                double temp = a[i][col];
                for (int j = col; j < m; j++){
                    // hàng dưới trừ hàng trên theo đố đầu để số đầu bằng 0
                    a[i][j] -= temp * a[rank][j];
                }
            }
        } 

        rank++;
    }
    return rank;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<double>> a(n, vector<double> (m));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        cout << solve(a, n, m) << endl;
    }
}