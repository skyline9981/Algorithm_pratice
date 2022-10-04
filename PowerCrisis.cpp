#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int n , m;

int work(int m){
    int a = 0;
    for(int i = 1 ; i < n ; i++){
        a = (a + m) % i;
    }
    return a;
}

int main(){
    int t , i;
    while(scanf("%d",&n)!=EOF){
        if(n == 0)break;
        for(i = 0 ; (t = work(i))!= 11 ; i++);
        printf("%d\n",i);
    }
    return 0;
}
