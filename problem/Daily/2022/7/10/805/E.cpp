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
vector<int> e[N];
map<int, int> color;

bool dfs(int u,int c)
{
    color[u]=c;

    for(int i = 0; i < e[u].size(); i ++ )
    {
        int j=e[u][i];
        if(!color[j])
        {
            if(!dfs(j,3-c))return false;

        }
        else if (color[j]==c)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    color.clear();
    for (int i = 1; i <= n; i++)
        e[i].clear();
    map<int,vector<int>>mp;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        
        mp[l].push_back(i);
        mp[r].push_back(i);
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (mp[i].size() > 2) returnNo;
        else if (mp[i].size() == 2)
        {
            e[mp[i][0]].push_back(mp[i][1]);
            e[mp[i][1]].push_back(mp[i][0]);
        }
    }
    
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    if (flag)
        puts("Yes");
    else
        puts("No");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}