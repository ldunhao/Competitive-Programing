#include <bits/stdc++.h>

using namespace std;



int main() {

    int n,pa=0,pi=0,ra=0,ri=0;
    int ans=0;
    int maior=0,i_maior=0;
    vector<int> p;
    vector<int> r;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    
    while(cin >> n){

        for(int i=0;i<n-1;i++){
            cin >> pi >> ri;
            p.push_back(pi);
            r.push_back(ri);

            if(pi>maior){
                maior = pi;
                i_maior = i;
            }
        }
        
        if(r[i_maior] == 0) ans++;

        for(int i=i_maior+1;i<p.size();i++){
            if(r[i] == 1 ) ans++;
        }


        cout << ans << endl;
        ans=0;
        maior=0;
        i_maior=0;
        p.clear();
        r.clear();
    }

    return 0;
}