#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
    int Q;
    cin>>Q;
    vector<priority_queue<int,vector<int>,greater<int>>> ve;
    int cnt=0;
    map<int,int> mapnum;
    map<int,int>::iterator itr;
    while(Q--){
        int ty,item,ex,want;
        cin>>ty;
        if(ty==1){
            cin>>item>>ex;
            itr=mapnum.find(item);
            if(itr==mapnum.end()){
                priority_queue<int,vector<int>,greater<int>> pq;
				pq.push(ex);
				ve.push_back(pq);
				mapnum[item]=cnt;
				cnt++;
            }
            else{
                ve[mapnum[item]].push(ex);
            }
        }
        else{
            cin>>want;
            itr=mapnum.find(want);
            if(itr==mapnum.end()||ve[mapnum[want]].empty() ){
                cout<<"-1\n";
            }
            else{
                cout<< ve[mapnum[want]].top()<<'\n';
                ve[mapnum[want]].pop();
            }
        }
    }
}
