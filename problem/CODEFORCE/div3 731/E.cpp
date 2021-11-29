#include<bits/stdc++.h>
using namespace std;
int a[200010];

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int res=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        a[n]=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)cout<<0<<endl;
        else
        {
            while(flag)
            {
                res++;
                int sum=0;
                for(int i=0;i<n;i++)
                {
                    //cout<<a[i]<<endl;
                    a[i]=gcd(a[i],a[i+1]);
                    sum+=
                }
                a[n]=a[0];
                for(int i=0;i<n-1;i++)
                {
                    flag=0;
                    if(a[i]!=a[i+1])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            cout<<res<<endl;

        }

    }
    return 0;

}
