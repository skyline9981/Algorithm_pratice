#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
    int pro,cost;
    char name[12];
};

int compare(const void *p,const void *q){
    const struct item *p1=p;
    const struct item *q1=q;
    if(p1->pro < q1->pro)return 1;
    else if(p1->pro == q1->pro) return 0;
    else return -1;
}

int main(void){
    int N;
    scanf("%d",&N);
    while(N--){
        int sum=0;
        char ans[12][12];
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                ans[i][j]='\0';
            }
        }
        int money,goods,cnt=0;
        scanf("%d %d",&money,&goods);
        struct item wantbuy[12];
        for(int i=0;i<goods;i++){
            scanf("%d %d %s",&wantbuy[i].pro,&wantbuy[i].cost,wantbuy[i].name);
        }
        qsort(wantbuy,goods,sizeof(struct item),compare);
        for(int i=0;i<goods;i++){
            if(money >= wantbuy[i].cost){
                sum += wantbuy[i].cost;
                money -= wantbuy[i].cost;
                strcpy(ans[cnt],wantbuy[i].name);
                cnt++;
            }
            if(money <= 0)break;
        }
        printf("%d ",sum);
        for(int i=0;i<cnt;i++){
            for(int j=i+1;j<cnt;j++){
                if(strcmp(ans[i],ans[j])>0){
                    char temp[12];
                    strcpy(temp,ans[i]);
                    strcpy(ans[i],ans[j]);
                    strcpy(ans[j],temp);
                }
            }
        }
        for(int i=0;i<cnt;i++)printf("%s ",ans[i]);
        printf("\n");
    }
}
