#include<bits/stdc++.h>

using namespace std;

long solve(long a, long b, long mod) {
    if (b == 0) return 1; 
    
    long x = solve(a, b / 2, mod) % mod;
    if (b % 2 == 1) return ((x * x) % mod) * a % mod;
    return (x * x) % mod;
}

int main() {
    long n, m, k;
    cin >> n >> m >> k;

    long mod = pow(10, k);
    cout << solve(n, m, mod);
}