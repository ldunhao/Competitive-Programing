#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n,k,a;
    vector<int> num;

    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        cin >> a;
        num.push_back(a);
    }

    if (n == k) cout << 0 << endl;
    else if (k == 1) cout << num[n-1] - num[0] << endl;
    else {
        int i=0, f=n-k, menor=num[n-1]+10; 
        while(f!=n){
            if((num[f]-num[i])<menor){
                menor=(num[f]-num[i]);
            }
            f++;
            i++;
        }
        cout<<menor<<endl;
        num.clear();
    }

    return 0;
}