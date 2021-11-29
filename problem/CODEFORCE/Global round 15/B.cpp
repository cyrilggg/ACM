#include<bits/stdc++.h>
using namespace std;

const int N=50010;
int a[N][5];
int n;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=-1;
        cin>>n;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=5;j++)
                cin>>a[i][j];

        if(n==1){cout<<1<<endl;continue;}
        for(int i=1;i<=n;i++)
            {
                int cntwin=0;
                for(int j=1;j<=n;j++)
                    if(i!=j)
                    {

                        int cnt=0;
                        for(int k=1;k<=5;k++)
                        {
                            if(a[i][k]<a[j][k]){cnt++;}
                        }
                        if(cnt>=3){cntwin++;}
                    }
                if(cntwin==n-1){ans=i;break;}
            }
        cout<<ans<<endl;


    }


    return 0;
}
