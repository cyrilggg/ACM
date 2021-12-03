/*
    Rating : 1300
    Ä£ÄâÌâ
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int l = 0, r = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if(i > 1)
        {
            if(a[i] <= a[i - 1])
            {
                if(!l)l = i - 1;
                r = i;
            }
        }
    }
    if (l == 0) l = 1;
    if (r == 0) r = 1;
    
    reverse(a + l, a + 1 + r);
    if (is_sorted(a + 1, a + 1 + n))
    {
        puts("yes");
        cout << l << ' ' << r << endl;
    }
    else puts("no");
    return 0;
}