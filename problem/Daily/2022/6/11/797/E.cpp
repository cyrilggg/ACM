#include <bits/stdc++.h>
using namespace std;

#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 1);
    map<int,queue<pair<int,int>>>mp;
    map<int,int>vis;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        mp[v[i] % k].push({v[i], i});
        vis[v[i]] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (vis[i]) continue; 
        int cnt = k - v[i] % k;
        int cur = cnt;
        bool cat = false;
        while (cur != cnt - 1)
        {
            while (mp[cur].size())
            {
                cat = true;
                int top = mp[cur].front().first;
                int toc = mp[cur].front().second;
                mp[cur].pop();

                vis[i] = 1;
                ans += (top + v[i]) / k;
                break;
            }
            cur ++;
            cur %= k;
        }
        if (cat == false)
        {
            while (true)
            {
                auto front = mp[cur].front();
                mp[cur].pop();
                if (front.second == i) mp[cur].push(front);
                else
                {

                }
            }
        }
    }
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