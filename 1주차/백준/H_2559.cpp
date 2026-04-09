// N: 1~10만
// K: 1~10만
// 온도는 -100 ~ 100
// 연속된 온도의 합이 "최대" 되는 값 구하기 => 구간합 prefix sum, psum

// 이 문제의 최솟값? -100 * (10만) => -1000만, 하지만 여유있게 4정도는 늘려서
// 최대값은 어디부터

#include <bits/stdc++.h>
using namespace std;
int n, k, temp, psum[100001], ret = -10000004;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }
  for (int i = k; i <= n; i++) {
    ret = max(ret, psum[i] - psum[i - k]);
  }

  cout << ret << "\n";
  return 0;
}