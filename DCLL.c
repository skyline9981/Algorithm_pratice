#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *l,*r;
};
char com[10];
struct node *tp;

int main(void){
    int T;
    scanf("%d",&T);
    tp=(struct node*)malloc(sizeof(struct node));
    tp->data=1;
    tp->l=tp->r=tp;
    while(T--){
        scanf("%s",com);
        if(com[0]=='W')printf("%d\n",tp->data);
        else if(com[0]=='I'){
            int in;
            scanf("%d",&in);
            struct node *tmp,*next;
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=in;
            next=tp->r;
            tmp->r=next;
            tmp->l=tp;
            tp->r=tmp;
            next->l=tmp;
        }
        else if(com[0]=='L'){
            tp=tp->l;
        }
        else if(com[0]=='R'){
            tp=tp->r;
        }
    }

}
