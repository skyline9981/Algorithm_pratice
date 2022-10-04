#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int N;
    scanf("%d",&N);
    while(N--){
        int a,b,cnt=0;
        char secret[12],mes[1000][12];
        for(int i=0;i<12;i++)secret[i]='\0';
        for(int i=0;i<1000;i++){
            for(int j=0;j<12;j++){
                mes[i][j]='\0';
            }
        }
        scanf("%d %d %s",&a,&b,secret);
        while(1){
            scanf("%s",mes[cnt]);
            if(strcmp(mes[cnt],"end")==0)break;
            cnt++;
        }
        for(int i=0;i<cnt;i++){
            if(strcmp(mes[i],secret)>0){
                for(int j=0;j<11;j++){
                    if(mes[i][j]=='\0')break;
                    if(mes[i][j]-b<'a')mes[i][j]-=(b-26);
                    else mes[i][j]-=b;
                }
            }
            else if(strcmp(mes[i],secret)<0){
                for(int j=0;j<11;j++){
                    if(mes[i][j]=='\0')break;
                    if(mes[i][j]>'z'-a)mes[i][j]+=(a-26);
                    else mes[i][j]+=a;
                }
            }
            else if(strcmp(mes[i],secret)==0)continue;
        }
        for(int i=0;i<cnt;i++){
            printf("%s ",mes[i]);
        }
        printf("\n");
    }
}
