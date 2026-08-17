#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> s{4, 3, 3, 5, 1, 2, 3};
  cout << "sort 하기 전\n";
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i : s) cout << i << " ";
  cout << '\n';

  cout << "sort 한 후\n";
  vector<int> s2{4, 3, 3, 5, 1, 2, 3};
  sort(s2.begin(), s2.end());
  for (int i : s2) cout << i << " ";
  cout << "\n";
  s2.erase(unique(s2.begin(), s2.end()), s2.end());
  for (int i : s2) cout << i << " ";
  cout << "\n";
  return 0;
}