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
