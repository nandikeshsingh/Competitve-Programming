#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n,m;
vector<vector<int>>gp;
vector<int>vis;
vector<int>par;
void dfs(int node,int p)
{
    vis[node]=1;
    for(int c : gp[node])
    {
        if(!vis[c])
        {
            par[c]=node;
            dfs(c,node);
        }
        else if(vis[c]==1)
        {
            vector<int>ans;
            int cur=node;
            int has=node;
            while(cur!=c)
            {
                ans.push_back(cur);
                cur=par[cur];
            }
            ans.push_back(cur);
            ans.push_back(has);
            reverse(all(ans));
            cout<<ans.size()<<endl;
            for(auto& u : ans)cout<<u <<" ";
            cout<<endl;
            exit(0);
        }
    }
    vis[node]=2;
}
signed main()
{
    speed;
    cin>>n>>m;
    gp.resize(n+1,vector<int>(0));
    vis.resize(n+1);
    par.resize(n+1);
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i,i);
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
 