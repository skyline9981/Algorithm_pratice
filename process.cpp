#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

struct node{
    int task_num;
    int next_pos;
    int run_where=-1;
};

struct cmp{
    bool operator()(node a, node b){
        return a.next_pos < b.next_pos;
    }
};

int main(){
    fastio;
    int n,core,total_task,ans=0;
    cin >> n >> core >> total_task;

    vector<int>waiting(total_task,0);

    vector<queue<int> >pos(n+1);

    vector<int>cpu(core,-1);

    vector<int>where(n+1,-1);

    for(int i=0;i<n;i++){
        queue<int>Q;
        pos.push_back(Q);
    }

    for(int i=0;i<total_task;i++){
        int tmp_task;
        cin >> tmp_task;
        pos[tmp_task].push(i);
        waiting[i] = tmp_task;
    }
/*
    for(int i=1;i<=n;i++){
        cout<< i << ": ";
        while(!pos[i].empty()){
            int temp;
            temp = pos[i].front();
            pos[i].pop();
            cout << temp << ' ';
        }
        cout << '\n';
    }
*/

    int nowtask=0;

    priority_queue<node, vector<node>, cmp> select;

    for(int i=0;i<total_task;i++){
        //cout<<"i: "<<i<<"\n";
        //cout<<"waiting: "<< waiting[i]<<"\n";
        if(nowtask!=core){
            for(int j=0;j<core;j++){
                if(cpu[j] == -1){
                    cpu[j] = waiting[i];
                    //cout<<"waiting: "<<waiting[i]<<"\n";
                    pos[waiting[i]].pop();
                    if(pos[waiting[i]].empty()){
                        node temp;
                        temp.task_num = waiting[i];
                        temp.next_pos = INT_MAX;
                        temp.run_where = j;

                        where[waiting[i]] = j;
                        select.push(temp);

                        //cout<<"aaa"<<temp.run_where<<'\n';
                    }else{
                        node temp;
                        temp.task_num = waiting[i];
                        temp.next_pos = pos[waiting[i]].front();
                        temp.run_where = j;

                        where[waiting[i]] = j;
                        select.push(temp);

                        //cout<<"bbb"<<temp.run_where<<'\n';
                    }
                    ans++;
                    nowtask++;
                    break;
                }else{
                    if(cpu[j] == waiting[i]){
                        pos[waiting[i]].pop();
                        node temp;
                        temp.task_num = waiting[i];
                        temp.next_pos = pos[waiting[i]].front();
                        temp.run_where = j;

                        where[waiting[i]] = j;
                        select.push(temp);

                        break;
                    }
                    else continue;
                }
            }
        }
        else{
            if(where[waiting[i]] == -1){
                node needpop = select.top();
                select.pop();
                cpu[needpop.run_where] = waiting[i];

                where[needpop.task_num] = -1;
                where[waiting[i]] = needpop.run_where;

                pos[waiting[i]].pop();
                ans++;

                node temp;
                temp.run_where = needpop.run_where;

                //cout<<"ccc"<<temp.run_where<<'\n';

                temp.task_num = waiting[i];
                if(pos[waiting[i]].empty()){
                    temp.next_pos = INT_MAX;
                }else{
                    temp.next_pos = pos[waiting[i]].front();
                }

                //cout<<needpop.task_num<<'\n';
                select.push(temp);
            }
            else{
                pos[waiting[i]].pop();

                node temp;
                temp.task_num = waiting[i];
                temp.next_pos = pos[waiting[i]].front();
                temp.run_where = where[waiting[i]];

                select.push(temp);

            }
        }

    }
    cout<<ans<<'\n';
}
