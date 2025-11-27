#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
vector<vector<int>>gp;
vector<int>dp,vis,topo;
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
    dp.resize(n+1);
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
    // p[1]=1;
    reverse(all(topo));
    for(int i=0;i<sz(topo);i++)
    {
        for(auto& u : gp[topo[i]])
        {
            dp[u]+=dp[topo[i]];
            dp[u]%=mod;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}


