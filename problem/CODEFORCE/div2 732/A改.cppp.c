#include<bits/stdc++.h>
using namespace std;

int a[105],b[105],c[105],d[105];
pair<int,int>u[105],s[105];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)   {cin>>a[i];c[i]=a[i];}
        for(int i=0;i<n;i++)   {cin>>b[i];d[i]=b[i];}
        sort(c,c+n);
        sort(d,d+n);
        for(int i=0;i<n;i++)
            if(c[i]!=d[i])
                {
                    flag=1;
                    break;
                }
        if(flag)cout<<-1<<endl;
        else
        {
            int ans=0;
            int j=0,k=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]>b[i])
                {
                    ans+=a[i]-b[i];
                    u[j].first=a[i]-b[i];
                    u[j].second=i+1;
                    j++;
                }
                else if(a[i]<b[i])
                {
                    s[k].first=b[i]-a[i];
                    s[k].second=i+1;
                    k++;
                }
            }
            int m=0,n=0;
            cout<<ans<<endl;
            while(m<j&&n<k)
            {
                if(!u[m].first)m++;
                if(!s[n].first)n++;
                if(m<j&&n<k)
                cout<<u[m].second<<' '<<s[n].second<<endl;

                u[m].first--;
                s[n].first--;
            }
        }

    }
    return 0;
}
