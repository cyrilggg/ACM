#include <bits/stdc++.h>
using namespace std;
set<pair<int,int>>S;
signed main()
{
    for (long long i = 1; i <= 20; i ++ )
        for (long long j = 1; j <= 21; j ++ )
            for (long long s = 1; s <= 20; s ++ )
                for (long long t = 1; t <= 21; t ++ )
                {
                    if (s == i) continue;
                    double k, m;
                    double so = t - j;
                    double mo = s - i;
                    k = so / mo;
                    m = t - k * i;
                    
                    int kk = k * 10000000;
                    int mm = m * 10000000;
                    S.insert({kk ,mm});
                }
    cout << S.size() + 20 << endl;
    
    return 0;
}