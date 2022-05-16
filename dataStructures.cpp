#include <bits/stdc++.h>

using namespace std;


/*******************************segment tree with struct****************************************************/

const int N = 2e5+1;
 
int arr[N];
 
struct Item{
  int min , sum;
}tree[4*N];
 
Item merge(Item a, Item b){
  return {min(a.min, a.sum + b.min),a.sum+b.sum};
};
Item nothing(){
  return {INT_MAX,0LL};
};
Item single(int a){
  return {a,a};
}
 
void build(int node, int L, int R){   // build(1 , 0 , n - 1)
  if(L==R){
    tree[node]=single(arr[L]);
    return;
  }
  int m=(L+R)>>1;
  build(2*node,L,m);
  build(2*node+1,m+1,R);
  tree[node]=merge(tree[2*node],tree[2*node+1]);
}
 
void update(int node,int L,int R,int l,int r,int val){ // point update(1 , 0 , n - 1 , index , index , value)
  if(l<=L&&R<=r){
    tree[node] = single(val);
    return;
  }
  if(r<L||l>R)return;
  int m=(L+R)>>1;
  update(2*node,L,m,l,r,val);
  update(2*node+1,m+1,R,l,r,val);
  tree[node]=merge(tree[2*node],tree[2*node+1]);
}
 
Item reply(int node,int L, int R, int l, int r){
  if(l<=L&&R<=r){
    return tree[node];
  }
  if(r<L||l>R)return nothing();
  int m=(L+R)>>1;
  return merge(reply(2*node,L,m,l,r),reply(2*node+1,m+1,R,l,r));
}

/****************************************segment tree with struct******************************************/











const  int N = 1e6;

int arr[N] , n;

struct info{
    int odd;
    int even;
    int val;
};
info t[N];
/// segment tree 1 based index
void init(int node, int b, int e)
{
    if (b == e) {
        t[node].even = !(arr[b]%2);
        t[node].odd = (arr[b] % 2);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    t[node].even = t[Left].even + t[Right].even;
    t[node].odd = t[Left].odd + t[Right].odd;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; 
    if (b >= i && e <= i) { 
        t[node].odd = newvalue%2==0;
        t[node].even = !(newvalue%2);
        return;
    }
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    t[node].odd = t[Left].odd + t[Right].even;
    t[node].even = t[Left].even + t[Right].even;
}

int queryOdd(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; 
    if (b >= i && e <= j)
        return t[node].odd;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = queryOdd(Left, b, mid, i, j);
    int p2 = queryOdd(Right, mid + 1, e, i, j);
    return p1 + p2; 
}
int queryEven(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; 
    if (b >= i && e <= j)
        return t[node].even;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = queryEven(Left, b, mid, i, j);
    int p2 = queryEven(Right, mid + 1, e, i, j);
    return p1 + p2; 
}
// fenwick Tree 1 based index


void modify(int id , int val){
	for(; id <= n ; id += id & -id){
		bit[id] += val;
	}
}
int get(int r ){
	int res = 0;
	for(; r > 0 ; r -= r & -r){
		res += bit[r];
	}
	return res;
}
 
const int N = 2e5+5;
struct node{
  int64_t s,mn,lz;
} t[4*N];
 
void apply(int v, int64_t new_val, int tl,int tr){
  t[v].s += new_val*(tr-tl+1);
  t[v].lz += new_val;
}
void push(int v, int tl, int tm, int tr){
  apply(2*v,t[v].lz,tl,tm);
  apply(2*v+1,t[v].lz,tm+1,tr);
  t[v].lz = 0;
}
 
int n,q;
 
void update(int pos, int new_val,int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) {
        t[v].s = new_val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v,tl,tm,tr);
        if (pos <= tm)
            update(pos,new_val,v*2,tl,tm);
        else
            update(pos,new_val,v*2+1,tm+1,tr);
        t[v].s = t[v*2].s + t[v*2+1].s;
    }
}
 
