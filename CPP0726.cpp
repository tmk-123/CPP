#include<bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b, long long c) {
    if (b == 0) return 0;

    long long x = solve(a, b / 2, c);
    
    if (b % 2 == 0) return (2 * (x % c)) % c;
    else return (a + 2 * (x % c)) % c;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
}