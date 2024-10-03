#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int fre[10] = {0}; // frequency

int compare(int a, int b){
    if (fre[a] == fre[b]) return a > b;
    return fre[a] > fre[b];
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        vector<int> odd, even;

        for (char x : s){
            fre[x - '0']++;
        }

        for (int i = 0; i < 10; i++){
            if (fre[i] % 2) odd.push_back(i);
            else if (fre[i])even.push_back(i); 
        }

        // neu chi co chu so 0 trong even thi xoa so 0 di
        if (even.size() && !even.back())
            even.pop_back();

        if (odd.size() > 1){
            sort(odd.begin(), odd.end(), compare); // sap xep theo tan suat va gia tri, xuat hien nhieu thi nhieu chu so se tang them gia tri
            if (!odd[0] && even.empty()) // neu chi co chu so 0 la le va chan rong thi swap de so 0 khong o dau
                swap(odd[0], odd[1]);
        } 

        for (int i = even.size() - 1; i >= 0; i--){
            int temp = fre[even[i]] / 2;
            while (fre[even[i]] > temp){
                cout << even[i];
                fre[even[i]]--;
            }
        }
        
        if (odd.size()){
            while (fre[odd[0]]--){
                cout << odd[0];
            }
        }

        for (int i = 0; i < even.size(); i++){
            while (fre[even[i]]--) cout << even[i];
        }
        
        cout << endl;

        memset(fre, 0, sizeof(fre));
    }
}

// bai nay thieu truong hop cho so le doi xung dat o dau va cuoi