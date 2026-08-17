#include <bits/stdc++.h>
using namespace std;
const int n = 6;
vector<int> adj[n];
int visited[n];

// 1. 돌다리도 두들겨 건너는 방식
// void DFS(int u) {
//   visited[u] = 1;
//   cout << u << "\n";

//   for (int v : adj[u]) {
//     if (visited[v] == 0) {
//       DFS(v);
//     }
//   }
//   cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
//   return;
// }

// 2. 못먹어도 go 방식
// void DFS(int u) {
//   if (visited[u]) {
//     return;
//   }
//   visited[u] = 1;
//   cout << u << "\n";
//   for (int v : adj[u]) {
//     DFS(v);
//   }
// }

void DFS(int here){

  if(visited[here]){
    return;
  }
  cout << here << "\n";
  visited[here] = 1;

  for(int there: adj[here]){
    DFS(there);
  }
}




int main() {
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(4);
  adj[4].push_back(2);
  adj[2].push_back(5);

  DFS(1);
}
/*
1
2
4
4로부터 시작된 함수가 종료되었습니다.
5
5로부터 시작된 함수가 종료되었습니다.
2로부터 시작된 함수가 종료되었습니다.
3
3로부터 시작된 함수가 종료되었습니다.
1로부터 시작된 함수가 종료되었습니다.
*/
