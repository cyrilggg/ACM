#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
#define int long long
int a[3][N];
int fron[N],last[N];
int m,t;

signed main()
{
    cin>>t;
    while(t--)
    {
        memset(fron,0,sizeof fron);
        memset(last,0,sizeof last);
        cin>>m;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=m;i++)
            fron[i]=fron[i-1]+a[2][i];
        for(int i=m;i>=1;i--)
            last[i]=last[i+1]+a[1][i];
        int res=1000000;
        for(int i=1;i<=m;i++)
            res=min(res,max(last[i+1],fron[i-1]));
        cout<<res<<endl;
    }
    return 0;
}
