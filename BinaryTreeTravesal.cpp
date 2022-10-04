#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define PB push_back
#define eb emplace_back
#define MK make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define TIE ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


int cnt = 0;
int n;
int out = 0;
void trav(int l,int r,vector<int> &pre ,vector<int>&in_rev){
    if(l>r||cnt>=n){
        return ;
    }
    int root = pre[cnt++];
    trav(l,in_rev[root]-1,pre,in_rev);
    trav(in_rev[root]+1,r,pre,in_rev);
    out++;
    cout<<char(int('A')+root)<<" \n"[out==n];
}


int main(){TIE
    int testcase;
    cin>>testcase;
    int result_o = 0;
    while(testcase--){
        cnt = 0;
        out = 0;
        cin>>n;
        vector<int>pre(26),in_rev(26);
        for(int i=0;i<n;i++){
            char tmp;
            cin>>tmp;
            pre[i] = (int)(tmp-'A');
        }

        for(int i=0;i<n;i++){
            char tmp;
            cin>>tmp;
            in_rev[(int)(tmp-'A')]=i;
        }

        trav(0,n-1,pre,in_rev);
    }

    return 0;
}
