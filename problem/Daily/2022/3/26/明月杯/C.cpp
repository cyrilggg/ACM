#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
const int N = 1e6+10;
bool st[N];
int primes[N];

void get_primes(int n)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
    {

        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
signed main()
{
  
    get_primes(N);
    int ans = 1;
    for (int i = 0;; i ++ )
    {
        if (ans * primes[i] > 1e9) break;
        ans *= primes[i];
    }
    cout << ans << endl;
    return 0;
}