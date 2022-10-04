#include<stdio.h>
#include<stdlib.h>

int* files[10005];

int main(void){
    int N,cnt=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int K;
        scanf("%d",&K);
        files[i] = (int*) malloc(sizeof(int)*K);
        for(int j=0;j<K;j++){
            scanf("%d",&files[i][j]);
        }
    }
    long Q;
    scanf("%ld",&Q);
    while(Q--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",files[a][b]);
    }
}
