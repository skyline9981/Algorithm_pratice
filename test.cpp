#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

struct point{
    int x,y;
};

struct point p[100001];

void create(){
    int index=2;
    p[1].x=0;
    p[1].y=0;
    int nowi=0,nowj=0,cnt,num;
    for(int num=1;index<=100000;num++){
        for(cnt=0;cnt<num && index<=100000;cnt++,index++){
            p[index].x=nowi;
            p[index].y=++nowj;
        }


        for(cnt=0;cnt<num-1 && index<=100000;cnt++,index++){
            p[index].x=--nowi;
            p[index].y=++nowj;
        }


        for(cnt=0;cnt<num && index<=100000;cnt++,index++){
            p[index].x=--nowi;
            p[index].y=nowj;
        }


        for(cnt=0;cnt<num && index<=100000;cnt++,index++){
            p[index].x=nowi;
            p[index].y=--nowj;
        }


        for(cnt=0;cnt<num && index<=100000;cnt++,index++){
            p[index].x=++nowi;
            p[index].y=--nowj;
        }


        for(cnt=0;cnt<num && index<=100000;cnt++,index++){
            p[index].x=++nowi;
            p[index].y=nowj;
        }

    }
}

int main(void){
    fastio;
    create();
    int n;
    while(cin>>n){
        cout<<p[n].x<<' '<<p[n].y<<'\n';
    }
}
