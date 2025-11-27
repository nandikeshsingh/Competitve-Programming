#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<int>>gp;
vector<int>p,dp,vis,topo;
void dfs(int node)
{
    vis[node]=1;
    for(auto& u : gp[node])
    {
        if(vis[u]==0)
        {
            dfs(u);
        }
        // else if(vis[u]==1)
        // {
        //     cout<<"IMPOSSIBLE"<<endl;
        //     exit(0);
        // }
    }
    topo.push_back(node);
    vis[node]=2;
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    gp.resize(n+1,vector<int>(0));
    vis.resize(n+1);
    p.resize(n+1);
    dp.resize(n+1,-1e18);
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
        gp[a].push_back(b);
    }
    dfs(1);
    dp[1]=1;
    p[1]=1;
    reverse(all(topo));
    for(int i=0;i<sz(topo);i++)
    {
        for(auto& u : gp[topo[i]])
        {
            if(dp[u]<dp[topo[i]]+1)
            {
                dp[u]=dp[topo[i]]+1;
                p[u]=topo[i];
            }
        }
    }
    if(dp[n]==-1e18)cout<<"IMPOSSIBLE"<<endl;
    else 
    {
        cout<<dp[n]<<endl;
        int cur=n;
        vector<int>ans;
        while (cur^p[cur])
        {
            ans.push_back(cur);
            cur=p[cur];
        }
        ans.push_back(cur);
        while(sz(ans))
        {
            cout<<ans.back()<<" ";
            ans.pop_back();
        }
        cout<<endl;
    }
    return 0;
}


