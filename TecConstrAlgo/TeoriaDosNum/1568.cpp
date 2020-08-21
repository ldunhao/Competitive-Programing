#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<int>> matrix;

int C[31700000], P[4000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];
bool teste;

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
  for (int i=2; i<=rq; i++)
      if (C[i]==i)  P[++np]= i;
}

int Fatora (long long int q){    
  int i=0, cont, resp=1, contImpar=0;
  long long int aux=q;

  if(q==0 || q==1 || q==2) return 1;

  while(aux%2==0){
      aux=aux/2;
  }

  for(int i=1; i<np; i++){
      cont=0;
      if(aux==0 || aux==1) return resp;
      if(aux%P[i]==0) contImpar++;
      while(aux%P[i]==0){
          aux=aux/P[i];
          cont++;
      }
      resp*=(cont+1);
  }
  if(resp==1) return 2;
  if(aux==1) return resp;
  else return resp*2;
}


int main(){
  lli n,ans=1, cont=0,aux=0;

  lli num = 1000000000000000;
  rq=sqrt(num)+1;
  GeraCrivo(rq);
  GeraPrimos(rq);

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> n){
    ans = Fatora(n);
    cout << ans << endl;
  }
  
  return 0;
}