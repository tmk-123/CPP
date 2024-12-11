#include<bits/stdc++.h>

using namespace std;

string multiple(string a, string b) {
    string c(a.length() + b.length() + 1, '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int iB = 0; iB < b.length(); iB++) {
        int iA;
        for (iA = 0; iA < a.length(); iA++) {
            int tich = (a[iA] - '0') * (b[iB] - '0') + (c[iA + iB] - '0');
            c[iA + iB] = tich % 10 + '0';
            c[iA + iB + 1] += tich / 10;
        }
    }

    reverse(c.begin(), c.end());
    while (c[0] == '0' && c.length() > 1) c.erase(0, 1);
    return c;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << multiple(a, b) << endl;
    }
}