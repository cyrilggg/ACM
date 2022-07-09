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

int rand(int l, int r)
{
    return 1.0 * rand() / RAND_MAX * (r - l) + l;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n + 1);
    map<int,int>mp;
    set<int>S;
    vector<int>ans;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        if (v[i] != 0) ans.push_back(v[i]);
        S.insert(v[i]);
    }
    if (n < 100)
    {
        for (int i = 1; i <= n; i ++ )
        {
            for (int j = i + 1; j <= n; j ++ )
            {
                for (int k = j + 1; k <= n; k ++ )
                {
                    if (!S.count(v[i] + v[j] + v[k])) returnNo;
                }
            }
        }
    }
    else
    {
    if (ans.size() <= 1) returnYes;
    else if (ans.size() > 2) returnNo;
    else
    {
        if ((ans[0] + ans[1]) == 0) returnYes;
        else returnNo;
    }
    }
    returnYes;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   srand(time(0));
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}