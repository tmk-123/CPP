#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105];
vector<int> res;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void DFS(int x, int y, int& P, vector<vector<bool>>& visited) {
    int common = 0;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newY >= 0 && newX < n && newY < m && a[newX][newY]) common++; 
    }    

    P += 4 - common;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newY >= 0 && newX < n && newY < m && a[newX][newY] && !visited[newX][newY]) {
            visited[newX][newY] = true;
            DFS(newX, newY, P, visited);
        } 
    }

    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> a[i][j]; 
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                int P = 0;
                visited[i][j] = true;
                DFS(i, j, P, visited);
                res.push_back(P); 
            }
        }
    }

    for (int x : res) {
        cout << x << " ";
    }
}