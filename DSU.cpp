#include<bits/stdc++.h>;
using namespace std;

struct DSU {
    vector<int> root,size;
    int cc ;
    DSU(int n){
        root.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
            size[i] = 1;
        }
        cc = n;
    }
    int find_set (int x){
        if (root[x] == x) return x;
        return root[x] = find_set(root[x]);
    }
    bool union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if ( u == v ) return false;
        if(size[u] < size[v]) swap (u,v);
        root[v] = u;
        size[u] += size[v];
        cc--;
        return true;
    }
};