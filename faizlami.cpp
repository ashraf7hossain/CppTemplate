/*********************************************************************************************************
 
                                                ___________________         _______________________________   _____
                /***************\               |                   *       /                             /  |     |
               /                 \              |                     *    /                             /   |     |
              /      ______       \             |                       * /__________________           /    |     |
             /      /      \       \            |      ______________    *                   /         /     |     |
            /      /        \       \           |     |              |                      /         /      |     |
           /      /          \       \          |     |______________|   *                 /         /       |     |
          /      /____________\       \         |      _____            *                 /         /        |     |
         /      _______________\       \        |     |     \         *                  /         /         |     |
        /      /                \       \       |     |      \     *                    /         /          |     |
       /      /                  \       \      |     |       \    \                   /         /           |     |
      /      /                    \       \     |     |        \    \                 /         /            |     |
     /      /                      \       \    |     |         \    \               /         /             |     |_____________
   /______/                          \_______\  |_____|           \____\           /_________/               |___________________|
 
 
 
 
 
 
 
 
 
**************************************************************************************************************************/
 
#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
 
bool isPerfectSquare(int x)
{
        int s = sqrt(x);
        return (s*s == x);
}
 
bool isFibonacci(int n)
{
        return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}
bool odd(int a, int b, int c){
        if(a+b > c && a+c > b && b+c > a)return true;
        return false;
}
 
bool  getS(int n){
           int s = 0;
           bool b;
           while(n){
               s += n%10;
               n /= 10;
           }
           (s==10)?b = true : b = false;
           return b;
 
}
//vector< int > v;
 
bool checkDuplicates( vector<int> array, int n)
{
        sort(array.begin(), array.end());
        int i;
        for( i = 0; i < n-1; i++)
        {
            if( array[i] == array[i+1] )
            return true;
 }
           return false;
}
 
ll getP(ll d){
      ll p = 1;
      while(d){
        p *= d%10;
        d /= 10;
      }
      return p;
 
}
 
ll prodDig(ll d){
        ll  p = 1;
        while(d){
        if((d%10)){
        p *= d%10;
        }
        d /= 10;
  }
       return p;
}
ll search(ll n){
        if(prodDig(n) < 10) return prodDig(n);
        else return search(prodDig(n));
}
string  rev(string s){
        int n = s.size();
         string c;
         for(int i=n-1;i>=0;--i){
             c+=s[i];
        }
         return c;
}
 
 
