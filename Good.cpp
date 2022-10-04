# include<bits/stdc++.h>

typedef long long ll;
using namespace std;

// Returns the correct position of pivot element (pivot = rightmost element)
int Partition(vector<ll> &arr, int l, int r){
    ll lst = arr[r], i = l, j = l;
    while(j < r){
        if(arr[j] < lst){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}

// Utility function to find median
void MedianUtil(vector<ll> &arr, int l, int r, int k, ll& a){

    if(l <= r){
        int partitionIndex = Partition(arr, l, r);
        if(partitionIndex == k){
            a = arr[partitionIndex];
            return;
        }else if(partitionIndex > k){
            return MedianUtil(arr, l, partitionIndex - 1, k, a);
        }else{
            return MedianUtil(arr, partitionIndex + 1, r, k, a);
        }
    }
}

ll find_med(vector<ll> &v){
    ll ans, a = -1;
    int n = v.size();
    MedianUtil(v, 0, n - 1, n / 2, a);
    ans = a;
    //cout << "Median = " << ans << endl;
    return ans;
}


ll cost(vector<ll> &vec, int s, int e){
    vector<ll> v(vec.begin()+s, vec.begin()+e+1);
    //sort(v.begin(), v.end());
    ll median = find_med(v);

    ll cnt = 0;
	for(int i=s; i<=e; i++){
        cnt += abs(vec[i] - median);
	}

	return cnt;

}

ll rec(vector<ll> &vec, int start, int end){
	if( (end-start+1) <= 2 )
		return 0;

	int mid = (start+end)/2;
	ll current,first, second;
	first=rec(vec, start, mid);
	second=rec(vec, mid+1, end);
	current=min(first + cost(vec, mid+1, end), second + cost(vec, start, mid) );
	return current;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<ll> vec(N, 0);
	for(int i=0; i<N; i++){
		ll element;
		cin >> element;
		vec[i] = element;
	}
	ll ans = rec(vec, 0, N-1);
	cout<<ans;

}

/*
8
1 2 3 4 5 6 7 8

8
1 3 6 5 4 2 8 7

*/
