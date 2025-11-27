#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<int>>gp;
vector<int>vis;
vector<int>ans;
void dfs(int node)
{
    vis[node]=1;
    for(auto& c : gp[node])
    {
        if(!vis[c])
        dfs(c);
        else if(vis[c]==1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            exit(0);
        }
    }
    ans.push_back(node);
    vis[node]=2;
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    gp.resize(n+1,vector<int>(0));
    vis.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    if(vis[i]==0)dfs(i);
    while(sz(ans))
    {
        cout<<ans.back()<<" ";
        ans.pop_back();
    }
    cout<<endl;
    return 0;
}


