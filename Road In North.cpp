#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int maxn=10001;
vector<pair<int,int> > vp[10001];
int ans;

int dfs(int to,int from){
    int Aroad=0,tem;
    for(int i=0;i<vp[to].size();i++){
        int go=vp[to][i].first;
        if(go!=from){
            tem=dfs(go,to)+vp[to][i].second;
            ans=max(ans,tem+Aroad);
            Aroad=max(tem,Aroad);
        }
    }
    return Aroad;
}
int main(){
    //fastio;
    int a,b,c;
    string s;
    while(!cin.eof()){
        for(int i=0;i<maxn;i++){
            vp[i].clear();
        }
        ans=0;
        getline(cin,s);
        while(s.length()>0&&!cin.eof()){
            stringstream ss;
            ss<<s;
            ss>>a>>b>>c;
            vp[a].push_back(make_pair(b,c));
            vp[b].push_back(make_pair(a,c));
            getline(cin,s);
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
