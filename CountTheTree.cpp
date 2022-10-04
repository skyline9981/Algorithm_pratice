#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

ll ans[1000050];

int main(void){
    fastio;
    int n;
    while(cin>>n){
        if(n==0)break;
        ans[0]=1;
        int len=0;
        for(int i=n+2;i<=2*n;i++){
            ll tmp=0;
            for(int j=0;j<=len;j++){
                ans[j]=ans[j]*i*1ll+tmp;
                tmp=ans[j]/100000000;
                ans[j]%=100000000;
            }
            if(tmp>0){
                ans[++len]=tmp;
            }
        }
        printf("%lld",ans[len]);
        for(int i=len-1;i>=0;i--){
            printf("%08lld",ans[i]);
        }
        printf("\n");
    }
}

