#include<bits/stdc++.h>

using namespace std;

const int max_n = 105;
const int mod = 10007;

struct element {
    // số nguyên tố đến 19 bởi 23^2 = 529 > 500, không cần lặp qua mất thời gian
    int p2, p3, p5, p7, p11, p13, p17, p19;
    int rest;
};

int t, n;
// vì 2^8 = 256 , 2^9 > 500 nên mảng có 9 phần tử, tương tự với các số khác
int dp[max_n][9][6][4][4][3][3][3][3][2];
int a[max_n]; // lưu trữ các phần tử mảng đã cho
int listPrime[] = {2, 3, 5, 7, 11, 13, 17, 19};
vector<element> save; // lưu trữ các phần tử đã phân tích

// tính x^n
int POW(int x, int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= x;
        res %= mod;
    }
    return res;
}

// tính số lần chia hết cho x của n
int calc(int& n, int x) {
    int res = 0;
    while (n % x == 0) {
        res++;
        n /= x;
    }
    return res;
}

bool compare(element a, element b) {
    return a.rest < b.rest;
}

int main() {
    cin >> t;
    int cnt = 1;

    while (t--) {
        save.clear();
        cin >> n;
        // bắt đầu từ 1 để số 0
        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            int p2 = calc(a[i], 2);
            int p3 = calc(a[i], 3);
            int p5 = calc(a[i], 5);
            int p7 = calc(a[i], 7);
            int p11 = calc(a[i], 11);
            int p13 = calc(a[i], 13);
            int p15 = calc(a[i], 15);
            int p17 = calc(a[i], 17);
            int p19 = calc(a[i], 19);

            // rest là giá trị còn lại sau khi chia các số nguyên tố, vd nếu số là 23
            // thì sẽ không chia được nên rest bằng 23, nếu chia được thì rest = 1
            int rest = a[i];

            save.push_back({p2, p3, p5, p7, p11, p13, p17, p19, rest});
        }

        save.push_back({0, 0, 0, 0, 0, 0, 0, 0, -1});

        sort(save.begin(), save.end(), compare);    

        memset(dp, 0, sizeof(dp));

        dp[0][0][0][0][0][0][0][0][0][0] = 1;

        // tác dụng của dp là lưu trữ phần tử còn dư (nhân các rest với nhau)

        // giống quy hoạch động bình thường, phân nhánh theo chọn hoặc không chọn 
        // gốc -> số đầu tiên, hoặc chọn thì have = 1, hoặc have = 0. ta xử lý cả 2 trường hợp đó, cứ thế xử lý hết         
        for (int i = 0; i < n; i++) 
        for (int p2 = 0; p2 <= 8; p2++) 
        for (int p3 = 0; p3 <= 5; p3++) 
        for (int p5 = 0; p5 <= 3; p5++) 
        for (int p7 = 0; p7 <= 3; p7++) 
        for (int p11 = 0; p11 <= 2; p11++) 
        for (int p13 = 0; p13 <= 2; p13++) 
        for (int p17 = 0; p17 <= 2; p17++) 
        for (int p19 = 0; p19 <= 2; p19++) 
        for (int have = 0; have <= 1; have++) {
            int currentValue = dp[i][p2][p3][p5][p7][p11][p13][p17][p19][have];

            // nếu bcnn bằng 0
            if (!dp[i][p2][p3][p5][p7][p11][p13][p17][p19][have]) continue;
            
            // nếu các phần tử liên tiếp có phần dư giống nhau, ta có thể chuyển sang trạng thái tiếp theo mà không thay đổi trạng thái lựa chọn
            if (save[i + 1].rest == save[i].rest) (dp[i + 1][p2][p3][p5][p7][p11][p13][p17][p19][have] += currentValue) %= mod; 
            // sự chuyển đổi giữa các nhóm phần dư k    hác nhau, đặt lại trạng thái lựa chọn
            else (dp[i + 1][p2][p3][p5][p7][p11][p13][p17][p19][0] += currentValue) %= mod;
            
            // ta xét trường hợp lấy i + 1
            element e = save[i + 1];
            int newp2 = max(p2, e.p2);
            int newp3 = max(p3, e.p3);
            int newp5 = max(p5, e.p5);
            int newp7 = max(p7, e.p7);
            int newp11 = max(p11, e.p11);
            int newp13 = max(p13, e.p13);
            int newp17 = max(p17, e.p17);
            int newp19 = max(p19, e.p19);

            if (save[i].rest == save[i + 1].rest) {
                // nhân thêm phần dư 
                if (have == 0) (dp[i + 1][newp2][newp3][newp5][newp7][newp11][newp13][newp17][newp19][1] += (save[i + 1].rest * currentValue) % mod) %= mod;
                else (dp[i + 1][newp2][newp3][newp5][newp7][newp11][newp13][newp17][newp19][1] += currentValue) %= mod;
            }
            else (dp[i + 1][newp2][newp3][newp5][newp7][newp11][newp13][newp17][newp19][1] += (save[i + 1].rest * currentValue) % mod) %= mod;
        }

        int ans = 0;
        for (int p2 = 0; p2 <= 8; ++p2)
        for (int p3 = 0; p3 <= 5; ++p3)
        for (int p5 = 0; p5 <= 3; ++p5)
        for (int p7 = 0; p7 <= 3; ++p7)
        for (int p11 = 0; p11 <= 2; ++p11)
        for (int p13 = 0; p13 <= 2; ++p13)
        for (int p17 = 0; p17 <= 2; ++p17)
        for (int p19 = 0; p19 <= 2; ++p19)
        for (int have = 0; have <= 1; ++have) {
            int ways = dp[n][p2][p3][p5][p7][p11][p13][p17][p19][have];
            if (p2 + p3 + p5 + p7 + p11 + p13 + p17 + p19 + have == 0) {
                ways--;
                if (ways < 0) ways += mod;
            }
            int value = 1;
            value = (value * POW(2, p2)) % mod;
            value = (value * POW(3, p3)) % mod;
            value = (value * POW(5, p5)) % mod;
            value = (value * POW(7, p7)) % mod;
            value = (value * POW(11, p11)) % mod;
            value = (value * POW(13, p13)) % mod;
            value = (value * POW(17, p17)) % mod;
            value = (value * POW(19, p19)) % mod;
            value = (value * ways) % mod;
            ans = (ans + value) % mod;
        }

        cout << "Case " << cnt++ << ": " << ans << endl;
    }
}