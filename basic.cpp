#include <bits/stdc++.h>
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define fi first
#define se second
#define pb push_back
#define read(type, ...)type __VA_ARGS__; macro_scan(__VA_ARGS__);

using namespace std;

template<typename T> void macro_scan(T& t){cin>>t;};
template<typename F, typename ...R>void macro_scan(F& f , R& ...r){
  cin>>f;macro_scan(r...);
}

void deb(){
    cerr<<endl;
}
template<typename T , typename... t>
void deb(T a , t...b){
    cerr<<a<<" ";
    deb(b...);
}
template<typename T>
void dev(vector<T>v){
    int c = 0;
    for(auto i : v){
        cerr<<i<<" ";
        c++;
    }
    cerr<<endl;
}

void done(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t; cin>>t;for(;t--;)done();
}


