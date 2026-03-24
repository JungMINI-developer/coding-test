#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& input, string delimiter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimiter);
  // string::npos -> 찾는 문자열이 없을 때
  while (end != string::npos) {
    // start부터 end-start까지 짜른 결과
    result.push_back(input.substr(start, end - start));
    // result에 넣기 start 값 재정의
    start = end + delimiter.size();
    // end 값 재정의 -> start 부터 delimiter가 있는 곳이 end
    end = input.find(delimiter, start);
  }
  // 마지막 원소를 넣어줌 substr(a) -> a부터 끝까지
  result.push_back(input.substr(start));
  return result;
}

int main() {
  string str = "apple,banana,orange,grape";
  vector<string> fruits = split(str, ",");
  for (const string& fruit : fruits) {
    cout << fruit << "\n";
  }
  return 0;
}