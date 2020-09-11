#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int MOD = 1e9-1;
const long long int MAXN = 1e6;
const double pi = 2 * acos(0.0);

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int find_lis(vector<pair<double,double>> v){
    int n = v.size(), len=0;
    vector<int> tam(n), dad(n);

    for(int i = 0; i < n; i++){
        int lo=0, hi=len;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(v[tam[mid]].second<v[i].second) lo = mid+1;
            else hi=mid;
        }
        dad[i] = (lo>0) ? tam[lo-1] : -1;
        tam[lo] = i;
        if(lo == len) len++;
    }

    vector<pair<double,double>> ans(len);

    for (int u = tam[len-1], i = len-1; u != -1; u = dad[u], i--)
        ans[i] = v[u];
    
    return ans.size();
}

int main(){ 
  int n;double xa,xb;

  vector<pair<int,int>> points;
  vector<pair<double,double>> angs; 

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n >> xa >> xb;

  double hip=(xb-xa);
  while(n--){
    int x,y;cin >> x >> y;
    points.push_back(make_pair(x,y));

    double angleA,angleB;

    angleA = atan2(y,abs(x-xa));
    angleB = atan2(y,abs(x-xb));

    angleA = angleA*180/pi;
    angleB = angleB*180/pi;

    angs.push_back(make_pair(angleA,angleB));

    sort(all(angs));
  }

  int ans = find_lis(angs);

  cout << ans << endl;
  
  return 0;
}