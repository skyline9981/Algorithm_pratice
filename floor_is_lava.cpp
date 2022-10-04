#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long int lli;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    vector<pair<double,double>> vec;
    double max_r=0;
    double min_r=INT_MAX;
    for (int i=0;i<n;i++){
        double c,p;
        cin>>c>>p;
        if (c/(p+1)>max_r){
            max_r = c/(p+1);
        }
        if (c/(p+k)<min_r){
            min_r = c/(p+k);
        }
        vec.push_back(make_pair(c,p));
    }
    int remain=k;
    int prev_now=1;
    int now=prev_now*2;
    double mid;
    int q=1;
    while (true){
        lli people=0;
        mid = (max_r + min_r)/2;
        if (max_r-mid<1e-6||mid-min_r<1e-6||(max_r-mid)/max_r<1e-6||(mid-min_r)/min_r<1e-6) break;
        for (int i=0;i<n;i++){
            if (vec[i].second==0||vec[i].first/vec[i].second-mid>0){
                people+= (vec[i].first/mid-vec[i].second);
            }
            if (people>k||people>1e+9){
                min_r=mid;
                break;
            }
        }
        if (people<k){
            max_r = mid;
        }
        if (people==k){
            min_r = mid;
        }

    }
    cout<<fixed<<setprecision(6)<<mid<<"\n";
}
