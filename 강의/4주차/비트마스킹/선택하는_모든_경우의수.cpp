#include <bits/stdc++.h>
using namespace std;

const int n = 4;

int main(){
  string a[n] = {"사과", "딸기", "포도", "배"};
  for(int i =0 ;i < (1<<n); i++){ // 모든 경우의 수 2^n
    string ret = ""; //ret 변수 초기화
    for(int j = 0; j < n; j++){  //i값에 따라 n까지 비교
      if(i & (1 << j)){ //비트가 켜져있으면
        ret += (a[j] + " "); //ret 변수에 해당 과일 이름 추가
      }
    }
    cout << ret << "\n"; //i값에 해당하는 ret 변수 출력
  }
  return 0;
}
