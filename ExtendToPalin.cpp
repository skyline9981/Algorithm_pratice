#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int f[100001];

void fail(char p[]){
    int i,j;
    f[0]=-1;
    for(i=1,j=-1;p[i];i++){
        while(j>=0 && p[j+1]!=p[i]){
            j=f[j];
        }
        if(p[j+1]==p[i]){
            j++;
        }
        f[i]=j;
    }
}

int KMP(char s[], char p[]){
    int i,j;
    fail(p);
    for(i=0,j=-1;s[i];i++){
        while(j>=0 && p[j+1]!=s[i]){
            j=f[j];
        }
        if(p[j+1]==s[i]){
            j++;
        }
    }
    return j;
}

int main(void){
    fastio;
    char s[100001],p[100001];
    int i,j,len,cut;
    while(scanf("%s",s)!=EOF){
        len=strlen(s);
        for(i=0,j=len-1;i<len;i++,j--){
            p[i]=s[j];
        }
        p[len]='\0';
        cut=KMP(s,p);
        printf("%s",s);
        for(i=cut+1;i<len;i++){
            printf("%c",p[i]);
        }
        printf("\n");
    }
}
