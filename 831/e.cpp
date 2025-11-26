#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>depth,dp;
vector<vector<int>>gp;
void dfs(int node)
{
    int sum=0;
    int mx=0;
    for(auto& u : gp[node])
    {
        dfs(u);
        sum+=dp[u];
        mx=max(mx,depth[u]+1);
    }
    if(gp[node].size()==0)dp[node]=1,depth[node]=1;
    else 
    {
        dp[node]=max(sum,mx);
        depth[node]=mx;
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    depth.resize(n+1);
    dp.resize(n+1);
    vector<int>p(n+1);
    gp.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        gp[p[i]].push_back(i);
        // gp[i].push_back(p[i]);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    return 0;
}
