#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
signed main()
{
    int n, m;
    scanf("%lld %lld", &n, &m);
    vector<int>v(n + 1);
    
    for (int i = 1; i <= n; i ++ )  scanf("%lld", &v[i]);
    
    while (m -- )
    {  
        int x;
        scanf("%lld", &x);
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (v[mid] < x) l = mid + 1;
            else r = mid;
        }
        if (v[l] == x) cout << l << " ";
        else cout << -1 << " ";
    }
    return 0;
}