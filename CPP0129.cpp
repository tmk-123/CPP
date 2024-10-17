#include<iostream>

#define ll long long

using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, p;
        cin >> n >> p;

        int cnt = 0;

        for (int i = p; i <= n; i += p){
            if (i % p == 0){
                int temp = i;
                while (temp % p == 0){
                    cnt++;
                    temp /= p;
                }
            }
        }

        cout << cnt << endl;
    }
}