#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int money[7]={1000,500,100,50,10,5,1};

bool cmp(ll a,ll b){
    return a > b;
}

int main(void){
    fastio;
    string yes="Yes";
    string no="No";
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n;
        cin >> n;
        vector<vector<ll> >vec;
        bool cansol=true;
        ll total_money[7];
        for(int i=0;i<7;i++)total_money[i]=0;

        for(int i=0;i<n;i++){
            vector<ll> tmpvec(8);
            for(int j=0;j<8;j++){
                ll tmp;
                cin >> tmp;
                if(j>0)total_money[j-1]+=tmp;
                tmpvec[j]=tmp;
            }
            vec.push_back(tmpvec);
        }

        vector<ll> need(n,0);
        for(int i=0;i<n;i++){
            ll sum=vec[i][0];
            ll cnt=0;
            for(int j=1;j<8;j++){
                cnt+=(vec[i][j]*money[j-1]);
            }
            need[i] = cnt-sum;
        }
        sort(need.begin(),need.end(),cmp);

        for(int i=0;i<n;i++){
            if(need[i]==0)continue;
            else{
                for(int j=0;j<7;j++){
                    if(need[i]==0)break;
                    if(total_money[j]==0)continue;
                    if(need[i] >= money[j] && total_money[j] > 0){
                        if((total_money[j] * money[j]) >= need[i]){
                            total_money[j] -= (need[i]/money[j]);
                            need[i] %= money[j];
                        }
                        else{
                            need[i] -= (total_money[j]*money[j]);
                            total_money[j]=0;
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(need[i]!=0)cansol=false;
        }

        if(cansol){
            cout<<yes<<endl;
        }
        else{
            cout<<no<<endl;
        }
    }
}
