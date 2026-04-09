#include <bits/stdc++.h>
using namespace std;

int A, B, C, sum;
int result[101];
pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;
int main() {
  cin >> A >> B >> C;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;

  for (int i = p1.first; i < p1.second; i++) {
    result[i] += 1;
  }
  for (int i = p2.first; i < p2.second; i++) {
    result[i] += 1;
  }
  for (int i = p3.first; i < p3.second; i++) {
    result[i] += 1;
  }

  for (int i : result) {
    if (i == 1) {
      sum += A;
    } else if (i == 2) {
      sum += B * 2;
    } else if (i == 3) {
      sum += C * 3;
    }
  }
  cout << sum << "\n";
}