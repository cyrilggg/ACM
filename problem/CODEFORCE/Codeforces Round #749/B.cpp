#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define int long long
using namespace std;
const int N = 1e5 + 10;
 
 
bool st[N];
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(st, 0, sizeof st);
        int n,m;
        cin>>n>>m;
        for (int i = 1; i <= m; i ++ )
        {
            int a,b,c;
            cin>>a>>b>>c;
            st[b] = true;
        }
        for (int i = 1; i <= n; i ++ )
        {
            if(!st[i])
            {
                for(int j = 1;j <= n; j ++ )
                {
                    if(i != j)
                    cout<<i<<' '<<j<<endl;
                }
                break;
            }
        }
        
    }
    return 0;
}