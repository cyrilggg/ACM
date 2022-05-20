#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
map<string,int>mp;
void solve()
{ 
    string a;
    cin >> a;
    cout << mp[a] << endl;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int idx = 1;
    for (char i = 'a'; i <= 'z'; i ++ )
    {
        for (char j = 'a'; j <= 'z';j ++ )
        {
            if (i == j)continue;
            string a = "";
            a += i;
            a += j;
            mp[a] = idx ++;
        }
    }
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}