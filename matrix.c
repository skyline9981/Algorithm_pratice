#include<stdio.h>
int size=3;
long long mod=10000007;
long long matrix[3][3];
long long I[3][3];
long long trans[3][3];
long long x,y,z,A,B,C,in;

void mul(long long c[3][3],long long a[3][3],long long b[3][3]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            c[i][j] = 0;
            for(int k=0;k<size;k++){
                c[i][j] += (a[i][k]*b[k][j]);
                c[i][j] %= mod;
            }
        }
    }
}

void copy(long long b[3][3],long long a[3][3]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            b[i][j]=a[i][j];
        }
    }
}

void pow(long long in,long long ans[3][3]){
    long long a[3][3],temp[3][3];
    copy(a,trans);
    copy(ans,I);
    while(in){
        if(in%2 == 1){
            copy(temp,ans);
            mul(ans,temp,a);
        }
        in /= 2;
        copy(temp,a);
        mul(a,temp,temp);
    }
}

int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d %d %d %d",&A,&B,&C,&x,&y,&z,&in);
        I[0][0]=I[1][1]=I[2][2]=1;
        trans[0][0]=x;
        trans[0][1]=y;
        trans[0][2]=z;
        trans[1][0]=trans[2][1]=1;
        pow(in,matrix);
        long long ans = (matrix[2][0] * C % mod + matrix[2][1] * B % mod + matrix[2][2]*A % mod) % mod;
        printf("%lld\n",ans);
    }
}
