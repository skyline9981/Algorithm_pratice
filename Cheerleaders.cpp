#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> vec;
    for (int i=0;i<n;i++){
        int h;
        cin>>h;
        vec.push_back(h);
    }
    vector<int> lis1;
    vector<int> taillis1(n, 0);
    vector<int> lds1;
    vector<int> taillds1(n, 0);
    lis1.push_back(vec[0]);
    lds1.push_back(vec[n-1]);
    for (int i=1;i<n;i++){
        int num = vec[i];
        if (num>lis1.back()){
            lis1.push_back(num);
            taillis1[i] = lis1.size();
        }
        else{
            int idx = lower_bound(lis1.begin(),lis1.end(),num) - lis1.begin();
            lis1[idx] = num;
            taillis1[i] = idx;
        }
    }
    for (int i = n-2;i>=0;i--){
        int num = vec[i];
        if (num>lds1.back()){
            lds1.push_back(num);
            taillds1[i] = lds1.size();
        }
        else{
            int idx = lower_bound(lds1.begin(), lds1.end(), num) - lds1.begin();
            lds1[idx] = num;
            taillds1[i] = idx;
        }
    }
    int max1 = taillis1[0] + taillds1[0] -1;
    for (int i=1;i<n;i++){
        max1 = max(max1, taillis1[i] + taillds1[i] -1);
    }
    vector<int> lis2;
    vector<int> lds2;
    vector<int> taillis2(n, 0);
    vector<int> taillds2(n, 0);
    lis2.push_back(vec[n-1]);
    lds2.push_back(vec[0]);
    for (int i=1;i<n;i++){
        int num = vec[i];
        if (num < lds2.back()){
            lds2.push_back(num);
            taillds2[i] = lds2.size();
        }
        else{
            int idx = lower_bound(lds2.begin(), lds2.end(), num, greater<int>()) - lds2.begin();
            lds2[idx] = num;
            taillds2[i] = idx;
        }
    }
    for (int i=n-2;i>=0;i--){
        int num = vec[i];
        if (num < lis2.back()){
            lis2.push_back(num);
            taillis2[i] = lis2.size();
        }
        else{
            int idx = lower_bound(lis2.begin(), lis2.end(), num, greater<int>()) - lis2.begin();
            lis2[idx] = num;
            taillis2[i] = idx;
        }
    }
    int max2 = taillis2[0] + taillds2[0] -1;
    for (int i=1;i<n;i++){
        max2 = max(max2, taillis2[i]+ taillds2[i] -1);
    }
    if (max2>max1) cout<<max2<<"\n";
    else cout<<max1<<"\n";
}
