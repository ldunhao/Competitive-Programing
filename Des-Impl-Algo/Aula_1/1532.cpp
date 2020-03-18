#include <bits/stdc++.h>

using namespace std;

int n = 0,v = 0,contDist = 0, contTemp = 0;
vector<int> buracos;

bool calcula (int n, int v) {
    bool ok = false;
    
    while(v!=0) {

        for (int i=0; i<v;i++){
            contTemp+=v;
            if(contTemp > n) break;
            //buracos.push_back(contTemp);
            if(contTemp == n) ok = true;
        }

        v--;
    }


    // for(int i=0;i<buracos.size(); i++){
    //         cout << buracos[i] << " ";
    // }

    // cout << endl;
    // cout << endl;
    // buracos.clear();
    contTemp = 0;


    return ok;
}

int main(){
    
    bool ok = false;

    cin >> n >> v;
    while (n!=0 && v!=0){

        
        for (int i = v; i>0 ; i--){
            ok = calcula(n,v);
            v--;

            if (ok) break;
        }

        cout << ((ok) ? "possivel" : "impossivel") << endl;

        ok = false;
        contTemp = 0;
        n = 0; v = 0;
        cin >> n >> v;
    }
    
    return 0;
}