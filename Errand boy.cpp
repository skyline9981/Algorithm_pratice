#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



int main(void){
    fastio;
    int N,L,K;
    cin>>N>>L>>K;
    K*=2;
    vector<int>book;
    vector<int>vis(N,0);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        book.push_back(a);
    }
    int cnt=0,br=N-1;
    sort(book.begin(),book.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<vis[j]<<'\n';
        }
        if(vis[i]==1)continue;

        if(book[i]>L-book[i] && vis[i]==0){
            cnt++;
            cout<<book[i]<<'\n';
            cout<<"cnt: "<<cnt<<'\n';
            vis[i]=1;
            continue;
        }
        cout<<book[i]<<'x'<<'\n';
        vis[i]=1;
        int l=i+1,r=N-1,need=L-book[i],pl=i;
        while(l<r){
            if(book[r]>need){
                r--;
            }
            else if(book[r]<=need){
                if(vis[r]==1){
                    r--;
                }
                else{
                    vis[r]=1;
                    cnt++;
                    br=r-1;
                    cout<<book[r]<<'r'<<'\n';
                    cout<<"cnt: "<<cnt<<'\n';
                    break;
                }
            }
            if(book[l]<need){
                if(vis[l]==0){
                    pl=l;
                }
                l++;
            }
            else if(book[l]>=need){
                if(book[l]==need && vis[l]==0){
                    vis[l]=1;
                    cnt++;
                    cout<<book[l]<<'a'<<'\n';
                    cout<<"cnt: "<<cnt<<'\n';
                    break;
                }
                else if(book[pl]<=need && vis[pl]==0){
                    vis[pl]=1;
                    cnt++;
                    cout<<book[pl]<<'b'<<'\n';
                    cout<<"cnt: "<<cnt<<'\n';
                    break;
                }
            }

        }

    }
    cout<<cnt*K<<'\n';
}
