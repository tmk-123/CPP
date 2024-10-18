#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int a[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int BFS(int m, int n, int x, int y, int z, int t){
    if (a[x][y] == 0 || a[z][t] == 0) return -1;

    vector<vector<bool>> visited(m, vector<bool> (n, false));
    queue<pair<pair<int, int>, int>> q; // hàng đợi chứa tọa độ x,y và số bước đi

    q.push({{x, y}, 0});
    visited[x][y] = true;

    while (!q.empty()){
        int curX = q.front().first.first; // lấy tọa độ x;
        int curY = q.front().first.second;
        int steps = q.front().second;

        q.pop();

        if (curX == z && curY == t) return steps;

        for (int i = 0; i < 4; i++){
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY] && a[newX][newY] == 1){
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }

    return -1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int m, n, x ,y, z, t;
        cin >> m >> n >> x >> y >> z >> t;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }

        cout << BFS(m, n, x, y, z, t) << endl;
    }
}