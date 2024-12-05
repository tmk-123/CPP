#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int maxP = 0;

void solve(vector<vector<bool>>& visited, int x, int y, int& P) {
    int common = 0;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && a[newX][newY]) {
            common++;
        }
    }

    P += 4 - common;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && a[newX][newY] && !visited[newX][newY]) {
            visited[newX][newY] = true;
            solve(visited, newX, newY, P);
        }
    }

    return;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j =  0; j < m; j++) {
            cin >> a[i][j];
        }
    }    

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && a[i][j] == 1) {
                visited[i][j] = true;
                int P = 0;
                solve(visited, i, j, P);
                maxP = max(P, maxP);
            }
        }
    }

    cout << maxP;
}