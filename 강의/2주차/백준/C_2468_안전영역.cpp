#include <bits/stdc++.h>
using namespace std;
int a[104][104];
int visited[104][104];
int dy[4] = {-1,0,+1,0};
int dx[4] = {0, +1, 0, -1};
int n;
int level; // 현재 시도하는 기준 강수량

void dfs(int y, int x){
  visited[y][x] = 1;
  for(int i=0; i<4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx <0 || ny >= n || nx >= n ) continue;
    if(visited[ny][nx] == 0 && a[ny][nx] > level){
      dfs(ny,nx);
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int maxHeight = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> a[i][j];
        maxHeight = max(maxHeight, a[i][j]);
      }
    }

    int answer = 0;
    // 기준값(강수량)을 0부터 최대높이-1까지 전부 시도
    for(level = 0; level < maxHeight; level++){
        memset(visited, 0, sizeof(visited)); // 매번 초기화 필수!
        int cnt = 0;
        for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
            if(a[i][j] > level && visited[i][j]==0){
              dfs(i,j);
              cnt++;
            }        
          }
        }
        answer = max(answer, cnt);
    }

    // 모든 지점이 물에 잠기지 않는 경우(높이가 전부 0인 특수 케이스) 대비
    if(maxHeight == 0) answer = 0;

    cout << answer << "\n";
    return 0;
}