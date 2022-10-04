#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int a;

long long ipow( ll base, ll exp ){
    long long result = 1;
    while( exp ){
        if ( exp & 1 ){
            result *= (long long)base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

vector<ll> rec(vector<ll>&vec,int n){
    if(n==0){
        vec.push_back(1);
        return vec;
    }else{
        vector<ll>pre;
        pre = rec(vec,n-1);
        a=n-1;
        for_each(vec.begin(),vec.end(),[](ll& d) {d+=ipow(2,a);} );
        reverse(pre.begin(),pre.end());
        vec.insert(vec.end(),pre.begin(),pre.end());
        return vec;
    }
}

int main(void){
    fastio;
    int N;
    cin>>N;
    vector<ll> vec;
    vector<ll> ans;
    ans = rec(vec,N);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}
