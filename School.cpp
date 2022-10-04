#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

struct line{
    ll start;
    ll finish;
};

bool cmp(line a, line b){
    if(a.start == b.start){
        return a.finish < b.finish;
    }
    return a.start < b.start;
}

int main(void){
    fastio;
    ll n,cost,cnt=0;
    cin >> n >> cost;
    line target;
    cin >> target.start >> target.finish;

    vector<line> vec;
    for(int i=0;i<n;i++){
        line tmp;
        cin >> tmp.start >> tmp.finish;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp);
    int now=0,temp=0;
    while(target.start < target.finish){
        int select=0;
        ll maxfinish=-1,temp2=0;
        for(int i=now;i<n;i++){
            if(vec[i].start > target.finish)break;
            else if(vec[i].finish <= target.start)continue;
            else if(vec[i].start > target.start){
                temp = i;
                break;
            }
            else{
                ll dis = vec[i].finish - target.start;
                if(!select)cnt++;
                select = 1;
                if(maxfinish < dis){
                    temp2 = vec[i].finish;
                }
            }
        }
        if(!select){
            cnt = 0;
            break;
        }else{
            now = temp;
            target.start = temp2;
        }
    }
    cout << cost*cnt << '\n';
}
