#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, mp, mf, ms, mv;

struct A{
    int mp, mf, ms, mv, cost;
}a[16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> mp >> mf >> ms >> mv;

    for(int i=0; i<n; i++)
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;

    int ret = INF;

    vector<vector<int>> candidates; // ret과 같은 비용을 내는 조합들

    for(int i=0; i < (1 << n); i++){
        int b=0, c=0, d=0, e=0, sum=0;
        vector<int> v;

        for(int j=0; j<n; j++){
            if(i & (1 << j)){        
                v.push_back(j+1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }

        if(b >= mp && c >= mf && d >= ms && e >= mv){
            if(sum < ret){
                ret = sum;
                candidates.clear();
                candidates.push_back(v);
            } else if(sum == ret){
                candidates.push_back(v);
            }
        }
    }

    // 반복문 밖에서 딱 한 번 출력
    if(ret == INF) cout << -1 << '\n';
    
    else{
        sort(candidates.begin(), candidates.end());
        cout << ret << "\n";
        for(int x : candidates[0]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}