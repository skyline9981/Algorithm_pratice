#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

ll b_search(vector<ll> &vec, ll pos, ll target){ // right bound
    ll l = pos, h = n - 1;
    ll m;

    while(l <= h){
        m = (l + h) / 2;
        if(vec[m] == target){
            l = m + 1;
        }else if(vec[m] > target){
            h = m - 1;
        }else{
            l = m + 1;
        }
    }

    return l;
}

ll b2_search(ll prev_idx, ll idx, vector<ll> &vec, ll target){
    ll l = prev_idx;
    ll h = idx;
    ll m;
    while(h != l){
        m = (l + h) / 2;
        if(vec[m] == target){
            h = m;
        }else if(vec[m] < target){
            l = m + 1;
        }
    }
    return idx - l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> k;
    vector<ll> vec(n,0);
    for(int i=0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());

    ll test;
    cin >> test;

    for(int i=0;i<test;i++){
        ll need, limit;
        cin >> need >> limit;
        ll idx = 0, prev_idx = 0, sum = 0;

        for(ll j=1;j<=k;++j){
            if(need * (j - 1) >= limit){
                break;
            }
            ll bound = (need * j > limit) ? limit: (need * j);
            idx = b_search(vec, idx, bound); // right bound
            //cout << idx << endl;
            sum += (idx - prev_idx) * (j - 1);

            if(idx - 1 >= 0 && vec[idx-1] % need == 0){
                sum += b2_search(prev_idx, idx, vec, vec[idx-1]); // left bound
            }

            prev_idx = idx;

        }
        cout << sum << '\n';
    }



	return 0;
}

/*
10 5
9 9 18 27 42 44 45 50 75 85
1
9 44
*/
