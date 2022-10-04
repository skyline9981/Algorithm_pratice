#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
	int N, Q;
	cin >> N >> Q;
	vector<vector<int>> vec(N);

	for(int i=0;i<Q;++i){
		int a, b, c;
		cin >> a >> b >> c;

		if(a == 1){
			vec[b].push_back(c);
		}else{
			if(c >= vec[b].size()){
				cout << "-1" << '\n';
			}else{
				cout << vec[b][c] << '\n';
			}
		}

	}

    return 0;
}
