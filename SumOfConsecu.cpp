#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int prim[10003];
vector<int> v;

int main(void){
    fastio;
    for (int i = 2; i < 10003; i++){
        if (prim[i] == 0){
            for (int j = i+i; j < 10003; j+=i){
                prim[j] = 1;
            }
            v.push_back(i);
        }
    }
    int num;
    while(true){
        cin>>num;
        if(num==0)break;
        int cnt=0;
        for(int i=0;v[i]<=num;i++){
            int sum=0;
            for(int j=i;sum<num;j++){
                sum+=v[j];
                if(sum==num){
                    cnt++;
                    break;
                }
            }
        }
        cout<< cnt<<'\n';
    }
}
