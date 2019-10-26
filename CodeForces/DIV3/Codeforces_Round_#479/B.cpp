#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,max=0,resp=0;
    string s;
    char a,b;

    cin >> n;
    cin >> s;

    for(int i=0; i<n-1; i++){
        
        max=1;
        for(int j=i+1;j<n-1;j++){
            if(s[i]==s[j] && s[i+1]==s[j+1]) max++;
        }
        if(resp < max){
            a=s[i];
            b=s[i+1];
            resp = max;
        }
    }
    cout << a << b <<endl;

    return 0;
}