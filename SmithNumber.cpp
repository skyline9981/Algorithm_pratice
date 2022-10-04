#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

const int N = 20000000;
bool sieve[N];
vector<int> prime;

void linear_sieve(){
    for (int i=2; i<N; i++){
        if (!sieve[i]) prime.push_back(i);
        for (int j=0; i*prime[j]<N; j++){
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int sumdigit(int n){
    int sum=0;
    while(n>0){
        sum+=n%=10;
        n/=10;
    }
    return sum;
}

int main(void){
    fastio;
    linear_sieve();
    int t;
    cin>>t;
    while(t--){
        int in;
        cin>>in;

    }
}
