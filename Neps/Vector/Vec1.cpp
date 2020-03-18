#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s,k;
    vector<int> vec, vec2, resp;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;

    for(int i = 0; i<n;i++){
        cin >> s;
        vec.push_back(s);
    }

    for(int i =0; i< vec.size() ; i++) cout << vec[i] << " ";
    cout << endl;

    cin >> k; 

    for(int i=0; i < k; i++){
        cin >> s;
        vec2.push_back(s);
    }

    for(int i =0; i< vec2.size() ; i++) cout << vec2[i] << " ";
    cout << endl;

    bool ok = true;

    for(int i=0; i<vec.size();i++){
        for(int j=0; j<vec2.size(); j++){
            if(vec[i]==vec2[j]){
                ok = false;
                break;
            } 
        }
        if(ok) resp.push_back(vec[i]);
        ok = true;
    }

    for(int i =0; i< resp.size() ; i++) cout << resp[i] << " "; 
}