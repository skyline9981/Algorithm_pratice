#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int prime[50003],ans[50003];

int main(void){
    //fastio;
    for(int i=2;i<50003;i++){
        if(prime[i]==0){
            for(int j=i+i;j<50003;j+=i){
                prime[j]=1;
            }
        }
    }

    int L,U;
    while(scanf("%d %d",&L,&U)!=EOF){
        int cnt=0;
        for(int i=L;i<=U;i++){
            if(i>1 && !prime[i]){
                ans[cnt++]=i;
            }
        }
        if(cnt<2){
            printf("There are no adjacent primes.\n");
            continue;
        }
        else{
            int max = -2147483647, min = 2147483647, mil=0, mir=0, mal=0, mar=0;
            for(int i=1;i<cnt;i++){
                if(max<ans[i]-ans[i-1]){
                    max=ans[i]-ans[i-1];
                    mal=ans[i-1];
                    mar=ans[i];
                }
                if(min>ans[i]-ans[i-1]){
                    min=ans[i]-ans[i-1];
                    mil=ans[i-1];
                    mir=ans[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",mil,mir,mal,mar);
        }
    }
}
