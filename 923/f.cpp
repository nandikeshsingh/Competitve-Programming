#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=2e5+5;
int n,m;
vector<vector<int>> graph;
vector<vector<int>> cycles;
vector<int>vis;
void dfs_cycle(int u, int p, int color[], int par[] )
{
    vis[u]=1;
    if (color[u] == 2) {
        return;
    }
 
    if (color[u] == 1) {
        vector<int> v;
           
        int cur = p;
          v.push_back(cur);
 
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    color[u] = 1;
 
    for (int v : graph[u]) {
 
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par);
    }
 
    color[u] = 2;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int color[n+1]={0},par[n+1]={0};
        graph.resize(n+1);
        vis.resize(n+1,0);
        map<pair<int,int>,int>mp;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            mp[{min(u,v),max(u,v)}]=w;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]);
            dfs_cycle(i, 0, color, par);
        }
       
        int ans=-1;
        int mn=1e18;
        // cout<<cycles.size()<<endl;
        for(int i=0;i<cycles.size();i++)
        {
            for(int j=0;j<cycles[i].size();j++)
            {
                // cout<<cycles[i][j-1]<<" ";
                int u,v;
                if(j==0)
                {
                 u=cycles[i][0];
                 v=cycles[i][cycles[i].size()-1];
                }
                else 
                {
                      u=cycles[i][j];
                 v=cycles[i][j-1];
                }
       
                if(u>v)swap(u,v);
                if(mp.find({u,v})!=mp.end())
                {
                    if(mn>mp[{u,v}])
                    {
                        mn=mp[{u,v}];
                        ans=i;
                    }
                }
            }
            // cout<<cycles[i][cycles[i].size()-1]<<endl;
        }
        cout<<mn<<" "<<cycles[ans].size()<<endl;
        for(auto& u : cycles[ans])cout<<u<<" ";
        cout<<endl;
        cycles.clear();
        graph.clear();
    }
    return 0;
}


