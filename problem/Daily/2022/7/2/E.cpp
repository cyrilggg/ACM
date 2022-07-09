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
    int n, queries, m;
    cin >> n >> queries >> m;
    vector<int>v(n + 1);
    queue<int>q;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        q.push(v[i]);
    }
    vector<int>T;
    set<pair<int,int>>S;
    int idx = 1;
    int cir = 0;
    int iidx = 0;
    map<pair<int,int>, int> mp; 
    while (true)
    {
        pair<int,int>cur = {0, idx};
        int num = 0;
        while (cur.first < m)
        {
            auto f = q.front();
            q.pop();
            idx ++;
            num ++;
            cur.first += f;
            q.push(f);
            if (idx == n + 1) idx = 1;
        }
        debug(num, idx, cur);
        if (S.count(cur))
        {
            cir = mp[cur];
            break;
        }
        else
        {
            mp[cur] = iidx ++;
            S.insert(cur);
            T.push_back(num);
        }
    }
    int time = T.size();
    debug(time, cir);
    debug(T);
    while (queries -- )
    {
        int x;
        cin >> x;
        x --;
        if (x >= T.size()){
            x = (x - cir) % (time - cir) + cir;
        }
        debug(x, cir, T.size() - cir);
        cout << T[x] << endl;
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