#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll sum,a[N],x;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> x;
    ll aa = x / sum;
    ll b = x % sum;


        for (int i = 1; i <= n; i ++ )
        {
            b -= a[i];
            if(b < 0)
            {
                cout << aa * n + i <<endl;
                break;
            }
        }
    
    return 0;
}