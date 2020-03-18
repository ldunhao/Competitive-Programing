#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,minD=1000000,r;
    int cont=1000000,minC=0,minF=0;
    int disCR, disFR;
    string av;
    vector<int> posC;
    vector<int> posF;
    vector<int> posR;
    vector<pair<int,int> > pares;
    pair<int, int> par;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i<n;i++){
        cin >> av;
        for(int j=0;j<av.size();j++){
            if(av[j] == 'C') posC.push_back(j); 
            if(av[j] == 'F') posF.push_back(j);
            if(av[j] == 'R') posR.push_back(j);
        }

        for(int j=0;j<posC.size();j++){
            for(int s=0;s<posF.size();s++){
                if(abs(posC[j]-posF[s])<minD){
                    minD = abs(posC[j]-posF[s]);
                    minC = posC[j];
                    minF = posF[s];

                }
            }
        }  

        for(int j=0;j<posC.size();j++){
            for(int s=0;s<posF.size();s++){
                if(abs(posC[j]-posF[s]) == minD){
                    minC = posC[j];
                    minF = posF[s];

                    par.first = minC;
                    par.second = minF;
                    pares.push_back(par);
                }
            }
        }    
    
        int tmp = av.size();
        for(int j=0;j<posR.size();j++){
            for(int s=0;s<pares.size();s++){
                disCR = abs(pares[s].first - posR[j]);
                disFR = abs(pares[s].second - posR[j]);

                if (min(disCR,disFR) < tmp) tmp = min(disCR,disFR);
            }
        }

        cont = tmp + minD;

        // for(int j=0;j<pares.size();j++){
        //     cout << pares[j].first << " " << pares[j].second << endl; 
        // }

        cout << cont << endl;

        minD=1000000; cont=100000;minC=0;minF=0;r=0;
        posC.clear();
        posF.clear();
        posR.clear();
        av.clear();
        pares.clear();
    }

    
    return 0;
}