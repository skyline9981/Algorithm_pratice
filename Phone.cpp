#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;


class Graph_SP_AllPairs{
    int num_vertex;
    vector< vector<ll> > AdjMatrix, Distance;
public:
    Graph_SP_AllPairs():num_vertex(0){};
    Graph_SP_AllPairs(ll n);
    void AddEdge(ll from, ll to, ll weight);
    void InitializeData();
    void FloydWarshall();
    void printans();
};

Graph_SP_AllPairs::Graph_SP_AllPairs(ll n):num_vertex(n){
    AdjMatrix.resize(num_vertex);
    for (int i = 0; i < num_vertex; i++) {
        AdjMatrix[i].resize(num_vertex, INT_MAX);
        for (int j=0; j<num_vertex; j++) {
            if (i == j){
                AdjMatrix[i][j] = 0;
            }
        }
    }
}

void Graph_SP_AllPairs::InitializeData(){

    Distance.resize(num_vertex);

    for (int i = 0; i < num_vertex; i++) {
        Distance[i].resize(num_vertex);
        for (int j = 0; j < num_vertex; j++) {
            Distance[i][j] = AdjMatrix[i][j];
        }
    }
}

void Graph_SP_AllPairs::FloydWarshall(){

    InitializeData();
    for (int k = 0; k < num_vertex; k++) {
        for (int i = 0; i < num_vertex; i++) {
            for (int j = 0; j < num_vertex; j++) {
                if ((Distance[i][j] > Distance[i][k] + Distance[k][j])){
                    Distance[i][j] = Distance[i][k]+Distance[k][j];
                }
            }
        }
    }
}

void Graph_SP_AllPairs::AddEdge(ll from, ll to, ll weight){
    AdjMatrix[from][to] = min(weight, AdjMatrix[from][to]);
}

void Graph_SP_AllPairs::printans(){
    int k,f,t;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> f >> t;
        if(Distance[f][t] < INT_MAX){
            cout << Distance[f][t] << '\n';
        }else{
            cout << "-1\n";
        }
    }
}

int main(void){
    fastio;
    ll n,m;
    cin >> n >> m;
    Graph_SP_AllPairs g(n);
    ll a,b,w;
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        if(a==b)continue;
        g.AddEdge(a,b,w);
    }
    g.FloydWarshall();
    g.printans();
}

