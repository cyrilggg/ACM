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
    for (int n = 6; n <= 50; n ++ )
    {
        if (n <= 3) return void(puts("-1"));
        else if (n == 4) return void(puts("-1+(2+4)*3"));
        else if (n == 5) return void(puts("1*(2*5+3+4)"));
        else
        {
            int cnt = 0;
            for (int i = 1; i <= n; i ++ )
            {
                cnt += i;
            }
            int diff = cnt - 17;
            map<int,int>mp;
            for (int i = n - 2; i >= 1; i -- )
            {
                if (2 * i <= diff)
                {
                    diff -= 2 * i;
                    mp[i] = -1;
                }
                else if (i == 1 && diff == 1)
                {
                    mp[1] = 2;
                    diff --;
                }
            }
            string a = "";
            for (int i = 1; i <= n; i ++ )
            {
                if (mp[i] == -1)
                {
                    a += "-" + to_string(i);
                }
                else if (mp[i] == 0)
                {
                    if (i == 1)
                    {
                        a += to_string(i);
                    }
                    else a += "+" + to_string(i);
                }
            }
            if (mp[1] == 2)
            {
                a = "1*(" + a + ")";
            }
            if (diff != 0)
            {
                cout << n << ' ' << a <<' '<<diff << endl;
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
   
   //cin >> _;
   while (_--)
      solve();
}