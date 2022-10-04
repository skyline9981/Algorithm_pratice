#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

ll c[100001];

int main(void){
    fastio;
    int coin;
    cin >> coin;
    vector<int>price(coin,0);
    for(int i=0;i<coin;i++){
        cin >> price[i];
    }

    int Q;
    cin >> Q;
    vector<ll>need(Q,0);

    for(int i=0;i<Q;i++){
        ll cost;
        cin >> cost;
        ll pay=0;
        for(int j=0;j<coin;j++){
            ll tmp;
            cin >> tmp;
            pay += tmp*price[j];
        }
        need[i] = pay-cost;
    }

    memset(c, 0x7f,sizeof(c));
    c[0] = 0;

    for(int i=0;i<coin;i++){
        for(int j=price[i];j<=100000;j++){
            c[j] = min(c[j], c[j-price[i]]+1);
        }
    }

    for(int i=0;i<Q;i++){
        cout << c[need[i]] << '\n';
    }

}
