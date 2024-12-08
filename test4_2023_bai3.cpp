#include<bits/stdc++.h>

using namespace std;

int n;
int x, y, z, t;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool Try(vector<vector<int>>& a, int i, int j, vector<vector<bool>>& visited) {
    if (i == z && j == t) return true;
    
    for (int k = 0; k < 8; k++) {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if (newX >= 1 && newY >= 1 && newX <= n && newY <= n && a[newX][newY] == 1 && !visited[newX][newY]) {
            visited[newX][newY] = true;
            if (Try(a, newX, newY, visited)) return true;
            visited[newX][newY] = false;
        }
    }

    return false;
}
int main() {
    cin >> n;
    cin >> x >> y >> z >> t;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    visited[x][y] = true;
    if (Try(a, x, y, visited)) cout << "YES";
    else cout << "NO";
}