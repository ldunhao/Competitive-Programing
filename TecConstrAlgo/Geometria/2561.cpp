#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const int INF = 0x3f3f3f3f;
const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const long double PI = acos(-1.0);
const double QZERO = 0.000000001;
const double EPS = 1e-9;

typedef long long int lli;
typedef vector<vector<char>> matrix;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int x0,x1,y0,y1;
    int x2,x3,y2,y3;
    while(cin >> x0 >> y0 >> x1 >> y1){
        cin >> x2 >> y2 >> x3 >> y3;

        pair<int,int> p1,p2;

        p1.first = max(x0,x2);
        p2.first = min(x1,x3);
        p1.second = max(y0,y2);
        p2.second = min(y1,y3);

        double A = abs(p2.second - p1.second) * abs(p2.first - p1.first);

        pair<int,int> dc1(x0,y1),db1(x1,y0);
        pair<int,int> dc2(x2,y3),db2(x3,y2);


        if((max(dc1.first,db1.first) >= min(dc2.first,db2.first)) && 
            (max(dc2.first,db2.first) >= min(dc1.first,db1.first)) && 
            (max(dc1.second,db1.second) >= min(dc2.second,db2.second)) && 
            (max(dc2.second,db2.second) >= min(dc1.second,db1.second))){

            // cout << "(" << p1.first << "," << p1.second << ")" << endl;
            // cout << "(" << p2.first << "," << p2.second << ")" << endl;

            bool msmPonto = p1.first == p2.first && p1.second == p2.second;

            if(A == 0 && msmPonto) cout << "ponto" << endl;
            else if(A == 0) cout << "linha" << endl;
            else if(A > 10) cout << "grande" << endl;
            else cout << "adequada" << endl;
        }else cout << "inexistente" << endl;
        
       
    }


    return 0;
}