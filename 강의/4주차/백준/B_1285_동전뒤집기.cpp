#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;   
const int INF = 987654321;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 

int n, a[44], ret = INF;
string s; 

void go(int here){
    if(here == n + 1){
        int sum = 0; 
        for(int i = 1; i <= (1 << (n - 1)); i *= 2){ // 열 순회 -> 1, 2, 4, 8, i = 지금 몇번째 열을 검사하고 있는가
            int cnt = 0;  // cnt: 검사중인 열에 T가 몇개가 있는가
            for(int j = 1; j <= n; j++) { // 행을 순회하며 T의 개수 세기
              if(a[j] & i){ // 행 j의 비트마스크와 열 i의 AND 연산 -> j번째 행의 i번째 열칸이 T인가?
                cnt++; 
              }
            }
            sum += min(cnt, n - cnt); // 이 열을 뒤집을지 안뒤집을지가 결정, 뒤집지 않으면 = 그대로 cnt개, 뒤집으면 T와 F가 바뀌므로 => T의 개수는 n - cnt 
        }
        ret = min(ret, sum); //sum에는 이미 확정된 행 뒤집기 조합 + 각 열의 최적으로 뒤집었을 때 남는 T의 총 개수가 완성. 이 값을 최솟값 ret와 비교해서더 작으면 갱신.
        return;
    } 
    go(here + 1); //1. here 번째 행을 "안 뒤집고" 다음 행으로
    a[here] = ~a[here]; // 2. here 행을 뒤집는다.
    go(here + 1); //3. 뒤집은 채로 다음으로 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; // N 입력
    for(int i = 1; i <= n; i++){
        cin >> s; // 각 줄의 문자 입력
        int value = 1; // value값 1로 초기화
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'T')a[i] |= value; // 첫번째 행부터 비트마스킹을 위해 문자로 변환.
            value *= 2;
        }
    }   

    go(1);
    cout << ret << "\n";
    return 0;
}
