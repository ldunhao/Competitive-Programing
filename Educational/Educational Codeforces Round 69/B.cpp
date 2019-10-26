#include <bits/stdc++.h>
using namespace std;

long int vet[100001];

int main(int argc, char const *argv[])
{
    int n,a,maior=0,pos=0;
    bool antes=true,depois=true;
    vector<int> num;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a;
        num.push_back(a);
        if(a>maior) maior = a, pos = i;
    }
    for(int i=0;i<pos;i++){
        if(num[i]<num[i+1]) antes=true;
        else antes = false;
        if(!antes){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i=pos+1;i<n-1;i++){
        if(num[i]>num[i+1]) depois=true;
        else depois=false;
        if(!depois){
            cout << "NO" << endl;
            return 0;
        }
    }

    if(depois && antes) cout << "YES" << endl;
    return 0;
}
