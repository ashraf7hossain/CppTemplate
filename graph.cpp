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
