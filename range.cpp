# include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<double> vec;
	double element;
	double first;
	double third;
	int N=1;
	cin >> element;
	vec.push_back(element);
	if(element){
		cout<<0<<endl;
		cin >> element;
	}
	while(element){
		N+=1;
		vec.push_back(element);
		for (int j=0; j<N-1; j++){
			if (element<=vec[j]){
				// place
				for(int k=N-1; k>j; k--){
					vec[k]= vec[k-1];
				}
				vec[j] = element;
				break;
			}
		}

		/*for(int i=0; i<N; i++){
			cout<<vec[i]<<" ";
		}*/

		int M=N/2;
		if(M%2==0){
			first= (vec[M/2] + vec[M/2-1])/2.0;
			third= (vec[(N-1+N-M)/2] + vec[(N-1+N-M)/2+1])/2.0;
		}else{
			first= vec[M/2];
			third= vec[(N-1+N-M)/2];
		}
		//cout<< "zz"<<first<<" "<<third<<endl;
		//cout << "xx" <<third-first << endl;
		double ans = third-first;
		if (ans!=(int)ans){
			ans=((int) (ans*10) )/10.0;
			cout<<ans<<endl;
			//cout <<"xx"<<fixed<<setprecision(1)<<ans<<endl;
			//cout.unsetf( ios::fixed );
		}else{
			cout<<ans<<endl;
		}

		cin >> element;
	}
	/*for(int i=0; i<N; i++){
		cout<<vec[i]<<" ";
	}*/
}
/*
-1
-2
-3
-4
-5
-6
-7
-8
-9
0

4
3
4
1
4
2
6
5
5
6
0

*/
