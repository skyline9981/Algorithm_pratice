#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

using namespace std;



void countOfAtoms(string s){
    map<string, int> m;
    stack<map<string, int> > st;
    int i = 0;
    int n = s.size();
    while (i < n) {
        char c = s[i];
        i++;
        if (c == '(') {
            st.push(m);
            m = map<string, int>();
        }
        else if (c == ')') {
            int val = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                val = val * 10 + (s[i] - '0');
                i++;
            }

            if(val==0)val=1;

            map<string, int> temp = st.top();
            st.pop();

            for (auto it=m.begin();it!=m.end();it++) {
                it->second *= val;
                temp[it->first] += it->second;
            }
            m = temp;
        }
        else {
            string name = "";
            int val = 0;
            name += c;
            while (i < n && s[i] >= 'a' && s[i] <= 'z') {
                name += s[i];
                i++;
            }

            while (i < n && s[i] >= '0' && s[i] <= '9') {
                val = val * 10 + (s[i] - '0');
                i++;
            }

            if(val == 0)val = 1;
            m[name] += val;

        }
    }

    string str1="",str2="";
    vector<string>vec1;
    vector<string>vec2;
    int cnt1=0,cnt2=0;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->first.size()==1){
            cnt1++;
            str1="";
            str1+=it->first;
            str1+=":";
            str1+=to_string(it->second);
            str1+='\n';
            vec1.push_back(str1);
        }else{
            cnt2++;
            str2="";
            str2+=it->first;
            str2+=":";
            str2+=to_string(it->second);
            vec2.push_back(str2);
        }
    }
    cout<<cnt1<<'\n';
    for(int i=0;i<vec1.size();i++){
        cout<<vec1[i];
    }
    cout<<cnt2<<'\n';
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i];
        if(i!=(vec2.size()-1))cout<<'\n';
    }
}


int main(){
    fastio;
    string aa;
    cin >> aa;
    countOfAtoms(aa);
    return 0;
}
/*
Ca(OH)2
Ca(Al(OH)2)2
Ca(AlC(OH)2)2
C2O3H4
*/
