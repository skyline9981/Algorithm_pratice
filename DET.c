#include<stdio.h>

int n;
long long matrix[10][10];
long long mod = 100000007;

long long solve(int A[], int B[], int n) {
    if (n == 1) return matrix[ A[0] ][ B[0] ];
    long long re = 0;
    int nA[n-1], nB[n-1];
    for (int i = 0; i < n-1; i++) {
        nB[i] = B[i+1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                nA[j] = A[j];
            } else if (i < j) {
                nA[j-1] = A[j];
            }
        }
        long long th = solve(nA, nB, n-1);
        if (i&1) th = -th;
        re += th * matrix[ A[i] ][ B[0] ];
        re %= mod;
    }
    return re;
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&matrix[i][j]);
            }
        }
        int A[n], B[n];
        for (int i = 0; i < n; i++) {
            A[i] = i, B[i] = i;
        }
        long long ans=solve(A,B,n);
        if (ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
}
