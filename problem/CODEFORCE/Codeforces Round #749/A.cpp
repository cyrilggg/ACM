#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define int long long
using namespace std;
const int N = 110;
int a[N];
bool check(int a)
{
    for(int i = 2; i < a ; i ++ )
    {
        if(a%i == 0)return true;
    }
    return false;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            cin>>a[i];
            ans += a[i];
        }
        if(ans&1)
        {
            if(check(ans))
            {
                cout<<n<<endl;
                for(int i = 1; i <= n; i++)
            {
                cout<<i<<' ';
            }
            cout<<endl;
            }
            else
            {
                bool flag = false;
                cout<<n - 1<<endl;
                for(int i = 1; i<= n; i ++ )
                {
                    if(a[i]&1 && !flag)
                    {
                        flag = true;
                    }
                    else cout<<i<<' ';
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<n<<endl;
            for(int i = 1; i <= n; i++)
            {
                cout<<i<<' ';
            }
            cout<<endl;
        }
        
    }
    return 0;
}
