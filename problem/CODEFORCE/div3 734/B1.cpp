#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int num[26];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      memset(num,0,sizeof num);
      int maxn=0;
      char a[55];
      cin>>a;
      for(int i=0;i<strlen(a);i++)
      {
          num[a[i]-'a']++;
         // cout<<num[a[i]-'a']<<endl;
          maxn=max(maxn,num[a[i]-'a']);
      }
      if(strlen(a)==1)cout<<0<<endl;
      else
      {
        if(2*maxn>strlen(a))cout<<(strlen(a)-maxn+2)/2<<endl;
        else cout<<strlen(a)/2<<endl;
      }
    }

    return 0;
}
