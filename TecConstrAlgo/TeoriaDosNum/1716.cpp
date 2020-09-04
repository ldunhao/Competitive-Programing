#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9-1;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int C[31700000], P[4000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];

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

void Fatora (long long int q){    
  int rq = sqrt(q)+1;
  nf = 0; 
  for (int i=1; i <=np; i++){   
    while((q % P[i]) == 0){   
      F[++nf] = P[i];  q = q/P[i];
    }
    if (q == 1 || P[i] >= rq) break;  
  }
  if (q != 1) F[++nf] = q;
}

int inv(int a, int m) { 
  int m0 = m, t, q; 
  int x0 = 0, x1 = 1; 

  if (m == 1) return 0; 

  while (a > 1){ 
    q = a / m; 
    t = m; 
    m = a % m, a = t; 
    t = x0; 
    x0 = x1 - q * x0; 
    x1 = t; 
  } 

  if (x1 < 0) x1 += m0; 

  return x1; 
} 

lli gcd(lli a, lli b) {  
  if (a == 0) return b;  
  return gcd(b % a, a);  
}  

long long fast_exp(long long a, long long b, long long m){
  long long result = 1;
  while(b){
      if(b & 1) result = (result * a) % m;
      a = (a * a) % m;
      b >>= 1;
  }
  return result;
}

int main(){
  lli chave1,chave2,crypt;
  lli pq,t,d,ans;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> chave1 >> chave2 >> crypt;

  rq = sqrt(chave1)+1;
  GeraCrivo(rq);
  GeraPrimos(rq);
  Fatora(chave1);

  int p1=F[1],p2=F[2];

  t = (p1-1)*(p2-1);
  d = inv(chave2,t);

  ans = fast_exp(crypt,d,chave1);

  cout << ans << endl;

  return 0;
}