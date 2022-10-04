#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

ll b1_search(vector<ll> &vec, ll st, ll fin, ll target){
    ll l=st,r=fin;
    ll m;
    while(l<=r){
        m= (l+r)/2;
        if(vec[m]==target){
            return m;
        }
        else if(vec[m]>target){
            r=m-1;
        }
        else{
            l=m+1;
        }

    }
    return -1;
}

ll b2_search(vector<ll> &vec, ll st, ll fin, ll target){
    ll l=st,r=fin;
    ll m;
    while(l<=r){
        m= (l+r)/2;
        if(vec[m]==target){
            return m;
        }
        else if(vec[m]<target){
            r=m-1;
        }
        else{
            l=m+1;
        }

    }
    return -1;
}

int main(void){
    fastio;
    int n,m;
    cin>>n>>m;

    vector<ll> vec(n,0);
    ll node=-1,pos=0,a=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i] > node){
            node = vec[i];
        }
        else {
            if(!a){
                a=1;
                pos=i;
            }
        }
    }
    ll t;
    for(int i=0;i<m;i++){
        cin>>t;
        ll ans;
        if(t < vec[0]){
            ans= b2_search(vec,pos,n-1,t);

            cout<<ans<<'\n';
        }
        else if(t==vec[0]){
            ans=0;
            cout<<ans<<'\n';
        }
        else{

            ans=b1_search(vec, 0, pos-1, t);

            cout<<ans<<'\n';
        }
    }
}

/*
5 5
5 6 3 2 1
4
3
2
1
6
*/
