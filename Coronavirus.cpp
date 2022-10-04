#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ll num_fastpow(ll a, ll n){
    ll base = a;
    ll ans = 1;
    while(n!=0){
        if(n&1){
            ans = (ans * base % 1000000007);
        }
        base = (base * base % 1000000007);
        n >>= 1;
    }
    return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	int N;
	cin >> a >> b >> N;
	vector<ll> vec(N,0);
	for(int i=0;i<N;++i){
        ll x;
        cin >> x;
        vec[i] = x;
	}

	ll k = b / (a-1);

	for(int i=0;i<N;++i){

        ll ans = num_fastpow(a, vec[i]-1) * (k+1) - k;
        ans = ans % 1000000007;

        ans = (ans < 0)? ans + 1000000007: ans;
        cout << ans << endl;
	}

	return 0;
}
