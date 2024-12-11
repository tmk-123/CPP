#include<bits/stdc++.h>

using namespace std;

string sum_string(string a, string b) {
    if (a.length() < b.length()) swap(a, b);
    while (a.length() > b.length()) b.insert(0, "0");
    
    string c = "";
    int remainder = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int tong = (a[i] - '0') + (b[i] - '0') + remainder;
        c.push_back(tong % 10 + '0');
        remainder = tong / 10;
    }

    if (remainder > 0) c.push_back(remainder + '0');
    reverse(c.begin(), c.end());
    return c;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << sum_string(a, b) << endl;
    }
}