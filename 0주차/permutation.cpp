#include <bits/stdc++.h>
using namespace std;

// 배열의 경우
int main() {
  int a[] = {1, 2, 3};
  do {
    for (int i : a) cout << i << " ";
    cout << "\n";
    // 2개만 뽑는 경우.
    // for (int i = 0; i < 2; i++) {
    //   cout << a[i] << " ";
    // }
    // cout << "\n";
  } while (next_permutation(&a[0], &a[0] + 3));
}

// 벡터의 경우
// int main() {
//   vector<int> a = {1, 2, 3};
//   do {
//     for (int i : a) {
//       cout << i << " ";
//     }
//     cout << "\n";
//   } while (next_permutation(a.begin(), a.end()));
// }