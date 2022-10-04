#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check4(char *str){
    int cnt=0,sign=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='.'){
            int tmp=0;
            if(cnt<4 && cnt>0){
                for(int j=0;j<cnt;j++){
                    tmp=tmp*10+(str[i-cnt+j]-'0');
                }
                if(tmp>=256 || tmp<0){
                    printf("QAQ\n");
                    return;
                }
                cnt=0;
            }
            else {
                printf("QAQ\n");
                return;
            }
            sign++;
        }
        else if(str[i]>=48 && str[i]<=57){
            if(cnt==0 && str[i]==48 && str[i+1]!='.'){
                printf("QAQ\n");
                return;
            }
            cnt++;
        }
        else{
            printf("QAQ\n");
            return;
        }
    }
    if(sign==3 && cnt<4 && cnt>0){
        printf("Valid IP\n");
    }
    else printf("QAQ\n");
}

void check6(char *str){
    int cnt=0,sign=0;
    for(int i=0;i<strlen(str);i++){
        char now=str[i];
        if(str[i]==':'){
            if(cnt<5 && cnt>0){
                cnt=0;
            }
            else{
                printf("QAQ\n");
                return;
            }
            sign++;
        }
        else if(now>=48&&now<=57 || now>=65&&now<=70 || now>=97&&now<=102){
            cnt++;
        }
        else{
            printf("QAQ\n");
            return;
        }
    }
    if(cnt<5&&cnt>0&&sign==7) printf("Valid IP\n");
    else printf("QAQ\n");
}


int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        int num;
        char str[51];
        scanf("%d %s",&num,str);
        if(num==4)check4(str);
        else check6(str);
    }
}
