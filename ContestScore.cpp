#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

struct team{
    bool join;
    int num;
    int score;
    int problem;
    int error[10];
};

bool cmp(team a, team b){
    if(a.problem > b.problem)return true;
    if(a.problem < b.problem)return false;
    if(a.score < b.score)return true;
    if(a.score > b.score)return false;
    if(a.num < b.num)return true;
    else return false;
}

int main(void){
    //fastio;
    int t;
    string in;
    stringstream ss;
    team li[105];
    int stu,que,time;
    char c;
    scanf("%d",&t);
    getchar();
    getchar();
    for(int i=0;i<t;i++){
        if(i)cout<<'\n';
        for(int j=0;j<105;j++){
            li[j].join=0;
            li[j].num=j;
            li[j].problem=0;
            li[j].score=0;
            memset(li[j].error,0,sizeof(li[j].error));
        }
        while(getline(cin,in) && in!=""){
            ss.clear();
            ss.str(in);
            ss>>stu>>que>>time>>c;
            li[stu].join=true;

            if(c=='R'||c=='U'||c=='E')continue;
            if(li[stu].error[que]==-1)continue;
            if(c=='C'){
                li[stu].problem++;
                li[stu].score+=time+li[stu].error[que]*20;
                li[stu].error[que]=-1;
            }
            else if(c=='I'){
                li[stu].error[que]++;
            }
        }
        sort(li,li+105,cmp);
        for(int j=0;j<105;j++){
            if(li[j].join){
                cout<<li[j].num<<' '<<li[j].problem<<' '<<li[j].score<<'\n';
            }
        }
    }

}
