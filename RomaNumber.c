#include<stdio.h>
#include<stdlib.h>

int cal(char in[]){
    int sum=0;
    for(int i=0;i<20;i++){
        if(in[i]=='\0'){
            return sum;
        }
        if(in[i]=='M'){
            if(in[i-1]=='C')continue;
            else sum+=1000;
        }
        else if(in[i]=='D'){
            if(in[i-1]=='C')continue;
            else sum+=500;
        }
        else if(in[i]=='C'){
            if(in[i+1]=='D')sum+=400;
            else if(in[i-1]=='X')continue;
            else if(in[i+1]=='M')sum+=900;
            else sum+=100;
        }
        else if(in[i]=='L'){
            if(in[i-1]=='X')continue;
            else sum+=50;
        }
        else if(in[i]=='X'){
            if(in[i+1]=='C')sum+=90;
            else if(in[i-1]=='I')continue;
            else if(in[i+1]=='L')sum+=40;
            else sum+=10;
        }
        else if(in[i]=='V'){
            if(in[i-1]=='I')continue;
            else sum+=5;
        }
        else if(in[i]=='I'){
            if(in[i+1]=='X')sum+=9;
            else if(in[i+1]=='V')sum+=4;
            else sum+=1;
        }
    }
}

int main(void){
    int T,sum;
    scanf("%d",&T);
    char in[20];
    for(int i=0;i<T;i++){
        scanf("%s",in);
        sum=cal(in);
        printf("%d\n",sum);
    }
}
