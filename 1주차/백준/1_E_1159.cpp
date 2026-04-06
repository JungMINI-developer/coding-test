#include <bits/stdc++.h>
using namespace std;

// 1. 나의 풀이
//  int n, cnt = 1;
//  vector<string> v;
//  string result = "";

// int main() {
//   cin >> n;
//   for (int i = 0; i < n; i++) {
//     string temp;
//     cin >> temp;
//     v.push_back(temp);
//   }

//   sort(v.begin(), v.end());

//   for (int i = 0; i < n - 1; i++) {
//     // 현재 이름의 첫 글자와 다음 이름의 첫 글자가 같으면
//     if (v[i][0] == v[i + 1][0]) {
//       cnt++;
//     } else {
//       // 글자가 달라지는 시점에 개수 확인
//       if (cnt >= 5) {
//         result += v[i][0];
//       }
//       cnt = 1;  // 개수 초기화
//     }
//   }
//   // 마지막 묶음 확인 (루프가 n-1에서 끝나므로 마지막 그룹 처리 필요)
//   if (cnt >= 5) result += v[n - 1][0];

//   // 결과 출력
//   if (result.empty()) {
//     cout << "PREDAJA" << "\n";
//   } else {
//     cout << result << "\n";
//   }

//   return 0;
// }

// 2. 해설 풀이

int n, cnt[26];
string s, ret;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    // cnt 아스키코드를 활용하여 좌표 이동.
    // ex) b가 첫글짜면 cnt[1]로 들어감  -> 문자를 숫자로
    cnt[s[0] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 5) {
      // 숫자를 문자열로
      ret += (i + 'a');
    }
  }

  if (ret.size()) {
    cout << ret << "\n";
  } else {
    cout << "PREDAJA" << "\n";
  }
}