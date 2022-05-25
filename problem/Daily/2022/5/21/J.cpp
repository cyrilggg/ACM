#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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

void solve()
{
    string a, b, c;
    cin >> a >> b;
    map<char,int>mp;
    for (int i = 0; i < a.size(); i ++ )
    {
        mp[a[i]] ++;
    }
    for (int i = 0; i < b.size(); i ++ )
    {
        if (mp[a[i]] > 0)
        {
            mp[a[i]] --;
        }
        else
        {
            c += b[i];
        }
    }
    for (int i = 0; i < a.size(); i ++ )
    {
        if (mp[a[i]] > 0)
        {
            cout << "impossible" << endl;
            return;
        }
    }
    sort(c.begin(), c.end());
    bool flag = true;
    string ans;
    for (int i = 0; i < c.size() - 1; i ++ )
    {
        if (c[i] == a[0])
        {
            int idx = 1;
            while (idx < a.size() && a[idx] == c[i + 1]) idx ++;
            if (idx == a.size())
            {
                ans = c.substr(0, i) + a + c.substr(i + 1);
                flag = false;
            }
            else if (a[idx] < c[i + 1])
            {
                ans = c.substr(0, i) + a + c.substr(i + 1);
                flag = false;
            }
        }
        if (c[i] > a[0])
        {
            ans = c.substr(0, i) + a + c.substr(i);
            flag = false;
        }

    }
    if (flag)
    {
        ans = c + a;
    }
    cout << ans << endl;
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