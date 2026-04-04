#include <bits/stdc++.h>
using namespace std;
int main() {
  int b[9];
  int temp;
  for (int i = 0; i < 9; i++) {
    cin >> temp;
    b[i] = temp;
  }

  sort(b, b + 9);

  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += b[i];
    }
    if (sum == 100) {
      break;
    }
  } while (next_permutation(b, b + 9));

  for (int i = 0; i < 7; i++) {
    cout << b[i] << "\n";
  }
}
