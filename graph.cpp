vector<int>cl(10000,-1);
vector<int>g[1000];
vector<int>bg[2];
int cnt[2];
bool bip;

void bipert(int u, int pr){
  cl[u] = pr;
  ++cnt[pr];
  bg[pr].push_back(u);
  for(auto v: g[u]){
    if(cl[v] == -1)
     bipert(v,1-pr);
    if(cl[v] == cl[u])
      bip = true;
  }
}

void BFS(vector<int>adj[100001] , int start , int target){
    vector<int>dist(100001 , INT_MAX);
    dist[start] = 0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x : adj[u]){
            if(dist[x] == INT_MAX){
                dist[x] = dist[u] + 1;
                q.push(x);
            }
        }
    }
    printf("%d\n" , dist[target]);
}
