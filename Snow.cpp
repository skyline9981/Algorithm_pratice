#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long



int main(void){
    int testcase;
    char s[1024];
    scanf("%d", &testcase);
    while(getchar() != '\n');
    while(getchar() != '\n');
    while(testcase--) {
        gets(s);
        double x1, y1, x2, y2;
        double dist = 0;
        while(gets(s) && s[0] != '\0') {
            sscanf(s, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            dist += hypot(x1 - x2, y1 - y2);
        }
        dist = dist / 1000; // km
        double hh = dist * 2 / 20; // * 2 (with one lane in each direction)
        int mm = (int)round(hh * 60);
        printf("%d:%02d\n", mm/60, mm%60);
        if(testcase)
            puts("");
    }
    return 0;
}
