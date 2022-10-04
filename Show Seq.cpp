#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

long long a[128];

void parsing(char s[]) {
    int sign = 1, i, m = 0;
    char pos;
    for(i = 1; s[i]; i++) {
        if(s[i] == '-')	sign = -1;
        else if(s[i] >= '0' && s[i] <= '9')
            m = m * 10 + s[i] - '0';
        else {
            pos = s[i];
            break;
        }
    }
    m = sign * m;
    if(pos == '+') {
        parsing(s + i + 1);
        long long d = a[0];
        a[0] = m;
        for(int i = 1; i < 50; i++) {
            long long t = a[i];
            a[i] = a[i - 1] + d, d = t;
        }
    }
    else if(pos == '*') {
        parsing(s + i + 1);
        a[0] *= m;
        for(int i = 1; i < 50; i++)
            a[i] = a[i] * a[i-1];
    }
    else {
        for(int i = 0; i < 50; i++)
            a[i] = m;
    }
}

int main() {
    char s[1024];
    int n;
    while(scanf("%s %d", s, &n) !=EOF) {
        memset(a, 0, sizeof(a));
        parsing(s);
        for(int i = 0; i < n; i++)
            printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
