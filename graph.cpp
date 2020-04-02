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
void dfs(int u , int pr){
    if(color[u] == 2)return;
    if(color[u] == 1){
        times++;
        int cur = pr;
        mark[cur] = times;
        while(cur != u){
            cur = par[cur];
            mark[cur] = times;
        }
        memset(mark , 0 , sizeof(mark));
        memset(par, 0 , sizeof(par));
        return;
    }
    color[u] = 1;
    par[u] = pr;
    for(int i : g[u]){
        if(i == par[u])continue;
        dfs(i , u);
    }
    color[u] = 2;
}
///MAZE GRID MINIMUM OR MAXIMUM PATH BFS ///
const int deltaX[4] = {-1 , 1, 0 , 0};
const int deltaY[4] = {0 , 0 , -1 , 1};
char grid[26][26];
int h , w;
bool ok(int x , int y){
    return x >-1 && x < h && y >-1 && y < w && grid[x][y]=='.';
}
int BFS(int x , int y){
    int dist[26][26];
    int ans = 0;
    memset(dist, -1 , sizeof(dist));
    dist[x][y] = 0;
    queue<pair<int, int> > q;
    q.push({x, y});
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        for(int d = 0 ; d < 4; ++d){
            pair<int,int> new_pos = {pos.first + deltaX[d]  , pos.second + deltaY[d]};
            if(ok(new_pos.first , new_pos.second)){
                if(dist[new_pos.first][new_pos.second] == -1){
                    dist[new_pos.first][new_pos.second] = dist[pos.first][pos.second] + 1;
                    ans = max(dist[new_pos.first][new_pos.second] , ans);
                    q.push(new_pos);
                }
            }
        }
    }
    return ans;
}
