#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)   {cin>>a[i];}
        for(int i=0;i<n;i++)   {cin>>b[i];}

            int key1[105],key2[105],ans=0;
            int p=0,q=0;
            int flag2=1;
            while(flag2)
            {

                flag2=0;
                for(int i=0;i<n;i++)
                {
                    if(a[i]>b[i])
                    {
                        ans++;
                        key1[p]=i+1;
                        p++;
                        a[i]--;
                        break;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(a[i]<b[i])
                    {
                        key2[q]=i+1;
                        q++;
                        a[i]++;
                        break;
                    }
                }
                for(int i=0;i<n;i++)
                {

                    if(a[i]!=b[i])
                    {
                        flag2=1;
                        break;
                    }
                }
            }
            if(q!=ans)cout<<-1<<endl;
            else
            {cout<<ans<<endl;
            for(int i=0;i<q;i++)
                cout<<key1[i]<<' '<<key2[i]<<endl;}

        }

    return 0;
}

