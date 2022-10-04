#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class edge{
public:
    int x, y, c;
    edge(int x1, int y1, int c1){
        x = x1;
        y = y1;
        c = c1;
    }
};

bool cmp(edge &a, edge &b){
    return a.c > b.c;
}

bool check_neg_cycle(int N, vector<edge> &edges, int idx){
    vector<ll> dis(N+1, LLONG_MAX);
	dis[0] = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<=idx;++j){
            edge e = edges[j];
            if(dis[e.x] != LLONG_MAX && dis[e.x] + e.c < dis[e.y]){
                 dis[e.y] = dis[e.x] + e.c;
            }
        }
    }
    bool is_cycle = 0;
	for(int j=0;j<=idx;++j){
        edge e = edges[j];
        if(dis[e.x] != LLONG_MAX && dis[e.x] + e.c < dis[e.y]){
             is_cycle = 1;
             break;
        }
    }
    return is_cycle;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
	cin >> N >> M;

    vector<edge> edges;

    for(int j=1;j<N+1;++j){
        edge e(0, j, 0);
        edges.push_back(e);
	}

	for(int i=0;i<M;++i){
        int x, y, c;
        cin >> x >> y >> c;
        edge e(x+1, y+1, c);
        edges.push_back(e);
	}

    sort(edges.begin(), edges.end(), cmp);

	vector<ll> dis(N+1, LLONG_MAX);
	dis[0] = 0;

	for(int i=0;i<N;++i){
        for(int j=0;j<edges.size();++j){
            edge e = edges[j];
            if(dis[e.x] != LLONG_MAX && dis[e.x] + e.c < dis[e.y]){
                 dis[e.y] = dis[e.x] + e.c;
            }
        }
	}

	bool is_cycle = 0;
	for(int j=0;j<edges.size();++j){
        edge e = edges[j];
        if(dis[e.x] != LLONG_MAX && dis[e.x] + e.c < dis[e.y]){
             is_cycle = 1;
             break;
        }
    }

    if(!is_cycle){
        cout << "GO AHEAD" << endl;
        return 0;
    }

    int L = 0;
    int R = edges.size() - 1;
    for(int i=0;i<edges.size();++i){
        if(edges[i].c < 0){
            L = i;
            break;
        }
    }

    int s_idx = L;

    while(L <= R){
        int mid = (L + R) / 2;
        if(check_neg_cycle(N, edges, mid)){
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }

    while(edges[L-1].c == edges[L].c){
        L--;
    }

    if(s_idx == L){
        cout << "NO WAY BACK" << endl;
    }else{
        cout << edges[L].c << endl;
    }

	return 0;
}
