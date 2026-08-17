#include <bits/stdc++.h>
using namespace std;
int N, M;
void solve(int N, int M) {
  int a = 1;
  for (int i = 0; i < N; i++) {
    a *= i;
  }  // N 만큼 반복
  for (int j = 0; j < M; j++) {
    a *= j;
  }  // M 만큼 반복
  cout << a << "\n";
}
int main() {
  cin >> N >> M;
  solve(N, M);
  return 0;
}

// 이 코드의 시간복잡도는 O(N+M)