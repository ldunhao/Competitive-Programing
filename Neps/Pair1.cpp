#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,t;
    vector<pair<string, int> > jogadores;
    vector<pair<int, string> > ord_h;
    pair<int, string> tmp_sort;
    pair<string, int> tmp;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    cin >> n >> t;
    int qntdT = n/t;

    vector<vector<pair<string,int> > > times(t,vector<pair<string, int> > (qntdT+1));

    for(int i=0;i<n;i++){
        cin >> tmp_sort.second >> tmp_sort.first;
        ord_h.push_back(tmp_sort);
    }

    sort(ord_h.begin(), ord_h.end());

    for(int i=ord_h.size()-1; i>=0 ;i--){
        tmp.second = ord_h[i].first;
        tmp.first = ord_h[i].second; 
        jogadores.push_back(tmp);
    }
    for(int i=0;i<ord_h.size();i++) cout << jogadores[i].first << " " <<jogadores[i].second << endl;
    
    for(int i=0;i<ord_h.size();i++){
        times[i%t].push_back(jogadores[i]);
    }

    for(int i=0; i<times.size(); i++){
        cout << "Time " << i+1 << endl;
        for(int j=0; j<times[i].size();i++){
            cout << times[i][j].first << endl;
        }
        cout << endl;
    }
}