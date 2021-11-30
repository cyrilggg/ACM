/*
    Rating : 1200
    简单题，就是问当只有一个奇数，奇数的下标是多少，或者只有一个偶数，偶数的下标是多少，简单存一下即可
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n;
int ocnt, oidx, eidx, ecnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        if(x & 1)
        {
            oidx = i;
            ocnt ++;
        }
        else
        {
            eidx = i;
            ecnt ++;
        }
    }
    if(ocnt == 1)
    {
        cout << oidx <<endl;
    }
    else cout << eidx << endl;
    return 0;
}