#include <bits/stdc++.h>
using namespace std;

string str;
string s1, s2;

int main() {
  cin >> str;
  int len = str.size();
  if (len % 2 == 0) {
    int mid = str.size() / 2;
    s1 = str.substr(0, mid);
    s2 = str.substr(mid);
  } else {
    int mid = str.size() / 2;
    s1 = str.substr(0, mid);
    s2 = str.substr(mid + 1);
  }

  reverse(s2.begin(), s2.end());

  if (s1 == s2) {
    cout << 1 << "\n";

  } else
    cout << 0 << "\n";
}