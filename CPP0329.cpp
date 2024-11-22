#include<bits/stdc++.h>

using namespace std;

string subtractString(string a, string b) {
    while (a.length() > b.length()) b.insert(0, "0");
    string res;
    int borrow = 0;

    for (int i = a.length() - 1; i >= 0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else borrow = 0;

        res.push_back(diff + '0');
    }
    reverse(res.begin(), res.end());

    while (res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return res;
}
bool isGreaterOrEqual(string a, string b) {
    if (a.length() < b.length()) return false;
    if (a.length() > b.length()) return true;
    return a >= b;
}
string divideString(string a, string b) {
    if (a == "0") return "0";
    if (!isGreaterOrEqual(a, b)) return "0";

    string res, current;

    // cách làm giống như phép chia thủ công, lấy từng số một chia cho b(ở đây dùng trừ)
    for (int i = 0; i < a.length(); i++) {
        current += a[i];
        if (current[0] == '0') current.erase(0, 1);

        int cnt = 0;
        while (isGreaterOrEqual(current, b)) {
            current = subtractString(current, b);
            cnt++;
        }

        res += (cnt + '0');
    }

    while (res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << divideString(a, b) << endl;
    }
}