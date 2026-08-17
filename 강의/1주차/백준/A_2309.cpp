#include <bits/stdc++.h>
using namespace std;
// 순열은 사용하는 방법
//  int main() {
//    int b[9];
//    int temp;
//    for (int i = 0; i < 9; i++) {
//      cin >> temp;
//      b[i] = temp;
//    }

//   sort(b, b + 9);

//   do {
//     int sum = 0;
//     for (int i = 0; i < 7; i++) {
//       sum += b[i];
//     }
//     if (sum == 100) {
//       break;
//     }
//   } while (next_permutation(b, b + 9));

//   for (int i = 0; i < 7; i++) {
//     cout << b[i] << "\n";
//   }
// }

// 조합을 사용하는 방법
int main() {
  int a[9], sum = 0;
  vector<int> v;
  pair<int, int> p;
  // 배열 설정
  for (int i = 0; i < 9; i++) {
    int temp;
    cin >> temp;
    a[i] = temp;
    sum += temp;
  }

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (sum - a[i] - a[j] == 100) {
        p = make_pair(a[i], a[j]);
        break;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    if (p.first == a[i] || p.second == a[i]) {
      continue;
    }
    v.push_back(a[i]);
  }

  for (int i : v) {
    cout << i << "\n";
  }
}
