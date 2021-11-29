#include<bits/stdc++.h>
using namespace std;
const int N=45;
char a[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++)cin>>a[i];
        int r=-1;
        for(int i=1;i<n;i++)
        {

            if(a[i]<a[i-1]&&r==-1)
            {
                res++;
                r=i-1;
            }
            if(a[i]<a[r])
            {
                res++;
            }
            if(a[i]>=a[r])
            {
                r=i;
            }

        }

        printf("%d\n",res?(res>=n)?n:res+1:0);

    }
    return 0;
}
