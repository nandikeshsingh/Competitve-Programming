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
    vector<int>col(n+1);
    vector<bool>vis(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            col[i]=1;
            vis[i]=1;
            while (!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto& u : gp[node])
                {
                    if(!vis[u])
                    {
                        vis[u]=1;
                        q.push(u);
                        col[u]=1-col[node];
                    }
                    else ok&=col[u]!=col[node];
                }
            }
        }
    }
    if(!ok)cout<<"IMPOSSIBLE"<<endl;
    else 
    {
        for(int i=1;i<=n;i++)cout<<col[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}


