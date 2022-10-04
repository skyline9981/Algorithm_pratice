#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n,t;
    cin >> n >> t;
    vector<vector<ll>>vec;
    vector<vector<ll>>ans;

    for(int i=0;i<t;i++){
        vector<ll>tmp(n,0);
        vector<ll>temp(n,LLONG_MIN);
        for(int j=0;j<n;j++){
            cin >> tmp[j];
        }
        vec.push_back(tmp);
        ans.push_back(temp);
    }
    for(int i=0;i<n;i++){
        ans[t-1][i] = vec[t-1][i];
    }

    for(int i=t-1;i>=1;i--){
        for(int j=0;j<n;j++){
            if(j==0){
                ans[i-1][j] = max(ans[i][j]+vec[i-1][j], ans[i-1][j]);
                ans[i-1][j+1] = max(ans[i][j]+vec[i-1][j+1], ans[i-1][j+1]);
            }else if(j==n-1){
                ans[i-1][j] = max(ans[i][j]+vec[i-1][j], ans[i-1][j]);
                ans[i-1][j-1] = max(ans[i][j]+vec[i-1][j-1], ans[i-1][j-1]);
            }else{
                ans[i-1][j] = max(ans[i][j]+vec[i-1][j], ans[i-1][j]);
                ans[i-1][j-1] = max(ans[i][j]+vec[i-1][j-1], ans[i-1][j-1]);
                ans[i-1][j+1] = max(ans[i][j]+vec[i-1][j+1], ans[i-1][j+1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[0][i] << ' ';
    }

	return 0;
}
