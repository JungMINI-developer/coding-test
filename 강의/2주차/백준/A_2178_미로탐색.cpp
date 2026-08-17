#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main() {
  cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;               // 한 줄을 문자열로 읽음
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j] - '0'; // 문자 '1' -> 정수 1로 변환
        }
    }

  queue<pair<int,int>> q;
  q.push({0,0});
  visited[0][0] = 1;

  while(q.size()){
    tie(y,x) = q.front();
    q.pop();
    
    for(int i=0; i<4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if(visited[ny][nx] || a[ny][nx] == 0) continue;
      
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny,nx});
    }
  }
    
  cout << visited[n-1][m-1];


  return 0;
}