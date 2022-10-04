#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
typedef pair<int,int> pii;



void toEast(int* arr){
    int t = arr[0];
    arr[0] = arr[3];
    arr[3] = arr[1];
    arr[1] = arr[5];
    arr[5] = t;
}

void toWest(int* arr){
    int t = arr[0];
    arr[0] = arr[5];
    arr[5] = arr[1];
    arr[1] = arr[3];
    arr[3] = t;
}

void toNorth(int* arr){
    int t = arr[0];
    arr[0] = arr[4];
    arr[4] = arr[1];
    arr[1] = arr[2];
    arr[2] = t;
}

void toSouth(int* arr){
    int t = arr[0];
    arr[0] = arr[2];
    arr[2] = arr[1];
    arr[1] = arr[4];
    arr[4] = t;
}

int main(){
    int times;
    while(cin >> times && times!=0){
        int faces[6] = {1, 6, 2, 3, 5, 4};
        while(times--){
            string a;
            cin >> a;
            if(a=="north"){
                toNorth(faces);
            }
            else if(a=="south"){
                toSouth(faces);
            }
            else if(a=="west"){
                toWest(faces);
            }
            else if(a=="east"){
                toEast(faces);
            }
        }
        cout << faces[0] << endl;
    }
    return 0;
}
