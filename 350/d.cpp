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
    vector<int>vis(n+1,0);
    vector<vector<int>>gp(n+1,vector<int>(0));
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    int cnt=0;
    auto dfs=[&](auto self,int node)->void
    {
        vis[node]=1;
        cnt++;
        for(auto& u : gp[node])
        {
            if(vis[u]==0)
            self(self,u);
        }
    };
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(dfs,i);
            int ret=cnt;
            tot+=(ret*(ret-1))/2;
            cnt=0;
        }
    }
    cout<<tot-m<<endl;
    return 0;
}


