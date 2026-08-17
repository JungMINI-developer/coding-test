// 내가 풀다가 멈춘 부분.
// #include <bits/stdc++.h>
// using namespace std;
// int cnt[26];   // 각 알파벳의 개수
// int c;         // 문자열 수
// int odd;       // 홀수 개수
// string str;    // 입력 문자열
// char mid;      // 중간 문자
// string s1, s2; // 앞, 뒤

// int main() {
//   cin >> str;

//   for (int i = 0; i < str.size(); i++) {
//     if (str[i]) {
//       cnt[str[i] - 'A']++;
//       c++;
//     }
//   }
//   for (int i = 25; i >= 0; i--) {
//     if (cnt[i] == 0) {
//       continue;
//     }
//     if (cnt[i] % 2 != 0) {
//       mid = char('A' + i);
//       odd++; // 홀수의 갯수 세기
//     }
//     for (int j = 0; j < cnt[i]; j += 2) {
//       s1 += char('A' + i);
//       s1 = char('A' + i) + s1;
//     }
//   }

//   if (odd >= 2) {
//     cout << "I'm Sorry Hansoo" << "\n";
//   } else {
//     if (c % 2 == 0) {
//       // 짝수의 경우
//       cout << s1 << "\n";

//     } else {
//       s1.insert(s1.begin() + s1.size() / 2, mid);
//       cout << s1 << "\n";
//     }
//   }

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid = 0; // 0으로 초기화

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  for (int a : s)
    cnt[a]++;

  // 사전순 출력을 위해 'Z'부터 'A'까지 거꾸로 확인하며
  // 양 끝에 붙여나갑니다. (가운데가 A에 가까워지게)
  for (int i = 'Z'; i >= 'A'; i--) {
    if (cnt[i]) {
      if (cnt[i] & 1) { // 홀수 개인 경우
        mid = (char)i;
        flag++;
        cnt[i]--;
      }
      if (flag == 2)
        break; // 홀수가 2개 이상이면 불가

      for (int j = 0; j < cnt[i]; j += 2) {
        ret = (char)i + ret; // 탐색 글짜 + 기존 글짜
        ret += (char)i;      // 기존글짜 + 탐색글짜
        // 따라서 char(i) + ret + char(i) 가 됨.
      }
    }
  }

  if (flag == 2) {
    cout << "I'm Sorry Hansoo\n";
  } else {
    // flag가 2가 아닐 때만 가운데 글자를 삽입
    if (mid) {
      ret.insert(ret.begin() + ret.size() / 2, mid);
    }
    cout << ret << "\n";
  }

  return 0;
}