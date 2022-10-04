#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

struct node{
    string word;
    node* next;
};

bool is_alp(char ch){
    return ('a'<=ch && 'z'>=ch)||('A'<=ch && 'Z'>=ch);
}

bool is_num(char ch){
    return '0'<=ch && '9'>=ch;
}

int main(void){
    node* head=NULL;
    string word;
    char ch = getchar();
    while(true){
        if(is_num(ch)){
            if(ch == '0') break;
            int num = 0;
            while(is_num(ch)){
                num = num * 10 + (ch - '0');
                ch = getchar();
            }
            node *now = head, *prev = NULL;
            for(int i = 1; i < num ; i ++){
                prev = now;
                now = now->next;
            }
            cout << now->word;
            if(now != head){
                prev->next = now->next;
                now->next = head;
                head = now;
            }

        }
        else if(is_alp(ch)){
            string word;
            while(is_alp(ch)){
                word += ch;
                ch = getchar();
            }
            cout << word;
            node *n = new node;
            n->word = word;
            n->next = head;
            head = n;

        }
        else{
            putchar(ch);
            ch = getchar();
        }
    }
}
