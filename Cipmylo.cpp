#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

bool in_vec=false;

struct input_data{
    ll byear;
    ll eyear;
    int virus;
    ll total_game;
};

ll b_search(vector<ll> &vec, ll target){
    ll l = 0, h = vec.size()-1;
    ll m;

    while(l <= h){
        m = (l + h) / 2;
        if(vec[m] == target){
            //h = m - 1;
            in_vec = true;
            return m;
        }else if(vec[m] > target){
            h = m - 1;
        }else{
            l = m + 1;
        }
    }

    return l;
}

int main(void){
    fastio;
    int n,m,s;
    cin >> n >> m >> s;

    vector<ll>games(n,0);
    for(int i=0;i<n;i++){
        cin >> games[i];
    }
    sort(games.begin(),games.end());
    vector<input_data> testcase;
    ll total_virus = 0;
    for(int i=0;i<m;i++){
        input_data tmp;
        cin >> tmp.byear >> tmp.eyear >> tmp.virus;

        ll idx1 = b_search(games, tmp.byear);
        in_vec = false;
        ll idx2 = b_search(games, tmp.eyear);
        if(in_vec)idx2+=1;

        tmp.total_game = idx2 - idx1;
        total_virus+=tmp.total_game;
        testcase.push_back(tmp);
        in_vec = false;
    }

    ll ans=n-total_virus;
    ll c[s+1];
    memset(c,0,sizeof(c));
    for(int i=0;i<m;i++){
        for(int j=s;j-testcase[i].virus>=0;j--){
            c[j] = max(c[j], c[j-testcase[i].virus]+testcase[i].total_game);
        }
    }
    ans += c[s];
    cout << ans;
}
