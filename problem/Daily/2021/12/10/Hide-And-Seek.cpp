/*
    Rating : 1500
    哈希表存数，预处理从前往后的每个数字的个数，再从后往前倒回来判断前面有没有数字，此外还得用个set来存序列避免重复
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, k;
typedef pair<int, int> PII;
unordered_map<int,int>mp;
set<PII>s;
int a[N];
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i ++ )  
    {
        cin >> a[i];
        mp[a[i]] ++;
    }
    int ans = n * 3 - mp.size() - 2;
    for (int i = k; i >= 1; i -- )
    {
        if(mp[a[i] - 1] > 0 && s.count({a[i] - 1,a[i]}) == 0)
        {
            s.insert({a[i] - 1, a[i]});
            ans --;
        }
        if(mp[a[i] + 1] > 0 && s.count({a[i] + 1,a[i]}) == 0)
        {
            s.insert({a[i] + 1, a[i]});
            ans --;
        }
        mp[a[i]] --;
       // cout << i <<' '<< ans << endl;
    }
    cout << ans << endl;
    return 0;
}
