#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;  
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
// a[11]: 인구수, comp[11]: 각 정점이 어느 그룹에 속해있는지 표시
vector<int> adj[11]; 
//전체 흐름
// 1. 입력 받기 (그래프 + 인구수)
// 2. 가능한 모든 이분을 비트마스크로 하나씩 시도
//   2-1. 이번 분할에서 각 정점이 그룹0/그룹1 인지 표시
//   2-2. 그룹1 쪽에서 DFS 한번 -> 연결 여부 + 인구합 확인
//   2-3. 그룹0 쪽에서 DFS 한번 -> 연결 여부 + 인구합 확인
//   2-4. 둘 다 연결 되어있으면 -> 인구차이로 답 갱신
// 3. 최종 답 출력

// dfs 함수 설명
// 1. 이 그룹이 연결되어 있는가
// 2. 연결되어 있다면, 이 그룹의 인구수 합은 얼마인가?
pair<int, int> dfs(int here, int value){ 
    visited[here] = 1; //지금 정점을 방문 처리  
    pair<int, int> ret = {1, a[here]};  //지금까지 방문한 정점 개수는 1개(자기자신), 인구합은 본인의 인구수로 초기화
    for(int there : adj[here]){ //here와 간선으로 연결된 모든 이웃 정점 there을 하나씩 검사.
        if(comp[there] != value) continue; // 이웃 정점이 있어도 그 정접이 value에 속하지 않으면 무시하고 건너뜀.
        if(visited[there]) continue;  // 방문한 정점이면 건너뜀
        pair<int, int> _temp = dfs(there, value); // 조건 통과 시 재귀 호출, value는 그대로 넘겨서 같은 그룹 탐색.
        ret.first += _temp.first; //자식 정점 개수와 인구 합을 내 결과에 더해서 누적.
        ret.second += _temp.second;  
    }
    return ret; 
}  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 1단계
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];  
    }
    for(int i = 1; i <= n; i++){
        cin >> m;  // 정점 i와 연결된 간선 개수 (인접 리스트)
        for(int j = 0; j < m; j++){
            cin >> temp; 
            adj[i].push_back(temp); // 무방향 그래프 이므로
            adj[temp].push_back(i);  // 양쪽에 다 넣어줌
        } 
    }
    // 2단계
    for(int i = 1; i < (1 << n) - 1; i++){
      // 2-1단계
        fill(comp, comp + 11, 0); // 매 반복마다 comp와 visited 배열 초기화.
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1; 

        for(int j = 0; j < n; j++){ //j는 대응 정점을 가리킴.
            if(i & (1 << j)){ // i의 j번째 비트가 켜져있으면
              comp[j + 1] = 1;  // j+1의 이유는 우리가 a[1] 을 1번 정점으로 정했기 때문.
              idx1 = j + 1;
            }
            else idx2 = j + 1; 
        }

        // 2-2, 2-3 단계 -> 각 그룹 DFS로 검증
        pair<int, int> comp1 = dfs(idx1, 1); // 그룹1에 속한 정점들만 dfs, 정점의 개수 + 인구 합 계산.
        pair<int, int> comp2 = dfs(idx2, 0); // 그룹0에 속한 정점들만 dfs, 정점의 개수 + 인구 합 계산.   
        // 2-4 단계 -> 조건 확인 및 답 갱신
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second)); 
    } 
    cout << (ret == INF ? -1 : ret)<< "\n";
}
