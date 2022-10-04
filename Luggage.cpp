#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;

int dp[40][5000];

int main(){
    int m;
    scanf("%d ", &m);
    while(m--){
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> weights;
        int sum = 0;
        int weight;
        while(ss >> weight){
            weights.push_back(weight);
            sum += weight;
        }
        if(sum % 2 == 1){
            printf("NO\n");
            continue;
        }
        else{
            vector<bool> isOneBootPossibleLoadWeight(sum + 1, false);
            isOneBootPossibleLoadWeight[0] = true;
            for(int i = 0 ; i < weights.size() ; ++i){
                for(int j = sum ; j >= weights[i] ; --j){
                    if(isOneBootPossibleLoadWeight[j - weights[i]]){
                        isOneBootPossibleLoadWeight[j] = true;
                    }
                }
            }
            printf("%s\n", (isOneBootPossibleLoadWeight[sum / 2] ? "YES" : "NO"));

        }

    }
    return 0;
}
