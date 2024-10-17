#include<iostream>

#define ll long long

using namespace std;

int isPrime(int n){
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int gcd(int a, int b){
    if (!b) return a;
    return gcd(b, a % b);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int cnt = 0;

        for (int i = 1; i <= n; i++){
            if (gcd(i, n) == 1) cnt++;
        }

        if (isPrime(cnt)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}