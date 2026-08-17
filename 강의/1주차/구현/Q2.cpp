#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v;

void print(const vector<int>& vec) {
  for (int i : vec) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  double sum = 0;
  double avg;
  cin >> n;
  // 1. 배열 설정
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sum += temp;
    v.push_back(temp);
  }
  // 2. 오름 차순 정렬
  cout << "정렬 전" << "\n";
  print(v);
  sort(v.begin(), v.end());
  cout << "정렬 후" << "\n";
  print(v);

  // 3. 평균값 계산
  avg = sum / n;

  cout << fixed << setprecision(2) << avg << "\n";

  return 0;
}