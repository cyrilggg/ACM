/*
    Rating : 1200
    很容易想到用前缀和，至于查询发现二分可以解决
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N];
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        s[i] = s[i - 1]  + a[i];
    }
    cin >> m;
    while (m -- )
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if( s[mid] >= x ) r = mid ;
            else l = mid + 1;
            //cout <<"---"<< r <<endl;
        }
        cout << l  << endl;
        
    }
    return 0;
    
}