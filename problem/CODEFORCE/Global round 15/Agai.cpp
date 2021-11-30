#include <iostream>
#include <cstring>
using namespace std;

const int N = 45;
char a[N];
int q[N];
int ans;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        ans=0;
        int n;
        cin>>n;
        for (int i = 0; i < n; i ++ ) cin>>a[i];
        for (int i = 0; i < n; i ++ ) q[i]=a[i]-'a';
        for(int i=0;i<n;i++)
        {
            int minn=1e9;
            int key;
            for(int j=i;j<n;j++)
                if(minn>q[j])
                {
                    minn=q[j];
                    key=j;
                }
            if(key==i||q[key]==q[key-1])continue;



            ans++;
            printf("%c ",'a'+q[key]);
            q[key]=1e9;

        }

        printf("%d\n",ans?ans+1:0);

    }
    return 0;
}
