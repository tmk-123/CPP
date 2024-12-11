#include<bits/stdc++.h>

using namespace std;

string diff(string a, string b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) swap(a, b);
    while (a.length() > b.length()) b.insert(0, "0");

    string c = "";
    int remainder = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int hieu = (a[i] - '0') - (b[i] - '0') - remainder;
        if (hieu < 0) {
            hieu += 10;
            remainder = 1;
        }
        else remainder = 0;

        c.push_back(hieu + '0');
    }

    reverse(c.begin(), c.end());
   // while (c[0] == '0' && c.length() > 1) c.erase(0, 1);
    return c;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << diff(a, b) << endl;
    }
}