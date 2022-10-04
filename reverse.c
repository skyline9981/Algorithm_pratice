#include<stdio.h>
#include<stdlib.h>


int main(void){
    int t;
    scanf("%d",&t);
    char str[105][105];
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        for(int i=n-1;i>=0;i--){
            printf("%s ",str[i]);
        }
        printf("\n");
    }
}
