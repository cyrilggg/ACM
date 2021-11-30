#include<bits/stdc++.h>
using namespace std;

int lowbit(int t)
{
    return t&(-t);
}
const int N=2e5;
int a[N];
int b[N];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++)    cin>>a[i];

        if(n==1)cout<<0<<endl;

        else
        {
            for(int i=1;i<=n-1;i++)
                if(a[i]&a[i+1]!=a[i])
                    {
                        flag=1;
                        break;
                    }
            if(flag==0)
            {
                cout<<"hi"<<endl;
                for(int i=1;i<=n;i++)cout<<0<<' ';
                cout<<endl;
            }
            else
            {
                b[1]=0;
                a[1]^=0;
                for(int i=2;i<=n;i++)
                {
                    cout<<a[i-1]<<endl;
                    b[i]=a[i-1]-a[i-1]&a[i];
                    a[i]^=b[i];
                }
                for(int i=1;i<=n;i++)
                    cout<<b[i]<<' ';
                    cout<<endl;


            }
        }
    }
    return 0;
}
