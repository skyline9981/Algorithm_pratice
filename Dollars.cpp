#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int use[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
ll dp[30005];

int main(void){
    fastio;
    dp[0]=1;
    for(int i=0;i<11;i++){
        for(int j=use[i];j<=30000;j++){
            dp[j]=dp[j]+dp[j-use[i]];
        }
    }
    double n;
    while(~scanf("%lf", &n)) {
        if(n == 0.00 ) break;
        ll x = (n * 100 +0.5);//4out5get
        printf("%6.2f%17lld\n", x * 1.0 / 100, dp[x]);

    }
    return 0;
}
