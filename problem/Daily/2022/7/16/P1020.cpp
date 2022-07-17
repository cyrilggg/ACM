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
constexpr int N = 1e5 + 10;
int v[N], q[N];
void solve()
{
    int n = 0;
    while (cin >> v[n]) n ++ ;
    int ans1 = 1, ans2 = 1;
    q[1] = v[0];
    for (int i = 1; i < n; i ++ )
    {
        int l = 0, r = ans1 + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            debug(l, r, mid, q[mid]);
            if (q[mid] >= v[i]) l = mid + 1;
            else r = mid;
        }
        q[l] = v[i];
        ans1 = max(ans1, l);
        
        debug(i, ans1);
    }
    cout << ans1 << endl;

    memset(q, 0 ,sizeof q);

    q[1] = v[0];
    for (int i = 1; i < n; i ++ )
    {
        int l = 0, r = ans2 + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            debug(l, r, mid, q[mid]);
            if (q[mid] <= v[i]) l = mid + 1;
            else r = mid;
            
        }
        q[l] = v[i];
        ans2 = max(ans2, l);
        debug(i, ans2);
    }
    cout << ans2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
       solve();
}