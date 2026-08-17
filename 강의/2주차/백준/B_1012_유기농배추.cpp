#include <bits/stdc++.h>
using namespace std;


int a[54][54], n, m, t, k;
int ay,ax;
int visited[54][54];
int cnt;
int dy[4] = {-1,0,+1,0};
int dx[4] = {0,+1,0,-1};

void dfs(int y,int x){
  visited[y][x] = 1;

  for(int i=0; i<4; i++){
    int ny, nx;
    ny = y + dy[i];
    nx = x + dx[i];
    if(ny<0 || nx<0|| ny >= n || nx >= m) continue;
    if(a[ny][nx] ==1 && visited[ny][nx] == 0){
      dfs(ny,nx);
    }
  }

}

int main(){
  cin >> t;

  while(t--){
    cin >> m >> n >> k;

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        a[i][j] = 0;
        visited[i][j] = 0;
      }
    }
  
    while(k--){    
      cin >> ax >> ay;
      a[ay][ax] = 1;
    }

    cnt = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(a[i][j] ==1 && visited[i][j] ==0){
          dfs(i,j);
          cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}