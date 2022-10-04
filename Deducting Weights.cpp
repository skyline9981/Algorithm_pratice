#include<bits/stdc++.h>
#define ll long long
#define MK make_pair
#define endl "\n"
#define fastio ios::sync_with_stdio(false), cin.tie(0)

using namespace std;

typedef pair<int,int> pii;
typedef pair<ll,int>pli;

const int MAXN = 1e5;
const int MAXE = 5e5;

vector<ll>dist1;
vector<ll>rev_dist;

struct EDGE{
    int from;
    int to;
    int weight;
    EDGE(){}
    EDGE(int a,int b,int c):from(a),to(b),weight(c)
    {}
};
EDGE edge_list[MAXE+5];

int N,M;

int dijkstra(int src,int dst,vector<vector<pii> >&adj,vector<ll> &dist);

int main(){
    fastio;
    cin>>N>>M;
    vector<vector<pii> >adj(N);
    vector<vector<pii> >adj_rev(N);

    for(int i=0;i<M;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        from--,to--;
        edge_list[i] = EDGE(from,to,weight);
        adj[from].push_back(MK(to,weight));
        adj_rev[to].push_back(MK(from,weight));
    }

    int need = N-1;
    int ans1 = dijkstra(0,need,adj,dist1);
    int ans2 = dijkstra(need,0,adj_rev,rev_dist);
    for(int i=0;i<M;i++){
        int from = edge_list[i].from,to = edge_list[i].to;

        ll reduce =  dist1[need] - rev_dist[to] -dist1[from];
        ll ans = edge_list[i].weight - reduce;
        if(reduce<0)
            cout<<"-1"<<endl;
        else
            cout<< ans <<endl;
    }
    return 0;
}


int dijkstra(int src,int dst,vector<vector<pii> >&adj,vector<ll> &dist){
    priority_queue<pli,vector<pli>,greater<pli> >pq;
    vector<int>visit(N,0);
    dist.clear();
    dist.resize(N,5e15);
    dist[src] = 0;
    pq.push(MK(0,src));
    while(!pq.empty()){
        pii now = pq.top();
        pq.pop();
        if(visit[now.second])continue;
        visit[now.second] = 1;
        for(int i=0;i<adj[now.second].size();i++){
            int from = now.second;
            int to = adj[now.second][i].first;
            ll weight = adj[now.second][i].second;
            if(dist[from] + weight < dist[to])
            {
                dist[to ] = dist[from] + weight;
                pq.push(MK(dist[to],to));
            }
        }
    }
    return dist[dst];
}
