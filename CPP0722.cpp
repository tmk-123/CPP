#include <bits/stdc++.h>

using namespace std;

string operator*(string s, int n) {
    if (s == "0" || n == 0) return "0";
    
    int len = s.length();
    string product(len, '0');
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int temp = (s[i] - '0') * n + carry;
        product[i] = temp % 10 + '0';
        carry = temp / 10;
    }

    if (carry > 0) product = to_string(carry) + product;

    return product;
} 

string catalan(short int n) {
    vector<int> tu;
    for (int i = n + 2; i <= 2 * n; i++) {
        tu.push_back(i);
    }

    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 0; j < tu.size() && x > 1; j++) {
            int gcd = __gcd(tu[j], x);
            x /= gcd;
            tu[j] /= gcd;
        }
    }

    string res = "1";
    for (auto x : tu) {
        res = res * x;
    }

    return res;
}
int main() {
    short int n;
    cin >> n;

    cout << catalan(n + 1);
}