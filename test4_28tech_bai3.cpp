#include<bits/stdc++.h>

using namespace std;

int n;
int a[21][21];
int cnt = 1;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void DFS(vector<vector<bool>>& visited, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY] && !a[newX][newY]) {
			visited[newX][newY] = true;
			cnt++;
			DFS(visited, newX, newY);
		}
	}	

	return;
}
int main() {
	int s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}	

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[s - 1][t - 1] = true;
	DFS(visited, s - 1, t - 1);

	cout << cnt;
}