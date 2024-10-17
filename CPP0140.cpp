#include<iostream>

#define ll long long

using namespace std;

ll n;

int solve(){
    ll sum = 1, temp = n;
    if (n > 1e12) return 0;

    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }

    if (temp == sum) return 1;
    return 0;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        cout << solve() << endl;
    }
}