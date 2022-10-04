#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> cal(int idx){
    vector<vector<int>> res;
    for(int i=1;i<idx;i+=2){
        vector<int> v(3,0);
        int j = 1;
        int k = idx - i - j;
        while(1){
            v[0] = i;
            v[1] = j;
            v[2] = k;
            res.push_back(v);
            j += 2;
            k -= 2;
            if(k < 0){
                break;
            }
        }
    }

    return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, x;
	cin >> n;
	vector<ll> v(n,0);
	for(int i=0;i<n;++i){
        cin >> x;
        v[i] = x;
	}

	if(n == 1){
        cout << '0';
        return 0;
	}

	vector<vector<ll>> prefix_sum(n+1,vector<ll>(n,0));
	for(int i=1;i<n+1;i+=2){
        for(int j=i-1;j<n;++j){
            ll sum = 0;
            for(int k=i-1;k>=0;--k){
                sum += v[j-k];
            }
            prefix_sum[i][j] = sum;
        }
	}

	vector<vector<ll>> cost(n+1,vector<ll>(n,0));
	for(int i=3;i<n+1;i+=2){
        vector<vector<int>> vec = cal(i);
        for(int j=i-1;j<n;++j){
            ll Max = LLONG_MIN;
            for(int k=0;k<vec.size();++k){
                int row1 = vec[k][0];
                int row2 = vec[k][1];
                int row3 = vec[k][2];
                int idx = j-i;
                idx += row1;
                int col1 = idx;
                ll cost1 = cost[row1][col1];
                idx += row2;
                int col2 = idx;
                ll cost2 = cost[row2][col2];
                idx += row3;
                int col3 = idx;
                ll cost3 = cost[row3][col3];

                ll total = cost1 + cost2 + cost3 + (prefix_sum[row1][col1] * prefix_sum[row3][col3] - prefix_sum[row2][col2]);
                Max = max(Max, total);
            }
            cost[i][j] = Max;
        }
	}

	cout << cost[n][n-1];

	return 0;
}
