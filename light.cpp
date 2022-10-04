#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
    double t;
    while(cin>>t){
        if(t==0)break;
        ll num=sqrt(t);
        if(num*num==t)cout<<"yes\n";
        else cout<<"no\n";
    }
}
