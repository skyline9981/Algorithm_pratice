#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rec(int left, int right, int N,char *ans){
    if(left==N && right==N){
        puts(ans);
        return;
    }
    int now=left+right;
    if(left<N){
        ans[now]='(';
        rec(left+1,right,N,ans);
    }
    if(right<left){
        ans[now]=')';
        rec(left,right+1,N,ans);
    }
}

int main(void){
    int N;
    scanf("%d",&N);
    char ans[N*2+5];
    for(int i=0;i<N*2+5;i++)ans[i]='\0';
    rec(0,0,N,ans);
}
