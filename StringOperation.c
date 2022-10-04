#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int T;
    scanf("%d",&T);
    char str[T][101];
    for(int i=0;i<T;i++){
        scanf("%s",str[i]);
    }
    int a,b;
    char op[10];
    while(scanf("%s %d %d",op,&a,&b)!=EOF){
        if(strcmp(op,"add")==0) puts(strcat(str[a],str[b]));
        else if(strcmp(op,"eq")==0){
            if(!strcmp(str[a],str[b]))printf("same\n");
            else printf("different\n");
        }
        else if(strcmp(op,"sub")==0){
            int cnt=0;
            for(int i=0;i<strlen(str[a]);i++){
                if(str[a][i]!=str[b][0])str[a][cnt++]=str[a][i];
            }
            str[a][cnt]='\0';
            puts(str[a]);
        }
        else printf("Oops\n");
    }
}
