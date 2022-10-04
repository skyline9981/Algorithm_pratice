#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<ll,ll> pii;

struct Edge {
    ll start, fin, wei;
};

ll MOD=1e9+7;
bool has_MST=false;
ll MST_wei=0,ans2=0;
int V, E;
ll dp[200001];
vector<Edge> e;
ll p[200001];
vector<pii>adj_mst[200001];

bool cmp(Edge e1, Edge e2){
    return e1.wei < e2.wei;
}

void init(){
    for (int i=0; i<V; ++i){
        p[i] = i;
    }
}

int find1(int x){
    return x == p[x] ? x : (p[x] = find1(p[x]));

}

void merge1(int x, int y){
    p[find1(x)] = find1(y);
}

void Kruskal(){
    init();
    sort(e.begin(), e.end(),cmp);

    int i, j;

    for (i = 0, j = 0; i < V-1 && j < E; ++j){
        if (find1(e[j].start) == find1(e[j].fin)) continue;
        merge1(e[j].start, e[j].fin);
        pii temp(e[j].fin,e[j].wei);
        pii temp1(e[j].start,e[j].wei);
        adj_mst[e[j].start].push_back(temp);
        adj_mst[e[j].fin].push_back(temp1);

        MST_wei += e[j].wei%MOD;
        MST_wei %= MOD;
        i++;
    }

    if(i==V-1){
        has_MST=true;
    }
}

void dfs(int a, int f) {
    for (pii &t : adj_mst[a]) {
        if (t.first != f) {
            dfs(t.first, a);
            dp[a] += dp[t.first];
            ans2 += (long long)t.second * dp[t.first] % MOD * (V - dp[t.first]) % MOD;
        }
    }
}

int main(){
    fastio;
    cin >> V >> E;
    int start,fin,wei;
    Edge tmp;
    for(int i=0;i<E;i++){
        cin >> tmp.start >> tmp.fin >> tmp.wei;
        tmp.start-=1;
        tmp.fin-=1;
        e.push_back(tmp);
    }
    Kruskal();

    if(!has_MST){
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < V; i++){
        dp[i] = 1;
    }
    dfs(0,0);
    ans2 = ans2 * 2 % MOD;
    MST_wei = MST_wei * 2 % MOD;

    cout << MST_wei << " " << ans2 << '\n';

    return 0;
}
