#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int prim[10000003];

int bitsum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main(void){
    fastio;
    vector<int> v;
    for (int i = 2; i < 10000003; i++){
        if (prim[i] == 0){
            for (int j = i+i; j < 10000003; j+=i){
                prim[j] = 1;
            }
            v.push_back(i);
        }
    }
    int T;
    cin>>T;
    while(T--){
        int up,down;
        cin>>down>>up;
        int cnt=0;
        for(int i=down;i<=up;i++){
            if(prim[i]==0){
                int aa=bitsum(i);
                if(prim[aa]==0)cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}
