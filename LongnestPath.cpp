#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int n;
bool m[105][105];
int dis[105];

void spfa(int start){
    int cur;
    bool inq[105];
    memset(inq,false,sizeof(inq));
    queue<int>my;
    my.push(start);
    while(!my.empty()){
        cur=my.front();
        my.pop();
        inq[cur]=false;
        for(int i=1;i<=n;i++){
            if(cur!=i && m[cur][i] && dis[cur]+1 > dis[i]){
                dis[i]=dis[cur]+1;
                if(!inq[i]){
                    my.push(i);
                    inq[i]=true;
                }
            }
        }
    }
}

int main(void){
    fastio;
    int cnt=0;
    int a,b;
    int start;
    while(cin>>n){
        if(n==0)break;
        memset(m,false,sizeof(m));
        memset(dis,0,sizeof(dis));
        cin>>start;
        while(cin>>a>>b){
            if(a==0 && b==0)break;
            m[a][b]=true;
        }
        spfa(start);
        int ans=1;
        for(int i=1;i<=n;i++){
            if(dis[i]>dis[ans])ans=i;
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cnt,start,dis[ans],ans);
    }
}
