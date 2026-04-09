#include <bits/stdc++.h>
using namespace std;

int n;
string p, s1, s2;
vector<string> v;

int main() {
  cin >> n >> p;

  int pos = p.find("*");
  s1 = p.substr(0, pos);
  s2 = p.substr(pos + 1);

  while (n--) {
    string i;
    cin >> i;

    // [방어막] 파일 이름이 (앞패턴 + 뒤패턴) 길이보다 짧으면 검사할 필요도 없이
    if (i.size() < s1.size() + s2.size()) {
      cout << "NE" << "\n";
    } else {
      // 이제 안전하게 substr을 사용할 수 있습니다.
      if (s1 == i.substr(0, s1.size()) &&
          s2 == i.substr(i.size() - s2.size())) {
        cout << "DA" << "\n";
      } else {
        cout << "NE" << "\n";
      }
    }
    }
  return 0;
}