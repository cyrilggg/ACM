#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr int maxn = 2e5 + 10;
int n, m;
int st;
int outdeg[maxn];
int vis[maxn];
int suc = 0;

struct custom_hash
{
    size_t operator()(const long long &tmp) const
    {
        long long o(tmp);
        o += 0x9e3779b97f4a7c15;
        o = (o ^ (o >> 30)) * 0xbf58476d1ce4e5b9;
        o = (o ^ (o >> 27)) * 0x94d049bb133111eb;
        return o ^ (o >> 31);
    }
};

unordered_map<long long, vector<int>, custom_hash> mp;
vector<int> vec[maxn];
int ans1, ans2;
queue<int> q;

int cnt(0);

void bfs(int st)
{
    mp.clear();
    for (auto &e : vec[st])
    {
        vector<int> tmp;
        tmp.push_back(st);
        tmp.push_back(e);
        mp[e] = tmp;
        q.emplace(e);
    }
    while (!q.empty())
    {
        auto &idx = q.front();
        q.pop();
        /*
        if (vis[p])
        {
            suc = true;
            ans = idx;
            printf("p=%d\n",p);
            return;
        }
        */
        vis[idx] = true;
        // printf("idx=%d\n",idx);
        for (int i(0); i < vec[idx].size(); ++i)
        {
            if (vis[vec[idx][i]])
            {
                suc = 1;
                ans1 = vec[idx][i];
                ans2 = idx;
                return;
            }
            vector<int> tmp(mp[idx]);
            tmp.emplace_back(vec[idx][i]);
            mp[vec[idx][i]] = tmp;
            q.emplace(vec[idx][i]);
            vis[vec[idx][i]] = 1;
        }
    }
}

int main()
{
    cin >> n >> m >> st;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        outdeg[u]++;
    }
    int flag = 0;
    if (outdeg[st] < 2)
    {
        flag = 1;
        printf("Impossible\n");
    }
    else
    {
        suc = 0;
        bfs(st);
        if (suc)
        {
            printf("Possible\n");
            // printf("ans1=%d ans2=%d\n",ans1,ans2);
            printf("%d\n", mp[ans1].size());
            for (int i(0); i < mp[ans1].size(); i++)
            {
                printf("%d%c", mp[ans1][i], i == mp[ans1].size() - 1 ? '\n' : ' ');
            }
            printf("%d\n", mp[ans2].size() + 1);
            int last = mp[ans1][mp[ans1].size() - 1];
            for (int i(0); i < mp[ans2].size(); i++)
            {
                printf("%d ", mp[ans2][i]);
            }
            printf("%d\n", last);
        }
        else
        {
            printf("Impossible\n");
        }
    }

    return 0;
}