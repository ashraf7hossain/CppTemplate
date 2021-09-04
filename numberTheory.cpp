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
bool is_composit[N];
vector<int>primes;
void LinearSieve(){
    is_composit[1] = 1;
    for(int i = 2 ; i < N; ++i){
        if(!is_composit[i]){
            primes.push_back(i);
        }
        for(int j = 0 ; j < primes.size() && i * primes[j] < N; ++j){
            is_composit[i * primes[j]] = 1;
            if(i % primes[j] == 0)break;
        }
    }
}
vector<int>phi(N + 1);
void PHI(){
    iota(phi.begin(), phi.end(), 0);
    for(int i = 2 ; i <= N; ++i){
        if(phi[i] == i){
            for(int j = i ; j <= N; j += i){
                phi[j] -= phi[j] / i; 
            }
        }
    }
}
void PrimeFactoraizattion(){   
    vector<pair<long long,int> > primeFactors;
    for(long long i = 2; i * i  <= n; ++i){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            primeFactors.emplace_back(i , cnt);
        }
    }
    if(n > 1)primeFactors.emplace_back(n , 1);
 }

class Seive{
  private: int N;
    vector<bool>is_composit;
    vector<int>primes;;

    public:
      Seive(int sz = 1e5 + 10){
        N = sz;
        is_composit.resize(N + 1);
      }
    void LinearSieve(){
      // cerr << is_composit.size() << endl;
        is_composit[1] = 1;
        for(int i = 2 ; i < N; ++i){
            if(!is_composit[i]){
                primes.push_back(i);
            }
            for(int j = 0 ; j < primes.size() && i * primes[j] < N; ++j){
                is_composit[i * primes[j]] = 1;
                if(i % primes[j] == 0)break;
            }
        }
    }
    vector<int> SegmentedSeive(int L , int R){
      bool is_prime[R - L + 1];
      // LinearSieve();
      vector<int>seg_primes;
      memset(is_prime , 1 , sizeof(is_prime));
      for(int i = 0 ; primes[i] * primes[i] <= R ; ++i){
        int now = primes[i];
        int base = (L / now) * now;
        if(base < L){
          base += now;
        }
        for(int j = base; j <= R; j += now){
            is_prime[j - L] = false;
           }
           if(base == now){
            is_prime[base-L] = true;
           }
      }
      for(int i = 0 ; i <= R - L; ++i){
        if(is_prime[i])seg_primes.push_back(i + L);
      }
      return seg_primes;

    }
    void printPrimes(){
      // cerr << primes.size();
      for(int i : primes){
        cout << i <<" ";
      }
      cout << endl;
    }
};




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
