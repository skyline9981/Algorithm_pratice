#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int LCS[1005][1005];
char a[1005];
char b[1005];

int main(void){
    while(gets(a) && gets(b)){
        memset(LCS, 0, sizeof(LCS));
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(a[i-1]==b[j-1]) LCS[i][j]=LCS[i-1][j-1]+1;
                else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
        cout<<LCS[len1][len2]<<'\n';
    }

}
