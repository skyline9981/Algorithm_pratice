#include<bits/stdc++.h>
#define PB push_back
#define MK make_pair
using namespace std;
typedef pair<int,int> pii;

struct line{
    int a,b,c;
    bool operator< (const line &l)const{
        if(a==l.a){
            if(b==l.b){
                return c<l.c;
            }
            return b<l.b;
        }
        return a<l.a;
    }
};

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int teestcase;
    cin>>teestcase;
    while(teestcase--){
        int n;
        cin>>n;
        vector<pii>loc;
        set<line>line_set;
        for(int i=0,x,y;i<n;i++){
            cin>>x>>y;
            pii tmp = MK(x,y);
            for(int ptr = 0; ptr<loc.size();ptr++){
                int x1 = loc[ptr].first,y1 = loc[ptr].second , x2 = x , y2 = y,a,b,c;
                a = y2-y1;
                b = y1*x2-y2*x1;
                c = x2-x1;
                int divider = (gcd(a,gcd(b,c)));
                a/=divider,b/=divider,c/=divider;
                if(a<0){
                    a*=-1,b*=-1,c*=-1;
                }
                line_set.insert({a,b,c});
            }
            loc.PB(tmp);
        }
        cout<<line_set.size()<<endl;
    }
    return 0;
}
