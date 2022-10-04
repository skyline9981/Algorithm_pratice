#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

struct item{
    double first;
    int second;
    int cnt;
};

struct cmp{
    bool operator()(item a, item b){
        double a1 = 0;
        if(a.second!=0){
            a1 = (a.first/a.second)*a.cnt;
        }
        double b1 = 0;
        if(b.second!=0){
            b1 = (b.first/b.second)*b.cnt;
        }

        double a2 = (a.first/(a.second+1))*(a.cnt+1);
        double b2 = (b.first/(b.second+1))*(b.cnt+1);

        return (a2-a1) < (b2-b1);
    }
};

int main(void){
    fastio;
    int n, k;
    cin >> n >> k;
    priority_queue<item, vector<item>, cmp> pq;
    for(int i=0;i<n;++i){
        item a;
        cin >> a.first >> a.second;
        a.cnt=0;
        pq.push(a);
    }

    double ans = 0;
    while(k > 0){
        item now1 = pq.top();
        pq.pop();
        now1.cnt+=1;
        now1.second+=1;
        pq.push(now1);
        k -= 1;
    }
    while(!pq.empty()){
        item aa = pq.top();
        pq.pop();
        if(aa.second == 0)continue;
        ans += ((aa.first/aa.second)*aa.cnt);
    }
    cout << fixed << setprecision(10) << ans;
}
