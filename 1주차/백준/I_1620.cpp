#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, int> mp;  // 이름으로 숫자 찾기
string a[100004];     // 숫자로 이름 찾기

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s] = i + 1;
    a[i + 1] = s;
  }

  for (int i = 0; i < m; i++) {
    cin >> s;

    if (isdigit(s[0])) {
      // 숫자인 경우
      //  숫자로 이름 찾기.
      int n = stoi(s);
      cout << a[n] << "\n";
    } else {
      // 문자열인 경우
      cout << mp[s] << "\n";
    }
  }
}