void update2(int l, int r,int64_t new_val,int v=1, int tl=0,int tr=n-1){ // lazy propagation
  if(l<=tl&&r>=tr){
    apply(v,new_val,tl,tr);
    return;
  }
  int tm = (tl+tr)>>1;
  push(v, tl, tm, tr);
  if(l<=tm){
    update2(l,r,new_val,2*v,tl,tm);
  }
  if(tm<r){
    update2(l,r,new_val,2*v+1,tm+1,tr);
  }
}
 
int64_t query(int l,int r,int v=1, int tl=0, int tr=n-1) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v].s;
    }
    if(l<=tl&&tr<=r){
      return t[v].s;
    }
    int tm = (tl + tr) >> 1;
    push(v,tl,tm,tr);
   /* return (l<=tm?query(l,r,2*v,tl,tm):0)+(tm<r?query(l,r,2*v+1,tm+1,tr):0);*/
    return query(l,min(r,tm),v*2, tl, tm)
           + query(max(l,tm+1),r,v*2+1, tm+1, tr);
}
struct node{
  int64_t s , lz;
  bool lz2 = 0;
};
 
struct segmentTree{
  int32_t n ;
  int64_t s , mn , lz;
  bool lz2 = 0;
  vector<node>t;
  segmentTree(int32_t x):n(x),t(4*x + 5){}
  void apply(int v, int64_t new_val,bool x2, int tl,int tr){
    if(x2){
     t[v].s = 0;
     t[v].lz = 0;
     t[v].lz2 = 1;
    }
    t[v].s += new_val*(tr-tl+1);
    t[v].lz += new_val;
  }
  void push(int v, int tl, int tm, int tr){
    apply(2*v,t[v].lz,t[v].lz2,tl,tm);
    apply(2*v+1,t[v].lz,t[v].lz2,tm+1,tr);
    t[v].lz = 0;
    t[v].lz2 = 0;
  }
   
 
  void update(int pos, int new_val,int v, int tl, int tr) {
      if (tl == tr) {
          t[v].s = new_val;
      } else {
          int tm = (tl + tr) >> 1;
          push(v,tl,tm,tr);
          if (pos <= tm)
              update(pos,new_val,v*2,tl,tm);
          else
              update(pos,new_val,v*2+1,tm+1,tr);
          t[v].s = t[v*2].s + t[v*2+1].s;
      }
  }
  void update(int pos , int64_t new_val){
    update(pos , new_val , 1 , 0 , n - 1);
  }
   
  void update2(int l, int r,int64_t new_val,bool x2,int v, int tl,int tr){
    if(l<=tl&&r>=tr){
      apply(v,new_val,x2,tl,tr);
      return;
    }
    int tm = (tl+tr)>>1;
    push(v, tl, tm, tr);
    if(l<=tm){
      update2(l,r,new_val,x2,2*v,tl,tm);
    }
    if(tm<r){
      update2(l,r,new_val,x2,2*v+1,tm+1,tr);
    }
    t[v].s = t[2*v].s+t[2*v+1].s;
  }
  //update range l,r by new_val @if x2=0 it adds new_val @else set to new_val
  void update2(int l , int r , int64_t new_val , bool x2){ 
    update2(l , r , new_val , x2 , 1 , 0 , n  - 1);
  }
   
  int64_t query(int l,int r,int v, int tl, int tr) {
      if (l > r) 
          return 0;
      if (l == tl && r == tr) {
          return t[v].s;
      }
      if(l<=tl&&tr<=r){
        return t[v].s;
      }
      int tm = (tl + tr) >> 1;
      push(v,tl,tm,tr);
     /* return (l<=tm?query(l,r,2*v,tl,tm):0)+(tm<r?query(l,r,2*v+1,tm+1,tr):0);*/
      return query(l,min(r,tm),v*2, tl, tm)
             + query(max(l,tm+1),r,v*2+1, tm+1, tr);
  }
  int64_t query(int l , int r){
    return query(l , r ,  1 , 0 ,  n - 1);
  }
  
  void write(){
    for(int i = 0 ; i < n ; ++i){
      cout << query(i , i) <<" ";
    }
    cout << "\n";
  }
};
 
