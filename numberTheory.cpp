
long long inverse(int a, int md){
  a %= md;
  if(a<0)a += md;
  int b = md, u=0,v=1;
  
  while(a){
    int q = b / a;
    b = b - q * a; swap(a,b);
    u = u - q * v; swap(u,v);
    
  }
  assert(b == 1);
  return (u < 0)?u+md:u;
  
}
long long qpow(long long a , long long n , long long M){
    a %= M;
    long long res = 1LL;
    for(;n;n>>=1){
        if(n&1LL){
            res *= a;
            res %= M;
        }
        a = (a * a) % M;
    }
    return res;
}
long long QC(long long n , int r , long long M){
    long long res = 1;
    n %= M;
    for(int i = 1 ; i <= r; ++i){
        res = (res * (n - i + 1)) % M;
        res = res * inverse(i , M);
        res %= M;
    }
    return res;
}
vector <bool> p(N,0);
void sieve(){
    p[1] = 1;
    for(long long i=2;i*i<=N;i++){
        if(p[i]==0){
            for(long long j=i*i;j<=N;j+=i){
                p[j] = 1;
            }
        }
    }
}
