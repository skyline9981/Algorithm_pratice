#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
vector<int>adj[MAXN+10];
vector<int>adj_rev[MAXN+10];
vector<int>scc_edge[MAXN+10];
int visit1[MAXN+10];
int visit2[MAXN+10];
stack<int>order;
stack<int>order2;
int cnt = 0;
int scc_group_size[MAXN+10];
int scc_group[MAXN+10];
int scc_in_degree[MAXN+10];
int dp[MAXN+10];

void dfs(int cur){
    visit1[cur] = 1;
    for(auto it:adj[cur]){
        if(!visit1[it])
            dfs(it);
    }
    order.push(cur);
}

void dfs2(int cur,int group){
    scc_group[cur] = group;
    scc_group_size[group]++;
    visit2[cur] = 1;
    for(auto it:adj_rev[cur]){
        if(!visit2[it])
            dfs2(it,group);
    }
}

void build_scc_edge(int n){
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            if(scc_group[i]==scc_group[it])
                continue;
            scc_in_degree[scc_group[it]]++;
            scc_edge[scc_group[i]].push_back(scc_group[it]);
        }
    }
}

void dfs_scc(int cur){
    visit1[cur] = 1;
    for(auto it:scc_edge[cur]){
        if(!visit1[it])
            dfs_scc(it);
    }
    order2.push(cur);
}

int main(){
    int N,M;
    cin>>N>>M;
    memset(visit1,0,sizeof(visit1));
    memset(visit2,0,sizeof(visit2));
    for(int i=0,from,to;i<M;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj_rev[to].push_back(from);
    }
    for(int i=0;i<N;i++){
        if(!visit1[i])
            dfs(i);
    }

    while(!order.empty()){
        int src = order.top();
        order.pop();
        if(!visit2[src])
            dfs2(src,cnt++);
    }
    build_scc_edge(N);

    memset(visit1,0,sizeof(visit1));

    for(int i=0;i<cnt;i++){
        if(!visit1[i]){
            dfs_scc(i);
        }
    }
    while(!order2.empty()){
        int cur=order2.top();
        order2.pop();
        if(scc_in_degree[cur]==0)
            dp[cur] = scc_group_size[cur];
        for(auto it:scc_edge[cur]){
            dp[it] = max(dp[it],dp[cur]+scc_group_size[it]);
        }
    }
    int ans = 0;
    for(int i=0;i<cnt;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
