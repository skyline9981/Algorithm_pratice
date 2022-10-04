#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class query{
public:
    char oper;
    int x, y;
    query(char c, int i, int j){
        oper = c;
        x = i;
        y = j;
    }
};

void dfs(int i, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &finish_order, vector<int> &parent){
    visited[i] = 1;
    for(int j=0;j<adj_list[i].size();++j){
        if(!visited[adj_list[i][j]]){
            parent[adj_list[i][j]] = i;
            dfs(adj_list[i][j], adj_list, visited, finish_order, parent);
        }
    }
    finish_order.push_back(i);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;

    set<pair<int,int>> edge;
    for(int i=0;i<M;++i){
        int x, y;
        cin >> x >> y;
        if(y > x){
            swap(x, y);
        }
        edge.insert({x,y});
    }

    vector<query> vec_q;
    for(int i=0;i<Q;++i){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(y > x){
            swap(x, y);
        }
        query q(c, x, y);
        vec_q.push_back(q);
        if(c == 'U'){
            edge.erase({x,y});
        }
    }

    vector<vector<int>> adj_list(N);
    for(auto &s: edge){
        adj_list[s.first].push_back(s.second);
        adj_list[s.second].push_back(s.first);
    }

    vector<int> finish_order;
    vector<bool> visited(N, 0);
    vector<int> parent(N, 0);

    for(int i=0;i<N;++i){
        parent[i] = i;
    }

    for(int i=0;i<N;++i){
        if(!visited[i]){
            dfs(i, adj_list, visited, finish_order, parent);
        }
    }

    vector<stack<int>> child(N);
    for(int i=0, j=0;i<N;++i){
        if(parent[finish_order[i]] == finish_order[i]){
            int root = finish_order[i];
            for(;j<=i;++j){
                parent[finish_order[j]] = root;
                child[root].push(finish_order[j]);
            }

        }
    }


    vector<bool> output;
    for(int i=Q-1;i>=0;--i){
        query q = vec_q[i];
        if(q.oper == 'A'){
            if(parent[q.x] == parent[q.y]){
                output.push_back(1);
            }else{
                output.push_back(0);
            }
        }else{
            if(parent[q.x] != parent[q.y]){
                int r1 = parent[q.x];
                int r2 = parent[q.y];

                if(child[r1].size() > child[r2].size()){
                    while(!child[r2].empty()){
                        int k = child[r2].top();
                        child[r2].pop();
                        child[r1].push(k);
                        parent[k] = r1;
                    }

                }else{
                    while(!child[r1].empty()){
                        int k = child[r1].top();
                        child[r1].pop();
                        child[r2].push(k);
                        parent[k] = r2;
                    }
                }

            }
        }
    }

    for(int i=output.size()-1;i>=0;i--){
        if(output[i]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
	return 0;
}
