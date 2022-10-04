#include<stdio.h>

int vertex,edge,end=0,front=0;
int map[101][101];
int ans[101],numofedge[101];
int que[1001];

int main(void){
    scanf("%d %d",&vertex,&edge);
    int a,b;
    for(int i=0;i<edge;i++){
        scanf("%d %d",&a,&b);
        map[a][numofedge[a]]=b;
        numofedge[a]++;
        map[b][numofedge[b]]=a;
        numofedge[b]++;
    }
    int s,f;
    scanf("%d %d",&s,&f);
    que[end]=s;
    end+=1;
    ans[s]=1;
    while(front!=end){
        int now=que[front];
        for(int i=0;i<numofedge[now];i++){
            int next=map[now][i];
            if(ans[next]==0){
                ans[next]=ans[now]+1;
                que[end]=next;
                end++;
            }
        }
        front++;
    }
    if(ans[f]==0)puts("Oops");
    else printf("%d\n",ans[f]-1);
}
