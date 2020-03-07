
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
///Matrix starts from here


#include <bits/stdc++.h>
 
using namespace std;
 
void add_self(int&a , int b , int M){
    a += b;
    if(a >= M){
        a -= M;
    }
}
int mul(int a , int b, int M){
    return (long long) a * b % M;
}
int Mod = 1e9 + 7;
struct Matrix{
    int r = 0 ;
    int c = 0;
    vector<vector<int> >temp;
    Matrix(int a , int b){
        temp.resize(a , vector<int>(b));
        r = a;
        c = b;
  }
  Matrix operator* (const Matrix& b)const{
      Matrix res = Matrix(r ,b.c);
      for(int i = 0 ; i < r; ++i){
          for(int j = 0 ; j < b.c; ++j){
              for(int k = 0 ; k < c; ++k){
                  add_self(res.temp[i][k], mul(temp[i][j] , b.temp[j][k] , Mod),  Mod);
              }
          }
      }
      return res;
  }
  void write(){
      for(int i = 0 ; i < r; ++i){
          for(int j = 0 ; j < c; ++j){
              printf("%d ",temp[i][j]);
          }
          puts("");
      }
  }
};
 
Matrix mpow(Matrix x , long long n){
    Matrix ans = Matrix(2 , 2);
    ans.temp = {{1 , 1},{1 , 1}};
    for(;n;n >>= 1){
        if(n&1){
            ans = ans * x;
        }
        x = x * x;
    }
    return ans;
}
