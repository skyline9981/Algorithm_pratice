#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
typedef pair<int,int> pii;

ll M = 1e9+7;


int main(void){
    fastio;

    vector<ll>vec(3,0);
    vector<ll>ans;
    vec[0] = 1;
    ans.push_back(1);
    for(int i=1;i<10000000;i++){
        ll tmp1,tmp2,tmp3,temp;
        tmp1 = (vec[0]+vec[1]+vec[2])%M;
        tmp2 = (vec[0]+vec[2])%M;
        tmp3 = (vec[0])%M;
        temp = ((tmp1+tmp2+tmp3-1)*4)%M;
        temp+=1;
        ans.push_back(temp);
        vec[0] = tmp1;
        vec[1] = tmp2;
        vec[2] = tmp3;
    }
    int t;
    cin >> t;
    ll n;
    for(int i=0;i<t;i++){
        cin >> n;
        cout << ans[n-1] << '\n';
    }
    return 0;
}
/*
5
10
100
10000
1000000
1000000

*/
