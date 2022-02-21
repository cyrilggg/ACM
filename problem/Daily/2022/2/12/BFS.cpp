#include<bits/stdc++.h>
using namespace std;

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

#define upmin(x,y) x=min(x,y)
#define upmax(x,y) x=max(x,y)
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

const int N = 1111 ;

int m[N][N] , n , mm , dx[8] = { -1 , -1 , -1 , 0, 0 , 1, 1 ,1} , dy[8] = {-1 , 0 , 1 ,-1, 1 ,-1, 0,1};

queue<pii > q ;

vector<pii > v ;
vector<int > clr ;

int ok(int x,int y)
{
    if(x<1||x>=n||y<1||y>=mm) return  0 ;
    if(m[x][y] + m[x+1][y] + m[x][y+1] +m[x+1][y+1] == -4 ) return 0;
    vector<int> pp ;
    pp.clear() ;
    pp.push_back(m[x][y]) ;
    pp.push_back(m[1+x][y]) ;
    pp.push_back(m[x][1+y]) ;
    pp.push_back(m[1+x][1+y]) ;
    sort(pp.begin(),pp.end());
    qc(pp);
    if(pp.size() == 1 ) return pp[0] ;
    if  (pp.size() == 2 && pp[0] == -1 )  return pp[1] ;
    return 0;
}

signed main()
{
    read(n,mm);
    rep(i,1,n) rep(j,1,mm) read(m[i][j]) ;
    rep(i,1,n-1) rep(j,1,mm-1) if(ok(i,j)) q.push({i,j});
    while(!q.empty())
    {
        auto nw = q .front() ;
        q.pop() ;
        int kk = ok(nw.fi,nw.se) ;
        if(kk) v.push_back(nw) , clr.push_back(kk) ;
        else continue ;
        m[nw.fi] [nw.se] = -1 ;
        m[nw.fi+1] [nw.se+1] = -1 ;
        m[nw.fi] [nw.se+1] = -1 ;
        m[nw.fi+1] [nw.se] = -1 ;
        for(int f = 0 ; f < 8 ;++ f)
        {
            int tx = nw . fi + dx[f] ;
            int ty = nw . se + dy[f] ;
            if(ok(tx,ty)) q.push({tx,ty});
        }
    }
    reverse(v.begin() , v.end() );
    reverse(clr.begin() ,clr.end()) ;
    wrt(v.size(),'\n');
    for(int i=0;i<v.size() ;++i)
    wrt(v[i].fi,' '), wrt(v[i].se,' '),wrt(clr[i],'\n');
    return 0;
}