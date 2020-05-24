
const int32_t M = 1e9 + 7;
struct Mint{
    int64_t x;
    Mint(int64_t x = 0) : x((x % M + M) % M){}
    Mint operator -() const { return Mint(-x);}
    Mint& operator += (const Mint a){
        if((x += a.x) >= M)x -= M;
        return *this;
    }
    Mint& operator -=(const Mint a){
        x -= a.x;
        if(x < 0)x += M;
        return *this;
    }
    Mint& operator *= (const Mint a){
        (x *= a.x) %= M; return *this;
    }
    Mint operator + (const Mint a) const {
        return Mint(*this) += a;
    }
    Mint operator - (const Mint a) const {
        return Mint(*this) -= a;
    }
    Mint operator * (const Mint a) const {
        return Mint(*this) *= a;
    }
    Mint& operator ++(){
        x += 1;
        return *this;
    }
    Mint& operator --() {
        x -= 1;
        return *this;
    }

    //some functions
};
istream& operator>>(istream& is , const Mint a){return is >> a.x;}
ostream& operator<<(ostream& os , const Mint a){return os << a.x;}

Mint qpow(Mint a , int n){
    Mint res = 1;
    for(;n;n>>=1){
        if(n&1LL){
            res *= a;
        }
        a = a * a;
    }
    return res;
}