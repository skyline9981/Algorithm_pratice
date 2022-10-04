#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long



int main(void){
    fastio;
    int t;
    while(cin>>t){
        int ans=0;
        vector<int>num(t);
        vector<int>LIS(t);
        for(int i=0;i<t;i++){
            cin>>num[i];
            LIS[i]=1;
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<i;j++){
                if(num[i]>num[j]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
            ans=max(ans,LIS[i]);
        }
        cout<<ans<<'\n';
    }


}
