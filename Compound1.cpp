#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <utility>
using namespace std;

int to_int(string str) {
    int ans=0;
    for (int i=0;i<str.length();i++) {
        ans = ans*10+(str[i]-'0');
    }
    return ans;
}

map<string, int> solve(string str, int &idx){
    map<string, int> mymap;
    map<string, int> ::iterator iter;
    string curr = "";
    while (idx<str.length()){
        if (isupper(str[idx])){
            curr +=str[idx];
            if (idx+1<str.length()&&isdigit(str[idx+1])){
                int shift=1;
                string str_num="";
                while (idx+shift<str.length()&&isdigit(str[idx+shift])){
                    str_num+=str[idx+shift];
                    shift++;
                }
                int num = to_int(str_num);
                idx+=(shift-1);
                mymap[curr]+=num;
                curr="";
            }
            else if (idx+1<str.length()&&!(islower(str[idx+1]))){
                mymap[curr]++;
                curr="";
            }
        }
        if (islower(str[idx])){
            curr +=str[idx];
            if (idx+1<str.length()&&isdigit(str[idx+1])){
                int shift=1;
                string str_num="";
                while (idx+shift<str.length()&&isdigit(str[idx+shift])){
                    str_num+=str[idx+shift];
                    shift++;
                }
                int num = to_int(str_num);
                idx+=(shift-1);
                mymap[curr]+=num;
                curr="";
            }
            else if(idx+1<str.length()){
                mymap[curr]++;
                curr="";
            }
        }
        if (str[idx]=='('){
            idx++;
            map<string, int> submap = solve(str, idx);
            map<string, int>::iterator iter;
            for (iter = submap.begin(); iter != submap.end();iter++) {
                mymap[iter->first]+= iter->second;
            }
        }
        if (str[idx]==')'){
            if (idx+1<str.length()&&isdigit(str[idx+1])){
                int shift=1;
                string str_num="";
                while (idx+shift<str.length()&&isdigit(str[idx+shift])){
                    str_num+=str[idx+shift];
                    shift++;
                }
                int num = to_int(str_num);
                idx+=(shift-1);
                for (iter=mymap.begin(); iter!=mymap.end();iter++){
                    mymap[iter->first]*=num;
                }
                curr="";
            }
            return mymap;
        }
        idx++;
    }
    if (curr.length()>0){
        mymap[curr]++;
    }
    return mymap;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str;
    cin>>str;
    int idx=0;
    map<string ,int> mymap=solve(str,idx);
    map<string,int> ::iterator iter;
    vector<pair<string,int> > str1;
    vector<pair<string,int> > str2;
    for (iter = mymap.begin(); iter != mymap.end();iter++){
        if (iter->first.length() ==1){
            str1.push_back(make_pair(iter->first,iter->second));
        }
        else if (iter->first.length()==2){
            str2.push_back(make_pair(iter->first,iter->second));
        }
    }
    cout<<str1.size()<<endl;
    for (int i=0;i<str1.size();i++){
        cout<<str1[i].first<<":"<<str1[i].second<<"\n";
    }
    cout<<str2.size()<<endl;
    for (int i=0;i<str2.size();i++){
        cout<<str2[i].first<<":"<<str2[i].second<<"\n";
    }
}