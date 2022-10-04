#include<stdio.h>
#include<string.h>

int time[10]={480,240,120,60,32,16,8,4,2,1},used[10];
char led[10],solution[10];
int limit_hour=660,limit_min=59;
long long total,sum,temp_hour,temp_min;

void backtrack(int n, int N){
    char last_letter = '\0';
    if (n == N){
        for(int i=0;i<4;i++){
            if(solution[i]=='1'){
                temp_hour+=time[i];
            }
            if(temp_hour>limit_hour){
                break;
            }
        }
        for(int i=4;i<N;i++){
            if(solution[i]=='1'){
                temp_min+=time[i];
            }
            if(temp_min>limit_min){
                break;
            }
        }
        if(temp_hour<=limit_hour && temp_min<=limit_min){
            sum+=temp_min;
            sum+=temp_hour;
        }
        temp_hour=0;
        temp_min=0;
        return;
    }
    for (int i=0; i<N; i++){
        if(used[i]){
            continue;
        }
        if(led[i] == last_letter){
            continue;
        }
        last_letter = led[i];
        used[i] = 1;
        solution[n] = led[i];
        backtrack(n+1, N);
        used[i] = 0;
    }
}

int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&total);
        for(int i=0;i<10;i++){
            if(i<total){
                led[i]='1';
            }
            else{
                led[i]='0';
            }
        }
        backtrack(0,10);
        printf("%lld\n",sum);
        sum=0;
    }
}
