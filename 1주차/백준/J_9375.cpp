#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main() {
  cin >> t;
  while (t--) {
    map<string, int> _map;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;  // a값은 중요하지 않아서 버림.
      _map[b]++;      // b에 해당하는 map이 있으면 해당 int 를 1더하고, 없으면
                      // 새로운 map을 생성하고 1을 추가해줌.
    }
    long long ret = 1;                   // cout 결과 생성.
    for (auto c : _map) {                // 맵을 탐색
      ret *= ((long long)c.second + 1);  // 해당 종류를 모두 곱해줌.
    }
    ret--;  // 마지막에 -1을 해주면 전체 경우의 수 -> 알몸인 경우 빼기.
    cout << ret << "\n";
  }
  return 0;
}