#include <bits/stdc++.h>

using namespace std;
 
 
const int MAXN = 112345;

int st[4*MAXN], lazy[4*MAXN], a[MAXN];

void build(int node, int left, int right){
    if(left == right){
        st[node] = 0;
    }else{
        int mid = (left + right)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        st[node] = st[2*node] + st[2*node + 1]; 
        
    }
}

void propagation(int node, int left, int right){
    if(lazy[node] != -1){
        st[node] += (right - left + 1) * lazy[node];                                
        if(left != right)
            lazy[2*node] = lazy[2*node + 1] += lazy[node]; // update: =, increment: +=
        lazy[node] = -1;
    }
}

void update(int node, int left, int right, int a, int b, int val){
    propagation(node, left, right);

    if(right < a || left > b) return;

    if(left >= a && right <= b){
        lazy[node] = val;
        propagation(node, left, right);
    }else{
        int mid = (left + right)/2;
        update(2*node, left, mid, a, b, val);
        update(2*node + 1, mid + 1, right, a, b, val);
        st[node] = st[2*node] + st[2*node + 1]; // RMQ -> min/max; RSQ -> +
    }
}

int query(int node, int left, int right, int a, int b){
    propagation(node, left, right);

    if(right < a || left > b) return 0; // RMQ -> INF, RSQ -> 0
    if(left >= a && right <= b){
        return st[node];
    }else{
        int mid = (left + right)/2;
        return query(2*node, left, mid, a, b) + query(2*node + 1, mid + 1, right, a, b); // RMQ -> min/max; RSQ -> +
    }
}

int main(void) { 


    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,x,p,q,v;
    int n,c;
    cin >> i;

    while(i--){
        cin >> n >> c;
        build(1,1,n);

        while(c--){
            cin >> x;
            if(x==0){
                cin >> p >> q >> v;
                update(1,1,n,p,q,v); 
            }
            if(x == 1){
                cin >> p >> q;
                cout << query(1,1,n,p,q) << endl;
            }
        }
    }   

    return 0;
}