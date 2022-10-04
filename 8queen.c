#include<stdio.h>

int queen;
int solution[12];
int horizon[12],slope_negative[24],slope_postive[24];

void backtrack(int x){
    if(x == queen){
        for(int i=0;i < queen;i++){
            printf("%d ",solution[i]+1);
        }
        printf("\n");
        return;
    }
    for (int y=0; y < queen; ++y){
        int d1 = (x+y) % (2*queen), d2 = (x-y+2*queen) % (2*queen);
        if (!horizon[y] && !slope_negative[d1] && !slope_postive[d2]){
            horizon[y] = slope_negative[d1] = slope_postive[d2] = 1;
            solution[x] = y;
            backtrack(x+1);
            horizon[y] = slope_negative[d1] = slope_postive[d2] = 0;
        }
    }
}

int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&queen);
        backtrack(0);
    }
}
