/*
    一直扫描周期
*/
#include <iostream>
#include <algorithm>
const int N=1e5+3;
using namespace std;
#define int long long
int n,p[N];
signed main()
{
	int x, y;
	int t;
    cin >> t;
    while (t -- )
    {
        cin >> n;
        for(int i=1;i<=n;i++)p[i]=0;
        for(int i=1;i<=n;i++)if(!p[i]){
            x=0;
            while(1)
            {
                cout <<"? " << i << endl;
                cin >> y;
                p[x]=y,x = y;
                if(p[x])break;
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; i ++)cout << p[i] << ' ';
        cout << endl;
	}
    return 0;
}