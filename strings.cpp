#include <bits/stdc++.h>

using namespace std;

class Hash {

  const int M = 1e9 + 7;
  string s;
  static const int sz = (int)2e5 + 5;
  const int cnt = 2;
  long long p[2][sz], inv[2][sz];
  vector<long long>h[2];
  int N = 200005;
  int BASE[2] = {
    313,
    499
  };
  long long qpow(long long a, long long n) {
    a %= M;
    long long res = 1LL;
    for (; n; n >>= 1) {
      if (n & 1LL) {
        res *= a;
        res %= M;
      }
      a = (a * a) % M;
    }
    return res;
  }
  public:
    Hash(int i, string _s) {
      s = _s;
      N = s.size();
      p[i][0] = 1LL;
      for (int j = 1; j < sz; ++j) {
        p[i][j] = (long long)(p[i][j - 1] * BASE[i]) % M;
      }
      inv[i][sz - 1] = qpow(p[i][sz - 1], M - 2);
      // cerr << "inv : "<<inv[i][N] << "\n";
      for (int j = sz - 1; j > 0; --j) {    
        inv[i][j - 1] = (long long)(inv[i][j] * BASE[i]) % M;
      }
      h[i].push_back((long long)s[0]);
      for (int j = 1; j < N; ++j) {
        long long cur = (h[i].back() + (long long)(s[j] * p[i][j]) % M) % M;
        h[i].push_back(cur);
      }

    }
  long long get(int l, int r, int i) {
    if(!l)return h[i][r];
    int ret = (h[i][r] - h[i][l - 1] + M) % M;
    // cerr <<" get " << ret << "\n";
    ret = (long long)(ret * inv[i][l]) % M;
    return ret;
  }
  void push(int i , char c){
    // s.push_back(c);
    N++;
    long long cur = ((h[i].back() * BASE[i])%M + (int)c)%M; 
    h[i].push_back(cur);
  }
  void insert(int i , char c){
    // s.insert(s.begin() , c);
    long long cur = (((int)c * p[i][N])%M + h[i].back())%M;
    h[i].push_back(cur);
    N++;
  }
};

void done(){
  int n ; cin >> n;
  string s; cin >> s;
  Hash fi = Hash(0 , s);
  string t = s;
  reverse(s.begin(),s.end());
  Hash se = Hash(0 , s);
  // cout << fi.get(0 , )
  for(int i = 0 ; i < n; ++i){
    fi.push(0 , t[i]);
    se.insert(0 , t[i]);
    if(fi.get(0 , n + i  , 0) == se.get(0 , n + i, 0)){
      cout << t.substr(0, i + 1) << "\n";
      return;
    }
  }
}

int main(){
  int t; cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #"<<i<<": ";
    done();
  }
}