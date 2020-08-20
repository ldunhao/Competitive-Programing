#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int C[31700000], P[4000001], np;

void GeraCrivo (int n){    
  int i, rq, t, d;

  for (i=1; i<=n; i++)   C[i] = i;

  for (i=2; i<=n; i+=2)  C[i] = 2;

  rq = sqrt(n);
  for (i=3; i<=rq; i+=2){   
    if (C[i] == i){   
      t = i*i;  d = i+i;
      while(t<=n){   
        if (C[t] == t) C[t] = i;
        t = t+d;
      }
    }
  }
}

void GeraPrimos (int rq){    
  np=0;
  for (int i=2; i<=rq; i++) if (C[i]==i)  P[++np]= i;
}

bool TestaPrimo (long long int q){    
  bool primo = true;
  for (int i=1; i<=np; i++){   
    if ((q % P[i]) == 0){   
      if (q != P[i]) primo = false;
          break;
    }    
  }
  return (primo);
}

int main() {
  int n,x;
  int rq;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  rq=sqrt(10000000000)+1;
  GeraCrivo(rq);
  GeraPrimos(rq);

  cin >> n;
  while(n--){
    cin >> x;
    TestaPrimo(x) ? cout << "Prime" << endl : cout << "Not Prime" << endl;
  }
  return 0;
}