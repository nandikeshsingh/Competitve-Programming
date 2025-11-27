#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>gp(n+1,vector<pair<int,int>>(0));
    vector<vector<pair<int,int>>>rgp(n+1,vector<pair<int,int>>(0));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        gp[a].push_back({b,c});
        rgp[b].push_back({a,c});
    }
    vector<bool>vis(n+1);
    // pair<int,int>p[n+1];
    multiset<pair<int,int>>ms;
    vector<int>dis(n+1,1e18);
    vector<int>dis2(n+1,1e18);
    dis[1]=0;
    vis[1]=1;
    ms.insert({0,1});
    while(sz(ms))
    {
        pair<int,int>pr=*ms.begin();
        ms.erase(ms.begin());
        vis[pr.second]=1;
        if(dis[pr.second]<pr.first)continue;
        for(auto& u : gp[pr.second])
        {
            if(!vis[u.first])
            {
                if(dis[u.first]>dis[pr.second]+u.second)
                {
                    dis[u.first]=dis[pr.second]+u.second;
                    ms.insert({dis[u.first],u.first});
                    // p[u.first]={pr.second,u.second};
                }
            }
        }
    }
    for(int i=0;i<=n;i++)vis[i]=0;
    ms.clear();
    dis2[n]=0;
    vis[n]=1;
    ms.insert({0,n});
    while(sz(ms))
    {
        pair<int,int>pr=*ms.begin();
        ms.erase(ms.begin());
        vis[pr.second]=1;
        if(dis2[pr.second]<pr.first)continue;
        for(auto& u : rgp[pr.second])
        {
            if(!vis[u.first])
            {
                if(dis2[u.first]>dis2[pr.second]+u.second)
                {
                    dis2[u.first]=dis2[pr.second]+u.second;
                    ms.insert({dis2[u.first],u.first});
                    // p[u.first]={pr.second,u.second};
                }
            }
        }
    }
    int ans=1e18;
    for(int i=1;i<=n;i++)//iterating over all the edges
    {
        for(auto& u : gp[i])
        {
            ans=min(ans,dis[i]+dis2[u.first]+u.second/2);
        }
    }
    cout<<ans<<endl;
    return 0;
}
