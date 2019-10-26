#include <bits/stdc++.h>

using namespace std;
long long int val[10000001], soma;
int main(int argc, char const *argv[])
{
    long long int qtd, maximo, repeticao;
    cin>>qtd>>maximo>>repeticao;
    for(long long int i=1; i<=qtd; i++){
        cin>>val[i];
    }
    sort(val+1, val+qtd+1, greater<long long int>());
   soma=(maximo/(repeticao+1))*(repeticao*val[1]+val[2]) + (maximo%(repeticao+1)*val[1]);
    printf("%lld", soma);
    return 0;
}
