#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
    ll in,day;
    while(cin>>in){
        cin>>day;
        while(day-in>=0){
            day=day-in;
            if(day!=0)in++;
        }
        cout<<in<<'\n';
    }
}
