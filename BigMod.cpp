#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

ll big(ll base,ll pow,ll mod){
    if(pow==0)return 1;
        else if(pow==1)return base%mod;
        else{
            ll res=big(base,pow/2,mod);
            if(pow%2) return res*res*base%mod;
            else return res*res%mod;
        }
}

int main(){
    fastio;
    ll base,pow,mod;
    while(cin>>base>>pow>>mod){
        ll ans=big(base,pow,mod);
        cout<<ans<<'\n';
    }
}
