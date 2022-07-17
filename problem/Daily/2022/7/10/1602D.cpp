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

struct Node{
    int idx;
    vector<int>v;
};

void solve()
{
   map<int,int>vis; 
   int n;
   cin >> n;
   vector<int>a(n + 1), b(n + 1);
   for (int i = 1; i <= n; i ++ )
   {
      cin >> a[i];
   }
   for (int i = 1; i <= n; i ++ )
   {
       cin >> b[i];
   }
   queue<Node> q;
    vector<int>v;
    q.push({0, v});
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t.idx == n)
        {
            reverse(v.begin(), v.end());
            cout << v.size() << endl;
            for (auto vv : v)
            {
                cout << vv << " ";
            }
            return;
        }
        for (int i = t.idx + 1; i <= n; i ++ )
        {
            if (vis[i]) continue;
            if (i - t.idx > a[i]) continue;
            
        } 
    }
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   while (_--)
      solve();
}