#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>gp(n+1,vector<pair<int,int>>(0));
    vector<int>dis(n+1);
    for(int i=0;i<=n;i++)dis[i]=1e18;
    vector<bool>vis(n+1,0);
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        if(mp.find({u,v})!=mp.end())
        {
            mp[{u,v}]=min(mp[{u,v}],c);
        }
        else mp[{u,v}]=c;
    }
    for(auto & u : mp)
    {
        gp[u.first.first].push_back({u.first.second,u.second});//vertex,distance
    }
    dis[1]=0;
    vis[1]=1;
    multiset<pair<int,int>>ms;
    ms.insert({0,1});
    // for(int i=2;i<=n;i++)ms.insert({1e18,i});
    while(!ms.empty())
    {
        pair<int,int>p=*ms.begin();
        ms.erase(ms.begin());
        if(p.first>dis[p.second])continue;
        vis[p.second]=1;
        for(auto& u : gp[p.second])
        {
            if(!vis[u.first])
            {
                if(dis[u.first]>dis[p.second]+u.second)
                {
                    ms.insert({dis[p.second]+u.second,u.first});
                    dis[u.first]=dis[p.second]+u.second;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}