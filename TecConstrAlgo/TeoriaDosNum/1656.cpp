#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, n;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while (cin >> c >> n) {
    if (c == 0 || n == 0) {
        break;
    }

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int sum = 0;
    vector<int> m(c, -1);
    m[0] = 0;

    for (int i = 0; i < n; i++) {
      sum = (sum + v[i]) % c;

      if (m[sum] >= 0) {
          for (int j = m[sum]; j <= i; j++) {
              cout << j + 1 << " \n"[j == i];
          }
          break;
      }

      m[sum] = i + 1;
    }
  }

  return 0;
}