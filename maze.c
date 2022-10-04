#include<stdio.h>
#include<stdlib.h>

int direc[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int que[1001][2],front,end;

int main(void){
    int r,c;
    scanf("%d %d",&r,&c);
    int maze[r][c],vis[r][c],dst[2],path[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&maze[i][j]);
            vis[i][j]=0;
            path[i][j]=0;
            if(maze[i][j]==-2){
                que[0][0]=i;
                que[0][1]=j;
                end+=1;
            }
            else if(maze[i][j]==-3){
                dst[0]=i;
                dst[1]=j;
            }
        }
    }
    int shortest;
    while(front!=end){
        if(que[front][0]==dst[0] && que[front][1]==dst[1])break;
        for(int i=0;i<4;i++){
            int x=que[front][0]+direc[i][0];
            int y=que[front][1]+direc[i][1];
            if(x<0 || x>=r || y<0 || y>=c)continue;
            if(maze[x][y]==-3){
                if(vis[x][y]==0){
                    vis[x][y]=1;
                    que[end][0]=x;
                    que[end][1]=y;
                    end++;
                    shortest=path[x][y]=path[que[front][0]][que[front][1]]+1;
                }
                else if(vis[x][y]==1 && shortest>path[que[front][0]][que[front][1]]+1){
                    shortest=path[que[front][0]][que[front][1]]+1;
                }
            }
            if(vis[x][y]==0 && maze[x][y]==0){
                vis[x][y]=1;
                que[end][0]=x;
                que[end][1]=y;
                end++;
                path[x][y]=path[que[front][0]][que[front][1]]+1;
            }

        }
        front++;
    }
    printf("%d\n",shortest);
}
