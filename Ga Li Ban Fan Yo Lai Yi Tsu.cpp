#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
typedef long long int lli;
struct pwnode{lli n,w,another_pos;};
struct wnode{lli n,w;};
struct record{lli b,mypos,another_pos;};

lli bfs(int s,int t,vector<record> &path, vector<vector<pwnode>> &residual, int sz){
    vector<int> visited(sz, 0);
    vector<lli> bottleneck(sz, INT_MAX);
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    path[s] = (record){s, -1,-1};
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i=0;i<residual[now].size();i++){
            pwnode n1 = residual[now][i];
            if (!visited[n1.n] && n1.w>0){
                visited[n1.n] =1;
                path[n1.n] = (record){now, i, n1.another_pos};
                bottleneck[n1.n] = min(bottleneck[now], n1.w);
                q.push(n1.n);
                if (n1.n == t) return bottleneck[t];
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int f,n,m;
    cin >> f >> n >> m;
    vector<vector<pwnode>> capacity1(f+2*n+m+2);
    vector<vector<pwnode>> flow1(f+2*n+m+2);
    vector<vector<pwnode>> residual1(f+2*n+m+2);
    vector<int> farmer(f);
    for (int i=0;i<f;i++){
        int l;
        cin >> l;
        farmer[i] = l;
    }
    vector<int> factory(n);
    for (int i=0;i<n;i++){
        int p;
        cin >> p;
        factory[i] = p;
    }
    vector<int> store(m);
    for (int i=0;i<m;i++){
        int s;
        cin >> s;
        store[i] = s;
    }
    for (int i=0;i<farmer.size();i++){
        capacity1[0].push_back((pwnode){i+1, farmer[i], 0});
        capacity1[i+1].push_back((pwnode){0, 0, i}); //link s(0) node, 0 weight, the other position
        flow1[0].push_back((pwnode){i+1, 0, 0});
        flow1[i+1].push_back((pwnode){0, 0, i});
        residual1[0].push_back((pwnode){i+1, farmer[i], 0});
        residual1[i+1].push_back((pwnode){0, 0, i});
    }
    int c;
    cin>>c;
    for (int i=0;i<c;i++){
        int x,y,cost;
        cin >> x >> y >> cost;
        int xsize = capacity1[x].size();
        int ysize = capacity1[f+y].size();
        capacity1[x].push_back((pwnode){f+y, cost, ysize});
        capacity1[f+y].push_back((pwnode){x, 0, xsize});
        residual1[x].push_back((pwnode){f+y, cost, ysize});
        residual1[f+y].push_back((pwnode){x, 0, xsize});
        flow1[x].push_back((pwnode){f+y, 0, ysize});
        flow1[f+y].push_back((pwnode){x, 0, xsize});
    }
    for (int i = 0; i <factory.size();i++){
        int node_id1 = i+f+1;
        int node_id2 = i+f+n+1;
        int id1_pos = capacity1[node_id1].size();
        capacity1[node_id1].push_back((pwnode){node_id2, factory[i], 0});
        capacity1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
        residual1[node_id1].push_back((pwnode){node_id2, factory[i], 0});
        residual1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
        flow1[node_id1].push_back((pwnode){node_id2, 0, 0});
        flow1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
    }
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int x,y,cost;
        cin >> x >> y >> cost;
        int idx = f+n+x;
        int idy = f+2*n+y;
        int xsize = capacity1[idx].size();
        int ysize = capacity1[idy].size();
        capacity1[idx].push_back((pwnode){idy, cost, ysize});
        capacity1[idy].push_back((pwnode){idx, 0, xsize});
        residual1[idx].push_back((pwnode){idy, cost, ysize});
        residual1[idy].push_back((pwnode){idx, 0, xsize});
        flow1[idx].push_back((pwnode){idy, 0, ysize});
        flow1[idy].push_back((pwnode){idx, 0, xsize});
    }
    for (int i=0;i<store.size();i++){
        int node_id1 = i+f+2*n+1;
        int node_id2 = f+2*n+m+1;
        int id1_pos = capacity1[node_id1].size();
        capacity1[node_id1].push_back((pwnode){node_id2, store[i], i});
        capacity1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
        residual1[node_id1].push_back((pwnode){node_id2, store[i], i});
        residual1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
        flow1[node_id1].push_back((pwnode){node_id2, 0, i});
        flow1[node_id2].push_back((pwnode){node_id1, 0, id1_pos});
    }

    vector<record> path1(f+2*n+m+2);
    lli total_f, df;
    int k;
    cin >> k;
    for (total_f = 0;df=bfs(0, f+2*n+m+1, path1, residual1, f+2*n+m+2);total_f+=df){
        record prev;
        int seek1 = f+2*n+m+1;
        prev = path1[seek1];
        for (int i = prev.b, j =prev.mypos,k=prev.another_pos;;){
            flow1[i][j].w = flow1[i][j].w + df;
            flow1[seek1][k].w = -flow1[i][j].w;
            residual1[i][j].w = capacity1[i][j].w - flow1[i][j].w;
            residual1[seek1][k].w = capacity1[seek1][k].w - flow1[seek1][k].w;
            prev = path1[i];
            seek1 = i;
            if (prev.b == i) break;
            i = prev.b;
            j = prev.mypos;
            k = prev.another_pos;
        }
        if (total_f>k){
            cout << k << "\n";
            break;
        }
    }
    if (total_f<=k) cout << total_f << "\n";


}
