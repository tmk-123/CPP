#include<bits/stdc++.h>

using namespace std;

string v[21];
void solve() {
    v[0] = "{}";
    for (int i = 1; i <= 20; i++) {
        v[i] += "{";
        for (int j = 0; j < i; j++) {
            v[i] += v[j];
            if (j < i - 1 && i != 1) v[i] += ","; 
        }
        v[i] += "}";
    }
}
int main() {
    solve();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int x = s.find("+");
        int a = stoi(s.substr(0, x));
        int b = stoi(s.substr(x + 1));
        int c = a + b;
        cout << v[a] << "+" << v[b] << "=" << v[c] << endl;
    }
}