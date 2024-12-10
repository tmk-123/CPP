#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> pass(n);
	for (int i = 0; i < n; i++) cin >> pass[i];
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (pass[i].find(pass[j]) != string::npos || pass[j].find(pass[i]) != string::npos){
				cnt++;
				if (pass[i] == pass[j]) cnt++;
			}
		}
	}
	cout << cnt;
}
