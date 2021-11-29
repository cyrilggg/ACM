#include <iostream>
using namespace std;
int main()
{
    long long n,d;
    long long cnt = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i ++ )
    {
        long long x, y;
        cin >> x >> y;
        if ((long long)1 *x * x + y * y <= (long long)1 *d * d)cnt ++;
    }
    cout << cnt << endl;
    return 0;
}