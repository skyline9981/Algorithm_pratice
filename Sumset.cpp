#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

ll MAX=-1000;

ll check(vector<ll> num){
    for(int i=num.size()-1;i>=0;i--){
        for(int j=0;j<num.size();j++){
            for(int k=j+1;k<num.size();k++){
                for(int l=k+1;l<num.size();l++){
                    if(num[i]==num[j]+num[k]+num[l] && i!=j && i!=k && i!=l)return num[i];
                }
            }
        }
    }
    return MAX;
}

int main(void){
    fastio;
    ll t;
    while(cin>>t){
        if(t==0)break;
        vector<ll>num(t);
        for(int i=0;i<t;i++){
            cin>>num[i];
        }
        sort(num.begin(),num.end());
        ll ans=check(num);
        if(ans==MAX)cout<<"no solution\n";
        else cout<<ans<<'\n';
    }
}
