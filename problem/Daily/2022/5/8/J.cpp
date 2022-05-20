#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

vector<int>v;
int n, k;

bool check(int x)
{
    int cnt = 0;
    unordered_map<int,int>mp, ttl;
    int timm = 0;
    int tim = 1;
    for (int i = 0; i < n; i ++ )
    {
        cout << ' ' << v[i] << ' ' << timm <<' '<< ttl[v[i]] <<' ' <<mp[v[i]]<< endl;
        if (mp[v[i]] + timm + ttl[v[i]] >= tim)
        {
            cnt ++;
            mp[v[i]] = tim + x;
            timm ++;
            ttl[v[i]] --;
        }
        else
        {
            
            ttl[v[i]] = 0;
            mp[v[i]] = tim + x;
        }
        tim ++;
    }
    cout << x << ' ' << cnt << endl;
    return cnt >= k;    
}

void solve()
{
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i ++ )    cin >> v[i];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (check(l)) cout << l << endl;
    else if (check(l - 1)) cout << l - 1 << endl;
    else cout << "cbddl" << endl;
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