#include<bits/stdc++.h>

using namespace std;

string solve(int n, string s) {
    string res;

    for (char c : s) {
        if (c == '0' || c == '1') {
            continue;
        }
        else if (c == '4') {
            res += "322";
        }
        else if (c == '6') {
            res += "53";
        }
        else if (c == '8') {
            res += "7222";
        }
        else if (c == '9') {
            res += "7332";
        }
        else res += string(1, c);
    }
    sort(res.rbegin(), res.rend());
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n, s) << endl;
    }
}