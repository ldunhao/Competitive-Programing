#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int main(){
  string str;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> str;

  lli m=0,aux;
  for(int i=str.size()-1;i>=0;i--){
    aux = int(str[i])-48;
    m = (m*10 + aux)%3;
  }

  cout << m << endl;

  return 0;
}