#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define lll __int128
#define lb long double
#define D double

#define psb push_back
#define mkp make_pair

#define min3(xxx,yyy,zzz) min(min(xxx,yyy),zzz)
#define max3(xxx,yyy,zzz) max(max(xxx,yyy),zzz)

#define gi greater<int>
#define gl greater<ll>
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second

#define rep(variable,leftrange,rightrange) for(int variable=leftrange;variable<=rightrange;++variable)
#define Rep(variable,leftrange,rightrange) for(int variable=leftrange;variable>=rightrange;--variable)

#define Seed mt19937 rANd(random_device{}())
#define rd(p) (rANd()%p)

#define ss stable_sort
#define nxp next_permutation
#define rds random_shuffle

#define mem(x,y) memset(x,y,sizeof x) 
#define Finda(a,siz,b) (lower_bound(a+1,a+siz+1,b)-a)
#define Findv(a,b) (lower_bound(a.begin(),a.end(),b)-a.begin())
#define qc(v) v.erase(unique(v.begin(),v.end()),v.end())

#define sq(x) ((x)*(x))
#define lowbit(x) (x & -x)

template <typename T>inline void read(T &t)
{bool flag = 1 ;char c=getchar();t=0;while(!isdigit(c)){ if(c=='-') flag = 0; c=getchar();}while(isdigit(c))t=(t<<3)+(t<<1)+c-48,c=getchar(); if(!flag) t=~(t-1);}
template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
template <typename T> inline void wrt(T x)
{if(x<0) x=~(x-1),putchar('-'); if(x>9) wrt(x/10); putchar(x%10+'0');}
template <typename T> inline void wrt(T x,char c) {wrt(x);putchar(c);}

#define FileIO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define debug puts("I am still alive") 
#define S_debug(l,r,val) printf("[%d,%d] : %d \n",l,r,val)
#define P_debug(a,b) printf(#a"[%d] = %d \n",b,a[b])
#define A_debug(a,b) rep(i,1,b) P_debug(a,i);
const int N = 1010;

void solve()
{

}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}