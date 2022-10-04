#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int d[52][52];
int tab[52];

int dp(int x,int y){
    if(d[x][y]>-1)return d[x][y];
    if(x+1==y)return d[x][y]=0;
    int ans=100000;
    for(int i=x+1;i<y;i++){
        ans=min(ans,dp(x,i)+dp(i,y));
    }
    return d[x][y]=ans+tab[y]-tab[x];
}

int main(void){
    fastio;
    int l;
    while(cin>>l){
        if(l==0)break;
        memset(d,-1,sizeof(d));
        int cut;
        cin>>cut;
        memset(tab,0,sizeof(tab));
        tab[0]=0;tab[cut+1]=l;
        for(int i=1;i<=cut;i++){
            cin>>tab[i];
        }
        cout<<"The minimum cutting is "<<dp(0,cut+1)<<".\n";
    }
}
