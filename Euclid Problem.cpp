#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

void euclid(ll a,ll b,ll &x,ll &y,ll &val){
    if(b==0){
        val=a;
        x=1;
        y=0;
    }
    else{
        euclid(b,a%b,y,x,val);
        y-=x*(a/b);
    }
}

int main(void){
    fastio;
    ll a,b,x,y,val;
    while(cin>>a>>b){
        euclid(a,b,x,y,val);
        cout<<x<<' '<<y<<' '<<val<<'\n';
    }
}
