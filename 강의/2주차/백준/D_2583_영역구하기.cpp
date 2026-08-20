#include <bits/stdc++.h>
using namespace std;

int m, n, k, cnt;
int a[104][104], visited[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int lx, ly, rx, ry; //왼쪽 위 x,y좌표 & 오른쪽 아래 x,y 좌표
int area;


void paint(int lx, int ly, int rx, int ry){
  for(int x = lx; x < rx; x++){      // rx 미포함
    for(int y = ly; y < ry; y++){    // ry 미포함
      visited[y][x] = 1;
    }
  }
}
// 넓이 계산
void dfs(int y, int x){
  visited[y][x] = 1;
  area++; //이번 dfs 호출에서 방문한 칸 수 추적
  for(int i=0; i<4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
    if(visited[ny][nx] == 0){
      dfs(ny,nx);
    }

  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n >> k;

  while(k--){
    cin >> lx >> ly >> rx >> ry;
    paint(lx, ly, rx, ry);
  }

  //전체 탐색
  vector<int> areas;
  for(int y=0; y<m; y++){
    for(int x=0; x<n; x++){
      if(visited[y][x] == 0){ //색칠 안되고 방문 안된칸 발견되면 시작
        area = 0; //넓이 0으로 초기화
        dfs(y, x); //dfs 호출
        areas.push_back(area); //해당 넓이 벡터에 저장
      }
    }
  }

  sort(areas.begin(), areas.end());
  cout << areas.size() << '\n';
  for(int a:areas) cout << a << " ";
  cout << "\n";
  return 0;
}
