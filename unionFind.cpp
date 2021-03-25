struct Union{
	int n;
	vector<int>parents,sz,mini,maxi,rank;
	Union(int _n){
		n = _n;
		parents.resize(n + 1);
		sz.resize(n + 1);
		mini.resize(n + 1);
		maxi.resize(n + 1);
		rank.resize(n + 1);
		for(int i = 0 ; i <= n; ++i){
			parents[i] = i;
			sz[i] = 1;
			mini[i] = i;
			maxi[i] = i;
		}
	}
	int find(int x){
		return (x == parents[x])?x:parents[x] = find(parents[x]);
	}
	bool unite(int _x , int _y){
		int x = find(_x);
		int y = find(_y);
		if(x == y){
			return true;
		}
		if(sz[x] < sz[y]){
			swap(x , y);
		}
		parents[y] = x;
		mini[x] = min(mini[x],mini[y]);
		maxi[x] = max(maxi[x], maxi[y]);

		sz[x] += sz[y];
		return false;
	}
	void unite_by_rank(int x , int y){
		int px = find(x), py = find(y);
		if(px == py)return;
		if(rank[px] == rank[py]){
			rank[px]++;
		}
		if(rank[px] > rank[py]){
			parents[py] = px;
			sz[px] += sz[py];
			mini[px] = min(mini[px],mini[py]);
			maxi[px] = max(maxi[px],maxi[py]);
		}else{
			parents[px] = py;
			sz[py] += sz[px];
			mini[py] = min(mini[px],mini[py]);
			maxi[py] = max(maxi[px], maxi[py]);
		}
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	void write(){
		for(int i = 0 ; i <= n; ++i){
			cout << i <<" " << parents[i] << " " << sz[i] << endl;
		}
	}
};

