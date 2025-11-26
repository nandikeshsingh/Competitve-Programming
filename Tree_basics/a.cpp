#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<vector<int>>gp;
vector<int>depth;
void dfs(int node,int par,int dep)
{
    depth[node]=dep;
    for(auto& u : gp[node])
    {
        if(u!=par)
        {
            dfs(u,node,dep+1);
        }
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    gp.resize(n+1,vector<int>(0));
    depth.resize(n+1,0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    dfs(1,-1,0);
    int node=1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>depth[node])
            node=i;
    }
    depth.resize(n+1,0);
    dfs(node,-1,0);
    cout<<3*(*max_element(all(depth)))<<endl;
    return 0;
}


