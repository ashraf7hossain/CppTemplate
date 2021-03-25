
struct Union{
	int n;
	vector<int>parents,sz;
	Union(int _n){
		n = _n;
		parents.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 0 ; i <= n; ++i){
			parents[i] = i;
			sz[i] = 1;
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
		sz[x] += sz[y];
		return false;
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	void write(){
		for(int i = 0 ; i < n; ++i){
			cout << i <<" " << parents[i] << " " << sz[i] << endl;
		}
	}
};
