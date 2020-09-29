#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end();

const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;

typedef long long int lli;
typedef vector<vector<char>> matrix;

int T[MAXN+7][MAXN+7];

int SCM(vector<char> s, vector<char> z,int n, int m){
    for(int i=0;i<n;i++) T[i][0] = 0;
    for(int i=0;i<m;i++) T[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == z[j-1]) T[i][j] = T[i-1][j-1]+1;
            else T[i][j] = max(T[i-1][j],T[i][j-1]);
        }
    }

    return T[s.size()][z.size()];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t,h,w,caso=0;

    cin >> t;

    while(t--){
      cin >> h >> w;

      char tmp;
      matrix grade;

      for(int i=0;i<h;i++){
        vector<char> tmpv;
        for(int j=0;j<w;j++){
          cin >> tmp;
          tmpv.push_back(tmp);
        }
        grade.push_back(tmpv);
      }

      int n1,x1,y1; cin >> n1 >> x1 >> y1;
      vector<char> c1;
      for(int i=0;i<n1;i++) cin >> tmp, c1.push_back(tmp);

      int n2,x2,y2; cin >> n2 >> x2 >> y2;
      vector<char> c2;
      for(int i=0;i<n2;i++) cin >> tmp, c2.push_back(tmp);

      vector<char> cam1,cam2;

      x1-=1;y1-=1;x2-=1;y2-=1;

      cam1.push_back(grade[x1][y1]);
      for(int i=0;i<n1;i++){
        if(c1[i]=='E') cam1.push_back(grade[x1][++y1]);
        if(c1[i]=='W') cam1.push_back(grade[x1][--y1]);
        if(c1[i]=='N') cam1.push_back(grade[--x1][y1]);
        if(c1[i]=='S') cam1.push_back(grade[++x1][y1]);
      }

      cam2.push_back(grade[x2][y2]);
      for(int i=0;i<n2;i++){
        if(c2[i]=='E') cam2.push_back(grade[x2][++y2]);
        if(c2[i]=='W') cam2.push_back(grade[x2][--y2]);
        if(c2[i]=='N') cam2.push_back(grade[--x2][y2]);
        if(c2[i]=='S') cam2.push_back(grade[++x2][y2]);
      }


      int s = SCM(cam1,cam2,cam1.size(),cam2.size());

      cout << "Case " << ++caso << ": " << cam1.size()-s << ' ' << cam2.size()-s << endl;
    }

    return 0;
}