#include <bits/stdc++.h>
using namespace std;

#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '[';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << ']';
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

vector<pair<int, int>> e[N];
vector<vector<int>> dp;
vector<int> sz, v;
int m;
map<int, vector<int>> mp;

void dfs_input(int idx)
{
    int a, b;
    cin >> a >> b;
    e[idx].push_back({a, b});
    if (!b)
    {
        dfs_input(idx << 1);
        dfs_input(idx << 1 | 1);
    }
}

void dfs(int u)
{
    for (auto &vv : e[u])
    {
        int w = vv.first, w = vv.second;
        
        dfs(j, u);
        sz[u] += sz[j];
        for (int i = m - 1; i >= 0; i -- )
        {
            for (int k = 1; k <= i; k ++ )
            {
                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[j][k] - w);
            }
        }
    }
}

void build(int x){   //读入
	scanf("%d%d",&t[x],&a[x]);
	t[x]<<=1;
	if(!a[x])build(x<<1),build(x<<1|1);
}

inline void tomax(int &a,int b){if(a<b)a=b;}
void dfs(int x,int tim){   //树形DP主体
	if(!a[x]){
		int l=x<<1,r=x<<1|1;
		dfs(l,tim+t[l]);
		dfs(r,tim+t[r]);
		for(int i=0;i<=m-tim;++i)
		 for(int j=0;tim+i+j<=m;++j)
		  tomax(f[x][tim+i+j],f[l][tim+i]+f[r][tim+j]);
	}else{
		for(int i=1;i<=a[x];++i){
			int now=tim+(i*5);
			if(now>m)break;
			f[x][now]=f[x][now-5]+1;
		}
	}
}


void solve()
{
    cin >> m;
    m --;
    dfs_input(1);
    dp.resize(500, vector<int>(m + 1));
    
    dfs(1, 1);
    cout << dp[1][m] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}