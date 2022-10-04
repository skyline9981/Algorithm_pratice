#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll c = 1000000007;

ll recur(int node, vector<ll> &val, vector<vector<int>> &child_node){
    if(child_node[node][0] == 0){
        return val[node];
    }

    ll left_node = child_node[node][0];
    ll right_node = child_node[node][1];
    ll res = (recur(left_node, val, child_node) + recur(right_node, val, child_node)) * val[node] % c;
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> node_val(n+1,0);
	for(int i=1;i<=n;++i){
        ll x;
        cin >> x;
        node_val[i] = x;
	}

	vector<int> root_node(n+1,0);
	for(int i=2;i<=n;++i){
        int x;
        cin >> x;
        root_node[i] = x;
	}

	vector<vector<int>> child_node(n+1,vector<int>(2,0));
	for(int i=2;i<=n;++i){
        int r = root_node[i];
        if(child_node[r][0] == 0){
            child_node[r][0] = i;
        }else if(child_node[r][1] == 0){
            child_node[r][1] = i;
        }
	}

    cout << recur(1, node_val, child_node);





	return 0;
}
