#include <bits/stdc++.h>
using namespace std;
int a[100004], b, c, psum[100004], n, m;

int main(){
  cin >> n >> m;

  //psum 정의
  for(int i=1; i<=n; i++){
    cin >> a[i];
    psum[i] = psum[i-1] + a[i];
  }

  // 실제 psum을 활용하여 범위 계산.
  for(int i=0; i<m; i++){
    cin >> b >> c;
    cout << psum[c] - psum[b-1] << "\n";
  }
  return 0;
}