#include <bits/stdc++.h>
using namespace std;

//用于比较常见的 输出"YES"和"NO"题目
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
//

//用于 debug函数,只会在本地编辑器才显示
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
//

//常用头
#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

int n;

bool check(int mid, vector<int>&a, vector<int>&b)
{
    int x = 0;
    for (int i = 1; i <= n && x < mid; i ++ )
    {
        if (x <= b[i] && a[i] >= mid - x - 1)
            x ++;
    }
    return x == mid;
}

void solve()
{
   cin >> n;
   vector<int>a(n + 1), b(n + 1);
   for (int i = 1; i <= n; i ++ )
   {
      cin >> a[i] >> b[i];
   }
   int l = 1, r = n;
   while (l < r)
   {
       int mid = l + r >> 1;
       if (!check(mid, a, b)) r = mid;
       else l = mid + 1;
   }
   if (check(l, a, b)) cout << l << endl;
   else cout << l - 1 << endl;
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