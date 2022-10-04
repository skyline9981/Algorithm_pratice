#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
    int m,n,t;
    while(cin>>m){
        cin>>n>>t;
        int minBurgerTime=min(m,n);
        int maxBurgerTime=max(m,n);
        int maxBurgerAmount = t / minBurgerTime;
        int remainingTime = t - maxBurgerAmount * minBurgerTime;
        for (int i = maxBurgerAmount - 1 ; i >= 0 && remainingTime != 0 ; --i) {
            int currentRemainingTime = t - i * minBurgerTime;
            int anotherBurgerAmount = currentRemainingTime / maxBurgerTime;

            currentRemainingTime -= anotherBurgerAmount * maxBurgerTime;

            if (currentRemainingTime < remainingTime) {
                maxBurgerAmount = i + anotherBurgerAmount;
                remainingTime = currentRemainingTime;
            }
        }
        cout<<maxBurgerAmount;
        if(remainingTime>0)cout<<' '<<remainingTime;
        cout<<'\n';
    }
}
