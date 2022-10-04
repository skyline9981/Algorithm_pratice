#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rear;
char ok[32][32];
int vis[32];
int young[32][32],old[32][32];

int check(char* now){
    for(int i=0;i<rear;i++){
        if(strcmp(ok[i],now)==0){
            return i;
        }
    }
    vis[rear]=1000;
    strcpy(ok[rear],now);
    return rear++;
}

void dfs(int now,int lv){
    vis[now]=lv;
    for(int i=0;i<rear;i++){
        if(vis[i] == 1000){
            if(old[now][i])dfs(i,lv+1);
            else if(young[now][i])dfs(i,lv-1);
        }
    }
}

int main(void){
    int N;
    scanf("%d",&N);
    char names[32],namet[32];
    for(int i=0;i<N;i++){
        scanf("%s %s",names,namet);
        int s=check(names),t=check(namet);
        young[t][s] = 1;
        old[s][t] = 1;
    }
    int need=check("Dong");
    dfs(need,0);
    for(int i=0;i<rear;i++){
        if(i==need)continue;
        printf("%s ",ok[i]);
        if(vis[i]==1000)printf("unknown\n");
        else if(vis[i] > 0)printf("elder\n");
        else if(vis[i] < 0)printf("younger\n");
        else printf("same\n");
    }
}
