#include <bits/stdc++.h>

using namespace std;

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
