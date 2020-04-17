#include <bits/stdc++.h>

using namespace std;
// this graph is one based indexed
template<typename T>
class graph{
   public:
        vector<vector<T> > g;
        vector<bool> vis;
        vector<T> dist;
        vector<T> sz;
        vector<T>cl;
        vector<T>dp;
        vector<T>bg[2];
        vector<T>squares;
        int n;
        bool bprt;
    public:graph(int _n) : n(_n){
        g.resize(n + 1);
        for(int i = 1 ; i <= n; ++i){
            vector<T>v;
            g.push_back(v);
        }
        vis.resize(n + 1 , 0);
        dist.resize(n + 1, -1);
        sz.resize(n + 1, 0);
        cl.resize(n + 1, -1);
        dp.resize(n + 1, 0);
    }
    void addE(T a , T b , bool dir = 0){
        g[a].push_back(b);
        if(!dir){
            g[b].push_back(a);
        }
    }
    void dfsTree(T u , T pr){
        dp[u] = dp[pr] + 1;
        sz[u] = 1;
        for(int& v : g[u]){
            if(v != pr){
                dfs(v , u);
                sz[u] = sz[v] + 1;
            }
        }
    }
    void bipert(T u , T pr){
        cl[u] = pr;
        bg[pr].push_back(u);
        for(auto v: g[u]){
            if(cl[v] == -1)
            bipert(v,1-pr);
            if(cl[v] == cl[u])
            bprt = true;
        }
    }
    void write(){
        for(int i = 0 ; i < g.size(); ++i){
            for(int j = 0 ; j < g[i].size(); ++j){
                cout<<g[i][j]<<" ";
            }
            puts("");
        }
    }
};

void done(){
    int n , m; cin>>n>>m;
    graph<int>g(n + 1);
    for(int i = 0 ; i < m; ++i){
        int x , y ; cin>>x>>y;
        g.addE(x , y);
    }
    g.bipert(1, 0);

}
