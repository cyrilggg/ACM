#include<bits/stdc++.h>
using namespace std;
int b[26];
char a[26];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        int flag=0;
        char a[26];
            cin>>a;

        for(int i=0;i<strlen(a);i++)
            b[a[i]-'a']++;
        for(int i=0;i<strlen(a);i++)
           {
               //cout<<b[i]<<' '<<i<<endl;
               if(b[i]!=1)
                {

                    flag=1;
                    break;
                }
           }
        for(int i=1;i<strlen(a)-1;i++)
            if(a[i]>a[i-1]&&a[i]>a[i+1])
            {
                flag=1;
                break;
            }


        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}


