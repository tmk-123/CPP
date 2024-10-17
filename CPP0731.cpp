#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> numberOfJumps(n, 1e9);
        numberOfJumps[0] = 0;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (i <= j + a[j]){
                    numberOfJumps[i] = min(numberOfJumps[i], numberOfJumps[j] + 1);
                }
            }
        }
        
        cout << numberOfJumps[n - 1] << endl;
    }
}