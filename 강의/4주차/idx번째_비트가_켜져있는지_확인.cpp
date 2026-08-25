#include <bits/stdc++.h>
using namespace std;

int main(){
  int S = 18; // 10010
  int idx = 3;

  if(S & (1 << idx )){
    cout << "해당 idx: " << idx << "가 켜져있습니다.\n";
  }
  else{
    cout << "해당 idx: " << idx << "가 꺼져있습니다.\n";
  }
  return 0;
}