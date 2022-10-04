#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define mod 1000000007
#define vi vector<long long>
#define vll vector<long long>
#define PB push_back
#define eb emplace_back
#define MK make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define TIE ios::sync_with_stdio(0),cin.tie(0);
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

ll max_flow=0;
class Gra{
    public:
    int node;
    vector<vi >adj;
    Gra(int s):node(s){
        adj.resize(node+2,vi(node+2,0));
    }
    void addedge(int from,int to,int weight){
        adj[from][to]+=weight;
    }
    void add_source(int target){
        addedge(0,target,INF);
    }
    void add_dest(int target){
        addedge(target,node+1,INF);
    }
    bool BFS(vi &predecessor);
    void Ford_fulkerson();
    ll find_min(vi &predecessor);
};

ll Gra::find_min(vi &predecessor){
    ll min_cap=0x7fffffff;
    int count =0;
    for(int i=node+1;predecessor[i]!=-1;i=predecessor[i]){
        if(adj[predecessor[i]][i]>0)
            min_cap=min(min_cap,adj[predecessor[i]][i]);
    }//find min edge in augument path
    return min_cap;
}

bool Gra::BFS(vi &predecessor){
    predecessor[0]=-1;
    queue<int>q;
    q.push(0);
    vi visit(node+2,0);
    visit[0]=1;
    while(!q.empty()){
        int f=q.front();q.pop();
        for(int i=0;i<node+2;i++){
            if(visit[i]==0&&adj[f][i]>0){
                q.push(i);
                visit[i]=1;
                predecessor[i]=f;
            }
        }
    }
    return (visit[node+1]==1);
}

void Gra::Ford_fulkerson(){
    vi predecessor(node+2,-1);
    
    while(BFS(predecessor)){
        ll min_cap=find_min(predecessor);
        max_flow+=min_cap;
        for(int i=node+1;i!=0;i=predecessor[i]){
            int from=predecessor[i];
            adj[from][i]-=min_cap;
            adj[i][from]+=min_cap;
        }
        predecessor.clear();
        predecessor.resize(node+2,-1);
    }
}


int main(){TIE
    int N,M,src,dst;
    cin>>N;
    src = 0,dst=N+1;
    Gra g(N);// extra two node for src and dst
    for(int i=1;i<=N;i++){
        int a_i;
        cin>>a_i;
        g.addedge(0,i,a_i);
    }
    for(int i=1;i<=N;i++){
        int b_i;
        cin>>b_i;
        g.addedge(i,dst,b_i);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addedge(a,b,c);
        g.addedge(b,a,c);
    }
    g.Ford_fulkerson();
    cout<<max_flow<<endl;
    return 0;
}
