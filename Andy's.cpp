#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long


int main(){
    fastio;
    int n,target;

    cin>>n>>target;

    vector<int>v;

    for(int i=0;i<n;i++){
        int aa;
        cin>>aa;
        v.push_back(aa);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';

    int cnt=0,pi=INT_MAX,pj=INT_MAX;

    for(int i=0;i<n;i++){

        while(pi==v[i])i++;//avoid the same number

        for(int j=i+1;j<n;j++){

            while(pj==v[j])j++;//avoid the same number
            cout<< "j: " << j << '\n';
            int c=target-v[i]-v[j];
            if(v.begin()+j!=v.end() && binary_search(v.begin()+j+1,v.end(),c)){
                cnt++;
            }
            pj=v[j];
        }
        pi=v[i];
    }
    if(cnt!=0)cout<<cnt<<'\n';
    else cout<<"FeiDooDoo_Zuo_Wei_Men"<<'\n';
    return 0;
}
