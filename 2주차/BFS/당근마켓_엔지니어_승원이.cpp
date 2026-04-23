#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m; // n: 세로, m: 가로
int sx, sy, cx, cy, a[max_n][max_n], x, y,
    visited[max_n][max_n]; // x,y : 승원이의 위치, c_x, c_y: 당근마켓의 위치.

int main() {
  cin >> n >> m;
  cin >> sy >> sx;
  cin >> cy >> cx;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  queue<pair<int, int>> q;
  visited[sy][sx] = 1;
  q.push({sy, sx});

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || nx >= m || ny >= n || a[ny][nx] == 0) {
        continue;
      }
      if (visited[ny][nx]) {
        continue;
      }
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
  printf("%d\n", visited[cy][cx]);
}
