#include<bits/stdc++.h>

using namespace std;
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        double a1 = a.first/(a.second+1);
        double b1 = b.first/(b.second+1);
        if(a1 == b1){
            return a.first < b.first;
        }
        return a1 < b1;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i=0;i<n;++i){
        int x, y;
        cin >> x >> y;
        pq.push({x,y});
    }

    while(k > 1){
        auto now1 = pq.top();
        pq.pop();
        auto now2 = pq.top();
        int a1 = now1.first;
        int a2 = now1.second;
        int b1 = now2.first;
        int b2 = now2.second;
        int t = (a1*(b2+1)/b1)-a2;
        if(t <= 0){
            t = 1;
        }
        if(t >= k){
            t = k-1;
        }
        pq.push({now1.first,now1.second+t});
        k -= t;
    }

    double ans = (double)pq.top().first / (pq.top().second+1);
    cout << fixed << setprecision(6) << ans;


	return 0;
}
