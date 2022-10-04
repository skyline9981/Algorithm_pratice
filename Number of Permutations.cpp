#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> vec_con(n,0);
    for(int i=0;i<n;++i){
        ll x;
        cin >> x;
        if(x > n){
            x = n;
        }
        vec_con[i] = x;
    }

    sort(vec_con.begin(),vec_con.end());
    ll ans = 1;
    ll cnt;
    for(int i=0;i<n;++i){
        cnt = vec_con[i] - i;
        ans = ((ans % 1000000007) * (cnt % 1000000007)) % 1000000007;
    }
    cout << ans;

	return 0;
}
