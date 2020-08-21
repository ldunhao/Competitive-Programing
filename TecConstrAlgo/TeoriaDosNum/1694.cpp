#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << " "; cout << endl;

const long long int mod = 1e9+7;

typedef long long int lli;
typedef vector<vector<int>> matrix;

bool TestaPrimo (int q){    
  int rq;   
  bool primo=true;
  rq = sqrt(q);
  for (int i=2; i<=rq; i++)
      if ((q % i) == 0)
      {   primo = false;
          break;
      }    
  return (primo);
}

lli combinacao(lli n, lli k){
  if(k==0) return 1;
  else return combinacao(n-1,k-1)*n/k;
}

int main(){
  lli n,m,k,num=0,cont=0;
  matrix matriz;
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  while(cin >> n >> m >> k){
    if(n==0) break;

    for(int i=0;i<n;i++){
      vector<int> aux;
      for(int j=0;j<m;j++){
        num = i*m+j;
        if(num>1 && TestaPrimo(num)) num = -1;
        aux.push_back(num);
      }
      matriz.push_back(aux);
    }

    num = 0;
    cont = 0;


    if(n==1 && m==1 & k==1) num=1;
    else if(n==1){
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(matriz[i][j] != -1) cont++;
        }
        num+=combinacao(cont,k);
        cont = 0;
      }
    }else if(n==1){
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(matriz[i][j] != -1) cont++;
        }
        num+=combinacao(cont,k);
        cont = 0;
      }
    }else if(m==1){
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(matriz[j][i] != -1) cont ++;
        }
        num+=combinacao(cont,k);
        cont = 0;
      }
    }else{
      cont=0;
      if(m>1){
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matriz[i][j] != -1) cont++;
          }
          num+=combinacao(cont,k);
          cont = 0;
        }
      }
      
      cont = 0;
      if((n>1 && k>1)){
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(matriz[j][i] != -1) cont ++;
          }
          num+=combinacao(cont,k);
          cont = 0;
        }
      }
    }

    cout << num << endl;
    matriz.clear();
  }

  

  return 0;
}