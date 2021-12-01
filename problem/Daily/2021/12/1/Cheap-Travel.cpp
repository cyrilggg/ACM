/*
    Rating : 1200
    直接模拟就好了，注意一下特殊情况，之前误认为要全买完，实际上超一点也可以
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;

    cin >> n >> m >> a >> b;
    if( b / m  < a)//假如单程票比特价票还便宜就不用考虑了
        cout << min( (n / m) * b + (n - n / m * m) * a, (n / m + 1) * b) << endl;
    else cout << a * n << endl;
    return 0;
}