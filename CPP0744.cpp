#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, r, b, g;
		cin >> n >> r >> b >> g;
		
		ll cnt;
		ll gt[n + 1];
		gt[0] = 1;
		
		for (int i = 1; i <= n; i++)
			gt[i] = gt[i - 1] * i;
		
		int remaining = n - r - b - g;
		ll sum = 0;
		
		// i la so chu cai R, j la B, k la G
		for (int i = 0; i <= remaining; i++){
			for (int j = 0; j <= remaining - i; j++){
				int k = remaining - i - j;
				sum += gt[n] / (gt[i + r] * gt[j + b] * gt[k + g]);
			}
		}
		cout << sum << endl;
	}
}
