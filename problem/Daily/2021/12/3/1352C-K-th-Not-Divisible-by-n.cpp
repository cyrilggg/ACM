/*
    Rating : 1200
    ¶þ·Ö
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t -- )
    {
        int n, k;
        cin >> n >> k;
        
        int l = 0, r = 1e12 ;
        
        while (l < r)
        {
            int mid = l + r >> 1;
            int cnt = mid - mid / n;
            if (cnt < k)    l = mid + 1;
            else  r = mid ;
        }
        
        cout << r << endl;
    }
    return 0;
}