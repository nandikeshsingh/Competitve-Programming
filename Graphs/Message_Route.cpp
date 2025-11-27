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
    vector<vector<int>>gp(n+1,vector<int>(0));
    vector<int>dis(n+1);
    vector<bool>vis(n+1);
    vector<int>path(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }   
    queue<int>q;
    q.push(1);
    vis[1]=1;
    path[1]=-1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& u : gp[cur])
        {
            if(!vis[u])
            {
                vis[u]=1;
                q.push(u);
                dis[u]=dis[cur]+1;
                path[u]=cur;
            }
        }
    }
    if(vis[n])
    {
        cout<<dis[n]+1<<endl;
        vector<int>ans;
        int cur=n;
        while(cur!=-1)
        {
            ans.push_back(cur);
            cur=path[cur];
        }
        reverse(all(ans));
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
