#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int N, M, ny, nx, cnt;
int a[104][104];

bool visited[104][104];

void dfs(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= N || ny >= M) {
      continue;
    }
    if (a[ny][nx] == 1 && !visited[ny][nx]) {
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 1 && !visited[i][j]) {
        cnt++, dfs(i, j);
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
