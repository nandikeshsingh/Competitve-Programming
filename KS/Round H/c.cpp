#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
#define sz(v) (int)v.size()
int n;
vector<int>a;
vector<vector<int>>gp;
vector<int>vis,ans;
void dfs(int node)
{
    vis[node]=1;
    for(auto& u : gp[node])
    {
        if(vis[u]==0 && a[u]<a[node])
        dfs(u);
    }
}
void topo(int v) {
    vis[v] = true;
    for (int u : gp[v]) {
        if (!vis[u])
            topo(u);
    }
    ans.push_back(v);
}
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        cin>>n;
        a.clear();
        a.resize(n+1);
                    vis.clear();
            vis.resize(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        gp.clear();
        gp.resize(n+1,vector<int>(0));
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            if(a[u]>a[v])
            gp[u].push_back(v);
            else if(a[v]>a[u])
            gp[v].push_back(u);
        }
        cout<<"ok1"<<endl;
        //now we have a DAG
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                topo(i);
            }
        }
        cout<<"ok2"<<endl;
        reverse(all(ans));
        cout<<"Printint topo"<<endl;
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
        vector<int>dp(n+1);
        for(int i=sz(ans);i>=1;i--)
        {
            for(auto& v : gp[i])
            dp[v]=max(dp[v],dp[ans[i]]+1);
        }
        int anss=*max_element(all(dp));
        // int ans=0;
        // for(int i=1;i<=n;i++)
        // {
        //     vis.clear();
        //     vis.resize(n+1,0);
        //     dfs(i);
        //     int cur=0;
        //      for(int i=1;i<=n;i++)cur+=(vis[i]==1);
        //      ans=max(ans,cur);
        // }
        cout<<"Case #"<<c<<": "<<anss+1<<endl;
    }
    return 0;
}

