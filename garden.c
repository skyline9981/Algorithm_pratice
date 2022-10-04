#include<stdio.h>

int main(void){
    int r,c,x,y,size;
    long N;
    scanf("%d %d %ld",&r,&c,&N);
    int total=r*c,garden[r][c],water[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            garden[i][j]=water[i][j]=0;
        }
    }
    while(N--){
        scanf("%d %d %d",&size,&x,&y);
        if(size > water[x][y]){
            water[x][y] = size;
        }
        garden[x][y] = 1;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(water[i][j] != 0){
                for(int k=(i-water[i][j]/2);k <= (i+water[i][j]/2);k++){
                    for(int l=(j-water[i][j]/2);l <= (j+water[i][j]/2);l++){
                        if(k < 0 || k > r-1 || l < 0 || l > c-1){
                            continue;
                        }
                        else{
                            if(garden[k][l] == 0){
                                garden[k][l] = 1;
                            }
                        }

                    }
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(garden[i][j]==1){
                total -= 1;
            }
        }
    }
    printf("%d\n",total);
}
