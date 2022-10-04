#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rear;
int young[32][32],old[32][32],vis[32];
char ok[32][32];

int check(char* name){
    for(int i=0;i<rear;i++){
        if(strcmp(name,ok[i])==0)return i;
    }
    vis[rear]=1000;
    strcpy(ok[rear],name);
    return rear++;
}

void dfs(int level,int who){
    vis[who]=level;
    for(int i=0;i<rear;i++){
        if(vis[i]==1000){
            if(old[who][i])dfs(level+1,i);
            if(young[who][i])dfs(level-1,i);
        }
    }
}

int main(void){
    int N;
    scanf("%d",&N);
    char name1[32],name2[32];
    for(int i=0;i<N;i++){
        scanf("%s %s",name1,name2);
        int s=check(name1),t=check(name2);
        young[t][s]=1;
        old[s][t]=1;
    }
    int need=check("Dong");
    dfs(0,need);
    for(int i=0;i<rear;i++){
        if(i==need)continue;
        printf("%s ",ok[i]);
        if(vis[i]==1000)printf("unknown\n");
        else if(vis[i]>0)printf("elder\n");
        else if(vis[i]<0)printf("younger\n");
        else printf("same\n");
    }
}
