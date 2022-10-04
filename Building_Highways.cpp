#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long int lli;

lli n,m,k,f,s;

struct node{
    int id;
    lli cost;
};

struct Edge{
    int a,b;
    lli cost;
};

int find(int x, vector<int> &parent){
    return (parent[x] == x) ? x:(parent[x] = find(parent[x], parent));
}

void merge(int x,int y, vector<int> &parent){
    parent[find(x,parent)] = find(y,parent);
}

bool cmp(Edge a, Edge b){
    return a.cost<b.cost;
}

bool cmp1(Edge a, Edge b){
    return a.cost>b.cost;
}

lli kruskal(vector<Edge> &edges){
    vector<int> parent(n);
    for (int i=0;i<n;i++){
        parent[i] = i;
    }
    int i,j;
    lli total = 0;
    for (i = 0,j=0;i<n-1 && j<m;i++){
        while (find(edges[j].a, parent) == find(edges[j].b, parent) && j<m) j++;
        if (j<m){
            merge(edges[j].a, edges[j].b, parent);
            total+=edges[j].cost;
        }
        j++;
    }
    if (i == n-1) return total;
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;

    for (int i=0;i<t;i++){
        cin>>n>>m>>k>>f>>s;
        int remain = 0;
        vector<vector<node>> vec(n);
        vector<Edge> edges;
        for (int j=0;j<m;j++){
            int a,b;
            char type;
            cin>>a>>b>>type;
            if (type=='F'){
                edges.push_back((Edge){a,b,f});
            }
            else if (type=='S'){
                edges.push_back((Edge){a,b,s});
            }
        }
        sort(edges.begin(), edges.end(),cmp);
        lli mintree = kruskal(edges);
        if (mintree == -1){
            cout<<"No\n";
            continue;
        }
        sort(edges.begin(), edges.end(),cmp1);;
        lli maxtree = kruskal(edges);
        if (f==s && k == (n-1)*s) cout<<"Yes\n";
        else if (f==s && k != (n-1)*s) cout<<"No\n";
        else if (k>=mintree && k<= maxtree && (maxtree - k)%(f-s) == 0 && (k-mintree)%(f-s) == 0) cout<<"Yes\n";
        else cout<<"No\n";

    }
}
