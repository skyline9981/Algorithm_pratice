#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    string yes="Yes\n";
    string no="No\n";
    int T;
    scanf("%d", &T);
    while(T--){
        int n,m,s;
        scanf("%d %d %d", &n, &m, &s);

        int visit1[n+1],visit2[n+1];
        int dis1[n+1],dis2[n+1];
        queue<int>que1,que2;
        for(int i=0;i<n+1;i++){
            visit1[i]=0;
            visit2[i]=0;
        }

        //graph
        vector<int> graph[n+1];
        int v1,v2;
        for(int i=0;i<m;i++){
            scanf("%d %d", &v1, &v2);
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        //cop
        int x;
        scanf("%d", &x);
        vector<int>cop(x,0);
        for(int i=0;i<x;i++){
            scanf("%d", &cop[i]);
        }

        //hide
        int y;
        scanf("%d", &y);
        vector<int>goal(y,0);
        for(int i=0;i<y;i++){
            scanf("%d", &goal[i]);
        }

        //BFS for drug
        visit2[s]=1;
        dis2[s]=0;
        que2.push(s);
        while(!que2.empty()){
            int v=que2.front();
            que2.pop();
            for(int u: graph[v]){
                if(!visit2[u]){
                    visit2[u]=1;
                    que2.push(u);
                    dis2[u]=dis2[v]+1;
                }
            }
        }

        //BFS for cop
        //push all cop into queue and start BFS
        for(int i=0;i<cop.size();i++){
            visit1[cop[i]]=1;
            dis1[cop[i]]=0;
            que1.push(cop[i]);
        }
        while(!que1.empty()){
            int v=que1.front();
            que1.pop();
            for(int u: graph[v]){
                if(!visit1[u]){
                    visit1[u]=1;
                    que1.push(u);
                    dis1[u]=dis1[v]+1;
                }
            }
        }

        //make ans
        bool safe=false;
        for(int i=0;i<goal.size();i++){
            if(dis2[goal[i]] < dis1[goal[i]]){
                safe=true;
                break;
            }
        }
        if(safe){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
