#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


const int N=2e5+10;
pair<string,int> a[N];
int cnt[N][5];
int ans[5];
int i,j;

bool cmp(pair<string,int>c,pair<string,int>d)
{
    if( cnt[c.second][j]==cnt[d.second][j])
        return c.first.size()<d.first.size();
    else return cnt[c.second][j]>cnt[d.second][j];

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(ans,0,sizeof ans);
        memset(cnt,0,sizeof cnt);
        int maxn=0;
        int n;
        cin>>n;
        for(i=0;i<n;i++)
            {cin>>a[i].first;a[i].second=i;}
        for(i=0;i<n;i++)
            for(j=0;j<a[i].first.size();j++)
                cnt[i][a[i].first[j]-'a']++;


        for(j=0;j<5;j++)
            {
                sort(a,a+n,cmp);
                for(int k=0;k<n;k++)cout<<a[k].first<<endl;
                int l=0,r=0;
                int res=cnt [a[0].second][j];
                int re=a[0].first.size();
                while(r<n)
                {

                    while(r<n&&(2*res>re||res==re))
                    {
                        ans[j]++;
                        maxn=max(maxn,ans[j]);
                        r++;
                        res+=cnt [a[r].second][j];
                        re+=a[r].first.size();
                    }

                    printf("%c ",'a'+j);
                    cout<<' '<<r<<' '<<res<<' '<<re<<' '<<maxn<<endl;
                    r++;
                    res+=cnt [a[r].second][j];
                    re+=a[r].first.size();
                }



            }
        printf("------%d\n",(maxn)?maxn+1:0);
    }

    return 0;
}
