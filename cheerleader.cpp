#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<ll> LIS(vector<ll>& s){



    vector<ll> v;
    vector<ll> need(s.size(),0);
    if (s.size() == 0) return need;
    v.push_back(s[0]);
    need[0] = v.size();

    for (int i = 1; i < s.size(); ++i){
        ll tmp = s[i];

        if (tmp > v.back())
            v.push_back(tmp);
        else
            *lower_bound(v.begin(), v.end(), tmp) = tmp;

        need[i] = v.size();
    }
    return need;
    //return v.size();
}

vector<ll> LDS(vector<ll>& s){


    vector<ll> v;
    vector<ll> need(s.size(),0);
    if (s.size() == 0) return need;
    v.push_back(s[0]);
    need[0] = v.size();

    for (int i = 1; i < s.size(); ++i){
        ll tmp = s[i];

        if (tmp < v.back())
            v.push_back(tmp);
        else
            *lower_bound(v.begin(), v.end(), tmp) = tmp;

        need[i] = v.size();
        cout << need[i] << endl;
    }
    return need;
    //return v.size();
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	vector<ll>arr(n);//use for LIS
	vector<ll>rev_arr(n);//use for LDS
	for(int i=0;i<n;i++){
		cin>>arr[i];
		rev_arr[i] = arr[i];
	}
	reverse(rev_arr.begin(),rev_arr.end());

	vector<ll>temp1 = LIS(arr);
	vector<ll>temp2 = LIS(rev_arr);

	vector<ll>temp3 = LDS(arr);
	vector<ll>temp4 = LDS(rev_arr);





/*
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j]){
                temp1[i] = max(temp1[i],temp1[j]+1);
			}

			if(rev_arr[i] > rev_arr[j]){
                temp2[i] = max(temp2[i],temp2[j]+1);
			}

			if(arr[i] < arr[j]){
                temp3[i] = max(temp3[i],temp3[j]+1);
			}

			if(rev_arr[i] < rev_arr[j]){
                temp4[i] = max(temp4[i],temp4[j]+1);
			}

		}
	}
*/
	int Max1=-1,Max2=-1;
	for(int i=0;i<n;i++){
		if(Max1<temp1[i]+temp2[i]-1)Max1=temp1[i]+temp2[i]-1;
		cout << "1: " << temp1[i] << " " << temp2[i] << endl;
		if(Max2<temp3[i]+temp4[i]-1)Max2=temp3[i]+temp4[i]-1;
		cout << "2: " << temp3[i] << " " << temp4[i] << endl;
	}

	cout << max(Max1,Max2);

	return 0;
}
