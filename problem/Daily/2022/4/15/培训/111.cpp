#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
long long f[N];
int s[N];
long long w[N][N], v[N][N];
long long num;

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        long long ww, vv, idxx;
        cin >> ww >> vv >> idxx;
        w[idxx][++ s[idxx] ] = ww;
        v[idxx][s[idxx] ] = vv;
        num = max(idxx, num);
    }
    
    for (int i = 1; i <= num; i ++ )
    {
        for (int j = m; j >= 0; j -- )
        {
            for (int k = 1; k <= s[i]; k ++ )
                if (j >= w[i][k])
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);
        }
    }
    cout << f[m] << endl;
    return 0;
}